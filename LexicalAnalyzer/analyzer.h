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
    short num;

public:
    Analyzer();
    Analyzer(std::string, std::string, short);

    void setToken(std::string);
    void setLexeme(std::string);
    void setNum(short);

    std::string getToken();
    std::string getLexeme();
    short getNum();

};

#endif // ANALYZER_H
