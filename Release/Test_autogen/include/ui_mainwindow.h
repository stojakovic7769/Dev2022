/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widgetLogin;
    QPushButton *btnLogin;
    QLineEdit *lineEditName;
    QLineEdit *lineEditPwd;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1085, 725);
        MainWindow->setFocusPolicy(Qt::TabFocus);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widgetLogin = new QWidget(centralwidget);
        widgetLogin->setObjectName(QString::fromUtf8("widgetLogin"));
        widgetLogin->setGeometry(QRect(400, 300, 321, 171));
        btnLogin = new QPushButton(widgetLogin);
        btnLogin->setObjectName(QString::fromUtf8("btnLogin"));
        btnLogin->setGeometry(QRect(40, 124, 231, 31));
        btnLogin->setStyleSheet(QString::fromUtf8("color:white;background:rgb(68,129,84);border-radius:6px"));
        lineEditName = new QLineEdit(widgetLogin);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));
        lineEditName->setGeometry(QRect(160, 20, 141, 31));
        lineEditName->setAutoFillBackground(false);
        lineEditName->setStyleSheet(QString::fromUtf8("border-radius:10px"));
        lineEditPwd = new QLineEdit(widgetLogin);
        lineEditPwd->setObjectName(QString::fromUtf8("lineEditPwd"));
        lineEditPwd->setGeometry(QRect(160, 70, 141, 31));
        lineEditPwd->setStyleSheet(QString::fromUtf8("border-radius:10px"));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        btnLogin->setText(QApplication::translate("MainWindow", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
