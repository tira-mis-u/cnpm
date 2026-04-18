#include "studentdialog.h"
#include "ui_studentdialog.h"
#include <QMessageBox>
#include <QStyledItemDelegate>

StudentDialog::StudentDialog(QWidget* parent,
                             const Student* student,
                             ClassController* classCtrl)
    : QDialog(parent)
    , ui(new Ui::StudentDialog)
    , m_student(student)
    , m_classCtrl(classCtrl)
    , m_isEditMode(student != nullptr)
{
    ui->setupUi(this);
    setWindowTitle(m_isEditMode ? "Sửa Thông Tin Sinh Viên" : "Thêm Sinh Viên Mới");
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    ui->comboGender->setItemDelegate(new QStyledItemDelegate(this));
    ui->comboClass->setItemDelegate(new QStyledItemDelegate(this));

    // Giới hạn ngày sinh
    ui->dateDOB->setDisplayFormat("dd/MM/yyyy");
    ui->dateDOB->setCalendarPopup(true);
    ui->dateDOB->setMaximumDate(QDate::currentDate());
    ui->dateDOB->setDate(QDate(2004, 1, 1));

    // Combobox giới tính
    ui->comboGender->addItem("Nam");
    ui->comboGender->addItem("Nữ");
    ui->comboGender->addItem("Khác");

    loadClasses();

    if (m_isEditMode) {
        populateForm();
        ui->lineStudentId->setReadOnly(true);
        ui->lineStudentId->setStyleSheet(
            "background:#f1f5f9;color:#64748b;border:1px solid #cbd5e1;border-radius:5px;padding:7px;");
    }

    // Real-time validate nút Save
    validateForm();
    connect(ui->lineStudentId, &QLineEdit::textChanged, this, &StudentDialog::validateForm);
    connect(ui->lineName,      &QLineEdit::textChanged, this, &StudentDialog::validateForm);
    connect(ui->comboClass,    QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &StudentDialog::validateForm);

    connect(ui->btnSave,   &QPushButton::clicked, this, &StudentDialog::onAccept);
    connect(ui->btnCancel, &QPushButton::clicked, this, &QDialog::reject);
}

StudentDialog::~StudentDialog() { delete ui; }

// ─── Load dữ liệu lớp vào ComboBox ──────────────────────────────────────────

void StudentDialog::loadClasses() {
    ui->comboClass->clear();
    ui->comboClass->addItem("-- Chọn lớp --", -1);
    auto classes = m_classCtrl->getAllClasses();
    for (const auto& c : classes) {
        ui->comboClass->addItem(
            QString("%1  [%2]").arg(c.getName()).arg(c.getDepartmentName()),
            c.getId()
        );
    }
}

// ─── Điền dữ liệu khi edit ───────────────────────────────────────────────────

void StudentDialog::populateForm() {
    ui->lineStudentId->setText(m_student->getStudentId());
    ui->lineName->setText(m_student->getFullName());
    ui->dateDOB->setDate(m_student->getDateOfBirth());
    ui->lineEmail->setText(m_student->getEmail());
    ui->linePhone->setText(m_student->getPhone());
    ui->textAddress->setPlainText(m_student->getAddress());

    // Giới tính
    int gIdx = static_cast<int>(m_student->getGender());
    if (gIdx >= 0 && gIdx < ui->comboGender->count())
        ui->comboGender->setCurrentIndex(gIdx);

    // Tìm và set lớp
    for (int i = 0; i < ui->comboClass->count(); ++i) {
        if (ui->comboClass->itemData(i).toInt() == m_student->getClassId()) {
            ui->comboClass->setCurrentIndex(i);
            break;
        }
    }
}

// ─── Real-time Validation ────────────────────────────────────────────────────

void StudentDialog::validateForm() {
    bool valid = !ui->lineStudentId->text().trimmed().isEmpty()
              && !ui->lineName->text().trimmed().isEmpty()
              && ui->comboClass->currentData().toInt() > 0;
    ui->btnSave->setEnabled(valid);
}

// ─── Submit ──────────────────────────────────────────────────────────────────

void StudentDialog::onAccept() {
    // Validate bắt buộc
    if (ui->lineStudentId->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Thiếu thông tin", "Vui lòng nhập Mã Sinh Viên.");
        ui->lineStudentId->setFocus();
        return;
    }
    if (ui->lineName->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Thiếu thông tin", "Vui lòng nhập Họ và Tên.");
        ui->lineName->setFocus();
        return;
    }
    if (ui->comboClass->currentData().toInt() <= 0) {
        QMessageBox::warning(this, "Thiếu thông tin", "Vui lòng chọn Lớp học.");
        ui->comboClass->setFocus();
        return;
    }

    // Validate email
    QString email = ui->lineEmail->text().trimmed();
    if (!email.isEmpty() && !Student::isValidEmail(email)) {
        QMessageBox::warning(this, "Email không hợp lệ",
            "Định dạng email sai.\nVí dụ đúng: sinhvien@gmail.com");
        ui->lineEmail->setFocus();
        return;
    }

    // Validate phone
    QString phone = ui->linePhone->text().trimmed();
    if (!phone.isEmpty() && !Student::isValidPhone(phone)) {
        QMessageBox::warning(this, "Số điện thoại không hợp lệ",
            "Số điện thoại phải có 10-11 chữ số, bắt đầu bằng 0 hoặc +84.\n"
            "Ví dụ: 0901234567 hoặc +84901234567");
        ui->linePhone->setFocus();
        return;
    }

    // Validate tuổi hợp lý (16-40 tuổi)
    QDate dob = ui->dateDOB->date();
    int age = dob.daysTo(QDate::currentDate()) / 365;
    if (age < 16 || age > 40) {
        if (QMessageBox::question(this, "Kiểm tra ngày sinh",
            QString("Tuổi sinh viên là %1. Có chắc ngày sinh đúng không?").arg(age),
            QMessageBox::Yes | QMessageBox::No) == QMessageBox::No) {
            ui->dateDOB->setFocus();
            return;
        }
    }

    accept();
}

// ─── Getter ──────────────────────────────────────────────────────────────────

Student StudentDialog::getStudent() const {
    Student::Gender gender = static_cast<Student::Gender>(ui->comboGender->currentIndex());
    int classId = ui->comboClass->currentData().toInt();

    return Student(
        ui->lineStudentId->text().trimmed().toUpper(),
        ui->lineName->text().trimmed(),
        ui->dateDOB->date(),
        gender,
        ui->lineEmail->text().trimmed().toLower(),
        ui->linePhone->text().trimmed(),
        ui->textAddress->toPlainText().trimmed(),
        classId
    );
}
