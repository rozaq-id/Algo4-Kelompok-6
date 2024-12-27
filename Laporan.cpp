#include <iostream>
#include <string>

using namespace std;

const int MAX_MENU = 100;

struct Menu {
    string nama;
    int harga;
    int stok;
};

Menu menu[MAX_MENU];
int jumlahMenu = 0; 

void tambahMenu() {
    if (jumlahMenu == MAX_MENU) {
        cout << "Menu sudah penuh!" << endl;
        return;
    }

    Menu newMenu;
    cout << "Masukkan nama menu: ";
    cin >> newMenu.nama;
    cout << "Masukkan harga: ";
    cin >> newMenu.harga;
    cout << "Masukkan stok awal: ";
    cin >> newMenu.stok;

    menu[jumlahMenu] = newMenu;
    jumlahMenu++;
    cout << "Menu berhasil ditambahkan!" << endl;
}


void inputPenjualan(int hari) {
    cout << "Masukkan data penjualan hari ke-" << hari << endl;
    for (int i = 0; i < jumlahMenu; i++) {
        int terjual;
        cout << "Menu " << menu[i].nama << ": ";
        cin >> terjual;
        menu[i].stok -= terjual;
    }
}


int hitungTotalPenjualan() {
    int total = 0;
    for (int i = 0; i < jumlahMenu; i++) {
        total += menu[i].harga * (menu[i].stok * -1); 
    }
    return total;
}


string cariMenuTerlaris() {
    int maxTerjual = 0;
    string menuTerlaris;
    for (int i = 0; i < jumlahMenu; i++) {
        if (menu[i].stok * -1 > maxTerjual) {
            maxTerjual = menu[i].stok * -1;
            menuTerlaris = menu[i].nama;
        }
    }
    return menuTerlaris;
}

// Fungsi untuk menampilkan status stok
void tampilkanStatusStok() {
    cout << "Status Stok Menu:" << endl;
    for (int i = 0; i < jumlahMenu; i++) {
        cout << menu[i].nama << ": ";
        if (menu[i].stok > 0) {
            cout << "Tersedia" << endl;
        } else {
            cout << "Habis" << endl;
        }
    }
}


int main() {
 
    int jumlahHari;
    cout << "Masukkan jumlah hari: ";
    cin >> jumlahHari;
    for (int i = 1; i <= jumlahHari; i++) {
        inputPenjualan(i);
    }


    cout << "Total penjualan: Rp" << hitungTotalPenjualan() << endl;
    cout << "Menu terlaris: " << cariMenuTerlaris() << endl;
    tampilkanStatusStok();

    return 0;
}
