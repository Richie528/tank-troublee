#pragma once

#include <bits/stdc++.h>
#include "raylib.h"
#include "physac.h"

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
    std::vector<Rectangle> wallRects;
    std::vector<PhysicsBody> wallBodies;

    float f(int x);
    int leader(int x);

public:
    Map();
    const std::vector<Rectangle> *getWallRects();
    const std::vector<PhysicsBody> *getWallBodies();
    int generate();
    int draw();
};