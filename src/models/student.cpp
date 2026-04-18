#include "student.h"
#include <QRegularExpression>
#include <stdexcept>

// ─── Constructors ────────────────────────────────────────────────────────────

Student::Student()
    : m_studentId(""), m_fullName(""), m_dateOfBirth(QDate()),
      m_gender(Gender::Male), m_email(""), m_phone(""),
      m_address(""), m_classId(0), m_className(""), m_deptName("") {}

Student::Student(const QString& studentId,
                 const QString& fullName,
                 const QDate&   dateOfBirth,
                 Gender         gender,
                 const QString& email,
                 const QString& phone,
                 const QString& address,
                 int            classId,
                 const QString& className,
                 const QString& deptName)
    : m_studentId(studentId), m_fullName(fullName),
      m_dateOfBirth(dateOfBirth), m_gender(gender),
      m_email(email), m_phone(phone), m_address(address),
      m_classId(classId), m_className(className), m_deptName(deptName) {}

// ─── Setters với Validation ──────────────────────────────────────────────────

void Student::setStudentId(const QString& id) {
    if (id.trimmed().isEmpty())
        throw std::invalid_argument("Mã sinh viên không được để trống");
    m_studentId = id.trimmed().toUpper();
}

void Student::setFullName(const QString& name) {
    if (name.trimmed().isEmpty())
        throw std::invalid_argument("Họ tên không được để trống");
    if (name.trimmed().length() < 2)
        throw std::invalid_argument("Họ tên quá ngắn");
    m_fullName = name.trimmed();
}

void Student::setDateOfBirth(const QDate& dob) {
    if (!dob.isValid())
        throw std::invalid_argument("Ngày sinh không hợp lệ");
    if (dob > QDate::currentDate())
        throw std::invalid_argument("Ngày sinh không thể ở tương lai");
    if (dob.year() < 1900)
        throw std::invalid_argument("Ngày sinh không hợp lệ");
    m_dateOfBirth = dob;
}

void Student::setGender(Gender gender) {
    m_gender = gender;
}

void Student::setEmail(const QString& email) {
    if (!email.isEmpty() && !isValidEmail(email))
        throw std::invalid_argument("Email không đúng định dạng");
    m_email = email.trimmed().toLower();
}

void Student::setPhone(const QString& phone) {
    if (!phone.isEmpty() && !isValidPhone(phone))
        throw std::invalid_argument("Số điện thoại không hợp lệ (10-11 chữ số)");
    m_phone = phone.trimmed();
}

void Student::setAddress(const QString& address) {
    m_address = address.trimmed();
}

void Student::setClassId(int classId) {
    if (classId <= 0)
        throw std::invalid_argument("Lớp học không hợp lệ");
    m_classId = classId;
}

void Student::setClassName(const QString& name) { m_className = name; }
void Student::setDeptName(const QString& name)  { m_deptName = name; }

// ─── Utility ─────────────────────────────────────────────────────────────────

bool Student::isValid() const {
    return !m_studentId.isEmpty()
        && !m_fullName.isEmpty()
        && m_dateOfBirth.isValid()
        && m_classId > 0;
}

QString Student::genderToString() const {
    switch (m_gender) {
        case Gender::Male:   return "Nam";
        case Gender::Female: return "Nữ";
        case Gender::Other:  return "Khác";
    }
    return "Nam";
}

Student::Gender Student::genderFromString(const QString& s) {
    if (s == "Nữ")   return Gender::Female;
    if (s == "Khác") return Gender::Other;
    return Gender::Male;
}

bool Student::isValidEmail(const QString& email) {
    static QRegularExpression re(R"(^[a-zA-Z0-9._%+\-]+@[a-zA-Z0-9.\-]+\.[a-zA-Z]{2,}$)");
    return re.match(email).hasMatch();
}

bool Student::isValidPhone(const QString& phone) {
    static QRegularExpression re(R"(^(0|\+84)[0-9]{9,10}$)");
    return re.match(phone).hasMatch();
}

QString Student::toString() const {
    return QString("Student[id=%1, name=%2, class=%3]")
        .arg(m_studentId).arg(m_fullName).arg(m_classId);
}
