/********************************************************************************
** Form generated from reading UI file 'studentdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTDIALOG_H
#define UI_STUDENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentDialog
{
public:
    QVBoxLayout *mainLayout;
    QLabel *lblTitle;
    QLabel *lblRequired;
    QWidget *formWidget;
    QFormLayout *formLayout;
    QLabel *label_id;
    QLineEdit *lineStudentId;
    QLabel *label_name;
    QLineEdit *lineName;
    QLabel *label_dob;
    QDateEdit *dateDOB;
    QLabel *label_gender;
    QComboBox *comboGender;
    QLabel *label_class;
    QComboBox *comboClass;
    QLabel *label_email;
    QLineEdit *lineEmail;
    QLabel *label_phone;
    QLineEdit *linePhone;
    QLabel *label_addr;
    QPlainTextEdit *textAddress;
    QHBoxLayout *hlButtons;
    QSpacerItem *spacerItem;
    QPushButton *btnSave;
    QPushButton *btnCancel;

    void setupUi(QDialog *StudentDialog)
    {
        if (StudentDialog->objectName().isEmpty())
            StudentDialog->setObjectName("StudentDialog");
        StudentDialog->resize(540, 580);
        mainLayout = new QVBoxLayout(StudentDialog);
        mainLayout->setSpacing(12);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(0, 0, 0, 16);
        lblTitle = new QLabel(StudentDialog);
        lblTitle->setObjectName("lblTitle");
        lblTitle->setAlignment(Qt::AlignCenter);
        lblTitle->setMinimumHeight(52);

        mainLayout->addWidget(lblTitle);

        lblRequired = new QLabel(StudentDialog);
        lblRequired->setObjectName("lblRequired");

        mainLayout->addWidget(lblRequired);

        formWidget = new QWidget(StudentDialog);
        formWidget->setObjectName("formWidget");
        formLayout = new QFormLayout(formWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setHorizontalSpacing(12);
        formLayout->setVerticalSpacing(10);
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignVCenter);
        formLayout->setContentsMargins(20, 0, 20, 0);
        label_id = new QLabel(formWidget);
        label_id->setObjectName("label_id");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_id);

        lineStudentId = new QLineEdit(formWidget);
        lineStudentId->setObjectName("lineStudentId");
        lineStudentId->setMaxLength(20);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineStudentId);

        label_name = new QLabel(formWidget);
        label_name->setObjectName("label_name");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_name);

        lineName = new QLineEdit(formWidget);
        lineName->setObjectName("lineName");
        lineName->setMaxLength(100);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineName);

        label_dob = new QLabel(formWidget);
        label_dob->setObjectName("label_dob");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_dob);

        dateDOB = new QDateEdit(formWidget);
        dateDOB->setObjectName("dateDOB");
        dateDOB->setCalendarPopup(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, dateDOB);

        label_gender = new QLabel(formWidget);
        label_gender->setObjectName("label_gender");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_gender);

        comboGender = new QComboBox(formWidget);
        comboGender->setObjectName("comboGender");

        formLayout->setWidget(3, QFormLayout::FieldRole, comboGender);

        label_class = new QLabel(formWidget);
        label_class->setObjectName("label_class");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_class);

        comboClass = new QComboBox(formWidget);
        comboClass->setObjectName("comboClass");
        comboClass->setMinimumHeight(36);

        formLayout->setWidget(4, QFormLayout::FieldRole, comboClass);

        label_email = new QLabel(formWidget);
        label_email->setObjectName("label_email");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_email);

        lineEmail = new QLineEdit(formWidget);
        lineEmail->setObjectName("lineEmail");

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEmail);

        label_phone = new QLabel(formWidget);
        label_phone->setObjectName("label_phone");

        formLayout->setWidget(6, QFormLayout::LabelRole, label_phone);

        linePhone = new QLineEdit(formWidget);
        linePhone->setObjectName("linePhone");
        linePhone->setMaxLength(15);

        formLayout->setWidget(6, QFormLayout::FieldRole, linePhone);

        label_addr = new QLabel(formWidget);
        label_addr->setObjectName("label_addr");

        formLayout->setWidget(7, QFormLayout::LabelRole, label_addr);

        textAddress = new QPlainTextEdit(formWidget);
        textAddress->setObjectName("textAddress");
        textAddress->setMaximumHeight(72);

        formLayout->setWidget(7, QFormLayout::FieldRole, textAddress);


        mainLayout->addWidget(formWidget);

        hlButtons = new QHBoxLayout();
        hlButtons->setObjectName("hlButtons");
        hlButtons->setContentsMargins(20, 0, 20, 0);
        spacerItem = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hlButtons->addItem(spacerItem);

        btnSave = new QPushButton(StudentDialog);
        btnSave->setObjectName("btnSave");
        btnSave->setMinimumHeight(42);
        btnSave->setMinimumWidth(150);

        hlButtons->addWidget(btnSave);

        btnCancel = new QPushButton(StudentDialog);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setMinimumHeight(42);
        btnCancel->setMinimumWidth(90);

        hlButtons->addWidget(btnCancel);


        mainLayout->addLayout(hlButtons);


        retranslateUi(StudentDialog);

        btnSave->setDefault(true);


        QMetaObject::connectSlotsByName(StudentDialog);
    } // setupUi

    void retranslateUi(QDialog *StudentDialog)
    {
        StudentDialog->setWindowTitle(QCoreApplication::translate("StudentDialog", "Th\303\264ng Tin Sinh Vi\303\252n", nullptr));
        StudentDialog->setStyleSheet(QCoreApplication::translate("StudentDialog", "\n"
"    QDialog { background: #f8fafc; }\n"
"    QLabel[class=\"field-label\"] { font-weight: bold; color: #374151; font-size: 13px; }\n"
"    QLineEdit, QComboBox, QDateEdit, QPlainTextEdit {\n"
"        border: 1.5px solid #cbd5e1;\n"
"        border-radius: 6px;\n"
"        padding: 7px 10px;\n"
"        font-size: 13px;\n"
"        background: white;\n"
"    }\n"
"    QLineEdit:focus, QComboBox:focus, QDateEdit:focus, QPlainTextEdit:focus {\n"
"        border-color: #3b82f6;\n"
"        outline: none;\n"
"    }\n"
"   ", nullptr));
        lblTitle->setText(QCoreApplication::translate("StudentDialog", "TH\303\224NG TIN SINH VI\303\212N", nullptr));
        lblTitle->setStyleSheet(QCoreApplication::translate("StudentDialog", "\n"
"       background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"           stop:0 #1e3a8a, stop:1 #2563eb);\n"
"       color: white;\n"
"       font-size: 16px;\n"
"       font-weight: bold;\n"
"       padding: 14px;\n"
"       border-radius: 0px;\n"
"       letter-spacing: 1px;\n"
"      ", nullptr));
        lblRequired->setText(QCoreApplication::translate("StudentDialog", "  * C\303\241c tr\306\260\341\273\235ng c\303\263 d\341\272\245u * l\303\240 b\341\272\257t bu\341\273\231c", nullptr));
        lblRequired->setStyleSheet(QCoreApplication::translate("StudentDialog", "color:#ef4444; font-size:12px; padding-left:16px;", nullptr));
        label_id->setText(QCoreApplication::translate("StudentDialog", "M\303\243 Sinh Vi\303\252n *", nullptr));
        label_id->setStyleSheet(QCoreApplication::translate("StudentDialog", "font-weight:bold; color:#1e293b;", nullptr));
        lineStudentId->setPlaceholderText(QCoreApplication::translate("StudentDialog", "VD: SV001  (vi\341\272\277t hoa t\341\273\261 \304\221\341\273\231ng)", nullptr));
        label_name->setText(QCoreApplication::translate("StudentDialog", "H\341\273\215 v\303\240 T\303\252n *", nullptr));
        label_name->setStyleSheet(QCoreApplication::translate("StudentDialog", "font-weight:bold; color:#1e293b;", nullptr));
        lineName->setPlaceholderText(QCoreApplication::translate("StudentDialog", "Nguy\341\273\205n V\304\203n A", nullptr));
        label_dob->setText(QCoreApplication::translate("StudentDialog", "Ng\303\240y Sinh", nullptr));
        label_dob->setStyleSheet(QCoreApplication::translate("StudentDialog", "font-weight:bold; color:#1e293b;", nullptr));
        dateDOB->setDisplayFormat(QCoreApplication::translate("StudentDialog", "dd/MM/yyyy", nullptr));
        label_gender->setText(QCoreApplication::translate("StudentDialog", "Gi\341\273\233i T\303\255nh", nullptr));
        label_gender->setStyleSheet(QCoreApplication::translate("StudentDialog", "font-weight:bold; color:#1e293b;", nullptr));
        label_class->setText(QCoreApplication::translate("StudentDialog", "L\341\273\233p H\341\273\215c *", nullptr));
        label_class->setStyleSheet(QCoreApplication::translate("StudentDialog", "font-weight:bold; color:#1e293b;", nullptr));
        label_email->setText(QCoreApplication::translate("StudentDialog", "Email", nullptr));
        label_email->setStyleSheet(QCoreApplication::translate("StudentDialog", "font-weight:bold; color:#1e293b;", nullptr));
        lineEmail->setPlaceholderText(QCoreApplication::translate("StudentDialog", "example@gmail.com", nullptr));
        label_phone->setText(QCoreApplication::translate("StudentDialog", "\304\220i\341\273\207n Tho\341\272\241i", nullptr));
        label_phone->setStyleSheet(QCoreApplication::translate("StudentDialog", "font-weight:bold; color:#1e293b;", nullptr));
        linePhone->setPlaceholderText(QCoreApplication::translate("StudentDialog", "0901234567", nullptr));
        label_addr->setText(QCoreApplication::translate("StudentDialog", "\304\220\341\273\213a Ch\341\273\211", nullptr));
        label_addr->setStyleSheet(QCoreApplication::translate("StudentDialog", "font-weight:bold; color:#1e293b;", nullptr));
        textAddress->setPlaceholderText(QCoreApplication::translate("StudentDialog", "S\341\273\221 nh\303\240, \304\221\306\260\341\273\235ng, ph\306\260\341\273\235ng/x\303\243, qu\341\272\255n/huy\341\273\207n, t\341\273\211nh/th\303\240nh ph\341\273\221", nullptr));
        btnSave->setText(QCoreApplication::translate("StudentDialog", "\360\237\222\276  L\306\260u Th\303\264ng Tin", nullptr));
        btnSave->setStyleSheet(QCoreApplication::translate("StudentDialog", "\n"
"         QPushButton { background:#16a34a; color:white; padding:10px 28px;\n"
"           border-radius:8px; font-weight:bold; font-size:14px; border:none; }\n"
"         QPushButton:hover { background:#15803d; }\n"
"         QPushButton:pressed { background:#166534; }\n"
"         QPushButton:disabled { background:#94a3b8; }\n"
"        ", nullptr));
        btnCancel->setText(QCoreApplication::translate("StudentDialog", "H\341\273\247y", nullptr));
        btnCancel->setStyleSheet(QCoreApplication::translate("StudentDialog", "\n"
"         QPushButton { background:#94a3b8; color:white; padding:10px 20px;\n"
"           border-radius:8px; font-size:14px; border:none; }\n"
"         QPushButton:hover { background:#64748b; }\n"
"        ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentDialog: public Ui_StudentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTDIALOG_H
