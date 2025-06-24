#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class temp
{
    string id, name, author, search;
    fstream file;

public:
    void addBook();
    void showAll();
    void extractBook();
} obj;

int main()
{
    cout << "--------------------------------" << endl;
    cout << "1- Show All Books" << endl;
    cout << "2-Extract Book" << endl;
    cout << "2- Add New Book" << endl;
    cout << "4- Exit" << endl;
    cout << "--------------------------------" << endl;
    char choice;
    cin >> choice;

    switch (choice)
    {
    case '1':
        cin.ignore();
        obj.showAll();

        break;

    case '2':
        cin.ignore();
        obj.extractBook();
        break;
    case '3':
        cin.ignore();
        obj.addBook();
        break;
    case '4':
        cout << "Exiting the program." << endl;
        return 0;

        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
    }
}

void temp::addBook()
{
    cout << "\nEnter Book ID: ";
    getline(cin, id);
    cout << "Enter Book Name: ";
    getline(cin, name);
    cout << "Enter Book Author: ";
    getline(cin, author);

    file.open("bookData.txt", ios ::out | ios::app);
    file << id << "*" << name << "*" << author << endl;
    file.close();
}

void temp ::showAll()
{
    file.open("bookData.txt", ios ::in);
    while (getline(file, id, '*') && getline(file, name, '*') && getline(file, author, '\n'))
    {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Author: " << author << endl;
    }
    file.close();
}

void temp ::extractBook()
{

    showAll();
    cout << "Enter Book ID to extract: ";
    getline(cin, search);

    file.open("bookData.txt", ios ::in);
    getline(file, id, '*');
    getline(file, name, '*');
    getline(file, author, '\n');

    cout << "\n\n";
    while (!file.eof())
    {
        if (id == search)
        {
            cout << "ID: " << id << endl;
            cout << "Name: " << name << endl;
            cout << "Author: " << author << endl;
            break;
        }
        getline(file, id, '*');
        getline(file, name, '*');
        getline(file, author, '\n');
    }
    file.close();
}
