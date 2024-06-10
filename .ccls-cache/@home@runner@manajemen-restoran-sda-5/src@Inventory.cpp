#include "../include/Inventory.h"
#include <fstream>
#include <iostream>

using namespace std;

Inventory::Inventory() {
    loadInventory();
}

void Inventory::loadInventory() {
    ifstream file("data/inventory.txt");
    string name, type;
    int quantity;

    while (file >> name >> type >> quantity) {
        items.push_back({name, type, quantity});
    }

    file.close();
}

void Inventory::displayInventory() {
    cout << "Inventaris Barang:" << endl;
    for (const auto &item : items) {
        cout << "Nama: " << item.name << ", Jenis: " << item.type
             << ", Jumlah: " << item.quantity << endl;
    }
}

void Inventory::editItemQuantity(const std::string &name, int quantity) {
    bool found = false;
    for (auto &item : items) {
        if (item.name == name) {
            item.quantity = quantity;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Item tidak ditemukan di inventory." << endl;
        return;
    }
    saveInventory();
    cout << "Jumlah barang berhasil diperbarui." << endl;
}

void Inventory::saveInventory() {
    ofstream file("data/inventory.txt");
    for (const auto &item : items) {
        file << item.name << " " << item.type << " " << item.quantity << endl;
    }
    file.close();
}

bool Inventory::itemExists(const std::string &name) const {
    for (const auto &item : items) {
        if (item.name == name) {
            return true;
        }
    }
    return false;
}

int Inventory::getItemQuantity(const std::string &name) const {  // Add this method
    for (const auto &item : items) {
        if (item.name == name) {
            return item.quantity;
        }
    }
    return 0;  // Or throw an exception if item not found
}
