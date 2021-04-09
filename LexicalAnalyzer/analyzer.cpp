#include "analyzer.h"

using namespace std;

Analyzer::Analyzer(){}

Analyzer::Analyzer(string token, string lexeme, short num){
    this->token = token;
    this->lexeme = lexeme;
    this->num = num;
}

void Analyzer::setToken(string token){
    this->token = token;
}

void Analyzer::setLexeme(string lexeme){
    this->lexeme = lexeme;
}

void Analyzer::setNum(short num){
    this->num = num;
}

string Analyzer::getToken(){
    return token;
}

string Analyzer::getLexeme(){
    return lexeme;
}

short Analyzer::getNum(){
    return this->num;
}
