#ifndef BOSSWINDOW_H
#define BOSSWINDOW_H

#include <QWidget>

namespace Ui {
class bossWindow;
}

class bossWindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit bossWindow(QWidget *parent = 0);
    ~bossWindow();
    
private:
    Ui::bossWindow *ui;
};

#endif // BOSSWINDOW_H
