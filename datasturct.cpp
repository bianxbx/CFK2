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
	purpose:	数据结构的函数定义部分
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
Parameter: QString username_tmp 用户名
Parameter: QString address_tmp 地址
Parameter: int account_tmp	账户余额
Parameter: QVector <int> order_id_list_tmp 订单列表
Created Time:	  	2013/11/24 0:34
Last Change:  		2013/11/24 0:34
version:	1.0.0
Description:	点餐者构造函数
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
Parameter: int price //订单价格
Parameter: int order_id//订单号
Created Time:	  	2013/11/24 0:35
Last Change:  		2013/11/24 0:35
version:	1.0.0
Description:	用户支付,传入要支付的订单的订单号以及价格。减账户余额,把订单加入列表
Remark:			
*************************************/
void DCZ::pay(int price,int order_id)
{
    this->account -= price;//账户减钱
    this->order_id_list.push_back(order_id);//订单号加入用户订单列表
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
Description:	从订单列表中删除已完成的
Remark:		1........将订单号置为特殊号(-1) 只标识不删除
				2.......好像没啥必要,直接出栈
*************************************/
void DCZ::finish_order()
{
//    this->order_id_list[0] = -1;
    this->order_id_list.pop_front();//已送完的订单出栈
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
Description:用户充值	由外部控制增加的金额
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
Parameter: int order_count_tmp//完成订单计数
Parameter: int amount_count_tmp//完成订单金额
Parameter: int delivering_order_tmp//正在运送订单号(-1表示没在运送)
Parameter: QVector<int> deliver_list_tmp//待运送订单列表
Created Time:	  	2013/11/24 0:38
Last Change:  		2013/11/24 0:38
version:	1.0.0
Description:	送餐员构造函数
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
Description:完成运送	订单计入统计数据	当前运送订单号设为特殊标识号-1
Remark:			
*************************************/
void SCY::finish_delivery()
{
    this->finish_delivered_list.push_back(this->delivering_order);//当前正在配送订单放入已完成订单列表
    this->amount_count+=all_orders[this->delivering_order].show_amount();//订单金额++
    this->order_count++;//订单计数++
    this->delivering_order = -1;//没有正在配送订单
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
Description:接受订单 把订单列表第一个设成正在运送	
Remark:			
*************************************/
bool SCY::acc_order()
{
    if (this->deliver_list.size()>0)
    {
        all_orders[this->deliver_list[0]].set_state_true();//当前订单状态变成开始配送
        this->delivering_order = this->deliver_list[0];//取出代配送订单放入正在配送订单
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
Description:把订单号放入代配送订单	
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
Parameter: QMap<int,int> item_tmp 订单食物ID，数量
Parameter: int amount_tmp 订单总金额
Parameter: QString address_tmp 送餐地址
Parameter: int dcz_id_tmp 订餐者ID
Created Time:	  	2013/11/24 0:43
Last Change:  		2013/11/24 0:43
version:	1.0.0
Description:	订单构造函数
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
Parameter: QString name_tmp 食物名
Parameter: int price_tmp 食物价格
Parameter: int id_tmp 食物ID
Created Time:	  	2013/11/24 0:44
Last Change:  		2013/11/24 0:44
version:	1.0.0
Description:	食物构造函数
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
Method:    operator操作符无脑重载!!!!
Author:		Bianx
Created Time:	  	2013/12/13 10:56
Last Change:  		2013/12/13 10:56
version:	1.0.0
Description:重载点餐者\送餐员\订单\食物 的 输入\输出流操作符	
Remark:		注意顺序要相同
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


