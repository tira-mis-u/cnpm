#include "classcontroller.h"

ClassController::ClassController(QObject* parent)
    : QObject(parent), m_db(DatabaseManager::instance()) {}

QString ClassController::validateClass(const ClassModel& cls) {
    if (cls.getName().trimmed().isEmpty())
        return "Tên lớp không được để trống.";
    if (cls.getDepartmentId() <= 0)
        return "Vui lòng chọn khoa.";
    return "";
}

bool ClassController::addClass(const ClassModel& cls) {
    QString err = validateClass(cls);
    if (!err.isEmpty()) { m_lastError = err; emit errorOccurred(err); return false; }
    if (!m_db.addClass(cls)) {
        m_lastError = m_db.lastError();
        if (m_lastError.contains("UNIQUE"))
            m_lastError = QString("Tên lớp '%1' đã tồn tại.").arg(cls.getName());
        emit errorOccurred(m_lastError);
        return false;
    }
    emit classAdded(cls);
    return true;
}

bool ClassController::updateClass(const ClassModel& cls) {
    QString err = validateClass(cls);
    if (!err.isEmpty()) { m_lastError = err; emit errorOccurred(err); return false; }
    if (!m_db.updateClass(cls)) {
        m_lastError = m_db.lastError();
        emit errorOccurred(m_lastError);
        return false;
    }
    emit classUpdated(cls);
    return true;
}

bool ClassController::deleteClass(int classId) {
    if (m_db.classHasStudents(classId)) {
        m_lastError = "Không thể xóa lớp đang có sinh viên. Hãy chuyển sinh viên trước.";
        emit errorOccurred(m_lastError);
        return false;
    }
    if (!m_db.deleteClass(classId)) {
        m_lastError = m_db.lastError();
        emit errorOccurred(m_lastError);
        return false;
    }
    emit classDeleted(classId);
    return true;
}

QList<ClassModel> ClassController::getAllClasses() {
    return m_db.getAllClasses();
}

QList<ClassModel> ClassController::getClassesByDepartment(int deptId) {
    return m_db.getClassesByDepartment(deptId);
}
