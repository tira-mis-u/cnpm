#include "logindialog.h"
#include "ui_logindialog.h"
#include "databasemanager.h"
#include <QMessageBox>
#include <QApplication>

LoginDialog::LoginDialog(QWidget* parent)
    : QDialog(parent), ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    setWindowTitle("Đăng Nhập - Quản Lý Sinh Viên");
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);


    // Mặc định hiển thị username admin
    ui->lineUsername->setText("admin");
    ui->linePassword->setEchoMode(QLineEdit::Password);
    ui->linePassword->setPlaceholderText("Nhập mật khẩu...");
    ui->lblError->hide();

    connect(ui->btnLogin,    &QPushButton::clicked,  this, &LoginDialog::onLogin);
    connect(ui->btnCancel,   &QPushButton::clicked,  this, &QDialog::reject);
    connect(ui->btnShowPass, &QPushButton::clicked,  this, &LoginDialog::onTogglePassword);
    connect(ui->linePassword,&QLineEdit::returnPressed, this, &LoginDialog::onLogin);
    connect(ui->lineUsername,&QLineEdit::returnPressed, this, [this]{ ui->linePassword->setFocus(); });

    ui->linePassword->setFocus();
    
    // Thay đổi logo trong LoginDialog thành logo_utt.png (phần khoanh đỏ)
    QPixmap logo(":/logo_utt.png");
    if (!logo.isNull()) {
        ui->lblLogo->setPixmap(logo.scaled(180, 80, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ui->lblLogo->setText(""); 
    }
}

LoginDialog::~LoginDialog() { delete ui; }

void LoginDialog::onLogin() {
    QString user = ui->lineUsername->text().trimmed();
    QString pass = ui->linePassword->text();

    if (user.isEmpty() || pass.isEmpty()) {
        ui->lblError->setText("Vui lòng nhập đầy đủ thông tin.");
        ui->lblError->show();
        return;
    }

    if (DatabaseManager::instance().verifyLogin(user, pass)) {
        accept();
    } else {
        m_attempts++;
        int remaining = 3 - m_attempts;

        if (remaining <= 0) {
            QMessageBox::critical(this, "Khóa tài khoản",
                "Đăng nhập sai 3 lần liên tiếp.\nỨng dụng sẽ đóng.");
            reject();
            return;
        }

        ui->lblError->setText(
            QString("Sai tên đăng nhập hoặc mật khẩu! (còn %1 lần thử)").arg(remaining));
        ui->lblError->show();
        ui->linePassword->clear();
        ui->linePassword->setFocus();
    }
}

void LoginDialog::onTogglePassword() {
    m_showPass = !m_showPass;
    ui->linePassword->setEchoMode(m_showPass ? QLineEdit::Normal : QLineEdit::Password);
    ui->btnShowPass->setText(m_showPass ? "Ẩn" : "Hiện");
}
