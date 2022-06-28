/**
 * \file handball.cpp
 *
 * Ez a fájl tartalmazza a Team egyik leszármazottjának, a Handball osztálynak a nem inline függvényeinek definícióit.
 */

#include "handball.h"
#include "team.h"

// Megadja, hogy az adott csapat milyen sportot űz
Sport Handball::getsport() const {
    return sport;
}

// Lemásolja a csapatot egy dinamikusan foglalt területre és visszaadja az erre mutató pointert
Handball* Handball::clone() const {
    return new Handball(*this);
}

// Kiírja a szabványos kimenetre a csapat adatait külön sorokba
void Handball::print() const {
    std::cout << "Sport: handball" << std::endl;
    Team::print();
    std::cout << "Amount of support this year: " << support << " Ft" << std::endl;
}

// Kiírja a szabványos kimenetre a csapat nevét
void Handball::printnames() const {
    Team::printnames();
    std::cout << " (handball)" << std::endl;
}

// Kiírja a csapat adatait külön sorokba, fájlba mentéshez lehet használni
void Handball::write(std::ostream& os) const {
    os << "handball" << std::endl;
    Team::write(os);
    os << support << std::endl;
}

// Beolvassa egy csapat adatait, korábban elmentett belső állapot visszaállításához lehet használni
void Handball::read(std::istream& is) {
    Team::read(is);
    is >> support;
}
