#ifndef OPERATEWINDOW_H
#define OPERATEWINDOW_H

#include <QMainWindow>
#include "sqlite3.h"
#include "./ThirdParty/xlsx/xlsxdocument.h"

namespace Ui { class OperateWindow; }

class OperateWindow : public QMainWindow
{
    Q_OBJECT

public:
    QString strTabStuInfoFileName;
public:
    QString GetXlsxName(QString filePath);
    void DataBase_StuInfo_Insert(sqlite3 *db, QList<QString> strlistTemp);
    void DataBase_StuInfo_Query(sqlite3 *db, QList<QString> strlistTemp);
    void InitStuInfoComboBox();
    void QueryByGS(QString strQueryCmd);
    void DB_Exercise_Operate(QString strTableName , QString strCmd);
    QStringList DB_Query_InitMarkManage(QString strQueryCmd);
    void QueryMarkBySomeCondition(QString strQueryCommonCmd,QString strQueryCmd,QString strExerciseOpt);
public:
    explicit OperateWindow(QWidget *parent = nullptr);
    ~OperateWindow();
signals:

private slots:
    void on_btnImport_clicked();
    void on_btnInputDB_clicked();
    void on_btnClearList_clicked();
    void on_btnQuery_clicked();

    //void on_comboBoxGrade_currentIndexChanged(int index);

    void on_btnQueryByGS_clicked();

    void on_btnMarkManageImport_clicked();

    void on_btnClearListMarkManage_clicked();

    void on_btnMarkManageImportDB_clicked();

    void on_cbxExerciseOption_currentIndexChanged(const QString &arg1);

    void on_btnFilterQueryMarkManage_clicked();

    void on_btnNameIDQueryMarkManage_clicked();

private:
    Ui::OperateWindow *ui;
};

#endif // OPERATEWINDOW_H
