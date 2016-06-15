/********************************************************************************
** Form generated from reading UI file 'bosswindow.ui'
**
** Created: Wed Jun 15 18:20:40 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOSSWINDOW_H
#define UI_BOSSWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTableView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_bossWindow
{
public:
    QFrame *Under;
    QLabel *label_username;
    QFrame *frame_order;
    QLabel *label_3;
    QTableView *tableView_orders;
    QLCDNumber *lcdNumber_counter;
    QLCDNumber *lcdNumber_amount;
    QLabel *label;
    QLabel *label_2;
    QFrame *frame_menu;
    QTableView *tableView_menu;
    QLabel *label_5;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_add_menu;
    QSpinBox *spinBox_add_menu;
    QPushButton *pushButton_add_menu;
    QPushButton *pushButton_change;
    QFrame *frame_scy;
    QTableView *tableView_scy;
    QLabel *label_7;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_4;
    QLineEdit *lineEdit_uname;
    QLabel *label_8;
    QLineEdit *lineEdit_passwd;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QWidget *bossWindow)
    {
        if (bossWindow->objectName().isEmpty())
            bossWindow->setObjectName(QString::fromUtf8("bossWindow"));
        bossWindow->resize(735, 638);
        Under = new QFrame(bossWindow);
        Under->setObjectName(QString::fromUtf8("Under"));
        Under->setGeometry(QRect(0, 0, 735, 638));
        Under->setStyleSheet(QString::fromUtf8("#Under{\n"
"	border-image: url(:/image/uibBG.png);\n"
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
        frame_order->setEnabled(true);
        frame_order->setGeometry(QRect(10, 100, 711, 0));
        frame_order->setFrameShape(QFrame::StyledPanel);
        frame_order->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(frame_order);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 40, 131, 31));
        label_3->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 0);\n"
"font-weight:bold;\n"
"text-align:center;"));
        tableView_orders = new QTableView(frame_order);
        tableView_orders->setObjectName(QString::fromUtf8("tableView_orders"));
        tableView_orders->setGeometry(QRect(40, 90, 621, 401));
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
        frame_menu = new QFrame(Under);
        frame_menu->setObjectName(QString::fromUtf8("frame_menu"));
        frame_menu->setGeometry(QRect(10, 100, 711, 0));
        frame_menu->setFrameShape(QFrame::StyledPanel);
        frame_menu->setFrameShadow(QFrame::Raised);
        tableView_menu = new QTableView(frame_menu);
        tableView_menu->setObjectName(QString::fromUtf8("tableView_menu"));
        tableView_menu->setGeometry(QRect(37, 74, 621, 311));
        label_5 = new QLabel(frame_menu);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(40, 30, 161, 31));
        label_5->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 0);\n"
"font-weight:bold;\n"
"text-align:center;"));
        horizontalLayoutWidget = new QWidget(frame_menu);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(40, 410, 621, 71));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(23);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_add_menu = new QLineEdit(horizontalLayoutWidget);
        lineEdit_add_menu->setObjectName(QString::fromUtf8("lineEdit_add_menu"));

        horizontalLayout->addWidget(lineEdit_add_menu);

        spinBox_add_menu = new QSpinBox(horizontalLayoutWidget);
        spinBox_add_menu->setObjectName(QString::fromUtf8("spinBox_add_menu"));

        horizontalLayout->addWidget(spinBox_add_menu);

        pushButton_add_menu = new QPushButton(horizontalLayoutWidget);
        pushButton_add_menu->setObjectName(QString::fromUtf8("pushButton_add_menu"));

        horizontalLayout->addWidget(pushButton_add_menu);

        tableView_menu->raise();
        label_5->raise();
        horizontalLayoutWidget->raise();
        pushButton_change = new QPushButton(Under);
        pushButton_change->setObjectName(QString::fromUtf8("pushButton_change"));
        pushButton_change->setGeometry(QRect(680, 50, 31, 31));
        pushButton_change->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_change->setStyleSheet(QString::fromUtf8("\n"
"background-color:rgba(97%,80%,9%,0%);"));
        pushButton_change->setFlat(true);
        frame_scy = new QFrame(Under);
        frame_scy->setObjectName(QString::fromUtf8("frame_scy"));
        frame_scy->setGeometry(QRect(10, 100, 711, 521));
        frame_scy->setFrameShape(QFrame::StyledPanel);
        frame_scy->setFrameShadow(QFrame::Raised);
        tableView_scy = new QTableView(frame_scy);
        tableView_scy->setObjectName(QString::fromUtf8("tableView_scy"));
        tableView_scy->setGeometry(QRect(37, 74, 621, 291));
        label_7 = new QLabel(frame_scy);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(40, 30, 161, 31));
        label_7->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 0);\n"
"font-weight:bold;\n"
"text-align:center;"));
        formLayoutWidget = new QWidget(frame_scy);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(40, 410, 621, 97));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setHorizontalSpacing(54);
        formLayout->setVerticalSpacing(15);
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_4);

        lineEdit_uname = new QLineEdit(formLayoutWidget);
        lineEdit_uname->setObjectName(QString::fromUtf8("lineEdit_uname"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_uname);

        label_8 = new QLabel(formLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_8);

        lineEdit_passwd = new QLineEdit(formLayoutWidget);
        lineEdit_passwd->setObjectName(QString::fromUtf8("lineEdit_passwd"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_passwd);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        pushButton = new QPushButton(formLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_4->addWidget(pushButton);


        formLayout->setLayout(2, QFormLayout::FieldRole, horizontalLayout_4);

        frame_menu->raise();
        label_username->raise();
        frame_order->raise();
        lcdNumber_counter->raise();
        lcdNumber_amount->raise();
        label->raise();
        label_2->raise();
        pushButton_change->raise();
        frame_scy->raise();

        retranslateUi(bossWindow);

        QMetaObject::connectSlotsByName(bossWindow);
    } // setupUi

    void retranslateUi(QWidget *bossWindow)
    {
        bossWindow->setWindowTitle(QApplication::translate("bossWindow", "Form", 0, QApplication::UnicodeUTF8));
        label_username->setText(QApplication::translate("bossWindow", "USERNAME", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("bossWindow", "\350\256\242\345\215\225\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("bossWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221'; font-size:16pt; font-weight:600; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\345\267\262\351\200\201\345\207\272</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\350\256\242\345\215\225\346\225\260</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("bossWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221'; font-size:20pt; font-weight:600; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\350\256\242\345\215\225</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\346\200\273\351\207\221\351\242\235</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("bossWindow", "Menu", 0, QApplication::UnicodeUTF8));
        pushButton_add_menu->setText(QApplication::translate("bossWindow", "ADD", 0, QApplication::UnicodeUTF8));
        pushButton_change->setText(QString());
        label_7->setText(QApplication::translate("bossWindow", "\351\200\201\351\244\220\345\221\230", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("bossWindow", "\347\224\250\346\210\267\345\220\215", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("bossWindow", "\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("bossWindow", "ADD", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class bossWindow: public Ui_bossWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOSSWINDOW_H
