#ifndef TESTCASE_H
#define TESTCASE_H

#include <QObject>
#include <QtGui>
#include <QtTest/QtTest>

class TestCase : public QObject
{
    Q_OBJECT
public:
    explicit TestCase(QObject *parent = 0);
    
signals:
    
public slots:
//    void initTestCase();
    void initTestCase();
    void myFirstTest();

    void mySecondTest();

    void cleanupTestCase();

    
};

#endif // TESTCASE_H
