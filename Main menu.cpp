#include <iostream>
#include <vector>
#include <conio.h>

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

bool login();
void registerUser();
void cekSaldo();
void lihatRiwayat();
void transfer();

int main()
{
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
            bool isSuccessLogin = login();
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
            registerUser();
            break;
        case 3:
            active = false;
            break;
        }

        system("cls");
    }
}

bool login()
{
    // Bagian login silahkan ngoding disini

    cout << "Press Enter to Continue";
}

void registerUser()
{
    // Bagian register user silahkan ngoding disini
 
    cout << "Press Enter to Continue";
    getch();
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
