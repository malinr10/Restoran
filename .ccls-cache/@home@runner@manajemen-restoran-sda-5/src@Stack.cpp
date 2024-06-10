#include <iostream>
#include "../include/Stack.h"

using namespace std;

void Stack::push(const Order &order) {
    orders.push(order);
}

void Stack::pop() {
    if (!orders.empty()) {
        orders.pop();
    }
}

Order Stack::top() {
    if (!orders.empty()) {
        return orders.top();
    }
    return {"", "", -1}; // Return invalid order if stack is empty
}

bool Stack::isEmpty() {
    return orders.empty();
}

void Stack::displayStack() {
    if (orders.empty()) {
        std::cout << "Belum ada pemesanan" << std::endl;
        return;
    }
    
    std::stack<Order> temp = orders;
    while (!temp.empty()) {
        std::cout << endl << "Nama Pelanggan: " << temp.top().customerName << endl
                  << "Menu: " << temp.top().menuItem << endl
                  << "Jumlah: " << temp.top().quantity << std::endl;
        temp.pop();
    }
}
