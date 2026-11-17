//Sarshar Chavoshi Rad
//2025.05.18
//Betyg E
//lärare : Jimmy Åhlander


#include <iostream>
#include "Labrys.h"

int main() {
    int width = 7, length = 7;
    Labrys maze(width, length);

    int choice;

    while (true) {

        std::cout << std::endl;
        std::cout << "1. Skapa en ny labyrint och visa den" << std::endl;
        std::cout << "2. Exit" << "\n\n";
        std::cin >> choice;
        std::cout << "\n\n";

        switch (choice) {
        case 1:
            maze = Labrys(width, length);
            maze.PrintLabrys();
            break;

        case 2:
            return 0;

        default:

            std::cout << "choose mellan 1 och 2\n";

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                continue;
            }

        }

    }

    return 0;
}