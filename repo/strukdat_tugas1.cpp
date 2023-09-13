#include <iostream>
#include <vector>
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

vector<Mahasiswa> dataMahasiswa;

void initData() {
    Mahasiswa mhs;
    mhs.NamaMhs = "Angel";
    mhs.AsalMhs = "Jawa";
    mhs.UsiaMhs = "19";
    mhs.AlamatMhs = "Keputih";
    mhs.NoHPMhs = "081234567890";
    mhs.JenisKelaminMhs = "Perempuan";
    mhs.NRPMhs = "5027221090";
    mhs.DepartemenMhs= "IT";
    mhs.FakultasMhs = "FTEIC";
    mhs.KelasMhs= "Strukdat";

    dataMahasiswa.push_back(mhs);
}

void TampilkanData() {
    if (dataMahasiswa.empty()) {
        cout << "Data Mahasiswa kosong." << endl;
        return;
    }

    cout << "Data Mahasiswa:" << endl;
    for (const Mahasiswa& mhs : dataMahasiswa) {
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

    dataMahasiswa.push_back(mhs);
    cout << "Data mahasiswa telah ditambahkan." << endl;
}

void HapusData() {
    int indeks;
    cout << "Masukkan indeks data yang ingin dihapus: ";
    cin >> indeks;

    if (indeks >= 0 && indeks < dataMahasiswa.size()) {
        dataMahasiswa.erase(dataMahasiswa.begin() + indeks);
        cout << "Data mahasiswa telah dihapus." << endl;
    } else {
        cout << "Indeks tidak valid." << endl;
    }
}

void UbahData() {
    int indeks;
    cout << "Masukkan indeks data yang ingin diubah: ";
    cin >> indeks;

    if (indeks >= 0 && indeks < dataMahasiswa.size()) {
        Mahasiswa &mhs = dataMahasiswa[indeks];
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
}

int main() {
    int pilihan;
    initData();

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

    return 0;
}