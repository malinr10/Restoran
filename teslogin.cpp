#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include <stdexcept>
#include <limits>
#include <algorithm>

using namespace std;

void saveUsersToFile(const unordered_map<string, string>& users, const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        throw runtime_error("Gagal membuka file untuk menulis.");
    }

    for (const auto& pair : users) {
        outFile << pair.first << " " << pair.second << endl;
    }
    outFile.close();
}

void registerUser(unordered_map<string, string>& users) {
    string username, password;
    cout << "=== Daftar ===" << endl;
    cout << "Masukkan username: ";
    cin >> username;
    cout << "Masukkan password: ";
    cin >> password;

    // Hapus spasi di awal dan akhir
    username.erase(username.begin(), find_if(username.begin(), username.end(), [](int ch) { return !isspace(ch); }));
    username.erase(find_if(username.rbegin(), username.rend(), [](int ch) { return !isspace(ch); }).base(), username.end());
    password.erase(password.begin(), find_if(password.begin(), password.end(), [](int ch) { return !isspace(ch); }));
    password.erase(find_if(password.rbegin(), password.rend(), [](int ch) { return !isspace(ch); }).base(), password.end());

    if (username.empty() || password.empty()) {
        cerr << "Username dan password tidak boleh kosong atau hanya berisi spasi!" << endl;
        return;
    }

    if (users.find(username) != users.end()) {
        cerr << "Username sudah terdaftar!" << endl;
        return;
    }

    users[username] = password;
    cout << "Registrasi berhasil!" << endl;

    try {
        saveUsersToFile(users, "pass.txt");
    } catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

bool loginUser(const unordered_map<string, string>& users) {
    string username, password;
    cout << "=== Masuk ===" << endl;
    cout << "Masukkan username: ";
    cin >> username;
    cout << "Masukkan password: ";
    cin >> password;

    // Hapus spasi di awal dan akhir
    username.erase(username.begin(), find_if(username.begin(), username.end(), [](int ch) { return !isspace(ch); }));
    username.erase(find_if(username.rbegin(), username.rend(), [](int ch) { return !isspace(ch); }).base(), username.end());
    password.erase(password.begin(), find_if(password.begin(), password.end(), [](int ch) { return !isspace(ch); }));
    password.erase(find_if(password.rbegin(), password.rend(), [](int ch) { return !isspace(ch); }).base(), password.end());

    if (username.empty() || password.empty()) {
        cerr << "Username dan password tidak boleh kosong atau hanya berisi spasi!" << endl;
        return false;
    }

    auto it = users.find(username);
    if (it != users.end() && it->second == password) {
        cout << "Login berhasil!" << endl;
        return true;
    } else {
        cout << "Username atau password salah!" << endl;
        return false;
    }
}

class Menu {
public:
    void displayMenu() {
        cout << "=== Menu ===" << endl;
        cout << "1. Opsi 1" << endl;
        cout << "2. Opsi 2" << endl;
        cout << "3. Keluar" << endl;
    }
};

void loadUsersFromFile(unordered_map<string, string>& users, const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Peringatan: Tidak dapat membuka file untuk membaca, memulai dengan daftar pengguna kosong." << endl;
        return;
    }

    string username, password;
    while (inFile >> username >> password) {
        users[username] = password;
    }
    inFile.close();
}

int main() {
    unordered_map<string, string> users;
    loadUsersFromFile(users, "pass.txt");

    int choice;
    while (true) {
        cout << "1. Daftar" << endl;
        cout << "2. Masuk" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih opsi: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear(); // bersihkan bendera error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // buang input yang tidak valid
            cerr << "Input tidak valid, masukkan angka." << endl;
            continue;
        }

        if (choice == 1) {
            registerUser(users);
        } else if (choice == 2) {
            if (loginUser(users)) {
                Menu menu;
                menu.displayMenu();
                break;
            }
        } else if (choice == 3) {
            cout << "Keluar dari program." << endl;
            break;
        } else {
            cout << "Opsi tidak valid, coba lagi." << endl;
        }
    }

    return 0;
}
