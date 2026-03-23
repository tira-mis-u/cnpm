#ifndef CLASSDIALOG_H
#define CLASSDIALOG_H

#include <QDialog>
#include "class_model.h"
#include "departmentcontroller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ClassDialog; }
QT_END_NAMESPACE

/**
 * @brief ClassDialog - Form thêm/sửa lớp học
 */
class ClassDialog : public QDialog {
    Q_OBJECT

public:
    explicit ClassDialog(QWidget*          parent,
                         const ClassModel* cls,
                         DepartmentController* deptCtrl);
    ~ClassDialog();

    ClassModel getClassModel() const;

private slots:
    void onAccept();

private:
    Ui::ClassDialog*      ui;
    const ClassModel*     m_cls;
    DepartmentController* m_deptCtrl;

    void loadDepts();
};

#endif // CLASSDIALOG_H
