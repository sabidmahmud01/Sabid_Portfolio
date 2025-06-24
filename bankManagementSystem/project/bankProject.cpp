#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class temp
{
    int accNo;
    char name[25];
    char fname[25];
    char cnic[25];
    char pnumber[25];
    char email[25];
    float amount;
    int newAmount;
    fstream file, file1;

public:
    int search;

    void createAccount(void);
    void depositAmount(void);
    void withdrawAmount(void);
    void checkInfo(void);
};

int main()
{
    temp obj;
    char choice;

    cout << "Welcome to the Bank Management System!" << endl;
    cout << "Choose an option:" << endl;
    cout << "1. Make Transaction or Check Balance" << endl;
    cout << "2. Create Amount" << endl;
    cout << "0. Exit" << endl;
    cin >> choice;

    switch (choice)
    {
    case '1':
        cout << "You have chosen to make transaction or check balance." << endl;

        cout << "1. Deposit Amount" << endl;
        cout << "2. Withdraw Amount" << endl;
        cout << "3. Check Information" << endl;
        cout << "0. Exit" << endl;
        char action;
        cin >> action;

        switch (action)
        {
        case '0':
            cout << "Exiting the program." << endl;
            return 0;
        case '1':
            obj.depositAmount();
            break;
        case '2':
            obj.withdrawAmount();
            break;
        case '3':
            obj.checkInfo();
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
        break;

    case '2':
        obj.createAccount();
        break;

    case '0':
        cout << "Exiting the program." << endl;
        return 0;

    default:
        cout << "Invalid choice!" << endl;
    }
}

void temp ::createAccount()
{
    srand(time(0));
    accNo = rand() * rand() + rand() * rand();

    cout << "Enter your first name: ";
    cin >> name;

    cout << "Enter your father's first name: ";
    cin >> fname;

    cout << "Enter your CNIC: ";
    cin >> cnic;

    cout << "Enter your phone number: ";
    cin >> pnumber;

    cout << "Enter your email: ";
    cin >> email;

    cout << "Enter the amount you want to deposit: ";
    cin >> amount;

    cout << accNo << " This is your account number." << endl;
    cout << "Please keep it safe." << endl;

    file.open("data.txt", ios::out | ios::app);
    file << accNo << "\t" << name << "\t" << fname << "\t"
         << cnic << "\t" << pnumber << "\t" << email
         << "\t" << amount << endl;

    file.close();
}

void temp::depositAmount()
{
    cout << "Enter your account number: ";
    cin >> search;

    file.open("data.txt", ios::in);
    file1.open("temp.txt", ios::out | ios::app);

    while (file >> accNo >> name >> fname >> cnic >> pnumber >> email >> amount)
    {
        if (accNo == search)
        {
            cout << "Enter the amount you want to deposit: ";
            cin >> newAmount;
            amount += newAmount;
            cout << "Your new balance is: " << amount << endl;
        }
        file1 << accNo << "\t" << name << "\t" << fname
              << "\t" << cnic << "\t" << pnumber
              << "\t" << email << "\t" << amount << endl;
    }

    file.close();
    file1.close();
    remove("data.txt");
    rename("temp.txt", "data.txt");
}

void temp::withdrawAmount()
{
    cout << "Enter your account number: ";
    cin >> search;

    file.open("data.txt", ios::in);
    file1.open("temp.txt", ios::out | ios::app);

    while (file >> accNo >> name >> fname >> cnic >> pnumber >> email >> amount)
    {
        if (accNo == search)
        {
            cout << "Enter the amount you want to withdraw: ";
            cin >> newAmount;
            if (newAmount > amount)
            {
                cout << "Insufficient balance!" << endl;
            }
            else
            {
                amount -= newAmount;
                cout << "Your new balance is: " << amount << endl;
            }
        }
        file1 << accNo << "\t" << name << "\t" << fname
              << "\t" << cnic << "\t" << pnumber
              << "\t" << email << "\t" << amount << endl;
    }

    file.close();
    file1.close();
    remove("data.txt");
    rename("temp.txt", "data.txt");
}

void temp::checkInfo()
{
    cout << "Enter your account number: ";
    cin >> search;

    file.open("data.txt", ios::in);

    while (file >> accNo >> name >> fname >> cnic >> pnumber >> email >> amount)
    {
        if (accNo == search)
        {
            cout << "Account Number: " << accNo << endl;
            cout << "Name: " << name << endl;
            cout << "Father's Name: " << fname << endl;
            cout << "CNIC: " << cnic << endl;
            cout << "Phone Number: " << pnumber << endl;
            cout << "Email: " << email << endl;
            cout << "Balance: " << amount << endl;
        }
    }

    file.close();
}