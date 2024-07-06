#pragma once

#include <bits/stdc++.h>
#include "raylib.h"

const Color wallColour = {50, 50, 50, 255};
const Color gridColourA = {240, 240, 240, 255};
const Color gridColourB = {220, 220, 220, 255};

class Map {
private:
    int map[8][8];
    int wallsY[8][9];
    int wallsX[9][8];
    int dsu[69];
    std::vector<std::pair<int, int>> edges;
    std::vector<Rectangle> walls;

    float f(int x);
    int leader(int x);

public:
    Map();
    const std::vector<Rectangle> *getWalls();
    int generate();
    int draw();
};