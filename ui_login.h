/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created: Wed Jun 15 18:17:47 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QFrame *Under;
    QLineEdit *Editline_Username;
    QLineEdit *Editline_Password;
    QPushButton *Pushbutton_Login;
    QFrame *Frame_error;
    QPushButton *pushButton;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(468, 397);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/11.png"), QSize(), QIcon::Normal, QIcon::Off);
        Login->setWindowIcon(icon);
        Under = new QFrame(Login);
        Under->setObjectName(QString::fromUtf8("Under"));
        Under->setGeometry(QRect(0, 0, 468, 397));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 0));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        Under->setPalette(palette);
        Under->setStyleSheet(QString::fromUtf8("#Under{\n"
"	border-image: url(:/image/LoginBG.png);\n"
"}"));
        Under->setFrameShape(QFrame::StyledPanel);
        Under->setFrameShadow(QFrame::Raised);
        Editline_Username = new QLineEdit(Under);
        Editline_Username->setObjectName(QString::fromUtf8("Editline_Username"));
        Editline_Username->setGeometry(QRect(78, 197, 311, 31));
        Editline_Username->setStyleSheet(QString::fromUtf8("font: 63 11pt \"Segoe UI Semibold\";\n"
"color: rgb(66,61,65);\n"
"background-color:rgba(97%,80%,9%,0%);"));
        Editline_Username->setFrame(false);
        Editline_Password = new QLineEdit(Under);
        Editline_Password->setObjectName(QString::fromUtf8("Editline_Password"));
        Editline_Password->setGeometry(QRect(77, 263, 311, 31));
        Editline_Password->setStyleSheet(QString::fromUtf8("font: 63 11pt \"Segoe UI Semibold\";\n"
"color: rgb(66,61,65);\n"
"background-color:rgba(97%,80%,9%,0%);"));
        Editline_Password->setFrame(false);
        Pushbutton_Login = new QPushButton(Under);
        Pushbutton_Login->setObjectName(QString::fromUtf8("Pushbutton_Login"));
        Pushbutton_Login->setGeometry(QRect(169, 303, 111, 41));
        Pushbutton_Login->setCursor(QCursor(Qt::PointingHandCursor));
        Pushbutton_Login->setStyleSheet(QString::fromUtf8("\n"
"background-color:rgba(97%,80%,9%,0%);"));
        Pushbutton_Login->setFlat(true);
        Frame_error = new QFrame(Under);
        Frame_error->setObjectName(QString::fromUtf8("Frame_error"));
        Frame_error->setGeometry(QRect(70, 102, 325, 48));
        Frame_error->setStyleSheet(QString::fromUtf8("border-image: url(:/image/login_Error.png);"));
        Frame_error->setFrameShape(QFrame::StyledPanel);
        Frame_error->setFrameShadow(QFrame::Raised);
        pushButton = new QPushButton(Under);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(110, 60, 31, 31));
        pushButton->setStyleSheet(QString::fromUtf8("\n"
"background-color:rgba(97%,80%,9%,0%);"));
        pushButton->setFlat(true);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Login", 0, QApplication::UnicodeUTF8));
        Editline_Username->setText(QString());
        Editline_Password->setText(QString());
        Pushbutton_Login->setText(QString());
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
