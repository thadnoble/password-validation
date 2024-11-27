#include <iostream>
#include <cctype>
#include "validation.h"
using namespace std;

bool passwordValidation(std::string password_par) {
    // Initialize criteria booleans
    bool isMinimumLength = password_par.length() >= 6;
    bool hasLowercaseAlphabet = false;
    bool hasUppercaseAlphabet = false;
    bool hasNumber = false;
    bool hasSpecialChar = false;
    bool isMoreThanMaximumLength = password_par.length() > 12;

    // Validates each character of the password
    for (char ch : password_par){
        if (islower(ch)) {
            hasLowercaseAlphabet = true;
        } else if (isupper(ch)) {
            hasUppercaseAlphabet = true;
        } else if (isdigit(ch)) {
            hasNumber = true;
        } else if (!isalnum(ch)) {
            hasSpecialChar = true;
        }
    }

    return isMinimumLength && hasLowercaseAlphabet && hasUppercaseAlphabet && hasNumber && hasSpecialChar && !isMoreThanMaximumLength;
}