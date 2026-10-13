# Sistem Seleksi Beasiswa (Project ETS Pemrograman Lanjut)

Program konsol berbasis C++ untuk menyeleksi penerima beasiswa berdasarkan nilai akademik mahasiswa. Program ini mengimplementasikan konsep struktur data dan algoritma dasar, termasuk perulangan iteratif, fungsi rekursif, pengurutan data (*sorting*), serta validasi input.

---

## Fitur Utama

- **Validasi Input yang Aman:**
  - Penanganan kesalahan input pada jumlah mahasiswa, NPM, Nama, dan Nilai (0 - 100).
  - Program tidak akan *crash* atau langsung keluar saat terjadi kesalahan pengetikan; pengguna akan diminta memasukkan kembali data yang valid.
- **Perhitungan Total & Rata-Rata:**
  - **Iteratif:** Menghitung total nilai menggunakan perulangan `for`.
  - **Rekursif:** Menghitung total nilai menggunakan pemanggilan fungsi rekursif.
- **Pengurutan Peringkat (*Sorting*):**
  - Menggunakan algoritma **Bubble Sort** untuk mengurutkan mahasiswa secara *descending* berdasarkan nilai rata-rata tertinggi.
- **Seleksi Kelolosan:**
  - Mahasiswa dinyatakan **Lolos** jika memiliki rata-rata nilai $\ge 80$, dan **Tidak Lolos** jika $< 80$.

---

## Konsep Pemrograman yang Diterapkan

1. **Struct (`struct Mahasiswa`):** Pengelompokan data majemuk mahasiswa (NPM, Nama, Nilai 1-3, Rata-rata, Status).
2. **Standard Template Library (STL Vector):** Menyimpan daftar objek mahasiswa secara dinamis.
3. **Fungsi Rekursif vs Iteratif:** Demonstrasi perbandingan perhitungan nilai secara rekursif (`totalRekursif`) dan iteratif (`totalIteratif`).
4. **Algoritma Bubble Sort:** Mengurutkan elemen dalam `std::vector<Mahasiswa>`.
5. **Input Stream Handling:** Menggunakan `cin.clear()`, `cin.ignore()`, dan `std::numeric_limits` untuk mencegah *infinite loop* atau *buffer mismatch*.

---

## Persyaratan Sistem

- Kompiler C++ yang mendukung standar C++11 atau lebih baru (misal: GCC / MinGW `g++`, Clang, atau MSVC).

---

## Cara Kompilasi dan Menjalankan

### Menggunakan Terminal / Command Prompt

1. **Buka terminal** di folder direktori project.
2. **Kompilasi kode program:**
   ```bash
   g++ -o SistemSeleksiBeasiswa SistemSeleksiBeasiswa.cpp
   ```
3. **Jalankan program:**
   - Di Windows (CMD / PowerShell):
     ```bash
     .\SistemSeleksiBeasiswa.exe
     ```
   - Di Linux / macOS:
     ```bash
     ./SistemSeleksiBeasiswa
     ```

---

## Contoh Alur Penggunaan

```text
========================================
     SISTEM SELEKSI BEASISWA
========================================
Masukkan jumlah mahasiswa: 2

Mahasiswa ke-1
NPM           : 23081010123
Nama          : Budi Santoso
Nilai 1       : 85
Nilai 2       : 90
Nilai 3       : 80

Mahasiswa ke-2
NPM           : 23081010124
Nama          : Siti Aminah
Nilai 1       : 75
Nilai 2       : 70
Nilai 3       : 80

========================================
          HASIL SELEKSI BEASISWA
========================================

Peringkat     : 1
NPM           : 23081010123
Nama          : Budi Santoso
Total (Iteratif) : 255.00
Total (Rekursif) : 255.00
Rata-rata     : 85.00
Status        : Lolos
----------------------------------------

Peringkat     : 2
NPM           : 23081010124
Nama          : Siti Aminah
Total (Iteratif) : 225.00
Total (Rekursif) : 225.00
Rata-rata     : 75.00
Status        : Tidak Lolos
----------------------------------------

Keterangan: Mahasiswa dinyatakan lolos jika rata-rata nilai >= 80.
```
