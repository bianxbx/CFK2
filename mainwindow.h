#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>

namespace Ui {
class MainWindow;
}

class customerwindow : public QMainWindow
{
    Q_OBJECT
    
public:
    void customerwindow::leftShow();
    void customerwindow::leftHide();
    void customerwindow::set_foodlist();
    void customerwindow::set_view_to();
    explicit customerwindow(QWidget *parent = 0);
    ~customerwindow();
    
private slots:
    void hideview ();
    void showview ();

    void wind_close();
    void on_tableView_menu_doubleClicked(const QModelIndex &index);

    void on_tableView_Food_ordered_doubleClicked(const QModelIndex &index);

    void on_pushButton_order_clicked();

    void on_pushButton_change_clicked();

    void on_pushButton_check_clicked();

    void on_pushButton_clicked();

    void on_tableView_menu_clicked(const QModelIndex &index);
    void show_detial();

    void on_pushButton_chongzhi_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
};

#endif // MAINWINDOW_H
