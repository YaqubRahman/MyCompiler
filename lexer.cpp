#include <iostream>
#include <vector>
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
    std::vector<TokenType> tokenlist;
    while (file.get(c)){
        TokenType token;
        switch(c){
            case '+':
                token = Plus;
                tokenlist.push_back(token);
                break;
            case '-':
                token = Minus;
                tokenlist.push_back(token);
                break;
            case '*':
                token = Star;
                tokenlist.push_back(token);
                break;
            case '/':
                token = Slash;
                tokenlist.push_back(token);
                break;
            case '(':
                token = LeftParen;
                tokenlist.push_back(token);
                break;
            case ')':
                token = RightParen;
                tokenlist.push_back(token);
                break;
            default:
                token = Error;
                tokenlist.push_back(token);
                break;
        }
        std::cout << token << " ";
    }

    file.close();

    // Recognise and Extract tokens
    // Store tokens as Object 


  return 0;
}