#include <iostream>
#include <string>

using namespace std;

// Fungsi untuk konversi Kilometer/jam ke unit yang dipilih
double KmPerJ(double nilai, int pilih) {
    switch (pilih) {
        case 1: // Km/j ke Cm/dtk
            return nilai * 100000 / 3600;
        case 2: // Km/j ke Meter/dtk
            return nilai * 1000 / 3600;
        case 3: // Km/j ke Mil/j
            return nilai / 1.609;
        default:
            return 0;
    }
}

// Fungsi untuk konversi Centimeter/detik ke unit yang dipilih
double CmPerD(double nilai, int pilih) {
    switch (pilih) {
        case 1: // Cm/dtk ke Kilometer/j
            return nilai * 0.036;
        case 2: // Cm/dtk ke Meter/dtk
            return nilai / 100;
        case 3: // Cm/dtk ke Mil/j
            return nilai * 0.022;
        default:
            return 0;
    }
}

// Fungsi untuk konversi Meter/detik ke unit yang dipilih
double MPerD(double nilai, int pilih) {
    switch (pilih) {
        case 1: // M/dtk ke Km/j
            return nilai * 3.6;
        case 2: // M/dtk ke Cm/dtk
            return nilai * 100;
        case 3: // M/dtk ke Mil/j
            return nilai * 2.237;
        default:
            return 0;
    }
}

// Fungsi untuk konversi Mil/jam ke unit yang dipilih
double MilPerJ(double nilai, int pilih) {
    switch (pilih) {
        case 1: // Mil/j ke Km/j
            return nilai * 1.609;
        case 2: // Mil/j ke Cm/dtk
            return nilai * 44.704;
        case 3: // Mil/j ke M/dtk
            return nilai * 0.447;
        default:
            return 0;
    }
}

int main() {
    std::string usr, pswd;
    int count = 0;

    while (count < 3) {
        cout << "Masukkan Nama Sebagai Username : ";
        getline(cin, usr);
        cout << "Masukkan 3 NIM terakhir Sebagai Password: ";
        getline(cin, pswd);

        if (usr == "Christian Mahatma Bima Alpindo" && pswd == "079") {
            cout << "\n\n\nLogin Berhasil!\n\n\n";
            cout << "====Selamat datang Di Sistem konversi Kecepatan====\n\n\n";
            break;
        } else {
            count++;
            cout << "Login Gagal! Silakan Coba Lagi.\n";
        }
    }

    if (count == 3) {
        cout << "Kesempatan Login Anda Sudah Habis.\n Program Akan DIberhentikan Secara Paksa.\n";
        return 0;
    }
    int pilihMenu;
    double nilai;
    char ulangi;

    do {
        cout << "Pilih menu konversi:\n"
                    "[1] Kilometer/jam\n"
                    "[2] Centimeter/detik\n"
                    "[3] Meter/detik\n"
                    "[4] Mil/jam\n"
                "Masukkan Pilihan Anda: ";
        cin >> pilihMenu;

        cout << "Masukkan Angka Kecepatan: ";
        cin >> nilai;

        switch (pilihMenu) {
            case 1: {
                int pilih;
                cout << "\n\nPilih konversi : \n"
                            "[1] Centimeter/detik\n"
                            "[2] Meter/detik\n"
                            "[3] Mil/jam\n" 
                        "\nMasukkan Pilihan Anda: ";
                cin >> pilih;
                cout << "Hasil konversi: " << KmPerJ(nilai, pilih) << endl;
                break;
            }
            case 2: {
                int pilih;
                cout << "\n\nPilih konversi : \n"
                            "[1] Kilometer/detik\n"
                            "[2] Meter/detik\n"
                            "[3] Mil/jam\n" 
                        "\nMasukkan Pilihan Anda: ";
                cin >> pilih;
                cout << "Hasil konversi: " << CmPerD(nilai, pilih) << endl;
                break;
            }
            case 3: {
                int pilih;
                cout << "\n\nPilih konversi : \n"
                            "[1] Kilometer/detik\n"
                            "[2] Centimeter/detik\n"
                            "[3] Mil/jam\n" 
                        "\nMasukkan Pilihan Anda: ";
                cin >> pilih;
                cout << "Hasil konversi: " << MPerD(nilai, pilih) << endl;
                break;
            }
            case 4: {
                int pilih;
                cout << "\n\nPilih konversi : \n"
                            "[1] Kilometer/detik\n"
                            "[2] Centimeter/detik\n"
                            "[3] Meter/jam\n" 
                        "\nMasukkan Pilihan Anda: ";
                cin >> pilih;
                cout << "Hasil konversi: " << MilPerJ(nilai, pilih) << endl;
                break;
            }
            default:
                cout << "Masukan Angka 1 Sampai 4 Saja!!";
        }

        cout << "\n\n\nApakah Anda ingin melakukan konversi lagi? (y/n): ";
        cin >> ulangi;
    } while (ulangi == 'y' || ulangi == 'Y');

    cout << "Terima kasih telah menggunakan Sistem Kami, \n"
                "Berakit-rakit Ke Hulu, Berenang-renang Ke Tepian\n"
                "=================CAPEK==========================\n"
                "Wassalamualaikum Wr Wb";

    return 0;
}