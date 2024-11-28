// File Name: main.cpp
// Author: Thaddeus Nathaniel L. Noble
// Email Address: tnoble@gbox.adnu.edu.ph
// ProgAss Number: 2
// Description: A password validator that checks if a given input meets the criteria.
// Last Changed: November 28, 2024

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "validation.h"
#include "colormod.h"
using namespace std;

string passwordInput;
vector<string> passwordList;

Color::Modifier red(Color::FG_RED);
Color::Modifier green(Color::FG_GREEN);
Color::Modifier defaultColor(Color::FG_DEFAULT);

int main() {
    // Splash 
    cout << "Welcome to Password Validator!" << endl;
    cout << "==============================" << endl;

    // do {
        // Asks user to input a password
        cout << "Please enter your password(s) (minimum of 6 characters, maximum of 12 characters, separated by commas):" << endl;
        cout << "(Press X to exit.)" << endl;
        getline(cin, passwordInput);
        
        // Allows input to be added to a vector
        stringstream ss(passwordInput);
        string password;
        // Splits the input by commas
        while (getline(ss, passwordInput, ',')) {
            passwordList.push_back(passwordInput);
        }
        
        // Validate all passwords entered
        vector<string> validPasswords;
        for (int i = 0; i < passwordList.size(); i++) {
            if (passwordValidation(passwordList[i])) {
                validPasswords.push_back(passwordList[i]);
            }
        }

        // Outputs all valid passwords
        cout << "==============================" << endl;
        cout << green << "Valid Passwords:" << endl;
        for (int i = 0; i < validPasswords.size(); i++) {
            cout << validPasswords[i] << endl;
        }

        // Outputs all invalid passwords
        vector<string> invalidPasswords;
        cout << "==============================" << endl;
        cout << red << "Invalid Passwords:" << endl;
        for (int i = 0; i < passwordList.size(); i++) {
            if (!passwordValidation(passwordList[i])) {
                invalidPasswords.push_back(passwordList[i]);
            }
        }
        for (int i = 0; i < invalidPasswords.size(); i++) {
            cout << invalidPasswords[i] << endl;
        }

        cout << "==============================" << endl;
        cout << defaultColor;
    // } while (passwordInput != "X" && passwordInput != "x");
    return 0;
}