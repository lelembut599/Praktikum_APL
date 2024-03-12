#include <iostream>
#include <vector>

using namespace std;

struct Barang {
    string nama;
    int stok;
    double harga;
};

vector<Barang> DaftarBarang;

void tambahBarang() {
    Barang barang;
    cout << "Masukkan Nama Barang: ";
    getline(cin >> ws, barang.nama);
    cout << "Masukkan Stok Barang: ";
    cin >> barang.stok;
    cout << "Masukkan Harga Barang: ";
    cin >> barang.harga;

    DaftarBarang.push_back(barang);

    cout << "\nBarang Berhasil DiTambah" << endl;
}

void tampilkanBarang() {
    if (DaftarBarang.empty()) {
        cout << "\nBlom Restock,Maapin deh\n" << endl;
    } else {
        cout << "       Daftar Barang Pendakian          " << endl;
        cout << "----------------------------------------" << endl;
        cout << "No.   Nama Barang       Stok      Harga " << endl;
        cout << "----------------------------------------" << endl;
        for (int i = 0; i < DaftarBarang.size(); ++i) {
            cout << i + 1 << "    " << DaftarBarang[i].nama << "         " << DaftarBarang[i].stok << "       " << DaftarBarang[i].harga << endl;
        }
        cout << "----------------------------------------" << endl;
    }
}

void ubahBarang() {
    tampilkanBarang();
    if (DaftarBarang.empty()) {
        return;
    }

    int nomor;
    cout << "\nMasukkan nomor barang yang ingin diubah: ";
    cin >> nomor;

    if (nomor <= 0 || nomor > DaftarBarang.size()) {
        cout << "Masukin Nomor Sampe "<<DaftarBarang.size()<< " Aja Jangan Lebih Dari Itu" << nomor <<" Kan Di Atas" <<DaftarBarang.size()<<" Tolol" << endl;
        return;
    }

    cout << "Masukkan Nama Barang Baru: ";
    getline(cin >> ws, DaftarBarang[nomor - 1].nama);
    cout << "Masukkan Stok Barang Baru: ";
    cin >> DaftarBarang[nomor - 1].stok;
    cout << "Masukkan Harga Barang Baru: ";
    cin >> DaftarBarang[nomor - 1].harga;

    cout << "\nBarang Beerhasil DiUbah" << endl;
}

void hapusBarang() {
    tampilkanBarang();
    if (DaftarBarang.empty()) {
        return;
    }

    int nomor;
    cout << "Masukkan nomor barang yang ingin dihapus: ";
    cin >> nomor;

    if (nomor <= 0 || nomor > DaftarBarang.size()) {
        cout << "Ih Tolol, Orang Cuma Sampe "<<DaftarBarang.size() <<" Malah Masukin No " << nomor << endl;
        return;
    }

    DaftarBarang.erase(DaftarBarang.begin() + (nomor - 1));

    cout << "\nBarang Bukti Berhasil Dimusnahakan, Aman Bro\n" << endl;
}

int main() {
    string usr, pswd;
    int count = 0;
    char ulangi;

    while (count < 3) {
        cout << "Masukkan Nama Sebagai Username : ";
        getline(cin, usr);
        cout << "Masukkan 3 NIM terakhir Sebagai Password: ";
        getline(cin, pswd);

        if (usr == "Christian Mahatma Bima Alpindo" && pswd == "079") {
            cout << "\n\n\nLogin Berhasil!\n\n\n";
            cout << "====Selamat datang Di TOKO BARANG ALAT PENDAKIAN Tong Fang====\n";
            cout << "         Kamu Kuat. Kamu Hebat. #MTMERBABU3142mdpl            \n\n\n";
            break;
        } else {
            count++;
            cout << "Login Gagal! Silakan Coba Lagi.\n";
        }
    }

    if (count == 3) {
        cout << "Maaf,Kesempatan Login Anda Sudah Habis.\n Program Akan Diberhentikan Secara Paksa.\n";
        return 0;
    }

    do {
        cout << "\nMenu Yang Ada, Ga usah Cari Yang Ga Ada_- : \n" << endl;
        cout << "1. Tambah Barang" << endl;
        cout << "2. Tampilkan Daftar Barang" << endl;
        cout << "3. Ubah Barang" << endl;
        cout << "4. Hapus Barang" << endl;
        cout << "Masukan Pilihan: ";

        int pilihan;
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahBarang();
                break;
            case 2:
                tampilkanBarang();
                break;
            case 3:
                ubahBarang();
                break;
            case 4:
                hapusBarang();
                break;
            default:
                cout << " Masukin 1 Sampe 4 Aja Bisa Ngga Sih Kok " <<pilihan<< " Loh Yang Kamu Masukin\n" << endl;
        }

        cout << "\nApakah Anda ingin mengulanginya lagi ? (y/n): ";
        cin >> ulangi;
    } while (ulangi == 'y' || ulangi == 'Y');

    cout << "\n\nTerima kasih telah Berkunjung Ke TOko Kami, \n"
            "Kalo Kata Orang Dulu mah\n"
            "Pulu pulu, pulu pulu pulu, PULU PULUUU. PULUUU!!!!\n"
            "Wassalamualaikum Wr Wb";

    return 0;
}
