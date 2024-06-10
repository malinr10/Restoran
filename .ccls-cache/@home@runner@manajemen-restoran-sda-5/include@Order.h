#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <iostream>

class Order {
private:
    std::string namaPelanggan;
    std::string item;
    int jumlah;
    bool sudahDikonfirmasi;

public:
    Order(const std::string& namaPelanggan, const std::string& item, int jumlah)
        : namaPelanggan(namaPelanggan), item(item), jumlah(jumlah), sudahDikonfirmasi(false) {}

    void tampilkanOrder() const {
        std::cout << "Nama Pelanggan: " << namaPelanggan << "\nItem: " << item << "\nJumlah: " << jumlah << std::endl;
    }

    void konfirmasiOrder() {
        sudahDikonfirmasi = true;
    }

    bool isOrderDikonfirmasi() const {
        return sudahDikonfirmasi;
    }

    std::string getNamaPelanggan() const { return namaPelanggan; }
    std::string getItem() const { return item; }
    int getJumlah() const { return jumlah; }
};

#endif // ORDER_H
