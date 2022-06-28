/**
 * \file string.h
 *
 * Ez a fájl tartalmazza a String osztály deklarációját és inline függvényeit.
 */

#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring>

/**
 * String osztály
 * A pData pointer mutat a karakterekre, a len pedig a karakterek számát adja meg lezáró nulla nélkül.
 */
class String {
    char *pData;        ///< pointer a karakterekre
    unsigned int len;   ///< a karakterek száma (lezáró nulla nélkül)
public:

    /// A String hosszát adja vissza (lezáró nulla nélkül)
    /// @return A String hossza (lezáró nulla nélkül)
	size_t size() const {
	    return len;
    }

    /// A karakterekre mutató pointert adja vissza
    /// @return A karakterekre mutató pointer
    const char* c_str() const {
        return pData;
    }

    /// Konstruktor egy karakterrel
    /// @param ch - a karakter
    explicit String(char ch);
    /// Konstruktor egy karakterre/karakterekre mutató pointerrel
    /// @param p - a karakterre/karakterekre mutató pointer
    String(const char *p = "");
    /// Másoló konstruktor
    /// @param s - a String, amit lemásol
    String(const String& s);
    /// Értékadó operátor
    /// @param s - a String, aminek az értékét adja a baloldali operandusnak
    /// @return A baloldali új értékkel rendelkező String referenciája
    String& operator=(const String& s);

    /// Destruktor
    ~String() {
        delete[] pData;
    }

    /// Két Stringet összefűz
    /// @param s - a jobboldali String
    /// @return Az összefűzött új String
    String operator+(const String& s) const;

    /// Stringhez karaktert fűz
    /// @param c - a hozzáfűzendő karakter
    /// @return Az összefűzött új String
    String operator+(char c) const {
        return *this + String(c);
    }

    /// Igazat ad vissza, ha a baloldali String kisebb mint a jobboldali
    /// @param rhs - a jobboldali String
    /// @return Logikai igaz vagy hamis
    bool operator<(const String& rhs) {
        return strcmp((*this).c_str(), rhs.c_str()) < 0;
    }
    /// Igazat ad vissza, ha a baloldali String nagyobb mint a jobboldali
    /// @param rhs - a jobboldali String
    /// @return Logikai igaz vagy hamis
    bool operator>(const String& rhs) {
        return strcmp((*this).c_str(), rhs.c_str()) > 0;
    }
    /// Igazat ad vissza, ha a baloldali String megegyezik a jobboldalival
    /// @param rhs - a jobboldali String
    /// @return Logikai igaz vagy hamis
    bool operator==(const String& rhs) {
        return strcmp((*this).c_str(), rhs.c_str()) == 0;
    }
    /// Igazat ad vissza, ha a baloldali String nem egyezik meg jobboldalival
    /// @param rhs - a jobboldali String
    /// @return Logikai igaz vagy hamis
    bool operator!=(const String& rhs) {
        return strcmp((*this).c_str(), rhs.c_str()) != 0;
    }
    /// Igazat ad vissza, ha a baloldali String kisebb vagy egyenlő mint a jobboldali
    /// @param rhs - a jobboldali String
    /// @return Logikai igaz vagy hamis
    bool operator<=(const String& rhs) {
        return strcmp((*this).c_str(), rhs.c_str()) <= 0;
    }
    /// Igazat ad vissza, ha a baloldali String nagyobb vagy egyenlő mint a jobboldali
    /// @param rhs - a jobboldali String
    /// @return Logikai igaz vagy hamis
    bool operator>=(const String& rhs) {
        return strcmp((*this).c_str(), rhs.c_str()) >= 0;
    }

    /// Indexelő operátor
    /// Indexelési hiba esetén kivételt dob
    /// @param idx - a karakter indexe
    /// @return A megfelelő indexű karakter referenciája
    char& operator[](unsigned int idx);
    /// Indexelő operátor konstans Stringhez
    /// Indexelési hiba esetén kivételt dob
    /// @param idx - a karakter indexe
    /// @return A megfelelő indexű karakter konstans referenciája
    const char& operator[](unsigned int idx) const;

    /// String típust int típussá alakít
    /// @return A String értéke int típusként
    int String_to_int();
};

/// Kiíró operátor, kiír egy Stringet
/// @param os - ostream típus, ahova a Stringet kiírja
/// @param s - a String, amit kiír
/// @return Az ostream típus referenciája
std::ostream& operator<<(std::ostream& os, const String& s);
/// Beolvasó operátor, beolvas egy sort
/// Kivételt dob, ha a sorban van tiltott karakter (nem az angol ábécében lévő betű, vagy a számjegyeken, a szóközön,
/// a ponton, vagy a kötőjelen kívül egyéb karakter)
/// @param is - istream típus, ahonnan a sort beolvassa
/// @param s - a String, amibe beolvassa a sort
/// @return Az istream típus referenciája
std::istream& operator>>(std::istream& is, String& s);

/// Addig olvas be a szabványos bemenetről egy Stringet, amíg ez nem sikerül kivétel keletkezése nélkül
/// @param s - a String, amibe beolvas a szabványos bemenetről
void getString(String& s);

#endif
