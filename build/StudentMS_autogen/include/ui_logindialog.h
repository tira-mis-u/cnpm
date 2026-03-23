/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QVBoxLayout *mainLayout;
    QLabel *lblLogo;
    QLabel *lblAppName;
    QLabel *lblSubtitle;
    QWidget *cardWidget;
    QVBoxLayout *cardLayout;
    QLabel *label_user;
    QLineEdit *lineUsername;
    QLabel *label_pass;
    QHBoxLayout *hboxLayout;
    QLineEdit *linePassword;
    QPushButton *btnShowPass;
    QLabel *lblError;
    QHBoxLayout *hlButtons;
    QPushButton *btnLogin;
    QPushButton *btnCancel;
    QLabel *lblDefaultHint;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName("LoginDialog");
        LoginDialog->resize(420, 360);
        mainLayout = new QVBoxLayout(LoginDialog);
        mainLayout->setSpacing(0);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(0, 0, 0, 0);
        lblLogo = new QLabel(LoginDialog);
        lblLogo->setObjectName("lblLogo");
        lblLogo->setAlignment(Qt::AlignCenter);

        mainLayout->addWidget(lblLogo);

        lblAppName = new QLabel(LoginDialog);
        lblAppName->setObjectName("lblAppName");
        lblAppName->setAlignment(Qt::AlignCenter);

        mainLayout->addWidget(lblAppName);

        lblSubtitle = new QLabel(LoginDialog);
        lblSubtitle->setObjectName("lblSubtitle");
        lblSubtitle->setAlignment(Qt::AlignCenter);

        mainLayout->addWidget(lblSubtitle);

        cardWidget = new QWidget(LoginDialog);
        cardWidget->setObjectName("cardWidget");
        cardLayout = new QVBoxLayout(cardWidget);
        cardLayout->setSpacing(12);
        cardLayout->setObjectName("cardLayout");
        cardLayout->setContentsMargins(24, 20, 24, 20);
        label_user = new QLabel(cardWidget);
        label_user->setObjectName("label_user");

        cardLayout->addWidget(label_user);

        lineUsername = new QLineEdit(cardWidget);
        lineUsername->setObjectName("lineUsername");
        lineUsername->setMinimumHeight(42);

        cardLayout->addWidget(lineUsername);

        label_pass = new QLabel(cardWidget);
        label_pass->setObjectName("label_pass");

        cardLayout->addWidget(label_pass);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName("hboxLayout");
        linePassword = new QLineEdit(cardWidget);
        linePassword->setObjectName("linePassword");
        linePassword->setMinimumHeight(42);
        linePassword->setEchoMode(QLineEdit::Password);

        hboxLayout->addWidget(linePassword);

        btnShowPass = new QPushButton(cardWidget);
        btnShowPass->setObjectName("btnShowPass");
        btnShowPass->setMinimumSize(QSize(42, 42));

        hboxLayout->addWidget(btnShowPass);


        cardLayout->addLayout(hboxLayout);

        lblError = new QLabel(cardWidget);
        lblError->setObjectName("lblError");
        lblError->setWordWrap(true);

        cardLayout->addWidget(lblError);


        mainLayout->addWidget(cardWidget);

        hlButtons = new QHBoxLayout();
        hlButtons->setSpacing(10);
        hlButtons->setObjectName("hlButtons");
        hlButtons->setContentsMargins(24, 16, 24, 16);
        btnLogin = new QPushButton(LoginDialog);
        btnLogin->setObjectName("btnLogin");
        btnLogin->setMinimumHeight(44);

        hlButtons->addWidget(btnLogin);

        btnCancel = new QPushButton(LoginDialog);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setMinimumHeight(44);
        btnCancel->setMinimumWidth(90);

        hlButtons->addWidget(btnCancel);


        mainLayout->addLayout(hlButtons);

        lblDefaultHint = new QLabel(LoginDialog);
        lblDefaultHint->setObjectName("lblDefaultHint");
        lblDefaultHint->setAlignment(Qt::AlignCenter);

        mainLayout->addWidget(lblDefaultHint);


        retranslateUi(LoginDialog);

        btnLogin->setDefault(true);


        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QCoreApplication::translate("LoginDialog", "\304\220\304\203ng Nh\341\272\255p H\341\273\207 Th\341\273\221ng", nullptr));
        LoginDialog->setStyleSheet(QCoreApplication::translate("LoginDialog", "\n"
"    QDialog { background: qlineargradient(x1:0,y1:0,x2:0,y2:1,\n"
"        stop:0 #eff6ff, stop:1 #dbeafe); }\n"
"    QLineEdit {\n"
"        border: 1.5px solid #93c5fd;\n"
"        border-radius: 8px;\n"
"        padding: 10px 14px;\n"
"        font-size: 14px;\n"
"        background: white;\n"
"    }\n"
"    QLineEdit:focus { border-color: #2563eb; }\n"
"   ", nullptr));
        lblLogo->setText(QCoreApplication::translate("LoginDialog", "\360\237\216\223", nullptr));
        lblLogo->setStyleSheet(QCoreApplication::translate("LoginDialog", "font-size:52px; padding:20px 0 8px 0; background:transparent;", nullptr));
        lblAppName->setText(QCoreApplication::translate("LoginDialog", "QU\341\272\242N L\303\235 H\341\273\222 S\306\240 SINH VI\303\212N", nullptr));
        lblAppName->setStyleSheet(QCoreApplication::translate("LoginDialog", "\n"
"       font-size: 17px;\n"
"       font-weight: bold;\n"
"       color: #1e3a8a;\n"
"       letter-spacing: 1px;\n"
"       padding-bottom: 4px;\n"
"       background: transparent;\n"
"      ", nullptr));
        lblSubtitle->setText(QCoreApplication::translate("LoginDialog", "Vui l\303\262ng \304\221\304\203ng nh\341\272\255p \304\221\341\273\203 ti\341\272\277p t\341\273\245c", nullptr));
        lblSubtitle->setStyleSheet(QCoreApplication::translate("LoginDialog", "color:#64748b; font-size:13px; padding-bottom:16px; background:transparent;", nullptr));
        cardWidget->setStyleSheet(QCoreApplication::translate("LoginDialog", "\n"
"       QWidget#cardWidget {\n"
"           background: white;\n"
"           border-radius: 12px;\n"
"           margin: 0 24px;\n"
"       }\n"
"      ", nullptr));
        label_user->setText(QCoreApplication::translate("LoginDialog", "T\303\252n \304\221\304\203ng nh\341\272\255p", nullptr));
        label_user->setStyleSheet(QCoreApplication::translate("LoginDialog", "font-weight:bold; color:#374151; font-size:13px; background:transparent;", nullptr));
        lineUsername->setPlaceholderText(QCoreApplication::translate("LoginDialog", "Nh\341\272\255p t\303\252n \304\221\304\203ng nh\341\272\255p...", nullptr));
        label_pass->setText(QCoreApplication::translate("LoginDialog", "M\341\272\255t kh\341\272\251u", nullptr));
        label_pass->setStyleSheet(QCoreApplication::translate("LoginDialog", "font-weight:bold; color:#374151; font-size:13px; background:transparent;", nullptr));
        linePassword->setPlaceholderText(QCoreApplication::translate("LoginDialog", "Nh\341\272\255p m\341\272\255t kh\341\272\251u...", nullptr));
        btnShowPass->setText(QCoreApplication::translate("LoginDialog", "\360\237\221\201", nullptr));
        btnShowPass->setStyleSheet(QCoreApplication::translate("LoginDialog", "\n"
"            QPushButton { background:#f1f5f9; border:1.5px solid #cbd5e1;\n"
"              border-radius:8px; font-size:16px; }\n"
"            QPushButton:hover { background:#e2e8f0; }\n"
"           ", nullptr));
#if QT_CONFIG(tooltip)
        btnShowPass->setToolTip(QCoreApplication::translate("LoginDialog", "Hi\341\273\203n th\341\273\213/\341\272\251n m\341\272\255t kh\341\272\251u", nullptr));
#endif // QT_CONFIG(tooltip)
        lblError->setText(QString());
        lblError->setStyleSheet(QCoreApplication::translate("LoginDialog", "\n"
"          color: #dc2626;\n"
"          background: #fef2f2;\n"
"          border: 1px solid #fecaca;\n"
"          border-radius: 6px;\n"
"          padding: 8px 10px;\n"
"          font-size: 12px;\n"
"         ", nullptr));
        btnLogin->setText(QCoreApplication::translate("LoginDialog", "\360\237\224\220  \304\220\304\203ng Nh\341\272\255p", nullptr));
        btnLogin->setStyleSheet(QCoreApplication::translate("LoginDialog", "\n"
"         QPushButton { background:#1e40af; color:white; padding:10px;\n"
"           border-radius:9px; font-weight:bold; font-size:14px; border:none; }\n"
"         QPushButton:hover { background:#1d4ed8; }\n"
"         QPushButton:pressed { background:#1e3a8a; }\n"
"        ", nullptr));
        btnCancel->setText(QCoreApplication::translate("LoginDialog", "Tho\303\241t", nullptr));
        btnCancel->setStyleSheet(QCoreApplication::translate("LoginDialog", "\n"
"         QPushButton { background:#94a3b8; color:white; padding:10px;\n"
"           border-radius:9px; font-size:13px; border:none; }\n"
"         QPushButton:hover { background:#64748b; }\n"
"        ", nullptr));
        lblDefaultHint->setText(QCoreApplication::translate("LoginDialog", "T\303\240i kho\341\272\243n m\341\272\267c \304\221\341\273\213nh: admin / admin123", nullptr));
        lblDefaultHint->setStyleSheet(QCoreApplication::translate("LoginDialog", "color:#94a3b8; font-size:11px; padding-bottom:8px; background:transparent;", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
