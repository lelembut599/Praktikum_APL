#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <windows.h>
#include <iomanip>
#include <sstream>
#include <conio.h>

using namespace std;

struct Menu {
    int pk;
    string nama;
    struct isi {
        int harga;
        string value;
    }isi;
};

struct User{
    int id;
    string usr;
    string pass;
    string bankName;
    struct bank{
        int saldo;
        int rek;
        int pin;
    }bank;

};

const int jml = 1000; // Maksimal item-menu

string usernameLogin; 

User usr[jml];

Menu itm[jml];



int AdminOption();
bool perulanganAdmin();
void cekdata(fstream &data);
void TambahMenu(fstream &data);
void displaydata(fstream &data);
void ubahMenu(fstream &data);
void hapusMenu(fstream &data);
void table(fstream &data);
void insertionSort(string **data, int size);
int UserOption();
void transaksi();
int IDotomatis(const string &filename);
bool perulanganUser();
void cekdatausr(fstream &data);
void cekdatatransaksi(fstream &data);
void headeruser();
void regisuser();
void loginUser();
void topUpSaldo();
void lihatSaldo();
void orderMenu();
void searchMenu();
void Riwayattransaksi();
int Option();
void menuuser();
string sensor();
int masuk();

int main(){

    masuk();
}

int masuk() {
    fstream data;
    int pilihan;
    cekdatausr(data);
    cekdatatransaksi(data);
    enum option { login = 1, regis, pinis };

    while (true) {
        pilihan = Option();
        switch (pilihan) {
            case login:
                loginUser();
                break;
            case regis:
                regisuser();
                cout << "========================================================================================================\n";
                cout << "\t\t\t\tRegistrasi Berhasil!" << endl;
                cout << "========================================================================================================\n";
                Sleep(2000);
                break;
            case pinis:
                system("cls");
                cout << "========================================================================================================\n";
                cout << "\tHadirin Yang Diberkati Allah, Akhirnya Tibalah Kita Di Penghujung Acara, Yang Sebagai Mana Mestinya\n Di isi Dengan AKhir Kata dan Kata Maaf. Oleh Karena Itu Kami Dari Team 1 Kelas B2 Angkatan 23 Memohon Maaf\nYang Sebesar-besarnya Atas Kesalahan yang Kami Sengaja Maupun Tidak, Tetapi Memang Sesungguhnya Kesempurnaan\nHanya Di Miliki Oleh Tuhan YME. Akhir Kata Kami Mengucapkan Wassalamu'alaikum Warohmatullahi Wabarokatuh.\n\t\t\t - Irpan Memasak Disebelah Taman\n\t\t\t - Rizky Menari Di Tengah Malam\n\t\t\t\t - Mohon Maaf Kami Ucapkan\n\t\t\t\t - Tapi Lain Kali Baku Hantam  " << endl;
                cout << "========================================================================================================\n";
                Sleep(2000); 
                return 0;
            default:
                system("cls");
                cout << "========================================================================================================\n";
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                cout << "========================================================================================================\n";
                Sleep(2000); 
        }
    }

    return 0;
}

void menuadmin() {
    fstream data;
    cekdata(data);
    int pilihan;
    enum option { Buat = 1, Baca, Ubah, Hapus, Liat, pinis };

    while (true) {
        pilihan = AdminOption();
        switch (pilihan) {
            case Buat:
                TambahMenu(data);
                break;
            case Baca:
                system("cls");
                table(data);
                perulanganAdmin();
                break;
            case Ubah:
                ubahMenu(data);
                break;
            case Hapus:
                hapusMenu(data);
                break;
            case Liat:
                transaksi();
                break;
            case pinis:
                system("cls");
                cout << "========================================================================================================\n";
                cout << "\t\tNasi Uduk Ikannya Tongkol\n \t\t Sambil Duduk Garuk-garuk Kantor " << endl;
                cout << "========================================================================================================\n";
                Sleep(2000);
                masuk();
                return;
            default:
                system("cls");
                cout << "========================================================================================================\n";
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                cout << "========================================================================================================\n";
                Sleep(2000); 
        }
    }
}


bool perulanganAdmin() {
    char Pilihan;
    while (true) {
        cout << "========================================================" << endl;
        cout << " \nApakah Admin Ingin Mengulangi Program? (y/n)\ny = Kembali Ke Menu Admin\nn = Close Program(exit)\n " << endl;
        cout << "========================================================" << endl;
        cout << "Pilihan Anda >> ";
        cin >> Pilihan;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        Pilihan = tolower(Pilihan);
        if (Pilihan == 'y') {
            return true;
        } else if (Pilihan == 'n') {
            return false;
        } else {
            system("cls");
            cout << "========================================================================================================\n";
            cout << "Input tidak valid. Silakan masukkan 'y' untuk ya atau 'n' untuk tidak." << endl;
            cout << "========================================================================================================\n";
            Sleep(2000);
        }
    }
}


int AdminOption() {
    int input;
    while (true) {
        system("cls");
        cout << "\n       Menu Ngadmin       " << endl;
        cout << "============================" << endl;
        cout << "   [1] Tambah Menu" << endl;
        cout << "   [2] Tampilkan Menu" << endl;
        cout << "   [3] Ubah Menu" << endl;
        cout << "   [4] Hapus Menu" << endl;
        cout << "   [5] Lihat Trsansaksi" << endl;
        cout << "   [6] Rampung Cuk, Metu" << endl;
        cout << "============================" << endl;
        cout << "Masukan Pilihan { 1 - 6 } : ";
        cin >> input;

        if (cin.fail() || input < 1 || input > 6) {
            cin.clear(); // clear the error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            system("cls");
            cout << "========================================================================================================\n";
            cout << "\tPilihan tidak valid. Silakan masukkan angka antara 1 dan 6." << endl;
            cout << "========================================================================================================\n";
            Sleep(2000); // Delay for 2 seconds to let the user read the error message
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard any extra input
            return input;
        }
    }
}


void cekdata(fstream &data) {
    data.open("menu.csv", ios::in | ios::out | ios::app);
    if (!data.is_open()) {
        cout << "Data ga ada, ini buat baru" << endl;
        data.open("menu.csv", ios::out | ios::in | ios::app);
    }
}


void TambahMenu(fstream &data) {
    Menu inputmenu;
    system("cls");
    cout << "    : : : TAMBAH DAFTAR MENU : : :    " << endl;
    cout << "======================================" << endl;
    cout << "Nama Menu Top Up Yang Baru: ";
    getline(cin, inputmenu.nama);

    // Input ID item dengan penanganan kesalahan
    while (true) {
        cout << "Masukkan ID Item\t  : ";
        string idStr;
        getline(cin, idStr);
        try {
            inputmenu.pk = stod(idStr);
            if (inputmenu.pk < 0) {
                cout << "Error: ID Item tidak boleh negatif." << endl;
            } else {
                break;
            }
        } catch (const std::invalid_argument& e) {
            cout << "Error: Masukkan harus berupa bilangan bulat." << endl;
        } catch (const std::out_of_range& e) {
            cout << "Error: ID terlalu besar." << endl;
        }
    }

    // Input harga dengan penanganan kesalahan
    int harga;
    while (true) {
        
        cout << "Masukkan Harga \t\t  : Rp  ";
        string hargaStr;
        getline(cin, hargaStr);

        try {
            harga = stoi(hargaStr);
            if (harga < 0) {
                cout << "Error: Harga tidak boleh negatif." << endl;
            } else {
                break;
            }
        } catch (const std::invalid_argument& e) {
            cout << "Error: Masukkan harus berupa bilangan bulat." << endl;
        } catch (const std::out_of_range& e) {
            cout << "Error: Harga terlalu besar." << endl;
        }
    }

     inputmenu.isi.harga = harga;

    // Buka file untuk membaca
    data.clear();
    data.seekg(0, ios::beg);

    string line;
    bool duplicate = false;
    while (getline(data, line)) {
        stringstream ss(line);
        string idStr, nama, hargaStr, value;
        getline(ss, idStr, ',');
        getline(ss, nama, ',');
        getline(ss, hargaStr, ',');
        getline(ss, value);

        int hargaint = stoi(hargaStr);
        if (nama == inputmenu.nama && hargaint == inputmenu.isi.harga) {
            duplicate = true;
            break;
        }
    }

    if (duplicate) {
        system("cls");
        cout << "========================================================================================================\n";
        cout << "\t\tSudah ada data dengan harga dan ID yang sama" << endl;
        cout << "========================================================================================================\n";
        Sleep(2000);
        return;
    }

    cout << "Jumlah Item Yang Didapat  : ";
    getline(cin, inputmenu.isi.value);

    data.clear();
    data.seekp(0, ios::end);
    data << inputmenu.pk << "," << inputmenu.nama << "," << inputmenu.isi.harga << "," << inputmenu.isi.value << endl;

    data.open("menu.csv", ios::in | ios::out | ios::app);

    string ulang;
    while (true) {
        cout << "\nApakah ingin menambah data lagi [y/n]? ";
        cin >> ulang;
        if (ulang == "y" || ulang == "Y") {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            TambahMenu(data);
            break;
        } else if (ulang == "n" || ulang == "N") {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        } else {
            system("cls");
            cout << "========================================================================================================\n";
            cout << "\tTolong Masukan Y / N Saja, TOLONG!!! Pantek bodohnya eh" << endl;
            cout << "========================================================================================================\n";
            Sleep(1000);
        }
    }

}


void displaydata(fstream &data) {
    string line;
    data.clear();
    data.seekg(0, ios::beg);

    while (getline(data, line)) {
        stringstream ss(line);
        string nama, harga, value;
        getline(ss, nama, ',');
        getline(ss, harga, ',');
        getline(ss, value);

        cout << "Nama \t: " << nama << endl;
        cout << "Harga \t: Rp " << harga << endl;
        cout << "Value \t: " << value << endl;
        cout << "===============================" << endl;
    }
}

void insertionSort(string **data, int size) {
    for (int i = 1; i < size; i++) {
        string* current = data[i];
        int j = i - 1;
        while (j >= 0 && stoi(data[j][0]) > stoi(current[0])) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = current;
    }
}

void table(fstream &data) {
    string line;
    cout << "========================================================================\n";
    cout << "| No ||   ID   |     Nama Menu     |     Harga     |    Jumlah Item    |\n";
    cout << "========================================================================\n";
    data.clear();
    data.seekg(0, ios::beg);
    int i = 1;
    const int all_menu = 1000; // Anggap maksimal 1000 baris dalam file
    string** items = new string*[all_menu];
    while (getline(data, line)) {
        stringstream ss(line);
        string pk, nama, harga, value;
        getline(ss, pk, ',');
        getline(ss, nama, ',');
        getline(ss, harga, ',');
        getline(ss, value);
        items[i - 1] = new string[4]{pk, nama, harga, value};
        i++;
    }
    insertionSort(items, i - 1);
    for (int j = 0; j < i - 1; j++) {
        cout << "| " << setiosflags(ios::left) << setw(2) << j + 1 << " ||   " << setw(4) << items[j][0] << " | " << setw(17) << items[j][1] << " |     " << setw(9) << items[j][2] << " |    " << setw(14) << items[j][3] << " |\n";
        delete[] items[j]; // Dealokasi memori untuk setiap baris
    }
    delete[] items; // Dealokasi memori untuk array baris
    cout << "========================================================================\n";
}

void ubahMenu(fstream &data) {
    system("cls");
    table(data);
    cout << "====================================" << endl;
    cout << "    : : : UBAH DAFTAR MENU : : :    " << endl;
    cout << "====================================" << endl;
    cout << "ID Menu yang akan diubah: ";
    int idMenu;
    cin >> idMenu;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string line;
    bool found = false; // menyimpan apakah ID menu ditemukan atau tidak

    // Kembali ke awal file
    data.clear();
    data.seekg(0, ios::beg);

    fstream tempFile("temp.csv", ios::out); // File sementara untuk menulis data yang tidak akan diubah

    while (getline(data, line)) {
        stringstream ss(line);
        string pk, nama, harga, value;
        getline(ss, pk, ',');
        getline(ss, nama, ',');
        getline(ss, harga, ',');
        getline(ss, value, ',');

        int currentId;
        try {
            currentId = stoi(pk); // Mengonversi ID menu yang dibaca menjadi integer
        } catch (const std::invalid_argument& e) {
            cout << "Error: ID menu tidak valid." << endl;
            tempFile << line << endl; // Menulis baris tanpa perubahan ke file sementara
            continue;
        }

        if (currentId == idMenu) {
            Menu newMenuData;
            int newHarga; // Simpan harga baru
            string newValue; // Simpan value baru
            
            // Input data baru
            cout << "Masukkan Harga Baru\t\t: Rp ";
            string hargaStr;
            while (true) {
                getline(cin, hargaStr);
                try {
                    newHarga = stoi(hargaStr);
                    if (newHarga < 0) {
                        cout << "Error: Harga tidak boleh negatif." << endl;
                    } else {
                        break;
                    }
                } catch (const std::invalid_argument& e) {
                    cout << "Error: Masukkan harus berupa bilangan bulat." << endl;
                } catch (const std::out_of_range& e) {
                    cout << "Error: Harga terlalu besar." << endl;
                }
            }

            cout << "Masukkan Value Baru\t: ";
            getline(cin, newValue);

            // Menulis data baru ke file sementara
            tempFile << idMenu << "," << nama << "," << newHarga << "," << newValue << endl;
            found = true;
        } else {
            // Menulis baris tanpa perubahan ke file sementara
            tempFile << line << endl;
        }
    }

    tempFile.close(); // Menutup file sementara
    data.close(); // Menutup file utama

    // Menghapus file asli
    remove("menu.csv");
    // Mengganti nama file sementara menjadi file asli
    rename("temp.csv", "menu.csv");

    data.open("menu.csv", ios::in | ios::out);

    if (found) {
        system("cls");
        cout << "========================================================================================================\n";
        cout << "\tData berhasil diubah." << endl;
        cout << "========================================================================================================\n";
        Sleep(2000);
        perulanganAdmin();
    } else {
        system("cls");
        cout << "========================================================================================================\n";
        cout << "\t\tMenu tidak ditemukan." << endl;
        cout << "========================================================================================================\n";
        Sleep(2000);
    }
}

void hapusMenu(fstream &data) {
    table(data); // Menampilkan tabel data terlebih dahulu
    cout << "====================================" << endl;
    cout << "    : : : HAPUS DAFTAR MENU : : :    " << endl;
    cout << "=====================================" << endl;
    cout << "ID Menu yang akan dihapus: ";
    int idMenu;
    cin >> idMenu;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    system("cls"); // Menghapus layar setelah tabel ditampilkan

    string line;
    bool found = false;

    fstream newData("temp.csv", ios::out); // File sementara untuk menulis data yang tidak akan dihapus

    // Kembali ke awal file
    data.clear();
    data.seekg(0, ios::beg);

    while (getline(data, line)) {
        stringstream ss(line);
        string pk, nama, harga, value;
        getline(ss, pk, ',');
        getline(ss, nama, ',');
        getline(ss, harga, ',');
        getline(ss, value, ',');

        int currentId;
        try {
            currentId = stoi(pk); // Mengonversi ID menu yang dibaca menjadi integer
        } catch (const std::invalid_argument& e) {
            cout << "Error: ID menu tidak valid." << endl;
            newData << line << endl; // Menulis baris tanpa perubahan ke file sementara
            continue;
        }

        if (currentId != idMenu) {
            newData << line << endl; // Menulis baris tanpa perubahan ke file sementara
        } else {
            found = true;
        }
    }

    newData.close(); // Menutup file sementara
    data.close(); // Menutup file utama

    // Menghapus file asli
    remove("menu.csv");
    // Mengganti nama file sementara menjadi file asli
    rename("temp.csv", "menu.csv");
    // Buka kembali file utama untuk membaca data yang diperbarui
    data.open("menu.csv", ios::in | ios::out);

    if (found) {
        system("cls");
        cout << "========================================================================================================\n";
        cout << "Data berhasil dihapus." << endl;
        cout << "========================================================================================================\n";
        Sleep(2000);        
        perulanganAdmin();
    } else {
        system("cls");
        cout << "========================================================================================================\n";
        cout << "Menu tidak ditemukan." << endl;
        cout << "========================================================================================================\n";
        Sleep(2000);        
    }
}

void transaksi(){
    ifstream transactionData("transaksi.csv");
    if (!transactionData.is_open()) {
        cerr << "\t\t Tidak dapat membuka file transaksi.csv\n";
        return;
    }

    // Menampilkan header untuk riwayat transaksi
    system("cls");
    cout << "============================================================================\n";
    cout << "| No ||  Username  |     Nama Menu     |     Harga     |    Jumlah Item    |\n";
    cout << "============================================================================\n";

    int transactionCount = 1;

    // Mencetak riwayat transaksi sesuai dengan ID pengguna yang login
    string line;
    while (getline(transactionData, line)) {
        stringstream ss(line);
        string userIdInFile, username, namaMenu, harga, item;
        getline(ss, userIdInFile, ',');
        getline(ss, username, ',');
        getline(ss, namaMenu, ',');
        getline(ss, harga, ',');
        getline(ss, item, ',');

        // Cetak transaksi jika ID pengguna pada transaksi sama dengan ID pengguna yang login
            cout << "| " << setiosflags(ios::left) << setw(2) << transactionCount++  << " || " << setw(11) << username << " | " << setw(17) << namaMenu << " |     " << setw(9) << harga << " |    " << setw(14) << item << " |\n";
        }
    
    transactionData.close();

    // Menampilkan pesan jika tidak ada riwayat transaksi
    if (transactionCount == 1) {
        cout << "Tidak ada riwayat transaksi untuk pengguna ini.\n";
    }

    cout << "============================================================================\n";
    Sleep(5000); // Tahan layar untuk membaca pesan
    perulanganAdmin();
}



// =======================================================================================================================================================================
// PUNYA USER   PUNYA USER   PUNYA USER   PUNYA USER   PUNYA USER   PUNYA USER   PUNYA USER   PUNYA USER   PUNYA USER   PUNYA USER   PUNYA USER   PUNYA USER   PUNYA USER 
// =======================================================================================================================================================================


void loginUser() {
    system("cls");
    cout << ": : : Silahkan Isi Username Dan Password Anda : : :" << endl;
    cout << "===================================================" << endl;

    string inputPass;
    cout << "Masukkan Username: ";
    getline(cin, usernameLogin);

    cout << "Masukkan Password: ";
    inputPass = sensor();

    // Jika user adalah admin
    if (usernameLogin == "a" && inputPass == "a") {
        system("cls");
        cout << "========================================================================================================\n";
        cout << "\t\t\t\tLogin Berhasil sebagai Admin!" << endl;
        cout << "========================================================================================================\n";
        Sleep(2000);
        menuadmin();
    }

    int login = 1;
    const int total_login = 3;
    bool loginSuccess = false;

    while (login <= total_login) {
        // Membuka file datauser.csv untuk membaca data user
        fstream data("datauser.csv", ios::in);
        if (!data.is_open()) {
            cerr << "Error: Tidak dapat membuka file datauser.csv\n";
            return;
        }

        string line;
        while (getline(data, line)) {
            stringstream ss(line);
            string idStr, username, password;
            getline(ss, idStr, ',');
            getline(ss, username, ',');
            getline(ss, password, ',');

            if (username == usernameLogin && password == inputPass) {
                loginSuccess = true;
                break;
            }
        }
        data.close();

        if (loginSuccess) {
            system("cls");            
            cout << "========================================================================================================\n";
            cout << "\t\t\t\tLogin Berhasil!" << endl;
            cout << "========================================================================================================\n";
            Sleep(2000);
            return menuuser();
        } else {
            system("cls");
            cout << "========================================================================================================\n";
            cout << "\t\tLogin Gagal! Username Atau Password Aalah. Percobaan Ke-" << login << " dari " << total_login <<", \n\tJika Login Gagal Sebanyak 3x Maka Program Akan Berhenti Secara Paksa." << endl;
            cout << "========================================================================================================\n";
            Sleep(2000);
            login++;
            cout << "Masukkan Username: ";
            getline(cin, usernameLogin);

            cout << "Masukkan Password: ";
            inputPass = sensor();
        }
    }

    // Jika sudah 3 kali gagal login
    system("cls");
    cout << "========================================================================================================\n";
    cout << "\t\t\tAnda Sudah Gagal Tes CPNS Sebanyak 3 Kali. Cobalah Beberapa Saat Lagi." << endl;
    cout << "========================================================================================================\n";
    Sleep(2000);
    exit(0);
}


string sensor() {
    string password;
    char ch;
    while ((ch = getch()) != '\r') { // '\r' adalah kode ASCII untuk Enter
        if (ch == '\b') { // '\b' adalah kode ASCII untuk Backspace
            if (!password.empty()) {
                cout << "\b \b";
                password.pop_back();
            }
        } else {
            cout << '*';
            password.push_back(ch);
        }
    }
    cout << endl;
    return password;
}


int IDotomatis(const string &filename) {
    fstream data(filename, ios::in);
    if (!data.is_open()) {
        cerr << "Error: Tidak dapat membuka file " << filename << "\n";
        return 1;
    }
    
    string line;
    int maxId = 116;
    while (getline(data, line)) {
        stringstream ss(line);
        string temp;
        getline(ss, temp, ',');
        int currentId = stoi(temp);
        if (currentId > maxId) {
            maxId = currentId;
        }
    }
    data.close();
    return maxId + 1 ;
}


void regisuser() {
    User newUser;
    system("cls");
    headeruser();
    cout << "                                            REGISTRASI                                                  \n";
    cout << "========================================================================================================\n";

    // Mendapatkan ID unik berikutnya
    newUser.id = IDotomatis("datauser.csv");

    cout << "Masukkan Username      : ";
    getline(cin, newUser.usr);

    cout << "Masukkan Password      : ";
    getline(cin, newUser.pass);

    cout << "Masukkan Nama Bank     : ";
    string bankName;
    getline(cin, bankName);
    
    for (char& c : bankName) {
        c = toupper(c);
    }

    while (true) {
        cout << "Masukkan Nomor Rekening: ";
        string rekStr;
        getline(cin, rekStr);
        try {
            newUser.bank.rek = stoi(rekStr);
            if (newUser.bank.rek < 0) {
                cout << "\t\t\tNomor Rekening tidak boleh negatif." << endl;
                Sleep(1000);
            } else {
                break;
            }
        } catch (const std::invalid_argument& e) {
            cout << "\t\t\tMasukkan harus berupa bilangan bulat." << endl;
            Sleep(1000);
        } catch (const std::out_of_range& e) {
            cout << "\t\t\tNomor Rekening terlalu besar." << endl;
            Sleep(1000);
        }
    }

    while (true) {
        cout << "Masukkan PIN Bank      : ";
        string pinStr;
        getline(cin, pinStr);
        try {
            if (pinStr.length() != 6) {
                throw out_of_range("PIN harus terdiri dari 6 digit.");
            }
            newUser.bank.pin = stoi(pinStr);
            if (newUser.bank.pin < 0) {
                cout << "\t\t\tPIN Bank tidak boleh negatif." << endl;
                Sleep(1000);
            } else {
                break;
            }
        } catch (const std::invalid_argument& e) {
            cout << "\t\t\tMasukkan harus berupa bilangan bulat." << endl;
            Sleep(1000);
        } catch (const std::out_of_range& e) {
            cout << "\t\t\tPIN harus terdiri dari 6 digit." << endl;
            Sleep(1000);
        }
    }

    // Mengecek duplikasi data
    fstream data("datauser.csv", ios::in);
    if (!data.is_open()) {
        cerr << "Error: Tidak dapat membuka file datauser.csv\n";
        return;
    }

    string line;
    bool duplicate = false;
    while (getline(data, line)) {
        stringstream ss(line);
        string idStr, username, password, bank, saldo, norek, pin;
        getline(ss, idStr, ',');
        getline(ss, username, ',');
        getline(ss, password, ',');
        getline(ss, bank, ',');
        getline(ss, saldo, ',');
        getline(ss, norek, ',');
        getline(ss, pin, ',');

        if (username == newUser.usr && stoi(norek) == newUser.bank.rek && bankName == bank) {
            duplicate = true;
            break;
        }
    }
    data.close();

    if (duplicate) {
        system("cls");
        cout << "========================================================================================================\n";
        cout << "\t\tSudah ada data dengan Nama, Bank dan Nomor Rekening yang sama" << endl;
        cout << "========================================================================================================\n";
        Sleep(2000);
        regisuser(); // memanggil ulang fungsi registrasi untuk mengulang proses
        return;
    }

    newUser.bank.saldo = 0; // Set saldo awal ke 0

    data.open("datauser.csv", ios::out | ios::app);
    if (!data.is_open()) {
        cerr << "Tidak dapat membuka file datauser.csv\n";
        return;
    }

    // Menulis data user baru ke file
    data << newUser.id << ","
         << newUser.usr << ","
         << newUser.pass << ","
         << bankName << ","
         << newUser.bank.saldo << ","
         << newUser.bank.rek << ","
         << newUser.bank.pin << "\n";
    data.close();

}


void menuuser() {
    fstream data;
    cekdatausr(data);
    cekdatatransaksi(data);
    int pilihan;
    enum option { Topup = 1, Saldo, Menu, Cari, Bayar, pinis };

    while (true) {
        pilihan = UserOption();
        switch (pilihan) {
            case Topup:
                topUpSaldo();
                break;
            case Saldo:
                lihatSaldo();
                break;
            case Menu:
                orderMenu();
                break;
            case Cari:
                searchMenu();
                break;
            case Bayar:
                Riwayattransaksi();
                break;
            case pinis:
                system("cls");
                cout << "========================================================================================================\n";
                cout << "\tSesungguhnya Kesempurnaan Hanya Milik Tuhan Yang Maha Esa *Emote Semyum*" << endl;
                cout << "========================================================================================================\n";
                Sleep(2000); 
                return;
            default:
                system("cls");
                cout << "========================================================================================================\n";
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                cout << "========================================================================================================\n";
                Sleep(2000); 
        }
    }
}


void topUpSaldo() {
    system("cls");
    headeruser();
    string bankInput, saldoStr, inputPin;

    cout << "==================================\n" << endl;
    cout << "Masukkan Bank         : ";
    cin >> bankInput ;
    for (char& c : bankInput) {
        c = toupper(c);
    }
    cout << "Masukkan PIN Anda     : ";
    inputPin = sensor();

    for (char& c : inputPin) {
        c = toupper(c);
    }

    fstream data("datauser.csv", ios::in | ios::out);
    if (!data.is_open()) {
        cerr << "Error: Tidak dapat membuka file datauser.csv\n";
        return;
    }

    string line;
    stringstream databaru;
    bool bankFound = false;

    while (getline(data, line)) {
        stringstream ss(line);
        string idStr, Username, password, bank, saldo, norek, Pin;
        getline(ss, idStr, ',');
        getline(ss, Username, ',');
        getline(ss, password, ',');
        getline(ss, bank, ',');
        getline(ss, saldo, ',');
        getline(ss, norek, ',');
        getline(ss, Pin, ',');

        for (char& c : bank) {
            c = toupper(c);
        }

        for (char& c : Pin) {
            c = toupper(c);
        }

        if (usernameLogin == Username && bank == bankInput && Pin == inputPin) {
            bankFound = true;
            cout << "==================================\n";
            cout << "Saldo saat ini: " << saldo << endl;
            cout << "==================================\n";
            cout << "Masukkan Jumlah Top Up : ";
            int jumlahtopup;
            cin >> jumlahtopup;

            if (cin.fail() || jumlahtopup < 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                system("cls");
                cout << "========================================================================================================\n";
                cout << "\t\t\t\tJumlah tidak valid. Top up dibatalkan. Yakali Top Up Minus\n\t\t\t\tYang Bener Aja Rugi Dong";
                cout << "========================================================================================================\n";
                Sleep(2000);
                return;
            }

            int currentSaldo = stoi(saldo);
            currentSaldo += jumlahtopup;
            saldoStr = to_string(currentSaldo);

            databaru << idStr << "," << Username << "," << password << "," << bank << "," << saldoStr << "," << norek << "," << Pin << "\n";
        } else {
            databaru << line << "\n";
        }
    }

    data.close();

    if (!bankFound) {
        system("cls");
        cout << "========================================================================================================\n";
        cout << "Bank atau Pin Yang Anda Masukan Salah, Mohon Untuk Memasukan Bank Atau Pin Yang Sudah Terdaftar.\n";
        cout << "========================================================================================================\n";
        Sleep(2000);
        return;
    }

    fstream outFile("datauser.csv", ios::out | ios::trunc);
    outFile << databaru.str();
    outFile.close();

    system("cls");
    cout << "========================================================================================================\n";
    cout << "\t\tTop up berhasil !!!!!\n\t    Saldo Anda Saat Ini: " << saldoStr << endl;
    cout << "========================================================================================================\n";
    Sleep(2000);
    perulanganUser();
}


void lihatSaldo() {
    system("cls");
    headeruser();

    fstream data("datauser.csv", ios::in);
    if (!data.is_open()) {
        cerr << "Error: Tidak dapat membuka file datauser.csv\n";
        return;
    }

    string line;
    while (getline(data, line)) {
        stringstream ss(line);
        string idStr, Username, password, bank, saldo, norek, Pin;
        getline(ss, idStr, ',');
        getline(ss, Username, ',');
        getline(ss, password, ',');
        getline(ss, bank, ',');
        getline(ss, saldo, ',');
        getline(ss, norek, ',');
        getline(ss, Pin, ',');

        if (Username == usernameLogin) {
            cout << "                                    Informasi Saldo\n";
            cout << "========================================================================================================\n";
            cout << "Username       : " << Username << endl;
            cout << "Bank           : " << bank << endl;
            cout << "Nomor Rekening : " << norek << endl;
            cout << "Saldo          : Rp " << saldo << endl;
            cout << "========================================================================================================\n";
            Sleep(5000);
            data.close();
            return;
        }
    }
}


int UserOption() {
    int input;
    while (true) {
        system("cls");
        headeruser();
        cout << "\n       Menu Yang Ada       " << endl;
        cout << "============================" << endl;
        cout << "   [1] Top Up Saldo" << endl;
        cout << "   [2] Lihat Saldo" << endl;
        cout << "   [3] Order Disini" << endl;
        cout << "   [4] Bantuan Pencarian" << endl;
        cout << "   [5] Riwayat Transaksi" << endl;
        cout << "   [6] Walk Out" << endl;
        cout << "============================" << endl;
        cout << "Masukan Pilihan { 1 - 6 } : ";
        cin >> input;

        if (cin.fail() || input < 1 || input > 6) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            cout << "========================================================================================================\n";
            cout << "\tPilihan tidak valid. Silakan masukkan angka antara 1 dan 4 saja." << endl;
            cout << "========================================================================================================\n";
            Sleep(2000);
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return input;
        }
    }
}


int Option() {
    int input;
    while (true) {
        system("cls");
        cout << "\t\t\tSelamat Datang, Silahkan Registrasi Jika Belum Mempunyai Akun       " << endl;
        cout << "========================================================================================================\n";
        cout << "   [1] Login" << endl;
        cout << "   [2] Registrasi" << endl;
        cout << "   [3] Keluar Program" << endl;
        cout << "============================" << endl;
        cout << "Masukan Pilihan { 1 - 3 } : ";
        cin >> input;

        if (cin.fail() || input < 1 || input > 3) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            cout << "========================================================================================================\n";
            cout << "\tPilihan tidak valid. Silakan masukkan angka antara 1 dan 3 saja." << endl;
            cout << "========================================================================================================\n";
            Sleep(2000);
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return input;
        }
    }
}


void cekdatausr(fstream &data) {
    data.open("datauser.csv", ios::in | ios::out | ios::app);
    if (!data.is_open()) {
        cout << "Data ga ada, ini buat baru" << endl;
        data.open("datauser.csv", ios::out | ios::in | ios::app);
    }
}


void cekdatatransaksi(fstream &data) {
    data.open("tansaksi.csv", ios::in | ios::out | ios::app);
    if (!data.is_open()) {
        cout << "Data ga ada, ini buat baru" << endl;
        data.open("transaksi.csv", ios::out | ios::in | ios::app);
    }
}


bool perulanganUser() {
    char Pilihan;
    while (true) {
        cout << "========================================================" << endl;
        cout << " \nApakah Anda Ingin Mengulangi Program? (y/n)\ny = Kembali Ke Menu\nn = Close Program(exit)\n " << endl;
        cout << "========================================================" << endl;
        cout << "Pilihan Anda >> ";
        cin >> Pilihan;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        Pilihan = tolower(Pilihan);
        if (Pilihan == 'y') {
            return true;
        } else if (Pilihan == 'n') {
            main();
            return false;
        } else {
            system("cls");
            cout << "========================================================================================================\n";
            cout << "\tInput tidak valid. Silakan masukkan 'y' untuk ya atau 'n' untuk tidak,\n\t\t Wes Gede Kok Gak Ngerti Huruf N Dan Y ,tll" << endl;
            cout << "========================================================================================================\n";
            Sleep(2000);
        }
    }
}


void headeruser(){

    cout << "\t\t\t\t\tSelamat Datang Di DONA\n\t\t\t\tSelamat Menikmati Apa Yang Sudah Kami Buat\n\t\t\tSemangat Ya, Aku Tau Ini Berat Tapi, Pinjam Dulu Seratus !!!\n\t\t\t\t\t     *emot senyum* " << endl;
    cout << "========================================================================================================\n";
}


void searchMenu() {
    system("cls");
    headeruser();
    ifstream menuData("menu.csv");
    if (!menuData.is_open()) {
        cerr << "Error: Tidak dapat membuka file menu.csv\n";
        return;
    }

    // Menggunakan array pointer dua dimensi
    string **items = new string*[jml];
    for (int i = 0; i < jml; ++i)
        items[i] = new string[4];

    int itemCount = 0;

    // Membaca data menu dari file
    string line;
    while (getline(menuData, line) && itemCount < jml) {
        stringstream ss(line);
        getline(ss, items[itemCount][0], ','); // pk
        getline(ss, items[itemCount][1], ','); // nama
        getline(ss, items[itemCount][2], ','); // harga
        getline(ss, items[itemCount][3]);      // value
        itemCount++;
    }
    menuData.close();

    // Melakukan pengurutan item berdasarkan nama menu
    // Menggunakan insertion sort
    for (int i = 1; i < itemCount; i++) {
        string* current = items[i];
        int j = i - 1;
        while (j >= 0 && items[j][1] > current[1]) {
            items[j + 1] = items[j];
            j--;
        }
        items[j + 1] = current;
    }

    // Meminta kata kunci dari pengguna
    string keyword;
    cout << "Masukkan nama menu yang ingin Anda cari: ";
    getline(cin, keyword);

    // Melakukan pencarian berdasarkan kata kunci
    cout << "========================================================================\n";
    cout << "| No ||   ID   |     Nama Menu     |     Harga     |    Jumlah Item    |\n";
    cout << "========================================================================\n";

    // Menampilkan semua hasil pencarian yang sama
    bool found = false;
    for (int i = 0; i < itemCount; ++i) {
        if (items[i][1] == keyword) {
            found = true;
            cout << "| " << setiosflags(ios::left) << setw(2) << i + 1 << " ||   " << setw(4) << items[i][0] << " | " << setw(17) << items[i][1] << " |     " << setw(9) << items[i][2] << " |    " << setw(14) << items[i][3] << " |\n";
        } 
    }
    cout << "========================================================================\n";
    if (!found) {
        cout << "Menu dengan kata kunci \"" << keyword << "\" tidak ditemukan.\n";
    }

    // Dealokasi memori array pointer
    for (int i = 0; i < jml; ++i)
        delete[] items[i];
    delete[] items;

    perulanganUser();
}


void Riwayattransaksi() {
    system("cls");
    ifstream data("datauser.csv");
    if (!data.is_open()) {
        cerr << "Error: Tidak dapat membuka file datauser.csv\n";
        return;
    }

    string line;
    string userId;
    bool userFound = false;

    // Mencari ID berdasarkan username
    while (getline(data, line)) {
        stringstream ss(line);
        string idStr, Username, password, bank, saldo, norek, Pin;
        getline(ss, idStr, ',');
        getline(ss, Username, ',');
        getline(ss, password, ',');
        getline(ss, bank, ',');
        getline(ss, saldo, ',');
        getline(ss, norek, ',');
        getline(ss, Pin, ',');

        if (Username == usernameLogin) {
            userId = idStr;
            userFound = true;
            break;
        }
    }
    data.close();

    if (!userFound) {
        system("cls");
        cout << "========================================================================================================\n";
        cout << "Username tidak ditemukan dalam database.\n";
        cout << "========================================================================================================\n";
        Sleep(2000);
        return;
    }

    ifstream transactionData("transaksi.csv");
    if (!transactionData.is_open()) {
        cerr << "\t\t Tidak dapat membuka file transaksi.csv\n";
        return;
    }

    // Menampilkan header untuk riwayat transaksi
    system("cls");
    cout << "============================================================================\n";
    cout << "| No ||  Username  |     Nama Menu     |     Harga     |    Jumlah Item    |\n";
    cout << "============================================================================\n";

    int transactionCount = 1;

    // Mencetak riwayat transaksi sesuai dengan ID pengguna yang login
    while (getline(transactionData, line)) {
        stringstream ss(line);
        string userIdInFile, username, namaMenu, harga, item;
        getline(ss, userIdInFile, ',');
        getline(ss, username, ',');
        getline(ss, namaMenu, ',');
        getline(ss, harga, ',');
        getline(ss, item, ',');

        // Cetak transaksi jika ID pengguna pada transaksi sama dengan ID pengguna yang login
        if (userIdInFile == userId) {
            cout << "| " << setiosflags(ios::left) << setw(2) << transactionCount++  << " || " << setw(11) << username << " | " << setw(17) << namaMenu << " |     " << setw(9) << harga << " |    " << setw(14) << item << " |\n";
        }
    }
    transactionData.close();

    // Menampilkan pesan jika tidak ada riwayat transaksi
    if (transactionCount == 1) {
        cout << "Tidak ada riwayat transaksi untuk pengguna ini.\n";
    }

    cout << "============================================================================\n";
    Sleep(5000); // Tahan layar untuk membaca pesan
    perulanganUser();
}


void orderMenu() {
    system("cls");
    ifstream data("datauser.csv");
    if (!data.is_open()) {
        cerr << "Error: Tidak dapat membuka file datauser.csv\n";
        return;
    }

    string line;
    string userId;
    int saldoUser;
    bool userFound = false;

    int saldo_int;
    // Mencari ID dan saldo berdasarkan username
    while (getline(data, line)) {
        stringstream ss(line);
        string idStr, Username, password, bank, saldo, norek, Pin;
        getline(ss, idStr, ',');
        getline(ss, Username, ',');
        getline(ss, password, ',');
        getline(ss, bank, ',');
        getline(ss, saldo, ',');
        getline(ss, norek, ',');
        getline(ss, Pin, ',');
        stringstream saldo_str(saldo);
        saldo_str>>saldo_int;

        if (Username == usernameLogin) {
            userId = idStr;
            saldoUser = saldo_int;
            userFound = true;
            break;
        }
    }
    data.close();

    fstream menuData("menu.csv");
    if (!menuData.is_open()) {
        cerr << "Error: Tidak dapat membuka file menu.csv\n";
        return;
    }

    // Menampilkan tabel menu
    system("cls");
    cout << "========================================================================\n";
    cout << "| No ||   ID   |     Nama Menu     |     Harga     |    Jumlah Item    |\n";
    cout << "========================================================================\n";


    int itemCount = 0;

    string pk, nama, harga, value;
    int pk_int, harga_int;

    while (getline(menuData, line) && itemCount < jml) {
        stringstream ss(line);
        getline(ss, pk, ',');
        getline(ss, nama, ',');
        getline(ss, harga, ',');
        getline(ss, value, '\n');
        stringstream pk_str(pk);
        pk_str>>pk_int;
        stringstream harga_str(harga);
        harga_str>>harga_int;
        itm[itemCount].pk = pk_int;
        itm[itemCount].nama = nama;
        itm[itemCount].isi.harga = harga_int;
        itm[itemCount].isi.value = value;
        itemCount++;
    }
    menuData.close();

    // Menampilkan item-menu dari array
    for (int j = 0; j < itemCount; j++) {
        cout << "| " << setiosflags(ios::left) << setw(2) << j + 1 << " ||   " << setw(4) << itm[j].pk << " | " << setw(17) << itm[j].nama << " |     " << setw(9) << itm[j].isi.harga << " |    " << setw(14) << itm[j].isi.value << " |\n";
    }

    cout << "========================================================================\n";

    int choice;
    while (true) {
        cout << "Pilih Nomor Menu Yang Ingin Dipesan : ";
        cin >> choice;
        if (cin.fail() || choice < 1 || choice >= itemCount + 1) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "========================================================================================================\n";
            cout << "\tPilihan tidak valid. Silakan masukkan nomor menu yang valid." << endl;
            cout << "========================================================================================================\n";
            Sleep(2000);
        } else {
            break;
        }
    }

    int hargaitem = itm[choice-1].isi.harga;

    // Periksa apakah saldo mencukupi
    if (saldoUser < hargaitem) {
        cout << "Saldo tidak mencukupi untuk pesanan ini.\n";
        return;
    }

    // Kurangi saldo
    saldoUser -= hargaitem;


    // Perbarui saldo dalam file datauser.csv
    fstream dataUpdate;
    dataUpdate.open("datauser.csv", ios::in);
    if (!dataUpdate.is_open()) {
        cerr << "Error: Tidak dapat membuka file datauser.csv\n";
        return;
    }

    int index = 0;
    while (getline(dataUpdate, line)) {
        stringstream ss(line);
        int saldo_int;
        string idStr, Username, password, bank, saldo, norek, Pin;
        getline(ss, idStr, ',');
        getline(ss, Username, ',');
        getline(ss, password, ',');
        getline(ss, bank, ',');
        getline(ss, saldo, ','); // Perbarui saldo di sini
        getline(ss, norek, ',');
        getline(ss, Pin, '\n');

        stringstream saldo_str(saldo);
        saldo_str >> saldo_int;

        int idint = stoi(idStr);
        int norekint = stoi(norek);
        int pinint = stoi(Pin);

        usr[index].id = idint;
        usr[index].usr = Username;
        usr[index].pass = password;
        usr[index].bankName = bank;
        usr[index].bank.saldo = saldo_int;
        usr[index].bank.rek = norekint;
        usr[index].bank.pin = pinint;
        index++;

    }
    dataUpdate.close();

    dataUpdate.open("datauser.csv", ios::out | ios::trunc);
    int saldoUpdate;
    for (int i = 0; i < index; i++){
        if (usr[i].usr == usernameLogin) {
            saldoUpdate = saldoUser;
        } else {
            saldoUpdate = usr[i].bank.saldo;
        }
        dataUpdate << usr[i].id << "," << usr[i].usr << "," << usr[i].pass << "," << usr[i].bankName << "," << saldoUpdate << "," << usr[i].bank.rek << "," << usr[i].bank.pin << "\n";
    }
    dataUpdate.close();

    // Menambahkan pesanan ke file transaksi.csv
    ofstream transaksiFile("transaksi.csv", ios::out | ios::app);
    if (!transaksiFile.is_open()) {
        cerr << "Error: Tidak dapat membuka file transaksi.csv\n";
        return;
    }

    transaksiFile << userId << "," << usernameLogin << "," << itm[choice - 1].nama << "," << itm[choice - 1].isi.harga << "," << itm[choice - 1].isi.value << "\n";

    transaksiFile.close();

    system("cls");
    cout << "========================================================================================================\n";
    cout << "Pesanan Berhasil Ditambahkan Ke Transaksi\n";
    cout << "Terima Kasih Atas Pesanan Anda!\n";
    cout << "========================================================================================================\n";
    perulanganUser();
}