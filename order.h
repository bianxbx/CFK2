#ifndef ORDER_H
#define ORDER_H
#include <QVector>
#include <QString>
class Order
{
public:
    Order();
    void additem();
    void set_deliver();
    void show_order();
private:
    QVector< QVector <int> >item;
    int total_amount;
    bool state;
    QString DCZ_address;
};

#endif // ORDER_H
