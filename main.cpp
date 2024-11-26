// File Name: main.cpp
// Author: Thaddeus Nathaniel L. Noble
// Email Address: tnoble@gbox.adnu.edu.ph
// ProgAss Number: 2
// Description: A password validator that checks if a given input meets the criteria.
// Last Changed: November 26, 2024

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
// #include <regex>
using namespace std;

string passwordInput;
char passwordChars[12];
bool hasLowercaseAlphabet, hasNumber, hasUppercaseAlphabet, hasSpecialChar, isMinimumLength, inputValid;

void validityCheck();

int main() {
    cout << "Welcome to Password Validator!" << endl;
    cout << "==============================" << endl;

    // Asks user to input a password
    cout << "Please enter your password (minimum of 6 characters, maximum of 12 characters, separated by commas):" << endl;
    getline(cin, passwordInput);
    
    // Adds input to a dynamic array of strings
    vector<string> passwords;
    stringstream ss(passwordInput);
    string password;

    while (getline(ss, passwordInput, ',')) {
        passwords.push_back(passwordInput);
    }

    // Split the string into an array of chars
    strcpy(passwordChars, passwordInput.c_str());

    // Checks if password has lowercase characters
    for (int i = 0; i < sizeof(passwordChars); i++) {
        if (islower(passwordChars[i])) {
            hasLowercaseAlphabet = true;
            break;
        }
    }

    // Checks if password has uppercase characters 
    for (int i = 0; i < sizeof(passwordChars); i++) {
        if (isupper(passwordChars[i])) {
            hasUppercaseAlphabet = true;
            break;
        }
    }

    // Checks if password has numbers 1-9
    /* for (int i = 0; i < sizeof(passwordChars); i++) {
        if (isupper(passwordChars[i])) {
            hasUppercaseAlphabet = true;
            break;
        }
    } */
    
    // validityCheck();
    return 0;
}

/* void validityCheck() {
    if (hasLowercaseAlphabet) {
        cout << "!! Password has at least 1 lowercase character" << endl;
    } else {
        cout << "!! Password has no lowercase characters" << endl;
    }

    if (hasUppercaseAlphabet) {
        cout << "!! Password has at least 1 uppercase character" << endl;
    } else {
        cout << "!! Password has at no uppercase characters" << endl;
    }
} */