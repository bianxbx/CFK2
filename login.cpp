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
	purpose:	��¼�����ļ�
*********************************************************************/

using namespace std;
int reset_flag;//���ñ��

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    #pragma region ���ڳ�ʼ��
	ui->Editline_Password->setEchoMode(QLineEdit::Password);
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(700);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->start();
    //���涯�����ı�͸���ȵķ�ʽ����0 - 1����
    //���ô�����������ز�����λ�ڶ���
    QPalette palette;
    setWindowOpacity(1);
    QPixmap pixmap("image/dialogBG.png");
    palette.setBrush(ui->Under->backgroundRole(),QBrush(pixmap));
    ui->Under->setPalette(palette);
    ui->Under->setMask(pixmap.mask());  //���Խ�ͼƬ��͸��������ʾΪ͸����
    ui->Under->setAutoFillBackground(true);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    //������С������󻯡��رհ�ť
    QToolButton *minButton = new QToolButton(this);
    QToolButton *closeButton= new QToolButton(this);
    connect (minButton,SIGNAL(clicked()),this,SLOT(showMinimized()));
    connect (closeButton,SIGNAL(clicked()),this,SLOT(wind_close()));
    //��ȡ��С�����رհ�ťͼ��
    QPixmap minPix  = style()->standardPixmap(QStyle::SP_TitleBarMinButton);
    QPixmap closePix = style()->standardPixmap(QStyle::SP_TitleBarCloseButton);
    //������С�����رհ�ťͼ��
    minButton->setIcon(minPix);
    closeButton->setIcon(closePix);
    //������С�����رհ�ť�ڽ����λ��
    minButton->setGeometry(410-46,100,20,20);
    closeButton->setGeometry(410-25,100,20,20);
    //�������������ť�ϵ���ʾ��Ϣ
    minButton->setToolTip(tr("��С��"));
    closeButton->setToolTip(tr("�ر�"));
    //������С�����رհ�ť����ʽ
    minButton->setStyleSheet("background-color:transparent;");
    closeButton->setStyleSheet("background-color:transparent;");
#pragma endregion ���ڳ�ʼ��
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
Description:��¼	����
Remark:			
*************************************/
void Login::on_Pushbutton_Login_clicked()
{
    int flag;
    customerwindow *temp;
    deliverwindow *temp2;
    bossWindow *temp3;
    flag = User_check(ui->Editline_Username->text(),ui->Editline_Password->text());//�û��������ж�
	/*���ؽṹ1���û���-1���Ͳ�Ա��0�Ǵ���*/
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
        ui -> Editline_Password -> clear();  // ������������
        ui -> Editline_Password -> setFocus();   //�����ת���û��������
        break;
    /*case code_err:
        ui->frame_y1->show ();
        ui->frame_n2->show ();
        ui -> PassLine -> clear();  // ������������
        ui -> PassLine -> setFocus();   //�����ת���û��������
        break;
    case name_emp:
        ui->frame_n1->show ();

        ui -> UserLine -> setFocus();   //�����ת���û��������
        break;
    case code_emp:
        ui->frame_n2->show ();

        ui -> PassLine -> setFocus();   //�����ת�����������
        break;
    default:

        ui -> UserLine -> clear();  // ����û��������
        ui -> PassLine -> clear();  // ������������
        ui -> PassLine -> setFocus();   //�����ת���û��������
        break;*/
    }
    QTimer::singleShot (2500,this,SLOT(hideerror()));//������ʾ���3sec����
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
Description:�ر�	���ڲ���
Remark:	�رմ���ͬʱҪ���ڴ�Ķ���д���ļ�
*************************************/
void Login::wind_close()
{
	/*д���ļ�*/
    QFile filedcz("dcz.dat");
    QFile filescy("scy.dat");
    QFile fileord("ord.dat");

#pragma region �����
    filedcz.open(QIODevice::WriteOnly);//ֻд
    QDataStream stream(&filedcz);//������
    stream << (quint32)0xB0E4D0B3;//ǩ��
    stream << (qint32)101;//�汾
    stream.setVersion(QDataStream::Qt_4_0);//д��汾

    int size;
    size = all_DCZ.size();
    stream << size;
    for (int i = 0; i < size;i++)
    {
        stream << all_DCZ[i];//д����ÿ�������
    }
    filedcz.close();//�ر��ļ�д����
#pragma endregion �����

#pragma region �Ͳ�Ա
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
#pragma endregion �Ͳ�Ա

#pragma region ����
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
#pragma endregion ����

    this->close();//���رմ���
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
Description:ϵͳ	���ã��ڵ�½�� �����ͻ�10�»�����ϵͳ
Remark:			
*************************************/
void Login::on_pushButton_clicked()
{
    reset_flag++;
    if (reset_flag == 10)
    {
		reset_flag = 0;//���ñ�־����������
        file_init(1);//�����÷�ʽ,д���ļ�
        ui -> Frame_error -> show ();//������ʾ
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
Description:�û���������	
Remark:			
*************************************/
int Login::User_check (QString username,QString password)
{
    QString md5;//��ʱ���16�������봮
    QString input;//���봮(�������û���ƴ��)
    QString result;//������봮��MD5���ܴ�
    input = username+password;
    QByteArray bb;
    bb = QCryptographicHash::hash ( input.toAscii(), QCryptographicHash::Md5 );
    result = md5.append(bb.toHex());//���ܴ�
    qDebug()<<result;
	/*�ȼ���Ƿ����Ͳ�Ա*/
    for (int i = 0;i<all_SCY.size();i++)
    {
        if (result == all_SCY[i].show_password())
        {
			//���ҳɹ�,���Ͳ�Ա
            active_scy = i;//��¼
            return -1;//����
            if (active_scy == 0)//boss
            {
                return -2;
            }
        }
    }
	/*������Ǿͼ���Ƿ����û�*/
    for (int i = 0;i<all_DCZ.size();i++)
    {
        if (result == all_DCZ[i].show_password())
        {
			//�Ƕ�����
            active_dcz = i;//��¼
            return 1;
        }
    }
    return 0;//û�ҵ�
}
