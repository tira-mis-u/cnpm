#ifndef DEPARTMENTDIALOG_H
#define DEPARTMENTDIALOG_H

#include <QDialog>
#include "department.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DepartmentDialog; }
QT_END_NAMESPACE

/**
 * @brief DepartmentDialog - Form thêm/sửa khoa
 */
class DepartmentDialog : public QDialog {
    Q_OBJECT

public:
    explicit DepartmentDialog(QWidget*          parent,
                              const Department* dept);
    ~DepartmentDialog();

    Department getDepartment() const;

private slots:
    void onAccept();

private:
    Ui::DepartmentDialog* ui;
    const Department*     m_dept;
};

#endif // DEPARTMENTDIALOG_H
