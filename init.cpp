#include <QString>
#include <QIODevice>
#include <QMap>
#include <QVector>
#include <QTime>
#include <QFile>
#include <QDataStream>
#include "datastruct.h"
#include "global.h"
#include "init.h"
#include <QDebug>
/********************************************************************
	created:	2013/12/3 15:37
	filename:	C:\Users\hp\Desktop\CFK\CFK2\init.cpp
	file path:	C:\Users\hp\Desktop\CFK\CFK2
	file base:	init
	file ext:	cpp
	author:	 	Bianx
	version:	1.0.0
	purpose:	��ʼ��
*********************************************************************/

QVector< Order > all_orders;
QVector< Food > all_food;
QVector< SCY > all_SCY;
QVector< DCZ > all_DCZ;
int active_scy;
int active_dcz;

/************************************
Method:    initial
FullName:  initial
Author:		Bianx
Access:    public 
Returns:   void
Qualifier:
Parameter: void
Created Time:	  	2013/11/24 12:38
Last Change:  		2013/11/24 12:38
version:	2.0.0
Description:��ʼ������	
Remark:			
*************************************/

void initial(void)
{
	      file_init(0);

    //    all_food.push_back(Food("�����",10,0));
    //    all_food.push_back(Food("�����",20,1));
    //    all_food.push_back(Food("�����",15,2));
    //active_dcz = 0;
    //active_scy = 0;
//    QVector <int> order_id_list_tmp;
//    QVector <int> delivering_id_list_tmp;
    //    QMap<int,int> a;
    //    a.insert(1,5);
    //    a.insert(2,1);
    //    order_id_list_tmp.push_back(0);
    //    delivering_id_list_tmp.push_back(1);
    //    delivering_id_list_tmp.push_back(2);
    //    delivering_id_list_tmp.push_back(3);
    //    all_orders.push_back(Order(a,10,"1qweqwe",0));
    //    all_orders.push_back(Order(a,30,"2asdasd",0));
    //    all_orders.push_back(Order(a,40,"3fzfzxc3",0));
    //    all_orders.push_back(Order(a,50,"4vzxcvzxc",0));

//    all_DCZ.push_back(DCZ("a","a","BUPT X1",200,order_id_list_tmp,0));
//    all_DCZ.push_back(DCZ("bCHESTtlong","houyi","luoyang",200,order_id_list_tmp,1));
//    all_DCZ.push_back(DCZ("b","b","china",200,order_id_list_tmp,2));
//    all_DCZ.push_back(DCZ("c","c","china",200,order_id_list_tmp,3));
//    all_DCZ.push_back(DCZ("d","d","china",200,order_id_list_tmp,4));
//    all_DCZ.push_back(DCZ("e","e","china",200,order_id_list_tmp,5));


//    stream >>tmp;
//    QString a = "JKJLK";
//    int b = 123,d;
//    QString c;
//    stream << a <<b<<endl;
//    file.close();
//    file.open(QIODevice::ReadOnly);
//    QDataStream streamo(&file);

    //all_SCY.push_back(SCY(0,0,-1,delivering_id_list_tmp));
    //all_SCY.push_back(SCY(10,100,-1,delivering_id_list_tmp));
    //all_SCY.push_back(SCY("wang","goudan",0,0,-1,delivering_id_list_tmp,0));

}
/************************************
Method:    file_init
FullName:  file_init
Author:		Bianx
Access:    public 
Returns:   void
Qualifier:
Parameter: int flag   ���ñ�־
Created Time:	  	2013/12/13 11:25
Last Change:  		2013/12/13 11:25
version:	1.0.0
Description:�ļ���ʼ��,�ļ��Ѵ�������ļ���ȡ	,��������д���µ�
Remark:			
*************************************/
void file_init(int flag)
{
	/*ָ���ļ�*/
    QFile filedcz("dcz.dat");
    QFile filescy("scy.dat");
    QFile fileord("ord.dat");
    QFile filefoo("foo.dat");
	/*���ݽṹ���*/
    all_DCZ.clear();
    all_orders.clear();
    all_food.clear();
    all_SCY.clear();

    if (!filedcz.exists()||flag == 1)
    {
		//���������
        filedcz.open(QIODevice::WriteOnly);//ֻ����ʽ��
        QDataStream stream(&filedcz);//������������
        QVector <int> order_id_list_tmp;//��ʱ�ն����б�
        stream << (quint32)0xB0E4D0B3;//�ļ�ǩ��magic number
        stream << (qint32)101;//�ļ��汾��
        stream.setVersion(QDataStream::Qt_4_0);//�����ȡqt�汾,��ֹ��ͬ�汾�ļ���ȡ�쳣
        int size;//���������
		/*���������*/
        all_DCZ.push_back(DCZ("a","4124bc0a9335c27f086f24ba207a4912","BUPT X1",200,order_id_list_tmp,0));//aa
        all_DCZ.push_back(DCZ("bCHESTtlong","092409cc789fb1b8be960eca90dc64ae","luoyang",200,order_id_list_tmp,1));//bCHESTtlong houyi
        all_DCZ.push_back(DCZ("b","21ad0bd836b90d08f4cf640b4c298e7c","china",200,order_id_list_tmp,2));//bb
        all_DCZ.push_back(DCZ("c","e0323a9039add2978bf5b49550572c7c","china",200,order_id_list_tmp,3));//cc
        all_DCZ.push_back(DCZ("d","1aabac6d068eef6a7bad3fdf50a05cc8","china",200,order_id_list_tmp,4));//dd
        all_DCZ.push_back(DCZ("dogVliang","42fca52f4bef6d4b959a03800078e843","Beijing",200,order_id_list_tmp,5));//dogVliang e

        size = all_DCZ.size();
        stream << size;//���ļ�����д���С
        for (int i = 0; i < size;i++)
        {
            stream << all_DCZ[i];//��ÿ��������д���ļ�
        }
        filedcz.close();//�ر��ļ�
    }
    else
    {
		//����߶�ȡ
        filedcz.open(QIODevice::ReadOnly);//ֻ����ʽ��
        QDataStream stream(&filedcz);//�����ļ���
        int size;
        quint32 magic_num;
        qint32 version;
        stream >> magic_num;//��ȡǩ��
        stream >> version;//��ȡ�汾
        if (magic_num == 0xB0E4D0B3 && version == 101)
        {
			//�ļ�����
            stream >> size;//���붩������
            DCZ tmp;
            for (int i = 0; i<size;i++)
            {
                stream >>tmp;//���붩����д����ʱ ����߿ռ�
                all_DCZ.push_back(tmp);//����ȫ�ֵ�����б�
            }
        }
    }
    if (!filescy.exists()||flag == 1)
    {
		//�Ͳ�Ա����
        filescy.open(QIODevice::WriteOnly);
        QDataStream stream(&filescy);
        QVector <int> delivering_id_list_tmp;
        stream << (quint32)0xB0E4D0B3;
        stream << (qint32)101;
        stream.setVersion(QDataStream::Qt_4_0);
        all_SCY.push_back(SCY("boss","d29c5d631e605d5e109029b6bfa39591",0,0,-1,delivering_id_list_tmp,0,delivering_id_list_tmp));//boss boss
        all_SCY.push_back(SCY("wang","ba0484cef03689235c64947a9592df22",0,0,-1,delivering_id_list_tmp,0,delivering_id_list_tmp));
        all_SCY.push_back(SCY("nuri","8168011134d0a62b7c096e610fb360bd",0,0,-1,delivering_id_list_tmp,0,delivering_id_list_tmp));

        int size;
        size = all_SCY.size();
        stream << size;

        for (int i = 0; i < size;i++)
        {
            stream << all_SCY[i];
        }
        filescy.close();
    }
    else
    {
		//�Ͳ�Ա��ȡ
        filescy.open(QIODevice::ReadOnly);
        QDataStream stream(&filescy);
        int size;
        quint32 magic_num;
        qint32 version;
        stream >> magic_num;
        stream >> version;
        if (magic_num == 0xB0E4D0B3 && version == 101)
        {
            stream >> size;
            SCY tmp;
            for (int i = 0; i<size;i++)
            {
                stream >> tmp;
                all_SCY.push_back(tmp);
            }
        }
    }
    if (!fileord.exists()||flag == 1)
    {
		//��������
        fileord.open(QIODevice::WriteOnly);
        QDataStream stream(&fileord);

        stream << (quint32)0xB0E4D0B3;
        stream << (qint32)101;
        stream.setVersion(QDataStream::Qt_4_0);

        int size = 0;
        //size = all_orders.size();
        stream << size;
        fileord.close();
    }
    else
    {
		//������ȡ
        fileord.open(QIODevice::ReadOnly);
        QDataStream stream(&fileord);
        int size;
        quint32 magic_num;
        qint32 version;
        stream >> magic_num;
        stream >> version;
        if (magic_num == 0xB0E4D0B3 && version == 101)
        {
            stream >> size;
            Order tmp;
            for (int i = 0; i<size;i++)
            {
                stream >> tmp;
                all_orders.push_back(tmp);
            }
        }
    }
    if (!filefoo.exists()||flag == 1)
    {
		//ʳ������
        filefoo.open(QIODevice::WriteOnly);
        QDataStream stream(&filefoo);
        stream << (quint32)0xB0E4D0B3;
        stream << (qint32)101;
        stream.setVersion(QDataStream::Qt_4_0);

#pragma region ������ɲ�Ʒ��+�۸�
        QVector<QString> name1,name2,name3;
        name1.push_back("����");
        name1.push_back("�°¶���");
        name1.push_back("����");
        name1.push_back("");
        name1.push_back("������");
        name1.push_back("����");
        name1.push_back("Ģ��֥ʿ");
        name1.push_back("��԰");
        name1.push_back("����");
        name1.push_back("ʮ��");
        name1.push_back("����");
        name2.push_back("����");
        name2.push_back("����");
        name2.push_back("ԭζ��");
        name2.push_back("���׻�");
        name2.push_back("��У����");
        name2.push_back("���ȱ�");
        name2.push_back("ȫϺ��");
        name2.push_back("ţ���");
        name2.push_back("�����");
        name2.push_back("��ţ��");
        name2.push_back("�̲�");
        name2.push_back("������");
        name2.push_back("����");
        name2.push_back("���");
        name2.push_back("����");
        name3.push_back("���У�");
        name3.push_back("��С��");
        name3.push_back("���ش�");
        name3.push_back("�ײ�");
        name3.push_back("");
        name3.push_back("");
        name3.push_back("");
        name3.push_back("");
        name3.push_back("��");
        name3.push_back("�ײ�");
        name3.push_back("�ײ�");
        QString random_food_name;
        QTime time;
        time= QTime::currentTime();
        qsrand(time.msec()+time.second()*1000);
        int randn=qrand()%10;
        int i;
        for (i = 0;i<50;i++)
        {
            random_food_name.clear();
            randn=qrand()%11;
            random_food_name = name1[randn];
            randn = qrand()%15;
            random_food_name += name2[randn];
            randn = qrand()%11;
            random_food_name += name3[randn];
            randn = qrand()%45;
            all_food.push_back(Food(random_food_name,randn+5,i));
        }
#pragma endregion ������ɲ�Ʒ��

        int size;
        size = all_food.size();
        stream << size;

        for (int i = 0; i < size;i++)
        {
            stream << all_food[i];
        }
        filefoo.close();
    }
    else
    {
		//ʳ���ȡ
        filefoo.open(QIODevice::ReadOnly);
        QDataStream stream(&filefoo);
        int size;
        quint32 magic_num;
        qint32 version;
        stream >> magic_num;
        stream >> version;
        if (magic_num == 0xB0E4D0B3 && version == 101)
        {
            stream >> size;
            Food tmp;
            for (int i = 0; i<size;i++)
            {
                stream >>tmp;
                all_food.push_back(tmp);
            }
        }
    }
}

