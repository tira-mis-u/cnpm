#ifndef STUDENTDIALOG_H
#define STUDENTDIALOG_H

#include <QDialog>
#include "student.h"
#include "classcontroller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class StudentDialog; }
QT_END_NAMESPACE

/**
 * @brief StudentDialog - Form nhập/sửa thông tin sinh viên
 */
class StudentDialog : public QDialog {
    Q_OBJECT

public:
    explicit StudentDialog(QWidget* parent,
                           const Student* student,       // nullptr = thêm mới
                           ClassController* classCtrl);
    ~StudentDialog();

    Student getStudent() const;

private slots:
    void onAccept();
    void validateForm();

private:
    Ui::StudentDialog* ui;
    const Student*     m_student;
    ClassController*   m_classCtrl;
    bool               m_isEditMode;

    void populateForm();
    void loadClasses();
    void applyValidationStyle(QWidget* w, bool valid);
};

#endif // STUDENTDIALOG_H
