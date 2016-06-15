#include "bosswindow.h"
#include "ui_bosswindow.h"

#include <QCryptographicHash>
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
#include <QDebug>

#include "ui_deliverwindow.h"
#include "login.h"
#include "global.h"
#include "init.h"
#include "datastruct.h"
#include "login.h"

//QStandardItemModel *model_delivering = new QStandardItemModel();
//QStandardItemModel *model_to_deliver = new QStandardItemModel();
QStandardItemModel *model_menu2 = new QStandardItemModel();
QStandardItemModel *model_orders = new QStandardItemModel();
QStandardItemModel *model_scy= new QStandardItemModel();
int window_flag3 = 0;

bossWindow::bossWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::bossWindow)
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

    ui->lineEdit_passwd->setEchoMode(QLineEdit::Password);

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
    qDebug()<< "asdasd";
//    ui->frame_menu->hide();
    ui->frame_order->hide();//查看页面隐藏
    ui->frame_scy->show();
    ui->label_username->setText(all_SCY[active_scy].show_username());//用户名设置
    ui->lcdNumber_amount->display(all_SCY[active_scy].show_amount_count());//总金额
    ui->lcdNumber_counter->display(all_SCY[active_scy].show_order_count());//总订单数

#pragma endregion window initialize

    int i;

    /*菜单初始化*/
    model_menu2->setHorizontalHeaderItem(0,new QStandardItem(QObject::tr("Name")));//行标设置
    model_menu2->setHorizontalHeaderItem(1,new QStandardItem(QObject::tr("Price")));
    model_menu2->setHorizontalHeaderItem(2,new QStandardItem(QObject::tr("Rank")));
    ui->tableView_menu->setSelectionBehavior(QAbstractItemView::SelectRows);//点击选中行
    ui->tableView_menu->setEditTriggers(QAbstractItemView::NoEditTriggers);//不能编辑
    /*输出菜单至界面*/
    for (i = 0;i<all_food.size();i++)
    {
        model_menu2->setItem(i, 0, new QStandardItem(all_food[i].show_food_name()));//输出菜品名字
        model_menu2->setItem(i, 1, new QStandardItem(QString::number(all_food[i].show_food_price(),10)));//价格
        model_menu2->setItem(i, 2, new QStandardItem("★★★★★"));//评分
    }
    ui->tableView_menu->setModel(model_menu2);//讲model与tableview关联

    ui->tableView_menu->setColumnWidth(0,184);//设置列宽
    ui->tableView_menu->setColumnWidth(1,86);
    ui->tableView_menu->setColumnWidth(2,86);


    model_orders->setHorizontalHeaderItem(0,new QStandardItem(QObject::tr("OrderID")));
    model_orders->setHorizontalHeaderItem(1,new QStandardItem(QObject::tr("Address")));
    model_orders->setHorizontalHeaderItem(2,new QStandardItem(QObject::tr("Amount")));
    model_orders->setHorizontalHeaderItem(3,new QStandardItem(QObject::tr("state")));
    model_orders->setHorizontalHeaderItem(4,new QStandardItem(QObject::tr("Customer")));
    model_orders->setHorizontalHeaderItem(5,new QStandardItem(QObject::tr("Deliver")));
    ui->tableView_orders ->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_orders->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_orders->setModel(model_orders);

    ui->tableView_orders->setColumnWidth(0,50);
    ui->tableView_orders->setColumnWidth(1,200);
    ui->tableView_orders->setColumnWidth(2,50);
    ui->tableView_orders->setColumnWidth(3,80);
    ui->tableView_orders->setColumnWidth(4,80);
    ui->tableView_orders->setColumnWidth(5,80);

    set_view_orders();

    model_scy->setHorizontalHeaderItem(0,new QStandardItem(QObject::tr("ID")));
    model_scy->setHorizontalHeaderItem(1,new QStandardItem(QObject::tr("Name")));
    model_scy->setHorizontalHeaderItem(2,new QStandardItem(QObject::tr("Delivering order")));
    model_scy->setHorizontalHeaderItem(3,new QStandardItem(QObject::tr("Amount count")));
    model_scy->setHorizontalHeaderItem(4,new QStandardItem(QObject::tr("Order count")));
    ui->tableView_scy ->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_scy->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_scy->setModel(model_scy);
    set_view_scy();
}

bossWindow::~bossWindow()
{
    delete ui;
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

void bossWindow::set_view_orders()
{

    int order_id_tmp;
    int i;
    QString state_tmp;
    int amount = 0;
    for (i = 0;i<all_orders.size();i++)
    {
        order_id_tmp = i;
        amount += all_orders[order_id_tmp].show_amount();
        state_tmp = all_orders[order_id_tmp].show_state();
        model_orders->setItem(i, 0, new QStandardItem(QString::number(order_id_tmp,10)));
        model_orders->setItem(i, 1, new QStandardItem(all_orders[order_id_tmp].show_order_address()));
        model_orders->setItem(i, 2, new QStandardItem(QString::number(all_orders[order_id_tmp].show_amount(),10)));
        model_orders->setItem(i, 3, new QStandardItem(state_tmp));
        model_orders->setItem(i, 4, new QStandardItem(all_DCZ[all_orders[order_id_tmp].show_dcz_id()].show_username()));
        model_orders->setItem(i, 5, new QStandardItem(all_SCY[all_orders[order_id_tmp].show_scy_id()].show_username()));
        // it = all_orders[order_id_tmp].item.begin();
        // //输出每个菜品
        // for (j = 0;j<all_orders[order_id_tmp].item.size();j++)
        // {
        //     food_id = it.key();
        //     food_num = it.value();
        //     model_orders->setHorizontalHeaderItem(j*2+3,new QStandardItem(QObject::tr("Name")));
        //     model_orders->setHorizontalHeaderItem(j*2+4,new QStandardItem(QObject::tr("Number")));
        //     model_orders->setItem(i, j*2+3, new QStandardItem(all_food[food_id].show_food_name()));
        //     model_orders->setItem(i, j*2+4, new QStandardItem(QString::number(food_num,10)));
        //     it++;
        // }
    }
    ui->lcdNumber_amount->display(amount);//总金额
    ui->lcdNumber_counter->display(all_orders.size());//总订单数
}

void bossWindow::set_view_scy()
{

    int scy_id_tmp;
    int i;
    QString tmp;
    for (i = 1;i<all_SCY.size();i++)
    {
        scy_id_tmp = i;
        if (all_SCY[scy_id_tmp].show_delivering_order_id() == -1)
        {
            tmp = "IDLE";
        }
        else
        {
            tmp = QString::number(all_SCY[scy_id_tmp].show_delivering_order_id());
        }

        model_scy->setItem(i, 0, new QStandardItem(QString::number(scy_id_tmp,10)));
        model_scy->setItem(i, 1, new QStandardItem(all_SCY[scy_id_tmp].show_username()));
        model_scy->setItem(i, 2, new QStandardItem(tmp));
        model_scy->setItem(i, 3, new QStandardItem(QString::number(all_SCY[scy_id_tmp].show_order_count())));
        model_scy->setItem(i, 4, new QStandardItem(QString::number(all_SCY[scy_id_tmp].show_amount_count())));
    }
}

///************************************
//Method:    leftShow
//FullName:  bossWindow::leftShow
//Author:		Bianx
//Access:    public
//Returns:   void
//Qualifier:
//Created Time:	  	2013/11/24 11:17
//Last Change:  		2013/11/24 11:17
//version:	1.0.0
//Description:	左部伸缩框动画
//Remark:
//*************************************/
//void bossWindow::leftShow()
//{
//    /*滑动出现*/
//    QPropertyAnimation *anim1=new QPropertyAnimation(ui->graphicsView_leftblock,"pos");
//    anim1->setDuration(200);
//    anim1->setStartValue(QPoint(-280, 0));
//    anim1->setEndValue(QPoint(0, 0));
//    anim1->start();
//    ui->leftFrame->show ();
//    QTimer::singleShot (200,this,SLOT(showview()));
//}

//void bossWindow::leftHide()
//{
//    /*滑动消失*/
//    QPropertyAnimation *anim1=new QPropertyAnimation(ui->graphicsView_leftblock,"pos");
//    anim1->setDuration(200);
//    anim1->setStartValue(QPoint(0, 0));
//    anim1->setEndValue(QPoint(-280, 0));
//    anim1->start();
//    //ui->frame_food_detil->hide();
//    QTimer::singleShot (200,this,SLOT(hideview()));
//    ui->frame_user_order->hide();
//}

/************************************
Method:    wind_close
FullName:  bossWindow::wind_close
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
void bossWindow::wind_close()
{
    Login *temp;
    temp = new Login;
    temp->show();
    this->close();
}


///************************************
//Method:    on_tableView_menu_clicked
//FullName:  bossWindow::on_tableView_menu_clicked
//Author:		Bianx
//Access:    private
//Returns:   void
//Qualifier:
//Parameter: const QModelIndex & index
//Created Time:	  	2013/11/24 11:18
//Last Change:  		2013/11/24 11:18
//version:	1.0.0
//Description:窗口单机双击不明确,自写
//Remark:
//*************************************/
//void bossWindow::on_tableView_menu_clicked(const QModelIndex &index)
//{
//    /*j是击键动作计数器*/
//    if (j == 1)
//    {
//        //第二次有点击动作
//        timer->start(3600000);//不执行单击操作
//        j = 0;
//    }
//    else
//    {
//        //第一次有点击动作
//        timer->start (300);//延时200MS,超时执行单击操作
//        index_tmp = index;
//        j = 1;
//    }
//}


/************************************
Method:    on_tableView_menu_doubleClicked
FullName:  bossWindow::on_tableView_menu_doubleClicked
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
void bossWindow::on_tableView_scy_doubleClicked(const QModelIndex &index)
{
    int id_tmp;
    id_tmp = index.row()+1;//点击行号就是食物ID号
    model_scy ->removeRow(id_tmp);//在界面显示
    all_SCY.remove(id_tmp);
}

void bossWindow::on_tableView_menu_doubleClicked(const QModelIndex &index)
{
    int id_tmp;
    id_tmp = index.row();//点击行号就是食物ID号
    model_menu2->removeRow(id_tmp);//在界面显示
    all_food.remove(id_tmp);
}

void bossWindow::on_pushButton_add_menu_clicked()
{
    QString food_name;
    int price;
    food_name = ui->lineEdit_add_menu->text();
    price = ui->spinBox_add_menu->value();
    int i = all_food.size()-1;
    Food *tmp_food = new Food (food_name,price,i);
    all_food.push_back(*tmp_food);
    i += 1;
    model_menu2->setItem(i, 0, new QStandardItem(all_food[i].show_food_name()));//输出菜品名字
    model_menu2->setItem(i, 1, new QStandardItem(QString::number(all_food[i].show_food_price(),10)));//价格
    model_menu2->setItem(i, 2, new QStandardItem("★★★★★"));//评分
}

void bossWindow::on_pushButton_change_clicked()
{
    qDebug() << window_flag3;
    if (window_flag3 == 0)
    {

        window_flag3 = 1;
        ui->frame_menu->hide();
        ui->frame_order->show();
    }
    else if (window_flag3 == 1)
    {
        window_flag3 = 2;
        ui->frame_order->hide();
        ui->frame_scy->show();

    }
    else if (window_flag3 == 2)
    {
        window_flag3 = 0;
        ui->frame_scy->hide();
        ui->frame_menu->show();
    }
}

void bossWindow::on_frame_order_destroyed()
{
    qDebug()<<"nothing";
}

void bossWindow::on_pushButton_clicked()
{
    QVector <int> delivering_id_list_tmp;
    QString md5;//临时存放16进制输入串
    QString input;//输入串(密码与用户名拼接)
    QString result;//存放输入串的MD5加密串
    QString username;
    QString password;
    username = ui->lineEdit_uname->text();
    password = ui->lineEdit_passwd->text();
    input = username+password;
    QByteArray bb;
    bb = QCryptographicHash::hash ( input.toAscii(), QCryptographicHash::Md5 );
    result = md5.append(bb.toHex());//加密串

    all_SCY.push_back(SCY(username,result,0,0,-1,delivering_id_list_tmp,0,delivering_id_list_tmp));
}
