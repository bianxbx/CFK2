#ifndef USER_H
#define USER_H
/********************************************************************
    created:	2013/11/24 0:07
    filename:	C:\Users\hp\Desktop\CFK\CFK1\datastruct.h
    file path:	C:\Users\hp\Desktop\CFK\CFK1
    file base:	datastruct
    file ext:	h
    author:	 	Bianx
    version:	1.0.0
    purpose:	数据结构声明文件

*********************************************************************/

#include <QString>
#include <QMap>
#include <QVector>
#include <QDataStream>

//用户订单类,基类
class Order
{
public:
    Order();
    Order(QMap<int,int> item_tmp,int amount_tmp, QString address_tmp,int dcz_id_tmp,int scy_id_tmp); //构造函数,传递参数初始化订单

    void set_state_true();//完成订单设置
    void set_state_fin();//完成订单设置
    QString show_order_address();//供外部获取订单地址
    QString show_state();//供外部获取订单状态
    int show_amount();	//供外部获取订单金额
    int show_dcz_id();//供外部获取订餐者号
    int show_scy_id();//供外部获取送餐员号
    int id;//订单ID
    QMap<int,int>item;
    bool show_urgent(void);
    void set_urgent(void);
    friend QDataStream& operator <<(QDataStream &out_stream,Order &ord);//出操作符友元
    friend QDataStream& operator >>(QDataStream &out_stream,Order &ord);//入操作符友元
private:
    int scy_id;//送餐员ID；
    int dcz_id;//点餐者ID号
    int total_amount;//订单总金额
    int state;//订单状态 true 正在配送 false 队列中
    bool urgent;//cuidan
    QString DCZ_address;//送餐地址
};

//用户类,基类
class User
{
public:
    User();

    void Login();//登录

    int id;

    QString show_username(void);//供外部获取用户名
    QString show_password(void);//供外部获取密码
private:
protected:
    QString Username;
    QString Password;
};
/************************************************************************
点餐者(DCZ)类
继承User
所有点餐者都是这个类
***********************************************************************/
class DCZ : public User
{
public:
    DCZ();
    DCZ(QString username_tmp,QString password_tmp,QString address_tmp, int account_tmp,QVector <int> order_id_list_tmp, int id_tmp);//构造函数,传递参数点餐者

    void pay(int price,int order_id );//确认下单付款函数
    void finish_order();//完成订单

    int show_account();//供外部获取用户余额
    int show_order(int order_id_tmp);//供外部获取订单号
    void prepaid (int money);
    QString show_address();//供外部获取用户地址
    friend QDataStream& operator <<(QDataStream &out_stream,DCZ &dcz);//出操作符友元
    friend QDataStream& operator >>(QDataStream &out_stream,DCZ &dcz);//入操作符友元
    QVector <int> order_id_list;

private:

    int account;//用户余额
    QString address;//用户地址
};
/************************************************************************
送餐员(SCY)类
继承User
所有送餐员都是这个类
***********************************************************************/
class SCY : public User
{
public:
    SCY();
    SCY(QString username_tmp,QString password_tmp,int order_count_tmp,int amount_count_tmp,int delivering_order_tmp,QVector< int >deliver_list_tmp, int id_tmp,QVector<int> delivered_list_tmp);//构造函数,传递参数构造送餐员
    void finish_delivery();//完成配送函数
    bool acc_order();//接受订单函数
    void add_order_in_list(int id_to_add);//为送餐员分配订单

    int show_delivering_order_id();//供外部获取正在配送订单ID
    int show_order_count();//供外部获取送餐员工作统计
    int show_amount_count();//供外部获取送餐员工作统计
    QVector<int>finish_delivered_list;
    QVector<int>deliver_list;
    friend QDataStream& operator <<(QDataStream &out_stream,SCY &scy);//出操作符友元
    friend QDataStream& operator >>(QDataStream &out_stream,SCY &scy);//入操作符友元
private:
    int delivering_order;//正在配送订单号
    int order_count;//订单计数
    int amount_count;//总金额计数
};

class Food
{
public:
    Food();
    Food(QString,int,int);//构造函数,传递参数构造食物

    QString show_food_name();//供外部食物名
    int show_food_price();//供外部获取订单号
    friend QDataStream& operator <<(QDataStream &out_stream,Food &foo);//出操作符友元
    friend QDataStream& operator >>(QDataStream &out_stream,Food &foo);//入操作符友元
    int ID;//食物ID
private:
    QString name;//食物名
    int price;//食物价格

};
#endif // USER_H
