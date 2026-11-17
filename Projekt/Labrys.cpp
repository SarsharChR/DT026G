//Sarshar Chavoshi Rad
//2025.05.18
//Betyg E
//lärare : Jimmy Åhlander


#include "Labrys.h"
#include <iostream>
#include <algorithm>
#include <random>

Labrys::Labrys(int w, int l) {
    width = w;
    length = l;
    start = { 0,0 };                          // https://en.cppreference.com/w/cpp/language/constructor   [1]
    end = { w - 1,l - 1 };
    mesh.resize(length);                    // https://en.cppreference.com/w/cpp/container/vector/resize    [2]
    for (int i = 0; i < length; ++i) {

        mesh[i].resize(width);
    }
    MakeLabrys();
}

bool Labrys::isValid(int x, int y) {
    return x >= 0 and x < width and y >= 0 and y < length and !mesh[y][x].visited;
}
// för att kolla att DFS funkar i labrint och besökta inte igen de noder som har besökt.

void Labrys::dfs(int x, int y) {

    mesh[y][x].visited = true;

    std::vector<Directions> directions = { UP, RIGHT, DOWN, LEFT };
    std::random_device rd;
    std::mt19937 g(rd());               // https://www.youtube.com/watch?v=uzseOE4e6VE shuffle algorithm  (från tiden 8:20)   [3]
    std::shuffle(directions.begin(), directions.end(), g);

    for (auto dirs : directions) {
        int dx = (dirs == RIGHT) - (dirs == LEFT);
        int dy = (dirs == DOWN) - (dirs == UP);
        int nx = x + dx;
        int ny = y + dy;

        if (isValid(nx, ny)) {

            Directions opposite;
            if (dirs == UP)    opposite = DOWN;
            else if (dirs== DOWN)  opposite = UP;
            else if (dirs == LEFT)  opposite = RIGHT;
            else opposite = LEFT;


            mesh[ny][nx].dir = opposite;     //för att ta bort vägg mellan node som besökt
            dfs(nx, ny);
        }
    }


}

void Labrys::MakeLabrys() {
    dfs(start.first, start.second);
}

void Labrys::PrintLabrys() {
    // Rita den övre väggen
    std::cout << " ";
    for (int x = 0; x < width; ++x) {
        std::cout << "+++ ";
    }
    std::cout << "\n";

    // Mellanväggar
    for (int y = 0; y < length; ++y) {
     
        for (int x = 0; x < width; ++x) {
            // vägg mellan varje node 
            if (x == 0 or (mesh[y][x].dir != LEFT and mesh[y][x - 1].dir != RIGHT))
                std::cout << "|";
            else
                std::cout << " ";

            // start och slut node
            if (y == start.first and x == start.second)
                std::cout << " S ";
            else if (y == end.first and x == end.second)
                std::cout << " E ";
            else
                std::cout << "   ";
        }
        // Höger vägg av den sista noden
        std::cout << "|\n";

        // Horisontella väggar under varje node
        std::cout << " ";
        for (int x = 0; x < width; ++x) {
            if (mesh[y][x].dir == DOWN or (y + 1 < length and mesh[y + 1][x].dir == UP))
                std::cout << "    ";
            else
                std::cout << "+++ ";
        }
        std::cout << "\n";
    }
}



