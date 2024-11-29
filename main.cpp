// File Name: Noble_PA2.cpp
// Author: Thaddeus Nathaniel L. Noble
// Email Address: tnoble@gbox.adnu.edu.ph
// ProgAss Number: 2
// Description: A CLI-based password validator that checks if a given input meets the criteria.
// Last Changed: November 28, 2024

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <thread>
#include <algorithm>
#include "colormod.h"
#include "validation.h"
using namespace std;

// Initializing color modifiers
Color::Modifier foregroundRed(Color::FG_RED);
Color::Modifier foregroundGreen(Color::FG_GREEN);
Color::Modifier foregroundDefaultColor(Color::FG_DEFAULT);

// Trim leading and trailing spaces 
string trimSpaces(const string &str) {
    size_t start = str.find_first_not_of(" ");
    size_t end = str.find_last_not_of(" ");
    return (start == string::npos || end == string::npos) ? "" : str.substr(start, end - start + 1);
}

// Splits the input using a delimiter (,)
vector<string> splitString(const string &str, char delimiter) {
    vector<string> tokens;
    string token;
    for (char ch : str) {
        if (ch == delimiter) {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
        } else {
            token += ch;
        }
    }
    if (!token.empty()) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    string passwordInput;

    // Splash screen
    cout << "Welcome to Password Validator!" << endl;
    cout << "==============================" << endl;
    // Add delay for 1 second
    this_thread::sleep_for(chrono::seconds(1));

    // Input prompt
    cout << "Please enter your password(s)" << endl << "(minimum of 6 characters, maximum of 12 characters, separated by commas):" << endl;
    getline(cin, passwordInput);

    // Parsing the input
    // Splitting and trimming the passwords
    vector<string> passwordList = splitString(passwordInput, ',');
    for (string &password : passwordList) {
        password = trimSpaces(password);
    }

    // Validate all passwords
    vector<string> validPasswords;
    vector<string> invalidPasswords;
    for (const string &pwd : passwordList) {
        if (isPasswordValid(pwd)) {
            validPasswords.push_back(pwd);
        } else {
            invalidPasswords.push_back(pwd);
        }
    }

    // Add artificial delay 
    cout << "Validating..." << endl;
    this_thread::sleep_for(chrono::seconds(1));

    // Outputs all valid passwords
    cout << "==============================" << endl;
    // Change the color of the output to green
    cout << foregroundGreen << "Valid Passwords:" << endl;
    cout << "------------------------------" << endl;
    for (int i = 0; i < validPasswords.size(); i++) {
        cout << validPasswords[i] << endl;
    }

    // Outputs all invalid passwords
    cout << "==============================" << endl;
    // Change the color of the output to red
    cout << foregroundRed << "Invalid Passwords:" << endl;
    cout << "------------------------------" << endl;
    for (int i = 0; i < invalidPasswords.size(); i++) {
        cout << invalidPasswords[i] << endl;
    }

    cout << "==============================" << endl;
    // Reset the color of the output to default
    cout << foregroundDefaultColor;

    return 0;
}