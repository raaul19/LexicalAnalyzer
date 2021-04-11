#ifndef ANALYZER_H
#define ANALYZER_H

#include <string>
#include <iostream>
#include <ctype.h>
#include <list>

class Analyzer{
private:
    std::string token;
    std::string lexeme;
    std::string num;

public:
    Analyzer();
    Analyzer(std::string, std::string, std::string);

    void setToken(std::string);
    void setLexeme(std::string);
    void setNum(std::string);

    std::string getToken();
    std::string getLexeme();
    std::string getNum();

};

#endif // ANALYZER_H
