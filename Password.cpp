#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

std::string generatePassword(int length) {
    const std::string characters =
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+{}|[]\\:;\"'<>,.?/";
    std::string password;
    srand(time(nullptr)); // Seed the random number generator

    for (int i = 0; i < length; ++i) {
        int randomIndex = rand() % characters.length();
        password += characters[randomIndex];
    }

    return password;
}

int main() {
    int length;
    std::cout << "Enter the length of the password: ";
    std::cin >> length;
    std::cout << "Generated password: " << generatePassword(length) << std::endl;

    return 0;
}
