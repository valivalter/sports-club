/**
 * \file string.cpp
 *
 * Ez a fájl tartalmazza a String osztály nem inline függvényeinek definícióit.
 */

#include <iostream>
#include <cstring>
#include <cctype>
#include "string.h"
#include "memtrace.h"

using std::cin;
using std::ios_base;

// Konstruktor egy karakterrel
String::String(char ch) {
    len = 1;
    pData = new char[len+1];
    pData[0] = ch;
    pData[1] = '\0';
}

// Konstruktor egy karakterre/karakterekre mutató pointerrel
String::String(const char *p) {
    len = strlen(p);
    pData = new char[len+1];
    strcpy(pData, p);
}

// Másoló konstruktor
String::String(const String& s) {
    len = s.len;
    pData = new char[len+1];
    strcpy(pData, s.pData);
}

// Értékadó operátor
String& String::operator=(const String& s) {
    if (this != &s) {
        delete[] pData;
        len = s.len;
        pData = new char[len+1];
        strcpy(pData, s.pData);
    }
    return *this;
}

// Indexelő operátor
char& String::operator[](unsigned int idx) {
    if (idx >= len)
        throw "String: indexelesi hiba";
    return pData[idx];
}

// Indexelő operátor konstans Stringhez
const char& String::operator[](unsigned int idx) const {
    if (idx >= len)
        throw "String: indexelesi hiba";
    return pData[idx];
}

// Két Stringet összefűz
String String::operator+(const String& s) const {
    String temp;
    temp.len = len + s.len;
    delete[] temp.pData;
    temp.pData = new char[temp.len+1];
    strcpy(temp.pData, pData);
    strcat(temp.pData, s.pData);
    return temp;

}

// String típust int típussá alakít
int String::String_to_int() {
    int value = 0;
    for (unsigned int i = 0; i < len; i++) {
        value = value*10 + (pData[i] - 48);
    }
    return value;
}

// Kiíró operátor, kiír egy Stringet
std::ostream& operator<<(std::ostream& os, const String& s) {
    os << s.c_str();
    return os;
}

// Beolvasó operátor, beolvas egy sort
std::istream& operator>>(std::istream& is, String& s) {
    unsigned char ch = '\0';
    s = String("");
	std::ios_base::fmtflags fl = is.flags();
	is.setf(ios_base::skipws);
	bool wrongcharacter = false;
    while (is >> ch) {
	    is.unsetf(ios_base::skipws);
        if (ch == '\n') {
            is.putback(ch);
            break;
        }
        //else if (ch == '\r') {
        //    is.ignore(256, '\n');
        //    break;
        //}
        else if (!isalpha(ch) && !isdigit(ch) && ch != ' ' && ch != '-' && ch != '.')
            wrongcharacter = true;
        else {
            s = s + ch;
        }
    }
	is.setf(fl);
	if (wrongcharacter)
        throw "At least one character is not allowed!";
    return is;
}

// Addig olvas be a szabványos bemenetről egy Stringet, amíg ez nem sikerül kivétel keletkezése nélkül
void getString(String& s) {
    bool valid = false;
    while (!valid) {
        try {
            std::cin >> s;
            valid = true;
        }
        catch (const char* p) {
            std::cout << p << std::endl;
        }
    }
}
