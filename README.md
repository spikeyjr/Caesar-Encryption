# Caesar-Encryption
Encryption program 
Caesar Encryption Program — Summary

You must write a C++ program that encrypts or decrypts text using a Caesar Cipher. The user chooses whether to encrypt or decrypt, provides an input file, enters a shift value, and the program outputs the transformed message into a second file.

Program Requirements

Must use:

File streams

Arrays

Functions

Must support shifting:

Letters a–z

Digits 0–9

Output should contain only lowercase letters.

Non-letter and non-digit characters must be copied unchanged.

Cannot use:

Mathematical wrap-around operations (like modulo) for shifting

Global variables (except for prototypes or enums)

User Flow

Ask user to choose encrypt or decrypt.

Ask for the input file name.

Ask for the shift number.

Process the text using your algorithm.

Write the result to result.txt or another file name chosen by the user.

Development Suggestions

Start with a high-level design:

Get user input

Read plaintext from file into an array

Shift characters to build the encrypted/decrypted text array

Write output to file

Use multiple functions to break the problem into smaller parts.

Add broad commented plans in your code before implementing details.

Build and test the program piece by piece.

Update your plan as you go.
