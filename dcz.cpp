#include "dcz.h"

DCZ::DCZ()
{
}
void DCZ::pay(int price)
{
    this->account-=price;
}

void DCZ::finish_order()
{

}

QString DCZ::get_address()
{
    return this->address;
}
