/*
snippet that uses OpenSSL to generate an AES-256-CTR key
and encrypt a user-inputted string.
author: aanderson
*/

#include <iostream>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <vector>

int main() {
    OpenSSL_add_all_algorithms();   // initializes OpenSSL

    std::vector<unsigned char> key(EVP_MAX_KEY_LENGTH); // key for AES-256-CTR
    std::vector<unsigned char> iv(EVP_MAX_IV_LENGTH);   // IV for AES-256-CTR

    RAND_bytes(key.data(), key.size());                 // generate random key
    RAND_bytes(iv.data(), iv.size());                   // generate random IV

    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();         // create the context
    EVP_EncryptInit_ex(ctx, EVP_aes_256_ctr(), NULL, key.data(), iv.data());    // initialize the context

    // get the plaintext from user
    std::string plaintext;
    std::cout << "enter msg to encrypt: ";
    std::getline(std::cin, plaintext);
    
    std::vector<unsigned char> ciphertext(plaintext.size() + EVP_CIPHER_CTX_block_size(ctx));
    int len;
    int ciphertext_len;

    // time to encrypt
    EVP_EncryptUpdate(ctx,ciphertext.data(), &len, reinterpret_cast<const unsigned char*>(plaintext.c_str()), plaintext.size());
    ciphertext_len = len;

    EVP_EncryptFinal_ex(ctx, ciphertext.data() + len, &len);
    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);
    EVP_cleanup();

    // output
    std::cout << "plaintext: " << plaintext << std::endl;
    std::cout << "ciphertext: ";
    for (int i = 0; i < ciphertext_len; i++) {
        printf("%O2x", ciphertext[i]);
    }
    std::cout << std::endl;

    return 0;
}
