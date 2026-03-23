/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *lblHeader;
    QTabWidget *tabWidget;
    QWidget *tabStudents;
    QVBoxLayout *vlStudents;
    QHBoxLayout *hlStudentToolbar;
    QPushButton *btnAddStudent;
    QPushButton *btnEditStudent;
    QPushButton *btnDeleteStudent;
    QPushButton *btnExportCSV;
    QSpacerItem *spacerItem;
    QLineEdit *lineSearch;
    QPushButton *btnSearch;
    QPushButton *btnClearSearch;
    QTableWidget *tableStudents;
    QLabel *lblStudentCount;
    QWidget *tabClasses;
    QVBoxLayout *vlClasses;
    QHBoxLayout *hlClassToolbar;
    QPushButton *btnAddClass;
    QPushButton *btnEditClass;
    QPushButton *btnDeleteClass;
    QSpacerItem *spacerItem1;
    QTableWidget *tableClasses;
    QWidget *tabDepts;
    QVBoxLayout *vlDepts;
    QHBoxLayout *hlDeptToolbar;
    QPushButton *btnAddDept;
    QPushButton *btnEditDept;
    QPushButton *btnDeleteDept;
    QSpacerItem *spacerItem2;
    QTableWidget *tableDepts;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1200, 760);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(8, 8, 8, 4);
        lblHeader = new QLabel(centralwidget);
        lblHeader->setObjectName("lblHeader");
        lblHeader->setAlignment(Qt::AlignCenter);
        lblHeader->setMinimumHeight(60);

        verticalLayout->addWidget(lblHeader);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabStudents = new QWidget();
        tabStudents->setObjectName("tabStudents");
        vlStudents = new QVBoxLayout(tabStudents);
        vlStudents->setSpacing(8);
        vlStudents->setObjectName("vlStudents");
        hlStudentToolbar = new QHBoxLayout();
        hlStudentToolbar->setSpacing(6);
        hlStudentToolbar->setObjectName("hlStudentToolbar");
        btnAddStudent = new QPushButton(tabStudents);
        btnAddStudent->setObjectName("btnAddStudent");
        btnAddStudent->setMinimumHeight(38);

        hlStudentToolbar->addWidget(btnAddStudent);

        btnEditStudent = new QPushButton(tabStudents);
        btnEditStudent->setObjectName("btnEditStudent");
        btnEditStudent->setMinimumHeight(38);

        hlStudentToolbar->addWidget(btnEditStudent);

        btnDeleteStudent = new QPushButton(tabStudents);
        btnDeleteStudent->setObjectName("btnDeleteStudent");
        btnDeleteStudent->setMinimumHeight(38);

        hlStudentToolbar->addWidget(btnDeleteStudent);

        btnExportCSV = new QPushButton(tabStudents);
        btnExportCSV->setObjectName("btnExportCSV");
        btnExportCSV->setMinimumHeight(38);

        hlStudentToolbar->addWidget(btnExportCSV);

        spacerItem = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hlStudentToolbar->addItem(spacerItem);

        lineSearch = new QLineEdit(tabStudents);
        lineSearch->setObjectName("lineSearch");
        lineSearch->setMinimumHeight(38);
        lineSearch->setMinimumWidth(280);

        hlStudentToolbar->addWidget(lineSearch);

        btnSearch = new QPushButton(tabStudents);
        btnSearch->setObjectName("btnSearch");
        btnSearch->setMinimumHeight(38);

        hlStudentToolbar->addWidget(btnSearch);

        btnClearSearch = new QPushButton(tabStudents);
        btnClearSearch->setObjectName("btnClearSearch");
        btnClearSearch->setMinimumHeight(38);

        hlStudentToolbar->addWidget(btnClearSearch);


        vlStudents->addLayout(hlStudentToolbar);

        tableStudents = new QTableWidget(tabStudents);
        tableStudents->setObjectName("tableStudents");
        tableStudents->setAlternatingRowColors(true);
        tableStudents->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableStudents->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableStudents->setSortingEnabled(true);

        vlStudents->addWidget(tableStudents);

        lblStudentCount = new QLabel(tabStudents);
        lblStudentCount->setObjectName("lblStudentCount");

        vlStudents->addWidget(lblStudentCount);

        tabWidget->addTab(tabStudents, QString());
        tabClasses = new QWidget();
        tabClasses->setObjectName("tabClasses");
        vlClasses = new QVBoxLayout(tabClasses);
        vlClasses->setSpacing(8);
        vlClasses->setObjectName("vlClasses");
        hlClassToolbar = new QHBoxLayout();
        hlClassToolbar->setSpacing(6);
        hlClassToolbar->setObjectName("hlClassToolbar");
        btnAddClass = new QPushButton(tabClasses);
        btnAddClass->setObjectName("btnAddClass");
        btnAddClass->setMinimumHeight(38);

        hlClassToolbar->addWidget(btnAddClass);

        btnEditClass = new QPushButton(tabClasses);
        btnEditClass->setObjectName("btnEditClass");
        btnEditClass->setMinimumHeight(38);

        hlClassToolbar->addWidget(btnEditClass);

        btnDeleteClass = new QPushButton(tabClasses);
        btnDeleteClass->setObjectName("btnDeleteClass");
        btnDeleteClass->setMinimumHeight(38);

        hlClassToolbar->addWidget(btnDeleteClass);

        spacerItem1 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hlClassToolbar->addItem(spacerItem1);


        vlClasses->addLayout(hlClassToolbar);

        tableClasses = new QTableWidget(tabClasses);
        tableClasses->setObjectName("tableClasses");
        tableClasses->setAlternatingRowColors(true);
        tableClasses->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableClasses->setEditTriggers(QAbstractItemView::NoEditTriggers);

        vlClasses->addWidget(tableClasses);

        tabWidget->addTab(tabClasses, QString());
        tabDepts = new QWidget();
        tabDepts->setObjectName("tabDepts");
        vlDepts = new QVBoxLayout(tabDepts);
        vlDepts->setSpacing(8);
        vlDepts->setObjectName("vlDepts");
        hlDeptToolbar = new QHBoxLayout();
        hlDeptToolbar->setSpacing(6);
        hlDeptToolbar->setObjectName("hlDeptToolbar");
        btnAddDept = new QPushButton(tabDepts);
        btnAddDept->setObjectName("btnAddDept");
        btnAddDept->setMinimumHeight(38);

        hlDeptToolbar->addWidget(btnAddDept);

        btnEditDept = new QPushButton(tabDepts);
        btnEditDept->setObjectName("btnEditDept");
        btnEditDept->setMinimumHeight(38);

        hlDeptToolbar->addWidget(btnEditDept);

        btnDeleteDept = new QPushButton(tabDepts);
        btnDeleteDept->setObjectName("btnDeleteDept");
        btnDeleteDept->setMinimumHeight(38);

        hlDeptToolbar->addWidget(btnDeleteDept);

        spacerItem2 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hlDeptToolbar->addItem(spacerItem2);


        vlDepts->addLayout(hlDeptToolbar);

        tableDepts = new QTableWidget(tabDepts);
        tableDepts->setObjectName("tableDepts");
        tableDepts->setAlternatingRowColors(true);
        tableDepts->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableDepts->setEditTriggers(QAbstractItemView::NoEditTriggers);

        vlDepts->addWidget(tableDepts);

        tabWidget->addTab(tabDepts, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Ph\341\272\247n M\341\273\201m Qu\341\272\243n L\303\275 H\341\273\223 S\306\241 Sinh Vi\303\252n", nullptr));
        lblHeader->setText(QCoreApplication::translate("MainWindow", "\360\237\216\223  PH\341\272\246N M\341\273\200M QU\341\272\242N L\303\235 H\341\273\222 S\306\240 SINH VI\303\212N", nullptr));
        lblHeader->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"        background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"            stop:0 #1e3a8a, stop:0.5 #1e40af, stop:1 #2563eb);\n"
"        color: white;\n"
"        font-size: 22px;\n"
"        font-weight: bold;\n"
"        padding: 16px;\n"
"        border-radius: 10px;\n"
"        margin-bottom: 6px;\n"
"        letter-spacing: 1px;\n"
"       ", nullptr));
        tabWidget->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"        QTabBar::tab {\n"
"            padding: 10px 24px;\n"
"            font-size: 13px;\n"
"            font-weight: bold;\n"
"            color: #64748b;\n"
"            border: none;\n"
"            background: transparent;\n"
"        }\n"
"        QTabBar::tab:selected {\n"
"            color: #1e40af;\n"
"            border-bottom: 3px solid #1e40af;\n"
"        }\n"
"        QTabBar::tab:hover:!selected { color: #334155; }\n"
"        QTabWidget::pane {\n"
"            border: 1px solid #e2e8f0;\n"
"            border-radius: 8px;\n"
"            background: white;\n"
"            padding: 8px;\n"
"        }\n"
"       ", nullptr));
        btnAddStudent->setText(QCoreApplication::translate("MainWindow", "\342\236\225  Th\303\252m Sinh Vi\303\252n", nullptr));
        btnAddStudent->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"              QPushButton { background:#16a34a; color:white; padding:8px 18px;\n"
"                border-radius:7px; font-weight:bold; font-size:13px; border:none; }\n"
"              QPushButton:hover { background:#15803d; }\n"
"              QPushButton:pressed { background:#166534; }\n"
"             ", nullptr));
#if QT_CONFIG(tooltip)
        btnAddStudent->setToolTip(QCoreApplication::translate("MainWindow", "Th\303\252m sinh vi\303\252n m\341\273\233i v\303\240o h\341\273\207 th\341\273\221ng", nullptr));
#endif // QT_CONFIG(tooltip)
        btnEditStudent->setText(QCoreApplication::translate("MainWindow", "\342\234\217\357\270\217  S\341\273\255a", nullptr));
        btnEditStudent->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"              QPushButton { background:#2563eb; color:white; padding:8px 18px;\n"
"                border-radius:7px; font-weight:bold; font-size:13px; border:none; }\n"
"              QPushButton:hover { background:#1d4ed8; }\n"
"              QPushButton:pressed { background:#1e40af; }\n"
"             ", nullptr));
#if QT_CONFIG(tooltip)
        btnEditStudent->setToolTip(QCoreApplication::translate("MainWindow", "S\341\273\255a th\303\264ng tin sinh vi\303\252n \304\221\306\260\341\273\243c ch\341\273\215n", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDeleteStudent->setText(QCoreApplication::translate("MainWindow", "\360\237\227\221\357\270\217  X\303\263a", nullptr));
        btnDeleteStudent->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"              QPushButton { background:#dc2626; color:white; padding:8px 18px;\n"
"                border-radius:7px; font-weight:bold; font-size:13px; border:none; }\n"
"              QPushButton:hover { background:#b91c1c; }\n"
"              QPushButton:pressed { background:#991b1b; }\n"
"             ", nullptr));
#if QT_CONFIG(tooltip)
        btnDeleteStudent->setToolTip(QCoreApplication::translate("MainWindow", "X\303\263a sinh vi\303\252n \304\221\306\260\341\273\243c ch\341\273\215n", nullptr));
#endif // QT_CONFIG(tooltip)
        btnExportCSV->setText(QCoreApplication::translate("MainWindow", "\360\237\223\245  Xu\341\272\245t CSV", nullptr));
        btnExportCSV->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"              QPushButton { background:#d97706; color:white; padding:8px 18px;\n"
"                border-radius:7px; font-weight:bold; font-size:13px; border:none; }\n"
"              QPushButton:hover { background:#b45309; }\n"
"              QPushButton:pressed { background:#92400e; }\n"
"             ", nullptr));
#if QT_CONFIG(tooltip)
        btnExportCSV->setToolTip(QCoreApplication::translate("MainWindow", "Xu\341\272\245t to\303\240n b\341\273\231 danh s\303\241ch ra file CSV", nullptr));
#endif // QT_CONFIG(tooltip)
        lineSearch->setPlaceholderText(QCoreApplication::translate("MainWindow", "\360\237\224\215  T\303\254m theo m\303\243 SV ho\341\272\267c t\303\252n sinh vi\303\252n...", nullptr));
        lineSearch->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"              QLineEdit {\n"
"                padding: 8px 12px;\n"
"                border: 2px solid #cbd5e1;\n"
"                border-radius: 7px;\n"
"                font-size: 13px;\n"
"                background: white;\n"
"              }\n"
"              QLineEdit:focus { border-color: #3b82f6; }\n"
"             ", nullptr));
        btnSearch->setText(QCoreApplication::translate("MainWindow", "T\303\254m", nullptr));
        btnSearch->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"              QPushButton { background:#4f46e5; color:white; padding:8px 18px;\n"
"                border-radius:7px; font-weight:bold; font-size:13px; border:none; }\n"
"              QPushButton:hover { background:#4338ca; }\n"
"             ", nullptr));
        btnClearSearch->setText(QCoreApplication::translate("MainWindow", "\342\234\226  X\303\263a l\341\273\215c", nullptr));
        btnClearSearch->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"              QPushButton { background:#94a3b8; color:white; padding:8px 14px;\n"
"                border-radius:7px; font-size:13px; border:none; }\n"
"              QPushButton:hover { background:#64748b; }\n"
"             ", nullptr));
        lblStudentCount->setText(QCoreApplication::translate("MainWindow", "T\341\273\225ng: 0 sinh vi\303\252n", nullptr));
        lblStudentCount->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#64748b; font-size:12px; padding:2px 4px;", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabStudents), QCoreApplication::translate("MainWindow", "  \360\237\221\250\342\200\215\360\237\216\223  Sinh Vi\303\252n  ", nullptr));
        btnAddClass->setText(QCoreApplication::translate("MainWindow", "\342\236\225  Th\303\252m L\341\273\233p", nullptr));
        btnAddClass->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"              QPushButton { background:#16a34a; color:white; padding:8px 18px;\n"
"                border-radius:7px; font-weight:bold; font-size:13px; border:none; }\n"
"              QPushButton:hover { background:#15803d; }\n"
"             ", nullptr));
        btnEditClass->setText(QCoreApplication::translate("MainWindow", "\342\234\217\357\270\217  S\341\273\255a", nullptr));
        btnEditClass->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"              QPushButton { background:#2563eb; color:white; padding:8px 18px;\n"
"                border-radius:7px; font-weight:bold; font-size:13px; border:none; }\n"
"              QPushButton:hover { background:#1d4ed8; }\n"
"             ", nullptr));
        btnDeleteClass->setText(QCoreApplication::translate("MainWindow", "\360\237\227\221\357\270\217  X\303\263a", nullptr));
        btnDeleteClass->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"              QPushButton { background:#dc2626; color:white; padding:8px 18px;\n"
"                border-radius:7px; font-weight:bold; font-size:13px; border:none; }\n"
"              QPushButton:hover { background:#b91c1c; }\n"
"             ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabClasses), QCoreApplication::translate("MainWindow", "  \360\237\223\232  L\341\273\233p H\341\273\215c  ", nullptr));
        btnAddDept->setText(QCoreApplication::translate("MainWindow", "\342\236\225  Th\303\252m Khoa", nullptr));
        btnAddDept->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"              QPushButton { background:#16a34a; color:white; padding:8px 18px;\n"
"                border-radius:7px; font-weight:bold; font-size:13px; border:none; }\n"
"              QPushButton:hover { background:#15803d; }\n"
"             ", nullptr));
        btnEditDept->setText(QCoreApplication::translate("MainWindow", "\342\234\217\357\270\217  S\341\273\255a", nullptr));
        btnEditDept->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"              QPushButton { background:#2563eb; color:white; padding:8px 18px;\n"
"                border-radius:7px; font-weight:bold; font-size:13px; border:none; }\n"
"              QPushButton:hover { background:#1d4ed8; }\n"
"             ", nullptr));
        btnDeleteDept->setText(QCoreApplication::translate("MainWindow", "\360\237\227\221\357\270\217  X\303\263a", nullptr));
        btnDeleteDept->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"              QPushButton { background:#dc2626; color:white; padding:8px 18px;\n"
"                border-radius:7px; font-weight:bold; font-size:13px; border:none; }\n"
"              QPushButton:hover { background:#b91c1c; }\n"
"             ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabDepts), QCoreApplication::translate("MainWindow", "  \360\237\217\253  Khoa  ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
