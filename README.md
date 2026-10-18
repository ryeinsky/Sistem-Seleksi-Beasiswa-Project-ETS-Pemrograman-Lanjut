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

### 1. Fungsi Memanggil Prosedur & Prosedur Memanggil Fungsi
- **Prosedur memanggil Fungsi:**
  Prosedur `void cetakBarisMahasiswa(...)` memanggil fungsi pengembali nilai `string seleksiBeasiswa(...)`.
- **Fungsi memanggil Prosedur:**
  Fungsi `bool tambahMahasiswa(...)` memanggil prosedur `void cetakPesanLog(...)`.

### 2. Permasalahan Diselesaikan dengan Iterasi dan Rekursif
Perhitungan akumulasi total nilai mahasiswa diselesaikan dengan 2 pendekatan:
- **Fungsi Iteratif (`totalIteratif`):** Menggunakan perulangan `for` biasa.
- **Fungsi Rekursif (`totalRekursif`):** Memanggil dirinya sendiri hingga mencapai kondisi dasar (*base case* `n <= 0`).

### 3. Analisa Perbandingan Fungsi Iterasi dan Rekursif
| Aspek | Fungsi Iteratif | Fungsi Rekursif |
|---|---|---|
| **Kompleksitas Waktu** | $O(n)$ | $O(n)$ |
| **Kompleksitas Ruang (Memori)** | $O(1)$ (Hemat, variabel biasa) | $O(n)$ (Memerlukan memori *Call Stack*) |
| **Kecepatan & Efisiensi** | Lebih cepat di C++ | Terdapat *overhead* pemanggilan fungsi |
| **Resiko** | Aman | Berisiko *Stack Overflow* jika $n$ sangat besar |

### 4. Uji 3 Algoritma Sorting pada $\ge 100.000$ Data & Analisa
Program menguji pengurutan data nilai acak (0–100) menggunakan generator `rand()` sebanyak 100.000 data dengan 3 algoritma:

1. **Quick Sort ($O(n \log n)$):**
   - Sangat cepat, membagi array menjadi bagian kecil (*Divide and Conquer*).
   - Waktu eksekusi pada 100.000 data: **~0.01 detik**.
2. **Selection Sort ($O(n^2)$):**
   - Mencari nilai ekstrem secara bertahap.
   - Waktu eksekusi pada 100.000 data: memakan waktu beberapa detik karena memerlukan 10 miliar komparasi.
3. **Bubble Sort ($O(n^2)$):**
   - Melakukan pertukaran elemen yang berdekatan secara berulang.
   - Waktu eksekusi pada 100.000 data: memakan waktu puluhan detik ($O(n^2)$).

---

## 💾 Fitur Penyimpanan CSV (`data_mahasiswa.csv`)

Program memiliki menu untuk:
1. Menyimpan data mahasiswa (NPM, Nama, Nilai 1-3, Rata-rata, Status) langsung ke format CSV.
2. Membaca dan menampilkan kembali isi file CSV di layar konsol.

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

## 🎬 Panduan Singkat Rekaman Video Presentasi (3–5 Menit)

1. **Pembukaan (30 detik):**
   - Sebutkan Nama, NPM, dan judul tugas: *"Sistem Seleksi Beasiswa"*.
2. **Demo Menu 1 & 2 (1.5 menit):**
   - Input 2 data mahasiswa contoh.
   - Jelaskan **Syarat 1** (prosedur `cetakBarisMahasiswa` memanggil fungsi `seleksiBeasiswa`).
   - Tunjukkan hasil peringkat dan periksa file `data_mahasiswa.csv` yang berhasil terbentuk.
3. **Demo Menu 4 - Analisa Iterasi vs Rekursi (1 menit):**
   - Tampilkan hasil perhitungan iteratif vs rekursif.
   - Jelaskan **Syarat 3**: Keduanya $O(n)$, namun iterasi lebih hemat memori stack.
4. **Demo Menu 5 - Sorting 100.000 Data (1.5 menit):**
   - Jalankan benchmark sorting 100.000 data.
   - Jelaskan **Syarat 4**: Tunjukkan Quick Sort selesai dalam 0.01 detik ($O(n \log n)$) dibandingkan algoritma $O(n^2)$.
5. **Penutup:** Ucapkan salam penutup.
