/**
 * \file team.cpp
 *
 * Ez a fájl tartalmazza a Club osztály nem inline függvényeinek definícióit.
 */

#include "team.h"
#include "string.h"

// Kiírja a szabványos kimenetre a csapat adatait külön sorokba
void Team::print() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Coach: " << coach << std::endl;
    std::cout << "Team members: " << members << std::endl;
}

// Kiírja a szabványos kimenetre a csapat nevét
void Team::printnames() const {
    std::cout << name;
}

// Kiírja a csapat adatait külön sorokba, fájlba mentéshez lehet használni
void Team::write(std::ostream& os) const {
    os << name << std::endl << coach << std::endl << members << std::endl;
}

// Beolvassa egy csapat adatait, korábban elmentett belső állapot visszaállításához lehet használni
void Team::read(std::istream& is) {
    is >> name >> coach;
    is >> members;
}
