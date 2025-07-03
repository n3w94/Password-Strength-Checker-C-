#include <iostream>
#include <string>
#include <cctype>

bool has_upper(const std::string& s) {
    for (char c : s) if (std::isupper(c)) return true;
    return false;
}
bool has_lower(const std::string& s) {
    for (char c : s) if (std::islower(c)) return true;
    return false;
}
bool has_digit(const std::string& s) {
    for (char c : s) if (std::isdigit(c)) return true;
    return false;
}
bool has_special(const std::string& s) {
    for (char c : s) if (!std::isalnum(c)) return true;
    return false;
}

int main() {
    std::string password;
    std::cout << "Enter a password to check its strength: ";
    std::getline(std::cin, password);

    bool strong = true;
    if (password.length() < 8) {
        std::cout << "Password is too short (minimum 8 characters)." << std::endl;
        strong = false;
    }
    if (!has_upper(password)) {
        std::cout << "Password should have at least one uppercase letter." << std::endl;
        strong = false;
    }
    if (!has_lower(password)) {
        std::cout << "Password should have at least one lowercase letter." << std::endl;
        strong = false;
    }
    if (!has_digit(password)) {
        std::cout << "Password should have at least one digit." << std::endl;
        strong = false;
    }
    if (!has_special(password)) {
        std::cout << "Password should have at least one special character (!@#$ etc)." << std::endl;
        strong = false;
    }

    if (strong)
        std::cout << "This is a strong password!" << std::endl;
    else
        std::cout << "Try to improve your password following the above suggestions." << std::endl;

    return 0;
}