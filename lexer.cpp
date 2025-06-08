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


std::string tokenToString(TokenType token) {
    switch (token) {
        case Plus: return "Plus";
        case Minus: return "Minus";
        case Star: return "Star";
        case Slash: return "Slash";
        case LeftParen: return "LeftParen";
        case RightParen: return "RightParen";
        case IntLiteral: return "IntLiteral";
        case StringLiteral: return "StringLiteral";
        case Identifier: return "Identifier";
        case If: return "If";
        case Else: return "Else";
        case While: return "While";
        case Return: return "Return";
        case EndOfFile: return "EndOfFile";
        case Error: return "Error";
        default: return "Unknown";
    }
}


int main() {
    std::ifstream file("source.txt");
    if(!file){
        std::cerr << "Error with opening source.text\n";
        return -1;

    }
    // Read input character by character by looping through source.txt
    char c;
    std::vector<TokenType> tokenlist;
    while (file.get(c)){
        TokenType token;
        // Check for groups of numbers that will be labelled together
        if (isdigit(c)){
            string consecutiveNums = "";
            consecutiveNums += c;

            while(isdigit(file.peek())){
                file.get(c);
                consecutiveNums += c;
            }
            token = IntLiteral;
            tokenlist.push_back(token);
            std::cout << (token) << " ";
            continue;
        }
        else if (isalpha(c)){
            string consecutiveChar = "";
            consecutiveChar += c;

            while(isalnum(file.peek())){
                file.get(c);
                consecutiveChar += c;
            }
            if (consecutiveChar == "if") token = If;
            else if (consecutiveChar == "else") token = Else;
            else if (consecutiveChar == "while") token = While;
            else if (consecutiveChar == "return") token = Return;
            else token = Identifier;
            tokenlist.push_back(token);
            std::cout << (token) << " ";
            continue;

        }
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
            case ' ':
                continue;
            case '\n':
                continue;
            case '\t':
                continue;
            default:
                token = Error;
                tokenlist.push_back(token);
                break;
        }
        std::cout << tokenToString(token) << " ";
    }

    file.close();

    // Recognise and Extract tokens
    // Store tokens as Object 


  return 0;
}