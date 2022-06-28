/**
 * \file handball.h
 *
 * Ez a fájl tartalmazza a Team egyik leszármazottjának, a Handball osztálynak a deklarációját és inline függvényeit.
 */

#ifndef HANDBALL_H_INCLUDED
#define HANDBALL_H_INCLUDED

#include "team.h"

/**
 * Handball osztály, a Team osztály leszármazottja.
 * A support adattag az évente kapott támogatás összegét tartalmazza forintban,
 * a sport adattag pedig a Sport típusnak a csapat által űzött sportágnak megfelelő értékét.
 */
class Handball : public Team {
    int support;                            ///< az évente kapott támogatás összege forintban
    static const Sport sport = handball;    ///< a csapat által űzött sportág

public:
    /// Konstruktor a csapat nevével, edzőjével, létszámával, és a kapott támogatás értékével
    /// @param name - a csapat neve
    /// @param coach - az edző neve
    /// @param members - a csapattagok száma
    /// @param support - az évente kapott támogatás összege forintban
    explicit Handball(const String& name = "", const String& coach = "", int members = 0, int support = 0)
        : Team(name, coach, members), support(support) {}

    /// Megadja, hogy az adott csapat milyen sportot űz
    /// @return Sport típus a csapat sportágának megfelelő értékkel
    Sport getsport() const;

    /// Lemásolja a csapatot egy dinamikusan foglalt területre és visszaadja az erre mutató pointert
    /// @return Az újonnan lefoglalt területen lévő másolatra mutató pointer
    Handball* clone() const;

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

#endif // HANDBALL_H_INCLUDED
