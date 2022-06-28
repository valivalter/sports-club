/**
 * \file main.cpp
 *
 * Ez a fájl tartalmazza a főprogramot és néhány, a felhasználói felülethez szükséges függvényt.
 */

#include <iostream>
#include <fstream>
#include <cctype>
#include "football.h"
#include "basketball.h"
#include "handball.h"
#include "club.h"
#include "menu.h"
#include "memtrace.h"

/// Addig olvas be a szabványos bemenetről, amíg nem a megadott tartományon belüli számot kap
/// @param any - ha logikai igaz, akkor tetszőleges számot elfogad a függvény
/// @param min - legalább ekkorának kell lennie a beolvasott számnak
/// @param max - legfeljebb ekkora lehet a beolvasott szám
/// @return A kritériumnak megfelelő beolvasott szám
int inputnumber(bool any, int min = 0, int max = 0) {
    String s("");
    bool isnumber = false;
    while (!isnumber) {
        try {
            std::cin >> s;
            unsigned int db = 0;
            for (unsigned int i = 0; i < s.size(); i++) {
                if (isdigit(s[i]))
                    db++;
            }
            if (db != s.size()) {
                if (any)
                    std::cout << "Input must be a number!" << std::endl;
                else
                    std::cout << "Input must be a number between " << min << " and " << max << "!" << std::endl;
            }
            else if (any)
                isnumber = true;
            else if (!any) {
                if (s.String_to_int() < min || s.String_to_int() > max)
                    std::cout << "Input must be a number between " << min << " and " << max << "!" << std::endl;
                else
                    isnumber = true;
            }
        }
        catch (const char* p) {
            std::cout << p << std::endl;
        }
    }
    return s.String_to_int();
}

/// Kiírja a szabványos kimenetre, hogy "Enter 1 to return", majd addig olvas be a szabványos bemenetről, amíg nem kap 1-et
/// Amíg ez nem teljesül, ismételten kiírja, hogy "Enter 1 to return"
void return_to_main() {
    std::cout << "Enter 1 to return" << std::endl;
    String s("");
    while (s != String('1')) {
        try {
            std::cin >> s;
        }
        catch (const char* p) {
            std::cout << p << std::endl;
        }
        if (s != String('1'))
            std::cout << "Enter 1 to return" << std::endl;
    }
}

int main() {

    Club bme;

    Football* mun = new Football("Manchester United FC", "Ole Gunnar Solskjaer", 37, "Mike Phelan");
    Basketball* utah = new Basketball("Utah Jazz", "Quin Snyder", 26, 15);
    Handball* vardar = new Handball("RK Vardar", "Stevce Alusevski", 26, 1500000);

    bme.push(mun);
    bme.push(utah);
    bme.push(vardar);

    String main_options[7] = {"Add new team", "Delete existing team", "List teams", "Export teams", "Import teams", "Delete every team", "Quit"};
    Menu main_menu(main_options, 7);

    String sports_options[3] = {"Football", "Basketball", "Handball"};
    Menu sports_menu(sports_options, 3);

    String list_options[4] = {"Only football teams", "Only basketball teams", "Only handball teams", "All teams"};
    Menu list_menu(list_options, 4);

    int selectedmenu = 0;
    while (selectedmenu != 7) {
        main_menu.print();
        selectedmenu = inputnumber(false, 1, 7);
        if (selectedmenu == 1) {
            std::cout << "Name: ";
            String name;
            getString(name);
            std::cout << "Coach: ";
            String coach;
            getString(coach);
            std::cout << "Team members (number): ";
            int members = inputnumber(true);
            sports_menu.print();
            int selectedsport = inputnumber(false, 1, 3);
            if (selectedsport == 1) {
                std::cout << "Assistant coach: ";
                String assistant_coach;
                getString(assistant_coach);
                bme.push(new Football(name, coach, members, assistant_coach));
            }
            else if (selectedsport == 2) {
                std::cout << "Cheerleaders (number): ";
                int cheerleaders = inputnumber(true);
                bme.push(new Basketball(name, coach, members, cheerleaders));
            }
            else if (selectedsport == 3) {
                std::cout << "Amount of support this year: ";
                int support = inputnumber(true);
                bme.push(new Handball(name, coach, members, support));
            }
            std::cout << "Team added!" << std::endl;
            return_to_main();
        }

        else if (selectedmenu == 2) {
            if (bme.size() >= 1) {
                std::cout << std::endl << "############################" << std::endl << std::endl;
                bme.listnames();
                std::cout << std::endl;
                int index = inputnumber(false, 1, bme.size());
                bme.pop(index-1);
                std::cout << "Team deleted!" << std::endl;
            }
            else {
                std::cout << "There aren't any teams!" << std::endl;
            }
            return_to_main();
        }

        else if (selectedmenu == 3) {
            list_menu.print();
            int selectedlisting = inputnumber(false, 1, 4);
            std::cout << std::endl << "############################" << std::endl << std::endl;
            if (selectedlisting == 1)
                bme.list(football);
            else if (selectedlisting == 2)
                bme.list(basketball);
            else if (selectedlisting == 3)
                bme.list(handball);
            else if (selectedlisting == 4)
                bme.list();
            return_to_main();
        }

        else if (selectedmenu == 4 || selectedmenu == 5) {
            std::cout << "Filename (without extension): ";
            String filename;
            getString(filename);
            filename = filename + ".dat";
            if (selectedmenu == 4) {
                std::ofstream file(filename.c_str());
                bme.write(file);
                std::cout << "Successful exportation!" << std::endl;
            }
            else {
                std::ifstream file(filename.c_str());
                if (file.is_open()) {
                    bme.read(file);
                    std::cout << "Successful importation!" << std::endl;
                }
                else
                    std::cout << "File couldn't be opened or does not exist!" << std::endl;
            }
            return_to_main();
        }

        else if (selectedmenu == 6) {
            bme.delete_teams();
            std::cout << "All teams deleted!" << std::endl;
            return_to_main();
        }
    }

    return 0;
}
