/********************************************************************************
** Form generated from reading UI file 'deliverwindow.ui'
**
** Created: Fri Dec 13 10:50:11 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELIVERWINDOW_H
#define UI_DELIVERWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_deliverwindow
{
public:
    QFrame *Under;
    QLabel *label_username;
    QFrame *frame_order;
    QTableView *tableView_ing;
    QLabel *label_3;
    QTableView *tableView_to;
    QLabel *label_4;
    QPushButton *pushButton_acc;
    QPushButton *pushButton_fin;
    QLCDNumber *lcdNumber_counter;
    QLCDNumber *lcdNumber_amount;
    QLabel *label;
    QLabel *label_2;
    QFrame *frame_view;
    QTableView *tableView_ed;
    QLabel *label_5;
    QPushButton *pushButton_change;

    void setupUi(QWidget *deliverwindow)
    {
        if (deliverwindow->objectName().isEmpty())
            deliverwindow->setObjectName(QString::fromUtf8("deliverwindow"));
        deliverwindow->resize(735, 638);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/18.png"), QSize(), QIcon::Normal, QIcon::Off);
        deliverwindow->setWindowIcon(icon);
        Under = new QFrame(deliverwindow);
        Under->setObjectName(QString::fromUtf8("Under"));
        Under->setGeometry(QRect(0, 0, 735, 638));
        Under->setStyleSheet(QString::fromUtf8("#Under{\n"
"	border-image: url(:/image/uidBG.png);\n"
"}"));
        Under->setFrameShape(QFrame::StyledPanel);
        Under->setFrameShadow(QFrame::Raised);
        label_username = new QLabel(Under);
        label_username->setObjectName(QString::fromUtf8("label_username"));
        label_username->setGeometry(QRect(100, 50, 151, 31));
        label_username->setStyleSheet(QString::fromUtf8("font: 20pt \"20thCenturyFont\";\n"
"color: rgb(255, 255, 255);\n"
"font-weight:bold;\n"
"text-align:center;"));
        frame_order = new QFrame(Under);
        frame_order->setObjectName(QString::fromUtf8("frame_order"));
        frame_order->setGeometry(QRect(7, 94, 711, 531));
        frame_order->setFrameShape(QFrame::StyledPanel);
        frame_order->setFrameShadow(QFrame::Raised);
        tableView_ing = new QTableView(frame_order);
        tableView_ing->setObjectName(QString::fromUtf8("tableView_ing"));
        tableView_ing->setGeometry(QRect(40, 92, 611, 71));
        label_3 = new QLabel(frame_order);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 43, 131, 31));
        label_3->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 0);\n"
"font-weight:bold;\n"
"text-align:center;"));
        tableView_to = new QTableView(frame_order);
        tableView_to->setObjectName(QString::fromUtf8("tableView_to"));
        tableView_to->setGeometry(QRect(40, 240, 611, 251));
        label_4 = new QLabel(frame_order);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 190, 131, 31));
        label_4->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 0);\n"
"font-weight:bold;\n"
"text-align:center;"));
        pushButton_acc = new QPushButton(frame_order);
        pushButton_acc->setObjectName(QString::fromUtf8("pushButton_acc"));
        pushButton_acc->setGeometry(QRect(300, 180, 161, 41));
        pushButton_acc->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 0);\n"
"font-weight:bold;\n"
"text-align:center;"));
        pushButton_fin = new QPushButton(frame_order);
        pushButton_fin->setObjectName(QString::fromUtf8("pushButton_fin"));
        pushButton_fin->setGeometry(QRect(490, 180, 161, 41));
        pushButton_fin->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 0);\n"
"font-weight:bold;\n"
"text-align:center;"));
        lcdNumber_counter = new QLCDNumber(Under);
        lcdNumber_counter->setObjectName(QString::fromUtf8("lcdNumber_counter"));
        lcdNumber_counter->setGeometry(QRect(360, 47, 101, 41));
        lcdNumber_counter->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lcdNumber_amount = new QLCDNumber(Under);
        lcdNumber_amount->setObjectName(QString::fromUtf8("lcdNumber_amount"));
        lcdNumber_amount->setGeometry(QRect(558, 47, 101, 41));
        lcdNumber_amount->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label = new QLabel(Under);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(270, 40, 91, 51));
        label->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);\n"
"font-weight:bold;\n"
"text-align:center;"));
        label_2 = new QLabel(Under);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(470, 40, 91, 51));
        label_2->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);\n"
"font-weight:bold;\n"
"text-align:center;"));
        frame_view = new QFrame(Under);
        frame_view->setObjectName(QString::fromUtf8("frame_view"));
        frame_view->setGeometry(QRect(10, 100, 711, 521));
        frame_view->setFrameShape(QFrame::StyledPanel);
        frame_view->setFrameShadow(QFrame::Raised);
        tableView_ed = new QTableView(frame_view);
        tableView_ed->setObjectName(QString::fromUtf8("tableView_ed"));
        tableView_ed->setGeometry(QRect(37, 84, 621, 401));
        label_5 = new QLabel(frame_view);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(40, 30, 161, 31));
        label_5->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 0);\n"
"font-weight:bold;\n"
"text-align:center;"));
        pushButton_change = new QPushButton(Under);
        pushButton_change->setObjectName(QString::fromUtf8("pushButton_change"));
        pushButton_change->setGeometry(QRect(680, 50, 31, 31));
        pushButton_change->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_change->setStyleSheet(QString::fromUtf8("\n"
"background-color:rgba(97%,80%,9%,0%);"));
        pushButton_change->setFlat(true);
        frame_view->raise();
        label_username->raise();
        frame_order->raise();
        lcdNumber_counter->raise();
        lcdNumber_amount->raise();
        label->raise();
        label_2->raise();
        pushButton_change->raise();

        retranslateUi(deliverwindow);

        QMetaObject::connectSlotsByName(deliverwindow);
    } // setupUi

    void retranslateUi(QWidget *deliverwindow)
    {
        deliverwindow->setWindowTitle(QApplication::translate("deliverwindow", "Form", 0, QApplication::UnicodeUTF8));
        label_username->setText(QApplication::translate("deliverwindow", "USERNAME", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("deliverwindow", "\345\275\223\345\211\215\350\256\242\345\215\225", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("deliverwindow", "\345\276\205\351\200\201\350\256\242\345\215\225", 0, QApplication::UnicodeUTF8));
        pushButton_acc->setText(QApplication::translate("deliverwindow", "\346\216\245\345\217\227\350\256\242\345\215\225\342\206\221", 0, QApplication::UnicodeUTF8));
        pushButton_fin->setText(QApplication::translate("deliverwindow", "\345\256\214\346\210\220\351\205\215\351\200\201\342\206\222", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("deliverwindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221'; font-size:16pt; font-weight:600; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\345\267\262\351\200\201\345\207\272</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\350\256\242\345\215\225\346\225\260</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("deliverwindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221'; font-size:20pt; font-weight:600; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\350\256\242\345\215\225</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\346\200\273\351\207\221\351\242\235</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("deliverwindow", "\345\267\262\345\256\214\346\210\220\350\256\242\345\215\225", 0, QApplication::UnicodeUTF8));
        pushButton_change->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class deliverwindow: public Ui_deliverwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELIVERWINDOW_H
