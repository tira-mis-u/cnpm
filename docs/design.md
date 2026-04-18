# 📘 Tài Liệu Thiết Kế Hệ Thống - StudentMS

> **Phần Mềm Quản Lý Hồ Sơ Sinh Viên**  
> Ngôn ngữ: C++ | Framework: Qt 6 | CSDL: SQLite | Kiến trúc: MVC

---

## Mục Lục

1. [Tổng Quan Hệ Thống](#1-tổng-quan-hệ-thống)
2. [Cấu Trúc Thư Mục](#2-cấu-trúc-thư-mục)
3. [Kiến Trúc MVC – Lý Do Chọn](#3-kiến-trúc-mvc--lý-do-chọn)
4. [Use Case Diagram](#4-use-case-diagram)
5. [Class Diagram](#5-class-diagram)
6. [Sequence Diagram – Luồng Thêm Sinh Viên](#6-sequence-diagram--luồng-thêm-sinh-viên)
7. [Sequence Diagram – Luồng Đăng Nhập](#7-sequence-diagram--luồng-đăng-nhập)
8. [Sequence Diagram – Luồng Tìm Kiếm](#8-sequence-diagram--luồng-tìm-kiếm)
9. [Database Schema & Mapping OOP](#9-database-schema--mapping-oop)
10. [Mô Tả Từng Module](#10-mô-tả-từng-module)
11. [Các Nguyên Lý OOP Áp Dụng](#11-các-nguyên-lý-oop-áp-dụng)
12. [Test Cases](#12-test-cases)
13. [Hướng Dẫn Build & Chạy](#13-hướng-dẫn-build--chạy)

---

## 1. Tổng Quan Hệ Thống

| Thuộc tính | Giá trị |
|---|---|
| Tên hệ thống | Phần Mềm Quản Lý Hồ Sơ Sinh Viên (StudentMS) |
| Ngôn ngữ | C++17 (OOP) |
| Framework | Qt 6 (Widgets + SQL) |
| Giao diện | Qt Designer (.ui XML) |
| Cơ sở dữ liệu | SQLite (chạy local, không cần server) |
| Kiến trúc | MVC (Model – View – Controller) |
| Môi trường | Desktop, offline hoàn toàn |
| Ngôn ngữ UI | Tiếng Việt |

### Mục Tiêu

- Quản lý thông tin sinh viên: thêm, sửa, xóa, tìm kiếm
- Quản lý lớp học và khoa
- Validate dữ liệu nghiêm ngặt
- Xuất danh sách ra file CSV
- Đăng nhập bảo mật (SHA-256 hash)

---

## 2. Cấu Trúc Thư Mục

```
StudentMS/
│
├── CMakeLists.txt                   ← Cấu hình build CMake
│
├── src/
│   ├── main.cpp                     ← Entry point, khởi tạo DB, Login, MainWindow
│   │
│   ├── models/                      ← [LAYER: Model] – Dữ liệu thuần, không UI
│   │   ├── department.h / .cpp      ← Class Khoa
│   │   ├── class_model.h / .cpp     ← Class Lớp học
│   │   └── student.h / .cpp         ← Class Sinh viên (phức tạp nhất)
│   │
│   ├── database/                    ← [LAYER: Model] – Persistence
│   │   ├── databasemanager.h        ← Singleton quản lý SQLite
│   │   └── databasemanager.cpp      ← CRUD cho cả 3 entity
│   │
│   ├── controllers/                 ← [LAYER: Controller] – Business logic
│   │   ├── studentcontroller.h/.cpp ← Validate + gọi DB + phát signal
│   │   ├── classcontroller.h/.cpp   ← Quản lý lớp học
│   │   └── departmentcontroller.h/.cpp ← Quản lý khoa
│   │
│   └── views/                       ← [LAYER: View] – Giao diện Qt
│       ├── mainwindow.h / .cpp      ← Cửa sổ chính, 3 tab
│       ├── studentdialog.h / .cpp   ← Form thêm/sửa sinh viên
│       ├── classdialog.h / .cpp     ← Form thêm/sửa lớp
│       ├── departmentdialog.h / .cpp← Form thêm/sửa khoa
│       └── logindialog.h / .cpp     ← Màn hình đăng nhập
│
├── ui/                              ← Qt Designer XML (giao diện kéo thả)
│   ├── mainwindow.ui
│   ├── studentdialog.ui
│   ├── classdialog.ui
│   ├── departmentdialog.ui
│   └── logindialog.ui
│
└── docs/
    ├── design.md                    ← File này (tài liệu thiết kế)
    └── schema.sql                   ← Script SQL tạo database độc lập
```

---

## 3. Kiến Trúc MVC – Lý Do Chọn

### Sơ đồ tổng quan MVC

```
┌─────────────────────────────────────────────────────────────────┐
│                                                                 │
│   ┌───────────┐    signal/slot    ┌──────────────┐             │
│   │   VIEW    │ ◀──────────────── │  CONTROLLER  │             │
│   │  (Qt UI)  │ ──────────────▶  │  (Logic)     │             │
│   └───────────┘   user events    └──────┬───────┘             │
│                                         │                       │
│                                         │ calls                 │
│                                         ▼                       │
│                                  ┌──────────────┐              │
│                                  │    MODEL     │              │
│                                  │  (Data+DB)   │              │
│                                  └──────────────┘              │
│                                                                 │
└─────────────────────────────────────────────────────────────────┘
```

### Tại sao chọn MVC?

| Tiêu chí | Giải thích |
|---|---|
| **Tách biệt trách nhiệm** | Model không biết gì về UI; View không truy vấn DB trực tiếp. Mỗi lớp có một vai trò rõ ràng |
| **Dễ bảo trì** | Thay đổi giao diện không ảnh hưởng logic; thay đổi DB không ảnh hưởng UI |
| **Dễ mở rộng** | Thêm tính năng mới (vd: quản lý điểm) chỉ cần thêm Model + Controller mới |
| **Dễ kiểm thử** | Controller và Model có thể test độc lập mà không cần khởi động UI |
| **Phù hợp Qt** | Qt Signal-Slot là cơ chế tự nhiên để kết nối View ↔ Controller theo hướng reactive |
| **Chuẩn công nghiệp** | MVC là kiến trúc phổ biến nhất cho desktop app, dễ onboard developer mới |

### Phân công trong code

| File | Layer | Vai trò |
|---|---|---|
| `student.h/cpp`, `class_model.h/cpp`, `department.h/cpp` | **Model** | Định nghĩa entity, validation dữ liệu |
| `databasemanager.h/cpp` | **Model** (Persistence) | Tất cả truy vấn SQLite, Singleton pattern |
| `studentcontroller.h/cpp` | **Controller** | Validate nghiệp vụ, gọi DB, phát signal |
| `classcontroller.h/cpp` | **Controller** | Logic quản lý lớp, kiểm tra ràng buộc |
| `departmentcontroller.h/cpp` | **Controller** | Logic quản lý khoa |
| `mainwindow.h/cpp` | **View** | Hiển thị bảng, nhận sự kiện nút bấm |
| `studentdialog.h/cpp` | **View** | Form nhập/sửa sinh viên |
| `*.ui` | **View** (XML) | Layout giao diện Qt Designer |

---

## 4. Use Case Diagram

```
╔══════════════════════════════════════════════════════════════════╗
║           HỆ THỐNG QUẢN LÝ HỒ SƠ SINH VIÊN                    ║
╠══════════════════════════════════════════════════════════════════╣
║                                                                  ║
║   ┌─── UC Hệ Thống ────────────────────────────────────────┐   ║
║   │  UC00: Đăng nhập hệ thống                              │   ║
║   │  UC01: Xem dashboard / thống kê tổng quan              │   ║
║   └────────────────────────────────────────────────────────┘   ║
║                                                                  ║
║   ┌─── UC Quản Lý Sinh Viên ───────────────────────────────┐   ║
║   │  UC10: Xem danh sách sinh viên (bảng)                  │   ║
║   │  UC11: Thêm sinh viên mới                              │   ║
║   │  UC12: Sửa thông tin sinh viên                         │   ║
║   │  UC13: Xóa sinh viên                                   │   ║
║   │  UC14: Tìm kiếm theo mã SV hoặc tên                   │   ║
║   │  UC15: Xuất danh sách ra file CSV                      │   ║
║   └────────────────────────────────────────────────────────┘   ║
║                                                                  ║
║   ┌─── UC Quản Lý Lớp Học ────────────────────────────────┐   ║
║   │  UC20: Xem danh sách lớp học                           │   ║
║   │  UC21: Thêm lớp học mới                                │   ║
║   │  UC22: Sửa thông tin lớp học                           │   ║
║   │  UC23: Xóa lớp học (ràng buộc: không có sinh viên)    │   ║
║   │  UC24: Gán lớp vào khoa                                │   ║
║   └────────────────────────────────────────────────────────┘   ║
║                                                                  ║
║   ┌─── UC Quản Lý Khoa ───────────────────────────────────┐   ║
║   │  UC30: Xem danh sách khoa                              │   ║
║   │  UC31: Thêm khoa mới                                   │   ║
║   │  UC32: Sửa thông tin khoa                              │   ║
║   │  UC33: Xóa khoa (ràng buộc: không có lớp)             │   ║
║   └────────────────────────────────────────────────────────┘   ║
║                                                                  ║
╚══════════════════════════════════════════════════════════════════╝
                      ▲
                      │ «thực hiện tất cả»
                  ┌───┴────┐
                  │  Admin │
                  └────────┘

Quan hệ include / extend:
  UC11 «include» UC14   → Khi thêm SV, kiểm tra mã trùng (tìm kiếm ngầm)
  UC12 «include» UC14   → Khi sửa SV, load dữ liệu từ DB
  UC23 «extend»  UC13   → Xóa lớp mở rộng từ hành vi xóa thông thường
```

---

## 5. Class Diagram

### Tầng Model

```
┌──────────────────────────────────┐
│           Department             │
│──────────────────────────────────│
│ - m_id          : int            │
│ - m_name        : QString        │
│ - m_description : QString        │
│──────────────────────────────────│
│ + Department()                   │
│ + Department(id, name, desc)     │
│ + getId()       : int            │
│ + getName()     : QString        │
│ + getDescription() : QString     │
│ + setId(int)                     │
│ + setName(QString)               │
│ + isValid()     : bool           │
│ + toString()    : QString        │
└────────────────┬─────────────────┘
                 │ 1
                 │ has many
                 │ *
┌────────────────▼─────────────────┐
│           ClassModel             │
│──────────────────────────────────│
│ - m_id             : int         │
│ - m_name           : QString     │
│ - m_departmentId   : int         │
│ - m_departmentName : QString     │  ← denormalized (display only)
│──────────────────────────────────│
│ + ClassModel()                   │
│ + ClassModel(id, name, deptId, …)│
│ + getId()          : int         │
│ + getName()        : QString     │
│ + getDepartmentId(): int         │
│ + setId(int)                     │
│ + setName(QString)               │
│ + isValid()        : bool        │
│ + toString()       : QString     │
└────────────────┬─────────────────┘
                 │ 1
                 │ has many
                 │ *
┌────────────────▼─────────────────┐
│             Student              │
│──────────────────────────────────│
│ - m_studentId    : QString       │  ← PK, TEXT
│ - m_fullName     : QString       │
│ - m_dateOfBirth  : QDate         │
│ - m_gender       : Gender (enum) │
│ - m_email        : QString       │
│ - m_phone        : QString       │
│ - m_address      : QString       │
│ - m_classId      : int           │  ← FK → classes.id
│ - m_className    : QString       │  ← denormalized
│ - m_deptName     : QString       │  ← denormalized
│──────────────────────────────────│
│ + Student()                      │
│ + Student(id, name, dob, …)      │
│ + getStudentId()  : QString      │
│ + getFullName()   : QString      │
│ + getDateOfBirth(): QDate        │
│ + genderToString(): QString      │
│ + isValid()       : bool         │
│ + toString()      : QString      │
│ «static»                         │
│ + genderFromString(s): Gender    │
│ + isValidEmail(s) : bool         │
│ + isValidPhone(s) : bool         │
└──────────────────────────────────┘
```

### Tầng Database

```
┌──────────────────────────────────────────────────────────────┐
│                 DatabaseManager  «Singleton»                  │
│──────────────────────────────────────────────────────────────│
│ - instance : DatabaseManager  (static)                       │
│ - m_db     : QSqlDatabase                                    │
│ - m_lastError : QString                                      │
│ - m_connected : bool                                         │
│──────────────────────────────────────────────────────────────│
│ + instance()        : DatabaseManager&   «static»            │
│ + initialize(path)  : bool                                   │
│ + close()           : void                                   │
│ + isConnected()     : bool                                   │
│ + lastError()       : QString                                │
│                                                              │
│ ── DEPARTMENT CRUD ──────────────────────────────────────── │
│ + addDepartment(Department)     : bool                       │
│ + updateDepartment(Department)  : bool                       │
│ + deleteDepartment(id)          : bool                       │
│ + getAllDepartments()           : QList<Department>          │
│ + getDepartmentById(id)         : Department                 │
│ + departmentHasClasses(id)      : bool                       │
│                                                              │
│ ── CLASS CRUD ───────────────────────────────────────────── │
│ + addClass(ClassModel)          : bool                       │
│ + updateClass(ClassModel)       : bool                       │
│ + deleteClass(id)               : bool                       │
│ + getAllClasses()               : QList<ClassModel>          │
│ + getClassesByDepartment(id)    : QList<ClassModel>          │
│ + classHasStudents(id)          : bool                       │
│                                                              │
│ ── STUDENT CRUD ─────────────────────────────────────────── │
│ + addStudent(Student)           : bool                       │
│ + updateStudent(Student)        : bool                       │
│ + deleteStudent(studentId)      : bool                       │
│ + getAllStudents()              : QList<Student>             │
│ + searchStudents(keyword)       : QList<Student>             │
│ + getStudentById(id)            : Student                    │
│ + studentIdExists(id)           : bool                       │
│                                                              │
│ ── AUTH & STATS ─────────────────────────────────────────── │
│ + verifyLogin(user, pass)       : bool                       │
│ + countStudents()               : int                        │
│ + countClasses()                : int                        │
│ + countDepartments()            : int                        │
│                                                              │
│ ── PRIVATE ──────────────────────────────────────────────── │
│ - createTables()                : bool                       │
│ - insertDefaultData()           : bool                       │
│ - hashPassword(s)               : QString  (SHA-256)         │
└──────────────────────────────────────────────────────────────┘
```

### Tầng Controller

```
┌────────────────────────────────────────────┐
│          StudentController  : QObject       │
│────────────────────────────────────────────│
│ - m_db        : DatabaseManager&           │
│ - m_lastError : QString                    │
│────────────────────────────────────────────│
│ + addStudent(Student)    : bool            │
│ + updateStudent(Student) : bool            │
│ + deleteStudent(id)      : bool            │
│ + getAllStudents()        : QList<Student>  │
│ + searchStudents(kw)     : QList<Student>  │
│ + validateStudent(s, isNew): QString       │
│ + exportToCSV(path, list): bool            │
│ + lastError()            : QString         │
│────────────────────────────────────────────│
│ «signals»                                  │
│ + studentAdded(Student)                    │
│ + studentUpdated(Student)                  │
│ + studentDeleted(QString)                  │
│ + errorOccurred(QString)                   │
└────────────────────────────────────────────┘

┌────────────────────────────────────────────┐
│           ClassController  : QObject        │
│────────────────────────────────────────────│
│ + addClass(ClassModel)      : bool         │
│ + updateClass(ClassModel)   : bool         │
│ + deleteClass(id)           : bool         │
│ + getAllClasses()           : QList<…>     │
│ + validateClass(ClassModel) : QString      │
│ «signals» classAdded, classUpdated, …      │
└────────────────────────────────────────────┘

┌────────────────────────────────────────────┐
│         DepartmentController  : QObject     │
│────────────────────────────────────────────│
│ + addDepartment(Department)    : bool       │
│ + updateDepartment(Department) : bool       │
│ + deleteDepartment(id)         : bool       │
│ + getAllDepartments()          : QList<…>  │
│ «signals» departmentAdded, …               │
└────────────────────────────────────────────┘
```

### Tầng View

```
┌──────────────────────────────────────────────────┐
│              MainWindow  : QMainWindow            │
│──────────────────────────────────────────────────│
│ - ui                : Ui::MainWindow*             │
│ - m_studentCtrl     : StudentController*          │
│ - m_classCtrl       : ClassController*            │
│ - m_deptCtrl        : DepartmentController*       │
│──────────────────────────────────────────────────│
│ «slots»                                           │
│ + onAddStudent()   + onEditStudent()              │
│ + onDeleteStudent()+ onSearchStudent()            │
│ + onExportCSV()    + refreshStudentTable()        │
│ + onAddClass()     + onEditClass()                │
│ + onDeleteClass()  + refreshClassTable()          │
│ + onAddDepartment()+ onEditDepartment()           │
│ + onDeleteDepartment()                            │
│ + updateStatusBar()+ onTabChanged(int)            │
└──────────────────────────────────────────────────┘

MainWindow «has-a» StudentController
MainWindow «has-a» ClassController
MainWindow «has-a» DepartmentController

StudentDialog «reads» ClassController
ClassDialog   «reads» DepartmentController
```

---

## 6. Sequence Diagram – Luồng Thêm Sinh Viên

```
┌────────┐  ┌──────────────┐  ┌───────────────┐  ┌──────────────────┐  ┌─────────────────┐
│  User  │  │  MainWindow  │  │ StudentDialog  │  │StudentController │  │DatabaseManager  │
└───┬────┘  └──────┬───────┘  └───────┬───────┘  └────────┬─────────┘  └────────┬────────┘
    │               │                  │                    │                      │
    │ click "Thêm SV"│                 │                    │                      │
    │──────────────▶│                  │                    │                      │
    │               │                  │                    │                      │
    │               │ new StudentDialog│                    │                      │
    │               │─────────────────▶│                    │                      │
    │               │                  │                    │                      │
    │               │                  │ getAllClasses()     │                      │
    │               │                  │───────────────────▶│                      │
    │               │                  │                    │ getAllClasses()       │
    │               │                  │                    │─────────────────────▶│
    │               │                  │                    │◀─────────────────────│
    │               │                  │◀───────────────────│  QList<ClassModel>   │
    │               │                  │                    │                      │
    │               │                  │ populate comboClass│                      │
    │               │                  │ (load classes)     │                      │
    │               │                  │                    │                      │
    │◀──────────────────────────────────│ show dialog        │                      │
    │  Nhập thông tin sinh viên         │                    │                      │
    │──────────────────────────────────▶│                    │                      │
    │                                   │                    │                      │
    │  click "Lưu Thông Tin"            │                    │                      │
    │──────────────────────────────────▶│                    │                      │
    │                                   │                    │                      │
    │                                   │ validate local     │                      │
    │                                   │ (không rỗng, email,│                      │
    │                                   │  phone format)     │                      │
    │                                   │                    │                      │
    │                                   │ [invalid] show QMessageBox::warning      │
    │◀──────────────────────────────────│ return             │                      │
    │                                   │                    │                      │
    │                                   │ [valid] accept()   │                      │
    │               │◀─────────────────│                    │                      │
    │               │                  │                    │                      │
    │               │ getStudent()     │                    │                      │
    │               │─────────────────▶│                    │                      │
    │               │◀─────────────────│ Student object     │                      │
    │               │                  │                    │                      │
    │               │ addStudent(s)    │                    │                      │
    │               │──────────────────────────────────────▶│                      │
    │               │                  │                    │                      │
    │               │                  │                    │ validateStudent()     │
    │               │                  │                    │ (trùng mã, v.v.)     │
    │               │                  │                    │                      │
    │               │                  │                    │ studentIdExists()?   │
    │               │                  │                    │─────────────────────▶│
    │               │                  │                    │◀─────────────────────│
    │               │                  │                    │  false (ok)          │
    │               │                  │                    │                      │
    │               │                  │                    │ addStudent(s)        │
    │               │                  │                    │─────────────────────▶│
    │               │                  │                    │  INSERT INTO students│
    │               │                  │                    │◀─────────────────────│
    │               │                  │                    │  true                │
    │               │                  │                    │                      │
    │               │◀───────────────────────────────────── │ emit studentAdded(s) │
    │               │                  │                    │                      │
    │               │ refreshStudentTable()                 │                      │
    │               │ showInfo("Thêm thành công!")          │                      │
    │◀──────────────│                  │                    │                      │
    │  [Bảng được cập nhật]            │                    │                      │
```

---

## 7. Sequence Diagram – Luồng Đăng Nhập

```
┌────────┐  ┌─────────────┐  ┌─────────────────┐
│  User  │  │ LoginDialog │  │ DatabaseManager  │
└───┬────┘  └──────┬──────┘  └────────┬─────────┘
    │               │                  │
    │ app.start()   │                  │
    │──────────────▶│                  │
    │               │ show()           │
    │◀──────────────│                  │
    │               │                  │
    │ nhập user/pass│                  │
    │──────────────▶│                  │
    │               │                  │
    │ click "Đăng Nhập"               │
    │──────────────▶│                  │
    │               │                  │
    │               │ [trống] lblError.show()     │
    │◀──────────────│ return           │
    │               │                  │
    │               │ verifyLogin(u,p) │
    │               │─────────────────▶│
    │               │                  │ SELECT password WHERE username=u
    │               │                  │ compare hash(p) == stored_hash
    │               │◀─────────────────│
    │               │  true / false    │
    │               │                  │
    │               │ [false] m_attempts++
    │               │ [attempts==3] reject() → app close
    │               │ [attempts<3] lblError: "còn N lần"
    │◀──────────────│                  │
    │               │                  │
    │               │ [true] accept()  │
    │               │                  │
    │ MainWindow.show()               │
    │◀──────────────│                  │
```

---

## 8. Sequence Diagram – Luồng Tìm Kiếm

```
┌────────┐  ┌──────────────┐  ┌──────────────────┐  ┌─────────────────┐
│  User  │  │  MainWindow  │  │StudentController │  │DatabaseManager  │
└───┬────┘  └──────┬───────┘  └────────┬─────────┘  └────────┬────────┘
    │               │                   │                       │
    │ nhập keyword  │                   │                       │
    │──────────────▶│                   │                       │
    │               │                   │                       │
    │ click "Tìm" / │                   │                       │
    │ Enter         │                   │                       │
    │──────────────▶│                   │                       │
    │               │                   │                       │
    │               │ [keyword rỗng]    │                       │
    │               │ refreshStudentTable() → getAllStudents()   │
    │               │                   │                       │
    │               │ [keyword có nội dung]                     │
    │               │ searchStudents(kw) │                       │
    │               │──────────────────▶│                       │
    │               │                   │ searchStudents(kw)    │
    │               │                   │──────────────────────▶│
    │               │                   │                       │ SELECT ... WHERE
    │               │                   │                       │ student_id LIKE %kw%
    │               │                   │                       │ OR full_name LIKE %kw%
    │               │                   │◀──────────────────────│
    │               │                   │  QList<Student>        │
    │               │◀──────────────────│                       │
    │               │  filtered list    │                       │
    │               │                   │                       │
    │               │ populateStudentTable(filtered)            │
    │               │ lblCount: "Tìm thấy N kết quả"           │
    │◀──────────────│                   │                       │
    │  [Bảng lọc]   │                   │                       │
    │               │                   │                       │
    │ click "Xóa lọc"│                  │                       │
    │──────────────▶│                   │                       │
    │               │ lineSearch.clear()│                       │
    │               │ refreshStudentTable() [tải lại toàn bộ]  │
    │◀──────────────│                   │                       │
```

---

## 9. Database Schema & Mapping OOP

### Sơ đồ ERD

```
┌───────────────┐         ┌─────────────────┐         ┌────────────────────┐
│  departments  │  1    * │     classes      │  1    * │      students      │
│───────────────│─────────│─────────────────│─────────│────────────────────│
│ id        PK  │         │ id          PK  │         │ student_id  PK TEXT│
│ name          │         │ name            │         │ full_name          │
│ description   │         │ department_id FK│         │ date_of_birth      │
│ created_at    │         │ created_at      │         │ gender   CHECK(…)  │
└───────────────┘         └─────────────────┘         │ email              │
                                                       │ phone              │
                                                       │ address            │
                                                       │ class_id       FK  │
                                                       │ created_at         │
                                                       │ updated_at         │
                                                       └────────────────────┘

┌──────────────┐
│    users     │
│──────────────│
│ id       PK  │
│ username     │
│ password     │  ← SHA-256 hex hash
│ role         │
│ created_at   │
└──────────────┘
```

### Mapping OOP ↔ Database

| C++ Class | Bảng DB | Khóa chính | Ghi chú |
|---|---|---|---|
| `Department` | `departments` | `id` AUTO | Cấp cao nhất |
| `ClassModel` | `classes` | `id` AUTO | FK → departments |
| `Student` | `students` | `student_id` TEXT | FK → classes |
| *(auth)* | `users` | `id` AUTO | SHA-256 password |

**Denormalization trong C++**: Các trường `m_className`, `m_deptName` trong class `Student` không có trong DB nhưng được load qua JOIN query để hiển thị UI nhanh hơn, tránh query lại nhiều lần.

**Tại sao student_id là TEXT thay vì AUTO INT?**  
→ Mã sinh viên trong thực tế (SV001, MSSV2024001, v.v.) không phải số tuần tự, cần do người dùng tự định nghĩa theo quy tắc trường.

### Ràng buộc Cascade

```
DELETE departments (id=1)
    → RESTRICT nếu còn classes có department_id=1
    → Controller kiểm tra trước: departmentHasClasses()

DELETE classes (id=5)
    → RESTRICT nếu còn students có class_id=5
    → Controller kiểm tra trước: classHasStudents()

UPDATE departments.id  → CASCADE cập nhật classes.department_id
UPDATE classes.id      → CASCADE cập nhật students.class_id
```

---

## 10. Mô Tả Từng Module

### 10.1. Department (src/models/department.h/cpp)

Class đại diện cho Khoa. Đây là cấp cao nhất trong phân cấp.

- **Encapsulation**: tất cả thuộc tính `private`, truy cập qua getter/setter
- **Setter validation**: `setName()` throw exception nếu tên rỗng
- `isValid()`: kiểm tra object hợp lệ trước khi lưu

### 10.2. ClassModel (src/models/class_model.h/cpp)

Class đại diện Lớp học. Tên `ClassModel` tránh xung đột với keyword `class` của C++.

- Chứa `m_departmentName` là trường denormalized phục vụ hiển thị
- `getDepartmentId()` là FK liên kết với bảng departments

### 10.3. Student (src/models/student.h/cpp)

Class phức tạp nhất, đại diện Sinh viên.

- Enum `Gender { Male, Female, Other }` thay vì dùng magic string
- Static methods: `isValidEmail()`, `isValidPhone()` – dùng `QRegularExpression`
- `genderToString()` / `genderFromString()` – chuyển đổi 2 chiều
- `isValid()` – kiểm tra tất cả trường bắt buộc

### 10.4. DatabaseManager (src/database/databasemanager.h/cpp)

**Pattern**: Singleton – đảm bảo chỉ có 1 kết nối SQLite trong toàn ứng dụng.

- `initialize()`: mở file .db, tạo bảng nếu chưa có, seed dữ liệu mẫu
- `createTables()`: DDL tạo 4 bảng với FOREIGN KEY
- `insertDefaultData()`: chèn dữ liệu mẫu lần đầu chạy
- Tất cả CRUD dùng `QSqlQuery` với **prepared statements** (chống SQL injection)
- Query sinh viên dùng `LEFT JOIN` lấy tên lớp + tên khoa trong 1 lần truy vấn
- `hashPassword()`: SHA-256 qua `QCryptographicHash`

### 10.5. StudentController (src/controllers/studentcontroller.h/cpp)

**Pattern**: Mediator + Observer (via Qt Signal-Slot)

- `validateStudent()`: kiểm tra tất cả nghiệp vụ – rỗng, trùng mã, format email/phone
- `addStudent()`: validate → gọi DB → emit signal → View cập nhật
- `exportToCSV()`: ghi file với BOM UTF-8 để Excel đọc được tiếng Việt
- Phát các signal: `studentAdded`, `studentUpdated`, `studentDeleted`, `errorOccurred`

### 10.6. ClassController / DepartmentController

Tương tự StudentController nhưng đơn giản hơn.

- `deleteClass()`: kiểm tra `classHasStudents()` trước khi xóa → bảo vệ referential integrity
- `deleteDepartment()`: kiểm tra `departmentHasClasses()` trước khi xóa

### 10.7. MainWindow (src/views/mainwindow.h/cpp)

Cửa sổ chính với 3 tab: Sinh Viên | Lớp Học | Khoa.

- `setupStudentTable()`: cấu hình QTableWidget – tiêu đề, resize mode, không edit trực tiếp
- `setupConnections()`: kết nối toàn bộ signal-slot giữa buttons và slots
- `populateStudentTable()`: render `QList<Student>` vào bảng
- `onStudentTableDoubleClick()`: double-click mở form sửa
- `updateStatusBar()`: hiện thống kê số lượng ở thanh dưới

### 10.8. StudentDialog (src/views/studentdialog.h/cpp)

Form thêm/sửa sinh viên.

- Constructor nhận `const Student*` – nếu `nullptr` → chế độ thêm mới; nếu có → chế độ sửa
- `loadClasses()`: điền combobox lớp từ ClassController
- `validateForm()`: real-time enable/disable nút Lưu
- `onAccept()`: validate kỹ trước khi `accept()`
- `getStudent()`: build object Student từ dữ liệu form

### 10.9. LoginDialog (src/views/logindialog.h/cpp)

- Giới hạn 3 lần đăng nhập sai → `reject()` đóng app
- Toggle show/hide password qua nút 👁
- SHA-256 hash được verify trong `DatabaseManager::verifyLogin()`

---

## 11. Các Nguyên Lý OOP Áp Dụng

### 11.1. Encapsulation (Đóng gói)

```cpp
class Student {
private:                          // Thuộc tính ẩn
    QString m_studentId;
    QString m_fullName;
    QDate   m_dateOfBirth;

public:
    QString getStudentId() const; // Chỉ đọc qua getter
    void setFullName(const QString&); // Kiểm soát ghi qua setter
};
```

### 11.2. Validation trong Setter

```cpp
void Student::setEmail(const QString& email) {
    if (!email.isEmpty() && !isValidEmail(email))
        throw std::invalid_argument("Email không đúng định dạng");
    m_email = email.trimmed().toLower();
}
```

### 11.3. Static Utility Methods

```cpp
// Dùng được mà không cần tạo object
bool Student::isValidEmail(const QString& email) {
    static QRegularExpression re(R"(^[a-zA-Z0-9._%+\-]+@[a-zA-Z0-9.\-]+\.[a-zA-Z]{2,}$)");
    return re.match(email).hasMatch();
}
```

### 11.4. Singleton Pattern (DatabaseManager)

```cpp
DatabaseManager& DatabaseManager::instance() {
    static DatabaseManager inst; // Chỉ tạo 1 lần, tồn tại suốt app
    return inst;
}
// Sử dụng:
DatabaseManager::instance().addStudent(s);
```

### 11.5. Polymorphism (Signal-Slot)

```cpp
// Controller phát signal
emit studentAdded(student);

// Bất kỳ View nào cũng có thể lắng nghe
connect(m_studentCtrl, &StudentController::studentAdded,
        this, &MainWindow::refreshStudentTable);
```

### 11.6. Composition (Dependency Injection)

```cpp
// MainWindow chứa Controller, không kế thừa
class MainWindow : public QMainWindow {
    StudentController*    m_studentCtrl;  // HAS-A
    ClassController*      m_classCtrl;
    DepartmentController* m_deptCtrl;
};
```

---

## 12. Test Cases

### TC01–TC05: Thêm Sinh Viên

| ID | Kịch bản | Input | Expected Output |
|---|---|---|---|
| TC01 | Thêm hợp lệ | Mã: SV100, Tên: Nguyễn B, Lớp: CNTT-K22A | Thêm thành công, hiện trong bảng |
| TC02 | Trùng mã SV | Mã: SV001 (đã tồn tại) | Lỗi: "Mã sinh viên 'SV001' đã tồn tại" |
| TC03 | Bỏ trống tên | Tên: (rỗng) | Lỗi: "Họ và tên không được để trống" |
| TC04 | Không chọn lớp | Lớp: (-- Chọn lớp --) | Lỗi: "Vui lòng chọn lớp học" |
| TC05 | Bỏ trống mã SV | Mã: (rỗng) | Nút Lưu bị disable |

### TC06–TC10: Validation Dữ Liệu

| ID | Kịch bản | Input | Expected Output |
|---|---|---|---|
| TC06 | Email sai định dạng | Email: "abc@" | Lỗi: "Email không đúng định dạng" |
| TC07 | SĐT ngắn | Phone: "123" | Lỗi: "Số điện thoại không hợp lệ" |
| TC08 | SĐT không bắt đầu 0 | Phone: "1901234567" | Lỗi: "Số điện thoại không hợp lệ" |
| TC09 | Ngày sinh tương lai | DOB: 01/01/2099 | Dialog: "Có chắc ngày sinh đúng không?" |
| TC10 | Email rỗng (OK) | Email: (rỗng) | Cho phép lưu (email không bắt buộc) |

### TC11–TC15: Tìm Kiếm

| ID | Kịch bản | Input | Expected Output |
|---|---|---|---|
| TC11 | Tìm theo tên | "Nguyễn" | Hiện SV có "Nguyễn" trong tên |
| TC12 | Tìm theo mã | "SV00" | Hiện SV có mã chứa "SV00" |
| TC13 | Không tìm thấy | "XYZXYZ" | Bảng rỗng, count = 0 |
| TC14 | Tìm keyword rỗng | (rỗng) | Hiện toàn bộ sinh viên |
| TC15 | Xóa lọc | Click "Xóa lọc" | Reset bảng về toàn bộ |

### TC16–TC20: Ràng Buộc Xóa

| ID | Kịch bản | Input | Expected Output |
|---|---|---|---|
| TC16 | Xóa SV hợp lệ | Chọn SV, xác nhận | Xóa thành công |
| TC17 | Xóa lớp có SV | Xóa CNTT-K22A (còn SV) | Lỗi: "Không thể xóa lớp đang có sinh viên" |
| TC18 | Xóa khoa có lớp | Xóa khoa CNTT (còn lớp) | Lỗi: "Không thể xóa khoa đang có lớp học" |
| TC19 | Hủy xác nhận xóa | Click "Không" trong hộp thoại | Không xóa, giữ nguyên dữ liệu |
| TC20 | Không chọn hàng rồi click Xóa | (không chọn) | Lỗi: "Vui lòng chọn sinh viên cần xóa" |

### TC21–TC25: Đăng Nhập

| ID | Kịch bản | Input | Expected Output |
|---|---|---|---|
| TC21 | Đăng nhập đúng | admin / admin123 | Mở MainWindow |
| TC22 | Sai mật khẩu | admin / wrong | Lỗi: "còn 2 lần thử" |
| TC23 | Sai 3 lần | (3 lần sai) | App đóng |
| TC24 | Bỏ trống | (rỗng) | Lỗi: "Vui lòng nhập đầy đủ" |
| TC25 | Toggle password | Click 👁 | Hiện/ẩn mật khẩu |

### TC26–TC27: Xuất CSV

| ID | Kịch bản | Expected Output |
|---|---|---|
| TC26 | Xuất CSV thành công | File .csv tạo được, mở Excel đọc được tiếng Việt |
| TC27 | Hủy hộp thoại chọn file | Không tạo file |

---

## 13. Hướng Dẫn Build & Chạy

### Yêu Cầu

| Phần mềm | Phiên bản tối thiểu | Ghi chú |
|---|---|---|
| Qt | 6.4+ | Cần Qt Widgets + Qt SQL |
| CMake | 3.16+ | Hoặc dùng qmake nếu muốn |
| GCC / MSVC / Clang | GCC 11 / MSVC 2022 / Clang 14 | C++17 |
| Qt Creator | 10+ | Khuyên dùng |
| SQLite | Tích hợp sẵn Qt | Không cần cài thêm |

### Cách 1 – Qt Creator (Khuyên Dùng)

```
1.  Mở Qt Creator
2.  File → Open Project
3.  Chọn StudentMS/CMakeLists.txt
4.  Chọn Kit: Qt 6.x Desktop (GCC/MSVC)
5.  Ctrl + B  → Build
6.  Ctrl + R  → Run
7.  Đăng nhập: admin / admin123
```

### Cách 2 – Terminal (Linux/macOS)

```bash
cd StudentMS
mkdir -p build && cd build
cmake .. -DCMAKE_PREFIX_PATH=/opt/Qt/6.5.0/gcc_64
cmake --build . --parallel $(nproc)
./StudentMS
```

### Cách 3 – Windows (MSVC)

```cmd
mkdir build
cd build
cmake .. -G "Visual Studio 17 2022" -A x64 ^
         -DCMAKE_PREFIX_PATH=C:\Qt\6.5.0\msvc2022_64
cmake --build . --config Release
Release\StudentMS.exe
```

### Cách 4 – Windows (MinGW)

```cmd
mkdir build && cd build
cmake .. -G "MinGW Makefiles" ^
         -DCMAKE_PREFIX_PATH=C:\Qt\6.5.0\mingw_64
mingw32-make -j4
StudentMS.exe
```

### File Database

- DB tự tạo tại: `studentms.db` trong thư mục chạy
- Muốn reset: xóa file `studentms.db`, chạy lại app → tự seed lại
- Muốn dùng schema SQL riêng: chạy `docs/schema.sql` với `sqlite3` CLI

```bash
sqlite3 studentms.db < docs/schema.sql
```

### Deploy (Windows)

```bash
# Sau khi build, copy DLL Qt cần thiết
cd build/Release
windeployqt StudentMS.exe
```

---

*Tài liệu được tạo cho môn Kỹ Thuật Phần Mềm (Software Engineering)*  
*Phiên bản: 1.0 | Ngôn ngữ: C++17 + Qt 6 | Kiến trúc: MVC*
