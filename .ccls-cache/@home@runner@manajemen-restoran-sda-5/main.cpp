// #include <iostream>
// #include <string>
// #include <unordered_map>
// #include <fstream>
// #include <stdexcept>
// #include <limits>

// using namespace std;

// void saveUsersToFile(const unordered_map<string, string>& users, const string& filename) {
//     ofstream outFile(filename);
//     if (!outFile) {
//         throw runtime_error("Gagal membuka file untuk menulis.");
//     }

//     for (const auto& pair : users) {
//         outFile << pair.first << " " << pair.second << endl;
//     }
//     outFile.close();
// }

// void loadUsersFromFile(unordered_map<string, string>& users, const string& filename) {
//     ifstream inFile(filename);
//     if (!inFile) {
//         cerr << "Tidak dapat membuka file untuk membaca. Memulai dengan basis data kosong." << endl;
//         return;
//     }

//     string username, password;
//     while (inFile >> username >> password) {
//         users[username] = password;
//     }
//     inFile.close();
// }

// void registerUser(unordered_map<string, string>& users) {
//     string username, password;
//     cout << "=== Register ===" << endl;
//     cout << "Masukkan username: ";
//     cin >> username;
//     cout << "Masukkan password: ";
//     cin >> password;

//     if (username.empty() || password.empty()) {
//         cerr << "Username dan password tidak boleh kosong!" << endl;
//         return;
//     }

//     if (users.find(username) != users.end()) {
//         cerr << "Username sudah terdaftar!" << endl;
//         return;
//     }

//     users[username] = password;
//     cout << "Registrasi berhasil!" << endl;

//     try {
//         saveUsersToFile(users, "pass.txt");
//     } catch (const runtime_error& e) {
//         cerr << "Error: " << e.what() << endl;
//     }
// }

// bool loginUser(const unordered_map<string, string>& users) {
//     string username, password;
//     cout << "=== Login ===" << endl;
//     cout << "Masukkan username: ";
//     cin >> username;
//     cout << "Masukkan password: ";
//     cin >> password;

//     if (username.empty() || password.empty()) {
//         cerr << "Username dan password tidak boleh kosong!" << endl;
//         return false;
//     }

//     auto it = users.find(username);
//     if (it != users.end() && it->second == password) {
//         cout << "Login berhasil!" << endl;
//         return true;
//     } else {
//         cout << "Username atau password salah!" << endl;
//         return false;
//     }
// }

// class Menu {
// public:
//     void displayMenu() {
//         cout << "=== Menu ===" << endl;
//         cout << "1. Opsi 1" << endl;
//         cout << "2. Opsi 2" << endl;
//         cout << "3. Keluar" << endl;
//     }
// };

// int main() {
//     unordered_map<string, string> users; 
//     int choice;

//     try {
//         loadUsersFromFile(users, "pass.txt");
//     } catch (const runtime_error& e) {
//         cerr << "Error: " << e.what() << endl;
//     }

//     while (true) {
//         cout << "1. Register" << endl;
//         cout << "2. Login" << endl;
//         cout << "3. Keluar" << endl;
//         cout << "Pilih opsi: ";
//         cin >> choice;

//         if (cin.fail()) {
//             cin.clear(); // clear the error flag
//             cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
//             cerr << "Input tidak valid, masukkan angka." << endl;
//             continue;
//         }

//         if (choice == 1) {
//             registerUser(users);
//         } else if (choice == 2) {
//             if (loginUser(users)) {
//                 Menu menu;
//                 menu.displayMenu();
//                 break;
//             }
//         } else if (choice == 3) {
//             cout << "Keluar dari program." << endl;
//             try {
//                 saveUsersToFile(users, "pass.txt");
//             } catch (const runtime_error& e) {
//                 cerr << "Error: " << e.what() << endl;
//             }
//             break;
//         } else {
//             cout << "Opsi tidak valid, coba lagi." << endl;
//         }
//     }

//     return 0;
// }
