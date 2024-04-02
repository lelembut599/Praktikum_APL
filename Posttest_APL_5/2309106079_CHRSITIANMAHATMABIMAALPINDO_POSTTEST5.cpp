#include <iostream>
#include <vector>

using namespace std;

struct Barang {
    string nama;
    int stok;
    int harga;

    struct Detail {
        string kondisi;
        string kualitas;
        string keterangan;
    } detail;
};

vector<Barang> DaftarBarang;

void tambahBarang(Barang* barang) {
    cout << "Masukkan Nama Barang: ";
    getline(cin >> ws, barang->nama);
    cout << "Masukkan Stok Barang: ";
    cin >> barang->stok;
    cout << "Masukkan Harga Barang: ";
    cin >> barang->harga;

    cout << "Masukkan Kondisi Barang: ";
    getline(cin >> ws, barang->detail.kondisi);
    cout << "Masukkan Kualitas Barang: ";
    getline(cin >> ws, barang->detail.kualitas);
    cout << "Masukkan Keterangan Barang: ";
    getline(cin >> ws, barang->detail.keterangan);
    DaftarBarang.push_back(*barang);

    cout << "\nBarang Berhasil Ditambahkan" << endl;
}


string ReadBarang() {
    string output = "";

    if (DaftarBarang.empty()) {
        output += "\nBelum ada barang yang ditambahkan\n";
    } else {
        output += "       Daftar Barang Pendakian          \n";
        output += "----------------------------------------\n";
        output += "No.   Nama Barang       Stok      Harga \n";
        output += "----------------------------------------\n";
        for (int i = 0; i < DaftarBarang.size(); ++i) {
            output += to_string(i + 1) + "    " + DaftarBarang[i].nama + "         " + to_string(DaftarBarang[i].stok) + "       " + to_string(DaftarBarang[i].harga) + "\n\n";
            output += "     Kondisi: " + DaftarBarang[i].detail.kondisi + "\n";
            output += "     Kualitas: " + DaftarBarang[i].detail.kualitas + "\n";
            output += "     Keterangan: " + DaftarBarang[i].detail.keterangan + "\n";
        }
        output += "----------------------------------------\n";
    }

    return output;
}


void tampilkanBarang() {
    cout << ReadBarang() << endl;
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
        cout << "Masukkan nomor antara 1 dan " << DaftarBarang.size() << endl;
        return;
    }

    Barang *barang = &DaftarBarang[nomor - 1];


    cout << "Masukkan Nama Barang Baru: ";
    getline(cin >> ws, barang->nama);
    cout << "Masukkan Stok Barang Baru: ";
    cin >> barang->stok;
    cout << "Masukkan Harga Barang Baru: ";
    cin >> barang->harga;

    cout << "Masukkan Kondisi Barang Baru: ";
    getline(cin >> ws, barang->detail.kondisi);
    cout << "Masukkan Kualitas Barang Baru: ";
    getline(cin >> ws, barang->detail.kualitas);
    cout << "Masukkan Keterangan Barang Baru: ";
    getline(cin >> ws, barang->detail.keterangan);

    cout << "\nBarang Berhasil Diubah" << endl;
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
        cout << "Masukkan nomor antara 1 dan " << DaftarBarang.size() << endl;
        return;
    }

    DaftarBarang.erase(DaftarBarang.begin() + (nomor - 1));

    cout << "\nBarang Berhasil Dihapus, Aman Bro\n" << endl;
}

bool login() {
    string usr, pswd;
    int count = 0;

    while (count < 3) {
        cout << "Masukkan Nama Sebagai Username : ";
        getline(cin, usr);
        cout << "Masukkan 3 NIM terakhir Sebagai Password: ";
        getline(cin, pswd);

        if (usr == "Christian Mahatma Bima Alpindo" && pswd == "079") {
            cout << "\n\n\nLogin Berhasil!\n\n\n";
            cout << "====Selamat datang Di TOKO BARANG ALAT PENDAKIAN Tong Fang====\n";
            cout << "         Kamu Kuat. Kamu Hebat. #MTMERBABU3142mdpl            \n\n\n";
            return true;
        } else {
            count++;
            cout << "Login Gagal! Silakan Coba Lagi.\n";
        }
    }

    if (count == 3) {
        cout << "Maaf, Kesempatan Login Anda Sudah Habis, Program Akan Berhenti Secara Paksa\n";
        return false;
    }

    return false;
}

bool ulang() {
    char ulangi;
    cout << "\nApakah Anda ingin mengulanginya lagi ? (y/n): ";
    cin >> ulangi;
    if (ulangi == 'y' || ulangi == 'Y') {
        cin.ignore();
        system ("cls");
        return true;
    } else {
        cout << "\n\nTerima kasih telah berkunjung ke toko kami!\n"
                "Kalo kata orang dulu mah,\n"
                "Pulu pulu, pulu pulu pulu, PULU PULUUU. PULUUU!!!!\n"
                "Wassalamualaikum Wr Wb";
        return false;
    }
}

void mainMenu() {
    cout << "\nMenu Yang Ada, Ga usah Cari Yang Ga Ada_- : \n" << endl;
    cout << "1. Tambah Barang" << endl;
    cout << "2. Tampilkan Daftar Barang" << endl;
    cout << "3. Ubah Barang" << endl;
    cout << "4. Hapus Barang" << endl;
    cout << "Masukan Pilihan: ";
}

int main() {
    if (!login()) {
        return 0;
    }

    do {
        mainMenu();

        int pilihan;
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                Barang barang; 
                tambahBarang(&barang); 
                break;
            }
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
                cout << " Masukin 1 Sampe 4 Aja Bisa Ngga Sih Kok " << pilihan << " Loh Yang Kamu Masukin\n" << endl;
        }

    } while (ulang());

    return 0;
}
