#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <conio.h>


using namespace std;

class Transaction
{
public:
    string usernameFrom, usernameTo;
    double amount;
};

class User
{
public:
    string username, password, email, name, address, phone, pin;
    double balance;
    vector<Transaction> transactions;
};

vector<User> users;

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
        cout << endl;
        cout << "|=================================|" << endl;
        cout << "|>>>>>|  The Central Bank  |<<<<<<|" << endl;
        cout << "|=================================|" << endl;
        cout << "| 1. Login" << "                        |"<< endl;
        cout << "| 2. Registrasi" << "                   |"<< endl;
        cout << "| 3. Exit" << "                         |"<<endl;
        cout << "|=================================|" << endl;
        cout << ">>>> Your Input : ";
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
                    cout << endl;
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
    string username, password;
	
	cout << endl;
	cout << endl;
    cout << " > Masukkan nomor rekening anda: ";
    cin >> username;
    cout << " > Masukkan password anda: ";
    cin >> password;

    system("cls");
    for (const User& user : users) {
        if (user.username == username && user.password == password) {
            activeUser = user;
            cout << endl;
            cout << "|-----------------------------|"<< endl;
            cout << "        Login sukses!" << endl;
            cout << "|-----------------------------|" <<endl;
            cout<<endl;
            cout << "Press Enter to Continue";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getch();
            system("cls");
            return true;
        }
    }

    cout << "Password yang anda masukan salah! " << endl;
    cout << endl;
    cout << "Press Enter to Back";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getch();
    system("cls");
    return false;
    }

void registerUser() {
    User user;
	
	cout << endl;
	cout << endl;
    cout << " > Masukkan nomor rekening anda: ";
    cin >> user.username;
    cout << " > Masukkan password anda: ";
    cin >> user.password;
    cout << " > Masukkan nama anda: ";
    cin >> user.name;
    cout << " > Masukkan pin anda: ";
    cin >> user.pin;
    cout << " > Tambahkan saldo: ";
    cin >> user.balance;

    users.push_back(user);

    cout << "Press Enter to Continue";
    system("cls");
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;
    cout << "|-----------------------------------------------------|" << endl;
    cout << "|      Selamat, anda berhasil registrasi!             |" << endl;
    cout << "|-----------------------------------------------------|" << endl;
    getch();
    system("cls");
}

void cekSaldo()
{
	system("cls");
	cout << endl;
	cout << "|--------------------------------|" << endl;
    cout << "     Hai " << activeUser.name << endl;
    cout << "     Saldo Anda: Rp. " << activeUser.balance << endl;
	cout << "|--------------------------------|" << endl;
	
	cout << endl;
    cout << "Press Enter to Continue";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getch();
    system("cls");
}

void lihatRiwayat()
{
	system("cls");
	cout << endl;
    cout << "|--------------------------------|" << endl;
    cout << "\tRiwayat Transaksi : " << endl;
    cout << "|--------------------------------|" << endl;

    for (const auto& t : activeUser.transactions) {
    	cout << endl;
    	cout << "|==============================|" << endl;
        cout << " |   Dari: " << t.usernameFrom << endl;
        cout << " |   No.Rek tujuan: " << t.usernameTo << endl;
        cout << " |   Nominal: Rp. " << t.amount << "\n";
        cout << "|==============================|" << endl;
    }

    cout << "Press Enter to Back";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getch();
    system("cls");
}

void transfer()
{
	system("cls");
   	string inputUser;
    double amount;
	
	cout << endl;
	cout << endl;
    cout << " > Masukkan No. Rek tujuan : ";
    cin >> inputUser;

    User userTo;
    bool found = false;
    for (User& user : users) {
        if (user.username == inputUser) {
            userTo = user;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "User not found!" << endl;
        cout << "Press Enter to Back";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getch();
        system("cls");
        return;
    }
	
	cout << endl;
    cout << " > Masukkan nominal transfer : Rp";
    cin >> amount;

    if (amount > activeUser.balance) {
        cout << "Saldo tidak cukup!" << endl;
        cout << "Press Enter to Back";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getch();
        system("cls");
        return;
    }

    system("cls");
    string pin;
    cout << endl;
    cout << " > Masukkan PIN Anda untuk konfirmasi: ";
    cin >> pin;

    if (pin != activeUser.pin) {
    	cout << endl;
        cout << "PIN yang Anda masukkan salah!" << endl;
        cout << "Press Enter to Back";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getch();
        system("cls");
        return;
    }

    activeUser.balance -= amount;
    userTo.balance += amount;

    Transaction t;
    t.usernameFrom = activeUser.username;
    t.usernameTo = userTo.username;
    t.amount = amount;
    activeUser.transactions.push_back(t);

    Transaction t1;
    t1.usernameFrom = activeUser.username;
    t1.usernameTo = userTo.username; 
    t1.amount = amount;
    userTo.transactions.push_back(t1);

   
    system("cls");
	cout << endl; 
	cout << endl;
    cout <<"            Transfer sukses!" << endl;

    cout << "|=========================================|" << endl;
    cout << "|  No. Rekening Tujuan: " << userTo.username << endl;
    cout << "|  Jenis Transaksi    : Transfer" << endl;
    cout << "|  Nominal           : Rp " << amount << endl;
    cout << "|=========================================|" << endl;

	cout << endl;
    cout << "Press Enter to Back";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getch();
    system("cls");
}
