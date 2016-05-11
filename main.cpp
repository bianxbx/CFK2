#include <QtGui/QApplication>
#include <QTextCodec>
#include "login.h"
#include "mainwindow.h"
#include "datastruct.h"
#include "init.h"
#include "deliverwindow.h"
#include "testcase.h"
#include <QtTest/QtTest>
#include <QDebug>

int main(int argc, char *argv[])
{
    qDebug() << "Test start";
    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));

    TestCase tc;

    QTest::qExec(&tc,argc,argv);

    qDebug() << "Test end";

    initial();//��ʼ��ϵͳ
    Login w;
    w.show();//��½����ʾ
//    customerwindow b;
//    deliverwindow c;

//    b.show();
//    c.show();
    
    return a.exec();
}
