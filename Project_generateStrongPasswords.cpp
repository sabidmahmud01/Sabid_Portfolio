#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


string getPassword(int length){
    string Password = "";
    string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+[]{}|;:,.<>?";
    int charSize = characters.size();
    srand(time(0)); // Seed for random number generation
    int randomIndex;
    for(int i = 0; i < length; i++){
        randomIndex = rand() % charSize; // Generate a random index
        Password += characters[randomIndex]; // Append the character at the random index
    }
    return Password; // Return the generated password
}

int main(){

    cout <<"Enter the length of the Password: ";

    int length;
    cin >> length;

    string password = getPassword(length);

    cout << "Generated Password: " << password;

    return 0;

}