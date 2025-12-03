#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream> 
#include <string>
#include <vector> 
#include <algorithm>
#include <ctime>
using namespace std;
//****************************************************************

//*  FILE NAME: Caesar Encryption

//*

//*  AUTHOR: the goat

//*

//*  DESCRIPTION:The Caesar Cipher technique is one of the earliest and simplest methods of encryption techniques. It is simply a substitution cipher, i.e., each letter of a given text is replaced by a letter with a fixed number of positions down the alphabet. For example, with a shift of 1, A would be replaced by B, B would become C, and so on. The method is apparently named after Julius Caesar, who apparently used it to communicate with his officials. 

// To encrypt and decrypt a given text we need an integer value, known as a shift which indicates the number of positions each letter of the text has been moved down. 

//*

//* 

//*

//****************************************************************
//

void buildPlainArray(char myArray[]);
void buildCipherArray(char plainAlphabet[], char cipherAlphabet[], int shiftvalue, string descion);
int lengthfinder(ifstream &file);

int main() {
    ifstream file;
    string filename;
    cout << "Enter name of file" << endl;
    cin >> filename;
    
    file.open(filename);
    if (!file.is_open()) {
        cout << "Error opening: " << filename << endl;
        return 1;
    }
    string outputname;
    cout << "Type Output Filename: " << endl;
    cin >> outputname;
    ofstream output(outputname + ".txt");
    if (!output.is_open()) {
        cout << "Error creating file!" << endl;
        return 1;   
    }

    // decides whether the file should be encrypted or decrypted
    string descion;
    cout << "Would you like to encrypt or decrypt an encrypted file?: " << endl;
    while (true) {
        cout << "Type below: Encrypt  or Decrypt" << endl;
        cin >> descion;

        for (int i = 0; i < descion.length(); ++i){
            descion[i] = tolower(descion[i]);
        }
        if ((descion == "encrypt") || (descion == "decrypt")){
            break;
        }
        else {
            cout << "Invalid entry: " << endl;
        }
    }
    
    int shiftvalue;
    cout << "shift value" << endl;
    cin >> shiftvalue;
    
    // Build the plain alphabet array
    char plainAlphabet[36];
    buildPlainArray(plainAlphabet);
    
    cout << "Plain alphabet: ";
    for(int i = 0; i < 36; i++){
        cout << plainAlphabet[i] << " ";
    }
    cout << endl;
    
    // Build the cipher alphabet array (shifted version)
    char cipherAlphabet[36];
    buildCipherArray(plainAlphabet, cipherAlphabet, shiftvalue, descion);
    
    cout << "Cipher alphabet: ";
    for(int i = 0; i < 36; i++){
        cout << cipherAlphabet[i] << " ";
    }
    cout << endl;
    
    // Read and process each line from the file
    string sentence;
    while (getline(file, sentence)) {
        char result[sentence.length()];
        
        // Process each character in the line
        for (int i = 0; i < sentence.length(); i++){
            char currentChar = sentence[i];
            char upperChar = toupper(currentChar);
            
            // Find the character in the plain alphabet
            int index = -1;
            for (int j = 0; j < 36; j++){
                if (plainAlphabet[j] == upperChar) {
                    index = j;
                    break;
                }
            }
            
            // If character found, substitute with cipher character (lowercase)
            if (index != -1) {
                result[i] = tolower(cipherAlphabet[index]);
            }
            else {
                // Other characters copied as-is
                result[i] = currentChar;
            }
        }
        
        // Output the result
        cout << "Result: ";
        for (int i = 0; i < sentence.length(); i++) {
            cout << result[i];
        }
        cout << endl;
        for (int i = 0; i < sentence.length(); i++){
            output << result[i];
        }
    }
    cout << "Output Finished: " << endl;
    
    
    file.close();
    output.close();
    return 0;
}

void buildCipherArray(char plainAlphabet[], char cipherAlphabet[], int shiftvalue, string descion){
    if (descion == "encrypt"){
        // Shift forward for encryption
        for (int i = 0; i < 36; i++) {
            int newPosition = i + shiftvalue;
            
            // Manually wrap around if we go past the end
            while (newPosition >= 36) {
                newPosition = newPosition - 36;
            }
            
            cipherAlphabet[i] = plainAlphabet[newPosition];
        }
    }
    else {  // decrypt
        // Shift backward for decryption
        for (int i = 0; i < 36; i++) {
            int newPosition = i - shiftvalue;
            
            // Manually wrap around if we go below 0
            while (newPosition < 0) {
                newPosition = newPosition + 36;
            }
            
            cipherAlphabet[i] = plainAlphabet[newPosition];
        }
    }
}

int lengthfinder(ifstream &file){
    string word;
    int counter = 0;
    while (file >> word){
        counter++; 
    }
    cout << counter << endl;
    return counter; 
} 

void buildPlainArray(char myArray[]){
    int index = 0;

    char letter = 'A';
    for (int i = 0; i < 26; i++){
        myArray[index] = letter;
        letter++;
        index++;
    }
    char numbers = '0';
    for (int i = 0; i < 10; i++){
        myArray[index] = numbers;
        numbers++;
        index++;
    }
    cout << "Array filled" << endl;
}