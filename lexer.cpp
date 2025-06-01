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
    std::ifstream file("source.txt");
    if(!file){
        std::cerr << "Error with opening source.tsxt\n";
        return -1;

    }
    // Read input character by character by looping through source.txt
    char c;
    while (file.get(c)){
        cout << c << " ";
    }

    file.close();

    // Recognise and Extract tokens
    // Store tokens as Object 


  return 0;
}