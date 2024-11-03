/*
** EPITECH PROJECT, 20220210
** operatewindow
** File description: 该窗口作为操作主界面,使用QTabwidget控件,各功能分布在各界面,可直接进行切换.
** operatewindow
** uic cmd:uic -o ui_operatewindow.h operatewindow.ui
** NOTE:数据库的表中各项不能以数字作为开头
*/

#include "operatewindow.h"
#include "ui_operatewindow.h"
#include "qscreen.h"
#include <QIcon>
#include "QFileDialog"
#include "QDesktopServices"
#include "qdebug.h"
#include "QFileDialog"
#include "qstandarditemmodel.h"
#include "sqlite3.h"
#include "qsqldatabase.h"
#include "qsqlquery.h"
#include "qsqlerror.h"
#include "qsqlrecord.h"
#include "qmessagebox.h"

#include "common.h"

#define owScreenRatio 1
#define nStudent 200

std::map<QString, QString> mapExercise{{"基础练习二", "EXERCISE_2"}, {"基础练习三", "EXERCISE_3"}, {"基础练习四", "EXERCISE_4"}};

OperateWindow::OperateWindow(QWidget *parent) : QMainWindow(parent),
                                                ui(new Ui::OperateWindow)
{
    ui->setupUi(this);
    strTabStuInfoFileName = QString();

    /*QScreen *screen = QGuiApplication::primaryScreen();
    QRect mm = screen->availableGeometry();
    int screen_width = mm.width();
    int screen_heigth = mm.height();*/

    // QTabWidget *tabWidget = new QTabWidget(this);

    this->setFixedSize(1280, 800);
    ui->tvStuInfo->setFixedWidth(910);
    ui->twOperate->setGeometry(10, 10, 1280 - 20, 800 - 30);

    //    QIcon iconTab0(":/Resource/n1.png");
    //    QIcon iconTab1(":/Resource/n2.png");
    //    QIcon iconTab2(":/Resource/n5.png");
    //    QIcon iconTab3(":/Resource/n7.png");
    //    QIcon iconTab4(":/Resource/n8.png");

    //    ui->twOperate->setTabIcon(0, iconTab0);
    //    ui->twOperate->setTabIcon(1, iconTab1);
    //    ui->twOperate->setTabIcon(2, iconTab2);
    //    ui->twOperate->setTabIcon(3, iconTab3);
    //    ui->twOperate->setTabIcon(4, iconTab4);

    InitStuInfoComboBox();

    QStandardItemModel *stuinfo_model = new QStandardItemModel();
    stuinfo_model->setColumnCount(9);

    QStandardItemModel *markManager_model = new QStandardItemModel();
    markManager_model->setColumnCount(12);
    /**********************************
            两种不同的表头设置方法
    **********************************/
    QStringList strListStuInfoTitle, strListMarkTitle;
    strListStuInfoTitle << "序号"
                        << "学号"
                        << "姓名"
                        << "年级"
                        << "队别"
                        << "专业"
                        << "类别"
                        << "身份"
                        << "知识背景";
    strListMarkTitle << "学号"
                     << "姓名"
                     << "考核学年"
                     << "考核科目"
                     << "1"
                     << "2"
                     << "3"
                     << "4"
                     << "5"
                     << "6"
                     << "完成时间"
                     << "总成绩";

    stuinfo_model->setHorizontalHeaderLabels(strListStuInfoTitle);
    markManager_model->setHorizontalHeaderLabels(strListMarkTitle);

    ui->tvStuInfo->verticalHeader()->hide();
    ui->tvStuInfo->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tvStuInfo->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tvMarkManage->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tvMarkManage->verticalHeader()->hide();
    ui->tvMarkManage->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tvMarkManage->horizontalHeader()->setStretchLastSection(true);

    ui->tvStuInfo->setModel(stuinfo_model);
    ui->tvMarkManage->setModel(markManager_model);

    for (auto i = 4; i < 10; i++)
    {
        ui->tvMarkManage->setColumnWidth(i, 40);
    }
    ui->tvMarkManage->setColumnWidth(1, 70);
    ui->tvMarkManage->setColumnWidth(10, 85);
    ui->tvMarkManage->setColumnWidth(11, 70);

    /********************************************************************************/
    /*
    ** 20220214:以下为对QXlsx的读入读出保存进行测试.
    */
    /*QXlsx::Document xlsx;
    xlsx.write("A1","Hello");
    xlsx.saveAs("Test.xlsx");

    QXlsx::Document xlsx("20220214.xlsx");
    qDebug() << xlsx.read("A1").toString();*/
    /********************************************************************************/
}

void OperateWindow::InitStuInfoComboBox()
{
    QSqlDatabase db;
    QStringList strListGradeOpt, strListSubjectOpt, strListExerciseSubjectOpt;

    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        db = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        db = QSqlDatabase::addDatabase("QSQLITE");
    }

    db.setDatabaseName("TacticalControl");
    QSqlQuery query_Grade(db);
    QSqlQuery query_Subject(db);
    QSqlQuery query_ExerciseSubject(db);

    if (!db.open())
    {
        qDebug() << "打开失败!";
        return;
    }

    strListGradeOpt.clear();
    strListSubjectOpt.clear();
    strListExerciseSubjectOpt.clear();

    query_Grade.exec("SELECT DISTINCT GRADE FROM STUINFO");
    query_Subject.exec("SELECT DISTINCT SUBJECT FROM STUINFO");
    query_ExerciseSubject.exec("SELECT DISTINCT NAME FROM EXERCISE_SUBJECT");

    while (query_Grade.next())
    {
        if(query_Grade.value(0).toString() != NULL )
            strListGradeOpt << query_Grade.value(0).toString();
    }
    while (query_Subject.next())
    {
        if(query_Subject.value(0).toString() != NULL)
            strListSubjectOpt << query_Subject.value(0).toString();
    }
    while (query_ExerciseSubject.next())
    {
        if(query_ExerciseSubject.value(0).toString() != NULL)
            strListExerciseSubjectOpt << query_ExerciseSubject.value(0).toString();
    }

    ui->comboBoxGrade->addItems(strListGradeOpt);
    ui->comboBoxGrade->setCurrentIndex(-1);

    ui->comboBoxPro->addItems(strListSubjectOpt);
    ui->comboBoxPro->setCurrentIndex(-1);

    ui->cbxExerciseOption->addItems(strListExerciseSubjectOpt);
    ui->cbxExerciseOption->setCurrentIndex(0);

    db.close();
}

// 20220217获取文件名，以该文件名作为数据库的表名，规定学员信息的xlsx文件应以队别或教学班命名
QString OperateWindow::GetXlsxName(QString filePath)
{
    QString rstrResult = NULL;

    QFileInfo fileInfo(filePath);
    rstrResult = fileInfo.baseName();

    return rstrResult;
}

OperateWindow::~OperateWindow()
{
    delete ui;
}

// 20220215:打开学员信息xlsx文件，加载学员信息，并以班级名在数据库中建表，写入数据库
void OperateWindow::on_btnImport_clicked()
{
    QString strfilePath = QFileDialog::getOpenFileName(this, "打开", "./", "*");

    QXlsx::Document xlsx(strfilePath);

    strTabStuInfoFileName = GetXlsxName(strfilePath);

    int nColumn = 0;
    int nRow = 0;

    //: TODO:20220215确定xlsx的列数nRow
    for (int i = 1; i <= nStudent; i++)
    {
        QString strRow = "A" + QString::number(i);
        if (xlsx.read(strRow).toString() == NULL)
        {
            nRow = i - 1;
            break;
        }
    }

    //: TODO:20220215确定xlsx的行数nRow
    char chColumn[20] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T'};
    for (int i = 0; i < 20; i++)
    {
        QString strColumn = QString(chColumn[i]) + QString::number(1);
        if (xlsx.read(strColumn).toString() == NULL)
        {
            nColumn = i;
            break;
        }
    }

    on_btnClearList_clicked();

    QStandardItemModel *model = new QStandardItemModel();
    model->setRowCount(nRow);
    model->setColumnCount(nColumn);

    for (int i = 0; i < nColumn; i++)
    {
        QString strColumn = QString(chColumn[i]) + QString::number(1);
        model->setHeaderData(i, Qt::Horizontal, xlsx.read(strColumn).toString());
    }

    for (int i = 0; i < nRow; i++)
    {
        for (int j = 0; j < nColumn; j++)
        {
            model->setItem(i, j, new QStandardItem(xlsx.read(i + 2, j + 1).toString()));
        }
    }

    for (int i = 0; i < nRow; i++)
    {
        for (int j = 0; j < nColumn; j++)
        {
            model->item(i, j)->setTextAlignment(Qt::AlignCenter);
        }
    }

    ui->tvStuInfo->setModel(model);
    // 20220218当加载的学员信息xlsx表有效，且命名无误的情况下，使能导入数据库按钮
    //    if (strTabStuInfoFileName != NULL)
    //    {
    //        ui->btnInputDB->setEnabled(true);
    //    }
}
// 20220215:Function:当前已显示的学员信息导入数据库中
void OperateWindow::on_btnInputDB_clicked()
{
    /**************************************************************************/
    /* 20220208:打开数据库
    ** 1.在数据库中按照xlsx的文件名查找是否存在同名的表
    ** 2.有,则比对信息看是否需要更新
    ** 3.没有,则在数据库中插入该表*/
    /**************************************************************************/
    sqlite3 *db = NULL;
    int lenDb = sqlite3_open("TacticalControl", &db);

    if (lenDb)
    {
        qDebug() << "Cannot Open DB!";
        sqlite3_close(db);
        return;
    }
    else
    {
        // qDebug()<<"Open Pattern.db Successfully!";
    }

    /****************************************************************************/
    /****************************************************************************/
    // 20220218注：Sqlite数据库中的表在命名时如果以数字开头，需要使用[2020-3-9-5]把表名包含起来。
    /****************************************************************************/
    /****************************************************************************/

    /*QString strCommand = NULL;
    strCommand = "CREATE TABLE [" + strTabStuInfoFileName + "](ID         INT PRIMARY KEY NOT NULL,"\
                                                             "NAME        TEXT NOT NULL," \
                                                             "GRADE       TEXT NOT NULL," \
                                                             "DEPARTMENT  TEXT NOT NULL," \
                                                             "SUBJECT     TEXT NOT NULL," \
                                                             "ORIGIN      TEXT ,"\
                                                             "IDENTITY    TEXT ,"\
                                                             "KNOWBK      TEXT )";
    QByteArray baTemp = strCommand.toLatin1();
    CommandSQL = baTemp.data();*/

    int nRow = 0;
    int nColumn = 0;

    QAbstractItemModel *model = ui->tvStuInfo->model();
    nRow = model->rowCount() - 1;
    nColumn = model->columnCount();

    QList<QString> strlist_StuInfo;

    if (model->rowCount() <= 0)
    {
        // qDebug() << "Empty List";
    }
    else
    {
        for (int varRow = 0; varRow < nRow; varRow++)
        {
            strlist_StuInfo.clear();
            for (int varColumn = 0; varColumn < nColumn; varColumn++)
            {
                QModelIndex indexCur = ui->tvStuInfo->model()->index(varRow, varColumn);
                strlist_StuInfo << indexCur.data().toString();
            }

            DataBase_StuInfo_Insert(db, strlist_StuInfo);
        }
    }

    sqlite3_close(db);
}
/*
** 20220321: 在学员信息管理界面,可按照学号或姓名进行查找,查找结果在tableview中显示.
** 20220322:TODO:下一步展望,可以通过各种条件进行查询操作,从界面先选择查询条件,再代入
*/
void OperateWindow::DataBase_StuInfo_Query(sqlite3 *db, QList<QString> strlistTemp)
{
    int res = -1;
    int err = -1;

    sqlite3_stmt *stmt;
    char *chResult = new char[16];

    QList<QString> qlist_StuInfo, qlist_Pos, qlist_Temp;
    QList<QStandardItem *> listItem;
    QStandardItemModel *stuinfo_model = new QStandardItemModel();

    stuinfo_model = dynamic_cast<QStandardItemModel *>(ui->tvStuInfo->model());

    /*
    ** 20220322:以下是查询的两种方法
    */
    /*************************************************************************************************/
    //：方法1
    /*
    QString qstrCommand;
    char *CommandSQL = NULL;
    qstrCommand = "SELECT * FROM STUINFO where " + strlistTemp[0] + " ='" + strlistTemp[1] + "'";

    CommandSQL = qstr_to_char(qstrCommand);

    res = sqlite3_prepare_v2(db, CommandSQL, strlen(CommandSQL), &stmt, NULL);

    if(SQLITE_OK != res){
        err =  -1;
        goto out_free;
    }

    while(SQLITE_ROW == sqlite3_step(stmt)){
        if(NULL != sqlite3_column_text(stmt, strlistTemp[0] == "ID"? 0:1)){
                strcpy(chResult , (const char *)sqlite3_column_text(stmt,0));
                qDebug() << chResult;
        }
    }
    err =  0;
    */
    /*************************************************************************************************/
    /*************************************************************************************************/
    //：方法2
    res = sqlite3_prepare_v2(db, strlistTemp[0] == "ID" ? SELECT_STUDENT_MSG_BY_ID : SELECT_STUDENT_MSG_BY_NAME, -1, &stmt, NULL);

    if (SQLITE_OK != res)
    {
        err = -1;
        goto out_free;
    }

    res = sqlite3_bind_text(stmt, 1, (const char *)qstr_to_char(strlistTemp[1]), -1, SQLITE_STATIC);

    if (SQLITE_OK != res)
    {
        err = -1;
        goto out;
    }

    while (SQLITE_ROW == sqlite3_step(stmt))
    {
        if (NULL != sqlite3_column_text(stmt, strlistTemp[0] == "ID" ? 0 : 1))
        {
            for (auto i = 0; i < 8; i++)
            {
                strcpy(chResult, (const char *)sqlite3_column_text(stmt, i));
                qlist_StuInfo << QString(chResult);
            }
            qlist_StuInfo << "/";
        }
    }

    qlist_StuInfo.prepend("/");
    // stuinfo_model->setRowCount(qlist_StuInfo.count("/")+1);

    // 20220329：根据间隔符“/”对整个Qstring list进行预处理，排序插入编码
    for (int i = 0; i < qlist_StuInfo.size(); i++)
    {
        if (qlist_StuInfo[i] == "/")
        {
            qlist_Pos << QString::number(i + 1);
        }
    }

    for (int i = 0; i < qlist_Pos.size(); i++)
    {
        qlist_StuInfo.insert(qlist_Pos[i].toInt() + i, QString::number(i + 1));
    }
    qlist_StuInfo.removeLast();

    // 20220329：根据间隔符“/”对整个Qstring list进行预处理，重新获取整体学员信息间隔情况
    qlist_Pos.clear();
    for (int i = 0; i < qlist_StuInfo.size(); i++)
    {
        if (qlist_StuInfo[i] == "/")
        {
            qlist_Pos << QString::number(i + 1);
        }
    }
    //逐行插入查找到的列数据
    for (int i = 0; i < qlist_Pos.size() - 1; i++)
    {
        qlist_Temp.clear();
        listItem.clear();
        for (int j = qlist_Pos[i].toInt(); j < qlist_Pos[i + 1].toInt() - 1; j++)
        {
            qlist_Temp << qlist_StuInfo[j];
        }

        for (auto k = 0; k < qlist_Temp.size(); k++)
        {
            listItem << new QStandardItem(qlist_Temp[k]);
        }
        stuinfo_model->appendRow(listItem);
    }
    //设置单元格居中
    for (int i = 0; i < stuinfo_model->rowCount(); i++)
    {
        for (int j = 0; j < stuinfo_model->columnCount(); j++)
        {
            stuinfo_model->item(i, j)->setTextAlignment(Qt::AlignCenter);
        }
    }

    ui->tvStuInfo->setModel(stuinfo_model);
    err = 0;
    /*************************************************************************************************/
out_free:
    sqlite3_finalize(stmt);
out:
    if (err < 0)
    {
        qDebug() << sqlite3_errmsg(db);
    }
    delete[] chResult;
    return;
}
/*************************************************************************************************/
//Function: 将列表中的学员信息写入数据库中。
/*************************************************************************************************/
void OperateWindow::DataBase_StuInfo_Insert(sqlite3 *db, QList<QString> strlistTemp)
{
    int res;

    QString qstrCommand;

    char *CommandSQL = NULL;
    char *ErrMsg = NULL;

    qstrCommand = "INSERT INTO STUINFO(ID,NAME,GRADE,DEPARTMENT,SUBJECT,ORIGIN,IDENTITY,KNOWBK)"
                  "VALUES('" +
                  strlistTemp[1] + "','" + strlistTemp[2] + "','" + strlistTemp[3] + "','" + strlistTemp[4] + "','" + 
                  strlistTemp[5] + "','" + strlistTemp[6] + "','" + strlistTemp[7] + "','" + strlistTemp[8] + "');";

    CommandSQL = qstr_to_char(qstrCommand);

    res = sqlite3_exec(db, CommandSQL, NULL, NULL, &ErrMsg);

    if (res != SQLITE_OK)
    {
        fprintf(stderr, "SQL error:%s", ErrMsg);
        sqlite3_free(ErrMsg);
    }
    else
    {
        // qDebug() << "Successlly!";
    }
}
/*************************************************************************************************/
//Function:清空列表
/*************************************************************************************************/
void OperateWindow::on_btnClearList_clicked()
{
    QAbstractItemModel *model = ui->tvStuInfo->model();

    if (model->rowCount() > 0)
    {
        model->removeRows(0, model->rowCount());
    }
    else
        return;
}
/*************************************************************************************************
**Function：根据输入的学号和姓名进行查询
*************************************************************************************************/
void OperateWindow::on_btnQuery_clicked()
{

    QString strInputID = ui->textEditID->toPlainText();
    QString strInputName = ui->textEditName->toPlainText();

    // 20220316在此要对输入学号和姓名的合法性进行判断
    /*
    ** TODO:查询合法性判断常见算法
    */

    sqlite3 *db = NULL;
    int lenDb = sqlite3_open("TacticalControl", &db);

    if (lenDb)
    {
        qDebug() << "Cannot Open DB!";
        sqlite3_close(db);
        return;
    }
    else
    {
        // qDebug()<<"Open Pattern.db Successfully!";
    }

    /*
    ** TODO: 根据输入情况,判断是使用ID还是NAME进行查询,两者皆有,使用ID查询
    ** strlist_QueryBy[0]为ID或NAME,strlist_QueryBy[1]为输入的查询依据.
    */
    QList<QString> strlist_QueryBy;

    if (strInputID != NULL)
    {
        strlist_QueryBy << "ID" << strInputID;
    }
    else
    {
        strlist_QueryBy << "NAME" << strInputName;
    }

    on_btnClearList_clicked();
    DataBase_StuInfo_Query(db, strlist_QueryBy);

    sqlite3_close(db);
}
/*************************************************************************************************/
//Function:根据年级和专业进行学员信息查询
/*************************************************************************************************/
void OperateWindow::QueryByGS(QString strQueryCmd)
{
    int cnt = 0;
    QSqlDatabase db;
    QSqlQuery query;

    QList<QStandardItem *> listItem;
    QStandardItemModel *stuinfo_model = new QStandardItemModel();
    stuinfo_model = dynamic_cast<QStandardItemModel *>(ui->tvStuInfo->model());

    if (QSqlDatabase::contains("qt_sql_default_connection")){
        db = QSqlDatabase::database("qt_sql_default_connection");
    } else{
        db = QSqlDatabase::addDatabase("QSQLITE");
    }

    db.setDatabaseName("TacticalControl");

    if (!db.open())
    {
        qDebug() << "打开失败!";
        return;
    }
    // qDebug() << strQueryCmd;
    query.exec(strQueryCmd);

    on_btnClearList_clicked();

    while (query.next())
    {
        listItem.clear();
        listItem << new QStandardItem(QString::number(cnt + 1));
        for (auto j = 0; j < query.record().count(); j++)
        {
            listItem << new QStandardItem(query.value(j).toString());
        }
        stuinfo_model->appendRow(listItem);
    }

    for (int i = 0; i < stuinfo_model->rowCount(); i++)
    {
        for (int j = 0; j < stuinfo_model->columnCount(); j++)
        {
            stuinfo_model->item(i, j)->setTextAlignment(Qt::AlignCenter);
        }
    }

    ui->tvStuInfo->setModel(stuinfo_model);
    db.close();
}
/*************************************************************************************************/
//Function:根据年级专业进行查询的按键函数
/*************************************************************************************************/
void OperateWindow::on_btnQueryByGS_clicked()
{
    QString strCmd = NULL;
    QString strGrade = ui->comboBoxGrade->currentText();
    QString strSubject = ui->comboBoxPro->currentText();
    int flagGrade,flagSubject,Result;
    Result = flagGrade = flagSubject = 0;

    if(strGrade != NULL)
        flagGrade = 1;
    if(strSubject != NULL)
        flagSubject = 2;

    Result = flagGrade | flagSubject;

    switch (Result)
    {
        case 1:
            strCmd = "SELECT * FROM STUINFO where GRADE = '" + strGrade + "'";
            break;
        case 2:
            strCmd = "SELECT * FROM STUINFO where SUBJECT = '" + strSubject + "'";
            break;
        case 3:
            strCmd = "SELECT * FROM STUINFO where GRADE = '" + strGrade + "' and SUBJECT = '" + strSubject + "'";
            break;
        default:
            break;
    }

    if(strCmd == NULL)
        return;
        
    QueryByGS(strCmd);
}
/*************************************************************************************************
**  Function:通过Excel文档加载学员考核成绩信息
*************************************************************************************************/
void OperateWindow::on_btnMarkManageImport_clicked()
{
    QString strfilePath = QFileDialog::getOpenFileName(this, "打开", "./", "*");

    QXlsx::Document xlsx(strfilePath);

    strTabStuInfoFileName = GetXlsxName(strfilePath);

    int nColumn = 0;
    int nRow = 0;

    QList<QStandardItem *> listItem;

    QStandardItemModel *markManage_model = new QStandardItemModel();
    markManage_model = dynamic_cast<QStandardItemModel *>(ui->tvMarkManage->model());

    //: TODO:20220215确定xlsx的列数nRow
    for (int i = 1; i <= nStudent; i++)
    {
        QString strRow = "A" + QString::number(i);
        if (xlsx.read(strRow).toString() == NULL)
        {
            nRow = i;
            break;
        }
    }

    //: TODO:20220215确定xlsx的行数nRow
    char chColumn[20] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T'};
    for (int i = 0; i < 20; i++)
    {
        QString strColumn = QString(chColumn[i]) + QString::number(1);
        if (xlsx.read(strColumn).toString() == NULL)
        {
            nColumn = i;
            break;
        }
    }
    //将excel文档中的数据载入tableview
    on_btnClearListMarkManage_clicked();

    for (int i = 2; i < nRow; i++)
    {
        listItem.clear();

        for (auto j = 1; j <= nColumn; j++)
        {
            listItem << new QStandardItem(xlsx.read(i, j).toString());
        }
        markManage_model->appendRow(listItem);
    }
    //设置单元格居中
    for (auto i = 0; i < markManage_model->rowCount(); i++)
    {
        for (auto j = 0; j < markManage_model->columnCount(); j++)
        {
            markManage_model->item(i, j)->setTextAlignment(Qt::AlignCenter);
        }
    }

    ui->tvMarkManage->setModel(markManage_model);
}
/*************************************************************************************************
**  Function:清空学员考核成绩TableView
*************************************************************************************************/
void OperateWindow::on_btnClearListMarkManage_clicked()
{
    QAbstractItemModel *model = ui->tvMarkManage->model();

    if (model->rowCount() > 0)
    {
        model->removeRows(0, model->rowCount());
    }
    else
        return;
}
/*************************************************************************************************
**  Function:针对数据库中学员考核成绩表Exercise_x的相关操作。
*************************************************************************************************/
void OperateWindow::DB_Exercise_Operate(QString strTableName, QString strCmd)
{
    QSqlDatabase db;
    if (QSqlDatabase::contains("qt_sql_default_connection")){   
        db = QSqlDatabase::database("qt_sql_default_connection");
    }
    else {
        db = QSqlDatabase::addDatabase("QSQLITE");
    }
    //qDebug() << strCmd;
    db.setDatabaseName("TacticalControl");
    QSqlQuery query(db);

    if (!db.open())
    {
        qDebug() << "打开失败!";
        return;
    }

    if(!query.exec(strCmd))
        qDebug() << query.lastError();
         
    db.close();
}
/*************************************************************************************************
**  Function:将列表中的学员考核信息写入数据库中。
*************************************************************************************************/
void OperateWindow::on_btnMarkManageImportDB_clicked()
{
    // TODO:获取tableview当前控件中的列表信息。
    int nRow = 0;
    int nColumn = 0;
    QString strDBCmd = NULL;

    QAbstractItemModel *model = ui->tvMarkManage->model();
    nRow = model->rowCount();
    nColumn = model->columnCount();

    QList<QString> strlist_MarkManage;

    if (model->rowCount() <= 0)
        return;
    else
    {
        for (int varRow = 0; varRow < nRow; varRow++)
        {
            strlist_MarkManage.clear();
            for (int varColumn = 0; varColumn < nColumn; varColumn++)
            {
                QModelIndex indexCur = ui->tvMarkManage->model()->index(varRow, varColumn);
                strlist_MarkManage << indexCur.data().toString();
            }
            strDBCmd = "INSERT INTO " + mapExercise[strlist_MarkManage[3]] + "(ID,DATE,ITEM1,ITEM2,ITEM3,ITEM4,ITEM5,ITEM6,TIME,SUM)"
                        "VALUES('" +strlist_MarkManage[0] + "','" + strlist_MarkManage[2] + "','" + strlist_MarkManage[4] + "','" + 
                        strlist_MarkManage[5] + "','" + strlist_MarkManage[6] + "','" + strlist_MarkManage[7] + "','" + strlist_MarkManage[8] + "','" + 
                        strlist_MarkManage[9] + "','" + strlist_MarkManage[10] + "','" + strlist_MarkManage[11] + "');";
            
            DB_Exercise_Operate(mapExercise[strlist_MarkManage[3]], strDBCmd);
           
        }
    }
}
/*************************************************************************************************
**  Function:考核成绩管理查询条件删选下拉框初始化过程中在数据库中的查询操作。
*************************************************************************************************/
QStringList OperateWindow::DB_Query_InitMarkManage(QString strQueryCmd)
{
    QSqlDatabase db;
    QStringList strListResult;

    if (QSqlDatabase::contains("qt_sql_default_connection")){
        db = QSqlDatabase::database("qt_sql_default_connection");
    } else{
        db = QSqlDatabase::addDatabase("QSQLITE");
    }

    db.setDatabaseName("TacticalControl");
    QSqlQuery query(db);

    if (!db.open())
    {
        qDebug() << "打开失败!";
    }

    strListResult.clear();    

    query.exec(strQueryCmd);

    while (query.next())
    {
        if(query.value(0).toString() != NULL)
            strListResult << query.value(0).toString();
    }

    db.close();
    return strListResult;
}
/*************************************************************************************************
**  Function:学员考核成绩管理界面中考核科目下拉框点选函数，根据选择的科目在相对应的数据库表中进行下拉框内容的选取
*************************************************************************************************/
void OperateWindow::on_cbxExerciseOption_currentIndexChanged(const QString &arg1)
{
    QStringList strListGradeOpt, strListExamTimeOpt,strListCompanyOpt;

    QString strCurrentExercise = NULL;

    int CurrentExercise = ui->cbxExerciseOption->currentIndex();

    switch (CurrentExercise)
    {
        case 0:
            strCurrentExercise = "EXERCISE_2";
            break;
        case 1:
            strCurrentExercise = "EXERCISE_3";
            break;
        case 2:
            strCurrentExercise = "EXERCISE_4";
            break;
        default:
            break;
    }

    if (strCurrentExercise == NULL)
        return;

    strListGradeOpt.clear();
    strListExamTimeOpt.clear();
    strListCompanyOpt.clear();

    ui->cbxDate->clear();
    ui->cbxCompany->clear();
    ui->cbxGradeOption->clear();

    strListExamTimeOpt = DB_Query_InitMarkManage("SELECT DISTINCT DATE FROM " + strCurrentExercise);
    strListCompanyOpt = DB_Query_InitMarkManage("SELECT DISTINCT STUINFO.COMPANY FROM STUINFO," + strCurrentExercise + " where STUINFO.ID = " + strCurrentExercise + ".ID");
    strListGradeOpt = DB_Query_InitMarkManage("SELECT DISTINCT STUINFO.GRADE FROM STUINFO," + strCurrentExercise + " where STUINFO.ID = " + strCurrentExercise + ".ID");

    ui->cbxDate->addItems(strListExamTimeOpt);
    ui->cbxDate->setCurrentIndex(-1);

    ui->cbxCompany->addItems(strListCompanyOpt);
    ui->cbxCompany->setCurrentIndex(-1);

    ui->cbxGradeOption->addItems(strListGradeOpt);
    ui->cbxGradeOption->setCurrentIndex(-1);
}
/*************************************************************************************************/
//Function:可根据多重限定条件进行学员考核信息查询
/*************************************************************************************************/
void OperateWindow::QueryMarkBySomeCondition(QString strQueryCommonCmd,QString strQueryName,QString strExerciseOpt)
{
    QSqlDatabase db;
    QSqlQuery query,query_Name;
    QStringList strListTemp;
    QString strName = NULL;

    QList<QStandardItem *> listItem;
    QStandardItemModel *markManage_model = new QStandardItemModel();
    markManage_model = dynamic_cast<QStandardItemModel *>(ui->tvMarkManage->model());

    if (QSqlDatabase::contains("qt_sql_default_connection")){
        db = QSqlDatabase::database("qt_sql_default_connection");
    } else{
        db = QSqlDatabase::addDatabase("QSQLITE");
    }

    db.setDatabaseName("TacticalControl");

    if (!db.open())
    {
        qDebug() << "打开失败!";
        return;
    }

    query.exec(strQueryCommonCmd);
    //qDebug() << strQueryCommonCmd;

    on_btnClearListMarkManage_clicked();

    while (query.next())
    {
        strListTemp.clear();
        listItem.clear(); 
        /*************************************************************************/
        //Note：qtableview在获取到Model进行追加插入操作时，插入的column数需和原布局保持一致。
        /*************************************************************************/
        for (auto j = 0; j < markManage_model->columnCount(); j++)
        { 
            strListTemp << query.value(j).toString();                   
        }

        query_Name.exec(strQueryName + query.value(0).toString());
        while(query_Name.next())
        {
            strName = query_Name.value(0).toString();
        }
       
        strListTemp.insert(1,strName);
        strListTemp.insert(3,strExerciseOpt);
        //qDebug() << strListTemp;

        for (auto j = 0; j < markManage_model->columnCount(); j++)
        { 
            listItem << new QStandardItem(strListTemp[j]);                   
        }
               
        markManage_model->appendRow(listItem);
    }
    //Note:设置居中
    for (int i = 0; i < markManage_model->rowCount(); i++)
    {
        for (int j = 0; j < markManage_model->columnCount(); j++)
        {
            markManage_model->item(i, j)->setTextAlignment(Qt::AlignCenter);
        }
    }

    ui->tvMarkManage->setModel(markManage_model);
    db.close();
}
/*************************************************************************************************
**  Function:根据设置的相关过滤条件进行学员考核成绩查询操作。
*************************************************************************************************/
void OperateWindow::on_btnFilterQueryMarkManage_clicked()
{
    QString strQueryCmd,strQueryName;
    QString strExerciseTable = NULL;
    int FlagExercise , FlagDate , FlagGrade , FlagCompany , Result;
    strExerciseTable = mapExercise[ui->cbxExerciseOption->currentText()];

    Result = FlagExercise = FlagDate = FlagGrade = FlagCompany = 0;
    
    if(ui->cbxExerciseOption->currentText() != NULL)
        FlagExercise = 1;
    if(ui->cbxGradeOption->currentText() != NULL)
        FlagGrade    = 2;
    if(ui->cbxDate->currentText() != NULL)
        FlagDate     = 4;
    if(ui->cbxCompany->currentText() != NULL)
        FlagCompany  = 8;
    Result = FlagExercise | FlagGrade | FlagDate | FlagCompany;

    strQueryName =  "select NAME from STUINFO where STUINFO.ID = ";
     
    switch (Result)
    {
        case 1: 
            strQueryCmd = "select * from " + strExerciseTable;           
            break;
        case 3:
            strQueryCmd = "select * from " + strExerciseTable +",STUINFO where STUINFO.GRADE = '" + ui->cbxGradeOption->currentText() 
                          + "' and STUINFO.ID = " + strExerciseTable + ".ID";
            break;
        case 5:
            strQueryCmd = "select * from " + strExerciseTable + " where " + strExerciseTable + ".DATE = '" + ui->cbxDate->currentText() + "'";            
            break;
        case 7:
            strQueryCmd = "select * from " + strExerciseTable + ",STUINFO where STUINFO.GRADE = '" + ui->cbxGradeOption->currentText() + "' and " + 
                           strExerciseTable + ".DATE = '" + ui->cbxDate->currentText() + "' and STUINFO.ID = " + strExerciseTable + ".ID";
            break;
        case 9:
            strQueryCmd = "select * from " + strExerciseTable + ",STUINFO where STUINFO.ID = " + 
                           strExerciseTable + ".ID and STUINFO.COMPANY = '" + ui->cbxCompany->currentText() +"'";
            break;
        case 11:
            strQueryCmd = "select * from " + strExerciseTable + ",STUINFO where STUINFO.ID = " + strExerciseTable + ".ID and STUINFO.GRADE = '" + 
                          ui->cbxGradeOption->currentText() + "' and STUINFO.COMPANY = '" + ui->cbxCompany->currentText() +"'";
            break;       
        case 13:
            strQueryCmd = "select * from " + strExerciseTable + ",STUINFO where STUINFO.ID = " + strExerciseTable + ".ID and " + strExerciseTable + ".DATE = '" + 
                          ui->cbxDate->currentText() + "' and STUINFO.COMPANY = '" + ui->cbxCompany->currentText() +"'";
            break;       
        case 15:
            strQueryCmd = "select * from " + strExerciseTable + ",STUINFO where STUINFO.ID = " + strExerciseTable + ".ID and STUINFO.GRADE = '" + 
                          ui->cbxGradeOption->currentText() + "' and " + strExerciseTable + ".DATE = '" + 
                          ui->cbxDate->currentText() + "' and STUINFO.COMPANY = '" + ui->cbxCompany->currentText() +"'";
            break;       
        default:
            break;
    }
    
    QueryMarkBySomeCondition(strQueryCmd,strQueryName,ui->cbxExerciseOption->currentText());

}


void OperateWindow::on_btnNameIDQueryMarkManage_clicked()
{
    int FlagName,FlagID,Result;
    Result = FlagName = FlagID = 0;
    QString strQueryCmd;
    QString strQueryName =  "select NAME from STUINFO where STUINFO.ID = ";
    
    QString strExerciseTable = mapExercise[ui->cbxExerciseOption->currentText()];;
    QString strName = ui->textEditMMName->toPlainText();
    QString strID = ui->textEditMMID->toPlainText();
    
    if(ui->textEditMMID->toPlainText() != NULL)
        FlagID = 1;
    if(ui->textEditMMName->toPlainText() != NULL)
        FlagName = 2;

    Result = FlagName | FlagID ;

    switch (Result)
    {
        case 0: 
            QMessageBox::warning(NULL, "提示", "请输入学员姓名或学号!", QMessageBox::Yes , QMessageBox::Yes);         
            break;
        case 1:
            strQueryCmd = "select * from " + strExerciseTable + " where " + strExerciseTable + ".ID = '" + strID + "'";
            break;
        case 2:
            strQueryCmd = "select * from " + strExerciseTable + ",STUINFO where " + strExerciseTable + ".ID = STUINFO.ID and STUINFO.NAME = '" + 
                           strName + "'";           
            break;
        case 3:
            strQueryCmd = "select * from " + strExerciseTable + " where " + strExerciseTable + ".ID = '" + strID + "'";
            break;      
        default:
            break;
    }

    QueryMarkBySomeCondition(strQueryCmd,strQueryName,ui->cbxExerciseOption->currentText());
}

