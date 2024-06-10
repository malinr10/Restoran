#include "../include/Queue.h"
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void Queue::enqueue(const Order &order) { orders.push(order); orderHistory.push_back(order); }

void Queue::dequeue() {
  if (!orders.empty()) {
    std::string customerName = orders.front().customerName;
    dequeueByCustomer(customerName);
  }
}
void Queue::clearOrderHistory() {
    orderHistory.clear();
    while (!orders.empty()) {
        orders.pop();
    }
    cout << "Riwayat pesanan berhasil dihapus." << endl;
}

void Queue::displayRecentOrder() {
  if (orderHistory.empty()) {
    std::cout << "Tidak ada pesanan yang tersedia." << std::endl;
    return;
  }

  // Ambil nama pelanggan dari pesanan terakhir
  std::string latestCustomer = orderHistory.back().customerName;
  std::vector<Order> latestOrders;

  for (const auto &order : orderHistory) {
    if (order.customerName == latestCustomer) {
        latestOrders.push_back(order);
    }
  }

  if (!latestOrders.empty()) {
    std::cout << "Nama Pelanggan: " << latestCustomer << std::endl;
    for (const auto &order : latestOrders) {
        std::cout << "Menu: " << order.menuItem << std::endl;
        std::cout << "Jumlah: " << order.quantity << std::endl;
    }
    std::cout << std::endl;
  } else {
    std::cout << "Tidak ada pesanan untuk pelanggan terbaru." << std::endl;
  }
}

void Queue::dequeueByCustomer(const std::string &customerName) {
  std::queue<Order> temp;
  while (!orders.empty()) {
    Order order = orders.front();
    orders.pop();
    if (order.customerName != customerName) {
      temp.push(order);
    }
  }
  std::swap(orders, temp);
}

Order Queue::front() {
  if (!orders.empty()) {
    return orders.front();
  }
  return {"", "", -1};
}

bool Queue::isEmpty() { return orders.empty(); }

void Queue::displayQueue() {
  std::unordered_map<std::string, std::vector<Order>> groupedOrders;
  std::queue<Order> temp = orders;

  while (!temp.empty()) {
    Order order = temp.front();
    groupedOrders[order.customerName].push_back(order);
    temp.pop();
  }

  for (const auto &entry : groupedOrders) {
    std::cout << "Nama: " << entry.first << std::endl;
    for (const auto &order : entry.second) {
      std::cout << "Menu: " << order.menuItem << std::endl;
      std::cout << "Jumlah: " << order.quantity << std::endl;
      std::cout << std::endl;
    }
  }
}