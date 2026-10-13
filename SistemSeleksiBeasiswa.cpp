
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>
using namespace std;

struct Mahasiswa {
    char npm;
    string nama;
    double nilai1, nilai2, nilai3;
    double rataRata;
    string status;
};

double totalIteratif(double nilai[], int n) {
    double total = 0;

    for (int i = 0; i < n; i++) {
        total += nilai[i];
    }

    return total;
}

double totalRekursif(double nilai[], int n) {
    if (n == 0) {
        return 0;
    }

    return nilai[n - 1] + totalRekursif(nilai, n - 1);
}

double hitungRataRata(double nilai[], int n) {
    return totalIteratif(nilai, n) / n;
}

void bubbleSort(vector<Mahasiswa>& data) {
    int n = data.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (data[j].rataRata < data[j + 1].rataRata) {
                Mahasiswa sementara = data[j];
                data[j] = data[j + 1];
                data[j + 1] = sementara;
            }
        }
    }
}

string seleksiBeasiswa(double rataRata) {
    if (rataRata >= 80) {
        return "Lolos";
    } else {
        return "Tidak Lolos";
    }
}

int main() {
    vector<Mahasiswa> data;
    int jumlah;

    cout << "========================================\n";
    cout << "     SISTEM SELEKSI BEASISWA\n";
    cout << "========================================\n";

    cout << "Masukkan jumlah mahasiswa: ";
    if (!(cin >> jumlah) || jumlah <= 0) {
        cout << "Jumlah mahasiswa harus lebih dari 0!\n";
        return 1;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Input data mahasiswa
    for (int i = 0; i < jumlah; i++) {
        Mahasiswa m;

        cout << "\nMahasiswa ke-" << i + 1 << endl; 
    do {
        cout << "NPM           : ";
        if (!(cin >> m.npm) || m.npm <= 0) {
            cout << "NPM tidak valid! Masukkan angka positif.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            m.npm = 0;
        } else {
            break;
        }
    } while (true);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Nama          : ";
        getline(cin, m.nama);

        cout << "Nilai 1       : ";
        if (!(cin >> m.nilai1) ||
            m.nilai1 < 0 || m.nilai1 > 100) {
            cout << "Nilai harus antara 0-100!\n";
            return 1;
        }

        cout << "Nilai 2       : ";
        if (!(cin >> m.nilai2) ||
            m.nilai2 < 0 || m.nilai2 > 100) {
            cout << "Nilai harus antara 0-100!\n";
            return 1;
        }

        cout << "Nilai 3       : ";
        if (!(cin >> m.nilai3) ||
            m.nilai3 < 0 || m.nilai3 > 100) {
            cout << "Nilai harus antara 0-100!\n";
            return 1;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Menghitung rata-rata secara iteratif
        double nilai[] = {m.nilai1, m.nilai2, m.nilai3};
        m.rataRata = hitungRataRata(nilai, 3);
        m.status = seleksiBeasiswa(m.rataRata);

        data.push_back(m);
    }

    bubbleSort(data);

    cout << "\n========================================\n";
    cout << "          HASIL SELEKSI BEASISWA\n";
    cout << "========================================\n";

    cout << fixed << setprecision(2);

    for (int i = 0; i < jumlah; i++) {
        double nilai[] = {
            data[i].nilai1,
            data[i].nilai2,
            data[i].nilai3
        };

        double totalI = totalIteratif(nilai, 3);
        double totalR = totalRekursif(nilai, 3);

        cout << "\nPeringkat     : " << i + 1 << endl;
        cout << "NPM           : " << data[i].npm << endl;
        cout << "Nama          : " << data[i].nama << endl;
        cout << "Total (Iteratif) : " << totalI << endl;
        cout << "Total (Rekursif) : " << totalR << endl;
        cout << "Rata-rata     : " << data[i].rataRata << endl;
        cout << "Status        : " << data[i].status << endl;
        cout << "----------------------------------------\n";
    }

    cout << "\nKeterangan: Mahasiswa dinyatakan lolos jika "
         << "rata-rata nilai >= 80.\n";

    return 0;
}
