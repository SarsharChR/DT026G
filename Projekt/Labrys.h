//Sarshar Chavoshi Rad
//2025.05.18
//Betyg E
//lärare : Jimmy Åhlander


#pragma once

#include <vector>
#include <utility>



enum Directions {
    UP, RIGHT, LEFT, DOWN
};

struct Node {
    bool visited = false; // besökt eller inte för noder
    Directions dir;
};

class Labrys {
private:


    int width, length; // storleken på labyrinten ( encapsulation)
    std::vector<std::vector<Node>> mesh; // 2D-vektor (matris) av nod
    std::pair<int, int> start, end; // start och slutposition i labyrint
    void dfs(int x, int y);//DFS för att utforska i vår labyrint
    bool isValid(int x, int y); // för att kolla att DFS funkar i labrint och besökta inte igen de noder som har besökt.


public:

    Labrys(int w, int l); /// konstruktör igen
    void MakeLabrys(); // funktion för att skapa en slumpmässig labyrint
    void PrintLabrys(); // display labyrint

};

//källor
// https://www.youtube.com/watch?v=UEAqtqzRHv4 (för att förstå dfs men spårket av videon är på mitt modersmål)
// https://www.youtube.com/watch?v=xRChbscy4tM (för att förstå dfs men spårket av videon är på mitt modersmål)
// https://en.cppreference.com/w/cpp/language/constructor   [1]
// https://en.cppreference.com/w/cpp/container/vector/resize            [2] 
// https://www.youtube.com/watch?v=uzseOE4e6VE shuffle algorithm  (från tiden 8:20)      [3]
// https://en.wikipedia.org/wiki/Maze_generation_algorithm   (För att förstå hur jag ska implementera Recursive[Recursive implementation delen]) 
// https://www.youtube.com/watch?v=Sbciimd09h4&t=199s (för att förstå hur funkar Recursive bara, från tiden 3:13 )
// fått häjlp från Martins datahörna och Chat gpt okcså 

