#include <bits/stdc++.h>
#include "raylib.h"
#include "box2d/box2d.h"

#include "map.hpp"
#include "tank.hpp"
#include "bullet.hpp"

const float timeStep = 1.0f / 60.0f;
const int32 velocityIterations = 6;
const int32 positionIterations = 2;
const int screenWidth = 808;
const int screenHeight = 808;
float f(int x) {return float(x + 3);}

b2Vec2 gravity(0.0f, 0.0f);
b2World world(gravity);

Map map;
Tank tank = Tank(&world, f(150), f(150), 90.0f, RED, {KEY_W, KEY_S, KEY_A, KEY_D, KEY_Q});

int draw() {
    BeginDrawing();
        ClearBackground(BLACK);
        map.draw();
        tank.draw();

    EndDrawing();
    return 0;
}

int main() {
    InitWindow(screenWidth, screenHeight, "Tank Troublee");

    map.generate(&world);

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        world.Step(timeStep, velocityIterations, positionIterations);

        tank.run();

        draw();
    }

    CloseWindow();
    return 0;
}