#include <iostream> 
#include <string>
#include <vector> 

using namespace std;

struct User {
    string username;
    size_t hashedPassword;
};

struct StringHash {
    size_t operator()(const string& str) const {
        size_t hash = 0;
        for (char c : str) {
            hash = hash * 31 + static_cast<size_t>(c);
        }
        return hash;
    }
};

vector<User> dataUser;

void registerUser() {
    string username,password;
    cout << "Masukkan Username: ";
    cin >> username;
    cout << "Masukkan Password: ";
    cin >> password;

    size_t hashedPassword = StringHash{}(password);
    dataUser.push_back({username, hashedPassword});
    cout << "Pengguna " << username << " telah terdaftar." << endl;
}

bool loginUser() {
    string username,password;
    cout << "Masukkan Username: ";
    cin >> username;
    cout << "Masukkan Password: ";
    cin >> password;

    size_t hashedPassword = StringHash{}(password);
    for (const User& user : dataUser) {
        if (user.username == username && user.hashedPassword == hashedPassword) {
            cout << "Selamat datang, " << username << "!" << endl;
            return true;
        }
    }
    cout << "Login gagal. Periksa username dan password Anda." << endl;
    return false;
}

int main() {
    registerUser();
    registerUser();

    loginUser();
    loginUser();

    return 0;
}