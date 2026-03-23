#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QList>
#include "student.h"
#include "class_model.h"
#include "department.h"

/**
 * @brief DatabaseManager - Singleton quản lý toàn bộ truy vấn SQLite
 *
 * Pattern: Singleton để đảm bảo chỉ có 1 kết nối DB trong toàn app
 * Mapping OOP → DB:
 *   Student   → bảng students
 *   ClassModel→ bảng classes
 *   Department→ bảng departments
 */
class DatabaseManager {
public:
    // Singleton access
    static DatabaseManager& instance();

    // Không cho copy
    DatabaseManager(const DatabaseManager&)            = delete;
    DatabaseManager& operator=(const DatabaseManager&) = delete;

    // Khởi tạo và đóng kết nối
    bool    initialize(const QString& dbPath = "studentms.db");
    void    close();
    bool    isConnected() const;
    QString lastError()   const;

    // ── DEPARTMENT CRUD ────────────────────────────────────────────────────
    bool              addDepartment(const Department& dept);
    bool              updateDepartment(const Department& dept);
    bool              deleteDepartment(int id);
    QList<Department> getAllDepartments();
    Department        getDepartmentById(int id);
    bool              departmentHasClasses(int deptId);

    // ── CLASS CRUD ─────────────────────────────────────────────────────────
    bool                addClass(const ClassModel& cls);
    bool                updateClass(const ClassModel& cls);
    bool                deleteClass(int id);
    QList<ClassModel>   getAllClasses();
    QList<ClassModel>   getClassesByDepartment(int deptId);
    ClassModel          getClassById(int id);
    bool                classHasStudents(int classId);

    // ── STUDENT CRUD ───────────────────────────────────────────────────────
    bool            addStudent(const Student& student);
    bool            updateStudent(const Student& student);
    bool            deleteStudent(const QString& studentId);
    QList<Student>  getAllStudents();
    QList<Student>  searchStudents(const QString& keyword);
    QList<Student>  getStudentsByClass(int classId);
    Student         getStudentById(const QString& studentId);
    bool            studentIdExists(const QString& studentId);

    // ── AUTH ───────────────────────────────────────────────────────────────
    bool verifyLogin(const QString& username, const QString& password);

    // ── STATS ──────────────────────────────────────────────────────────────
    int countStudents();
    int countClasses();
    int countDepartments();

private:
    DatabaseManager() = default;
    ~DatabaseManager();

    bool    createTables();
    bool    insertDefaultData();
    QString hashPassword(const QString& password);

    QSqlDatabase m_db;
    QString      m_lastError;
    bool         m_connected = false;
};

#endif // DATABASEMANAGER_H
