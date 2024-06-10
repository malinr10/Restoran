## Dokumentasi

### Struktur File :

```
    main.cpp
    /include
        Menu.h
        Inventory.h
        Queue.h
        Stack.h
        Tree.h
        Graph.h
    /src
        /menu
            InventoryMenu.cpp
            OrderMenu.cpp
            DisplayOrdersMenu.cpp
        Menu.cpp
        Inventory.cpp
        Queue.cpp
        Stack.cpp
        Tree.cpp
        Graph.cpp
    /data
        inventory.txt
```

### Penjelasan Struktur File:

- `main.cpp`: Berkas utama program, yang berisi fungsi `main` untuk menjalankan aplikasi.

- `/include`: Direktori yang berisi berkas header (.h) untuk deklarasi kelas dan fungsi.
    - `Menu.h`: Header file untuk kelas Menu yang mengatur menu utama aplikasi.
    - `Inventory.h`: Header file untuk kelas Inventory yang mengatur inventaris stok barang.
    - `Queue.h`: Header file untuk kelas Queue yang mengatur antrian pelanggan.
    - `Stack.h`: Header file untuk kelas Stack yang mengatur penampungan pesanan pelanggan.
    - `Tree.h`: Header file untuk kelas Tree yang mengatur struktur menu makanan/minuman.
    - `Graph.h`: Header file untuk kelas Graph yang mengatur struktur graf untuk mencari lantai/meja terdekat.

- `/src`: Direktori yang berisi berkas sumber (.cpp) untuk implementasi kelas dan fungsi.
    - `/menu`: Direktori yang berisi berkas sumber (.cpp) untuk setiap fitur menu.
        - `InventoryMenu.cpp`: Implementasi fitur inventaris stok menu barang.
        - `OrderMenu.cpp`: Implementasi fitur input pemesanan pelanggan.
        - `DisplayOrdersMenu.cpp`: Implementasi fitur menampilkan pesanan yang sedang berjalan.
    - `Menu.cpp`: Implementasi menu utama aplikasi.
    - `Inventory.cpp`: Implementasi kelas Inventory.
    - `Queue.cpp`: Implementasi kelas Queue.
    - `Stack.cpp`: Implementasi kelas Stack.
    - `Tree.cpp`: Implementasi kelas Tree.
    - `Graph.cpp`: Implementasi kelas Graph.

- `/data`: Direktori yang berisi data yang diperlukan oleh aplikasi.
    - `inventory.txt`: File teks yang berisi informasi inventaris stok barang.
