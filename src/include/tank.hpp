#pragma once

#include <bits/stdc++.h>
#include "raylib.h"
#include "box2d/box2d.h"
#include "action.hpp"
#include "physics.hpp"

const float moveSpeed = 10000;
const float rotateSpeed = 2.5;
const float tankWidth = 30;
const float tankHeight = 40;

class Tank {
private:
    Color colour;
    Vector2 pos;
    float rotation;
    int ammo;
    std::map<Action, int> actionKeys;
    b2Body* tankBody;
    int move();
    int shoot();
    int die();

public:
    Tank(b2World* world, float posX, float posY, float rotation, Color colour, std::vector<int> inputKeys);
    const b2Body *getTankBody();
    int run();
    int draw();
};