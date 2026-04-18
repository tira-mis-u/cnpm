-- ============================================================
-- PHẦN MỀM QUẢN LÝ HỒ SƠ SINH VIÊN
-- Database Schema - SQLite
-- Tác giả: StudentMS Team
-- Phiên bản: 1.0
-- ============================================================

PRAGMA foreign_keys = ON;
PRAGMA encoding     = "UTF-8";
PRAGMA journal_mode = WAL;      -- Hiệu năng ghi tốt hơn

-- ──────────────────────────────────────────────────────────
-- BẢNG 1: departments (Khoa)
-- Cấp cao nhất trong phân cấp: Khoa > Lớp > Sinh viên
-- ──────────────────────────────────────────────────────────
CREATE TABLE IF NOT EXISTS departments (
    id          INTEGER  PRIMARY KEY AUTOINCREMENT,
    name        TEXT     NOT NULL UNIQUE COLLATE NOCASE,
    description TEXT     NOT NULL DEFAULT '',
    created_at  DATETIME DEFAULT CURRENT_TIMESTAMP
);

-- ──────────────────────────────────────────────────────────
-- BẢNG 2: classes (Lớp học)
-- Mỗi lớp thuộc về một khoa duy nhất
-- ──────────────────────────────────────────────────────────
CREATE TABLE IF NOT EXISTS classes (
    id            INTEGER  PRIMARY KEY AUTOINCREMENT,
    name          TEXT     NOT NULL UNIQUE COLLATE NOCASE,
    department_id INTEGER  NOT NULL,
    created_at    DATETIME DEFAULT CURRENT_TIMESTAMP,

    FOREIGN KEY (department_id)
        REFERENCES departments(id)
        ON DELETE RESTRICT     -- Không cho xóa khoa còn lớp
        ON UPDATE CASCADE
);

-- ──────────────────────────────────────────────────────────
-- BẢNG 3: students (Sinh viên)
-- Mỗi sinh viên thuộc về một lớp duy nhất
-- ──────────────────────────────────────────────────────────
CREATE TABLE IF NOT EXISTS students (
    student_id    TEXT     PRIMARY KEY COLLATE NOCASE,
    full_name     TEXT     NOT NULL,
    date_of_birth TEXT     NOT NULL,   -- ISO 8601: yyyy-MM-dd
    gender        TEXT     NOT NULL DEFAULT 'Nam'
                           CHECK(gender IN ('Nam', 'Nữ', 'Khác')),
    email         TEXT     NOT NULL DEFAULT '',
    phone         TEXT     NOT NULL DEFAULT '',
    address       TEXT     NOT NULL DEFAULT '',
    class_id      INTEGER  NOT NULL,
    created_at    DATETIME DEFAULT CURRENT_TIMESTAMP,
    updated_at    DATETIME DEFAULT CURRENT_TIMESTAMP,

    FOREIGN KEY (class_id)
        REFERENCES classes(id)
        ON DELETE RESTRICT     -- Không cho xóa lớp còn sinh viên
        ON UPDATE CASCADE
);

-- ──────────────────────────────────────────────────────────
-- BẢNG 4: users (Người dùng - đăng nhập)
-- Mật khẩu được lưu dưới dạng SHA-256 hash
-- ──────────────────────────────────────────────────────────
CREATE TABLE IF NOT EXISTS users (
    id         INTEGER  PRIMARY KEY AUTOINCREMENT,
    username   TEXT     NOT NULL UNIQUE COLLATE NOCASE,
    password   TEXT     NOT NULL,       -- SHA-256 hex hash
    role       TEXT     NOT NULL DEFAULT 'admin'
                        CHECK(role IN ('admin', 'viewer')),
    created_at DATETIME DEFAULT CURRENT_TIMESTAMP
);

-- ──────────────────────────────────────────────────────────
-- INDEX - Tăng tốc tìm kiếm
-- ──────────────────────────────────────────────────────────
CREATE INDEX IF NOT EXISTS idx_students_name
    ON students(full_name);

CREATE INDEX IF NOT EXISTS idx_students_class
    ON students(class_id);

CREATE INDEX IF NOT EXISTS idx_classes_dept
    ON classes(department_id);

-- ──────────────────────────────────────────────────────────
-- TRIGGER - Tự động cập nhật updated_at
-- ──────────────────────────────────────────────────────────
CREATE TRIGGER IF NOT EXISTS trg_students_updated_at
AFTER UPDATE ON students
BEGIN
    UPDATE students SET updated_at = CURRENT_TIMESTAMP
    WHERE student_id = NEW.student_id;
END;

-- ──────────────────────────────────────────────────────────
-- DỮ LIỆU MẪU - Khoa
-- ──────────────────────────────────────────────────────────
INSERT OR IGNORE INTO departments (name, description) VALUES
    ('Công nghệ thông tin',       'Đào tạo kỹ sư phần mềm, hệ thống thông tin'),
    ('Kinh tế',                   'Đào tạo cử nhân kinh tế, tài chính'),
    ('Kỹ thuật điện - Điện tử',   'Đào tạo kỹ sư điện, điện tử, viễn thông'),
    ('Quản trị kinh doanh',       'Đào tạo quản trị doanh nghiệp, marketing');

-- ──────────────────────────────────────────────────────────
-- DỮ LIỆU MẪU - Lớp học
-- ──────────────────────────────────────────────────────────
INSERT OR IGNORE INTO classes (name, department_id) VALUES
    ('75DCTT36', 1),
    ('75DCTT18', 1),
    ('75DCTT67', 1),
    ('75DCMM36',   2),
    ('75DCMM18',   2),
    ('75DMX36', 3),
    ('120DOMIXI36', 4);

-- ──────────────────────────────────────────────────────────
-- DỮ LIỆU MẪU - Sinh viên
-- ──────────────────────────────────────────────────────────
INSERT OR IGNORE INTO students
    (student_id, full_name, date_of_birth, gender, email, phone, address, class_id)
VALUES
    ('SV001', 'Lê Nguyễn Minh Trí',    '2004-03-15', 'Nam', 'minhtri@email.com',    '0901234567', '120 Yên Lãng, Hà Nội',         1),
    ('SV002', 'Trần Quốc Thuận',    '2004-07-22', 'Nữ',  'qthuan@email.com',  '0912345678', '120 An Liễng, Hà Nội',     1),
    ('SV003', 'Phạm Trung Hiếu',   '2003-11-08', 'Nam', 'hieu@email.com', '0923456789', 'Thanh Hoá',  2),
    ('SV004', 'Nguyễn Quốc Trung',    '2004-05-30', 'Nữ',  'trungquoc@email.com',  '0934567890', 'Thanh Hoá',      3),
    ('SV005', 'Phạm Văn Đam',   '2003-09-12', 'Nam', 'photographerPhuTho@email.com',   '0945678901', 'Phú Thọ',  4);

-- ──────────────────────────────────────────────────────────
-- DỮ LIỆU MẪU - Tài khoản admin
-- Password: admin123 (SHA-256)
-- Hash: 240be518fabd2724ddb6f04eeb1da5967448d7e831d2a3e44d4c8f8c7e7e7b5
-- ──────────────────────────────────────────────────────────
INSERT OR IGNORE INTO users (username, password, role) VALUES
    ('admin', '240be518fabd2724ddb6f04eeb1da5967448d7e831d2a3e44d4c8f8c7e7e7b5', 'admin');

-- ──────────────────────────────────────────────────────────
-- KIỂM TRA DỮ LIỆU
-- ──────────────────────────────────────────────────────────
-- SELECT 'departments' AS tbl, COUNT(*) AS rows FROM departments
-- UNION ALL
-- SELECT 'classes',  COUNT(*) FROM classes
-- UNION ALL
-- SELECT 'students', COUNT(*) FROM students;
