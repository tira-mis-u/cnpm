#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginDialog; }
QT_END_NAMESPACE

/**
 * @brief LoginDialog - Màn hình đăng nhập hệ thống
 *
 * Giới hạn 3 lần thử. Sau 3 lần sai → đóng ứng dụng.
 * Mật khẩu được hash SHA-256 trước khi so sánh.
 */
class LoginDialog : public QDialog {
    Q_OBJECT

public:
    explicit LoginDialog(QWidget* parent = nullptr);
    ~LoginDialog();

private slots:
    void onLogin();
    void onTogglePassword();

private:
    Ui::LoginDialog* ui;
    int  m_attempts  = 0;
    bool m_showPass  = false;
};

#endif // LOGINDIALOG_H
