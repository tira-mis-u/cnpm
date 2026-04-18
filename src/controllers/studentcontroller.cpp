#include "studentcontroller.h"
#include <QFile>
#include <QTextStream>
#include <QDate>

StudentController::StudentController(QObject* parent)
    : QObject(parent), m_db(DatabaseManager::instance()) {}

// ─── Validation ───────────────────────────────────────────────────────────────

QString StudentController::validateStudent(const Student& s, bool isNew) {
    if (s.getStudentId().trimmed().isEmpty())
        return "Mã sinh viên không được để trống.";
    if (s.getFullName().trimmed().isEmpty())
        return "Họ và tên không được để trống.";
    if (!s.getDateOfBirth().isValid())
        return "Ngày sinh không hợp lệ.";
    if (s.getDateOfBirth() > QDate::currentDate())
        return "Ngày sinh không thể ở tương lai.";
    if (s.getClassId() <= 0)
        return "Vui lòng chọn lớp cho sinh viên.";
    if (!s.getEmail().isEmpty() && !Student::isValidEmail(s.getEmail()))
        return "Email không đúng định dạng (vd: abc@gmail.com).";
    if (!s.getPhone().isEmpty() && !Student::isValidPhone(s.getPhone()))
        return "Số điện thoại không hợp lệ (10-11 số, bắt đầu bằng 0 hoặc +84).";
    if (isNew && m_db.studentIdExists(s.getStudentId()))
        return QString("Mã sinh viên '%1' đã tồn tại trong hệ thống.").arg(s.getStudentId());
    return ""; // Hợp lệ
}

// ─── CRUD ─────────────────────────────────────────────────────────────────────

bool StudentController::addStudent(const Student& student) {
    QString err = validateStudent(student, true);
    if (!err.isEmpty()) {
        m_lastError = err;
        emit errorOccurred(err);
        return false;
    }
    if (!m_db.addStudent(student)) {
        m_lastError = m_db.lastError();
        emit errorOccurred(m_lastError);
        return false;
    }
    emit studentAdded(student);
    return true;
}

bool StudentController::updateStudent(const Student& student) {
    QString err = validateStudent(student, false);
    if (!err.isEmpty()) {
        m_lastError = err;
        emit errorOccurred(err);
        return false;
    }
    if (!m_db.updateStudent(student)) {
        m_lastError = m_db.lastError();
        emit errorOccurred(m_lastError);
        return false;
    }
    emit studentUpdated(student);
    return true;
}

bool StudentController::deleteStudent(const QString& studentId) {
    if (studentId.isEmpty()) {
        m_lastError = "Mã sinh viên không hợp lệ.";
        return false;
    }
    if (!m_db.deleteStudent(studentId)) {
        m_lastError = m_db.lastError();
        emit errorOccurred(m_lastError);
        return false;
    }
    emit studentDeleted(studentId);
    return true;
}

QList<Student> StudentController::getAllStudents() {
    return m_db.getAllStudents();
}

QList<Student> StudentController::searchStudents(const QString& keyword) {
    return m_db.searchStudents(keyword.trimmed());
}

Student StudentController::getStudentById(const QString& studentId) {
    return m_db.getStudentById(studentId);
}

// ─── Export CSV ───────────────────────────────────────────────────────────────

bool StudentController::exportToCSV(const QString& filePath, const QList<Student>& students) {
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        m_lastError = "Không thể tạo file: " + filePath;
        return false;
    }

    QTextStream out(&file);
    out.setEncoding(QStringConverter::Utf8);

    // BOM cho Excel đọc UTF-8
    out << "\xEF\xBB\xBF";

    // Header
    out << "Mã SV,Họ và Tên,Ngày Sinh,Giới Tính,Email,Điện Thoại,Địa Chỉ,Lớp,Khoa\n";

    for (const Student& s : students) {
        out << QString("\"%1\",\"%2\",\"%3\",\"%4\",\"%5\",\"%6\",\"%7\",\"%8\",\"%9\"\n")
               .arg(s.getStudentId())
               .arg(s.getFullName())
               .arg(s.getDateOfBirth().toString("dd/MM/yyyy"))
               .arg(s.genderToString())
               .arg(s.getEmail())
               .arg(s.getPhone())
               .arg(s.getAddress())
               .arg(s.getClassName())
               .arg(s.getDeptName());
    }

    file.close();
    return true;
}
