#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class temp
{
    string userName, Email, password;
    string temp;
    string searchName, searchPass, searchEmail;
    fstream file;

public:
    void login();
    void signUp();
    void forgot();

} obj;

int main()
{
    string hi;
    char choice;
    cout << "\n1- Login";
    cout << "\n2- Sign up";
    cout << "\n3- Forgot Password";
    cout << "\n4- Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    getline(cin, hi);

    switch (choice)
    {
    case '1':
        obj.login();
        break;
    case '2':
        obj.signUp();
        break;
    case '3':
        obj.forgot();
        break;
    case '4':
        return 0;

        break;
    default:
        cout << "Invalid choice. Please try again.";
    }
}

void temp ::signUp()
{

    cout << "\nEnter your username: ";
    getline(cin, userName);
    cout << "Enter Your Email: ";
    getline(cin, Email);
    cout << "Enter Your Password: ";
    getline(cin, password);

    file.open("loginData.txt", ios ::out | ios ::app);
    file << userName << "*" << Email << "*" << password << "\n";
    file.close();
}

void temp ::login()
{

    cout << "---------LOGIN---------\n";
    cout << "Enter Your Username: " << endl;

    getline(cin, searchName);
    cout << "Enter Your Password: " << endl;
    getline(cin, searchPass);

    file.open("loginData.txt", ios ::in);
    
    while (getline(file, userName, '*') &&
            getline(file, Email, '*') &&
            getline(file, password))
    {
        if (searchName == userName)
        {
            if (searchPass == password)
            {
                cout << "Login Successful!" << endl;
                cout << "\nusername: " << userName << endl;
                cout << "\nEmail: " << Email << endl;
            }
            else
            {
                cout << "Password incorrect!" << endl;
            }
            
        }
    }
}

void temp ::forgot()
{
    cout << "Enter your username: ";
    getline(cin, searchName);
    cout << "Enter your email: ";
    getline(cin, searchEmail);

    file.open("loginData.txt", ios::in);
    getline(file, userName, '*');
    getline(file, Email, '*');
    getline(file, password, '\n');

    while (!file.eof())
    {
        if (searchName == userName && Email == searchEmail)
        {
            cout << "Your password is: " << password << endl;
            file.close();
            return;
        }
        getline(file, userName, '*');
        getline(file, Email, '*');
        getline(file, password, '\n');
    }
    cout << "Username or email not found!" << endl;
    file.close();
}