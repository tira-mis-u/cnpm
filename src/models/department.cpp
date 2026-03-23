#include "department.h"
#include <stdexcept>

Department::Department()
    : m_id(0), m_name(""), m_description("") {}

Department::Department(int id, const QString& name, const QString& description)
    : m_id(id), m_name(name), m_description(description) {}

void Department::setId(int id) {
    if (id < 0) throw std::invalid_argument("ID không được âm");
    m_id = id;
}

void Department::setName(const QString& name) {
    if (name.trimmed().isEmpty())
        throw std::invalid_argument("Tên khoa không được để trống");
    m_name = name.trimmed();
}

void Department::setDescription(const QString& description) {
    m_description = description.trimmed();
}

bool Department::isValid() const {
    return m_id > 0 && !m_name.trimmed().isEmpty();
}

QString Department::toString() const {
    return QString("Department[id=%1, name=%2]").arg(m_id).arg(m_name);
}
