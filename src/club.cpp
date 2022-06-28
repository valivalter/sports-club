/**
 * \file club.cpp
 *
 * Ez a fájl tartalmazza a Club osztály nem inline függvényeinek definícióit.
 */

#include <cstring>
#include "club.h"
#include "dynamichetero.hpp"
#include "string.h"
#include "team.h"
#include "football.h"
#include "basketball.h"
#include "handball.h"

// Törli az objektumban lévő összes csapatot
void Club::delete_teams() {
    teams.delete_data();
}

// Indexelő operátor
Team*& Club::operator[](int i) {
    return teams[i];
}

// Indexelő operátor konstans objektumhoz
Team* Club::operator[](int i) const {
    return teams[i];
}

// A meglévő csapatok számát adja vissza
int Club::size() const {
    return teams.getsize();
}

// Hozzáad egy új csapatot az objektumhoz
void Club::push(Team* team) {
    teams.push(team);
}

// Kitörli a megfelelő indexű csapatot az objektumból
void Club::pop(int i) {
    teams.pop(i);
}

// Kiírja a szabványos kimenetre az objektumban lévő összes csapatot a jellemzőikkel együtt
void Club::list() const {
    for (int i = 0; i < teams.getsize(); i++) {
        std::cout << i+1 << "." << std::endl;
        teams[i]->print();
        std::cout << std::endl;
    }
}

// Kiírja a szabványos kimenetre az objektumban lévő összes csapatot a jellemzőikkel együtt, amik az adott sportágat űzik
void Club::list(Sport sport) const {
    int k = 1;
    for (DynamicHetero<Team>::iterator i = teams.begin(); i != teams.end(); ++i) {
        if ((*i)->getsport() == sport) {
            std::cout << k << "." << std::endl;
            (*i)->print();
            std::cout << std::endl;
            k++;
        }
    }
}

// Kiírja a szabványos kimenetre az objektumban lévő összes csapat nevét
void Club::listnames() const {
    for (int i = 0; i < teams.getsize(); i++) {
        std::cout << i+1 << ". ";
        teams[i]->printnames();
    }
}

// Kiírja az objektumban lévő összes csapatot a jellemzőikkel együtt külön sorokba
// Az objektum belső állapotának (például fájlba) elmentéséhez lehet használni
void Club::write(std::ostream& os) const {
    for (int i = 0; i < teams.getsize(); i++)
        teams[i]->write(os);
}

// Beolvassa az objektumba egy másik (vagy akár ugyanazon) objektum elmentett belső állapotát
void Club::read(std::istream& is) {
    String sport;
    while (is >> sport) {
        if (strcmp(sport.c_str(), "football") == 0) {
            Football f;
            f.read(is);
            push(f.clone());
        }
        else if (strcmp(sport.c_str(), "basketball") == 0) {
            Basketball b;
            b.read(is);
            push(b.clone());
        }
        else if (strcmp(sport.c_str(), "handball") == 0) {
            Handball h;
            h.read(is);
            push(h.clone());
        }
    }
}
