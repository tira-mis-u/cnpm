/********************************************************************************
** Form generated from reading UI file 'departmentdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPARTMENTDIALOG_H
#define UI_DEPARTMENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DepartmentDialog
{
public:
    QVBoxLayout *mainLayout;
    QLabel *lblTitle;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineName;
    QLabel *label1;
    QPlainTextEdit *textDesc;
    QHBoxLayout *hlButtons;
    QSpacerItem *spacerItem;
    QPushButton *btnSave;
    QPushButton *btnCancel;

    void setupUi(QDialog *DepartmentDialog)
    {
        if (DepartmentDialog->objectName().isEmpty())
            DepartmentDialog->setObjectName("DepartmentDialog");
        DepartmentDialog->resize(460, 270);
        mainLayout = new QVBoxLayout(DepartmentDialog);
        mainLayout->setSpacing(12);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(0, 0, 0, 16);
        lblTitle = new QLabel(DepartmentDialog);
        lblTitle->setObjectName("lblTitle");
        lblTitle->setAlignment(Qt::AlignCenter);
        lblTitle->setMinimumHeight(46);

        mainLayout->addWidget(lblTitle);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        formLayout->setHorizontalSpacing(12);
        formLayout->setVerticalSpacing(12);
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignVCenter);
        formLayout->setContentsMargins(24, 8, 24, 0);
        label = new QLabel(DepartmentDialog);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineName = new QLineEdit(DepartmentDialog);
        lineName->setObjectName("lineName");
        lineName->setMaxLength(100);
        lineName->setMinimumHeight(36);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineName);

        label1 = new QLabel(DepartmentDialog);
        label1->setObjectName("label1");

        formLayout->setWidget(1, QFormLayout::LabelRole, label1);

        textDesc = new QPlainTextEdit(DepartmentDialog);
        textDesc->setObjectName("textDesc");
        textDesc->setMaximumHeight(72);

        formLayout->setWidget(1, QFormLayout::FieldRole, textDesc);


        mainLayout->addLayout(formLayout);

        hlButtons = new QHBoxLayout();
        hlButtons->setObjectName("hlButtons");
        hlButtons->setContentsMargins(24, 4, 24, 0);
        spacerItem = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hlButtons->addItem(spacerItem);

        btnSave = new QPushButton(DepartmentDialog);
        btnSave->setObjectName("btnSave");
        btnSave->setMinimumHeight(40);
        btnSave->setMinimumWidth(120);

        hlButtons->addWidget(btnSave);

        btnCancel = new QPushButton(DepartmentDialog);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setMinimumHeight(40);
        btnCancel->setMinimumWidth(80);

        hlButtons->addWidget(btnCancel);


        mainLayout->addLayout(hlButtons);


        retranslateUi(DepartmentDialog);

        btnSave->setDefault(true);


        QMetaObject::connectSlotsByName(DepartmentDialog);
    } // setupUi

    void retranslateUi(QDialog *DepartmentDialog)
    {
        DepartmentDialog->setWindowTitle(QCoreApplication::translate("DepartmentDialog", "Th\303\264ng Tin Khoa", nullptr));
        DepartmentDialog->setStyleSheet(QCoreApplication::translate("DepartmentDialog", "\n"
"    QDialog { background:#f8fafc; }\n"
"    QLineEdit, QPlainTextEdit {\n"
"        border: 1.5px solid #cbd5e1; border-radius:6px;\n"
"        padding: 8px 10px; font-size:13px; background:white;\n"
"    }\n"
"    QLineEdit:focus, QPlainTextEdit:focus { border-color:#3b82f6; }\n"
"   ", nullptr));
        lblTitle->setText(QCoreApplication::translate("DepartmentDialog", "TH\303\224NG TIN KHOA", nullptr));
        lblTitle->setStyleSheet(QCoreApplication::translate("DepartmentDialog", "background:#1e40af; color:white; font-size:15px;\n"
"              font-weight:bold; padding:12px; letter-spacing:1px;", nullptr));
        label->setText(QCoreApplication::translate("DepartmentDialog", "T\303\252n Khoa *", nullptr));
        label->setStyleSheet(QCoreApplication::translate("DepartmentDialog", "font-weight:bold; color:#1e293b;", nullptr));
        lineName->setPlaceholderText(QCoreApplication::translate("DepartmentDialog", "VD: C\303\264ng ngh\341\273\207 th\303\264ng tin", nullptr));
        label1->setText(QCoreApplication::translate("DepartmentDialog", "M\303\264 T\341\272\243", nullptr));
        label1->setStyleSheet(QCoreApplication::translate("DepartmentDialog", "font-weight:bold; color:#1e293b;", nullptr));
        textDesc->setPlaceholderText(QCoreApplication::translate("DepartmentDialog", "M\303\264 t\341\272\243 ng\341\272\257n v\341\273\201 khoa (kh\303\264ng b\341\272\257t bu\341\273\231c)", nullptr));
        btnSave->setText(QCoreApplication::translate("DepartmentDialog", "\360\237\222\276  L\306\260u", nullptr));
        btnSave->setStyleSheet(QCoreApplication::translate("DepartmentDialog", "\n"
"         QPushButton { background:#16a34a; color:white; padding:8px 24px;\n"
"           border-radius:7px; font-weight:bold; font-size:13px; border:none; }\n"
"         QPushButton:hover { background:#15803d; }\n"
"        ", nullptr));
        btnCancel->setText(QCoreApplication::translate("DepartmentDialog", "H\341\273\247y", nullptr));
        btnCancel->setStyleSheet(QCoreApplication::translate("DepartmentDialog", "\n"
"         QPushButton { background:#94a3b8; color:white; padding:8px 16px;\n"
"           border-radius:7px; font-size:13px; border:none; }\n"
"         QPushButton:hover { background:#64748b; }\n"
"        ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DepartmentDialog: public Ui_DepartmentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPARTMENTDIALOG_H
