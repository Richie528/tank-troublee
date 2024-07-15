#include <bits/stdc++.h>
#include "raylib.h"
#include "box2d/box2d.h"

#include "physics.hpp"
#include "map.hpp"
#include "tank.hpp"
#include "bullet.hpp"

int screenWidth = 808;
int screenHeight = 808;
float f(int x) {return float(x + 3);}

Map map;
Tank tank = Tank(f(150), f(150), 90.0f, RED, {KEY_W, KEY_S, KEY_A, KEY_D, KEY_Q});

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

    map.generate();

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        tank.run();

        draw();
    }

    CloseWindow();
    return 0;
}