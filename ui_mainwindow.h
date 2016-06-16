/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Jun 16 10:49:25 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_username;
    QFrame *Under;
    QFrame *frame_user_order;
    QTableView *tableView_menu;
    QFrame *frame_user_view;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_Usrname_check;
    QLabel *label_address_check;
    QLabel *label_order_state;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit_chongzhi;
    QPushButton *pushButton_chongzhi;
    QLabel *label_chongzhi;
    QLabel *label_7;
    QLabel *label_scyname;
    QPushButton *pushButton_cancel;
    QPushButton *pushButton_urgent;
    QLabel *label_urgent;
    QTableView *tableView_Food_ordered;
    QLCDNumber *lcdNumber_order_amount;
    QLabel *label_2;
    QLabel *label_user_account;
    QPushButton *pushButton_change;
    QLabel *label;
    QPushButton *pushButton_order;
    QPushButton *pushButton_check;
    QFrame *leftFrame;
    QGraphicsView *graphicsView_leftblock;
    QFrame *frame_detial;
    QLabel *label_food_detial;
    QLabel *label_food_rate;
    QTextBrowser *textBrowser_food_detil;
    QGraphicsView *graphicsView;
    QPushButton *pushButton;
    QLabel *label_succ;
    QLabel *label_Fail;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(735, 638);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/9.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("#centralwidget{\n"
"	border-image: url(:/image/uiBG.png);\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_username = new QLabel(centralwidget);
        label_username->setObjectName(QString::fromUtf8("label_username"));
        label_username->setGeometry(QRect(100, 50, 151, 31));
        label_username->setStyleSheet(QString::fromUtf8("font: 20pt \"20thCenturyFont\";\n"
"color: rgb(255, 255, 255);\n"
"font-weight:bold;\n"
"text-align:center;"));
        Under = new QFrame(centralwidget);
        Under->setObjectName(QString::fromUtf8("Under"));
        Under->setGeometry(QRect(0, 0, 735, 638));
        Under->setFrameShape(QFrame::StyledPanel);
        Under->setFrameShadow(QFrame::Raised);
        frame_user_order = new QFrame(Under);
        frame_user_order->setObjectName(QString::fromUtf8("frame_user_order"));
        frame_user_order->setGeometry(QRect(4, 0, 721, 631));
        frame_user_order->setFrameShape(QFrame::StyledPanel);
        frame_user_order->setFrameShadow(QFrame::Raised);
        tableView_menu = new QTableView(frame_user_order);
        tableView_menu->setObjectName(QString::fromUtf8("tableView_menu"));
        tableView_menu->setEnabled(true);
        tableView_menu->setGeometry(QRect(40, 121, 372, 471));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableView_menu->sizePolicy().hasHeightForWidth());
        tableView_menu->setSizePolicy(sizePolicy);
        tableView_menu->setFrameShape(QFrame::WinPanel);
        tableView_menu->setFrameShadow(QFrame::Raised);
        tableView_menu->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView_menu->setShowGrid(true);
        tableView_menu->setSortingEnabled(false);
        tableView_menu->setCornerButtonEnabled(false);
        frame_user_view = new QFrame(Under);
        frame_user_view->setObjectName(QString::fromUtf8("frame_user_view"));
        frame_user_view->setGeometry(QRect(20, 99, 701, 521));
        frame_user_view->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 0);\n"
"\n"
"text-align:center;"));
        frame_user_view->setFrameShape(QFrame::StyledPanel);
        frame_user_view->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(frame_user_view);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 20, 120, 50));
        label_4 = new QLabel(frame_user_view);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 85, 120, 51));
        label_Usrname_check = new QLabel(frame_user_view);
        label_Usrname_check->setObjectName(QString::fromUtf8("label_Usrname_check"));
        label_Usrname_check->setGeometry(QRect(170, 20, 241, 50));
        label_address_check = new QLabel(frame_user_view);
        label_address_check->setObjectName(QString::fromUtf8("label_address_check"));
        label_address_check->setGeometry(QRect(170, 95, 231, 51));
        label_address_check->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_address_check->setWordWrap(true);
        label_order_state = new QLabel(frame_user_view);
        label_order_state->setObjectName(QString::fromUtf8("label_order_state"));
        label_order_state->setGeometry(QRect(170, 160, 231, 41));
        label_order_state->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_order_state->setWordWrap(true);
        label_5 = new QLabel(frame_user_view);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 150, 120, 51));
        label_6 = new QLabel(frame_user_view);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 310, 120, 51));
        lineEdit_chongzhi = new QLineEdit(frame_user_view);
        lineEdit_chongzhi->setObjectName(QString::fromUtf8("lineEdit_chongzhi"));
        lineEdit_chongzhi->setGeometry(QRect(30, 380, 371, 31));
        lineEdit_chongzhi->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        pushButton_chongzhi = new QPushButton(frame_user_view);
        pushButton_chongzhi->setObjectName(QString::fromUtf8("pushButton_chongzhi"));
        pushButton_chongzhi->setGeometry(QRect(270, 320, 131, 31));
        label_chongzhi = new QLabel(frame_user_view);
        label_chongzhi->setObjectName(QString::fromUtf8("label_chongzhi"));
        label_chongzhi->setGeometry(QRect(30, 440, 371, 31));
        label_chongzhi->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        label_7 = new QLabel(frame_user_view);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 220, 131, 51));
        label_scyname = new QLabel(frame_user_view);
        label_scyname->setObjectName(QString::fromUtf8("label_scyname"));
        label_scyname->setGeometry(QRect(170, 230, 231, 41));
        label_scyname->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_scyname->setWordWrap(true);
        pushButton_cancel = new QPushButton(frame_user_view);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(294, 162, 101, 31));
        pushButton_urgent = new QPushButton(frame_user_view);
        pushButton_urgent->setObjectName(QString::fromUtf8("pushButton_urgent"));
        pushButton_urgent->setGeometry(QRect(290, 230, 101, 31));
        label_urgent = new QLabel(frame_user_view);
        label_urgent->setObjectName(QString::fromUtf8("label_urgent"));
        label_urgent->setGeometry(QRect(170, 270, 91, 21));
        tableView_Food_ordered = new QTableView(Under);
        tableView_Food_ordered->setObjectName(QString::fromUtf8("tableView_Food_ordered"));
        tableView_Food_ordered->setGeometry(QRect(450, 120, 251, 251));
        tableView_Food_ordered->setFrameShape(QFrame::WinPanel);
        tableView_Food_ordered->setFrameShadow(QFrame::Raised);
        lcdNumber_order_amount = new QLCDNumber(Under);
        lcdNumber_order_amount->setObjectName(QString::fromUtf8("lcdNumber_order_amount"));
        lcdNumber_order_amount->setGeometry(QRect(450, 450, 251, 51));
        lcdNumber_order_amount->setSmallDecimalPoint(false);
        lcdNumber_order_amount->setNumDigits(7);
        lcdNumber_order_amount->setDigitCount(7);
        label_2 = new QLabel(Under);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(290, 49, 161, 31));
        label_2->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);\n"
"font-weight:bold;\n"
"text-align:center;"));
        label_user_account = new QLabel(Under);
        label_user_account->setObjectName(QString::fromUtf8("label_user_account"));
        label_user_account->setGeometry(QRect(460, 50, 191, 31));
        label_user_account->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);\n"
"font-weight:bold;\n"
"text-align:center;"));
        pushButton_change = new QPushButton(Under);
        pushButton_change->setObjectName(QString::fromUtf8("pushButton_change"));
        pushButton_change->setGeometry(QRect(679, 50, 31, 31));
        pushButton_change->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_change->setStyleSheet(QString::fromUtf8("\n"
"background-color:rgba(97%,80%,9%,0%);"));
        pushButton_change->setFlat(true);
        label = new QLabel(Under);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(450, 390, 211, 51));
        label->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 0);\n"
"font-weight:bold;\n"
"text-align:center;"));
        pushButton_order = new QPushButton(Under);
        pushButton_order->setObjectName(QString::fromUtf8("pushButton_order"));
        pushButton_order->setGeometry(QRect(450, 530, 251, 61));
        pushButton_order->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 0);\n"
"font-weight:bold;\n"
"text-align:center;"));
        pushButton_check = new QPushButton(Under);
        pushButton_check->setObjectName(QString::fromUtf8("pushButton_check"));
        pushButton_check->setGeometry(QRect(450, 530, 251, 61));
        pushButton_check->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 0);\n"
"font-weight:bold;\n"
"text-align:center;"));
        leftFrame = new QFrame(Under);
        leftFrame->setObjectName(QString::fromUtf8("leftFrame"));
        leftFrame->setGeometry(QRect(7, 94, 716, 531));
        leftFrame->setStyleSheet(QString::fromUtf8(""));
        leftFrame->setFrameShape(QFrame::StyledPanel);
        leftFrame->setFrameShadow(QFrame::Raised);
        graphicsView_leftblock = new QGraphicsView(leftFrame);
        graphicsView_leftblock->setObjectName(QString::fromUtf8("graphicsView_leftblock"));
        graphicsView_leftblock->setGeometry(QRect(-3, -2, 281, 542));
        graphicsView_leftblock->setStyleSheet(QString::fromUtf8("border-image: url(:/image/leftBG.png);"));
        frame_detial = new QFrame(leftFrame);
        frame_detial->setObjectName(QString::fromUtf8("frame_detial"));
        frame_detial->setGeometry(QRect(20, 100, 241, 421));
        frame_detial->setFrameShape(QFrame::StyledPanel);
        frame_detial->setFrameShadow(QFrame::Raised);
        label_food_detial = new QLabel(frame_detial);
        label_food_detial->setObjectName(QString::fromUtf8("label_food_detial"));
        label_food_detial->setGeometry(QRect(0, 0, 251, 51));
        label_food_detial->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);\n"
"font-weight:bold;\n"
"text-align:center;"));
        label_food_detial->setFrameShape(QFrame::NoFrame);
        label_food_rate = new QLabel(frame_detial);
        label_food_rate->setObjectName(QString::fromUtf8("label_food_rate"));
        label_food_rate->setGeometry(QRect(0, 70, 91, 61));
        label_food_rate->setStyleSheet(QString::fromUtf8("font: 25pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 108, 15);\n"
"font-weight:bold;\n"
"text-align:center;"));
        label_food_rate->setTextFormat(Qt::PlainText);
        label_food_rate->setScaledContents(false);
        label_food_rate->setMargin(3);
        label_food_rate->setIndent(-1);
        textBrowser_food_detil = new QTextBrowser(frame_detial);
        textBrowser_food_detil->setObjectName(QString::fromUtf8("textBrowser_food_detil"));
        textBrowser_food_detil->setGeometry(QRect(0, 210, 241, 201));
        textBrowser_food_detil->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 0);\n"
"text-align:center;"));
        textBrowser_food_detil->setFrameShape(QFrame::Box);
        textBrowser_food_detil->setFrameShadow(QFrame::Raised);
        graphicsView = new QGraphicsView(leftFrame);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 1, 1));
        graphicsView->setStyleSheet(QString::fromUtf8("border-image: url(:/image/block.png);"));
        pushButton = new QPushButton(leftFrame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(0, 0, 750, 700));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/image/block.png);"));
        pushButton->setFlat(true);
        pushButton->raise();
        graphicsView_leftblock->raise();
        frame_detial->raise();
        graphicsView->raise();
        label_succ = new QLabel(Under);
        label_succ->setObjectName(QString::fromUtf8("label_succ"));
        label_succ->setGeometry(QRect(530, 50, 131, 31));
        label_succ->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(250, 204, 59);\n"
"font-weight:bold;\n"
"text-align:center;"));
        label_Fail = new QLabel(Under);
        label_Fail->setObjectName(QString::fromUtf8("label_Fail"));
        label_Fail->setGeometry(QRect(530, 50, 131, 31));
        label_Fail->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(50, 93, 153);\n"
"font-weight:bold;\n"
"text-align:center;"));
        frame_user_order->raise();
        frame_user_view->raise();
        tableView_Food_ordered->raise();
        lcdNumber_order_amount->raise();
        label_2->raise();
        label_user_account->raise();
        pushButton_change->raise();
        label->raise();
        pushButton_order->raise();
        pushButton_check->raise();
        label_succ->raise();
        label_Fail->raise();
        leftFrame->raise();
        MainWindow->setCentralWidget(centralwidget);
        Under->raise();
        label_username->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label_username->setText(QApplication::translate("MainWindow", "USERNAME", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "UserName", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Address", 0, QApplication::UnicodeUTF8));
        label_Usrname_check->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_address_check->setText(QApplication::translate("MainWindow", "jaskldjfljaskdlfjkdasdasdasd", 0, QApplication::UnicodeUTF8));
        label_order_state->setText(QApplication::translate("MainWindow", "\350\256\242\345\215\225\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Order State", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\345\205\205\345\200\274", 0, QApplication::UnicodeUTF8));
        lineEdit_chongzhi->setText(QString());
        pushButton_chongzhi->setText(QApplication::translate("MainWindow", "\347\202\271\345\207\273\345\205\205\345\200\274", 0, QApplication::UnicodeUTF8));
        label_chongzhi->setText(QApplication::translate("MainWindow", "\345\205\205\345\200\274\345\244\261\350\264\245\357\274\201\350\257\267\350\276\223\345\205\245\351\225\277\345\272\246\344\270\2728\344\275\215\347\232\204\345\205\205\345\200\274\345\215\241\345\257\206\347\240\201\357\274\201", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "\345\210\206\351\205\215\351\200\201\351\244\220\345\221\230", 0, QApplication::UnicodeUTF8));
        label_scyname->setText(QApplication::translate("MainWindow", "\350\256\242\345\215\225\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        pushButton_cancel->setText(QApplication::translate("MainWindow", "\351\200\200\345\215\225", 0, QApplication::UnicodeUTF8));
        pushButton_urgent->setText(QApplication::translate("MainWindow", "\345\202\254\345\215\225", 0, QApplication::UnicodeUTF8));
        label_urgent->setText(QApplication::translate("MainWindow", "\345\267\262\345\202\254\345\215\225", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "\350\264\246\346\210\267\344\275\231\351\242\235\357\274\232\357\277\245", 0, QApplication::UnicodeUTF8));
        label_user_account->setText(QApplication::translate("MainWindow", "200", 0, QApplication::UnicodeUTF8));
        pushButton_change->setText(QString());
        label->setText(QApplication::translate("MainWindow", "\350\256\242\345\215\225\346\200\273\351\207\221\351\242\235", 0, QApplication::UnicodeUTF8));
        pushButton_order->setText(QApplication::translate("MainWindow", "\344\270\213\345\215\225", 0, QApplication::UnicodeUTF8));
        pushButton_check->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        label_food_detial->setText(QApplication::translate("MainWindow", "\351\244\220\345\223\201\345\220\215", 0, QApplication::UnicodeUTF8));
        label_food_rate->setText(QApplication::translate("MainWindow", "4.7", 0, QApplication::UnicodeUTF8));
        textBrowser_food_detil->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221'; font-size:20pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:15pt;\">\345\245\275\350\257\204\345\246\202\346\275\256</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QString());
        label_succ->setText(QApplication::translate("MainWindow", "\344\270\213\345\215\225\346\210\220\345\212\237", 0, QApplication::UnicodeUTF8));
        label_Fail->setText(QApplication::translate("MainWindow", "\344\275\231\351\242\235\344\270\215\350\266\263", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
