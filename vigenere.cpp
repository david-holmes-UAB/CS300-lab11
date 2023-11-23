#include "vigenere.h"

Vigenere::Vigenere(std::string inputKey) {
    key = inputKey;
}

std::string Vigenere::encrypt(std::string msg) {
    // string to hold encrypted char
    std::string encrypted = "";

    // position in the key
    int keyLen = key.length();
    // iterate over message
    for (int i = 0, keyPos = 0; i < msg.length(); i++) {
        char curr = msg[i];
        if (curr != ' '){
            /*
            * (keyPos % keyLen) ensures that the position in the key is
            * within the length of the key; TL;DR: ensures that the key
            * repeats if it is shorter than the message.
            *
            * Encryption algorithm Ei = ((Pi + Ki) % 26) + 'A'; adding 'A' ensures it's
            * in the ASCII value range for capital letters
            */
            encrypted += ((curr + key[keyPos % keyLen]) % 26) + 'A'; 
            keyPos++;  
        }
        else {
            encrypted += ' ';
        }
        
    }

    return encrypted;
}

std::string Vigenere::decrypt(std::string msg) {
    
    // string to hold the decrypted string
    std::string decrypted = "";
    
    // length of the key to iterate
    int keyLen = key.length();

    for (int i = 0, keyPos = 0; i < msg.length(); i++) {
        char curr = msg[i];
        if (curr != ' ') {
            // Decryption algorithm Di = (Ei - Ki + 26) % 26
            decrypted += (((curr - key[keyPos % keyLen]) + 26) % 26) + 'A';
            keyPos++;
        }
        else {
            decrypted += ' ';
        }
    }

    return decrypted;
}

bool Vigenere::isEncrypted(std::string encryptedMsg, std::string decryptedMsg) {
    if (decryptedMsg == decrypt(encryptedMsg)) {
        return true;
    }
    else {
        return false;
    }
}

void Vigenere::setKey(std::string inputKey) {
    key = inputKey;
}

Vigenere::~Vigenere() {
    /* Destructor */
}