#include "../include/Menu.h"
#include "../include/menu/DisplayOrdersMenu.h"
#include "../include/menu/InventoryMenu.h"
#include "../include/menu/OrderMenu.h"
#include "../include/Queue.h"
#include <iostream>

using namespace std;

void Menu::displayMenu() {
  Queue orderQueue;  // Instansiasi objek Queue
  string currentCustomerName; 
  int choice;
  do {
    cout << "=============================" << endl;
    cout << "MENU APLIKASI" << endl;
    cout << "=============================" << endl;
    cout << "1. Inventaris Stok Menu Barang" << endl;
    cout << "2. Input Pemesanan" << endl;
    cout << "3. Tampilkan Pesanan yang sedang berjalan" << endl;
    cout << "4. Tutup Aplikasi" << endl;
    cout << "Pilihan: ";
    cin >> choice;

    switch (choice) {
    case 1:
      InventoryMenu::displayInventoryMenu();
      break;
    case 2:
      OrderMenu::displayOrderMenu(orderQueue, currentCustomerName);
      break;
    case 3:
      DisplayOrdersMenu::displayOrdersMenu(orderQueue, currentCustomerName);
      break;
    case 4:
      cout << "Tutup Aplikasi." << endl;
      break;
    default:
      cout << "Pilihan tidak valid!" << endl;
    }
  } while (choice != 4);
}
