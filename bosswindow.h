#ifndef BOSSWINDOW_H
#define BOSSWINDOW_H

#include <QWidget>
#include <QTableView>

namespace Ui {
class bossWindow;
}

class bossWindow : public QWidget
{
    Q_OBJECT
    
public:
    void bossWindow::leftShow();
    void bossWindow::leftHide();
    void bossWindow::set_foodlist();
    void bossWindow::set_view_to();
    void bossWindow::set_view_orders();
    explicit bossWindow(QWidget *parent = 0);
    ~bossWindow();
    
private:
    Ui::bossWindow *ui;

private slots:

    void wind_close();
    void on_tableView_menu_doubleClicked(const QModelIndex &index);


    void on_pushButton_add_menu_clicked();
    void on_pushButton_change_clicked();
    void on_frame_order_destroyed();
};



#endif // BOSSWINDOW_H
