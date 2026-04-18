# BÁO CÁO KIỂM THỬ PHẦN MỀM
**Dự án:** Phần Mềm Quản Lý Hồ Sơ Sinh Viên
**Nền tảng:** Windows Desktop (C++ Qt 6, Hệ quản trị cơ sở dữ liệu SQLite)

---

## 1. Kế hoạch kiểm thử

**Mục tiêu:** Đảm bảo toàn bộ các module của phần mềm (Đăng nhập, Quản lý Khoa, Quản lý Lớp, Quản lý Sinh viên) vận hành chính xác, ổn định, giao diện thân thiện và kiến trúc hệ thống chặt chẽ, tối ưu hiệu năng theo mô hình MVC. 
**Môi trường kiểm thử:** Hệ điều hành Windows, độ phân giải màn hình chuẩn, tương tác qua chuột và bàn phím.

### 1.1. Kiểm thử chức năng (Functional Testing)
Kiểm thử các nghiệp vụ chính của phần mềm dựa trên dữ liệu đầu vào và kết quả đầu ra.

| Testcase ID | Mục đích | Các bước thực hiện | Kết quả dự kiến | Kết quả nhận được |
| :--- | :--- | :--- | :--- | :--- |
| **TC_AUTH_01** | Kiểm tra đăng nhập với tài khoản hợp lệ | 1. Mở phần mềm.<br>2. Nhập username: `admin`, password: `admin123`.<br>3. Nhấn "Đăng nhập". | Đăng nhập thành công, chuyển sang màn hình MainWindow. | Pass (Đăng nhập thành công, vào được hệ thống) |
| **TC_AUTH_02** | Kiểm tra đăng xuất phần mềm | 1. Tại MainWindow, nhấn nút "Đăng xuất" ở góc phải.<br>2. Xác nhận hộp thoại. | Hệ thống đóng MainWindow và hiển thị lại LoginDialog. | Pass (Vòng lặp Login hoạt động đúng, phần mềm không bị crash) |
| **TC_DEPT_01** | Kiểm tra thêm Khoa mới | 1. Qua tab Khoa, nhấn "Thêm Khoa".<br>2. Nhập Tên khoa, Mô tả và lưu. | Bảng Khoa cập nhật hiển thị dòng mới vừa thêm. | Pass (Không cho trùng tên khoa, lưu vào DB thành công) |
| **TC_CLASS_01** | Kiểm tra thêm Lớp học mới | 1. Qua tab Lớp học, nhấn "Thêm Lớp".<br>2. Nhập Mã/Tên lớp, chọn Khoa, Lưu. | Bảng Lớp học hiển thị Lớp mới và Khoa tương ứng. | Pass (Tự động load danh sách Khoa vào ComboBox để chọn) |
| **TC_STU_01** | Kiểm tra thêm Sinh viên thành công | 1. Trong tab Sinh Viên, nhấn "Thêm".<br>2. Điền đủ thông tin hợp lệ (Mã SV, Họ Tên, DOB định dạng đúng, Email, SĐT).<br>3. Bấm Lưu. | Hiện thông báo thêm thành công, bảng sinh viên load dòng tương ứng. Cột đếm tổng số SV tăng lên 1. | Pass (Duyệt thành công toàn bộ Validation thông tin) |
| **TC_STU_02** | Bắt lỗi Validation thêm Sinh viên | 1. Điền Email/SĐT sai chuẩn (ví dụ chữ).<br>2. Nhập thiếu "Mã SV" hoặc "Ngày sinh" > hiện tại.<br>3. Nhấn Lưu. | Hệ thống từ chối lưu, hiển thị bảng đỏ/popup thông báo chính xác lỗi định dạng. | Pass (Regex validation cho Email và Phone cản lại đúng quy trình) |
| **TC_STU_03** | Khả năng Tìm kiếm toàn diện (Đa trường) | 1. Tại ô tìm kiếm, nhập 1 địa chỉ, hoặc 1 email, hoặc 1 phần tên khoa (vd: `Công nghệ`).<br>2. Nhấn "Tìm". | Danh sách SV sẽ tự động được lọc sao cho khớp bất cứ trường thông tin nào với từ khóa. | Pass (SQL Query `LIKE` bằng `OR` hoạt động quét 7 cột hoàn hảo) |
| **TC_STU_04** | Kiểm tra Xuất báo cáo CSV | 1. Nhấn nút "Xuất CSV".<br>2. Chọn đường dẫn lưu file trên máy. | Xuất ra file `.csv` chứa toàn bộ Data sinh viên hiện hành với mã hóa UTF-8 BOM. | Pass (Mở bằng Excel không bị lỗi font tiếng Việt) |

---

### 1.2. Kiểm thử phi chức năng (Non-functional Testing)
Kiểm tra các khía cạnh về hiệu suất, bảo mật và trải nghiệm người dùng theo cấu trúc đơn giản.

| Test case | Các bước thực hiện | Kết quả trả về | Trạng thái |
| :--- | :--- | :--- | :--- |
| **Bảo mật: Hash Mật khẩu** | Mở tệp `studentms.db` bằng tool DB Browser, kiểm tra bảng `users`. | Mật khẩu tài khoản (admin) phải bị băm (SHA-256 hex string), không lưu plain text. | **Pass** |
| **Bảo mật: SQL Injection** | Ở ô Tìm kiếm SV hoặc Tên Đăng Nhập, nhập `' OR 1=1 --`. | Phần mềm không lỗi, không by-pass được login, chỉ coi đây là một chuỗi query thông thường. | **Pass** (Khống chế bằng `q.addBindValue()`) |
| **Hiệu năng: Load Table** | Giả lập cơ sở dữ liệu lên 50,000 Sinh viên, khởi động phần mềm. | Thời gian render bảng `QTableWidget` nhấp nháy không quá 2 giây, cuộn trang mượt. | **Pass** (Load dữ liệu không gây đơ luồng GUI chính) |
| **Trải nghiệm UI/UX** | Click vào các Dialog, kéo thu/phóng cửa sổ phần mềm. | UI phải Scale chuẩn, không vỡ layout, màu chuẩn, các nút cảnh báo hợp lý, không chèn Emoji lòe loẹt. | **Pass** (Toàn bộ Stylesheet đã fixed chuẩn Professional) |

---

### 1.3. Kiểm thử cấu trúc/ kiến trúc phần mềm
Đánh giá độ toàn vẹn của mã nguồn, mô hình cơ sở dữ liệu và thiết kế kiến trúc phần mềm.

1. **Kiểm thử mô hình dữ liệu (Database Integrity & Foreign Keys)**:
   - *Ràng buộc khóa ngoại (Constraint)*: Khi xóa một **Khoa** (Department) đang chứa nhiều Lớp bên trong, cơ sở dữ liệu SQLite (với tính năng `PRAGMA foreign_keys = ON;`) sẽ lập tức từ chối và văng lỗi, bảo vệ toàn vẹn dữ liệu tránh trường hợp "Mất cha/mẹ" ở bản ghi con. Điều tương tự áp dụng giữa **Lớp** và **Sinh Viên**.
   - *Unique Index*: Các cột như `student_id` hoặc tên `username`, tên lớp được kiểm thử bắt trùng lặp, nếu `INSERT` mã cũ sẽ bị Controller cản lại.

2. **Kiểm thử kiến trúc MVC (Model-View-Controller)**:
   - Các `QDialog` và `QMainWindow` (View) hoàn toàn không chứa mã kết nối Database trực tiếp. Mọi nghiệp vụ lấy, thêm, sửa, xóa đều gọi qua `StudentController`, `ClassController`,... đảm bảo tính tái sử dụng và nguyên lý đóng gói (Encapsulation).
   - Validation dữ liệu được xử lý chặt ở tầng Controller (Ví dụ hàm `validateStudent()`) trước khi gửi luồng tín hiệu (Signals/Slots) đến `DatabaseManager`.

3. **Kiểm thử Quản lý bộ nhớ C++ (Memory Management)**:
   - Thông qua cơ chế Parent-Child của dòng cây đối tượng Qt Object, các Dialog popup `LoginDialog`, `StudentDialog`, `ClassDialog` đều được cấp phát trên Stack (hoặc có `parent` trên luồng). Khi đóng khung window, bộ nhớ RAM được thu hồi sạch sẽ, không rò rỉ (Memory Leak).
   - Vòng lặp `while` quản lý state trong `main.cpp` xử lý dứt điểm rác tiến trình khi log out hệ thống ra vào nhiều lần. 
