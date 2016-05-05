#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT
    
public:
    explicit Login(QWidget *parent = 0);
int Login::User_check (QString username,QString password);
    ~Login();

private slots:
    void on_Pushbutton_Login_clicked();
    void hideerror ();

    void on_Editline_Username_editingFinished();

    void on_Editline_Password_editingFinished();

    void on_pushButton_clicked();
    void wind_close();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
