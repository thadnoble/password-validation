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
#include "validation.h"
// #include <regex>
using namespace std;

string passwordInput;
vector<string> passwordList;

int main() {
    cout << "Welcome to Password Validator!" << endl;
    cout << "==============================" << endl;

    // Asks user to input a password
    cout << "Please enter your password(s) (minimum of 6 characters, maximum of 12 characters, separated by commas):" << endl;
    getline(cin, passwordInput);
    
    // Adds input to a dynamic array of strings
    stringstream ss(passwordInput);
    string password;
    while (getline(ss, passwordInput, ',')) {
        passwordList.push_back(passwordInput);
    }
    
    // Validate all passwords entered
    vector<string> validPasswords;
    for (int i = 0; i < sizeof(passwordList); i++) {
        if (passwordValidation(passwordList[i])) {
            validPasswords.push_back(passwordList[i]);
        }
    }

    // Outputs all valid passwords
    for (int i = 0; i < sizeof(validPasswords); i++) {
        cout << validPasswords[i] << endl;
    }

    return 0;
}