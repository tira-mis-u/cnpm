#include "class_model.h"
#include <stdexcept>

ClassModel::ClassModel()
    : m_id(0), m_name(""), m_departmentId(0), m_departmentName("") {}

ClassModel::ClassModel(int id, const QString& name, int departmentId,
                       const QString& departmentName)
    : m_id(id), m_name(name), m_departmentId(departmentId),
      m_departmentName(departmentName) {}

void ClassModel::setId(int id) {
    if (id < 0) throw std::invalid_argument("ID không được âm");
    m_id = id;
}

void ClassModel::setName(const QString& name) {
    if (name.trimmed().isEmpty())
        throw std::invalid_argument("Tên lớp không được để trống");
    m_name = name.trimmed();
}

void ClassModel::setDepartmentId(int departmentId) {
    if (departmentId <= 0)
        throw std::invalid_argument("Khoa không hợp lệ");
    m_departmentId = departmentId;
}

void ClassModel::setDepartmentName(const QString& name) {
    m_departmentName = name.trimmed();
}

bool ClassModel::isValid() const {
    return m_id > 0 && !m_name.trimmed().isEmpty() && m_departmentId > 0;
}

QString ClassModel::toString() const {
    return QString("ClassModel[id=%1, name=%2, dept=%3]")
        .arg(m_id).arg(m_name).arg(m_departmentId);
}
