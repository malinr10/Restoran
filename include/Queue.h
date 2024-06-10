#ifndef QUEUE_H
#define QUEUE_H

#include <queue>
#include <string>

struct Order {
  std::string customerName;
  std::string menuItem;
  int quantity;
};

class Queue {
public:
  void enqueue(const Order &order);
  void dequeue();
  void dequeueByCustomer(const std::string &customerName);
  Order front();
  bool isEmpty();
  void displayQueue();
  void displayRecentOrder();
  void clearOrderHistory();
  

private:
  std::queue<Order> orders;
  std::vector<Order> orderHistory;

};

#endif
