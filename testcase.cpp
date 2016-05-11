#include "testcase.h"
#include <QtTest/QtTest>
#include "datastruct.h"
#include "login.h"

TestCase::TestCase(QObject *parent) :
    QObject(parent)
{

}

//void TestCase::toUpper()
//{
////    Login* a =new Login;
////    QVERIFY(1 == *a->User_check ("a","a"));
//}

//void TestCase::testGui()
//{
//    QLineEdit lineEdit;

//    QTest::keyClicks(&lineEdit, "!hello world");

//    QCOMPARE(lineEdit.text(), QString("hello world"));
//}
//void TestCase::initTestCase()
//    { qDebug("called before everything else"); }
void TestCase::initTestCase()
    { QVERIFY(1 == 2); }
    void TestCase::myFirstTest()
    { QVERIFY(1 == 1); }
    void TestCase::mySecondTest()
    { QVERIFY(1 == 2); }
    void TestCase::cleanupTestCase()
    { qDebug("called222222222222222222222222222222222222222222222222222222222222222222222222"); }

