# DES C++ Implementation

A clean, modular C++ implementation of the **Data Encryption Standard (DES)** algorithm operating in **Electronic Codebook (ECB)** mode.

## Features

- **Standard DES Algorithm:** Implements standard 16-round Feistel structure with standard permutation tables, expansion, S-box substitution, and subkey generation.
- **Modern C++ Design:** Built with C++17 standards, utilizing `std::bitset`, `std::string_view`, strongly-typed `enum class`, and standard containers.
- **Interactive CLI:** Menu-driven terminal interface to encrypt or decrypt 64-bit blocks using a 64-bit key (both provided as 16-character hexadecimal strings).

## Project Structure

- `DES.h`: Header file containing the main `DES` class interface and helper prototypes.
- `DES.cc`: Source file implementing the core cryptographic functions and permutation tables.
- `main.cc`: Driver program providing the user interface and input validation.

## Prerequisites

- **Compiler:** A C++ compiler supporting C++17 or higher (e.g., `g++` 7.0+, `clang++`, or MSVC).

## Building the Project

Compile the project using `g++` with the `-std=c++17` flag:

```bash
g++ -std=c++17 main.cc DES.cc -o des_program
```

## Usage

Run the compiled executable:

```bash
./des_program
```

### Prompt Input Format

- **Key:** Must be an exact 16-character Hexadecimal string (64 bits, e.g., `133457799BBCDFF1`).
- **Plaintext / Ciphertext:** Must be an exact 16-character Hexadecimal string (64 bits, e.g., `0123456789ABCDEF`).

### Example Run

```text
==========================================
0 - Encryption
1 - Decryption
Select option (0 or 1): 0
Enter 16-character Hex Key: 133457799BBCDFF1
Enter 16-character Hex Input: 0123456789ABCDEF

... [Intermediate Round State Output] ...

Resulting Ciphertext: 85E813540F0AB405
```

## Security Notice

This implementation is intended for **educational and learning purposes only**. DES has a short 56-bit key size and is considered cryptographically insecure by modern standards. Do not use this in production environments.