#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Menu {
    string nama;
    int harga;
};

struct Pesanan {
    Menu menu;
    int jumlah;
    Pesanan* next;
};

void tampilkanMenu(const Menu daftarMenu[], int size) {
    cout <<"selamat datang di restoran tawa saji" << endl;
    cout <<"------anda puas kami bahagia--------" << endl <<endl;
    cout << "Daftar Menu Restoran:" << endl;
    cout << setw(20) << left << "Menu" << setw(31) << right << "Harga" << endl;
    cout << setfill('-') << setw(51) << "" << setfill(' ') << endl;

    for (int i = 0; i < size; ++i) {
        cout << setw(31) << left << daftarMenu[i].nama << setw(20) << right << daftarMenu[i].harga << endl;
    }
}

int main() {
    // Inisialisasi daftar menu
    const int jumlahMenu = 8;
    Menu daftarMenu[jumlahMenu] = {
        {"1. Roti Jala Maklima Biadab", 20000},
        {"2. Sop Iga Tulang Belakang Eren", 30000},
        {"3. Nasi Kentut Medan", 25000},
        {"4. Steak Wahyu A5", 350000},
        {"5. Telor Presto", 5000},
        {"6. Mekdi Israel", 30000},
        {"7. Tahu", 4000},
        {"8. Tidak Tahu", 4000}
    };

    // Menampilkan daftar menu
    tampilkanMenu(daftarMenu, jumlahMenu);

    // Memproses pesanan
    Pesanan* head = nullptr;
    Pesanan* tail = nullptr;
    char lanjutPesan;
    int uangPelanggan = 0, totalHarga = 0, kembalian = 0;
    int nomorMenu, jumlahPesanan;

    cout << "Masukkan uang anda: ";
    cin >> uangPelanggan;
  
    do {

        cout << "Masukkan nomor menu yang dipilih: ";
        cin >> nomorMenu;

        if (nomorMenu >= 1 && nomorMenu <= jumlahMenu) {
            cout << "Masukkan jumlah pesanan: ";
            cin >> jumlahPesanan;

            // Menambahkan pesanan ke linked list
            Pesanan* newPesanan = new Pesanan;
            newPesanan->menu = daftarMenu[nomorMenu - 1];
            newPesanan->jumlah = jumlahPesanan;
            newPesanan->next = nullptr;

            totalHarga += daftarMenu[nomorMenu - 1].harga * jumlahPesanan; //dikurangin 1 karena index array dimulai dari 0
            
            if (head == nullptr) {
                head = tail = newPesanan;
            } else {
                tail->next = newPesanan;
                tail = newPesanan;
            }

            cout << "\nLanjutkan pesanan? (y/n): ";
            cin >> lanjutPesan;
        } else {
            cout << "Nomor menu tidak valid. Silakan coba lagi." << endl;
            lanjutPesan = 'y'; // Lanjutkan pesanan walaupun nomor menu tidak valid
        }
    } while (lanjutPesan == 'y' || lanjutPesan == 'Y');

    
  kembalian = uangPelanggan - totalHarga;

    switch (uangPelanggan < totalHarga) {
        case 1 :
        cout << "\nTotal Harga: " << totalHarga << endl;
        cout << "Maaf uang anda kurang untuk membeli menu ini." << endl;
        break;
        default :
        cout << "\nTotal Harga: " << totalHarga << endl;
        cout << "Kembalian anda: " << kembalian << endl; // Menampilkan kembalian pelanggan
    } 
        
    // Menampilkan pesanan
    cout << "\nDaftar Pesanan Anda:" << endl;
    cout << setw(20) << left << "Menu" << setw(10) << right << "Jumlah" << endl;
    cout << setfill('-') << setw(30) << "" << setfill(' ') << endl;
    Pesanan* current = head;
    while (current != nullptr) {
        cout << setw(20) << left << current->menu.nama << setw(10) << right << current->jumlah << endl;
        current = current->next;
    }

    // Dealokasi memori untuk linked list
    current = head;
    while (current != nullptr) {
        Pesanan* temp = current;
        current = current->next;
        delete temp;
    }
    return 0;
}
