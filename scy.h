#ifndef SCY_H
#define SCY_H
#include "order.h"
#include "user.h"
class SCY : public User
{
public:
    SCY();
    void finish_delivery();
    void add_order(Order order_to_delive);
private:
    Order* delivering_order;
    QVector< Order >deliver_list;
    int order_count;
    int amount_count;
};

#endif // SCY_H
