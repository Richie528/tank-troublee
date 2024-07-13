#pragma once

#include <bits/stdc++.h>
#include "raylib.h"
#include "physac.h"
#include "action.hpp"

const float moveSpeed = 2;
const float rotateSpeed = 2.5;
const Color tankPartsColor = {70, 70, 70, 255};

class Tank {
private:
    Color colour;
    Vector2 pos;
    float rotation;
    int ammo;
    std::vector<Rectangle> body;
    std::map<Action, int> actionKeys;

    int updateBody();
    int move();
    int shoot();

public:
    Tank(float posX, float posY, float rotation, Color colour, std::vector<int> inputKeys);
    const std::vector<Rectangle> *getBody();
    int run();
    int draw();
};