#include "bosswindow.h"
#include "ui_bosswindow.h"

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

//QStandardItemModel *model_delivering = new QStandardItemModel();
//QStandardItemModel *model_to_deliver = new QStandardItemModel();
QStandardItemModel *model_menu2 = new QStandardItemModel();

int window_flag3 = 1;

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
    ui->frame_order->hide();//查看页面隐藏
    ui->label_username->setText(all_SCY[active_scy].show_username());//用户名设置
    ui->lcdNumber_amount->display(all_SCY[active_scy].show_amount_count());//总金额
    ui->lcdNumber_counter->display(all_SCY[active_scy].show_order_count());//总订单数

#pragma endregion window initialize

    int i;
    window_flag3 = 1;

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

}

bossWindow::~bossWindow()
{
    delete ui;
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
