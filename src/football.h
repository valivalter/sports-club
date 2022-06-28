/**
 * \file football.h
 *
 * Ez a fájl tartalmazza a Team egyik leszármazottjának, a Football osztálynak a deklarációját és inline függvényeit.
 */

#ifndef FOOTBALL_H_INCLUDED
#define FOOTBALL_H_INCLUDED

#include "team.h"

/**
 * Football osztály, a Team osztály leszármazottja.
 * Az assistant_coach adattag a csapat másodedzőjének nevét tárolja,
 * a sport adattag pedig a Sport típusnak a csapat által űzött sportágnak megfelelő értékét.
 */
class Football : public Team {
    String assistant_coach;                     ///< a csapat másodedzőjének neve
    static const Sport sport = football;        ///< a csapat által űzött sportág

public:
    /// Konstruktor a csapat nevével, edzőjével, létszámával, és a másodedzőjének nevével
    /// @param name - a csapat neve
    /// @param coach - az edző neve
    /// @param members - a csapattagok száma
    /// @param assistant_coach - a másodedző neve
    explicit Football(const String& name = "", const String& coach = "", int members = 0, const String& assistant_coach = "")
        : Team(name, coach, members), assistant_coach(assistant_coach) {}

    /// Megadja, hogy az adott csapat milyen sportot űz
    /// @return Sport típus a csapat sportágának megfelelő értékkel
    Sport getsport() const;

    /// Lemásolja a csapatot egy dinamikusan foglalt területre és visszaadja az erre mutató pointert
    /// @return Az újonnan lefoglalt területen lévő másolatra mutató pointer
    Football* clone() const;

    /// Kiírja a szabványos kimenetre a csapat adatait külön sorokba
    void print() const;
    /// Kiírja a szabványos kimenetre a csapat nevét
    void printnames() const;
    /// Kiírja a csapat adatait külön sorokba, fájlba mentéshez lehet használni
    /// @param os - ostream típusú objektum, ide írja az adatokat
    void write(std::ostream& os) const;
    /// Beolvassa egy csapat adatait, korábban elmentett belső állapot visszaállításához lehet használni
    /// @param is - istream típusú objektum, innen olvassa be az adatokat
    void read(std::istream& is);
};

#endif // FOOTBALL_H_INCLUDED
