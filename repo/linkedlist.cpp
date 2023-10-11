#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa {
    string NamaMhs;
    string AsalMhs;
    string UsiaMhs;
    string AlamatMhs;
    string NoHPMhs;
    string JenisKelaminMhs;
    string NRPMhs;
    string DepartemenMhs;
    string FakultasMhs;
    string KelasMhs;
};

struct Node {
    Mahasiswa data;
    Node* next;
};

Node* head = nullptr; // Inisialisasi linked list kosong

void TampilkanData() {
    if (head == nullptr) {
        cout << "Data Mahasiswa kosong." << endl;
        return;
    }

    cout << "Data Mahasiswa:" << endl;
    Node* current = head;
    while (current != nullptr) {
        Mahasiswa mhs = current->data;
        cout << "Nama: " << mhs.NamaMhs << endl;
        cout << "Asal: " << mhs.AsalMhs << endl;
        cout << "Usia: " << mhs.UsiaMhs << endl;
        cout << "Alamat: " << mhs.AlamatMhs << endl;
        cout << "No. HP: " << mhs.NoHPMhs << endl;
        cout << "Jenis Kelamin: " << mhs.JenisKelaminMhs << endl;
        cout << "NRP: " << mhs.NRPMhs << endl;
        cout << "Departemen: " << mhs.DepartemenMhs << endl;
        cout << "Fakultas: " << mhs.FakultasMhs << endl;
        cout << "Kelas: " << mhs.KelasMhs << endl;
        cout << endl;
        current = current->next;
    }
}

void TambahData() {
    Mahasiswa mhs;

    cout << "Masukkan Nama: ";
    cin.ignore();
    getline(cin, mhs.NamaMhs);
    cout << "Masukkan Asal: ";
    getline(cin, mhs.AsalMhs);
    cout << "Masukkan Usia: ";
    getline(cin, mhs.UsiaMhs);
    cout << "Masukkan Alamat: ";
    getline(cin, mhs.AlamatMhs);
    cout << "Masukkan No. HP: ";
    getline(cin, mhs.NoHPMhs);
    cout << "Masukkan Jenis Kelamin: ";
    getline(cin, mhs.JenisKelaminMhs);
    cout << "Masukkan NRP: ";
    getline(cin, mhs.NRPMhs);
    cout << "Masukkan Departemen: ";
    getline(cin, mhs.DepartemenMhs);
    cout << "Masukkan Fakultas: ";
    getline(cin, mhs.FakultasMhs);
    cout << "Masukkan Kelas: ";
    getline(cin, mhs.KelasMhs);

    Node* newNode = new Node;
    newNode->data = mhs;
    newNode->next = head;
    head = newNode;

    cout << "Data mahasiswa telah ditambahkan." << endl;
}

void HapusData() {
    int indeks;
    cout << "Masukkan indeks data yang ingin dihapus: ";
    cin >> indeks;

    if (indeks < 0) {
        cout << "Indeks tidak valid." << endl;
        return;
    }

    if (indeks == 0) {
        // Hapus data dari awal linked list
        if (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Data mahasiswa telah dihapus." << endl;
        } else {
            cout << "Linked list kosong." << endl;
        }
    } else {
        // Hapus data dari tengah atau akhir linked list
        Node* current = head;
        Node* previous = nullptr;
        int currentIndex = 0;

        while (current != nullptr && currentIndex < indeks) {
            previous = current;
            current = current->next;
            currentIndex++;
        }

        if (current != nullptr) {
            previous->next = current->next;
            delete current;
            cout << "Data mahasiswa telah dihapus." << endl;
        } else {
            cout << "Indeks tidak valid." << endl;
        }
    }
}

void UbahData() {
    int indeks;
    cout << "Masukkan indeks data yang ingin diubah: ";
    cin >> indeks;

    if (indeks >= 0) {
        Node* current = head;
        int currentIndex = 0;

        while (current != nullptr && currentIndex < indeks) {
            current = current->next;
            currentIndex++;
        }

        if (current != nullptr) {
            Mahasiswa &mhs = current->data;
            cout << "Masukkan Nama Baru: ";
            cin.ignore();
            getline(cin, mhs.NamaMhs);
            cout << "Masukkan Asal Baru: ";
            getline(cin, mhs.AsalMhs);
            cout << "Masukkan Usia Baru: ";
            getline(cin, mhs.UsiaMhs);
            cout << "Masukkan Alamat Baru: ";
            getline(cin, mhs.AlamatMhs);
            cout << "Masukkan No. HP Baru: ";
            getline(cin, mhs.NoHPMhs);
            cout << "Masukkan Jenis Kelamin Baru: ";
            getline(cin, mhs.JenisKelaminMhs);
            cout << "Masukkan NRP Baru: ";
            getline(cin, mhs.NRPMhs);
            cout << "Masukkan Departemen Baru: ";
            getline(cin, mhs.DepartemenMhs);
            cout << "Masukkan Fakultas Baru: ";
            getline(cin, mhs.FakultasMhs);
            cout << "Masukkan Kelas Baru: ";
            getline(cin, mhs.KelasMhs);

            cout << "Data mahasiswa telah diubah." << endl;
        } else {
            cout << "Indeks tidak valid." << endl;
        }
    } else {
        cout << "Indeks tidak valid." << endl;
    }
}

int main() {
    int pilihan;

    do {
        cout << "Menu:" << endl;
        cout << "1. Tampilkan Data" << endl;
        cout << "2. Tambah Data" << endl;
        cout << "3. Hapus Data" << endl;
        cout << "4. Ubah Data" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                TampilkanData();
                break;
            case 2:
                TambahData();
                break;
            case 3:
                HapusData();
                break;
            case 4:
                UbahData();
                break;
            case 0:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 0);

    // Hapus semua node pada linked list sebelum keluar
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
