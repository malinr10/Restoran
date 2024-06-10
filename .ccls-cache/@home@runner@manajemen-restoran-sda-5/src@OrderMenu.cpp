#include "../include/menu/OrderMenu.h"
#include <limits>

void OrderMenu::tampilkanOrderMenu(Stack& orderStack) {
    std::vector<Order> orders;
    std::string namaPelanggan, item;
    int jumlah;
    char tambahOrder;

    do {
        std::cout << "Masukkan nama pelanggan: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, namaPelanggan);
        std::cout << "Masukkan item: ";
        std::getline(std::cin, item);

        std::cout << "Masukkan jumlah: ";
        while (!(std::cin >> jumlah) || jumlah <= 0) {
            std::cout << "Jumlah harus berupa angka positif. Masukkan lagi: ";
            std::cin.clear(); // clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
        }

        Order order(namaPelanggan, item, jumlah);
        orders.push_back(order);

        std::cout << "Tambah pesanan lagi? (y/n): ";
        std::cin >> tambahOrder;
    } while (tambahOrder == 'y' || tambahOrder == 'Y');

    std::cout << "\nTinjau pesanan Anda:\n";
    for (const auto& order : orders) {
        order.tampilkanOrder();
        std::cout << std::endl;
    }

    char konfirmasi;
    std::cout << "Apakah Anda ingin mengonfirmasi pesanan ini? (y/n): ";
    std::cin >> konfirmasi;

    if (konfirmasi == 'y' || konfirmasi == 'Y') {
        for (auto& order : orders) {
            order.konfirmasiOrder();
            orderStack.push(order);
        }
        std::cout << "Pesanan dikonfirmasi dan ditambahkan ke tumpukan." << std::endl;
    } else {
        std::cout << "Pesanan tidak dikonfirmasi." << std::endl;
    }
}
