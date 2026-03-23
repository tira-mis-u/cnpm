#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <QString>

/**
 * @brief Lớp Department - đại diện cho một Khoa trong trường
 *
 * Áp dụng OOP:
 * - Encapsulation: các thuộc tính private, truy cập qua getter/setter
 * - Tính mở rộng: có thể kế thừa để tạo khoa chuyên biệt
 */
class Department {
public:
    // Constructors
    Department();
    Department(int id, const QString& name, const QString& description = "");

    // Getters
    int         getId()          const { return m_id; }
    QString     getName()        const { return m_name; }
    QString     getDescription() const { return m_description; }

    // Setters với validation
    void setId(int id);
    void setName(const QString& name);
    void setDescription(const QString& description);

    // Kiểm tra hợp lệ
    bool isValid() const;

    // Chuyển đổi sang chuỗi để debug
    QString toString() const;

private:
    int     m_id;
    QString m_name;
    QString m_description;
};

#endif // DEPARTMENT_H
