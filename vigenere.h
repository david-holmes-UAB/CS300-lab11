/*!
* File: vigenere.h
* ---------------------------------------------
* File that outlines the Vigenere class. The Vigenere class
* uses a set key to encrypt and decrypt messages, with the letters 
* of the key acting as guidelines to move the letters in the original
* message a certain amount.
*
* For example: 'A' => no movement, 'D' => Move three letters forward.
*
* The current implementation of this function retains the whitespace it
* is provided in the input. It also assumes all inputs and outputs will be in uppercase.
*/

#ifndef _vigenere_h
#define _vigenere_h

#include <string>

class Vigenere {
    private:
    //! String holding the key to be used for encrypting and decrypting within the cipher.
    std::string key;            

    public:
    //! Creates a new Vigenere cipher object.
    /*!
    * @param key A std::string representing the key to be used for encrypting and decrypting within
    * the Vigenere cipher object.
    */
    Vigenere(std::string key); 

    //! Descructor for the Vigenere cipher object.
    ~Vigenere();               

    //! Encrypts a provided string with the Vigenere cipher using the set key.
    /*!
    * @param msg A std::string corresponding to the message to be encrypted using the cipher key.
    * @return Returns the encrypted string.
    */
    std::string encrypt(std::string msg);

    //! Decrypts a provided string with the Vigenere cipher using the set key.
    /*!
    * @param msg A std::string corresponding to the message to the already 
    * encrypted message to be decrypted using the inputted cipher key.
    * @return Returns the decrypted string.
    */
    std::string decrypt(std::string msg);

    //! Boolean to check if an encrypted string is encrypted correctly using the Vigenere cipher.
    /*!
    * @param encryptedMsg A std::string holding an encrypted string.
    * @param decryptedMsg A std::string holding the original unencrypted string.
    * @return Returns true if the encrypted string would match the original decryptedMsg when decrypted. Returns
    * false otherwise.
    */
    bool isEncrypted(std::string encryptedMsg, std::string decryptedMsg);

    //! Sets the key to the cipher to a different string keyword.
    /*!
    * @param key A std::string holding a specified key to be stored as the Vigenere cipher key.
    */
    void setKey(std::string key);

};

#endif