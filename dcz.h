#ifndef DCZ_H
#define DCZ_H
#include "order.h"
#include "user.h"
class DCZ : public User
{
public:
    DCZ();
    void pay(int price);
    void finish_order();
    QString get_address();
private:
    int account;
    QString address;
    Order* userorder;
};

#endif // DCZ_H
