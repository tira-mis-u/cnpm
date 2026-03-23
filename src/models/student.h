#ifndef STUDENT_H
#define STUDENT_H

#include <QString>
#include <QDate>

/**
 * @brief Lớp Student - đại diện cho một Sinh viên
 *
 * Quan hệ:
 *   Student --belongs_to--> ClassModel --belongs_to--> Department
 *
 * OOP:
 * - Encapsulation: dữ liệu private, truy cập qua public interface
 * - Validation trong setter để đảm bảo tính toàn vẹn dữ liệu
 */
class Student {
public:
    // Enum giới tính
    enum class Gender { Male, Female, Other };

    Student();
    Student(const QString& studentId,
            const QString& fullName,
            const QDate&   dateOfBirth,
            Gender         gender,
            const QString& email,
            const QString& phone,
            const QString& address,
            int            classId,
            const QString& className   = "",
            const QString& deptName    = "");

    // --- Getters ---
    QString getStudentId()  const { return m_studentId; }
    QString getFullName()   const { return m_fullName; }
    QDate   getDateOfBirth()const { return m_dateOfBirth; }
    Gender  getGender()     const { return m_gender; }
    QString getEmail()      const { return m_email; }
    QString getPhone()      const { return m_phone; }
    QString getAddress()    const { return m_address; }
    int     getClassId()    const { return m_classId; }
    QString getClassName()  const { return m_className; }
    QString getDeptName()   const { return m_deptName; }

    // --- Setters ---
    void setStudentId(const QString& id);
    void setFullName(const QString& name);
    void setDateOfBirth(const QDate& dob);
    void setGender(Gender gender);
    void setEmail(const QString& email);
    void setPhone(const QString& phone);
    void setAddress(const QString& address);
    void setClassId(int classId);
    void setClassName(const QString& name);
    void setDeptName(const QString& name);

    // --- Utility ---
    bool    isValid()       const;
    QString genderToString()const;
    static Gender genderFromString(const QString& s);
    static bool isValidEmail(const QString& email);
    static bool isValidPhone(const QString& phone);

    QString toString() const;

private:
    QString m_studentId;
    QString m_fullName;
    QDate   m_dateOfBirth;
    Gender  m_gender;
    QString m_email;
    QString m_phone;
    QString m_address;
    int     m_classId;
    QString m_className;  // Denormalized cho UI
    QString m_deptName;   // Denormalized cho UI
};

#endif // STUDENT_H
