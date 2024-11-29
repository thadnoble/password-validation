#include <iostream>
#include <cctype>
#include "validation.h"
using namespace std;

bool isPasswordValid(const string &password) {
    bool isMinimumLength = password.length() >= 6;
    bool hasLowercaseAlphabet = false;
    bool hasUppercaseAlphabet = false;
    bool hasNumber = false;
    bool hasSpecialChar = false;
    bool isMoreThanMaximumLength = password.length() > 12;

    // Loops through each character in the password
    for (char passwordChar : password) {
        if (islower(passwordChar)) {
            hasLowercaseAlphabet = true;
        } else if (isupper(passwordChar)) {
            hasUppercaseAlphabet = true;
        } else if (isdigit(passwordChar)) {
            hasNumber = true;
        } else if (!isalnum(passwordChar)) {
            hasSpecialChar = true;
        }
    }

    // Returns true if all criteria are met
    return isMinimumLength && !isMoreThanMaximumLength && hasLowercaseAlphabet && hasUppercaseAlphabet && hasNumber && hasSpecialChar;
}
