/********************************************************************************
** Form generated from reading UI file 'classdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLASSDIALOG_H
#define UI_CLASSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ClassDialog
{
public:
    QVBoxLayout *mainLayout;
    QLabel *lblTitle;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineName;
    QLabel *label1;
    QComboBox *comboDept;
    QHBoxLayout *hlButtons;
    QSpacerItem *spacerItem;
    QPushButton *btnSave;
    QPushButton *btnCancel;

    void setupUi(QDialog *ClassDialog)
    {
        if (ClassDialog->objectName().isEmpty())
            ClassDialog->setObjectName("ClassDialog");
        ClassDialog->resize(440, 250);
        mainLayout = new QVBoxLayout(ClassDialog);
        mainLayout->setSpacing(12);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(0, 0, 0, 16);
        lblTitle = new QLabel(ClassDialog);
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
        label = new QLabel(ClassDialog);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineName = new QLineEdit(ClassDialog);
        lineName->setObjectName("lineName");
        lineName->setMaxLength(50);
        lineName->setMinimumHeight(36);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineName);

        label1 = new QLabel(ClassDialog);
        label1->setObjectName("label1");

        formLayout->setWidget(1, QFormLayout::LabelRole, label1);

        comboDept = new QComboBox(ClassDialog);
        comboDept->setObjectName("comboDept");
        comboDept->setMinimumHeight(36);

        formLayout->setWidget(1, QFormLayout::FieldRole, comboDept);


        mainLayout->addLayout(formLayout);

        hlButtons = new QHBoxLayout();
        hlButtons->setObjectName("hlButtons");
        hlButtons->setContentsMargins(24, 4, 24, 0);
        spacerItem = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hlButtons->addItem(spacerItem);

        btnSave = new QPushButton(ClassDialog);
        btnSave->setObjectName("btnSave");
        btnSave->setMinimumHeight(40);
        btnSave->setMinimumWidth(120);

        hlButtons->addWidget(btnSave);

        btnCancel = new QPushButton(ClassDialog);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setMinimumHeight(40);
        btnCancel->setMinimumWidth(80);

        hlButtons->addWidget(btnCancel);


        mainLayout->addLayout(hlButtons);


        retranslateUi(ClassDialog);

        btnSave->setDefault(true);


        QMetaObject::connectSlotsByName(ClassDialog);
    } // setupUi

    void retranslateUi(QDialog *ClassDialog)
    {
        ClassDialog->setWindowTitle(QCoreApplication::translate("ClassDialog", "Th\303\264ng Tin L\341\273\233p H\341\273\215c", nullptr));
        ClassDialog->setStyleSheet(QCoreApplication::translate("ClassDialog", "\n"
"    QDialog { background:#f8fafc; }\n"
"    QLineEdit, QComboBox {\n"
"        border: 1.5px solid #cbd5e1; border-radius:6px;\n"
"        padding: 8px 10px; font-size:13px; background:white;\n"
"    }\n"
"    QLineEdit:focus, QComboBox:focus { border-color:#3b82f6; }\n"
"   ", nullptr));
        lblTitle->setText(QCoreApplication::translate("ClassDialog", "TH\303\224NG TIN L\341\273\232P H\341\273\214C", nullptr));
        lblTitle->setStyleSheet(QCoreApplication::translate("ClassDialog", "background:#1e40af; color:white; font-size:15px;\n"
"              font-weight:bold; padding:12px; letter-spacing:1px;", nullptr));
        label->setText(QCoreApplication::translate("ClassDialog", "T\303\252n L\341\273\233p *", nullptr));
        label->setStyleSheet(QCoreApplication::translate("ClassDialog", "font-weight:bold; color:#1e293b;", nullptr));
        lineName->setPlaceholderText(QCoreApplication::translate("ClassDialog", "VD: CNTT-K22A", nullptr));
        label1->setText(QCoreApplication::translate("ClassDialog", "Thu\341\273\231c Khoa *", nullptr));
        label1->setStyleSheet(QCoreApplication::translate("ClassDialog", "font-weight:bold; color:#1e293b;", nullptr));
        btnSave->setText(QCoreApplication::translate("ClassDialog", "\360\237\222\276  L\306\260u", nullptr));
        btnSave->setStyleSheet(QCoreApplication::translate("ClassDialog", "\n"
"         QPushButton { background:#16a34a; color:white; padding:8px 24px;\n"
"           border-radius:7px; font-weight:bold; font-size:13px; border:none; }\n"
"         QPushButton:hover { background:#15803d; }\n"
"        ", nullptr));
        btnCancel->setText(QCoreApplication::translate("ClassDialog", "H\341\273\247y", nullptr));
        btnCancel->setStyleSheet(QCoreApplication::translate("ClassDialog", "\n"
"         QPushButton { background:#94a3b8; color:white; padding:8px 16px;\n"
"           border-radius:7px; font-size:13px; border:none; }\n"
"         QPushButton:hover { background:#64748b; }\n"
"        ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClassDialog: public Ui_ClassDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLASSDIALOG_H
