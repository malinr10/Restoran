#include <iostream>
#include "../../include/menu/DisplayOrdersMenu.h"
#include "../../include/Queue.h"
#include <unordered_map>
#include <vector>

using namespace std;

void DisplayOrdersMenu::displayOrdersMenu(Queue &queue, std::string &currentCustomerName) {
    int choice;
    do {
        cout << "PESANAN YANG SEDANG BERJALAN" << endl;
        cout << "1. Tampilkan Semua Pesanan" << endl;
        cout << "2. Hapus Pesanan Pertama" << endl;
        cout << "3. Kembali ke Menu Awal" << endl;
        cout << "Pilihan: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                queue.displayQueue();
                break;
            }
            case 2:
                queue.dequeue();
                break;
            case 3:
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (choice != 3);
}
