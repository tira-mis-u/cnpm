#ifndef DEPARTMENTCONTROLLER_H
#define DEPARTMENTCONTROLLER_H

#include <QObject>
#include "department.h"
#include "databasemanager.h"

class DepartmentController : public QObject {
    Q_OBJECT
public:
    explicit DepartmentController(QObject* parent = nullptr);

    bool              addDepartment(const Department& dept);
    bool              updateDepartment(const Department& dept);
    bool              deleteDepartment(int id);
    QList<Department> getAllDepartments();
    QString           validateDepartment(const Department& dept);
    QString           lastError() const { return m_lastError; }

signals:
    void departmentAdded(const Department&);
    void departmentUpdated(const Department&);
    void departmentDeleted(int id);
    void errorOccurred(const QString&);

private:
    DatabaseManager& m_db;
    QString          m_lastError;
};

#endif
