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

void merge(vector<Barang>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<Barang> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i].nama <= R[j].nama) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<Barang>& arr, int l, int r) {
    if (l >= r) {
        return;
    }
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}


void bubbleSort(vector<Barang>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].harga < arr[j + 1].harga) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void sortingHarga() {
    bubbleSort(DaftarBarang);
    cout << "\nDaftar Barang Setelah Diurutkan Secara Descending Berdasarkan Harga: \n" << endl;
    cout << ReadBarang();
}

void sortingHuruf() {
    mergeSort(DaftarBarang, 0, DaftarBarang.size() - 1);
    cout << "\nDaftar Barang Setelah Diurutkan Secara Ascending Berdasarkan Nama: \n" << endl;
    cout << ReadBarang(); 
}

void bubbleSortStok(vector<Barang>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].stok > arr[j + 1].stok) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void sortingStok() {
    bubbleSortStok(DaftarBarang);
    cout << "\nDaftar Barang Setelah Diurutkan Secara Ascending Berdasarkan Stok: \n" << endl;
    cout << ReadBarang(); 
}
int binarySearch(vector<Barang>& arr, const string& nama) {
    int l = 0;
    int r = arr.size() - 1;

    while (l <= r) {
        int m = l + (r - l) / 2;

        if (arr[m].nama == nama)
            return m;

        if (arr[m].nama < nama)
            l = m + 1;
        else
            r = m - 1;
    }

    return -1;
}

string ReadBarangsearch(const vector<Barang>& listBarang) {
    string output = "";

    if (listBarang.empty()) {
        output += "\nTidak ada barang yang cocok dengan kriteria pencarian\n";
    } else {
        output += "       Daftar Barang Pendakian          \n";
        output += "----------------------------------------\n";
        output += "No.   Nama Barang       Stok      Harga \n";
        output += "----------------------------------------\n";
        for (int i = 0; i < listBarang.size(); ++i) {
            output += to_string(i + 1) + "    " + listBarang[i].nama + "         " + to_string(listBarang[i].stok) + "       " + to_string(listBarang[i].harga) + "\n\n";
            output += "     Kondisi: " + listBarang[i].detail.kondisi + "\n";
            output += "     Kualitas: " + listBarang[i].detail.kualitas + "\n";
            output += "     Keterangan: " + listBarang[i].detail.keterangan + "\n";
        }
        output += "----------------------------------------\n";
    }

    return output;
}

void searchingNama() {
    string nama;
    cout << "Masukkan Nama Barang yang Dicari: ";
    getline(cin >> ws, nama);

    vector<Barang> hasilPencarian;
    for (const auto& barang : DaftarBarang) {
        if (barang.nama == nama) {
            hasilPencarian.push_back(barang);
        }
    }

    if (!hasilPencarian.empty()) {
        cout << "\nHasil Pencarian untuk Barang dengan Nama '" << nama << "':\n";
        cout << ReadBarangsearch(hasilPencarian);
    } else {
        cout << "Barang dengan nama '" << nama << "' tidak ditemukan." << endl;
    }
}


int interpolationSearch(const vector<Barang>& arr, int harga) {
    int n = arr.size();
    int low = 0, high = n - 1;

    while (low <= high && harga >= arr[low].harga && harga <= arr[high].harga) {
        if (low == high) {
            if (arr[low].harga == harga)
                return low;
            return -1;
        }

        int pos = low + (((double)(high - low) / (arr[high].harga - arr[low].harga)) * (harga - arr[low].harga));

        if (arr[pos].harga == harga)
            return pos;

        if (arr[pos].harga < harga)
            low = pos + 1;
        else
            high = pos - 1;
    }

    return -1;
}

void searchingHarga() {
    int harga;
    cout << "Masukkan Harga Barang yang Dicari: ";
    cin >> harga;

    vector<Barang> hasilPencarian;
    for (const auto& barang : DaftarBarang) {
        if (barang.harga == harga) {
            hasilPencarian.push_back(barang);
        }
    }

    if (!hasilPencarian.empty()) {
        cout << "\nHasil Pencarian untuk Barang dengan Harga '" << harga << "':\n";
        cout << ReadBarangsearch(hasilPencarian);
    } else {
        cout << "Barang dengan harga '" << harga << "' tidak ditemukan." << endl;
    }
}

void mainMenu() {
    cout << "\nMenu Yang Ada, Ga usah Cari Yang Ga Ada_- : \n" << endl;
    cout << "[1] Tambah Barang" << endl;
    cout << "[2] Tampilkan Daftar Barang" << endl;
    cout << "[3] Ubah Barang" << endl;
    cout << "[4] Hapus Barang" << endl;
    cout << "[5] Sorting Nama Secara Ascending" << endl;
    cout << "[6] Sorting Harga Secara Descending" << endl;
    cout << "[7] Sorting Stock Secara Ascending" << endl;
    cout << "[8] Searching Berdasarkan Nama" << endl;
    cout << "[9] Searching Berdasarkan Harga" << endl;
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
            case 5:
                sortingHuruf();
                break;
            case 6:
                sortingHarga();
                break;
            case 7:
                sortingStok();
                break;
            case 8:
                searchingNama();
                break;
            case 9:
                searchingHarga();
                break;
            default:
                cout << " Masukin 1 Sampe 9 Aja Bisa Ngga Sih Kok " << pilihan << " Loh Yang Kamu Masukin\n" << endl;
        }

    } while (ulang()); 
}