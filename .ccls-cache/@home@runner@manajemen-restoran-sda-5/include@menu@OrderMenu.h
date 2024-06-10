#ifndef ORDER_MENU_H
#define ORDER_MENU_H

#include "../Queue.h"
#include <iostream>
#include <vector>

class OrderMenu {
public:
   static void displayOrderMenu(Queue &queue, std::string &currentCustomerName);
};

#endif 
