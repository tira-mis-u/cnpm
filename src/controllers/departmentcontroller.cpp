#include "departmentcontroller.h"

DepartmentController::DepartmentController(QObject* parent)
    : QObject(parent), m_db(DatabaseManager::instance()) {}

QString DepartmentController::validateDepartment(const Department& dept) {
    if (dept.getName().trimmed().isEmpty())
        return "Tên khoa không được để trống.";
    return "";
}

bool DepartmentController::addDepartment(const Department& dept) {
    QString err = validateDepartment(dept);
    if (!err.isEmpty()) { m_lastError = err; emit errorOccurred(err); return false; }
    if (!m_db.addDepartment(dept)) {
        m_lastError = m_db.lastError();
        if (m_lastError.contains("UNIQUE"))
            m_lastError = QString("Tên khoa '%1' đã tồn tại.").arg(dept.getName());
        emit errorOccurred(m_lastError);
        return false;
    }
    emit departmentAdded(dept);
    return true;
}

bool DepartmentController::updateDepartment(const Department& dept) {
    QString err = validateDepartment(dept);
    if (!err.isEmpty()) { m_lastError = err; emit errorOccurred(err); return false; }
    if (!m_db.updateDepartment(dept)) {
        m_lastError = m_db.lastError();
        emit errorOccurred(m_lastError);
        return false;
    }
    emit departmentUpdated(dept);
    return true;
}

bool DepartmentController::deleteDepartment(int id) {
    if (m_db.departmentHasClasses(id)) {
        m_lastError = "Không thể xóa khoa đang có lớp học.";
        emit errorOccurred(m_lastError);
        return false;
    }
    if (!m_db.deleteDepartment(id)) {
        m_lastError = m_db.lastError();
        emit errorOccurred(m_lastError);
        return false;
    }
    emit departmentDeleted(id);
    return true;
}

QList<Department> DepartmentController::getAllDepartments() {
    return m_db.getAllDepartments();
}
