#include "automatum.h"

using namespace std;

enum{ START, ID, RESERVED, SEMICOLON, COMA, OPARENTHESIS, CPARENTHESIS, OBRACKET, CBRACKET,
      EQUALS, OR, AND, ADD_SUBS, MULT_DIV, PESOS_SIGN, GREATHER, LOWER, EXCLAMATION, CONSTANTS

};

Automatum::Automatum(){}

list<Analyzer> Automatum::automata(std::string text){
    text +=" ";
    short state = 0;
    char buffer;
    string strToken;
    bool decimal = false;
    list<Analyzer> tokenList;
    int textSize = text.size();

    cout << "Text size: " << textSize << endl;
    for(unsigned int i=0 ;i < textSize; i++){
        buffer = text[i];
        //Automatum
        switch(state){
            case START:
                cout << "estado 0" << endl;
                //cout << "i: " << i << endl;
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
                else{// espacio, \t , \n ,lambda
                    //stays here
                    state = 0;
                }
                break;
            case ID:// Identificador  = hola2
                cout << "estado 1" << endl;
                if(isalnum(buffer)){
                    state = ID;
                    strToken += buffer;
                    if(i == textSize - 2){ // end of input
                        state = START;
                        Analyzer tokenItem("Identificador",strToken,1);
                        tokenList.push_back(tokenItem);
                    }

                }
                else if( buffer == ';'){
                    state = SEMICOLON;
                    strToken+=buffer;
                }
                else{// espacio, \t , \n ,lambda
                    Analyzer tokenItem("Identificador",strToken,1);
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
                        Analyzer tokenItem("While",strToken,10);
                        tokenList.push_back(tokenItem);
                        strToken = ""; // new
                        state = 0;
                    }
                    else if(strToken == "if"){
                        cout << "Token: " << strToken << endl;
                        Analyzer tokenItem("If",strToken,9);
                        tokenList.push_back(tokenItem);
                        strToken = ""; // new
                        state = 0;
                    }
                    else if(strToken == "else"){
                        cout << "Token: " << strToken << endl;
                        Analyzer tokenItem("Else",strToken,12);
                        tokenList.push_back(tokenItem);
                        strToken = ""; // new
                        state = 0;
                    }
                    else if(strToken == "return"){
                        cout << "Token: " << strToken << endl;
                        Analyzer tokenItem("Return",strToken,11);
                        tokenList.push_back(tokenItem);
                        strToken = ""; // new
                        state = 0;
                    }
                    else if(strToken == "int"  || strToken == "float" || strToken == "char"
                                || strToken == "void"){
                        cout << "Token: " << strToken << endl;
                        Analyzer tokenItem("Tipo dato",strToken,0);
                        tokenList.push_back(tokenItem);
                        strToken = ""; // new
                        state = 0;
                    }
                }
                else if(isdigit(buffer)){
                    state = ID;
                    strToken += buffer;
                    //cout << "strToken en state 2: " << strToken << endl;
                    //cout << "i: " << i << endl;
                    if(i == textSize - 2){ // end of input
                        state = START;
                        cout << "pos si entro aqui " << endl;
                        Analyzer tokenItem("Identificador",strToken,1);
                        tokenList.push_back(tokenItem);
                    }
                }
                else{// espacio, \t , \n ,lambda
                    state = RESERVED;
                    //strToken += buffer;
                    if(strToken == "while"){
                        cout << "Token: " << strToken << endl;\
                        Analyzer tokenItem("While",strToken,10);
                        tokenList.push_back(tokenItem);
                        strToken = ""; // new
                        state = 0;
                    }
                    else if(strToken == "if"){
                        cout << "Token: " << strToken << endl;
                        Analyzer tokenItem("If",strToken,9);
                        tokenList.push_back(tokenItem);
                        strToken = ""; // new
                        state = 0;
                    }
                    else if(strToken == "else"){
                        cout << "Token: " << strToken << endl;
                        Analyzer tokenItem("Else",strToken,12);
                        tokenList.push_back(tokenItem);
                        strToken = ""; // new
                        state = 0;
                    }
                    else if(strToken == "return"){
                        cout << "Token: " << strToken << endl;
                        Analyzer tokenItem("Return",strToken,11);
                        tokenList.push_back(tokenItem);
                        strToken = ""; // new
                        state = 0;
                    }
                    else if(strToken == "int"  || strToken == "float" || strToken == "char"
                                || strToken == "void"){
                        cout << "Token: " << strToken << endl;
                        Analyzer tokenItem("Tipo dato",strToken,0);
                        tokenList.push_back(tokenItem);
                        strToken = ""; // new
                        state = 0;
                    }
                    else{
                        Analyzer tokenItem("Identificador",strToken,1);
                        tokenList.push_back(tokenItem);
                        strToken = ""; // new
                        state = START;
                    }
                }
                break;
            case SEMICOLON:
                cout << "punto y coma wey v: " << endl;
                break;
            case 30:
                if(isdigit(buffer)){
                    state = 30;
                    strToken += buffer;
                }
                else if((buffer == '.') && (!decimal)){
                    decimal = true;
                    state = 30;
                    strToken += buffer;
                }
                else if(buffer == ' '){ // acepted
                    state = 0;
                    cout << "Token : " << strToken << endl;
                    strToken = "";
                }
                break;

             default:
                cout << "Algo extraño ocurrió..." << endl;
        }
    }
    return tokenList;
}
