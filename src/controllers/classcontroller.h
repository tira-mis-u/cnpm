#ifndef CLASSCONTROLLER_H
#define CLASSCONTROLLER_H

#include <QObject>
#include "class_model.h"
#include "databasemanager.h"

class ClassController : public QObject {
    Q_OBJECT
public:
    explicit ClassController(QObject* parent = nullptr);

    bool              addClass(const ClassModel& cls);
    bool              updateClass(const ClassModel& cls);
    bool              deleteClass(int classId);
    QList<ClassModel> getAllClasses();
    QList<ClassModel> getClassesByDepartment(int deptId);
    QString           validateClass(const ClassModel& cls);
    QString           lastError() const { return m_lastError; }

signals:
    void classAdded(const ClassModel&);
    void classUpdated(const ClassModel&);
    void classDeleted(int classId);
    void errorOccurred(const QString&);

private:
    DatabaseManager& m_db;
    QString          m_lastError;
};

#endif // CLASSCONTROLLER_H
