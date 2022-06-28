/**
 * \file menu.h
 *
 * Ez a fájl tartalmazza a Menu osztály deklarációját és inline függvényeit.
 */

#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "string.h"

/**
 * Menu osztály a felhasználói felület megvalósításához.
 * A maxnumber adattag határozza meg a menük maximális számát, az options tömb
 * tárolja a menüpontok neveit String típusként, a numberofoptions adattag pedig a
 * menüpontok aktuális számát tartja nyilván.
 */
class Menu {
    static const int maxnumber = 10;    ///< a menüpontok maximális száma
    String options[maxnumber];          ///< a menüpontok neveit tartalmazó tömb
    int numberofoptions;                ///< a menüpontok aktuális száma

public:
    /// Konstruktor egy Stringeket tartalmazó tömbbel és a tömb elemszámával
    /// @param array - a menüpontok neveit tartalmazó tömbre mutató pointer
    /// @param numberofoptions - az adott tömb elemszáma
    explicit Menu(const String* array = 0, int numberofoptions = 0) : numberofoptions(numberofoptions) {
        for (int i = 0; i < numberofoptions; i++)
            options[i] = array[i];
    }

    /// Kiírja a szabványos kimenetre a menüpontokat egymás alá, mindegyik elé kiírva a sorszámát is
    void print() {
        std::cout << std::endl << "############################" << std::endl << std::endl;
        for (int i = 0; i < numberofoptions; i++) {
            std::cout << i+1 << ". " << options[i] << std::endl;
        }
        std::cout << std::endl;
    }
};

#endif // MENU_H_INCLUDED
