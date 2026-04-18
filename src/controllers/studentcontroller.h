#ifndef STUDENTCONTROLLER_H
#define STUDENTCONTROLLER_H

#include <QObject>
#include <QList>
#include "student.h"
#include "databasemanager.h"

/**
 * @brief StudentController - Controller trong MVC
 *
 * Nhiệm vụ: làm trung gian giữa View (UI) và Model (Student + DB)
 * - Nhận lệnh từ View
 * - Gọi DatabaseManager để xử lý dữ liệu
 * - Trả kết quả về View thông qua signal
 */
class StudentController : public QObject {
    Q_OBJECT

public:
    explicit StudentController(QObject* parent = nullptr);

    // ── Các thao tác CRUD ───────────────────────────────────────────────────
    bool addStudent(const Student& student);
    bool updateStudent(const Student& student);
    bool deleteStudent(const QString& studentId);

    // ── Truy vấn ────────────────────────────────────────────────────────────
    QList<Student> getAllStudents();
    QList<Student> searchStudents(const QString& keyword);
    Student        getStudentById(const QString& studentId);

    // ── Validation ──────────────────────────────────────────────────────────
    QString validateStudent(const Student& student, bool isNew = true);

    // ── Export ──────────────────────────────────────────────────────────────
    bool exportToCSV(const QString& filePath, const QList<Student>& students);

    QString lastError() const { return m_lastError; }

signals:
    void studentAdded(const Student& student);
    void studentUpdated(const Student& student);
    void studentDeleted(const QString& studentId);
    void errorOccurred(const QString& message);

private:
    DatabaseManager& m_db;
    QString          m_lastError;
};

#endif // STUDENTCONTROLLER_H
