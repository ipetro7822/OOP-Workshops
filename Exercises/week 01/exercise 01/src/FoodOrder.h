#ifndef SENECA_FOODORDER_H
#define SENECA_FOODORDER_H

#include <iostream>

extern double g_taxrate;
extern double g_dailydiscount;

namespace seneca
{
    class FoodOrder
    {
        char m_customerName[10]{};
        char *m_orderDesc{};
        double m_price{};   
        bool m_dailySpecial{};

    public:
        void read(std::istream &is);
        void display();
        FoodOrder(){};
        FoodOrder(const FoodOrder& src);
        FoodOrder& operator=(const FoodOrder& src);
        ~FoodOrder();

    };
} // namespace seneca

#endif