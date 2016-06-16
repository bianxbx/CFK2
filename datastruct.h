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
    purpose:	���ݽṹ�����ļ�

*********************************************************************/

#include <QString>
#include <QMap>
#include <QVector>
#include <QDataStream>

//�û�������,����
class Order
{
public:
    Order();
    Order(QMap<int,int> item_tmp,int amount_tmp, QString address_tmp,int dcz_id_tmp,int scy_id_tmp); //���캯��,���ݲ�����ʼ������

    void set_state_true();//��ɶ�������
    void set_state_fin();//��ɶ�������
    QString show_order_address();//���ⲿ��ȡ������ַ
    QString show_state();//���ⲿ��ȡ����״̬
    int show_amount();	//���ⲿ��ȡ�������
    int show_dcz_id();//���ⲿ��ȡ�����ߺ�
    int show_scy_id();//���ⲿ��ȡ�Ͳ�Ա��
    int id;//����ID
    QMap<int,int>item;
    bool show_urgent(void);
    void set_urgent(void);
    friend QDataStream& operator <<(QDataStream &out_stream,Order &ord);//����������Ԫ
    friend QDataStream& operator >>(QDataStream &out_stream,Order &ord);//���������Ԫ
private:
    int scy_id;//�Ͳ�ԱID��
    int dcz_id;//�����ID��
    int total_amount;//�����ܽ��
    int state;//����״̬ true �������� false ������
    bool urgent;//cuidan
    QString DCZ_address;//�Ͳ͵�ַ
};

//�û���,����
class User
{
public:
    User();

    void Login();//��¼

    int id;

    QString show_username(void);//���ⲿ��ȡ�û���
    QString show_password(void);//���ⲿ��ȡ����
private:
protected:
    QString Username;
    QString Password;
};
/************************************************************************
�����(DCZ)��
�̳�User
���е���߶��������
***********************************************************************/
class DCZ : public User
{
public:
    DCZ();
    DCZ(QString username_tmp,QString password_tmp,QString address_tmp, int account_tmp,QVector <int> order_id_list_tmp, int id_tmp);//���캯��,���ݲ��������

    void pay(int price,int order_id );//ȷ���µ������
    void finish_order();//��ɶ���

    int show_account();//���ⲿ��ȡ�û����
    int show_order(int order_id_tmp);//���ⲿ��ȡ������
    void prepaid (int money);
    QString show_address();//���ⲿ��ȡ�û���ַ
    friend QDataStream& operator <<(QDataStream &out_stream,DCZ &dcz);//����������Ԫ
    friend QDataStream& operator >>(QDataStream &out_stream,DCZ &dcz);//���������Ԫ
    QVector <int> order_id_list;

private:

    int account;//�û����
    QString address;//�û���ַ
};
/************************************************************************
�Ͳ�Ա(SCY)��
�̳�User
�����Ͳ�Ա���������
***********************************************************************/
class SCY : public User
{
public:
    SCY();
    SCY(QString username_tmp,QString password_tmp,int order_count_tmp,int amount_count_tmp,int delivering_order_tmp,QVector< int >deliver_list_tmp, int id_tmp,QVector<int> delivered_list_tmp);//���캯��,���ݲ��������Ͳ�Ա
    void finish_delivery();//������ͺ���
    bool acc_order();//���ܶ�������
    void add_order_in_list(int id_to_add);//Ϊ�Ͳ�Ա���䶩��

    int show_delivering_order_id();//���ⲿ��ȡ�������Ͷ���ID
    int show_order_count();//���ⲿ��ȡ�Ͳ�Ա����ͳ��
    int show_amount_count();//���ⲿ��ȡ�Ͳ�Ա����ͳ��
    QVector<int>finish_delivered_list;
    QVector<int>deliver_list;
    friend QDataStream& operator <<(QDataStream &out_stream,SCY &scy);//����������Ԫ
    friend QDataStream& operator >>(QDataStream &out_stream,SCY &scy);//���������Ԫ
private:
    int delivering_order;//�������Ͷ�����
    int order_count;//��������
    int amount_count;//�ܽ�����
};

class Food
{
public:
    Food();
    Food(QString,int,int);//���캯��,���ݲ�������ʳ��

    QString show_food_name();//���ⲿʳ����
    int show_food_price();//���ⲿ��ȡ������
    friend QDataStream& operator <<(QDataStream &out_stream,Food &foo);//����������Ԫ
    friend QDataStream& operator >>(QDataStream &out_stream,Food &foo);//���������Ԫ
    int ID;//ʳ��ID
private:
    QString name;//ʳ����
    int price;//ʳ��۸�

};
#endif // USER_H
