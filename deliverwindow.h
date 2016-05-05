#ifndef DELIVERWINDOW_H
#define DELIVERWINDOW_H

#include <QWidget>

namespace Ui {
class deliverwindow;
}

class deliverwindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit deliverwindow(QWidget *parent = 0);
    ~deliverwindow();
    
private:
    Ui::deliverwindow *ui;
    void deliverwindow::set_view_ing();
    void deliverwindow::set_view_to();
    void deliverwindow::set_view_ed();
private slots:
        void wind_close();
        void on_pushButton_acc_clicked();
        void on_pushButton_fin_clicked();
        void on_pushButton_change_clicked();
};

#endif // DELIVERWINDOW_H
