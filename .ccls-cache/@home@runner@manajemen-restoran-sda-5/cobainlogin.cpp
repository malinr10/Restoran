#include <iostream>
#include <string>
#include <unordered_map>


using namespace std;

void registerUser(unordered_map<string, string>& users) {
    string username, password;
    cout << "=== Register ===" << endl;
    cout << "Masukkan username: ";
    cin >> username;
    cout << "Masukkan password: ";
    cin >> password;
    

    users[username] = password;
    cout << "Registrasi berhasil!" << endl;
}

bool loginUser(const unordered_map<string, string>& users) {
    string username, password;
    cout << "=== Login ===" << endl;
    cout << "Masukkan username: ";
    cin >> username;
    cout << "Masukkan password: ";
    cin >> password;

    if (users.find(username) != users.end() && users.at(username) == password) {
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

int main() {
    unordered_map<string, string> users; 
    int choice;

    while (true) {
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih opsi: ";
        cin >> choice;

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
