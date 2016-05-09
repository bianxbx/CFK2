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
	purpose:	初始化
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
Description:初始化函数	
Remark:			
*************************************/

void initial(void)
{
	      file_init(0);

    //    all_food.push_back(Food("打掉少",10,0));
    //    all_food.push_back(Food("大雕烧",20,1));
    //    all_food.push_back(Food("大屌烧",15,2));
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
Parameter: int flag   重置标志
Created Time:	  	2013/12/13 11:25
Last Change:  		2013/12/13 11:25
version:	1.0.0
Description:文件初始化,文件已存在则从文件读取	,不存在则写入新的
Remark:			
*************************************/
void file_init(int flag)
{
	/*指定文件*/
    QFile filedcz("dcz.dat");
    QFile filescy("scy.dat");
    QFile fileord("ord.dat");
    QFile filefoo("foo.dat");
	/*数据结构清空*/
    all_DCZ.clear();
    all_orders.clear();
    all_food.clear();
    all_SCY.clear();

    if (!filedcz.exists()||flag == 1)
    {
		//点餐者重置
        filedcz.open(QIODevice::WriteOnly);//只读方式打开
        QDataStream stream(&filedcz);//二进制流控制
        QVector <int> order_id_list_tmp;//临时空订单列表
        stream << (quint32)0xB0E4D0B3;//文件签名magic number
        stream << (qint32)101;//文件版本号
        stream.setVersion(QDataStream::Qt_4_0);//定义读取qt版本,防止不同版本文件读取异常
        int size;//点餐者总数
		/*构建点餐者*/
        all_DCZ.push_back(DCZ("a","4124bc0a9335c27f086f24ba207a4912","BUPT X1",200,order_id_list_tmp,0));//aa
        all_DCZ.push_back(DCZ("bCHESTtlong","092409cc789fb1b8be960eca90dc64ae","luoyang",200,order_id_list_tmp,1));//bCHESTtlong houyi
        all_DCZ.push_back(DCZ("b","21ad0bd836b90d08f4cf640b4c298e7c","china",200,order_id_list_tmp,2));//bb
        all_DCZ.push_back(DCZ("c","e0323a9039add2978bf5b49550572c7c","china",200,order_id_list_tmp,3));//cc
        all_DCZ.push_back(DCZ("d","1aabac6d068eef6a7bad3fdf50a05cc8","china",200,order_id_list_tmp,4));//dd
        all_DCZ.push_back(DCZ("dogVliang","42fca52f4bef6d4b959a03800078e843","Beijing",200,order_id_list_tmp,5));//dogVliang e

        size = all_DCZ.size();
        stream << size;//在文件流中写入大小
        for (int i = 0; i < size;i++)
        {
            stream << all_DCZ[i];//将每个订餐者写入文件
        }
        filedcz.close();//关闭文件
    }
    else
    {
		//点餐者读取
        filedcz.open(QIODevice::ReadOnly);//只读方式打开
        QDataStream stream(&filedcz);//读入文件流
        int size;
        quint32 magic_num;
        qint32 version;
        stream >> magic_num;//获取签名
        stream >> version;//获取版本
        if (magic_num == 0xB0E4D0B3 && version == 101)
        {
			//文件正常
            stream >> size;//读入订餐者数
            DCZ tmp;
            for (int i = 0; i<size;i++)
            {
                stream >>tmp;//读入订餐者写入临时 点餐者空间
                all_DCZ.push_back(tmp);//放入全局点餐者列表
            }
        }
    }
    if (!filescy.exists()||flag == 1)
    {
		//送餐员重置
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
		//送餐员读取
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
		//订单重置
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
		//订单读取
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
		//食物重置
        filefoo.open(QIODevice::WriteOnly);
        QDataStream stream(&filefoo);
        stream << (quint32)0xB0E4D0B3;
        stream << (qint32)101;
        stream.setVersion(QDataStream::Qt_4_0);

#pragma region 随机生成菜品名+价格
        QVector<QString> name1,name2,name3;
        name1.push_back("香辣");
        name1.push_back("新奥尔良");
        name1.push_back("川香");
        name1.push_back("");
        name1.push_back("新至珍");
        name1.push_back("劲脆");
        name1.push_back("蘑菇芝士");
        name1.push_back("田园");
        name1.push_back("二块");
        name1.push_back("十块");
        name1.push_back("劲爆");
        name2.push_back("鸡翅");
        name2.push_back("烤翅");
        name2.push_back("原味鸡");
        name2.push_back("鸡米花");
        name2.push_back("上校鸡块");
        name2.push_back("鸡腿堡");
        name2.push_back("全虾堡");
        name2.push_back("牛卷餐");
        name2.push_back("鸡肉卷");
        name2.push_back("嫩牛卷");
        name2.push_back("奶茶");
        name2.push_back("豆浆甜");
        name2.push_back("可乐");
        name2.push_back("红茶");
        name2.push_back("（大）");
        name3.push_back("（中）");
        name3.push_back("（小）");
        name3.push_back("（特大）");
        name3.push_back("套餐");
        name3.push_back("");
        name3.push_back("");
        name3.push_back("");
        name3.push_back("");
        name3.push_back("饭");
        name3.push_back("套餐");
        name3.push_back("套餐");
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
#pragma endregion 随机生成菜品名

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
		//食物读取
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

