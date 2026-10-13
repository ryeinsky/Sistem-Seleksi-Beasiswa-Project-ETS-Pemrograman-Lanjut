
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>
using namespace std;

struct Mahasiswa {
    string npm;
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
    if (n <= 0) {
        return 0;
    }

    return nilai[n - 1] + totalRekursif(nilai, n - 1);
}

double hitungRataRata(double nilai[], int n) {
    return totalIteratif(nilai, n) / n;
}

double inputNilai(const string& prompt) {
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

    while (true) {
        cout << "Masukkan jumlah mahasiswa: ";
        if (cin >> jumlah && jumlah > 0) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
        cout << "Jumlah mahasiswa tidak valid! Masukkan angka lebih dari 0.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Input data mahasiswa
    for (int i = 0; i < jumlah; i++) {
        Mahasiswa m;

        cout << "\nMahasiswa ke-" << i + 1 << endl;

        while (true) {
            cout << "NPM           : ";
            getline(cin, m.npm);
            if (!m.npm.empty()) {
                break;
            }
            cout << "NPM tidak boleh kosong!\n";
        }

        while (true) {
            cout << "Nama          : ";
            getline(cin, m.nama);
            if (!m.nama.empty()) {
                break;
            }
            cout << "Nama tidak boleh kosong!\n";
        }

        m.nilai1 = inputNilai("Nilai 1       : ");
        m.nilai2 = inputNilai("Nilai 2       : ");
        m.nilai3 = inputNilai("Nilai 3       : ");

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
