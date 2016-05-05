#include <QtGui/QApplication>
#include <QTextCodec>
#include "login.h"
#include "mainwindow.h"
#include "datastruct.h"
#include "init.h"
#include "deliverwindow.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));

    initial();//��ʼ��ϵͳ
    Login w;
    w.show();//��½����ʾ
//    customerwindow b;
//    deliverwindow c;

//    b.show();
//    c.show();
    
    return a.exec();
}
