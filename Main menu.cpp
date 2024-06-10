#include <iostream>
#include <vector>
#include <conio.h>
#include <sstream>
#include <string>

using namespace std;

// blueprint data structure for transaction.
class Transaction
{
public:
    string usernameFrom, usernameTo;
    double amount;
};

// blueprint data structure for user.
class User
{
public:
    string username, password, email, name, address, phone, pin;
    double balance;
    vector<Transaction> transactions;
};

// variable list of users
vector<User> users;

// variable for hold logged user.
User activeUser;


class daftar {
public:
    vector<string> nama3;
    vector<int> pin3;

    string nama2;
    int pin2;
    string str;

    bool login() {
        cout << "Masukkan Username Anda : ";
        cin.ignore();
        getline(cin, nama2);

        cout << "Masukkan Pin Anda : ";
        getline(cin, str);
        stringstream(str) >> pin2;

        return kebenaran();
    }

    void registerUser() {
        string nama;
        int pin;

        cout << "Masukkan username anda : ";
        cin.ignore();
        getline(cin, nama);

        cout << "\nMasukkan Pin anda : ";
        getline(cin, str);
        stringstream(str) >> pin;

        nama3.push_back(nama);
        pin3.push_back(pin);

        cout << "Akun anda Sukses dibuat!";
        getch(); 
    }


    bool kebenaran() {
        for (size_t i = 0; i < nama3.size(); i++) {
            if (nama3[i] == nama2 && pin3[i] == pin2) {
                return true;
            }
            else{
            	return false;
			}
        }
        
    }
};

void cekSaldo();
void lihatRiwayat();
void transfer();

int main()
{
    daftar df;
    bool active = true;
    while (active)
    {
        int input;
        cout << "|---------------------------------|" << endl;
        cout << "|-----| The Central Bank  |-------|" << endl;
        cout << "|---------------------------------|" << endl;
        cout << "| 1. Login" << endl;
        cout << "| 2. Register" << endl;
        cout << "| 3. Exit" << endl;
        cout << "|--------------" << endl;
        cout << "| Your input: ";
        cin >> input;
        system("cls");

        switch (input)
        {
        case 1:
        {
            bool isSuccessLogin = df.login();
            df.kebenaran();
            if (isSuccessLogin)
            {
                bool sesiLogin = true;
                while (sesiLogin)
                {
                    system("cls");
                    int input2;
                    cout << "|---------------------------------|" << endl;
                    cout << "| Hai " << activeUser.name << ", Selamat datang" << endl;
                    cout << "|---------------------------------|" << endl;
                    cout << "| 1. Cek Saldo" << endl;
                    cout << "| 2. Lihat Riwayat Transaksi" << endl;
                    cout << "| 3. Transfer Dana" << endl;
                    cout << "| 4. Logout" << endl;
                    cout << "|---------------------------------|" << endl;
                    cout << "| Input: ";
                    cin >> input2;
                    system("cls");
                    switch (input2)
                    {
                    case 1:
                        cekSaldo();
                        break;
                    case 2:
                        lihatRiwayat();
                        break;
                    case 3:
                        transfer();
                        break;
                    case 4:
                        sesiLogin = false;
                        break;
                    }
                    system("cls");
                }
            }
        }
        break;
        case 2:
            df.registerUser();
            break;
        case 3:
            active = false;
            break;
        }

        system("cls");
    }
}




void cekSaldo()
{
    // Bagian cek saldo user silahkan ngoding disini

    cout << "Press Enter to Continue";
    getch();
}

void lihatRiwayat()
{
    // Bagian lihat riwayat user silahkan ngoding disini
    
    cout << "Press Enter to Continue";
    getch();
}

void transfer()
{
    // Bagian transfer user silahkan ngoding disini

    cout << "Press Enter to Continue";
    getch();
}
