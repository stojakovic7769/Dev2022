/*
** EPITECH PROJECT, 2022.02.09
** Project: TacticalControl
** File description:
** author:CC
** mainwindow.c
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdebug.h"
#include "qscreen.h"
#include "sqlite3.h"
#include "qmessagebox.h"
#include "operatewindow.h"

#define debug_mode 1

#define ScreenRatio 1
char *UserName = NULL;
char *UserPwd = NULL;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /**********************************************************/
    /*
    **20210124：根据显示器的分辨率可按照设定的比例设置软件初始界面的大小并居中
    **注：在此获取到显示器的分辨率后，根据分辨率的大小加载不同分辨率的图片，使其可适应不同的屏幕
    */
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect mm = screen->availableGeometry();
    int screen_width = mm.width();
    int screen_heigth = mm.height();
    /*
    **TODO:判断屏幕分辨率，选取合适图片
    */
    // TODO... 2022.02.07
    this->setFixedSize(1280, 800);

    this->setWindowIcon(QIcon(":/Resource/Icon.jpg"));
    this->setWindowFlags(Qt::FramelessWindowHint);
    /*
    **20220208:增加一个退出按钮
    */
    QPushButton *btnQuit = new QPushButton(this);
    QPixmap pixmapBtnExit(":Resource/quit.png");
    QPixmap fitpixmap = pixmapBtnExit.scaled(40,40,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    btnQuit->setIcon(QIcon(fitpixmap));
    btnQuit->setIconSize(QSize(40,40));
    btnQuit->setStyleSheet("border:0");
    btnQuit->setGeometry(screen_width-40,0,40,40);

    connect(btnQuit,&QPushButton::clicked,this,&MainWindow::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*********************************************************************************/
/*
**20220208:测试用回调函数
*/
/*********************************************************************************/
// static int login_callback(void *data, int columnCount, char **columnValue, char **columnName)
// {
//     /*
//     fprintf(stderr,"%s: \n",(const char *)data);
//     qDebug()<< "columnCount = " << columnCount;
//     for(int i=0;i<columnCount;i++)
//     {
//         qDebug()<<columnValue[i];
//     }
//     */
//     qDebug() << "columnCount = " << columnCount;
//     if (columnCount == 0)
//     {
//         qDebug("Login failure!");
//         return 1;
//     }
//     else
//     {
//         qDebug("Login successfully");
//         return 0;
//     }
// }
/*********************************************************************************/

void MainWindow::on_btnLogin_clicked()
{
    /**************************************************************************/
    // 20220208:打开数据库
    /**************************************************************************/
    sqlite3 *db = NULL;
    int lenDb = sqlite3_open("TacticalControl", &db);

    if (lenDb)
    {
        qDebug() << "Cannot Open DB!";
        sqlite3_close(db);
    }
    else
    {
         //qDebug()<<"Open DB Successfully!";
    }

    char *CommandSQL = NULL;
    char **ResultSQL = NULL;
    char *ErrMsg = NULL;
    int nrow = 0;
    int ncolumn = 0;
    // const char *data = "Callback function called";

    /**************************************************************************/
    /*
        20220208:创建一个TABLE
    */
    /**************************************************************************/
    /*CommandSQL = "CREATE TABLE COMPANY("\
            "ID INT PRIMARY KEY NOT NULL," \
            "NAME TEXT NOT NULL," \
            "AGE INT NOT NULL," \
            "ADDRESS CHAR(50)," \
            "SALARY REAL );";

    rc = sqlite3_exec(db,CommandSQL,NULL,NULL,&ErrMsg);

    if(rc != SQLITE_OK)
    {
        fprintf(stderr,"SQL error: %s\n",ErrMsg);
        sqlite3_free(ErrMsg);
    }else
    {
        qDebug()<<"Create TABLE successfully";
    }*/
    /**************************************************************************/

    /**************************************************************************/
    /*
        20220208:利用回调函数查询TABLE
    */
    /**************************************************************************/
    /*rc = sqlite3_exec(db,CommandSQL,callback,(void *)data,&ErrMsg);

    if(rc != SQLITE_OK)
    {
        fprintf(stderr,"SQL error: %s\n",ErrMsg);
        sqlite3_free(ErrMsg);
    }else
    {
        qDebug()<<"Operation done successfully";
    }*/
    /**************************************************************************/

    /**************************************************************************/
    /*
      20220208:获取整个table,遍历输出所有元素.
      Qstring转char *的常见方法,借助QByteArray中转
    */
    /**************************************************************************/
    QString strName, strPwd, strCommand;
    strName = ui->lineEditName->text();
    strPwd = ui->lineEditPwd->text();

    strCommand = "SELECT * from USER where NAME = '" + strName + "'and PASSWORD = '" + strPwd + "'";
    QByteArray baTemp = strCommand.toUtf8();
    CommandSQL = baTemp.data();

    sqlite3_get_table(db, CommandSQL, &ResultSQL, &nrow, &ncolumn, &ErrMsg);

    // 20220209:输出查询结果
    /*qDebug() << nrow << ncolumn;

    for (auto i = 0; i < (nrow + 1) * ncolumn; i++)
    {
        qDebug("ResultSQL[%d] = %s", i, ResultSQL[i]);
    }*/
#ifdef debug_mode  
    OperateWindow *dlgoperatewindow = new OperateWindow(this);
    dlgoperatewindow->show();
#endif

    if (nrow != 0)
    {
        qDebug("Login successfully!");
        OperateWindow *dlgoperatewindow = new OperateWindow(this);
        dlgoperatewindow->show();
    }
    else
    {
#ifndef debug_mode
        qDebug("Login failure!");
        QMessageBox::warning(NULL,"Warning","用户名或密码错误!",QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
#endif
    }

    /**************************************************************************/
    /*
     *20220209:使用回调函数完成数据库查询,所有查询得到的数据通过回调函数来进行处理
     */
    /**************************************************************************/
    /*QString strName, strPwd, strCommand;
    strName = ui->lineEditName->text();
    strPwd = ui->lineEditPwd->text();
    strCommand = "SELECT * from USER where NAME = '" + strName + "'and PASSWORD = '" + strPwd + "'";
    QByteArray baTemp = strCommand.toUtf8();
    CommandSQL = baTemp.data();

    rc = sqlite3_exec(db, CommandSQL, login_callback, NULL, &ErrMsg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", ErrMsg);
        sqlite3_free(ErrMsg);
    }
    else
    {
        //qDebug()<<"Operation done successfully";
    }*/
    /**************************************************************************/

    sqlite3_free_table(ResultSQL);

    sqlite3_close(db);
}
