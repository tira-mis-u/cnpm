#include "classdialog.h"
#include "ui_classdialog.h"
#include <QMessageBox>
#include <QStyledItemDelegate>

ClassDialog::ClassDialog(QWidget* parent,
                         const ClassModel* cls,
                         DepartmentController* deptCtrl)
    : QDialog(parent)
    , ui(new Ui::ClassDialog)
    , m_cls(cls)
    , m_deptCtrl(deptCtrl)
{
    ui->setupUi(this);
    setWindowTitle(cls ? "✏️  Sửa Lớp Học" : "➕  Thêm Lớp Học");
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    
    ui->comboDept->setItemDelegate(new QStyledItemDelegate(this));


    loadDepts();

    if (m_cls) {
        ui->lineName->setText(m_cls->getName());
        for (int i = 0; i < ui->comboDept->count(); ++i) {
            if (ui->comboDept->itemData(i).toInt() == m_cls->getDepartmentId()) {
                ui->comboDept->setCurrentIndex(i);
                break;
            }
        }
    }

    connect(ui->btnSave,   &QPushButton::clicked, this, &ClassDialog::onAccept);
    connect(ui->btnCancel, &QPushButton::clicked, this, &QDialog::reject);
    connect(ui->lineName,  &QLineEdit::returnPressed, this, &ClassDialog::onAccept);
}

ClassDialog::~ClassDialog() { delete ui; }

void ClassDialog::loadDepts() {
    ui->comboDept->clear();
    ui->comboDept->addItem("-- Chọn khoa --", -1);
    auto depts = m_deptCtrl->getAllDepartments();
    for (const auto& d : depts)
        ui->comboDept->addItem(d.getName(), d.getId());
}

void ClassDialog::onAccept() {
    if (ui->lineName->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Thiếu thông tin", "Vui lòng nhập tên lớp.");
        ui->lineName->setFocus();
        return;
    }
    if (ui->comboDept->currentData().toInt() <= 0) {
        QMessageBox::warning(this, "Thiếu thông tin", "Vui lòng chọn khoa.");
        ui->comboDept->setFocus();
        return;
    }
    accept();
}

ClassModel ClassDialog::getClassModel() const {
    ClassModel c;
    if (m_cls) c.setId(m_cls->getId());
    c.setName(ui->lineName->text().trimmed());
    c.setDepartmentId(ui->comboDept->currentData().toInt());
    c.setDepartmentName(ui->comboDept->currentText());
    return c;
}
