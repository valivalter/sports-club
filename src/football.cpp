/**
 * \file football.cpp
 *
 * Ez a fájl tartalmazza a Team egyik leszármazottjának, a Football osztálynak a nem inline függvényeinek definícióit.
 */

#include "football.h"
#include "team.h"

// Megadja, hogy az adott csapat milyen sportot űz
Sport Football::getsport() const {
    return sport;
}

// Lemásolja a csapatot egy dinamikusan foglalt területre és visszaadja az erre mutató pointert
Football* Football::clone() const {
    return new Football(*this);
}

// Kiírja a szabványos kimenetre a csapat adatait külön sorokba
void Football::print() const {
    std::cout << "Sport: football" << std::endl;
    Team::print();
    std::cout << "Assistant coach: " << assistant_coach << std::endl;
}

// Kiírja a szabványos kimenetre a csapat nevét
void Football::printnames() const {
    Team::printnames();
    std::cout << " (football)" << std::endl;
}

// Kiírja a csapat adatait külön sorokba, fájlba mentéshez lehet használni
void Football::write(std::ostream& os) const {
    os << "football" << std::endl;
    Team::write(os);
    os << assistant_coach << std::endl;
}

// Beolvassa egy csapat adatait, korábban elmentett belső állapot visszaállításához lehet használni
void Football::read(std::istream& is) {
    Team::read(is);
    is >> assistant_coach;
}
