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
    explicit bossWindow(QWidget *parent = 0);
    ~bossWindow();
    
private:
    Ui::bossWindow *ui;
    QTimer *timer;

private slots:

    void wind_close();
    void on_tableView_menu_doubleClicked(const QModelIndex &index);


    void on_pushButton_add_menu_clicked();
};



#endif // BOSSWINDOW_H
