#include <iostream>
#include <string>
#include <string_view>
#include "DES.h"

namespace {
    bool ValidateHexInput(const std::string& input, size_t expected_length) {
        if (input.size() != expected_length) return false;
        return input.find_first_not_of("0123456789abcdefABCDEF") == std::string::npos;
    }
}

int main() {
    bool continue_program = true;

    while (continue_program) {
        std::cout << "\n==========================================" << std::endl;
        std::cout << "0 - Encryption\n1 - Decryption\nSelect option (0 or 1): ";
        
        int mode_choice;
        if (!(std::cin >> mode_choice) || (mode_choice != 0 && mode_choice != 1)) {
            std::cerr << "Error: Invalid selection. Exiting.\n";
            return 1;
        }

        Operation op = static_cast<Operation>(mode_choice);

        std::string key;
        std::cout << "Enter 16-character Hex Key: ";
        std::cin >> key;
        if (!ValidateHexInput(key, 16)) {
            std::cerr << "Error: Key must be exactly 16 hexadecimal characters.\n";
            return 1;
        }

        std::string input_text;
        std::cout << "Enter 16-character Hex Input: ";
        std::cin >> input_text;
        if (!ValidateHexInput(input_text, 16)) {
            std::cerr << "Error: Input text must be exactly 16 hexadecimal characters.\n";
            return 1;
        }

        try {
            if (op == Operation::Encrypt) {
                std::string ciphertext = DES::Encrypt(input_text, key);
                std::cout << "\nResulting Ciphertext: " << ciphertext << "\n";
            } else {
                std::string plaintext = DES::Decrypt(input_text, key);
                std::cout << "\nResulting Plaintext: " << plaintext << "\n";
            }
        } catch (const std::exception& ex) {
            std::cerr << "Execution Error: " << ex.what() << "\n";
            return 1;
        }

        std::cout << "\n0 - Run again\n1 - Exit\nSelect option: ";
        int exit_choice;
        std::cin >> exit_choice;
        continue_program = (exit_choice == 0);
    }

    return 0;
}