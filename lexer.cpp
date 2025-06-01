#include <iostream>
#include <fstream> // Libary allows us to work with files
using namespace std;

// Define Token types
enum TokenType{
    Plus, Minus, Star, Slash, LeftParen, RightParen,
    IntLiteral, StringLiteral,
    Identifier, If, Else, While, Return,
    EndOfFile, Error
};


int main() {
    std:: ifstream file("source.txt");
    // Read input character by character by looping throught source.txt
    char c;
    while (file.get(c)){
        std::cout << c;
    }

    // Recognise and Extract tokens
    // Store tokens as Objext 


  return 0;
}