#pragma once

#include <bits/stdc++.h>
#include "raylib.h"
#include "action.hpp"

class Tank {
private:
    Color colour;
    Vector2 pos;
    float rotation;
    int ammo;
    std::vector<Rectangle> body;
    std::map<Action, int> actionKeys;

    int move();
    int shoot();

public:
    Tank(float posX, float posY, float rotation, Color colour);
    const std::vector<Rectangle> *getBody();
    int run();
    int draw();
};