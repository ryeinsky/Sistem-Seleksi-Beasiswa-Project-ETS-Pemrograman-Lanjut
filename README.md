# Sistem Seleksi Beasiswa (Tugas Individu UTS Pemrograman Lanjut)

Aplikasi konsol berbasis C++ untuk menyeleksi penerima beasiswa berdasarkan nilai akademik mahasiswa, dilengkapi perbandingan fungsi iteratif vs rekursif, pengujian 3 algoritma pengurutan (*sorting*) pada 100.000 data, serta penyimpanan data ke format **CSV**.

---

## 📁 Struktur File Proyek

1. **`SistemSeleksiBeasiswaUTS.cpp`** *(File Utama UTS)*:
   - Program lengkap yang memenuhi seluruh 4 kriteria penugasan UTS.
   - Dilengkapi penyimpanan data otomatis ke `data_mahasiswa.csv`.
2. **`SistemSeleksiBeasiswa.cpp`**:
   - Versi dasar program seleksi beasiswa.
3. **`data_mahasiswa.csv`**:
   - File data mahasiswa hasil ekspor sistem (dapat dibuka di Microsoft Excel atau Notepad).

---

## 📌 Pemenuhan 4 Kriteria Tugas UTS

| No | Kriteria Tugas UTS | Implementasi dalam Kode Program |
|---|---|---|
| **1** | **Fungsi memanggil prosedur atau sebaliknya** | Prosedur `cetakBarisMahasiswa()` memanggil fungsi `seleksiBeasiswa()`.<br>Fungsi `tambahMahasiswa()` memanggil prosedur `cetakPesanLog()`. |
| **2** | **Permasalahan dengan Iterasi dan Rekursif** | Menghitung total nilai dengan `totalIteratif()` (perulangan `for`) dan `totalRekursif()` (pemanggilan diri sendiri). |
| **3** | **Analisa perbandingan iterasi vs rekursif** | Disediakan di **Menu 4**: penjelasan kompleksitas waktu $O(n)$ dan memori *Call Stack* $O(1)$ vs $O(n)$. |
| **4** | **Uji 3 algoritma sorting pada $\ge$ 100.000 data** | Disediakan di **Menu 5**: menguji *Quick Sort*, *Selection Sort*, dan *Bubble Sort* pada 100.000 data acak beserta tabel waktu eksekusinya. |

---

## 📖 Penjelasan Lengkap Kode, Fungsi, dan Perintah yang Digunakan

Bagian ini dapat Anda gunakan sebagai **bahan materi presentasi dan contekan saat rekaman video**:

### 1. Library & Header (`#include`)
- `#include <iostream>`: Menyediakan perintah standar input dan output layar (`cin`, `cout`, `endl`).
- `#include <iomanip>`: Mengatur format tabel tampilan konsol (`setw` untuk lebar kolom, `fixed` dan `setprecision(2)` untuk 2 angka di belakang koma desimal).
- `#include <string>`: Mengelola tipe data teks (NPM, Nama Mahasiswa, Status Kelolosan).
- `#include <vector>`: Struktur data array dinamis (`std::vector`) untuk menampung daftar data mahasiswa secara fleksibel tanpa batasan ukuran kaku.
- `#include <fstream>`: Mengelola operasi file (*File Handling*):
  - `ofstream` (*output file stream*): Digunakan untuk menulis/menyimpan data ke file `data_mahasiswa.csv`.
  - `ifstream` (*input file stream*): Digunakan untuk membaca kembali file `data_mahasiswa.csv`.
- `#include <ctime>`: Menyediakan fungsi `clock()` dan konstanta `CLOCKS_PER_SEC` untuk mengukur durasi waktu eksekusi kode dalam satuan detik, serta `time(0)` untuk inisialisasi angka acak.
- `#include <cstdlib>`: Menyediakan fungsi `rand()` untuk menghasilkan angka acak dan `srand()` untuk menentukan *seed* generator acak.
- `#include <limits>`: Menyediakan `numeric_limits<streamsize>::max()` untuk membersihkan sisa buffer pengetikan keyboard (*input stream*).

---

### 2. Tipe Data Bentukan (`struct Mahasiswa`)
```cpp
struct Mahasiswa {
    string npm;
    string nama;
    double nilai1, nilai2, nilai3;
    double rataRata;
    string status; // "Lolos" atau "Tidak Lolos"
};
```
- **Fungsi:** Mengelompokkan berbagai variabel yang saling berkaitan menjadi satu kesatuan objek mahasiswa.
- **Atribut:** Menyimpan nomor identitas (NPM bertipe `string` agar digit awal '0' tidak hilang), nama lengkap, nilai 3 mata kuliah/komponen, nilai rata-rata, dan status kelolosan.

---

### 3. Fungsi Perhitungan & Kelolosan (Syarat 2)
#### a. `double totalIteratif(double nilai[], int n)`
- **Cara Kerja:** Menggunakan perulangan `for (int i = 0; i < n; i++)` untuk menjumlahkan setiap elemen nilai satu per satu ke variabel akumulator `total`.
- **Karakteristik:** Eksekusi cepat, penggunaan memori tetap ($O(1)$).

#### b. `double totalRekursif(double nilai[], int n)`
- **Cara Kerja:** Menjumlahkan nilai dengan memanggil dirinya sendiri secara mundur.
  - *Base Case* (Kondisi Berhenti): Jika `n <= 0`, kembalikan nilai `0`.
  - *Recursive Call*: Mengembalikan `nilai[n - 1] + totalRekursif(nilai, n - 1)`.
- **Karakteristik:** Membutuhkan alokasi memori tumpukan (*Call Stack*) setinggi $n$ frame ($O(n)$ memori).

#### c. `double hitungRataRata(double nilai[], int n)`
- **Cara Kerja:** Memanggil `totalIteratif(nilai, n)` lalu membaginya dengan jumlah komponen $n$ (3 komponen).

#### d. `string seleksiBeasiswa(double rataRata)`
- **Cara Kerja:** Percabangan `if (rataRata >= 80.0)` mengembalikan status `"Lolos"`, jika di bawah 80.0 mengembalikan `"Tidak Lolos"`.

---

### 4. Hubungan Fungsi & Prosedur (Syarat 1)
Dalam C++:
- **Prosedur** adalah subprogram bertipe `void` (tidak mengembalikan nilai).
- **Fungsi** adalah subprogram yang memiliki tipe data kembalian (`string`, `double`, `bool`, dll).

#### a. Prosedur Memanggil Fungsi: `cetakBarisMahasiswa(Mahasiswa m, int peringkat)`
```cpp
void cetakBarisMahasiswa(Mahasiswa m, int peringkat) {
    string hasilStatus = seleksiBeasiswa(m.rataRata); // Prosedur void memanggil fungsi string
    cout << peringkat << setw(...) << m.npm << ... << hasilStatus << endl;
}
```
- Prosedur ini bertipe `void` yang bertugas mencetak satu baris data ke layar konsol, dan di dalamnya memanggil fungsi `seleksiBeasiswa()`.

#### b. Fungsi Memanggil Prosedur: `tambahMahasiswa(Mahasiswa& m, vector<Mahasiswa>& daftar)`
```cpp
bool tambahMahasiswa(Mahasiswa& m, vector<Mahasiswa>& daftar) {
    // ... kalkulasi nilai ...
    daftar.push_back(m);
    cetakPesanLog("Data mahasiswa " + m.nama + " berhasil disimpan."); // Fungsi memanggil prosedur void
    return true;
}
```
- Fungsi ini bertipe `bool`, dan di dalamnya memanggil prosedur `void cetakPesanLog()`.

---

### 5. File Handling CSV (`simpanKeCSV` dan `bacaDariCSV`)
#### a. `void simpanKeCSV(const vector<Mahasiswa>& daftar, string namaFile)`
- Menggunakan objek `ofstream file(namaFile);` untuk membuka aliran penulisan file.
- Menuliskan baris judul kolom: `NPM,Nama,Nilai1,Nilai2,Nilai3,RataRata,Status`.
- Melakukan perulangan untuk menuliskan setiap data mahasiswa dipisahkan tanda koma (`,`).
- Menutup file dengan `file.close()`. File CSV yang dihasilkan kompatibel dan dapat langsung dibuka di Microsoft Excel.

#### b. `void bacaDariCSV(string namaFile)`
- Menggunakan objek `ifstream file(namaFile);` untuk membuka aliran pembacaan file.
- Menggunakan fungsi `getline(file, baris)` di dalam perulangan `while` untuk membaca dan menampilkan isi file baris demi baris ke konsol.

---

### 6. Tiga Algoritma Sorting (Syarat 4)
Semua algoritma diatur untuk mengurutkan nilai secara *Descending* (dari nilai terbesar ke nilai terkecil).

#### a. `bubbleSort(vector<double>& arr)` — Kompleksitas $O(n^2)$
- **Cara Kerja:** Membandingkan dua elemen yang bersebelahan (`arr[j]` dan `arr[j+1]`). Jika elemen kiri lebih kecil dari elemen kanan, keduanya ditukar posisi (`swap`).
- Dilengkapi variabel `bool adaTukar = false` untuk menghentikan perulangan lebih awal jika data sudah terurut rapi.

#### b. `selectionSort(vector<double>& arr)` — Kompleksitas $O(n^2)$
- **Cara Kerja:** Pada setiap putaran loop luar, algoritma mencari indeks elemen dengan nilai terbesar (`maxIdx`) di sisa array, kemudian menukarnya sekali dengan posisi elemen awal loop (`swap(arr[i], arr[maxIdx])`).

#### c. `quickSort(vector<double>& arr, int low, int high)` — Kompleksitas $O(n \log n)$
- **Cara Kerja (Divide and Conquer):**
  1. Fungsi `partisi()` memilih elemen terakhir sebagai patokan (*pivot*).
  2. Semua elemen yang lebih besar dari pivot dipindahkan ke sisi kiri, dan yang lebih kecil ke sisi kanan.
  3. Posisi pivot dikembalikan, lalu fungsi `quickSort()` memanggil dirinya sendiri secara rekursif untuk mengurutkan bagian kiri dan kanan secara terpisah.

---

### 7. Pengukuran Waktu & Benchmark 100.000 Data (`ujiSorting100k`)
- **Membuat 100.000 Data Acak:**
  ```cpp
  for (int i = 0; i < 100000; i++) {
      dataMaster[i] = (rand() % 10000) / 100.0; // nilai acak antara 0.00 - 100.00
  }
  ```
- **Mengukur Waktu Eksekusi:**
  ```cpp
  clock_t mulai = clock();
  quickSort(dataQuick, 0, dataQuick.size() - 1);
  clock_t selesai = clock();
  double detik = (double)(selesai - mulai) / CLOCKS_PER_SEC;
  ```
  `CLOCKS_PER_SEC` adalah konstanta bawaan C++ untuk mengonversi detak jam CPU (*clock ticks*) menjadi satuan detik desimal.

---

### 8. Validasi Input Bebas Crash (`inputNilai`)
```cpp
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
```
- Jika pengguna salah memasukkan huruf atau angka di luar 0–100:
  - `cin.clear()` membersihkan status error pada input stream.
  - `cin.ignore(...)` membuang karakter yang salah pengetikannya dari memori buffer.
  - Program tidak akan *crash* dan meminta pengguna mengulang pengetikan dengan ramah.

---

## 🚀 Cara Kompilasi dan Menjalankan

### Menggunakan Terminal (GCC / MinGW g++)

1. **Kompilasi program utama:**
   ```bash
   g++ -O2 -o SistemSeleksiBeasiswaUTS SistemSeleksiBeasiswaUTS.cpp
   ```
2. **Jalankan aplikasi:**
   - Di Windows:
     ```bash
     .\SistemSeleksiBeasiswaUTS.exe
     ```
   - Di Linux / macOS:
     ```bash
     ./SistemSeleksiBeasiswaUTS
     ```

---

## 🎬 Panduan Singkat Alur Video Presentasi (3–5 Menit)

1. **Pembukaan (30 detik):**
   - Salam, perkenalkan diri (Nama & NPM), dan topik tugas: *"Sistem Seleksi Beasiswa berbasis C++"*.
2. **Demo Menu 1 & 2 (1.5 menit):**
   - Masukkan 2 data mahasiswa contoh.
   - Jelaskan bahwa data otomatis tersimpan ke `data_mahasiswa.csv` (*File Handling*).
   - Tunjukkan **Syarat 1** pada kode: Prosedur `cetakBarisMahasiswa` memanggil fungsi `seleksiBeasiswa`.
3. **Demo Menu 4 - Analisa Iterasi vs Rekursi (1 menit):**
   - Jalankan Menu 4.
   - Jelaskan **Syarat 2 & 3**: Iterasi menggunakan perulangan `for` ($O(1)$ memori), sedangkan rekursif memanggil dirinya sendiri ($O(n)$ memori *Call Stack*). Keduanya memiliki kompleksitas waktu $O(n)$.
4. **Demo Menu 5 - Sorting 100.000 Data (1.5 menit):**
   - Jalankan Menu 5. Tunjukkan bahwa 100.000 data di-generate dengan `rand()`.
   - Jelaskan **Syarat 4**: *Quick Sort* ($O(n \log n)$) selesai dalam **0.01 detik**, jauh lebih unggul dibandingkan *Bubble Sort* dan *Selection Sort* ($O(n^2)$) yang memerlukan 10 miliar perbandingan.
5. **Penutup:** Ucapkan terima kasih dan salam penutup.
