/********************************************************************
	created:	2013/11/24 10:16
	filename:	C:\Users\hp\Desktop\CFK\CFK1\mainwindow.cpp
	file path:	C:\Users\hp\Desktop\CFK\CFK1
	file base:	mainwindow
	file ext:	cpp
	author:	 	Bianx
	version:	2.0.0
	purpose:	用户点餐界面
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

QStandardItemModel *model_order_list = new QStandardItemModel();//点餐 tableview model
QStandardItemModel *model_menu = new QStandardItemModel();//菜单 tableview model
QMap<int,int> order_tmp;
int row_now;
int amount_tmp;
int window_flag;
int j;


QTimer timer;  // 记录两次点击的间隔, 间隔小于100为双击， 超过150为单击
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
    //界面动画，改变透明度的方式出现0 - 1渐变
    //设置窗体标题栏隐藏并设置位于顶层
    QPalette palette;
    setWindowOpacity(1);
    QPixmap pixmap("image/uiBG.png");
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
    minButton->setGeometry(700-30,10,20,20);
    closeButton->setGeometry(700-8,10,20,20);
    //设置鼠标移至按钮上的提示信息
    minButton->setToolTip(tr("最小化"));
    closeButton->setToolTip(tr("关闭"));
    //设置最小化、关闭按钮的样式
    minButton->setStyleSheet("background-color:transparent;");
    closeButton->setStyleSheet("background-color:transparent;");
    ui->label_username->setText("BBBB");
#pragma endregion window initialize

#pragma region 窗口控件初始化
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

	/*菜单初始化*/
    model_menu->setHorizontalHeaderItem(0,new QStandardItem(QObject::tr("Name")));//行标设置
    model_menu->setHorizontalHeaderItem(1,new QStandardItem(QObject::tr("Price")));
    model_menu->setHorizontalHeaderItem(2,new QStandardItem(QObject::tr("Rank")));
    ui->tableView_menu->setSelectionBehavior(QAbstractItemView::SelectRows);//点击选中行
    ui->tableView_menu->setEditTriggers(QAbstractItemView::NoEditTriggers);//不能编辑
	/*输出菜单至界面*/
    for (i = 0;i<all_food.size();i++)
    {
        model_menu->setItem(i, 0, new QStandardItem(all_food[i].show_food_name()));//输出菜品名字
        model_menu->setItem(i, 1, new QStandardItem(QString::number(all_food[i].show_food_price(),10)));//价格
        model_menu->setItem(i, 2, new QStandardItem("★★★★★"));//评分
    }
    ui->tableView_menu->setModel(model_menu);//讲model与tableview关联

    ui->tableView_menu->setColumnWidth(0,184);//设置列宽
    ui->tableView_menu->setColumnWidth(1,86);
    ui->tableView_menu->setColumnWidth(2,86);

	/*订单初始化*/
    model_order_list->setHorizontalHeaderItem(0,new QStandardItem(QObject::tr("Name")));
    model_order_list->setHorizontalHeaderItem(1,new QStandardItem(QObject::tr("Numer")));
    ui->tableView_Food_ordered->setModel(model_order_list);

    //model_order_list->setHorizontalHeaderItem(2,new QStandardItem(QObject::tr("Amount")));
    ui->tableView_Food_ordered->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_Food_ordered->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableView_Food_ordered->setColumnWidth(0,140);
    ui->tableView_Food_ordered->setColumnWidth(1,80);
    //ui->tableView_Food_ordered->setColumnWidth(2,80);

    ui->label_Fail->hide();//隐藏提示信息(下单失败)
    ui->label_succ->hide();//隐藏提示信息(下单成功)
    ui->label_chongzhi->hide();//隐藏充值提示

    ui->label_username->setText(all_DCZ[active_dcz].show_username());//显示用户名(主要)
    ui->label_Usrname_check->setText(all_DCZ[active_dcz].show_username());//显示用户名
    ui->label_address_check->setText(all_DCZ[active_dcz].show_address());//显示用户地址
    ui->label_user_account->setText(QString::number(all_DCZ[active_dcz].show_account(),10));//显示用户余额

    QString state_tmp;
	/*显示订单状态*/
    if (all_DCZ[active_dcz].order_id_list.size()!= 0)
    {
		//有订单
        state_tmp = all_orders[all_DCZ[active_dcz].show_order(0)].show_state();//临时订单状态设置为订单状态
        ui->label_scyname->setText(all_SCY[all_orders[all_DCZ[active_dcz].order_id_list[0]].show_scy_id()].show_username());//显示送餐员名字
        ui->pushButton_order->hide();//隐藏下单按钮
        ui->pushButton_check->show();//显示查询按钮
        ui->lcdNumber_order_amount->display(all_orders[all_DCZ[active_dcz].order_id_list[0]].show_amount());//显示订单金额
    }
    else
    {
		//无订单
        ui->pushButton_check->hide();//隐藏查询按钮
        ui->pushButton_order->show();//显示下单按钮
        ui->label_scyname->setText("无订单");//显示订单状态
        ui->lcdNumber_order_amount->display(0);//显示订单金额
        state_tmp = "无订单";
    }
    ui->label_order_state->setText(state_tmp);//显示订单状态
    timer = new QTimer(this);
    
#pragma endregion 窗口控件初始化
	/*这个信号的目的是为了区分QT中不明确的单击双击信号*/
	connect(timer, SIGNAL(timeout()), this, SLOT(show_detial()));;//连接超时信号与槽
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
Description:	左部伸缩框动画
Remark:			
*************************************/
void customerwindow::leftShow()
{
	/*滑动出现*/
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
	/*滑动消失*/
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
Description:自定义关闭窗口动作	
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
Description:窗口单机双击不明确,自写	
Remark:			
*************************************/
void customerwindow::on_tableView_menu_clicked(const QModelIndex &index)
{
	/*j是击键动作计数器*/
    if (j == 1)
    {
		//第二次有点击动作
        timer->start(3600000);//不执行单击操作
        j = 0;
    }
    else
    {
		//第一次有点击动作
        timer->start (300);//延时200MS,超时执行单击操作
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
Description:在菜单的地方双击.加菜进单	
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
        
		id_tmp = index.row();//点击行号就是食物ID号
        it = order_tmp.find(id_tmp);//迭代器遍历,看是否已经点过
        amount_tmp += all_food[id_tmp].show_food_price();//订单总金额++
        ui->lcdNumber_order_amount->display(amount_tmp);//金额显示改变
        if (it != order_tmp.end())
        {
            //如果添加过
            number_tmp = it.value();
            it.value() = ++number_tmp;//数量+1
            tList = model_order_list->findItems(all_food[id_tmp].show_food_name()) ;//在界面上找到要增加数量的菜
            tItem = tList.at(0);
            order_row = tItem->row();
            model_order_list->setItem(order_row, 1, new QStandardItem(QString::number(number_tmp,10)));//改变数值
        }
        else
        {
            //如果没有添加过
            order_tmp.insert(id_tmp,1);//添加
            model_order_list->setItem(row_now, 0, new QStandardItem(all_food[id_tmp].show_food_name()));//写入菜名
            model_order_list->setItem(row_now, 1, new QStandardItem("1"));//写入数量1
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
Description:	双击去除菜单中的菜
Remark:			
*************************************/
void customerwindow::on_tableView_Food_ordered_doubleClicked(const QModelIndex &index)
{
    if (all_DCZ[active_dcz].order_id_list.size() == 0)
    {
        int id_tmp,order_row,number_tmp;
        QMap<int, int>::iterator it;

        it = order_tmp.begin();
        order_row = index.row();//点击行号 = 食物在Order中的位置
        it += order_row;//迭代器指向订单要去除的菜品
        number_tmp = it.value();//临时记录菜的数量
        it.value() = --number_tmp;//减1
        id_tmp = it.key();
        amount_tmp -= all_food[id_tmp].show_food_price();//总金额减少
        if (number_tmp == 0)
        {
			/*如果数量为0,移除这一行*/
            order_tmp.erase(it);//删除Order中指定行
            model_order_list->removeRow(order_row);//在界面显示
            row_now--;//订单菜品总量记录-1
        }
        else
        {
			/*如果没删光*/
            model_order_list->setItem(order_row, 1, new QStandardItem(QString::number(number_tmp,10)));//只数量-1
        }
        ui->lcdNumber_order_amount->display(amount_tmp);//显示在界面
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
Description:下单按钮点击后操作	
Remark:			
*************************************/
void customerwindow::on_pushButton_order_clicked()
{
    QTime time;
    time= QTime::currentTime();
    qsrand(time.msec()+time.second()*1000);
    int randn=qrand()%(all_SCY.size()-1) + 1;//随机指派可用订餐员
	int scy_num = randn;    
    if (all_DCZ[active_dcz].show_account()>= amount_tmp&& amount_tmp != 0)
    {
		//如果订单金额不大于用户余额
        Order tmp(order_tmp,amount_tmp,all_DCZ[active_dcz].show_address(),active_dcz,scy_num);//生成订单
        all_orders.push_back(tmp);//放入送餐员订单列表
        all_DCZ[active_dcz].pay(amount_tmp,all_orders.size()-1);//用户支付
        ui->pushButton_order->hide();//隐藏下单按钮
        ui->pushButton_check->show();//显示查询按钮
        ui->label_user_account->setText(QString::number(all_DCZ[active_dcz].show_account(),10));//显示用户余额
        ui->label_succ->show();//下单成功提示
        ui->label_Fail->hide();//
        ui->label_order_state->setText(all_orders[all_DCZ[active_dcz].show_order(0)].show_state());//显示订单状态
        ui->label_scyname->setText(all_SCY[scy_num].show_username());//显示送餐员名字
        all_SCY[scy_num].add_order_in_list(all_orders.size()-1);//把菜加入送餐员的待送列表
    }
    else
    {
        ui->label_Fail->show();//下单失败提示
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
Description:页面切换	
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
Description:查询按钮点击	
Remark:			
*************************************/
void customerwindow::on_pushButton_check_clicked()
{
    window_flag = 0;
    ui->frame_user_order->hide();
    ui->frame_user_view->show();
	/*刷新一遍数据显示出来*/
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
Description:	设置已点餐列表
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
		//如果有已点订单
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
        for (j = 0;j<all_orders[order_id_tmp].item.size();j++)//把每个食物名字,数量输出
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
		//如果没订,清空
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
Description:	食物细节
Remark:			
*************************************/
void customerwindow::show_detial()
{
    j = 0;//击键计数清零
    timer->stop();//单击执行,计时器停止
    int id_tmp;
    id_tmp = index_tmp.row();//传入点击的是第几行
    ui->label_food_detial->setText(all_food[id_tmp].show_food_name());//显示食物名

    QPropertyAnimation *anim1=new QPropertyAnimation(ui->graphicsView_leftblock,"pos");//从右向左显示
    anim1->setDuration(200);
    anim1->setStartValue(QPoint(-294, -2));
    anim1->setEndValue(QPoint(-3, -2));
    anim1->start();
    ui->pushButton->show();
    ui->leftFrame->show ();
    QTimer::singleShot (190,this,SLOT(showview()));
}
//食物细节窗口消失
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
Description:用户充值	
Remark:			
*************************************/
void customerwindow::on_pushButton_chongzhi_clicked()
{
    QString message;
	/*如果输入充值密码不是8位*/
    if (ui->lineEdit_chongzhi->text().length()==8)
    {
        bool ok;
        int input = ui->lineEdit_chongzhi->text().toInt(&ok,10);//输入串Qstring->int 10进制
        int money;
		/*验证重置密码有消息和金额
		被11除取余数*/
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
			//充值成功显示充值信息
            message = "充值成功!!        充值金额：";
            message+=QString::number(money,10);
            message+="元";
        }
        else
        {
			//充值失败 显示信息
            message = "充值失败！密码错误请检查后重试！";
        }

    }
    else
    {//密码长度不对
        message = "充值失败！请输入长度为8位的充值卡密码！";
    }
    ui->label_chongzhi->setText(message);//充值信息显示
    ui->label_chongzhi->show();
    ui->label_user_account->setText(QString::number(all_DCZ[active_dcz].show_account(),10));//用户金额刷新
    ui->lineEdit_chongzhi->clear();//输入框清空
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
        /*显示订单状态*/
        if (all_DCZ[active_dcz].order_id_list.size()!= 0)
        {
            //有订单
            state_tmp = all_orders[all_DCZ[active_dcz].show_order(0)].show_state();//临时订单状态设置为订单状态
            ui->label_scyname->setText(all_SCY[all_orders[all_DCZ[active_dcz].order_id_list[0]].show_scy_id()].show_username());//显示送餐员名字
            ui->pushButton_order->hide();//隐藏下单按钮
            ui->pushButton_check->show();//显示查询按钮
            ui->lcdNumber_order_amount->display(all_orders[all_DCZ[active_dcz].order_id_list[0]].show_amount());//显示订单金额
        }
        else
        {
            //无订单
            ui->pushButton_check->hide();//隐藏查询按钮
            ui->pushButton_order->show();//显示下单按钮
            ui->label_scyname->setText("无订单");//显示订单状态
            ui->lcdNumber_order_amount->display(0);//显示订单金额
            state_tmp = "无订单";
            ui->pushButton_urgent->hide();
        }
        ui->label_order_state->setText(state_tmp);//显示订单状态
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
    /*显示订单状态*/
    if (all_DCZ[active_dcz].order_id_list.size()!= 0)
    {
        //有订单
        state_tmp = all_orders[all_DCZ[active_dcz].show_order(0)].show_state();//临时订单状态设置为订单状态
        ui->label_scyname->setText(all_SCY[all_orders[all_DCZ[active_dcz].order_id_list[0]].show_scy_id()].show_username());//显示送餐员名字
        ui->pushButton_order->hide();//隐藏下单按钮
        ui->pushButton_check->show();//显示查询按钮
        ui->lcdNumber_order_amount->display(all_orders[all_DCZ[active_dcz].order_id_list[0]].show_amount());//显示订单金额
    }
    else
    {
        //无订单
        ui->pushButton_check->hide();//隐藏查询按钮
        ui->pushButton_order->show();//显示下单按钮
        ui->label_scyname->setText("无订单");//显示订单状态
        ui->lcdNumber_order_amount->display(0);//显示订单金额
        state_tmp = "无订单";
    }
    ui->label_order_state->setText(state_tmp);//显示订单状态
}
