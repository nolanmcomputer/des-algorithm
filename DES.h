#ifndef DES_H
#define DES_H

#include <string>
#include <vector>
#include <string_view>

enum class Operation {
    Encrypt = 0,
    Decrypt = 1
};

class DES {
public:
    // Core API for DES encryption and decryption
    static std::string Encrypt(std::string_view hex_text, std::string_view hex_key);
    static std::string Decrypt(std::string_view hex_text, std::string_view hex_key);

private:
    // Internal helper routines
    static std::string ConvertHexToBin(std::string_view hex_str);
    static std::string ConvertBinToHex(std::string_view bin_str);
    
    static std::string InitialPermutation(std::string_view block);
    static std::string InverseInitialPermutation(std::string_view block);
    static std::string PC1Permutation(std::string_view key);
    static std::string Expansion(std::string_view right_block);
    static std::string Permutation(std::string_view sbox_output);
    static std::string SboxSubstitution(std::string_view xor_output);
    
    static std::vector<std::string> GenerateSubkeys(std::string_view binary_key);
    static std::string PerformRounds(std::string_view block, const std::vector<std::string>& subkeys);
};

#endif // DES_H