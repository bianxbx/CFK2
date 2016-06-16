/********************************************************************
	created:	2013/11/24 10:16
	filename:	C:\Users\hp\Desktop\CFK\CFK1\mainwindow.cpp
	file path:	C:\Users\hp\Desktop\CFK\CFK1
	file base:	mainwindow
	file ext:	cpp
	author:	 	Bianx
	version:	2.0.0
	purpose:	�û���ͽ���
*********************************************************************/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QPropertyAnimation>
#include <QTimer>
#include <QStringList>
#include <QStringListModel>
#include <QTableWidget>
#include <QColorGroup>
#include <QTableView>
#include <QStandardItemModel>
#include <QMap>
#include <QToolButton>
#include <QPropertyAnimation>
#include <QTime>
#include <QPalette>
#include <QBitmap>
#include <QDebug>

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "global.h"
#include "init.h"
#include "datastruct.h"
#include "login.h"

#include <QtTest/QtTest>
using namespace std;

QStandardItemModel *model_order_list = new QStandardItemModel();//��� tableview model
QStandardItemModel *model_menu = new QStandardItemModel();//�˵� tableview model
QMap<int,int> order_tmp;
int row_now;
int amount_tmp;
int window_flag;
int j;


QTimer timer;  // ��¼���ε���ļ��, ���С��100Ϊ˫���� ����150Ϊ����
QModelIndex index_tmp;

customerwindow::customerwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

#pragma region window initialize
	QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(700);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->start();
    //���涯�����ı�͸���ȵķ�ʽ����0 - 1����
    //���ô�����������ز�����λ�ڶ���
    QPalette palette;
    setWindowOpacity(1);
    QPixmap pixmap("image/uiBG.png");
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
    minButton->setGeometry(700-30,10,20,20);
    closeButton->setGeometry(700-8,10,20,20);
    //�������������ť�ϵ���ʾ��Ϣ
    minButton->setToolTip(tr("��С��"));
    closeButton->setToolTip(tr("�ر�"));
    //������С�����رհ�ť����ʽ
    minButton->setStyleSheet("background-color:transparent;");
    closeButton->setStyleSheet("background-color:transparent;");
    ui->label_username->setText("BBBB");
#pragma endregion window initialize

#pragma region ���ڿؼ���ʼ��
    int i;
    row_now = 0;
    amount_tmp = 0;
    window_flag = 1;
    ui->frame_user_view->hide();
    j = 0;
    ui->label_urgent->hide();
    ui->frame_detial ->hide ();
    ui->leftFrame->hide();
    set_view_to();

	/*�˵���ʼ��*/
    model_menu->setHorizontalHeaderItem(0,new QStandardItem(QObject::tr("Name")));//�б�����
    model_menu->setHorizontalHeaderItem(1,new QStandardItem(QObject::tr("Price")));
    model_menu->setHorizontalHeaderItem(2,new QStandardItem(QObject::tr("Rank")));
    ui->tableView_menu->setSelectionBehavior(QAbstractItemView::SelectRows);//���ѡ����
    ui->tableView_menu->setEditTriggers(QAbstractItemView::NoEditTriggers);//���ܱ༭
	/*����˵�������*/
    for (i = 0;i<all_food.size();i++)
    {
        model_menu->setItem(i, 0, new QStandardItem(all_food[i].show_food_name()));//�����Ʒ����
        model_menu->setItem(i, 1, new QStandardItem(QString::number(all_food[i].show_food_price(),10)));//�۸�
        model_menu->setItem(i, 2, new QStandardItem("������"));//����
    }
    ui->tableView_menu->setModel(model_menu);//��model��tableview����

    ui->tableView_menu->setColumnWidth(0,184);//�����п�
    ui->tableView_menu->setColumnWidth(1,86);
    ui->tableView_menu->setColumnWidth(2,86);

	/*������ʼ��*/
    model_order_list->setHorizontalHeaderItem(0,new QStandardItem(QObject::tr("Name")));
    model_order_list->setHorizontalHeaderItem(1,new QStandardItem(QObject::tr("Numer")));
    ui->tableView_Food_ordered->setModel(model_order_list);

    //model_order_list->setHorizontalHeaderItem(2,new QStandardItem(QObject::tr("Amount")));
    ui->tableView_Food_ordered->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_Food_ordered->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableView_Food_ordered->setColumnWidth(0,140);
    ui->tableView_Food_ordered->setColumnWidth(1,80);
    //ui->tableView_Food_ordered->setColumnWidth(2,80);

    ui->label_Fail->hide();//������ʾ��Ϣ(�µ�ʧ��)
    ui->label_succ->hide();//������ʾ��Ϣ(�µ��ɹ�)
    ui->label_chongzhi->hide();//���س�ֵ��ʾ

    ui->label_username->setText(all_DCZ[active_dcz].show_username());//��ʾ�û���(��Ҫ)
    ui->label_Usrname_check->setText(all_DCZ[active_dcz].show_username());//��ʾ�û���
    ui->label_address_check->setText(all_DCZ[active_dcz].show_address());//��ʾ�û���ַ
    ui->label_user_account->setText(QString::number(all_DCZ[active_dcz].show_account(),10));//��ʾ�û����

    QString state_tmp;
	/*��ʾ����״̬*/
    if (all_DCZ[active_dcz].order_id_list.size()!= 0)
    {
		//�ж���
        state_tmp = all_orders[all_DCZ[active_dcz].show_order(0)].show_state();//��ʱ����״̬����Ϊ����״̬
        ui->label_scyname->setText(all_SCY[all_orders[all_DCZ[active_dcz].order_id_list[0]].show_scy_id()].show_username());//��ʾ�Ͳ�Ա����
        ui->pushButton_order->hide();//�����µ���ť
        ui->pushButton_check->show();//��ʾ��ѯ��ť
        ui->lcdNumber_order_amount->display(all_orders[all_DCZ[active_dcz].order_id_list[0]].show_amount());//��ʾ�������
    }
    else
    {
		//�޶���
        ui->pushButton_check->hide();//���ز�ѯ��ť
        ui->pushButton_order->show();//��ʾ�µ���ť
        ui->label_scyname->setText("�޶���");//��ʾ����״̬
        ui->lcdNumber_order_amount->display(0);//��ʾ�������
        state_tmp = "�޶���";
    }
    ui->label_order_state->setText(state_tmp);//��ʾ����״̬
    timer = new QTimer(this);
    
#pragma endregion ���ڿؼ���ʼ��
	/*����źŵ�Ŀ����Ϊ������QT�в���ȷ�ĵ���˫���ź�*/
	connect(timer, SIGNAL(timeout()), this, SLOT(show_detial()));;//���ӳ�ʱ�ź����
}

customerwindow::~customerwindow()
{
    delete ui;
}
/************************************
Method:    leftShow
FullName:  customerwindow::leftShow
Author:		Bianx
Access:    public 
Returns:   void
Qualifier:
Created Time:	  	2013/11/24 11:17
Last Change:  		2013/11/24 11:17
version:	1.0.0
Description:	�������򶯻�
Remark:			
*************************************/
void customerwindow::leftShow()
{
	/*��������*/
    QPropertyAnimation *anim1=new QPropertyAnimation(ui->graphicsView_leftblock,"pos");
    anim1->setDuration(200);
    anim1->setStartValue(QPoint(-280, 0));
    anim1->setEndValue(QPoint(0, 0));
    anim1->start();
    ui->leftFrame->show ();
    QTimer::singleShot (200,this,SLOT(showview()));
}

void customerwindow::leftHide()
{
	/*������ʧ*/
    QPropertyAnimation *anim1=new QPropertyAnimation(ui->graphicsView_leftblock,"pos");
    anim1->setDuration(200);
    anim1->setStartValue(QPoint(0, 0));
    anim1->setEndValue(QPoint(-280, 0));
    anim1->start();
    //ui->frame_food_detil->hide();
    QTimer::singleShot (200,this,SLOT(hideview()));
    ui->frame_user_order->hide();
}

/************************************
Method:    wind_close
FullName:  customerwindow::wind_close
Author:		Bianx
Access:    private 
Returns:   void
Qualifier:
Created Time:	  	2013/11/24 11:17
Last Change:  		2013/11/24 11:17
version:	1.0.0
Description:�Զ���رմ��ڶ���	
Remark:			
*************************************/
void customerwindow::wind_close()
{
    Login *temp;
    temp = new Login;
    temp->show();
    this->close();
}

/************************************
Method:    on_tableView_menu_clicked
FullName:  customerwindow::on_tableView_menu_clicked
Author:		Bianx
Access:    private 
Returns:   void
Qualifier:
Parameter: const QModelIndex & index
Created Time:	  	2013/11/24 11:18
Last Change:  		2013/11/24 11:18
version:	1.0.0
Description:���ڵ���˫������ȷ,��д	
Remark:			
*************************************/
void customerwindow::on_tableView_menu_clicked(const QModelIndex &index)
{
	/*j�ǻ�������������*/
    if (j == 1)
    {
		//�ڶ����е������
        timer->start(3600000);//��ִ�е�������
        j = 0;
    }
    else
    {
		//��һ���е������
        timer->start (300);//��ʱ200MS,��ʱִ�е�������
        index_tmp = index;
        j = 1;
    }
}


/************************************
Method:    on_tableView_menu_doubleClicked
FullName:  customerwindow::on_tableView_menu_doubleClicked
Author:		Bianx
Access:    private 
Returns:   void
Qualifier:
Parameter: const QModelIndex & index
Created Time:	  	2013/11/24 11:18
Last Change:  		2013/11/24 11:18
version:	1.0.0
Description:�ڲ˵��ĵط�˫��.�Ӳ˽���	
Remark:			
*************************************/
void customerwindow::on_tableView_menu_doubleClicked(const QModelIndex &index)
{
    timer->start(3600000);
    if (all_DCZ[active_dcz].order_id_list.size() == 0)
    {
        int id_tmp;
        int order_row;
        int number_tmp;
        QList<QStandardItem *> tList;
        QStandardItem* tItem;
        QMap<int, int>::iterator it;
        
		id_tmp = index.row();//����кž���ʳ��ID��
        it = order_tmp.find(id_tmp);//����������,���Ƿ��Ѿ����
        amount_tmp += all_food[id_tmp].show_food_price();//�����ܽ��++
        ui->lcdNumber_order_amount->display(amount_tmp);//�����ʾ�ı�
        if (it != order_tmp.end())
        {
            //�����ӹ�
            number_tmp = it.value();
            it.value() = ++number_tmp;//����+1
            tList = model_order_list->findItems(all_food[id_tmp].show_food_name()) ;//�ڽ������ҵ�Ҫ���������Ĳ�
            tItem = tList.at(0);
            order_row = tItem->row();
            model_order_list->setItem(order_row, 1, new QStandardItem(QString::number(number_tmp,10)));//�ı���ֵ
        }
        else
        {
            //���û����ӹ�
            order_tmp.insert(id_tmp,1);//���
            model_order_list->setItem(row_now, 0, new QStandardItem(all_food[id_tmp].show_food_name()));//д�����
            model_order_list->setItem(row_now, 1, new QStandardItem("1"));//д������1
            row_now++;
        }
    }
}
/************************************
Method:    on_tableView_Food_ordered_doubleClicked
FullName:  customerwindow::on_tableView_Food_ordered_doubleClicked
Author:		Bianx
Access:    private 
Returns:   void
Qualifier:
Parameter: const QModelIndex & index
Created Time:	  	2013/11/24 11:33
Last Change:  		2013/11/24 11:33
version:	1.0.0
Description:	˫��ȥ���˵��еĲ�
Remark:			
*************************************/
void customerwindow::on_tableView_Food_ordered_doubleClicked(const QModelIndex &index)
{
    if (all_DCZ[active_dcz].order_id_list.size() == 0)
    {
        int id_tmp,order_row,number_tmp;
        QMap<int, int>::iterator it;

        it = order_tmp.begin();
        order_row = index.row();//����к� = ʳ����Order�е�λ��
        it += order_row;//������ָ�򶩵�Ҫȥ���Ĳ�Ʒ
        number_tmp = it.value();//��ʱ��¼�˵�����
        it.value() = --number_tmp;//��1
        id_tmp = it.key();
        amount_tmp -= all_food[id_tmp].show_food_price();//�ܽ�����
        if (number_tmp == 0)
        {
			/*�������Ϊ0,�Ƴ���һ��*/
            order_tmp.erase(it);//ɾ��Order��ָ����
            model_order_list->removeRow(order_row);//�ڽ�����ʾ
            row_now--;//������Ʒ������¼-1
        }
        else
        {
			/*���ûɾ��*/
            model_order_list->setItem(order_row, 1, new QStandardItem(QString::number(number_tmp,10)));//ֻ����-1
        }
        ui->lcdNumber_order_amount->display(amount_tmp);//��ʾ�ڽ���
    }
}

/************************************
Method:    on_pushButton_order_clicked
FullName:  customerwindow::on_pushButton_order_clicked
Author:		Bianx
Access:    private 
Returns:   void
Qualifier:
Created Time:	  	2013/11/24 11:50
Last Change:  		2013/11/24 11:50
version:	1.0.0
Description:�µ���ť��������	
Remark:			
*************************************/
void customerwindow::on_pushButton_order_clicked()
{
    QTime time;
    time= QTime::currentTime();
    qsrand(time.msec()+time.second()*1000);
    int randn=qrand()%(all_SCY.size()-1) + 1;//���ָ�ɿ��ö���Ա
	int scy_num = randn;    
    if (all_DCZ[active_dcz].show_account()>= amount_tmp&& amount_tmp != 0)
    {
		//��������������û����
        Order tmp(order_tmp,amount_tmp,all_DCZ[active_dcz].show_address(),active_dcz,scy_num);//���ɶ���
        all_orders.push_back(tmp);//�����Ͳ�Ա�����б�
        all_DCZ[active_dcz].pay(amount_tmp,all_orders.size()-1);//�û�֧��
        ui->pushButton_order->hide();//�����µ���ť
        ui->pushButton_check->show();//��ʾ��ѯ��ť
        ui->label_user_account->setText(QString::number(all_DCZ[active_dcz].show_account(),10));//��ʾ�û����
        ui->label_succ->show();//�µ��ɹ���ʾ
        ui->label_Fail->hide();//
        ui->label_order_state->setText(all_orders[all_DCZ[active_dcz].show_order(0)].show_state());//��ʾ����״̬
        ui->label_scyname->setText(all_SCY[scy_num].show_username());//��ʾ�Ͳ�Ա����
        all_SCY[scy_num].add_order_in_list(all_orders.size()-1);//�Ѳ˼����Ͳ�Ա�Ĵ����б�
    }
    else
    {
        ui->label_Fail->show();//�µ�ʧ����ʾ
    }
}

/************************************
Method:    on_pushButton_change_clicked
FullName:  customerwindow::on_pushButton_change_clicked
Author:		Bianx
Access:    private 
Returns:   void
Qualifier:
Created Time:	  	2013/11/24 12:24
Last Change:  		2013/11/24 12:24
version:	1.0.0
Description:ҳ���л�	
Remark:			
*************************************/
void customerwindow::on_pushButton_change_clicked()
{
    if (window_flag == 0)
    {
        window_flag = 1;
        ui->frame_user_view->hide();
        ui->frame_user_order->show();
    }
    else
    {
        window_flag = 0;
        ui->frame_user_order->hide();
        ui->frame_user_view->show();
    }
}

/************************************
Method:    on_pushButton_check_clicked
FullName:  customerwindow::on_pushButton_check_clicked
Author:		Bianx
Access:    private 
Returns:   void
Qualifier:
Created Time:	  	2013/12/13 16:14
Last Change:  		2013/12/13 16:14
version:	1.0.0
Description:��ѯ��ť���	
Remark:			
*************************************/
void customerwindow::on_pushButton_check_clicked()
{
    window_flag = 0;
    ui->frame_user_order->hide();
    ui->frame_user_view->show();
	/*ˢ��һ��������ʾ����*/
    set_view_to();
    ui->label_order_state->setText(all_orders[all_DCZ[active_dcz].show_order(0)].show_state());
    ui->lcdNumber_order_amount->display(all_orders[all_DCZ[active_dcz].show_order(0)].show_amount());
}
/************************************
Method:    set_view_to
FullName:  customerwindow::set_view_to
Author:		Bianx
Access:    public 
Returns:   void
Qualifier:
Created Time:	  	2013/11/24 12:25
Last Change:  		2013/11/24 12:25
version:	1.0.0
Description:	�����ѵ���б�
Remark:			
*************************************/
void customerwindow::set_view_to()
{
    qDebug() << "asdasdasd";
    int order_id_tmp;
    int food_id,food_num,j;
    QMap<int, int>::iterator it;

    if (all_DCZ[active_dcz].order_id_list.size() != 0)
    {
		//������ѵ㶩��
        ui->pushButton_urgent->show();
        order_id_tmp = all_DCZ[active_dcz].order_id_list[0];//
        if(all_orders[order_id_tmp].show_urgent() == true)
        {
            ui->label_urgent->show();
        }
        else
        {
            ui->label_urgent->hide();
        }
        it = all_orders[order_id_tmp].item.begin();
        for (j = 0;j<all_orders[order_id_tmp].item.size();j++)//��ÿ��ʳ������,�������
        {
            food_id = it.key();
            food_num = it.value();
//            model_order_list->setVerticalHeaderItem(j,new QStandardItem(QObject::tr("Name")));
//            model_order_list->setVerticalHeaderItem(j,new QStandardItem(QObject::tr("Number")));
            model_order_list->setItem(j, 0, new QStandardItem(all_food[food_id].show_food_name()));
            model_order_list->setItem(j, 1, new QStandardItem(QString::number(food_num,10)));
            it++;
        }
    }
    else
    {
		//���û��,���
        ui->pushButton_urgent->hide();
        model_order_list->setColumnCount(2);
        model_order_list->setRowCount(0);
    }
}


/************************************
Method:    show_detial
FullName:  customerwindow::show_detial
Author:		Bianx
Access:    private 
Returns:   void
Qualifier:
Created Time:	  	2013/11/24 12:27
Last Change:  		2013/11/24 12:27
version:	1.0.0
Description:	ʳ��ϸ��
Remark:			
*************************************/
void customerwindow::show_detial()
{
    j = 0;//������������
    timer->stop();//����ִ��,��ʱ��ֹͣ
    int id_tmp;
    id_tmp = index_tmp.row();//���������ǵڼ���
    ui->label_food_detial->setText(all_food[id_tmp].show_food_name());//��ʾʳ����

    QPropertyAnimation *anim1=new QPropertyAnimation(ui->graphicsView_leftblock,"pos");//����������ʾ
    anim1->setDuration(200);
    anim1->setStartValue(QPoint(-294, -2));
    anim1->setEndValue(QPoint(-3, -2));
    anim1->start();
    ui->pushButton->show();
    ui->leftFrame->show ();
    QTimer::singleShot (190,this,SLOT(showview()));
}
//ʳ��ϸ�ڴ�����ʧ
void customerwindow::on_pushButton_clicked()
{
    QPropertyAnimation *anim1=new QPropertyAnimation(ui->graphicsView_leftblock,"pos");
    anim1->setDuration(200);
    anim1->setStartValue(QPoint(-3, -2));
    anim1->setEndValue(QPoint(-294, -2));
    anim1->start();
    ui->pushButton->hide();
    ui->frame_detial->hide ();
    QTimer::singleShot (190,this,SLOT(hideview()));
}
void customerwindow::showview ()
{
    ui->frame_detial->show ();
}
void customerwindow::hideview ()
{
    ui->leftFrame->hide ();
}

/************************************
Method:    on_pushButton_chongzhi_clicked
FullName:  customerwindow::on_pushButton_chongzhi_clicked
Author:		Bianx
Access:    private 
Returns:   void
Qualifier:
Created Time:	  	2013/12/13 16:16
Last Change:  		2013/12/13 16:16
version:	1.0.0
Description:�û���ֵ	
Remark:			
*************************************/
void customerwindow::on_pushButton_chongzhi_clicked()
{
    QString message;
	/*��������ֵ���벻��8λ*/
    if (ui->lineEdit_chongzhi->text().length()==8)
    {
        bool ok;
        int input = ui->lineEdit_chongzhi->text().toInt(&ok,10);//���봮Qstring->int 10����
        int money;
		/*��֤������������Ϣ�ͽ��
		��11��ȡ����*/
        switch(input%11)
        {
        case 0:
            money = 10;
            all_DCZ[active_dcz].prepaid(money);
            break;
        case 1:
            money = 20;
            all_DCZ[active_dcz].prepaid(money);
            break;
        case 5:
            money = 50;
            all_DCZ[active_dcz].prepaid(money);
            break;
        case 8:
            money = 80;
            all_DCZ[active_dcz].prepaid(money);
            break;
        case 10:
            money = 100;
            all_DCZ[active_dcz].prepaid(money);
            break;
        default:
            money = -1;
            break;
        }

        if (money != -1)
        {
			//��ֵ�ɹ���ʾ��ֵ��Ϣ
            message = "��ֵ�ɹ�!!        ��ֵ��";
            message+=QString::number(money,10);
            message+="Ԫ";
        }
        else
        {
			//��ֵʧ�� ��ʾ��Ϣ
            message = "��ֵʧ�ܣ����������������ԣ�";
        }

    }
    else
    {//���볤�Ȳ���
        message = "��ֵʧ�ܣ������볤��Ϊ8λ�ĳ�ֵ�����룡";
    }
    ui->label_chongzhi->setText(message);//��ֵ��Ϣ��ʾ
    ui->label_chongzhi->show();
    ui->label_user_account->setText(QString::number(all_DCZ[active_dcz].show_account(),10));//�û����ˢ��
    ui->lineEdit_chongzhi->clear();//��������
}

void customerwindow::on_pushButton_cancel_clicked()
{
    int order_id = all_DCZ[active_dcz].show_order(0);
    int scy_id = all_orders[order_id].show_scy_id();
    if(all_orders[order_id].show_state() == "Waiting")
    {
        all_DCZ[active_dcz].finish_order();
        QVector <int>::iterator it;
        for( it = all_SCY[scy_id].deliver_list.begin();it!=all_SCY[scy_id].deliver_list.end();)
        {
            qDebug()<< all_SCY[scy_id].deliver_list.size();
            if(*it == order_id)
            {
                it=all_SCY[scy_id].deliver_list.erase(it);
            }
            else
            {
                ++it;
            }
        }
        order_tmp.clear();
        amount_tmp = 0;
        QString state_tmp;
        /*��ʾ����״̬*/
        if (all_DCZ[active_dcz].order_id_list.size()!= 0)
        {
            //�ж���
            state_tmp = all_orders[all_DCZ[active_dcz].show_order(0)].show_state();//��ʱ����״̬����Ϊ����״̬
            ui->label_scyname->setText(all_SCY[all_orders[all_DCZ[active_dcz].order_id_list[0]].show_scy_id()].show_username());//��ʾ�Ͳ�Ա����
            ui->pushButton_order->hide();//�����µ���ť
            ui->pushButton_check->show();//��ʾ��ѯ��ť
            ui->lcdNumber_order_amount->display(all_orders[all_DCZ[active_dcz].order_id_list[0]].show_amount());//��ʾ�������
        }
        else
        {
            //�޶���
            ui->pushButton_check->hide();//���ز�ѯ��ť
            ui->pushButton_order->show();//��ʾ�µ���ť
            ui->label_scyname->setText("�޶���");//��ʾ����״̬
            ui->lcdNumber_order_amount->display(0);//��ʾ�������
            state_tmp = "�޶���";
            ui->pushButton_urgent->hide();
        }
        ui->label_order_state->setText(state_tmp);//��ʾ����״̬
        set_view_to();

    }
    else if (all_orders[all_DCZ[active_dcz].show_order(0)].show_state() == "Delivering")
    {

    }
    else
    {

    }
}

void customerwindow::on_pushButton_urgent_clicked()
{
    all_orders[all_DCZ[active_dcz].show_order(0)].set_urgent();
    ui->label_urgent->show();
    QString state_tmp;
    /*��ʾ����״̬*/
    if (all_DCZ[active_dcz].order_id_list.size()!= 0)
    {
        //�ж���
        state_tmp = all_orders[all_DCZ[active_dcz].show_order(0)].show_state();//��ʱ����״̬����Ϊ����״̬
        ui->label_scyname->setText(all_SCY[all_orders[all_DCZ[active_dcz].order_id_list[0]].show_scy_id()].show_username());//��ʾ�Ͳ�Ա����
        ui->pushButton_order->hide();//�����µ���ť
        ui->pushButton_check->show();//��ʾ��ѯ��ť
        ui->lcdNumber_order_amount->display(all_orders[all_DCZ[active_dcz].order_id_list[0]].show_amount());//��ʾ�������
    }
    else
    {
        //�޶���
        ui->pushButton_check->hide();//���ز�ѯ��ť
        ui->pushButton_order->show();//��ʾ�µ���ť
        ui->label_scyname->setText("�޶���");//��ʾ����״̬
        ui->lcdNumber_order_amount->display(0);//��ʾ�������
        state_tmp = "�޶���";
    }
    ui->label_order_state->setText(state_tmp);//��ʾ����״̬
}
