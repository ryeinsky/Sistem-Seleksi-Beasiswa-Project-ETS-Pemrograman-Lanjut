#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <limits>

using namespace std;

// =========================================================================
// STRUKTUR DATA MAHASISWA
// =========================================================================
struct Mahasiswa {
    string npm;
    string nama;
    double nilai1, nilai2, nilai3;
    double rataRata;
    string status; // "Lolos" atau "Tidak Lolos"
};

// =========================================================================
// SYARAT 2: PERMASALAHAN DENGAN FUNGSI ITERASI DAN REKURSIF
// =========================================================================

// Menghitung total nilai secara iteratif (perulangan for)
double totalIteratif(double nilai[], int n) {
    double total = 0;
    for (int i = 0; i < n; i++) {
        total += nilai[i];
    }
    return total;
}

// Menghitung total nilai secara rekursif (memanggil dirinya sendiri)
double totalRekursif(double nilai[], int n) {
    if (n <= 0) {
        return 0;
    }
    return nilai[n - 1] + totalRekursif(nilai, n - 1);
}

// Menghitung rata-rata nilai
double hitungRataRata(double nilai[], int n) {
    return totalIteratif(nilai, n) / n;
}

// Fungsi menentukan kelolosan beasiswa
string seleksiBeasiswa(double rataRata) {
    if (rataRata >= 80.0) {
        return "Lolos";
    } else {
        return "Tidak Lolos";
    }
}

// =========================================================================
// SYARAT 1: PROSEDUR MEMANGGIL FUNGSI & FUNGSI MEMANGGIL PROSEDUR
// =========================================================================

// Contoh Prosedur (void) yang memanggil Fungsi (non-void):
// Prosedur 'cetakBarisMahasiswa' memanggil fungsi 'seleksiBeasiswa()'
void cetakBarisMahasiswa(Mahasiswa m, int peringkat) {
    string hasilStatus = seleksiBeasiswa(m.rataRata); // <- Prosedur memanggil fungsi

    cout << left << setw(10) << peringkat
         << setw(16) << m.npm
         << setw(22) << m.nama
         << setw(14) << fixed << setprecision(2) << m.rataRata
         << setw(14) << hasilStatus
         << "\n";
}

// Prosedur mencetak log notifikasi
void cetakPesanLog(string pesan) {
    cout << "[INFO SISTEM] " << pesan << "\n";
}

// Contoh Fungsi (non-void) yang memanggil Prosedur (void):
// Fungsi 'tambahMahasiswa' memanggil prosedur 'cetakPesanLog()'
bool tambahMahasiswa(Mahasiswa& m, vector<Mahasiswa>& daftar) {
    double arrNilai[] = {m.nilai1, m.nilai2, m.nilai3};
    m.rataRata = hitungRataRata(arrNilai, 3);
    m.status = seleksiBeasiswa(m.rataRata);

    daftar.push_back(m);

    // Fungsi memanggil prosedur di bawah ini:
    cetakPesanLog("Data mahasiswa " + m.nama + " berhasil disimpan ke memori.");
    return true;
}

// =========================================================================
// FITUR FILE HANDLING (MENYIMPAN & MEMBACA FILE CSV)
// =========================================================================

// Menyimpan data mahasiswa ke file CSV
void simpanKeCSV(const vector<Mahasiswa>& daftar, string namaFile = "data_mahasiswa.csv") {
    ofstream file(namaFile);

    if (!file.is_open()) {
        cout << "Gagal membuat file " << namaFile << "!\n";
        return;
    }

    // Tulis header tabel CSV
    file << "NPM,Nama,Nilai1,Nilai2,Nilai3,RataRata,Status\n";

    // Tulis isi data per baris
    for (size_t i = 0; i < daftar.size(); i++) {
        file << daftar[i].npm << ","
             << daftar[i].nama << ","
             << daftar[i].nilai1 << ","
             << daftar[i].nilai2 << ","
             << daftar[i].nilai3 << ","
             << fixed << setprecision(2) << daftar[i].rataRata << ","
             << daftar[i].status << "\n";
    }

    file.close();
    cout << "\n>> Data berhasil disimpan ke file: " << namaFile << " <<\n";
    cout << "(File CSV ini bisa Anda buka di Notepad maupun Microsoft Excel)\n";
}

// Membaca data mahasiswa dari file CSV
void bacaDariCSV(string namaFile = "data_mahasiswa.csv") {
    ifstream file(namaFile);

    if (!file.is_open()) {
        cout << "\nFile " << namaFile << " belum ada! Silakan input data terlebih dahulu.\n";
        return;
    }

    cout << "\n============================================================\n";
    cout << "          ISI FILE: " << namaFile << "\n";
    cout << "============================================================\n";

    string baris;
    while (getline(file, baris)) {
        cout << baris << "\n";
    }

    file.close();
    cout << "============================================================\n";
}

// =========================================================================
// SYARAT 4: TIGA ALGORITMA SORTING UNTUK DATA BESAR (>= 100.000 DATA)
// =========================================================================

// 1. Bubble Sort (O(n^2))
void bubbleSort(vector<double>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool adaTukar = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) { // descending (terbesar ke terkecil)
                swap(arr[j], arr[j + 1]);
                adaTukar = true;
            }
        }
        if (!adaTukar) break; // Berhenti jika sudah urut
    }
}

// 2. Selection Sort (O(n^2))
void selectionSort(vector<double>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIdx]) {
                maxIdx = j;
            }
        }
        if (maxIdx != i) {
            swap(arr[i], arr[maxIdx]);
        }
    }
}

// 3. Quick Sort (O(n log n))
int partisi(vector<double>& arr, int low, int high) {
    double pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] > pivot) { // descending
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<double>& arr, int low, int high) {
    if (low < high) {
        int pi = partisi(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// =========================================================================
// UJI BENCHMARK SORTING PADA 100.000 DATA
// =========================================================================
void ujiSorting100k(int jumlahData = 100000) {
    cout << "\n============================================================\n";
    cout << "     UJI 3 ALGORITMA SORTING PADA " << jumlahData << " DATA\n";
    cout << "============================================================\n";

    cout << "1. Meng-generate " << jumlahData << " data nilai acak dengan rand()...\n";
    vector<double> dataMaster(jumlahData);
    for (int i = 0; i < jumlahData; i++) {
        dataMaster[i] = (rand() % 10000) / 100.0; // nilai acak 0.00 - 100.00
    }
    cout << "   -> Data selesai dibuat!\n\n";

    // --- Uji Quick Sort ---
    cout << "2. Menguji QUICK SORT (O(n log n))...\n";
    vector<double> dataQuick = dataMaster;
    clock_t mulaiQ = clock();
    quickSort(dataQuick, 0, dataQuick.size() - 1);
    clock_t selesaiQ = clock();
    double detikQuick = (double)(selesaiQ - mulaiQ) / CLOCKS_PER_SEC;
    cout << "   -> Selesai dalam: " << detikQuick << " detik\n\n";

    // --- Pilihan Uji Bubble & Selection Sort ---
    double detikSelection = -1.0;
    double detikBubble = -1.0;

    cout << "Catatan: Bubble Sort & Selection Sort (O(n^2)) membutuhkan 10 miliar operasi\n";
    cout << "sehingga memerlukan waktu 10-40 detik untuk 100.000 data.\n";
    cout << "Apakah ingin menjalankan pengujian Selection & Bubble Sort sekarang? (y/n): ";
    char pilihan;
    cin >> pilihan;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (pilihan == 'y' || pilihan == 'Y') {
        cout << "\n3. Menguji SELECTION SORT (O(n^2))... Mohon tunggu...\n";
        vector<double> dataSel = dataMaster;
        clock_t mulaiS = clock();
        selectionSort(dataSel);
        clock_t selesaiS = clock();
        detikSelection = (double)(selesaiS - mulaiS) / CLOCKS_PER_SEC;
        cout << "   -> Selesai dalam: " << detikSelection << " detik\n\n";

        cout << "4. Menguji BUBBLE SORT (O(n^2))... Mohon tunggu...\n";
        vector<double> dataBub = dataMaster;
        clock_t mulaiB = clock();
        bubbleSort(dataBub);
        clock_t selesaiB = clock();
        detikBubble = (double)(selesaiB - mulaiB) / CLOCKS_PER_SEC;
        cout << "   -> Selesai dalam: " << detikBubble << " detik\n\n";
    }

    // Tampilkan Tabel Analisa
    cout << "============================================================\n";
    cout << "          TABEL PERBANDINGAN PERFORMA SORTING\n";
    cout << "============================================================\n";
    cout << left << setw(18) << "Algoritma"
         << setw(16) << "Kompleksitas"
         << setw(20) << "Waktu Eksekusi" << "\n";
    cout << "------------------------------------------------------------\n";

    cout << left << setw(18) << "Quick Sort"
         << setw(16) << "O(n log n)"
         << detikQuick << " detik\n";

    if (detikSelection >= 0) {
        cout << left << setw(18) << "Selection Sort"
             << setw(16) << "O(n^2)"
             << detikSelection << " detik\n";
    } else {
        cout << left << setw(18) << "Selection Sort"
             << setw(16) << "O(n^2)"
             << "[Dilewati, estimasi > 5 detik]\n";
    }

    if (detikBubble >= 0) {
        cout << left << setw(18) << "Bubble Sort"
             << setw(16) << "O(n^2)"
             << detikBubble << " detik\n";
    } else {
        cout << left << setw(18) << "Bubble Sort"
             << setw(16) << "O(n^2)"
             << "[Dilewati, estimasi > 20 detik]\n";
    }

    cout << "============================================================\n";
    cout << "KESIMPULAN ANALISA PERFORMA:\n";
    cout << "1. Quick Sort (O(n log n)) jauh lebih cepat pada data besar (100.000 data)\n"
         << "   karena membagi data menjadi bagian-bagian kecil (Divide and Conquer).\n";
    cout << "2. Bubble Sort & Selection Sort (O(n^2)) lambat pada 100.000 data karena\n"
         << "   melakukan perbandingan berulang sebanyak n * n (10 miliar komparasi).\n";
    cout << "============================================================\n";
}

// =========================================================================
// SYARAT 3: ANALISA PERBANDINGAN ITERATIF VS REKURSIF
// =========================================================================
void ujiDanAnalisaIterasiRekursif() {
    cout << "\n============================================================\n";
    cout << "   UJI & ANALISA: FUNGSI ITERATIF VS FUNGSI REKURSIF\n";
    cout << "============================================================\n";

    double contohNilai[] = {85.5, 90.0, 78.5};
    int n = 3;

    double totalI = totalIteratif(contohNilai, n);
    double totalR = totalRekursif(contohNilai, n);

    cout << "Data Nilai Mahasiswa : 85.5, 90.0, 78.5\n";
    cout << "Total secara Iteratif: " << totalI << "\n";
    cout << "Total secara Rekursif: " << totalR << "\n";

    cout << "\n------------------------------------------------------------\n";
    cout << "ANALISA PERBANDINGAN FUNGSI ITERASI DAN REKURSIF:\n";
    cout << "------------------------------------------------------------\n";
    cout << "1. Kompleksitas Waktu:\n";
    cout << "   - Kedua fungsi memiliki kompleksitas waktu O(n) karena sama-sama\n";
    cout << "     mengunjungi setiap elemen nilai sebanyak satu kali.\n\n";
    cout << "2. Penggunaan Memori (Space Complexity):\n";
    cout << "   - Fungsi Iteratif: Memori O(1). Sangat hemat karena hanya memakai\n";
    cout << "     satu variabel penampung (total) di dalam perulangan for.\n";
    cout << "   - Fungsi Rekursif: Memori O(n). Membutuhkan memori tumpukan (Call Stack)\n";
    cout << "     karena setiap pemanggilan fungsi disimpan sampai mencapai kondisi n == 0.\n\n";
    cout << "3. Kesimpulan Performa:\n";
    cout << "   - Fungsi iteratif lebih efisien dan cepat di C++ karena tidak memiliki\n";
    cout << "     overhead pemanggilan stack frame berulang.\n";
    cout << "============================================================\n";
}

// Helper input nilai aman
double inputNilai(string prompt) {
    double nilai;
    while (true) {
        cout << prompt;
        if (cin >> nilai && nilai >= 0 && nilai <= 100) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return nilai;
        }
        cout << "Nilai tidak valid! Masukkan angka antara 0 - 100.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// =========================================================================
// PROGRAM UTAMA (MENU SEDERHANA)
// =========================================================================
int main() {
    srand(time(0)); // Inisialisasi seed angka acak
    vector<Mahasiswa> daftarMahasiswa;
    int pilihan;

    do {
        cout << "\n============================================================\n";
        cout << "   SISTEM SELEKSI BEASISWA (PROJECT UTS PEMROGRAMAN LANJUT)\n";
        cout << "============================================================\n";
        cout << "1. Input Data Mahasiswa (Simpan ke Memori & File CSV)\n";
        cout << "2. Tampilkan Hasil Seleksi & Peringkat Mahasiswa\n";
        cout << "3. Buka & Lihat File CSV (data_mahasiswa.csv)\n";
        cout << "4. Uji & Analisa Fungsi Iterasi vs Rekursif (Syarat 2 & 3)\n";
        cout << "5. Uji 3 Algoritma Sorting pada 100.000 Data (Syarat 4)\n";
        cout << "6. Keluar\n";
        cout << "============================================================\n";
        cout << "Pilih menu (1-6): ";

        if (!(cin >> pilihan)) {
            cout << "Pilihan harus angka 1-6!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (pilihan) {
            case 1: {
                int jumlah;
                while (true) {
                    cout << "\nMasukkan jumlah mahasiswa yang ingin diinput: ";
                    if (cin >> jumlah && jumlah > 0) {
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }
                    cout << "Jumlah harus angka lebih dari 0!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                for (int i = 0; i < jumlah; i++) {
                    Mahasiswa m;
                    cout << "\n--- Input Mahasiswa ke-" << i + 1 << " ---\n";

                    while (true) {
                        cout << "NPM           : ";
                        getline(cin, m.npm);
                        if (!m.npm.empty()) break;
                        cout << "NPM tidak boleh kosong!\n";
                    }

                    while (true) {
                        cout << "Nama          : ";
                        getline(cin, m.nama);
                        if (!m.nama.empty()) break;
                        cout << "Nama tidak boleh kosong!\n";
                    }

                    m.nilai1 = inputNilai("Nilai 1       : ");
                    m.nilai2 = inputNilai("Nilai 2       : ");
                    m.nilai3 = inputNilai("Nilai 3       : ");

                    // Panggil fungsi tambahMahasiswa (Fungsi memanggil Prosedur log)
                    tambahMahasiswa(m, daftarMahasiswa);
                }

                // Otomatis simpan data ke file CSV
                simpanKeCSV(daftarMahasiswa);
                break;
            }

            case 2: {
                if (daftarMahasiswa.empty()) {
                    cout << "\nBelum ada data mahasiswa! Silakan input di Menu 1 terlebih dahulu.\n";
                    break;
                }

                // Urutkan mahasiswa dari nilai tertinggi (Selection sort sederhana pada struct)
                for (size_t i = 0; i < daftarMahasiswa.size() - 1; i++) {
                    size_t maxIdx = i;
                    for (size_t j = i + 1; j < daftarMahasiswa.size(); j++) {
                        if (daftarMahasiswa[j].rataRata > daftarMahasiswa[maxIdx].rataRata) {
                            maxIdx = j;
                        }
                    }
                    if (maxIdx != i) {
                        swap(daftarMahasiswa[i], daftarMahasiswa[maxIdx]);
                    }
                }

                cout << "\n============================================================\n";
                cout << "               HASIL PERINGKAT SELEKSI BEASISWA\n";
                cout << "============================================================\n";
                cout << left << setw(10) << "Peringkat"
                     << setw(16) << "NPM"
                     << setw(22) << "Nama"
                     << setw(14) << "Rata-rata"
                     << setw(14) << "Status" << "\n";
                cout << "------------------------------------------------------------\n";

                // Cetak menggunakan prosedur yang memanggil fungsi (Syarat 1)
                for (size_t i = 0; i < daftarMahasiswa.size(); i++) {
                    cetakBarisMahasiswa(daftarMahasiswa[i], i + 1);
                }
                cout << "============================================================\n";
                break;
            }

            case 3:
                bacaDariCSV();
                break;

            case 4:
                ujiDanAnalisaIterasiRekursif();
                break;

            case 5:
                ujiSorting100k(100000);
                break;

            case 6:
                cout << "\nTerima kasih! Program selesai.\n";
                break;

            default:
                cout << "Pilihan tidak valid! Pilih angka 1-6.\n";
                break;
        }

    } while (pilihan != 6);

    return 0;
}
