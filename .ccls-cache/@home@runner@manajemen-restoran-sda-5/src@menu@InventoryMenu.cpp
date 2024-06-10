#include <iostream>
#include <limits>
#include "../../include/menu/InventoryMenu.h"
#include "../../include/Inventory.h"

using namespace std;

class InventoryException : public std::exception {
    string message;
public:
    InventoryException(const string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

void InventoryMenu::displayInventoryMenu() {
    Inventory inventory;
    int choice;
    do {
        cout << "=============================" << endl;
        cout << "INVENTARIS STOK MENU BARANG" << endl;
        cout << "=============================" << endl;
        cout << "1. Tampilkan Inventory" << endl;
        cout << "2. Edit Jumlah Barang" << endl;
        cout << "3. Kembali ke Menu Awal" << endl;
        cout << "Pilihan: " << endl;

        while (!(cin >> choice)) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Pilihan tidak valid! Masukkan angka: ";
        }

        string name;
        int quantity;

        switch(choice) {
            case 1:
                inventory.displayInventory();
                break;
            case 2:
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear newline character from buffer
                cout << "Masukkan Nama Barang yang akan diedit: ";
                getline(cin, name);

                if (!inventory.itemExists(name)) {
                    cout << "Error: Item tidak ditemukan di inventory." << endl;
                    break;
                }

                cout << "Masukkan Jumlah Baru: ";
                while (!(cin >> quantity) || quantity < 0) {
                    cin.clear(); // Clear the error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                    cout << "Jumlah tidak valid! Masukkan angka positif: ";
                }
                inventory.editItemQuantity(name, quantity);
                break;
            case 3:
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (choice != 3);
}
