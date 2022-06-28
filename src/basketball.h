/**
 * \file basketball.h
 *
 * Ez a fájl tartalmazza a Team egyik leszármazottjának, a Basketball osztálynak a deklarációját és inline függvényeit.
 */

#ifndef BASKETBALL_H_INCLUDED
#define BASKETBALL_H_INCLUDED

#include "team.h"

/**
 * Basketball osztály, a Team osztály leszármazottja.
 * A cheerleaders adattag a csapatban lévő pomponlányok számát tárolja,
 * a sport adattag pedig a Sport típusnak a csapat által űzött sportágnak megfelelő értékét.
 */
class Basketball : public Team {
    int cheerleaders;                           ///< a csapatban lévő pomponlányok száma
    static const Sport sport = basketball;      ///< a csapat által űzött sportág

public:
    /// Konstruktor a csapat nevével, edzőjével, létszámával, és a pomponlányok számával
    /// @param name - a csapat neve
    /// @param coach - az edző neve
    /// @param members - a csapattagok száma
    /// @param cheerleaders - a pomponlányok száma
    explicit Basketball(const String& name = "", const String& coach = "", int members = 0, int cheerleaders = 0)
        : Team(name, coach, members), cheerleaders(cheerleaders) {}

    /// Megadja, hogy az adott csapat milyen sportot űz
    /// @return Sport típus a csapat sportágának megfelelő értékkel
    Sport getsport() const;

    /// Lemásolja a csapatot egy dinamikusan foglalt területre és visszaadja az erre mutató pointert
    /// @return Az újonnan lefoglalt területen lévő másolatra mutató pointer
    Basketball* clone() const;

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

#endif // BASKETBALL_H_INCLUDED
