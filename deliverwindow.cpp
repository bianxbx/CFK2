#include "deliverwindow.h"

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
#include <QPalette>
#include <QBitmap>

#include "ui_deliverwindow.h"
#include "login.h"
#include "global.h"
#include "init.h"
#include "datastruct.h"
#include "login.h"

QStandardItemModel *model_delivering = new QStandardItemModel();
QStandardItemModel *model_to_deliver = new QStandardItemModel();
QStandardItemModel *model_delivered = new QStandardItemModel();

int window_flag2 = 1;
deliverwindow::deliverwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::deliverwindow)
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
    connect (closeButton,SIGNAL(clicked()),this,SLOT(wind_close()));//构建新槽 关闭当前窗口=注销
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
    ui->frame_view->hide();//查看页面隐藏
	ui->label_username->setText(all_SCY[active_scy].show_username());//用户名设置
	ui->lcdNumber_amount->display(all_SCY[active_scy].show_amount_count());//总金额
	ui->lcdNumber_counter->display(all_SCY[active_scy].show_order_count());//总订单数
#pragma endregion window initialize

	#pragma region 送餐列表初始化
    model_delivering->setHorizontalHeaderItem(0,new QStandardItem(QObject::tr("ID")));//设置行标
    model_delivering->setHorizontalHeaderItem(1,new QStandardItem(QObject::tr("Address")));
    model_delivering->setHorizontalHeaderItem(2,new QStandardItem(QObject::tr("Amount")));
    ui->tableView_ing ->setSelectionBehavior(QAbstractItemView::SelectRows);//表格设置,点格选中行
    ui->tableView_ing->setEditTriggers(QAbstractItemView::NoEditTriggers);//表格设置,不可编辑
    ui->tableView_ing->setModel(model_delivering);//表格与 MODEL 关联

    ui->tableView_ing->setColumnWidth(0,50);//列宽设置
    ui->tableView_ing->setColumnWidth(1,200);
    ui->tableView_ing->setColumnWidth(2,50);

    model_to_deliver->setHorizontalHeaderItem(0,new QStandardItem(QObject::tr("ID")));
    model_to_deliver->setHorizontalHeaderItem(1,new QStandardItem(QObject::tr("Address")));
    model_to_deliver->setHorizontalHeaderItem(2,new QStandardItem(QObject::tr("Amount")));
    ui->tableView_to ->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_to->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_to->setModel(model_to_deliver);

    ui->tableView_to->setColumnWidth(0,50);
    ui->tableView_to->setColumnWidth(1,200);
    ui->tableView_to->setColumnWidth(2,50);

    model_delivered->setHorizontalHeaderItem(0,new QStandardItem(QObject::tr("ID")));
    model_delivered->setHorizontalHeaderItem(1,new QStandardItem(QObject::tr("Address")));
    model_delivered->setHorizontalHeaderItem(2,new QStandardItem(QObject::tr("Amount")));
    ui->tableView_ed ->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_ed->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_ed->setModel(model_delivered);

    ui->tableView_ed->setColumnWidth(0,50);
    ui->tableView_ed->setColumnWidth(1,200);
    ui->tableView_ed->setColumnWidth(2,50);

    set_view_ing();//设置正在配送tableview
    set_view_to();//设置即将配送tableview
    set_view_ed();//设置已经配送tableview
#pragma endregion 送餐列表初始化
}

deliverwindow::~deliverwindow()
{
    delete ui;
}

/************************************
Method:    wind_close
FullName:  deliverwindow::wind_close
Author:		Bianx
Access:    private 
Returns:   void
Qualifier:
Created Time:	  	2013/12/13 11:15
Last Change:  		2013/12/13 11:15
version:	1.0.0
Description:关闭当前窗口打开login窗口	
Remark:			
*************************************/
void deliverwindow::wind_close()
{
    Login *temp;
    temp = new Login;
    temp->show();
    this->close();
}

/************************************
Method:    set_view_ing
FullName:  deliverwindow::set_view_ing
Author:		Bianx
Access:    private 
Returns:   void
Qualifier:
Created Time:	  	2013/11/24 12:30
Last Change:  		2013/11/24 12:30
version:	1.0.0
Description:显示正在配送订单	
Remark:			
*************************************/
void deliverwindow::set_view_ing()
{
    int order_id_tmp = all_SCY[active_scy].show_delivering_order_id();//正在配送号
    int food_id,food_num,i;
    QMap<int, int>::iterator it;

    if (order_id_tmp != -1)
    {
		//如果有正在配送的
        model_delivering->setItem(0, 0, new QStandardItem(QString::number(order_id_tmp,10)));//设置订单号
        model_delivering->setItem(0, 1, new QStandardItem(all_orders[order_id_tmp].show_order_address()));//设置地址
        model_delivering->setItem(0, 2, new QStandardItem(QString::number( all_orders[order_id_tmp].show_amount(),10)));//设置总金额
        it = all_orders[order_id_tmp].item.begin();//迭代器指向订单的第一个菜品

		/*循环输出每个菜品*/
        for (i = 0;i<all_orders[order_id_tmp].item.size();i++)
        {
            food_id = it.key();//食物号
            food_num = it.value();//食物数量
            model_delivering->setHorizontalHeaderItem(i*2+3,new QStandardItem(QObject::tr("Name")));
            model_delivering->setHorizontalHeaderItem(i*2+4,new QStandardItem(QObject::tr("Number")));
            model_delivering->setItem(0, i*2+3, new QStandardItem(all_food[food_id].show_food_name()));//设置食物名字
            model_delivering->setItem(0, i*2+4, new QStandardItem(QString::number(food_num,10)));//设置食物数量
            it++;
        }
    }
    else
    {
		//如果没有正在配送的,清空
        model_delivering->setColumnCount(3);
        model_delivering->setRowCount(0);
        //        model_delivering->setItem(0, 0, new QStandardItem("空"));
        //        model_delivering->setItem(0, 1, new QStandardItem("空"));
        //        model_delivering->setItem(0, 2, new QStandardItem("空"));
    }
}
/************************************
Method:    set_view_to
FullName:  deliverwindow::set_view_to
Author:		Bianx
Access:    private 
Returns:   void
Qualifier:
Created Time:	  	2013/11/24 12:30
Last Change:  		2013/11/24 12:30
version:	1.0.0
Description:显示待送订单列表	
Remark:			
*************************************/
void deliverwindow::set_view_to()
{
    int order_id_tmp;
    int food_id,food_num,i,j;
    QMap<int, int>::iterator it;

    if (all_SCY[active_scy].deliver_list.size() != 0)
    {
		//输出每个订单
        for (i = 0;i<all_SCY[active_scy].deliver_list.size();i++)
        {
            order_id_tmp = all_SCY[active_scy].deliver_list[i];
            model_to_deliver->setItem(i, 0, new QStandardItem(QString::number(order_id_tmp,10)));
            model_to_deliver->setItem(i, 1, new QStandardItem(all_orders[order_id_tmp].show_order_address()));
            model_to_deliver->setItem(i, 2, new QStandardItem(QString::number( all_orders[order_id_tmp].show_amount(),10)));
            it = all_orders[order_id_tmp].item.begin();
			//输出每个菜品
            for (j = 0;j<all_orders[order_id_tmp].item.size();j++)
            {
                food_id = it.key();
                food_num = it.value();
                model_to_deliver->setHorizontalHeaderItem(j*2+3,new QStandardItem(QObject::tr("Name")));
                model_to_deliver->setHorizontalHeaderItem(j*2+4,new QStandardItem(QObject::tr("Number")));
                model_to_deliver->setItem(i, j*2+3, new QStandardItem(all_food[food_id].show_food_name()));
                model_to_deliver->setItem(i, j*2+4, new QStandardItem(QString::number(food_num,10)));
                it++;
            }
        }
    }
    else
    {
        model_to_deliver->setColumnCount(3);
        model_to_deliver->setRowCount(0);
    }
}
void deliverwindow::set_view_ed()
{
    int order_id_tmp;
    int food_id,food_num,i,j;
    QMap<int, int>::iterator it;

    if (all_SCY[active_scy].finish_delivered_list.size() != 0)
    {
        //输出每个订单
        for (i = 0;i<all_SCY[active_scy].finish_delivered_list.size();i++)
        {
            order_id_tmp = all_SCY[active_scy].finish_delivered_list[i];
            model_delivered->setItem(i, 0, new QStandardItem(QString::number(order_id_tmp,10)));
            model_delivered->setItem(i, 1, new QStandardItem(all_orders[order_id_tmp].show_order_address()));
            model_delivered->setItem(i, 2, new QStandardItem(QString::number( all_orders[order_id_tmp].show_amount(),10)));
            it = all_orders[order_id_tmp].item.begin();
            //输出每个菜品
            for (j = 0;j<all_orders[order_id_tmp].item.size();j++)
            {
                food_id = it.key();
                food_num = it.value();
                model_delivered->setHorizontalHeaderItem(j*2+3,new QStandardItem(QObject::tr("Name")));
                model_delivered->setHorizontalHeaderItem(j*2+4,new QStandardItem(QObject::tr("Number")));
                model_delivered->setItem(i, j*2+3, new QStandardItem(all_food[food_id].show_food_name()));
                model_delivered->setItem(i, j*2+4, new QStandardItem(QString::number(food_num,10)));
                it++;
            }
        }
    }
    else
    {
        model_delivered->setColumnCount(3);
        model_delivered->setRowCount(0);
    }
}

/************************************
Method:    on_pushButton_acc_clicked
FullName:  deliverwindow::on_pushButton_acc_clicked
Author:		Bianx
Access:    private 
Returns:   void
Qualifier:
Created Time:	  	2013/11/24 12:36
Last Change:  		2013/11/24 12:36
version:	1.0.0
Description:接受订单,从待送中取出放到正在配送	
Remark:			
*************************************/
void deliverwindow::on_pushButton_acc_clicked()
{
    if (all_SCY[active_scy].deliver_list.size() != 0&&all_SCY[active_scy].show_delivering_order_id() == -1)
    {
		//如果  (有待送订单 &&  没有正在配送的订单)
        all_SCY[active_scy].acc_order();//接受订单
        model_to_deliver->setRowCount(0);//清空原订单
        set_view_to();//改变界面待送tableview显示
        set_view_ing();//改变界面正在送tableview显示
    }
    else
    {
        //error acc failed
    }
}

/************************************
Method:    on_pushButton_fin_clicked
FullName:  deliverwindow::on_pushButton_fin_clicked
Author:		Bianx
Access:    private 
Returns:   void
Qualifier:
Created Time:	  	2013/11/24 12:37
Last Change:  		2013/11/24 12:37
version:	1.0.0
Description:完成订单,讲正在配送订单删除.完成统计	
Remark:			
*************************************/
void deliverwindow::on_pushButton_fin_clicked()
{
    int order_id_tmp = all_SCY[active_scy].show_delivering_order_id();//正在配送订单号
    if (order_id_tmp != -1)
    {
		//有正在配送的
        all_SCY[active_scy].finish_delivery();//完成配送
        ui->lcdNumber_amount->display(all_SCY[active_scy].show_amount_count());//总金额改变反映在界面上
        ui->lcdNumber_counter->display(all_SCY[active_scy].show_order_count());//总订单改变反映在界面上
        all_orders[order_id_tmp].set_state_fin();//改变订单状态
        all_DCZ[all_orders[order_id_tmp].show_dcz_id()].finish_order();//点餐者收到外卖
		set_view_ing();//改变界面正在送tableview显示
        set_view_ed();//改变界面完成tableview显示
    }
    else
    {
        //error fin failed
    }
}

/************************************
Method:    on_pushButton_change_clicked
FullName:  deliverwindow::on_pushButton_change_clicked
Author:		Bianx
Access:    private 
Returns:   void
Qualifier:
Created Time:	  	2013/12/13 11:24
Last Change:  		2013/12/13 11:24
version:	1.0.0
Description:页面切换,在查询订单与操作界面间切换	
Remark:			
*************************************/
void deliverwindow::on_pushButton_change_clicked()
{
    if (window_flag2 == 0)
    {
        window_flag2 = 1;
        ui->frame_view->hide();
        ui->frame_order->show();
    }
    else
    {
        window_flag2 = 0;
        ui->frame_order->hide();
        ui->frame_view->show();
    }
}
