//
// Created by teich on 15/06/2022.
//

#include <exception>
#include <string>
using std::string;

#ifndef MTMCHKIN_CPP_EXCEPTION_H
#define MTMCHKIN_CPP_EXCEPTION_H

class Exception : public std::exception{};

class DeckFileNotFound : public Exception{
    const char* what() const noexcept override {return "Deck File Error: File not found\n";}
};

class DeckFileFormatError : public Exception {
private:
    string m_numOfLine;
public:
    DeckFileFormatError(string& numOfLine) :
            m_numOfLine(numOfLine) {}
    //const char *what() const noexcept override {
       // string s = "Deck File Error: File format error in line " + m_numOfLine + "\n";
        //return s.c_str();
    };
//};

class DeckFileInvalidSize : public Exception{
    const char* what() const noexcept override {return "Deck File Error: Deck size is invalid\n";}
};


#endif //MTMCHKIN_CPP_EXCEPTION_H