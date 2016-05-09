#include <QToolButton>
#include <QPropertyAnimation>
#include <QTimer>
#include <QPalette>
#include <QBitmap>
#include <QFile>
#include <QDataStream>
#include <QDebug>
#include <QCryptographicHash>

#include <iostream>
#include <string>
#include <map>
#include <QString>

#include "login.h"
#include "ui_login.h"

#include "init.h"
#include "global.h"
#include "mainwindow.h"
#include "deliverwindow.h"
#include "bosswindow.h"

/********************************************************************
	created:	2013/12/13 11:34
	filename:	C:\Users\hp\Desktop\CFK\CFK2\login.cpp
	file path:	C:\Users\hp\Desktop\CFK\CFK2
	file base:	login
	file ext:	cpp
	author:	 	Bianx
	version:	1.0.0
	purpose:	登录窗口文件
*********************************************************************/

using namespace std;
int reset_flag;//重置标记

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    #pragma region 窗口初始化
	ui->Editline_Password->setEchoMode(QLineEdit::Password);
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(700);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->start();
    //界面动画，改变透明度的方式出现0 - 1渐变
    //设置窗体标题栏隐藏并设置位于顶层
    QPalette palette;
    setWindowOpacity(1);
    QPixmap pixmap("image/dialogBG.png");
    palette.setBrush(ui->Under->backgroundRole(),QBrush(pixmap));
    ui->Under->setPalette(palette);
    ui->Under->setMask(pixmap.mask());  //可以将图片中透明部分显示为透明的
    ui->Under->setAutoFillBackground(true);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    //构建最小化、最大化、关闭按钮
    QToolButton *minButton = new QToolButton(this);
    QToolButton *closeButton= new QToolButton(this);
    connect (minButton,SIGNAL(clicked()),this,SLOT(showMinimized()));
    connect (closeButton,SIGNAL(clicked()),this,SLOT(wind_close()));
    //获取最小化、关闭按钮图标
    QPixmap minPix  = style()->standardPixmap(QStyle::SP_TitleBarMinButton);
    QPixmap closePix = style()->standardPixmap(QStyle::SP_TitleBarCloseButton);
    //设置最小化、关闭按钮图标
    minButton->setIcon(minPix);
    closeButton->setIcon(closePix);
    //设置最小化、关闭按钮在界面的位置
    minButton->setGeometry(410-46,100,20,20);
    closeButton->setGeometry(410-25,100,20,20);
    //设置鼠标移至按钮上的提示信息
    minButton->setToolTip(tr("最小化"));
    closeButton->setToolTip(tr("关闭"));
    //设置最小化、关闭按钮的样式
    minButton->setStyleSheet("background-color:transparent;");
    closeButton->setStyleSheet("background-color:transparent;");
#pragma endregion 窗口初始化
    reset_flag = 0;

    ui -> Frame_error ->hide();
}

Login::~Login()
{
    delete ui;
}


/************************************
Method:    on_Pushbutton_Login_clicked
FullName:  Login::on_Pushbutton_Login_clicked
Author:		Bianx
Access:    private 
Returns:   void
Qualifier:
Created Time:	  	2013/12/13 11:37
Last Change:  		2013/12/13 11:37
version:	1.0.0
Description:登录	操作
Remark:			
*************************************/
void Login::on_Pushbutton_Login_clicked()
{
    int flag;
    customerwindow *temp;
    deliverwindow *temp2;
    bossWindow *temp3;
    flag = User_check(ui->Editline_Username->text(),ui->Editline_Password->text());//用户名密码判断
	/*返回结构1是用户，-1是送餐员，0是错误*/
    switch(flag)
    {
    case 1:
        temp = new customerwindow;
        temp->show();
        this->close();
        break;
    case -1:
        temp2 = new deliverwindow;
        temp2->show();
        this->close();
        break;
    case -2:
        temp3 = new bossWindow;
        temp3->show();
        this->close();
        break;
    case 0:
        ui -> Frame_error -> show ();
        ui -> Editline_Password -> clear();  // 清空密码输入框
        ui -> Editline_Password -> setFocus();   //将光标转到用户名输入框
        break;
    /*case code_err:
        ui->frame_y1->show ();
        ui->frame_n2->show ();
        ui -> PassLine -> clear();  // 清空密码输入框
        ui -> PassLine -> setFocus();   //将光标转到用户名输入框
        break;
    case name_emp:
        ui->frame_n1->show ();

        ui -> UserLine -> setFocus();   //将光标转到用户名输入框
        break;
    case code_emp:
        ui->frame_n2->show ();

        ui -> PassLine -> setFocus();   //将光标转到密码输入框
        break;
    default:

        ui -> UserLine -> clear();  // 清空用户名输入框
        ui -> PassLine -> clear();  // 清空密码输入框
        ui -> PassLine -> setFocus();   //将光标转到用户名输入框
        break;*/
    }
    QTimer::singleShot (2500,this,SLOT(hideerror()));//错误提示框架3sec隐藏
}
/************************************
Method:    wind_close
FullName:  Login::wind_close
Author:		Bianx
Access:    private 
Returns:   void
Qualifier:
Created Time:	  	2013/12/13 11:39
Last Change:  		2013/12/13 11:39
version:	1.0.0
Description:关闭	窗口操作
Remark:	关闭窗口同时要将内存的东西写入文件
*************************************/
void Login::wind_close()
{
	/*写入文件*/
    QFile filedcz("dcz.dat");
    QFile filescy("scy.dat");
    QFile fileord("ord.dat");

#pragma region 点餐者
    filedcz.open(QIODevice::WriteOnly);//只写
    QDataStream stream(&filedcz);//输入流
    stream << (quint32)0xB0E4D0B3;//签名
    stream << (qint32)101;//版本
    stream.setVersion(QDataStream::Qt_4_0);//写入版本

    int size;
    size = all_DCZ.size();
    stream << size;
    for (int i = 0; i < size;i++)
    {
        stream << all_DCZ[i];//写入流每个点餐者
    }
    filedcz.close();//关闭文件写入流
#pragma endregion 点餐者

#pragma region 送餐员
	filescy.open(QIODevice::WriteOnly);
    QDataStream stream1(&filescy);
    stream1 << (quint32)0xB0E4D0B3;
    stream1 << (qint32)101;
    stream1.setVersion(QDataStream::Qt_4_0);

    size = all_SCY.size();
    stream1 << size;
    for (int i = 0; i < size;i++)
    {
        stream1 << all_SCY[i];
    }
    filescy.close();
#pragma endregion 送餐员

#pragma region 订单
    fileord.open(QIODevice::WriteOnly);
    QDataStream stream2(&fileord);
    stream2 <<  (quint32)0xB0E4D0B3;
    stream2 << (qint32)101;
    stream2.setVersion(QDataStream::Qt_4_0);

    size = all_orders.size();
    stream2 << size;
    for (int i = 0; i < size;i++)
    {
        stream2 << all_orders[i];
    }
    fileord.close();
#pragma endregion 订单

    this->close();//最后关闭窗口
}

void Login::hideerror ()
{

    ui->Frame_error->hide ();
}

void Login::on_Editline_Username_editingFinished()
{
    ui -> Editline_Password -> setFocus();
}

void Login::on_Editline_Password_editingFinished()
{
//   ui->Pushbutton_Login->setFocus();
}

/************************************
Method:    on_pushButton_clicked
FullName:  Login::on_pushButton_clicked
Author:		Bianx
Access:    private 
Returns:   void
Qualifier:
Created Time:	  	2013/12/13 15:41
Last Change:  		2013/12/13 15:41
version:	1.0.0
Description:系统	重置，在登陆框 右眼猛击10下会重置系统
Remark:			
*************************************/
void Login::on_pushButton_clicked()
{
    reset_flag++;
    if (reset_flag == 10)
    {
		reset_flag = 0;//重置标志计数器置零
        file_init(1);//以重置方式,写入文件
        ui -> Frame_error -> show ();//重置提示
        QTimer::singleShot (2500,this,SLOT(hideerror()));
    }
}
/************************************
Method:    User_check
FullName:  Login::User_check
Author:		Bianx
Access:    public 
Returns:   int
Qualifier:
Parameter: QString username
Parameter: QString password
Created Time:	  	2013/12/13 15:43
Last Change:  		2013/12/13 15:43
version:	1.0.0
Description:用户名密码检测	
Remark:			
*************************************/
int Login::User_check (QString username,QString password)
{
    QString md5;//临时存放16进制输入串
    QString input;//输入串(密码与用户名拼接)
    QString result;//存放输入串的MD5加密串
    input = username+password;
    QByteArray bb;
    bb = QCryptographicHash::hash ( input.toAscii(), QCryptographicHash::Md5 );
    result = md5.append(bb.toHex());//加密串
    qDebug()<<result;
	/*先检测是否是送餐员*/
    for (int i = 0;i<all_SCY.size();i++)
    {
        if (result == all_SCY[i].show_password())
        {
			//查找成功,是送餐员
            active_scy = i;//登录
            return -1;//返回
            if (active_scy == 0)//boss
            {
                return -2;
            }
        }
    }
	/*如果不是就检测是否是用户*/
    for (int i = 0;i<all_DCZ.size();i++)
    {
        if (result == all_DCZ[i].show_password())
        {
			//是订餐者
            active_dcz = i;//登录
            return 1;
        }
    }
    return 0;//没找到
}
