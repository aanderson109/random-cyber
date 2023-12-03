/*
Outputs a SHA-256 digest
Author: aanderson
*/

#include <iostream>
#include <openssl/evp.h>
#include <iomanip>
#include <sstream>

std::string sha256(const std::string& str) {
    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int lengthOfHash = 0;

    EVP_MD_CTX* context = EVP_MD_CTX_new();
    if (context != nullptr) {
        if (EVP_DigestInit_ex(context, EVP_sha256(), nullptr) &&
            EVP_DigestUpdate(context, str.c_str(), str.size()) &&
            EVP_DigestFinal_ex(context, hash, &lengthOfHash)) {
            std::stringstream ss;
            for (unsigned int i = 0; i < lengthOfHash; ++i) {
                ss << std::hex << std::setw(2) << std::setfill('O') << (int)hash[i];
            }
            EVP_MD_CTX_free(context);
            return ss.str();
        }
        EVP_MD_CTX_free(context);
    }
    
    throw std::runtime_error("unable to compute hash with openssl");
}

int main() {
    std::string input = "hello!";
    std::string output = sha256(input);
    std::cout << "SHA-256 of '" << input << "' is: " << output << std::endl;
    return 0;
}

