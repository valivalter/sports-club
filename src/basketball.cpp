/**
 * \file basketball.cpp
 *
 * Ez a fájl tartalmazza a Team egyik leszármazottjának, a Basketball osztálynak a nem inline függvényeinek definícióit.
 */

#include "basketball.h"
#include "team.h"

// Megadja, hogy az adott csapat milyen sportot űz
Sport Basketball::getsport() const {
    return sport;
}

// Lemásolja a csapatot egy dinamikusan foglalt területre és visszaadja az erre mutató pointert
Basketball* Basketball::clone() const {
    return new Basketball(*this);
}

// Kiírja a szabványos kimenetre a csapat adatait külön sorokba
void Basketball::print() const {
    std::cout << "Sport: basketball" << std::endl;
    Team::print();
    std::cout << "Cheerleaders: " << cheerleaders << std::endl;
}

// Kiírja a szabványos kimenetre a csapat nevét
void Basketball::printnames() const {
    Team::printnames();
    std::cout << " (basketball)" << std::endl;
}

// Kiírja a csapat adatait külön sorokba, fájlba mentéshez lehet használni
void Basketball::write(std::ostream& os) const {
    os << "basketball" << std::endl;
    Team::write(os);
    os << cheerleaders << std::endl;
}

// Beolvassa egy csapat adatait, korábban elmentett belső állapot visszaállításához lehet használni
void Basketball::read(std::istream& is) {
    Team::read(is);
    is >> cheerleaders;
}
