#pragma once

#include <bits/stdc++.h>
#include "raylib.h"
#include "box2d/box2d.h"
#include "action.hpp"

const float moveSpeed = 100;
const float rotateSpeed = 2.5;
const int tankWidth = 30;
const int tankHeight = 40;

class Tank {
private:
    Color colour;
    Vector2 pos;
    float rotation;
    int ammo;
    std::vector<Rectangle> tankRects;
    std::map<Action, int> actionKeys;

    int move();
    int shoot();
    int die();

public:
    Tank(float posX, float posY, float rotation, Color colour, std::vector<int> inputKeys);
    const std::vector<Rectangle> *getTankRects();
    int run();
    int draw();
};