/********************************************************************************
** Form generated from reading UI file 'operatewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPERATEWINDOW_H
#define UI_OPERATEWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OperateWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *twOperate;
    QWidget *tabTacticalManage;
    QPushButton *btn_PicWrite;
    QPushButton *btn_PicRead;
    QWidget *tabSchemePreparation;
    QWidget *tabSubjectManager;
    QWidget *tabMarkManage;
    QTableView *tvMarkManage;
    QWidget *widgetMarkManage;
    QWidget *layoutWidget;
    QGridLayout *gridLayoutMarkManager_1;
    QLabel *labelexercise;
    QComboBox *cbxExerciseOption;
    QLabel *labelGrade;
    QComboBox *cbxGradeOption;
    QLabel *labeleTime;
    QComboBox *cbxDate;
    QLabel *labelCompany;
    QComboBox *cbxCompany;
    QLabel *labelMMID;
    QTextEdit *textEditMMID;
    QLabel *labelMMName;
    QTextEdit *textEditMMName;
    QPushButton *btnFilterQueryMarkManage;
    QWidget *layoutWidget1;
    QGridLayout *gridLayoutMarkManage_2;
    QPushButton *btnMarkManageImport;
    QPushButton *btnMarkManageImportDB;
    QPushButton *btnClearListMarkManage;
    QPushButton *btnNameIDQueryMarkManage;
    QWidget *tabStuInfo;
    QTableView *tvStuInfo;
    QWidget *widget;
    QPushButton *btnQuery;
    QWidget *layoutWidget2;
    QGridLayout *gridLayoutStuInfo_1;
    QLabel *labelName;
    QTextEdit *textEditName;
    QLabel *labelID;
    QTextEdit *textEditID;
    QLabel *labelIGrade;
    QComboBox *comboBoxGrade;
    QLabel *labelIPro;
    QComboBox *comboBoxPro;
    QPushButton *btnQueryByGS;
    QWidget *layoutWidget3;
    QGridLayout *gridLayoutStuInfo_2;
    QPushButton *btnImport;
    QPushButton *btnInputDB;
    QPushButton *btnClearList;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *OperateWindow)
    {
        if (OperateWindow->objectName().isEmpty())
            OperateWindow->setObjectName(QString::fromUtf8("OperateWindow"));
        OperateWindow->resize(1538, 904);
        centralwidget = new QWidget(OperateWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        twOperate = new QTabWidget(centralwidget);
        twOperate->setObjectName(QString::fromUtf8("twOperate"));
        twOperate->setGeometry(QRect(0, 0, 1241, 751));
        twOperate->setStyleSheet(QString::fromUtf8("QTabBar::tab{width:252;height:40; font:bold 20px \345\276\256\350\275\257\351\233\205\351\273\221;background-color:rgb(132, 171, 208); color:white;}\n"
"QTabBar::tab:selected{color:#000000;border-bottom:6px solid rgb(0,0,0);background-color:#FFFFFF;}"));
        twOperate->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        tabTacticalManage = new QWidget();
        tabTacticalManage->setObjectName(QString::fromUtf8("tabTacticalManage"));
        btn_PicWrite = new QPushButton(tabTacticalManage);
        btn_PicWrite->setObjectName(QString::fromUtf8("btn_PicWrite"));
        btn_PicWrite->setGeometry(QRect(760, 580, 111, 25));
        btn_PicRead = new QPushButton(tabTacticalManage);
        btn_PicRead->setObjectName(QString::fromUtf8("btn_PicRead"));
        btn_PicRead->setGeometry(QRect(890, 580, 111, 25));
        twOperate->addTab(tabTacticalManage, QString());
        tabSchemePreparation = new QWidget();
        tabSchemePreparation->setObjectName(QString::fromUtf8("tabSchemePreparation"));
        twOperate->addTab(tabSchemePreparation, QString());
        tabSubjectManager = new QWidget();
        tabSubjectManager->setObjectName(QString::fromUtf8("tabSubjectManager"));
        twOperate->addTab(tabSubjectManager, QString());
        tabMarkManage = new QWidget();
        tabMarkManage->setObjectName(QString::fromUtf8("tabMarkManage"));
        tvMarkManage = new QTableView(tabMarkManage);
        tvMarkManage->setObjectName(QString::fromUtf8("tvMarkManage"));
        tvMarkManage->setGeometry(QRect(0, 10, 910, 721));
        widgetMarkManage = new QWidget(tabMarkManage);
        widgetMarkManage->setObjectName(QString::fromUtf8("widgetMarkManage"));
        widgetMarkManage->setGeometry(QRect(920, 10, 311, 371));
        layoutWidget = new QWidget(widgetMarkManage);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(3, 12, 311, 351));
        gridLayoutMarkManager_1 = new QGridLayout(layoutWidget);
        gridLayoutMarkManager_1->setObjectName(QString::fromUtf8("gridLayoutMarkManager_1"));
        gridLayoutMarkManager_1->setContentsMargins(0, 0, 0, 0);
        labelexercise = new QLabel(layoutWidget);
        labelexercise->setObjectName(QString::fromUtf8("labelexercise"));
        labelexercise->setMaximumSize(QSize(85, 16777215));
        QFont font;
        font.setPointSize(13);
        labelexercise->setFont(font);

        gridLayoutMarkManager_1->addWidget(labelexercise, 0, 0, 1, 1);

        cbxExerciseOption = new QComboBox(layoutWidget);
        cbxExerciseOption->setObjectName(QString::fromUtf8("cbxExerciseOption"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cbxExerciseOption->sizePolicy().hasHeightForWidth());
        cbxExerciseOption->setSizePolicy(sizePolicy);
        cbxExerciseOption->setMaximumSize(QSize(160, 50));

        gridLayoutMarkManager_1->addWidget(cbxExerciseOption, 0, 1, 1, 1);

        labelGrade = new QLabel(layoutWidget);
        labelGrade->setObjectName(QString::fromUtf8("labelGrade"));
        labelGrade->setMaximumSize(QSize(85, 16777215));
        labelGrade->setFont(font);

        gridLayoutMarkManager_1->addWidget(labelGrade, 1, 0, 1, 1);

        cbxGradeOption = new QComboBox(layoutWidget);
        cbxGradeOption->setObjectName(QString::fromUtf8("cbxGradeOption"));
        sizePolicy.setHeightForWidth(cbxGradeOption->sizePolicy().hasHeightForWidth());
        cbxGradeOption->setSizePolicy(sizePolicy);
        cbxGradeOption->setMaximumSize(QSize(160, 50));

        gridLayoutMarkManager_1->addWidget(cbxGradeOption, 1, 1, 1, 1);

        labeleTime = new QLabel(layoutWidget);
        labeleTime->setObjectName(QString::fromUtf8("labeleTime"));
        labeleTime->setMaximumSize(QSize(85, 16777215));
        labeleTime->setFont(font);

        gridLayoutMarkManager_1->addWidget(labeleTime, 2, 0, 1, 1);

        cbxDate = new QComboBox(layoutWidget);
        cbxDate->setObjectName(QString::fromUtf8("cbxDate"));
        sizePolicy.setHeightForWidth(cbxDate->sizePolicy().hasHeightForWidth());
        cbxDate->setSizePolicy(sizePolicy);
        cbxDate->setMaximumSize(QSize(160, 50));

        gridLayoutMarkManager_1->addWidget(cbxDate, 2, 1, 1, 1);

        labelCompany = new QLabel(layoutWidget);
        labelCompany->setObjectName(QString::fromUtf8("labelCompany"));
        labelCompany->setMaximumSize(QSize(85, 16777215));
        labelCompany->setFont(font);

        gridLayoutMarkManager_1->addWidget(labelCompany, 3, 0, 1, 1);

        cbxCompany = new QComboBox(layoutWidget);
        cbxCompany->setObjectName(QString::fromUtf8("cbxCompany"));
        sizePolicy.setHeightForWidth(cbxCompany->sizePolicy().hasHeightForWidth());
        cbxCompany->setSizePolicy(sizePolicy);
        cbxCompany->setMaximumSize(QSize(160, 50));

        gridLayoutMarkManager_1->addWidget(cbxCompany, 3, 1, 1, 1);

        labelMMID = new QLabel(layoutWidget);
        labelMMID->setObjectName(QString::fromUtf8("labelMMID"));
        labelMMID->setMaximumSize(QSize(85, 16777215));
        labelMMID->setFont(font);

        gridLayoutMarkManager_1->addWidget(labelMMID, 4, 0, 1, 1);

        textEditMMID = new QTextEdit(layoutWidget);
        textEditMMID->setObjectName(QString::fromUtf8("textEditMMID"));
        sizePolicy.setHeightForWidth(textEditMMID->sizePolicy().hasHeightForWidth());
        textEditMMID->setSizePolicy(sizePolicy);
        textEditMMID->setMaximumSize(QSize(160, 50));
        QFont font1;
        font1.setPointSize(18);
        textEditMMID->setFont(font1);

        gridLayoutMarkManager_1->addWidget(textEditMMID, 4, 1, 1, 1);

        labelMMName = new QLabel(layoutWidget);
        labelMMName->setObjectName(QString::fromUtf8("labelMMName"));
        labelMMName->setMaximumSize(QSize(85, 16777215));
        labelMMName->setFont(font);

        gridLayoutMarkManager_1->addWidget(labelMMName, 5, 0, 1, 1);

        textEditMMName = new QTextEdit(layoutWidget);
        textEditMMName->setObjectName(QString::fromUtf8("textEditMMName"));
        sizePolicy.setHeightForWidth(textEditMMName->sizePolicy().hasHeightForWidth());
        textEditMMName->setSizePolicy(sizePolicy);
        textEditMMName->setMaximumSize(QSize(160, 50));
        textEditMMName->setFont(font1);

        gridLayoutMarkManager_1->addWidget(textEditMMName, 5, 1, 1, 1);

        btnFilterQueryMarkManage = new QPushButton(tabMarkManage);
        btnFilterQueryMarkManage->setObjectName(QString::fromUtf8("btnFilterQueryMarkManage"));
        btnFilterQueryMarkManage->setGeometry(QRect(930, 440, 281, 41));
        QFont font2;
        font2.setPointSize(15);
        btnFilterQueryMarkManage->setFont(font2);
        layoutWidget1 = new QWidget(tabMarkManage);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(930, 630, 312, 70));
        gridLayoutMarkManage_2 = new QGridLayout(layoutWidget1);
        gridLayoutMarkManage_2->setObjectName(QString::fromUtf8("gridLayoutMarkManage_2"));
        gridLayoutMarkManage_2->setSizeConstraint(QLayout::SetNoConstraint);
        gridLayoutMarkManage_2->setContentsMargins(0, 0, 0, 0);
        btnMarkManageImport = new QPushButton(layoutWidget1);
        btnMarkManageImport->setObjectName(QString::fromUtf8("btnMarkManageImport"));
        sizePolicy.setHeightForWidth(btnMarkManageImport->sizePolicy().hasHeightForWidth());
        btnMarkManageImport->setSizePolicy(sizePolicy);
        btnMarkManageImport->setMinimumSize(QSize(152, 0));
        btnMarkManageImport->setMaximumSize(QSize(152, 31));

        gridLayoutMarkManage_2->addWidget(btnMarkManageImport, 0, 0, 1, 1);

        btnMarkManageImportDB = new QPushButton(layoutWidget1);
        btnMarkManageImportDB->setObjectName(QString::fromUtf8("btnMarkManageImportDB"));
        btnMarkManageImportDB->setMaximumSize(QSize(152, 31));

        gridLayoutMarkManage_2->addWidget(btnMarkManageImportDB, 0, 1, 1, 1);

        btnClearListMarkManage = new QPushButton(layoutWidget1);
        btnClearListMarkManage->setObjectName(QString::fromUtf8("btnClearListMarkManage"));
        btnClearListMarkManage->setMaximumSize(QSize(152, 31));

        gridLayoutMarkManage_2->addWidget(btnClearListMarkManage, 1, 0, 1, 2);

        btnNameIDQueryMarkManage = new QPushButton(tabMarkManage);
        btnNameIDQueryMarkManage->setObjectName(QString::fromUtf8("btnNameIDQueryMarkManage"));
        btnNameIDQueryMarkManage->setGeometry(QRect(930, 390, 281, 41));
        btnNameIDQueryMarkManage->setFont(font2);
        twOperate->addTab(tabMarkManage, QString());
        tabStuInfo = new QWidget();
        tabStuInfo->setObjectName(QString::fromUtf8("tabStuInfo"));
        tvStuInfo = new QTableView(tabStuInfo);
        tvStuInfo->setObjectName(QString::fromUtf8("tvStuInfo"));
        tvStuInfo->setGeometry(QRect(0, 10, 910, 721));
        tvStuInfo->horizontalHeader()->setMinimumSectionSize(20);
        tvStuInfo->horizontalHeader()->setStretchLastSection(true);
        widget = new QWidget(tabStuInfo);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(920, 30, 311, 331));
        btnQuery = new QPushButton(widget);
        btnQuery->setObjectName(QString::fromUtf8("btnQuery"));
        btnQuery->setGeometry(QRect(10, 270, 141, 41));
        layoutWidget2 = new QWidget(widget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 0, 301, 231));
        gridLayoutStuInfo_1 = new QGridLayout(layoutWidget2);
        gridLayoutStuInfo_1->setObjectName(QString::fromUtf8("gridLayoutStuInfo_1"));
        gridLayoutStuInfo_1->setContentsMargins(0, 0, 0, 0);
        labelName = new QLabel(layoutWidget2);
        labelName->setObjectName(QString::fromUtf8("labelName"));
        labelName->setMaximumSize(QSize(70, 16777215));
        labelName->setFont(font);

        gridLayoutStuInfo_1->addWidget(labelName, 0, 0, 1, 1);

        textEditName = new QTextEdit(layoutWidget2);
        textEditName->setObjectName(QString::fromUtf8("textEditName"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(227);
        sizePolicy1.setVerticalStretch(60);
        sizePolicy1.setHeightForWidth(textEditName->sizePolicy().hasHeightForWidth());
        textEditName->setSizePolicy(sizePolicy1);
        textEditName->setMaximumSize(QSize(190, 50));
        QFont font3;
        font3.setPointSize(19);
        textEditName->setFont(font3);

        gridLayoutStuInfo_1->addWidget(textEditName, 0, 1, 1, 1);

        labelID = new QLabel(layoutWidget2);
        labelID->setObjectName(QString::fromUtf8("labelID"));
        labelID->setFont(font);

        gridLayoutStuInfo_1->addWidget(labelID, 1, 0, 1, 1);

        textEditID = new QTextEdit(layoutWidget2);
        textEditID->setObjectName(QString::fromUtf8("textEditID"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(227);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(textEditID->sizePolicy().hasHeightForWidth());
        textEditID->setSizePolicy(sizePolicy2);
        textEditID->setMaximumSize(QSize(190, 50));
        textEditID->setFont(font3);

        gridLayoutStuInfo_1->addWidget(textEditID, 1, 1, 1, 1);

        labelIGrade = new QLabel(layoutWidget2);
        labelIGrade->setObjectName(QString::fromUtf8("labelIGrade"));
        labelIGrade->setFont(font);

        gridLayoutStuInfo_1->addWidget(labelIGrade, 2, 0, 1, 1);

        comboBoxGrade = new QComboBox(layoutWidget2);
        comboBoxGrade->setObjectName(QString::fromUtf8("comboBoxGrade"));
        sizePolicy.setHeightForWidth(comboBoxGrade->sizePolicy().hasHeightForWidth());
        comboBoxGrade->setSizePolicy(sizePolicy);
        comboBoxGrade->setMaximumSize(QSize(190, 50));

        gridLayoutStuInfo_1->addWidget(comboBoxGrade, 2, 1, 1, 1);

        labelIPro = new QLabel(layoutWidget2);
        labelIPro->setObjectName(QString::fromUtf8("labelIPro"));
        labelIPro->setFont(font);

        gridLayoutStuInfo_1->addWidget(labelIPro, 3, 0, 1, 1);

        comboBoxPro = new QComboBox(layoutWidget2);
        comboBoxPro->setObjectName(QString::fromUtf8("comboBoxPro"));
        sizePolicy.setHeightForWidth(comboBoxPro->sizePolicy().hasHeightForWidth());
        comboBoxPro->setSizePolicy(sizePolicy);
        comboBoxPro->setMaximumSize(QSize(190, 50));

        gridLayoutStuInfo_1->addWidget(comboBoxPro, 3, 1, 1, 1);

        btnQueryByGS = new QPushButton(widget);
        btnQueryByGS->setObjectName(QString::fromUtf8("btnQueryByGS"));
        btnQueryByGS->setGeometry(QRect(160, 270, 141, 41));
        layoutWidget3 = new QWidget(tabStuInfo);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(930, 630, 311, 70));
        gridLayoutStuInfo_2 = new QGridLayout(layoutWidget3);
        gridLayoutStuInfo_2->setObjectName(QString::fromUtf8("gridLayoutStuInfo_2"));
        gridLayoutStuInfo_2->setContentsMargins(0, 0, 0, 0);
        btnImport = new QPushButton(layoutWidget3);
        btnImport->setObjectName(QString::fromUtf8("btnImport"));

        gridLayoutStuInfo_2->addWidget(btnImport, 0, 0, 1, 1);

        btnInputDB = new QPushButton(layoutWidget3);
        btnInputDB->setObjectName(QString::fromUtf8("btnInputDB"));

        gridLayoutStuInfo_2->addWidget(btnInputDB, 0, 1, 1, 1);

        btnClearList = new QPushButton(layoutWidget3);
        btnClearList->setObjectName(QString::fromUtf8("btnClearList"));

        gridLayoutStuInfo_2->addWidget(btnClearList, 1, 0, 1, 1);

        twOperate->addTab(tabStuInfo, QString());
        OperateWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(OperateWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1538, 22));
        OperateWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(OperateWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        OperateWindow->setStatusBar(statusbar);

        retranslateUi(OperateWindow);

        twOperate->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(OperateWindow);
    } // setupUi

    void retranslateUi(QMainWindow *OperateWindow)
    {
        OperateWindow->setWindowTitle(QApplication::translate("OperateWindow", " TacticalControl", nullptr));
        btn_PicWrite->setText(QApplication::translate("OperateWindow", "\345\206\231\345\205\245", nullptr));
        btn_PicRead->setText(QApplication::translate("OperateWindow", "\350\257\273\345\207\272", nullptr));
        twOperate->setTabText(twOperate->indexOf(tabTacticalManage), QApplication::translate("OperateWindow", "\346\210\230\346\234\257\346\203\205\345\206\265\347\256\241\347\220\206", nullptr));
        twOperate->setTabText(twOperate->indexOf(tabSchemePreparation), QApplication::translate("OperateWindow", "\351\200\232\350\257\235\346\226\271\346\241\210\346\213\237\345\210\266", nullptr));
        twOperate->setTabText(twOperate->indexOf(tabSubjectManager), QApplication::translate("OperateWindow", "\350\200\203\346\240\270\347\247\221\347\233\256\347\256\241\347\220\206", nullptr));
        labelexercise->setText(QApplication::translate("OperateWindow", "\350\200\203\346\240\270\347\247\221\347\233\256", nullptr));
        labelGrade->setText(QApplication::translate("OperateWindow", "\345\271\264         \347\272\247", nullptr));
        labeleTime->setText(QApplication::translate("OperateWindow", "\350\200\203\346\240\270\345\255\246\345\271\264", nullptr));
        labelCompany->setText(QApplication::translate("OperateWindow", "\351\230\237         \345\210\253", nullptr));
        labelMMID->setText(QApplication::translate("OperateWindow", "\345\255\246         \345\217\267", nullptr));
        labelMMName->setText(QApplication::translate("OperateWindow", "\345\247\223         \345\220\215", nullptr));
        btnFilterQueryMarkManage->setText(QApplication::translate("OperateWindow", " \347\255\233 \351\200\211 \346\237\245 \350\257\242", nullptr));
        btnMarkManageImport->setText(QApplication::translate("OperateWindow", "Excel\345\257\274\345\205\245\345\255\246\345\221\230\346\210\220\347\273\251", nullptr));
        btnMarkManageImportDB->setText(QApplication::translate("OperateWindow", "\345\210\227\350\241\250\345\257\274\345\205\245\346\225\260\346\215\256\345\272\223", nullptr));
        btnClearListMarkManage->setText(QApplication::translate("OperateWindow", " \346\270\205\347\251\272\345\210\227\350\241\250", nullptr));
        btnNameIDQueryMarkManage->setText(QApplication::translate("OperateWindow", "\346\214\211\345\247\223\345\220\215\345\255\246\345\217\267\346\237\245\350\257\242", nullptr));
        twOperate->setTabText(twOperate->indexOf(tabMarkManage), QApplication::translate("OperateWindow", "\350\200\203\346\240\270\346\210\220\347\273\251\347\256\241\347\220\206", nullptr));
        btnQuery->setText(QApplication::translate("OperateWindow", "\346\214\211\345\247\223\345\220\215\345\255\246\345\217\267\346\237\245\350\257\242", nullptr));
        labelName->setText(QApplication::translate("OperateWindow", "\345\247\223         \345\220\215", nullptr));
        labelID->setText(QApplication::translate("OperateWindow", "\345\255\246         \345\217\267", nullptr));
        labelIGrade->setText(QApplication::translate("OperateWindow", "\345\271\264         \347\272\247", nullptr));
        labelIPro->setText(QApplication::translate("OperateWindow", "\344\270\223         \344\270\232", nullptr));
        btnQueryByGS->setText(QApplication::translate("OperateWindow", "\346\214\211\344\270\223\344\270\232\345\271\264\347\272\247\346\237\245\350\257\242", nullptr));
        btnImport->setText(QApplication::translate("OperateWindow", "Excel\345\257\274\345\205\245\345\255\246\345\221\230\344\277\241\346\201\257", nullptr));
        btnInputDB->setText(QApplication::translate("OperateWindow", "\345\210\227\350\241\250\345\257\274\345\205\245\346\225\260\346\215\256\345\272\223", nullptr));
        btnClearList->setText(QApplication::translate("OperateWindow", " \346\270\205\347\251\272\345\210\227\350\241\250", nullptr));
        twOperate->setTabText(twOperate->indexOf(tabStuInfo), QApplication::translate("OperateWindow", "\345\255\246\345\221\230\344\277\241\346\201\257\347\256\241\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OperateWindow: public Ui_OperateWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPERATEWINDOW_H
