#include "bosswindow.h"
#include "ui_bosswindow.h"

bossWindow::bossWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::bossWindow)
{
    ui->setupUi(this);
}

bossWindow::~bossWindow()
{
    delete ui;
}
