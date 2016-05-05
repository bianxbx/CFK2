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
    connect (closeButton,SIGNAL(clicked()),this,SLOT(wind_close()));//�����²� �رյ�ǰ����=ע��
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
    ui->frame_view->hide();//�鿴ҳ������
	ui->label_username->setText(all_SCY[active_scy].show_username());//�û�������
	ui->lcdNumber_amount->display(all_SCY[active_scy].show_amount_count());//�ܽ��
	ui->lcdNumber_counter->display(all_SCY[active_scy].show_order_count());//�ܶ�����
#pragma endregion window initialize

	#pragma region �Ͳ��б��ʼ��
    model_delivering->setHorizontalHeaderItem(0,new QStandardItem(QObject::tr("ID")));//�����б�
    model_delivering->setHorizontalHeaderItem(1,new QStandardItem(QObject::tr("Address")));
    model_delivering->setHorizontalHeaderItem(2,new QStandardItem(QObject::tr("Amount")));
    ui->tableView_ing ->setSelectionBehavior(QAbstractItemView::SelectRows);//�������,���ѡ����
    ui->tableView_ing->setEditTriggers(QAbstractItemView::NoEditTriggers);//�������,���ɱ༭
    ui->tableView_ing->setModel(model_delivering);//����� MODEL ����

    ui->tableView_ing->setColumnWidth(0,50);//�п�����
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

    set_view_ing();//������������tableview
    set_view_to();//���ü�������tableview
    set_view_ed();//�����Ѿ�����tableview
#pragma endregion �Ͳ��б��ʼ��
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
Description:�رյ�ǰ���ڴ�login����	
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
Description:��ʾ�������Ͷ���	
Remark:			
*************************************/
void deliverwindow::set_view_ing()
{
    int order_id_tmp = all_SCY[active_scy].show_delivering_order_id();//�������ͺ�
    int food_id,food_num,i;
    QMap<int, int>::iterator it;

    if (order_id_tmp != -1)
    {
		//������������͵�
        model_delivering->setItem(0, 0, new QStandardItem(QString::number(order_id_tmp,10)));//���ö�����
        model_delivering->setItem(0, 1, new QStandardItem(all_orders[order_id_tmp].show_order_address()));//���õ�ַ
        model_delivering->setItem(0, 2, new QStandardItem(QString::number( all_orders[order_id_tmp].show_amount(),10)));//�����ܽ��
        it = all_orders[order_id_tmp].item.begin();//������ָ�򶩵��ĵ�һ����Ʒ

		/*ѭ�����ÿ����Ʒ*/
        for (i = 0;i<all_orders[order_id_tmp].item.size();i++)
        {
            food_id = it.key();//ʳ���
            food_num = it.value();//ʳ������
            model_delivering->setHorizontalHeaderItem(i*2+3,new QStandardItem(QObject::tr("Name")));
            model_delivering->setHorizontalHeaderItem(i*2+4,new QStandardItem(QObject::tr("Number")));
            model_delivering->setItem(0, i*2+3, new QStandardItem(all_food[food_id].show_food_name()));//����ʳ������
            model_delivering->setItem(0, i*2+4, new QStandardItem(QString::number(food_num,10)));//����ʳ������
            it++;
        }
    }
    else
    {
		//���û���������͵�,���
        model_delivering->setColumnCount(3);
        model_delivering->setRowCount(0);
        //        model_delivering->setItem(0, 0, new QStandardItem("��"));
        //        model_delivering->setItem(0, 1, new QStandardItem("��"));
        //        model_delivering->setItem(0, 2, new QStandardItem("��"));
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
Description:��ʾ���Ͷ����б�	
Remark:			
*************************************/
void deliverwindow::set_view_to()
{
    int order_id_tmp;
    int food_id,food_num,i,j;
    QMap<int, int>::iterator it;

    if (all_SCY[active_scy].deliver_list.size() != 0)
    {
		//���ÿ������
        for (i = 0;i<all_SCY[active_scy].deliver_list.size();i++)
        {
            order_id_tmp = all_SCY[active_scy].deliver_list[i];
            model_to_deliver->setItem(i, 0, new QStandardItem(QString::number(order_id_tmp,10)));
            model_to_deliver->setItem(i, 1, new QStandardItem(all_orders[order_id_tmp].show_order_address()));
            model_to_deliver->setItem(i, 2, new QStandardItem(QString::number( all_orders[order_id_tmp].show_amount(),10)));
            it = all_orders[order_id_tmp].item.begin();
			//���ÿ����Ʒ
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
        //���ÿ������
        for (i = 0;i<all_SCY[active_scy].finish_delivered_list.size();i++)
        {
            order_id_tmp = all_SCY[active_scy].finish_delivered_list[i];
            model_delivered->setItem(i, 0, new QStandardItem(QString::number(order_id_tmp,10)));
            model_delivered->setItem(i, 1, new QStandardItem(all_orders[order_id_tmp].show_order_address()));
            model_delivered->setItem(i, 2, new QStandardItem(QString::number( all_orders[order_id_tmp].show_amount(),10)));
            it = all_orders[order_id_tmp].item.begin();
            //���ÿ����Ʒ
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
Description:���ܶ���,�Ӵ�����ȡ���ŵ���������	
Remark:			
*************************************/
void deliverwindow::on_pushButton_acc_clicked()
{
    if (all_SCY[active_scy].deliver_list.size() != 0&&all_SCY[active_scy].show_delivering_order_id() == -1)
    {
		//���  (�д��Ͷ��� &&  û���������͵Ķ���)
        all_SCY[active_scy].acc_order();//���ܶ���
        model_to_deliver->setRowCount(0);//���ԭ����
        set_view_to();//�ı�������tableview��ʾ
        set_view_ing();//�ı����������tableview��ʾ
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
Description:��ɶ���,���������Ͷ���ɾ��.���ͳ��	
Remark:			
*************************************/
void deliverwindow::on_pushButton_fin_clicked()
{
    int order_id_tmp = all_SCY[active_scy].show_delivering_order_id();//�������Ͷ�����
    if (order_id_tmp != -1)
    {
		//���������͵�
        all_SCY[active_scy].finish_delivery();//�������
        ui->lcdNumber_amount->display(all_SCY[active_scy].show_amount_count());//�ܽ��ı䷴ӳ�ڽ�����
        ui->lcdNumber_counter->display(all_SCY[active_scy].show_order_count());//�ܶ����ı䷴ӳ�ڽ�����
        all_orders[order_id_tmp].set_state_true();//�ı䶩��״̬
        all_DCZ[all_orders[order_id_tmp].show_dcz_id()].finish_order();//������յ�����
		set_view_ing();//�ı����������tableview��ʾ
        set_view_ed();//�ı�������tableview��ʾ
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
Description:ҳ���л�,�ڲ�ѯ���������������л�	
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
