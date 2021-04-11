#include "analyzer.h"

using namespace std;

Analyzer::Analyzer(){}

Analyzer::Analyzer(string token, string lexeme, string num){
    setToken(token);
    setLexeme(lexeme);
    setNum(num);
}

void Analyzer::setToken(string token){
    this->token = token;
}

void Analyzer::setLexeme(string lexeme){
    this->lexeme = lexeme;
}

void Analyzer::setNum(string num){
    this->num = num;
}

string Analyzer::getToken(){
    return token;
}

string Analyzer::getLexeme(){
    return lexeme;
}

string Analyzer::getNum(){
    return this->num;
}
