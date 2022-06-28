/**
 * \file menu.h
 *
 * Ez a f�jl tartalmazza a Menu oszt�ly deklar�ci�j�t �s inline f�ggv�nyeit.
 */

#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "string.h"

/**
 * Menu oszt�ly a felhaszn�l�i fel�let megval�s�t�s�hoz.
 * A maxnumber adattag hat�rozza meg a men�k maxim�lis sz�m�t, az options t�mb
 * t�rolja a men�pontok neveit String t�pusk�nt, a numberofoptions adattag pedig a
 * men�pontok aktu�lis sz�m�t tartja nyilv�n.
 */
class Menu {
    static const int maxnumber = 10;    ///< a men�pontok maxim�lis sz�ma
    String options[maxnumber];          ///< a men�pontok neveit tartalmaz� t�mb
    int numberofoptions;                ///< a men�pontok aktu�lis sz�ma

public:
    /// Konstruktor egy Stringeket tartalmaz� t�mbbel �s a t�mb elemsz�m�val
    /// @param array - a men�pontok neveit tartalmaz� t�mbre mutat� pointer
    /// @param numberofoptions - az adott t�mb elemsz�ma
    explicit Menu(const String* array = 0, int numberofoptions = 0) : numberofoptions(numberofoptions) {
        for (int i = 0; i < numberofoptions; i++)
            options[i] = array[i];
    }

    /// Ki�rja a szabv�nyos kimenetre a men�pontokat egym�s al�, mindegyik el� ki�rva a sorsz�m�t is
    void print() {
        std::cout << std::endl << "############################" << std::endl << std::endl;
        for (int i = 0; i < numberofoptions; i++) {
            std::cout << i+1 << ". " << options[i] << std::endl;
        }
        std::cout << std::endl;
    }
};

#endif // MENU_H_INCLUDED
