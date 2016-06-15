#include <QDataStream>
#include <QDebug>
#include "datastruct.h"
#include "global.h"


/********************************************************************
	created:	2013/11/24 0:32
	filename:	C:\Users\hp\Desktop\CFK\CFK1\datasturct.cpp
	file path:	C:\Users\hp\Desktop\CFK\CFK1
	file base:	datasturct
	file ext:	cpp
	author:	 	Bianx
	version:	1.0.0
	purpose:	���ݽṹ�ĺ������岿��
*********************************************************************/

User::User()
{
}
QString User::show_username(void)
{
    return this->Username;
}
QString User::show_password(void)
{
    return this->Password;
}
DCZ::DCZ()
{

}
/************************************
Method:    DCZ
FullName:  DCZ::DCZ
Author:		Bianx
Access:    public 
Returns:   
Qualifier:
Parameter: QString username_tmp �û���
Parameter: QString address_tmp ��ַ
Parameter: int account_tmp	�˻����
Parameter: QVector <int> order_id_list_tmp �����б�
Created Time:	  	2013/11/24 0:34
Last Change:  		2013/11/24 0:34
version:	1.0.0
Description:	����߹��캯��
Remark:			
*************************************/
DCZ::DCZ(QString username_tmp,QString password_tmp,QString address_tmp,int account_tmp, QVector <int> order_id_list_tmp, int id_tmp)
{
    this->Password = password_tmp;
    this->Username = username_tmp;
    this->id = id_tmp;
    this->account = account_tmp;
    this->address = address_tmp;
    this->order_id_list = order_id_list_tmp;
}
/************************************
Method:    pay
FullName:  DCZ::pay
Author:		Bianx
Access:    public 
Returns:   void
Qualifier:
Parameter: int price //�����۸�
Parameter: int order_id//������
Created Time:	  	2013/11/24 0:35
Last Change:  		2013/11/24 0:35
version:	1.0.0
Description:	�û�֧��,����Ҫ֧���Ķ����Ķ������Լ��۸񡣼��˻����,�Ѷ��������б�
Remark:			
*************************************/
void DCZ::pay(int price,int order_id)
{
    this->account -= price;//�˻���Ǯ
    this->order_id_list.push_back(order_id);//�����ż����û������б�
}
/************************************
Method:    finish_order
FullName:  DCZ::finish_order
Author:		Bianx
Access:    public 
Returns:   void
Qualifier:
Created Time:	  	2013/11/24 0:36
Last Change:  		2013/11/24 0:36
version:	1.0.0
Description:	�Ӷ����б���ɾ������ɵ�
Remark:		1........����������Ϊ�����(-1) ֻ��ʶ��ɾ��
				2.......����ûɶ��Ҫ,ֱ�ӳ�ջ
*************************************/
void DCZ::finish_order()
{
//    this->order_id_list[0] = -1;
    this->order_id_list.pop_front();//������Ķ�����ջ
}
int DCZ::show_order(int order_id_tmp)
{
    return this->order_id_list[order_id_tmp];
}
/************************************
Method:    prepaid
FullName:  DCZ::prepaid
Author:		Bianx
Access:    public 
Returns:   void
Qualifier:
Parameter: int money
Created Time:	  	2013/12/13 11:00
Last Change:  		2013/12/13 11:00
version:	1.0.0
Description:�û���ֵ	���ⲿ�������ӵĽ��
Remark:			
*************************************/
void DCZ::prepaid(int money)
{
    this->account+=money;//greedisgood 999999
}

QString DCZ::show_address()
{
    return this->address;
}
int DCZ::show_account()
{
    return this->account;
}

SCY::SCY()
{
}
/************************************
Method:    SCY
FullName:  SCY::SCY
Author:		Bianx
Access:    public 
Returns:   
Qualifier:
Parameter: int order_count_tmp//��ɶ�������
Parameter: int amount_count_tmp//��ɶ������
Parameter: int delivering_order_tmp//�������Ͷ�����(-1��ʾû������)
Parameter: QVector<int> deliver_list_tmp//�����Ͷ����б�
Created Time:	  	2013/11/24 0:38
Last Change:  		2013/11/24 0:38
version:	1.0.0
Description:	�Ͳ�Ա���캯��
Remark:			
*************************************/
SCY::SCY(QString username_tmp,QString password_tmp,int order_count_tmp, int amount_count_tmp, int delivering_order_tmp, QVector<int> deliver_list_tmp,int id_tmp,QVector<int> delivered_list_tmp)
{
    this->id = id_tmp;
    this->Password = password_tmp;
    this->Username = username_tmp;
    this->order_count = order_count_tmp;
    this->amount_count = amount_count_tmp;
    this->delivering_order = delivering_order_tmp;
    this->deliver_list = deliver_list_tmp;
    this->finish_delivered_list = delivered_list_tmp;
}

/************************************
Method:    finish_delivery
FullName:  SCY::finish_delivery
Author:		Bianx
Access:    public 
Returns:   void
Qualifier:
Created Time:	  	2013/11/24 0:40
Last Change:  		2013/11/24 0:40
version:	1.0.0
Description:�������	��������ͳ������	��ǰ���Ͷ�������Ϊ�����ʶ��-1
Remark:			
*************************************/
void SCY::finish_delivery()
{
    this->finish_delivered_list.push_back(this->delivering_order);//��ǰ�������Ͷ�����������ɶ����б�
    this->amount_count+=all_orders[this->delivering_order].show_amount();//�������++
    this->order_count++;//��������++
    this->delivering_order = -1;//û���������Ͷ���
}
/************************************
Method:    acc_order
FullName:  SCY::acc_order
Author:		Bianx
Access:    public 
Returns:   bool
Qualifier:
Created Time:	  	2013/11/24 0:42
Last Change:  		2013/11/24 0:42
version:	1.0.0
Description:���ܶ��� �Ѷ����б��һ�������������	
Remark:			
*************************************/
bool SCY::acc_order()
{
    if (this->deliver_list.size()>0)
    {
        all_orders[this->deliver_list[0]].set_state_true();//��ǰ����״̬��ɿ�ʼ����
        this->delivering_order = this->deliver_list[0];//ȡ�������Ͷ��������������Ͷ���
        this->deliver_list.pop_front();
        return true;
    }
    else
    {
        return false;
    }
}
/************************************
Method:    add_order_in_list
FullName:  SCY::add_order_in_list
Author:		Bianx
Access:    public 
Returns:   void
Qualifier:
Parameter: int id_to_add
Created Time:	  	2013/12/13 11:04
Last Change:  		2013/12/13 11:04
version:	1.0.0
Description:�Ѷ����ŷ�������Ͷ���	
Remark:			
*************************************/
void SCY::add_order_in_list(int id_to_add)
{
    this->deliver_list.push_back(id_to_add);//
}
int SCY::show_delivering_order_id()
{
    return this->delivering_order;
}
int SCY::show_order_count()
{
    return this->order_count;
}

int SCY::show_amount_count()
{
    return this->amount_count;
}

Order::Order()
{
}
/************************************
Method:    Order
FullName:  Order::Order
Author:		Bianx
Access:    public 
Returns:   
Qualifier:
Parameter: QMap<int,int> item_tmp ����ʳ��ID������
Parameter: int amount_tmp �����ܽ��
Parameter: QString address_tmp �Ͳ͵�ַ
Parameter: int dcz_id_tmp ������ID
Created Time:	  	2013/11/24 0:43
Last Change:  		2013/11/24 0:43
version:	1.0.0
Description:	�������캯��
Remark:			
*************************************/
Order::Order(QMap<int, int> item_tmp , int amount_tmp,QString address_tmp,int dcz_id_tmp, int scy_id_tmp)
{
    this->item = item_tmp;
    this->total_amount = amount_tmp;
    this->state = 0;
    this->DCZ_address = address_tmp;
    this->dcz_id = dcz_id_tmp;
    this->scy_id = scy_id_tmp;
}

int Order::show_amount()
{
    return total_amount;
}
QString Order::show_state()
{
    qDebug()<<"####" <<int(this->state);
    if (this->state == 1)
    {

        return "Delivering";
    }
    else if (this->state == 0)
    {
        return "Waiting";
    }
    else
    {
        return "Finished";
    }
}
int Order::show_dcz_id()
{
    return this->dcz_id;
}
int Order::show_scy_id()
{
    return this->scy_id;
}
QString Order::show_order_address()
{
    return this->DCZ_address;
}
void Order::set_state_true()
{
    this->state = 1;
}
void Order::set_state_fin()
{
    this->state = -1;
}


Food::Food()
{

}

/************************************
Method:    Food
FullName:  Food::Food
Author:		Bianx
Access:    public 
Returns:   
Qualifier:
Parameter: QString name_tmp ʳ����
Parameter: int price_tmp ʳ��۸�
Parameter: int id_tmp ʳ��ID
Created Time:	  	2013/11/24 0:44
Last Change:  		2013/11/24 0:44
version:	1.0.0
Description:	ʳ�ﹹ�캯��
Remark:			
*************************************/
Food::Food(QString name_tmp,int price_tmp, int id_tmp)
{
    name = name_tmp;
    price = price_tmp;
    ID = id_tmp;
}
QString Food::show_food_name()
{
    return this->name;
}
int Food::show_food_price()
{
    return this->price;
}

/************************************
Method:    operator��������������!!!!
Author:		Bianx
Created Time:	  	2013/12/13 10:56
Last Change:  		2013/12/13 10:56
version:	1.0.0
Description:���ص����\�Ͳ�Ա\����\ʳ�� �� ����\�����������	
Remark:		ע��˳��Ҫ��ͬ
*************************************/
QDataStream& operator << (QDataStream &out_stream,DCZ &dcz)
{
    out_stream << dcz.Username;
    out_stream << dcz.Password;
    out_stream << dcz.id;
    out_stream << dcz.account;
    out_stream << dcz.address;
    out_stream << dcz.order_id_list;
    return out_stream;
}

QDataStream& operator >> (QDataStream &out_stream,DCZ &dcz)
{
    out_stream >> dcz.Username;
    out_stream >> dcz.Password;
    out_stream >> dcz.id;
    out_stream >> dcz.account;
    out_stream >> dcz.address;
    out_stream >> dcz.order_id_list;
    return out_stream;
}
QDataStream& operator << (QDataStream &out_stream,SCY &scy)
{
    out_stream << scy.Username;
    out_stream << scy.Password;
    out_stream << scy.order_count;
    out_stream << scy.amount_count;
    out_stream << scy.delivering_order;
    out_stream << scy.deliver_list;
    out_stream << scy.finish_delivered_list;
    return out_stream;
}

QDataStream& operator >> (QDataStream &out_stream,SCY &scy)
{
    out_stream >> scy.Username;
    out_stream >> scy.Password;
    out_stream >> scy.order_count;
    out_stream >> scy.amount_count;
    out_stream >> scy.delivering_order;
    out_stream >> scy.deliver_list;
    out_stream >> scy.finish_delivered_list;
    return out_stream;
}

QDataStream& operator << (QDataStream &out_stream,Order &ord)
{
    out_stream << ord.item;
    out_stream << ord.total_amount;
    out_stream << ord.DCZ_address;
    out_stream << ord.dcz_id;
    out_stream << ord.scy_id;
    return out_stream;
}
QDataStream& operator >> (QDataStream &out_stream,Order &ord)
{
    out_stream >> ord.item;
    out_stream >> ord.total_amount;
    out_stream >> ord.DCZ_address;
    out_stream >> ord.dcz_id;
    out_stream >> ord.scy_id;
    return out_stream;
}
QDataStream& operator <<(QDataStream &out_stream,Food &foo)
{
    out_stream << foo.ID;
    out_stream << foo.name;
    out_stream << foo.price;
    return out_stream;
}

QDataStream& operator >>(QDataStream &out_stream,Food &foo)
{
    out_stream >> foo.ID;
    out_stream >> foo.name;
    out_stream >> foo.price;
    return out_stream;
}


