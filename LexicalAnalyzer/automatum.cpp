#include "automatum.h"

using namespace std;

enum{ START, ID, RESERVED,EQUALS, LOGIC, RELATIONAL, CONSTANTS, EXCLAMATION};

Automatum::Automatum(){}

list<Analyzer> Automatum::automata(std::string text){
    text +=" ";
    short state = 0;
    char buffer;
    string strToken;
    bool decimal = false;
    list<Analyzer> tokenList;
    int textSize = text.size();

    for(unsigned int i=0 ;i < textSize; i++){
        buffer = text[i];
        //Automatum
        switch(state){
            case START:
                if(isalpha(buffer)){
                    state = RESERVED;
                    strToken += buffer;
                }
                else if(buffer == '_'){
                    state = ID;
                    strToken += buffer;
                }
                else if(isdigit(buffer)){
                    state = CONSTANTS;
                    strToken += buffer;
                }
                else if(buffer == ';'){ // SEMICOLON
                    strToken ="";
                    strToken += buffer;
                    Analyzer tokenItem(";",strToken,"2");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == ','){ // COMA
                    strToken ="";
                    strToken += buffer;
                    Analyzer tokenItem(",",strToken,"3");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '('){// OPEN PARENTHESIS
                    strToken ="";
                    strToken += buffer;
                    Analyzer tokenItem("(",strToken,"4");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == ')'){ // CLOSING PARENTHESIS
                    strToken ="";
                    strToken += buffer;
                    Analyzer tokenItem(")",strToken,"5");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '{'){ // OPEN BRACKET
                    strToken ="";
                    strToken += buffer;
                    Analyzer tokenItem("{",strToken,"6");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '}'){ //CLOSING BRACKET
                    strToken ="";
                    strToken += buffer;
                    Analyzer tokenItem("}",strToken,"7");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '='){
                    strToken ="";
                    state = EQUALS;
                    strToken += buffer;
                }
                else if(buffer == '$'){ // PESOS SIGN
                    strToken ="";
                    strToken += buffer;
                    Analyzer tokenItem("$",strToken,"18");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '+' || buffer == '-'){ // ADD SUBSTRACT
                    strToken ="";
                    strToken += buffer;
                    Analyzer tokenItem("OpSuma",strToken,"14");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '*' || buffer == '/'){ // MULT DIV
                    strToken ="";
                    strToken += buffer;
                    Analyzer tokenItem("OpMultiplicacion",strToken,"16");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '|' || buffer == '&' ){
                    strToken ="";
                    state = LOGIC;
                    strToken += buffer;
                }
                else if(buffer == '>' || buffer == '<'){
                    strToken ="";
                    state = RELATIONAL;
                    strToken += buffer;
                }
                else if(buffer == '!'){
                    strToken= "";
                    state = EXCLAMATION;
                    strToken += buffer;
                }
                else if(buffer == '@' || buffer == '?' || buffer == '\'' || buffer == '\"'
                        || buffer == '#' || buffer == '¿' || buffer == '%'){
                    strToken ="";
                    state = START;
                    strToken += buffer;
                    Analyzer tokenItem("Error",strToken,"-1");
                    tokenList.push_back(tokenItem);
                    strToken ="";
                }
                else{// espacio, \t , \n ,lambda
                    //stays here
                    state = START;
                }
                break;
            case ID:// Identificador  = hola2 ||  _hola2
                if(isalnum(buffer)){
                    state = ID;
                    strToken += buffer;
                    if(i == textSize - 2){ // end of input
                        state = START;
                        Analyzer tokenItem("Identificador",strToken,"1");
                        tokenList.push_back(tokenItem);
                    }
                }
                else if(buffer == ';'){ // SEMICOLON
                    Analyzer tokenItem1("Identificador",strToken,"1");
                    tokenList.push_back(tokenItem1);
                    strToken ="";
                    strToken += buffer;
                    Analyzer tokenItem(";",strToken,"2");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == ','){ // COMA
                    Analyzer tokenItem1("Identificador",strToken,"1");
                    tokenList.push_back(tokenItem1);
                    strToken ="";
                    strToken += buffer;
                    Analyzer tokenItem(",",strToken,"3");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '('){// OPEN PARENTHESIS
                    Analyzer tokenItem1("Identificador",strToken,"1");
                    tokenList.push_back(tokenItem1);
                    strToken ="";
                    strToken += buffer;
                    Analyzer tokenItem("(",strToken,"4");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == ')'){ // CLOSING PARENTHESIS
                    Analyzer tokenItem1("Identificador",strToken,"1");
                    tokenList.push_back(tokenItem1);
                    strToken ="";
                    strToken += buffer;
                    Analyzer tokenItem(")",strToken,"5");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '{'){ // OPEN BRACKET
                    Analyzer tokenItem1("Identificador",strToken,"1");
                    tokenList.push_back(tokenItem1);
                    strToken ="";
                    strToken += buffer;
                    Analyzer tokenItem("{",strToken,"6");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '}'){ //CLOSING BRACKET
                    Analyzer tokenItem1("Identificador",strToken,"1");
                    tokenList.push_back(tokenItem1);
                    strToken ="";
                    strToken += buffer;
                    Analyzer tokenItem("}",strToken,"7");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '='){
                    state = EQUALS;
                    strToken += buffer;
                }
                else if(buffer == '$'){ // PESOS SIGN
                    Analyzer tokenItem1("Identificador",strToken,"1");
                    tokenList.push_back(tokenItem1);
                    strToken ="";
                    strToken += buffer;
                    Analyzer tokenItem("$",strToken,"18");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '+' || buffer == '-'){ // ADD SUBSTRACT
                    Analyzer tokenItem1("Identificador",strToken,"1");
                    tokenList.push_back(tokenItem1);
                    strToken ="";
                    strToken += buffer;
                    Analyzer tokenItem("OpSuma",strToken,"14");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '*' || buffer == '/'){ // MULT DIV
                    Analyzer tokenItem1("Identificador",strToken,"1");
                    tokenList.push_back(tokenItem1);
                    strToken ="";
                    strToken += buffer;
                    Analyzer tokenItem("OpMultiplicacion",strToken,"16");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '|' || buffer == '&' ){
                    Analyzer tokenItem1("Identificador",strToken,"1");
                    tokenList.push_back(tokenItem1);
                    strToken ="";
                    state = LOGIC;
                    strToken += buffer;
                }
                else if(buffer == '>' || buffer == '<'){
                    Analyzer tokenItem1("Identificador",strToken,"1");
                    tokenList.push_back(tokenItem1);
                    strToken ="";
                    state = RELATIONAL;
                    strToken += buffer;
                }
                else if(buffer == '!'){
                    Analyzer tokenItem1("Identificador",strToken,"1");
                    tokenList.push_back(tokenItem1);
                    strToken= "";
                    state = EXCLAMATION;
                    strToken += buffer;
                }
                else if(buffer == '@' || buffer == '?' || buffer == '\'' || buffer == '\"'
                        || buffer == '#' || buffer == '¿' || buffer == '%'){
                    Analyzer tokenItem1("Identificador",strToken,"1");
                    tokenList.push_back(tokenItem1);
                    strToken ="";
                    state = START;
                    strToken += buffer;
                    Analyzer tokenItem("Error",strToken,"-1");
                    tokenList.push_back(tokenItem);
                    strToken ="";
                }
                else{// espacio, \t , \n ,lambda
                    Analyzer tokenItem("Identificador",strToken,"1");
                    tokenList.push_back(tokenItem);
                    strToken = ""; // new
                    state = START;
                }
                break;
            case RESERVED: //while, if, else, return  // int float char void
                if(isalpha(buffer)){
                    state = RESERVED;
                    strToken += buffer;
                    if(strToken == "while"){
                        cout << "Token: " << strToken << endl;\
                        Analyzer tokenItem("While",strToken,"10");
                        tokenList.push_back(tokenItem);
                        strToken = ""; // new
                        state = START;
                    }
                    else if(strToken == "if"){
                        cout << "Token: " << strToken << endl;
                        Analyzer tokenItem("If",strToken,"9");
                        tokenList.push_back(tokenItem);
                        strToken = ""; // new
                        state = START;
                    }
                    else if(strToken == "else"){
                        cout << "Token: " << strToken << endl;
                        Analyzer tokenItem("Else",strToken,"12");
                        tokenList.push_back(tokenItem);
                        strToken = ""; // new
                        state = START;
                    }
                    else if(strToken == "return"){
                        cout << "Token: " << strToken << endl;
                        Analyzer tokenItem("Return",strToken,"11");
                        tokenList.push_back(tokenItem);
                        strToken = ""; // new
                        state = START;
                    }
                    else if(strToken == "int"  || strToken == "float" || strToken == "char"
                                || strToken == "void"){
                        cout << "Token: " << strToken << endl;
                        Analyzer tokenItem("Tipo dato",strToken,"0");
                        tokenList.push_back(tokenItem);
                        strToken = ""; // new
                        state = START;
                    }
                }
                else if(isdigit(buffer)){
                    state = ID;
                    strToken += buffer;
                    if(i == textSize - 2){ // end of input
                        state = START;
                        Analyzer tokenItem("Identificador",strToken,"1");
                        tokenList.push_back(tokenItem);
                    }
                }
                else{// espacio, \t , \n ,lambda
                    state = RESERVED;
                    //strToken += buffer;
                    if(strToken == "while"){
                        cout << "Token: " << strToken << endl;\
                        Analyzer tokenItem("While",strToken,"10");
                        tokenList.push_back(tokenItem);
                        strToken = ""; // new
                        state = 0;
                    }
                    else if(strToken == "if"){
                        cout << "Token: " << strToken << endl;
                        Analyzer tokenItem("If",strToken,"9");
                        tokenList.push_back(tokenItem);
                        strToken = ""; // new
                        state = 0;
                    }
                    else if(strToken == "else"){
                        cout << "Token: " << strToken << endl;
                        Analyzer tokenItem("Else",strToken,"12");
                        tokenList.push_back(tokenItem);
                        strToken = ""; // new
                        state = 0;
                    }
                    else if(strToken == "return"){
                        cout << "Token: " << strToken << endl;
                        Analyzer tokenItem("Return",strToken,"11");
                        tokenList.push_back(tokenItem);
                        strToken = ""; // new
                        state = 0;
                    }
                    else if(strToken == "int"  || strToken == "float" || strToken == "char"
                                || strToken == "void"){
                        cout << "Token: " << strToken << endl;
                        Analyzer tokenItem("Tipo dato",strToken,"0");
                        tokenList.push_back(tokenItem);
                        strToken = ""; // new
                        state = 0;
                    }
                    else{
                        Analyzer tokenItem("Identificador",strToken,"1");
                        tokenList.push_back(tokenItem);
                        strToken = ""; // new
                        state = START;
                    }
                }
                break;
            case EQUALS:
                if( buffer == '='){
                    strToken += buffer;
                    Analyzer tokenItem("OpRelacional",strToken,"17");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == ';'){ // SEMICOLON
                    Analyzer tokenItem1("=",strToken,"8");
                    tokenList.push_back(tokenItem1);
                    strToken ="";
                    strToken += buffer;
                    Analyzer tokenItem(";",strToken,"2");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == ','){ // COMA
                    Analyzer tokenItem1("=",strToken,"8");
                    tokenList.push_back(tokenItem1);
                    strToken ="";
                    strToken += buffer;
                    Analyzer tokenItem(",",strToken,"3");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '('){// OPEN PARENTHESIS
                    Analyzer tokenItem1("=",strToken,"8");
                    tokenList.push_back(tokenItem1);
                    strToken ="";
                    strToken += buffer;
                    Analyzer tokenItem("(",strToken,"4");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == ')'){ // CLOSING PARENTHESIS
                    Analyzer tokenItem1("=",strToken,"8");
                    tokenList.push_back(tokenItem1);
                    strToken ="";
                    strToken += buffer;
                    Analyzer tokenItem(")",strToken,"5");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '{'){ // OPEN BRACKET
                    Analyzer tokenItem1("=",strToken,"8");
                    tokenList.push_back(tokenItem1);
                    strToken ="";
                    strToken += buffer;
                    Analyzer tokenItem("{",strToken,"6");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '}'){ //CLOSING BRACKET
                    Analyzer tokenItem1("=",strToken,"8");
                    tokenList.push_back(tokenItem1);
                    strToken ="";
                    strToken += buffer;
                    Analyzer tokenItem("}",strToken,"7");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '$'){ // PESOS SIGN
                    Analyzer tokenItem1("=",strToken,"8");
                    tokenList.push_back(tokenItem1);
                    strToken ="";
                    strToken += buffer;
                    Analyzer tokenItem("$",strToken,"18");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '+' || buffer == '-'){ // ADD SUBSTRACT
                    Analyzer tokenItem1("=",strToken,"8");
                    tokenList.push_back(tokenItem1);
                    strToken ="";
                    strToken += buffer;
                    Analyzer tokenItem("OpSuma",strToken,"14");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '*' || buffer == '/'){ // MULT DIV
                    Analyzer tokenItem1("=",strToken,"8");
                    tokenList.push_back(tokenItem1);
                    strToken ="";
                    strToken += buffer;
                    Analyzer tokenItem("OpMultiplicacion",strToken,"16");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '|' || buffer == '&' ){
                    Analyzer tokenItem1("=",strToken,"8");
                    tokenList.push_back(tokenItem1);
                    strToken ="";
                    state = LOGIC;
                    strToken += buffer;
                }
                else if(buffer == '>' || buffer == '<'){
                    Analyzer tokenItem1("=",strToken,"8");
                    tokenList.push_back(tokenItem1);
                    strToken ="";
                    state = RELATIONAL;
                    strToken += buffer;
                }
                else if(buffer == '!'){
                    Analyzer tokenItem1("=",strToken,"8");
                    tokenList.push_back(tokenItem1);
                    strToken= "";
                    state = EXCLAMATION;
                    strToken += buffer;
                }
                else if(isalpha(buffer)){
                    Analyzer tokenItem("=",strToken,"8");
                    tokenList.push_back(tokenItem);
                    strToken ="";
                    state = RESERVED;
                    strToken += buffer;
                }
                else if(buffer == '_'){
                    Analyzer tokenItem("=",strToken,"8");
                    tokenList.push_back(tokenItem);
                    state = ID;
                    strToken="";
                    strToken += buffer;
                }
                else if(buffer == '@' || buffer == '?' || buffer == '\'' || buffer == '\"'
                        || buffer == '#' || buffer == '¿' || buffer == '%'){
                    Analyzer tokenItem1("=",strToken,"8");
                    tokenList.push_back(tokenItem1);
                    state = START;
                    strToken ="";
                    strToken += buffer;
                    Analyzer tokenItem("Error",strToken,"-1");
                    tokenList.push_back(tokenItem);
                    strToken ="";
                }
                else{// espacio, \t , \n ,lambda
                    Analyzer tokenItem("=",strToken,"8");
                    tokenList.push_back(tokenItem);
                    strToken = ""; // new
                    state = START;
                }
                break;

            case CONSTANTS:
                if(isdigit(buffer)){
                    state = CONSTANTS;
                    strToken += buffer;
                }
                else if((buffer == '.') && (!decimal)){
                    decimal = true;
                    state = CONSTANTS;
                    strToken += buffer;
                }
                else if(buffer == ';'){ // SEMICOLON
                    Analyzer tokenItem1("Constante",strToken,"13");
                    tokenList.push_back(tokenItem1);
                    strToken ="";
                    strToken += buffer;
                    Analyzer tokenItem(";",strToken,"2");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == ','){ // COMA
                    Analyzer tokenItem1("Constante",strToken,"13");
                    tokenList.push_back(tokenItem1);
                    strToken= "";
                    strToken += buffer;
                    Analyzer tokenItem(",",strToken,"3");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '('){// OPEN PARENTHESIS
                    Analyzer tokenItem1("Constante",strToken,"13");
                    tokenList.push_back(tokenItem1);
                    strToken= "";
                    strToken += buffer;
                    Analyzer tokenItem("(",strToken,"4");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == ')'){ // CLOSING PARENTHESIS"
                    Analyzer tokenItem1("Constante",strToken,"13");
                    tokenList.push_back(tokenItem1);
                    strToken= "";
                    strToken += buffer;
                    Analyzer tokenItem(")",strToken,"5");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '{'){ // OPEN BRACKET
                    Analyzer tokenItem1("Constante",strToken,"13");
                    tokenList.push_back(tokenItem1);
                    strToken= "";
                    strToken += buffer;
                    Analyzer tokenItem("{",strToken,"6");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '}'){ //CLOSING BRACKET
                    Analyzer tokenItem1("Constante",strToken,"13");
                    tokenList.push_back(tokenItem1);
                    strToken= "";
                    strToken += buffer;
                    Analyzer tokenItem("}",strToken,"7");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '='){
                    Analyzer tokenItem1("Constante",strToken,"13");
                    tokenList.push_back(tokenItem1);
                    state = EQUALS;
                    strToken += buffer;
                }
                else if(buffer == '$'){ // PESOS SIGN
                    Analyzer tokenItem1("Constante",strToken,"13");
                    tokenList.push_back(tokenItem1);
                    strToken= "";
                    strToken += buffer;
                    Analyzer tokenItem("$",strToken,"18");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '+' || buffer == '-'){ // ADD SUBSTRACT
                    Analyzer tokenItem1("Constante",strToken,"13");
                    tokenList.push_back(tokenItem1);
                    strToken= "";
                    strToken += buffer;
                    Analyzer tokenItem("OpSuma",strToken,"14");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '*' || buffer == '/'){ // MULT DIV
                    Analyzer tokenItem1("Constante",strToken,"13");
                    tokenList.push_back(tokenItem1);
                    strToken= "";
                    strToken += buffer;
                    Analyzer tokenItem("OpMultiplicacion",strToken,"16");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '|' || buffer == '&' ){
                    Analyzer tokenItem1("Constante",strToken,"13");
                    tokenList.push_back(tokenItem1);
                    strToken="";
                    state = LOGIC;
                    strToken += buffer;
                }
                else if(buffer == '>' || buffer == '<'){
                    Analyzer tokenItem1("Constante",strToken,"13");
                    tokenList.push_back(tokenItem1);
                    strToken = "";
                    state = RELATIONAL;
                    strToken += buffer;
                }
                else if(buffer == '!'){
                    Analyzer tokenItem1("Constante",strToken,"13");
                    tokenList.push_back(tokenItem1);
                    strToken = "";
                    state = EXCLAMATION;
                    strToken += buffer;
                }
                else if(isalpha(buffer)){
                    Analyzer tokenItem("Constante",strToken,"13");
                    tokenList.push_back(tokenItem);
                    strToken ="";
                    state = RESERVED;
                    strToken += buffer;
                }
                else if(buffer == '_'){
                    Analyzer tokenItem("Constante",strToken,"13");
                    tokenList.push_back(tokenItem);
                    state = ID;
                    strToken="";
                    strToken += buffer;
                }
                else if(buffer == '@' || buffer == '?' || buffer == '\'' || buffer == '\"'
                        || buffer == '#' || buffer == '¿' || buffer == '%'){
                    Analyzer tokenItem1("Constante",strToken,"13");
                    tokenList.push_back(tokenItem1);
                    state = START;
                    strToken ="";
                    strToken += buffer;
                    Analyzer tokenItem("Error",strToken,"-1");
                    tokenList.push_back(tokenItem);
                    strToken ="";
                }
                else{// espacio, \t , \n ,lambda
                    Analyzer tokenItem("Constante",strToken,"13");
                    tokenList.push_back(tokenItem);
                    strToken = ""; // new
                    state = START;
                }
                break;
            case LOGIC:
                if(buffer == '|' || buffer == '&'){
                    strToken+= buffer;
                    Analyzer tokenItem("OpLogico",strToken,"15");
                    tokenList.push_back(tokenItem);
                    strToken = ""; // new
                    state = START;
                }
                else if(buffer == ';'){ // SEMICOLON
                    Analyzer tokenItem1("OpLogico",strToken,"15");
                    tokenList.push_back(tokenItem1);
                    strToken ="";
                    strToken += buffer;
                    Analyzer tokenItem(";",strToken,"2");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == ','){ // COMA
                    Analyzer tokenItem1("OpLogico",strToken,"15");
                    tokenList.push_back(tokenItem1);
                    strToken ="";
                    strToken += buffer;
                    Analyzer tokenItem(",",strToken,"3");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '('){// OPEN PARENTHESIS
                    Analyzer tokenItem1("OpLogico",strToken,"15");
                    tokenList.push_back(tokenItem1);
                    strToken ="";
                    strToken += buffer;
                    Analyzer tokenItem("(",strToken,"4");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == ')'){ // CLOSING PARENTHESIS
                    Analyzer tokenItem1("OpLogico",strToken,"15");
                    tokenList.push_back(tokenItem1);
                    strToken ="";
                    strToken += buffer;
                    Analyzer tokenItem(")",strToken,"5");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '{'){ // OPEN BRACKET
                    Analyzer tokenItem1("OpLogico",strToken,"15");
                    tokenList.push_back(tokenItem1);
                    strToken ="";
                    strToken += buffer;
                    Analyzer tokenItem("{",strToken,"6");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '}'){ //CLOSING BRACKET
                    Analyzer tokenItem1("OpLogico",strToken,"15");
                    tokenList.push_back(tokenItem1);
                    strToken ="";
                    strToken += buffer;
                    Analyzer tokenItem("}",strToken,"7");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '='){
                    Analyzer tokenItem1("OpLogico",strToken,"15");
                    tokenList.push_back(tokenItem1);
                    state = EQUALS;
                    strToken ="";
                    strToken += buffer;
                }
                else if(buffer == '$'){ // PESOS SIGN
                    Analyzer tokenItem1("OpLogico",strToken,"15");
                    tokenList.push_back(tokenItem1);
                    strToken ="";
                    strToken += buffer;
                    Analyzer tokenItem("$",strToken,"18");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '+' || buffer == '-'){ // ADD SUBSTRACT
                    Analyzer tokenItem1("OpLogico",strToken,"15");
                    tokenList.push_back(tokenItem1);
                    strToken ="";
                    strToken += buffer;
                    Analyzer tokenItem("OpSuma",strToken,"14");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '*' || buffer == '/'){ // MULT DIV
                    Analyzer tokenItem1("OpLogico",strToken,"15");
                    tokenList.push_back(tokenItem1);
                    strToken ="";
                    strToken += buffer;
                    Analyzer tokenItem("OpMultiplicacion",strToken,"16");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '>' || buffer == '<'){
                    Analyzer tokenItem1("OpLogico",strToken,"15");
                    tokenList.push_back(tokenItem1);
                    strToken ="";
                    state = RELATIONAL;
                    strToken += buffer;
                }
                else if(buffer == '!'){
                    Analyzer tokenItem1("OpLogico",strToken,"15");
                    tokenList.push_back(tokenItem1);
                    strToken ="";
                    state = EXCLAMATION;
                    strToken += buffer;
                }

                else if(isalpha(buffer)){
                    Analyzer tokenItem("OpLogico",strToken,"15");
                    tokenList.push_back(tokenItem);
                    strToken ="";
                    state = RESERVED;
                    strToken += buffer;
                }
                else if(buffer == '_'){
                    Analyzer tokenItem("OpLogico",strToken,"15");
                    tokenList.push_back(tokenItem);
                    state = ID;
                    strToken="";
                    strToken += buffer;
                }
                else if(buffer == '@' || buffer == '?' || buffer == '\'' || buffer == '\"'
                        || buffer == '#' || buffer == '¿' || buffer == '%'){
                    Analyzer tokenItem1("OpLogico",strToken,"15");
                    tokenList.push_back(tokenItem1);
                    state = START;
                    strToken ="";
                    strToken += buffer;
                    Analyzer tokenItem("Error",strToken,"-1");
                    tokenList.push_back(tokenItem);
                    strToken ="";
                }
                else{// espacio, \t , \n ,lambda
                    Analyzer tokenItem("OpLogico",strToken,"15");
                    tokenList.push_back(tokenItem);
                    strToken = ""; // new
                    state = START;
                }
                break;
            case RELATIONAL:
                if(buffer == '='){
                    strToken+= buffer;
                    Analyzer tokenItem("OpRelacional",strToken,"17");
                    tokenList.push_back(tokenItem);
                    strToken = ""; // new
                    state = START;
                }
                else if(buffer == ';'){ // SEMICOLON
                    Analyzer tokenItem1("OpRelacional",strToken,"17");
                    tokenList.push_back(tokenItem1);
                    strToken ="";
                    strToken += buffer;
                    Analyzer tokenItem(";",strToken,"2");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == ','){ // COMA
                    Analyzer tokenItem1("OpRelacional",strToken,"17");
                    tokenList.push_back(tokenItem1);
                    strToken= "";
                    strToken += buffer;
                    Analyzer tokenItem(",",strToken,"3");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '('){// OPEN PARENTHESIS
                    Analyzer tokenItem1("OpRelacional",strToken,"17");
                    tokenList.push_back(tokenItem1);
                    strToken= "";
                    strToken += buffer;
                    Analyzer tokenItem("(",strToken,"4");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == ')'){ // CLOSING PARENTHESIS
                    Analyzer tokenItem1("OpRelacional",strToken,"17");
                    tokenList.push_back(tokenItem1);
                    strToken= "";
                    strToken += buffer;
                    Analyzer tokenItem(")",strToken,"5");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '{'){ // OPEN BRACKET
                    Analyzer tokenItem1("OpRelacional",strToken,"17");
                    tokenList.push_back(tokenItem1);
                    strToken= "";
                    strToken += buffer;
                    Analyzer tokenItem("{",strToken,"6");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '}'){ //CLOSING BRACKET
                    Analyzer tokenItem1("OpRelacional",strToken,"17");
                    tokenList.push_back(tokenItem1);
                    strToken= "";
                    strToken += buffer;
                    Analyzer tokenItem("}",strToken,"7");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '='){
                    Analyzer tokenItem1("OpRelacional",strToken,"17");
                    tokenList.push_back(tokenItem1);
                    state = EQUALS;
                    strToken += buffer;
                }
                else if(buffer == '$'){ // PESOS SIGN
                    Analyzer tokenItem1("OpRelacional",strToken,"17");
                    tokenList.push_back(tokenItem1);
                    strToken= "";
                    strToken += buffer;
                    Analyzer tokenItem("$",strToken,"18");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '+' || buffer == '-'){ // ADD SUBSTRACT
                    Analyzer tokenItem1("OpRelacional",strToken,"17");
                    tokenList.push_back(tokenItem1);
                    strToken= "";
                    strToken += buffer;
                    Analyzer tokenItem("OpSuma",strToken,"14");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '*' || buffer == '/'){ // MULT DIV
                    Analyzer tokenItem1("OpRelacional",strToken,"17");
                    tokenList.push_back(tokenItem1);
                    strToken= "";
                    strToken += buffer;
                    Analyzer tokenItem("OpMultiplicacion",strToken,"16");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '|' || buffer == '&' ){
                    Analyzer tokenItem1("OpRelacional",strToken,"17");
                    tokenList.push_back(tokenItem1);
                    state = LOGIC;
                    strToken += buffer;
                }
                else if(isalpha(buffer)){
                    Analyzer tokenItem1("OpRelacional",strToken,"17");
                    tokenList.push_back(tokenItem1);
                    strToken ="";
                    state = RESERVED;
                    strToken += buffer;
                }
                else if(buffer == '_'){
                    Analyzer tokenItem1("OpRelacional",strToken,"17");
                    tokenList.push_back(tokenItem1);
                    state = ID;
                    strToken="";
                    strToken += buffer;
                }
                else if(buffer == '@' || buffer == '?' || buffer == '\'' || buffer == '\"'
                        || buffer == '#' || buffer == '¿' || buffer == '%'){
                    Analyzer tokenItem1("OpRelacional",strToken,"17");
                    tokenList.push_back(tokenItem1);
                    state = START;
                    strToken ="";
                    strToken += buffer;
                    Analyzer tokenItem("Error",strToken,"-1");
                    tokenList.push_back(tokenItem);
                    strToken ="";
                }
                else{// espacio, \t , \n ,lambda
                    Analyzer tokenItem1("OpRelacional",strToken,"17");
                    tokenList.push_back(tokenItem1);
                    strToken = ""; // new
                    state = START;
                }
                break;
            case EXCLAMATION:
                if(buffer == '='){
                    strToken += buffer;
                    Analyzer tokenItem1("OpRelacional",strToken,"17");
                    tokenList.push_back(tokenItem1);
                    strToken = ""; // new
                    state = START;
                }
                else if(buffer == ';'){ // SEMICOLON
                    Analyzer tokenItem1("OpRelacional",strToken,"17");
                    tokenList.push_back(tokenItem1);
                    strToken ="";
                    strToken += buffer;
                    Analyzer tokenItem(";",strToken,"2");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == ','){ // COMA
                    Analyzer tokenItem1("OpRelacional",strToken,"17");
                    tokenList.push_back(tokenItem1);
                    strToken= "";
                    strToken += buffer;
                    Analyzer tokenItem(",",strToken,"3");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '('){// OPEN PARENTHESIS
                    Analyzer tokenItem1("OpRelacional",strToken,"17");
                    tokenList.push_back(tokenItem1);
                    strToken= "";
                    strToken += buffer;
                    Analyzer tokenItem("(",strToken,"4");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == ')'){ // CLOSING PARENTHESIS
                    Analyzer tokenItem1("OpRelacional",strToken,"17");
                    tokenList.push_back(tokenItem1);
                    strToken= "";
                    strToken += buffer;
                    Analyzer tokenItem(")",strToken,"5");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '{'){ // OPEN BRACKET
                    Analyzer tokenItem1("OpRelacional",strToken,"17");
                    tokenList.push_back(tokenItem1);
                    strToken= "";
                    strToken += buffer;
                    Analyzer tokenItem("{",strToken,"6");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '}'){ //CLOSING BRACKET
                    Analyzer tokenItem1("OpRelacional",strToken,"17");
                    tokenList.push_back(tokenItem1);
                    strToken= "";
                    strToken += buffer;
                    Analyzer tokenItem("}",strToken,"7");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '$'){ // PESOS SIGN
                    Analyzer tokenItem1("OpRelacional",strToken,"17");
                    tokenList.push_back(tokenItem1);
                    strToken= "";
                    strToken += buffer;
                    Analyzer tokenItem("$",strToken,"18");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '+' || buffer == '-'){ // ADD SUBSTRACT
                    Analyzer tokenItem1("OpRelacional",strToken,"17");
                    tokenList.push_back(tokenItem1);
                    strToken= "";
                    strToken += buffer;
                    Analyzer tokenItem("OpSuma",strToken,"14");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '*' || buffer == '/'){ // MULT DIV
                    Analyzer tokenItem1("OpRelacional",strToken,"17");
                    tokenList.push_back(tokenItem1);
                    strToken= "";
                    strToken += buffer;
                    Analyzer tokenItem("OpMultiplicacion",strToken,"16");
                    tokenList.push_back(tokenItem);
                    state = START;
                    strToken = ""; // new
                }
                else if(buffer == '|' || buffer == '&' ){
                    Analyzer tokenItem1("OpRelacional",strToken,"17");
                    tokenList.push_back(tokenItem1);
                    state = LOGIC;
                    strToken += buffer;
                }
                else if(isalpha(buffer)){
                    Analyzer tokenItem1("OpRelacional",strToken,"17");
                    tokenList.push_back(tokenItem1);
                    strToken ="";
                    state = RESERVED;
                    strToken += buffer;
                }
                else if(buffer == '_'){
                    Analyzer tokenItem1("OpRelacional",strToken,"17");
                    tokenList.push_back(tokenItem1);
                    state = ID;
                    strToken="";
                    strToken += buffer;
                }
                else if(buffer == '@' || buffer == '?' || buffer == '\'' || buffer == '\"'
                        || buffer == '#' || buffer == '¿' || buffer == '%'){
                    Analyzer tokenItem1("OpRelacional",strToken,"17");
                    tokenList.push_back(tokenItem1);
                    state = START;
                    strToken ="";
                    strToken += buffer;
                    Analyzer tokenItem("Error",strToken,"-1");
                    tokenList.push_back(tokenItem);
                    strToken ="";
                }
                else{// espacio, \t , \n ,lambda
                    Analyzer tokenItem("Error",strToken,"-1");
                    tokenList.push_back(tokenItem);
                    strToken = ""; // new
                    state = START;
                }
                break;
            default:
                cout << "Algo extraño ocurrió..." << endl;
        }
    }
    return tokenList;
}
