#ifndef CLASS_MODEL_H
#define CLASS_MODEL_H

#include <QString>

/**
 * @brief Lớp ClassModel - đại diện cho một Lớp học
 *
 * Quan hệ: ClassModel thuộc về một Department
 * Tránh trùng tên với class từ khóa C++ → đặt tên ClassModel
 */
class ClassModel {
public:
    ClassModel();
    ClassModel(int id, const QString& name, int departmentId,
               const QString& departmentName = "");

    // Getters
    int     getId()             const { return m_id; }
    QString getName()           const { return m_name; }
    int     getDepartmentId()   const { return m_departmentId; }
    QString getDepartmentName() const { return m_departmentName; }

    // Setters
    void setId(int id);
    void setName(const QString& name);
    void setDepartmentId(int departmentId);
    void setDepartmentName(const QString& name);

    bool    isValid()   const;
    QString toString()  const;

private:
    int     m_id;
    QString m_name;
    int     m_departmentId;
    QString m_departmentName; // Denormalized để hiển thị UI
};

#endif // CLASS_MODEL_H
