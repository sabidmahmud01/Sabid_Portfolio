#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class temp
{
    string rollNo, name, fName, address, search;
    fstream file;

public:
    void addStu();
    void viewStu();
    void searchStu();
} obj;

int main()
{
    char choice;
    cout << "---------------------------------\n";
    cout << "1. Add Student Record\n";
    cout << "2. View Student Records\n";
    cout << "3. Search Student Record\n";
    cout << "4. Exit\n";
    cout << "---------------------------------\n";

    cin >> choice;

    switch (choice)
    {
    case '1':
        cin.ignore(); // Clear the newline character from the input buffer
        obj.addStu();
        break;
    case '2':
        obj.viewStu();
        break;
    case '3':
        cin.ignore(); // Clear the newline character from the input buffer
        obj.searchStu();
        break;

    case '4':
        cout << "Exiting the program.\n";
        return 0;

    default:
        cout << "Invalid choice. Please try again.\n";
    }
}

void temp::addStu()
{
    cout << "Enter Roll No: ";
    getline(cin, rollNo);
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Father's Name: ";
    getline(cin, fName);
    cout << "Enter Address: ";
    getline(cin, address);
    file.open("studentManagement.txt", ios::out | ios::app);
    file << rollNo << "*" << name << "*" << fName << "*" << address << "\n";
    file.close();
}

void temp::viewStu()
{
    file.open("studentManagement.txt", ios ::in);
    while (getline(file, rollNo, '*') &&
           getline(file, name, '*') &&
           getline(file, fName, '*') &&
           getline(file, address, '\n'))
    {
        cout << "-----------------------------\n";
        cout << "Roll No: " << rollNo << "\n";
        cout << "Name: " << name << "\n";
        cout << "Father's Name: " << fName << "\n";
        cout << "Address: " << address << "\n";
        cout << "-----------------------------\n";
    }
    file.close();
}

void temp::searchStu()
{
    cout << "Enter Roll Number to Search: ";
    getline(cin, search);
    file.open("studentManagement.txt", ios::in);
    while (getline(file, rollNo, '*') &&
           getline(file, name, '*') &&
           getline(file, fName, '*') &&
           getline(file, address, '\n'))
    {
        if (rollNo == search)
        {
            cout << "-----------------------------\n";
            cout << "Roll No: " << rollNo << "\n";
            cout << "Name: " << name << "\n";
            cout << "Father's Name: " << fName << "\n";
            cout << "Address: " << address << "\n";
            cout << "-----------------------------\n";
        }
    }
    file.close();
}