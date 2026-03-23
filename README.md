# 🎓 StudentMS – Phần Mềm Quản Lý Hồ Sơ Sinh Viên

![Qt](https://img.shields.io/badge/Qt-6.4+-41CD52?logo=qt&logoColor=white)
![C++](https://img.shields.io/badge/C++-17-00599C?logo=cplusplus&logoColor=white)
![SQLite](https://img.shields.io/badge/SQLite-003B57?logo=sqlite&logoColor=white)
![License](https://img.shields.io/badge/License-MIT-blue)

Ứng dụng desktop quản lý hồ sơ sinh viên chạy **hoàn toàn offline**, xây dựng bằng **C++ + Qt 6 + SQLite** theo kiến trúc **MVC**.

---

## 📋 Tính Năng

| Chức năng | Mô tả |
|---|---|
| 👨‍🎓 Quản lý Sinh Viên | Thêm, sửa, xóa, tìm kiếm theo mã/tên |
| 📚 Quản lý Lớp Học | CRUD lớp, gán vào khoa |
| 🏫 Quản lý Khoa | CRUD khoa |
| 🔍 Tìm kiếm | Tìm real-time theo mã SV hoặc tên |
| 📥 Xuất CSV | Export danh sách ra file CSV (UTF-8, Excel-ready) |
| 🔐 Đăng nhập | Xác thực SHA-256, khóa sau 3 lần sai |
| ✅ Validate | Email, SĐT, ngày sinh, trùng mã, bắt buộc... |

---

## 🚀 Quick Start

### Yêu Cầu
- Qt 6.4+ (Qt Widgets + Qt SQL)
- CMake 3.16+
- Compiler C++17 (GCC 11 / MSVC 2022 / Clang 14)

### Build với Qt Creator
```
1. Mở Qt Creator → File → Open Project
2. Chọn CMakeLists.txt
3. Ctrl+B (Build) → Ctrl+R (Run)
```

### Build thủ công
```bash
mkdir build && cd build
cmake .. -DCMAKE_PREFIX_PATH=/path/to/Qt/6.x/gcc_64
cmake --build . --parallel 4
./StudentMS
```

### Tài Khoản Mặc Định
```
Username: admin
Password: admin123
```

---

## 📁 Cấu Trúc Project

```
StudentMS/
├── CMakeLists.txt          ← Cấu hình build
├── src/
│   ├── main.cpp            ← Entry point
│   ├── models/             ← [Model] Department, ClassModel, Student
│   ├── database/           ← [Model] DatabaseManager (Singleton + SQLite)
│   ├── controllers/        ← [Controller] Business logic + Signals
│   └── views/              ← [View] Qt Widgets + Dialogs
├── ui/                     ← Qt Designer XML (.ui)
└── docs/
    ├── design.md           ← Tài liệu thiết kế đầy đủ (UML, Sequence, v.v.)
    └── schema.sql          ← Script SQL tạo database
```

---

## 🏗️ Kiến Trúc MVC

```
View (Qt UI) ←──signal/slot──→ Controller ──calls──→ Model (Data + SQLite)
```

- **Model**: `Student`, `ClassModel`, `Department`, `DatabaseManager`
- **View**: `MainWindow`, `StudentDialog`, `ClassDialog`, `DepartmentDialog`, `LoginDialog`
- **Controller**: `StudentController`, `ClassController`, `DepartmentController`

---

## 📖 Tài Liệu

Xem tài liệu thiết kế đầy đủ tại [`docs/design.md`](docs/design.md):

- Use Case Diagram
- Class Diagram (toàn bộ tầng Model, Controller, View)
- Sequence Diagram (Thêm SV, Đăng nhập, Tìm kiếm)
- Giải thích OOP: Encapsulation, Singleton, Signal-Slot
- Mapping OOP ↔ Database
- Test Cases (27 test case)
- Hướng dẫn build chi tiết (4 cách)

---

## 🔑 Công Nghệ Sử Dụng

| Công nghệ | Mục đích |
|---|---|
| Qt Widgets | Giao diện desktop |
| Qt Designer (.ui) | Layout XML |
| QSqlDatabase + QSQLITE | Kết nối SQLite |
| QRegularExpression | Validate email, phone |
| QCryptographicHash | SHA-256 mật khẩu |
| CMake | Build system |

---

*Dự án học thuật – Môn Kỹ Thuật Phần Mềm*
