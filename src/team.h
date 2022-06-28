/**
 * \file team.h
 *
 * Ez a fájl tartalmazza a Team osztály, valamint a Sport nevű felsorolás deklarációját.
 */

#ifndef TEAM_H_INCLUDED
#define TEAM_H_INCLUDED

#include "string.h"

/**
 * Sport nevű felsorolás típus, értéke lehet football, basketball, vagy handball.
 */
enum Sport {
    football, basketball, handball
};

/**
 * Team absztrakt osztály, a sportcsapatok általános jellemzőit tárolja.
 * A name adattag a sportcsapat neve, a coach adattag a csapat edzőjének a neve,
 * a members adattag pedig a csapat tagjainak száma.
 */
class Team {
protected:
    String name;        ///< a sportcsapat neve
    String coach;       ///< a sportcsapat edzőjének neve
    int members;        ///< a sportcsapat tagjainak száma

public:
    /// Konstruktor a csapat nevével, edzőjével, és létszámával
    /// @param name - a csapat neve
    /// @param coach - az edző neve
    /// @param members - a csapattagok száma
    explicit Team(const String& name = "", const String& coach = "", int members = 0)
        : name(name), coach(coach), members(members) {}

    /// Virtuális destruktor
    virtual ~Team() {}

    /// Megadja, hogy az adott csapat milyen sportot űz
    /// @return Sport típus a csapat sportágának megfelelő értékkel
    virtual Sport getsport() const = 0;

    /// Lemásolja a csapatot egy dinamikusan foglalt területre és visszaadja az erre mutató pointert
    /// @return Az újonnan lefoglalt területen lévő másolatra mutató pointer
    virtual Team* clone() const = 0;

    /// Kiírja a szabványos kimenetre a csapat adatait külön sorokba
    virtual void print() const;
    /// Kiírja a szabványos kimenetre a csapat nevét
    virtual void printnames() const;
    /// Kiírja a csapat adatait külön sorokba, fájlba mentéshez lehet használni
    /// @param os - ostream típusú objektum, ide írja az adatokat
    virtual void write(std::ostream& os) const;
    /// Beolvassa egy csapat adatait, korábban elmentett belső állapot visszaállításához lehet használni
    /// @param is - istream típusú objektum, innen olvassa be az adatokat
    virtual void read(std::istream& is);
};

#endif // TEAM_H_INCLUDED
