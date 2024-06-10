#include "../../include/menu/OrderMenu.h"
#include "../../include/Queue.h"
#include "../../include/Tree.h"
#include "../../include/Inventory.h"
#include <iostream>
#include <sstream>
#include <limits>

using namespace std;

void OrderMenu::displayOrderMenu(Queue &queue, std::string &currentCustomerName) {
    Tree menuTree;
    menuTree.addMenuItem("ayam");
    menuTree.addMenuItem("soda");
    menuTree.addMenuItem("burger");
    menuTree.addMenuItem("pasta");
    menuTree.addMenuItem("kentang goreng");
    menuTree.addMenuItem("es krim");

    Inventory inventory;

    if (currentCustomerName.empty()) {
        cout << "Masukkan Nama Pelanggan: ";
        cin >> currentCustomerName;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int choice;
    bool isOrderConfirmed = false;
    Order order;

    do {
        cout << "MENU MAKANAN/MINUMAN" << endl;
        menuTree.displayMenu();
        cout << "1. Tambah Pesanan" << endl;
        cout << "2. Hapus Pesanan" << endl;
        cout << "3. Review Pesanan" << endl;
        cout << "4. Konfirmasi Pesanan" << endl;
        cout << "5. Kembali ke Menu Awal" << endl;
        cout << "Pilihan: ";

        string input;
        getline(cin, input);
        stringstream(input) >> choice;

        string menuItem;
        int quantity;

        switch (choice) {
            case 1:
                cout << "Masukkan Nama Menu: ";
                getline(cin, menuItem);
                if (menuTree.findMenuItem(menuItem) != nullptr) {
                    cout << "Masukkan Jumlah: ";
                    getline(cin, input);
                    stringstream(input) >> quantity;
                    if (inventory.itemExists(menuItem)) {
                        if (inventory.getItemQuantity(menuItem) >= quantity) {
                            order = {currentCustomerName, menuItem, quantity};
                            queue.enqueue(order);
                            inventory.editItemQuantity(menuItem, inventory.getItemQuantity(menuItem) - quantity);
                        } else {
                            cout << "Stok tidak cukup!" << endl;
                        }
                    } else {
                        cout << "Menu tidak ditemukan di inventory!" << endl;
                    }
                } else {
                    cout << "Menu tidak ditemukan!" << endl;
                }
                break;
            case 2:
                queue.clearOrderHistory();
                break;
            case 3:
                queue.displayRecentOrder();
                break;
            case 4:
                if (!queue.isEmpty()) {
                    cout << "Apakah Anda yakin ingin konfirmasi pesanan? (y/n): ";
                    char confirm;
                    getline(cin, input);
                    stringstream(input) >> confirm;
                    if (confirm == 'y') {
                        isOrderConfirmed = true;
                        cout << "Pesanan Dikonfirmasi!" << endl;
                        currentCustomerName.clear();
                    } else {
                        cout << "Pesanan tidak dikonfirmasi." << endl;
                    }
                } else {
                    cout << "Tidak ada pesanan untuk dikonfirmasi." << endl;
                }
                break;
            case 5:
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (choice != 5 || !isOrderConfirmed);
}
