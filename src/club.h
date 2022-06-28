/**
 * \file club.h
 *
 * Ez a fájl tartalmazza a Club osztály deklarációját és inline függvényeit.
 */

#ifndef CLUB_H_INCLUDED
#define CLUB_H_INCLUDED

#include "dynamichetero.hpp"
#include "team.h"

/**
 * Club osztály, amivel a különböző sportágakat űző csapatokat lehet tárolni.
 * A teams adattag tárolja az összes csapatot és a jellemzőiket.
 */
class Club {
    DynamicHetero<Team> teams; ///< tárolja az összes csapatot és a jellemzőiket

public:

    /// Törli az objektumban lévő összes csapatot
    void delete_teams();

    /// Indexelő operátor
    /// @param i - a csapat indexe
    /// @return A megfelelő indexű csapatra mutató pointer referenciája
    Team*& operator[](int i);
    /// Indexelő operátor konstans objektumhoz
    /// @param i - a csapat indexe
    /// @return A megfelelő indexű csapatra mutató pointer
    Team* operator[](int i) const;

    /// A meglévő csapatok számát adja vissza
    /// @return A meglévő csapatok száma
    int size() const;

    /// Hozzáad egy új csapatot az objektumhoz
    /// A pointernek dinamikusan foglaltnak kell lennie
    /// @param team - pointer, ami a hozzáadni a kívánt csapatra mutat
    void push(Team* team);
    /// Kitörli a megfelelő indexű csapatot az objektumból
    /// @param i - a törölni kívánt csapat indexe
    void pop(int i);

    /// Kiírja a szabványos kimenetre az objektumban lévő összes csapatot a jellemzőikkel együtt
    void list() const;
    /// Kiírja a szabványos kimenetre az objektumban lévő összes csapatot a jellemzőikkel együtt, amik az adott sportágat űzik
    /// @param sport - Sport típus, az ezt a sportot űző csapatokat írja ki a függvény
    void list(Sport sport) const;
    /// Kiírja a szabványos kimenetre az objektumban lévő összes csapat nevét
    void listnames() const;

    /// Kiírja az objektumban lévő összes csapatot a jellemzőikkel együtt külön sorokba
    /// Az objektum belső állapotának (például fájlba) elmentéséhez lehet használni
    /// @param os - ostream típusú objektum, ide írja ki az adatokat
    void write(std::ostream& os) const;
    /// Beolvassa az objektumba egy másik (vagy akár ugyanazon) objektum elmentett belső állapotát
    /// @param is - istream típusú objektum, innen olvassa be az adatokat
    void read(std::istream& is);

};

#endif // CLUB_H_INCLUDED
