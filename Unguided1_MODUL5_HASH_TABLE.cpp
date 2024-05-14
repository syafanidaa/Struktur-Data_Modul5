#include <iostream>
#include <list>

using namespace std;

class Mahasiswa {
public:
    long long int nim; 
    int nilai;

    Mahasiswa(long long int n, int v) : nim(n), nilai(v) {}
};

class HashTable {
private:
    static const int hashSize = 10;
    list<Mahasiswa> table[hashSize];

    int hashFunction(long long int nim) { 
        return nim % hashSize;
    }

public:
    void tambahData(long long int nim, int nilai) {
        int index = hashFunction(nim);
        table[index].emplace_back(nim, nilai);
    }

    void hapusData(long long int nim) {
        int index = hashFunction(nim);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->nim == nim) {
                table[index].erase(it);
                break;
            }
        }
    }

    
    void cariByNIM(long long int nim) { 
        int index = hashFunction(nim);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->nim == nim) {
                cout << "NIM: " << it->nim << ", Nilai: " << it->nilai << endl;
                return;
            }
        }
        cout << "Data tidak ditemukan." << endl;
    }

    
    void cariByRange(int minNilai, int maxNilai) {
        for (int i = 0; i < hashSize; ++i) {
            for (auto it = table[i].begin(); it != table[i].end(); ++it) {
                if (it->nilai >= minNilai && it->nilai <= maxNilai) {
                    cout << "NIM: " << it->nim << ", Nilai: " << it->nilai << endl;
                }
            }
        }
    }
};

int main() {
    HashTable hashTable;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Data\n";
        cout << "2. Hapus Data\n";
        cout << "3. Cari Data berdasarkan NIM\n";
        cout << "4. Cari Data berdasarkan Rentang Nilai\n";
        cout << "5. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                long long int nim;
                int nilai;
                cout << "Masukkan NIM: ";
                cin >> nim;
                cout << "Masukkan Nilai: ";
                cin >> nilai;
                hashTable.tambahData(nim, nilai);
                break;
            }
            case 2: {
                long long int nim; 
                cout << "Masukkan NIM yang akan dihapus: ";
                cin >> nim;
                hashTable.hapusData(nim);
                break;
            }
            case 3: {
                long long int nim; 
                cout << "Masukkan NIM yang akan dicari: ";
                cin >> nim;
                hashTable.cariByNIM(nim);
                break;
            }
            case 4: {
                int minNilai, maxNilai;
                cout << "Masukkan Rentang Nilai (Min Max): ";
                cin >> minNilai >> maxNilai;
                cout << "Mahasiswa dengan nilai antara " << minNilai << " - " << maxNilai << ":\n";
                hashTable.cariByRange(minNilai, maxNilai);
                break;
            }
            
            case 5:
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (choice != 5);

 return 0;
}