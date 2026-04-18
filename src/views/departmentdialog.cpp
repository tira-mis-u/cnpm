#include "departmentdialog.h"
#include "ui_departmentdialog.h"
#include <QMessageBox>

DepartmentDialog::DepartmentDialog(QWidget* parent, const Department* dept)
    : QDialog(parent)
    , ui(new Ui::DepartmentDialog)
    , m_dept(dept)
{
    ui->setupUi(this);
    setWindowTitle(dept ? "Sửa Thông Tin Khoa" : "Thêm Khoa Mới");
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);


    if (m_dept) {
        ui->lineName->setText(m_dept->getName());
        ui->textDesc->setPlainText(m_dept->getDescription());
    }

    connect(ui->btnSave,   &QPushButton::clicked, this, &DepartmentDialog::onAccept);
    connect(ui->btnCancel, &QPushButton::clicked, this, &QDialog::reject);
    connect(ui->lineName,  &QLineEdit::returnPressed, this, &DepartmentDialog::onAccept);

    ui->lineName->setFocus();
}

DepartmentDialog::~DepartmentDialog() { delete ui; }

void DepartmentDialog::onAccept() {
    if (ui->lineName->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Thiếu thông tin", "Vui lòng nhập tên khoa.");
        ui->lineName->setFocus();
        return;
    }
    accept();
}

Department DepartmentDialog::getDepartment() const {
    Department d;
    if (m_dept) d.setId(m_dept->getId());
    d.setName(ui->lineName->text().trimmed());
    d.setDescription(ui->textDesc->toPlainText().trimmed());
    return d;
}
