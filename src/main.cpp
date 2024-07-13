#include <bits/stdc++.h>
#include "raylib.h"
#define PHYSAC_IMPLEMENTATION
#include "physac.h"

#include "map.hpp"
#include "tank.hpp"
#include "bullet.hpp"

int screenWidth = 808;
int screenHeight = 808;
float f(int x) {return float(x + 3);}

Map map;
Tank tank = Tank(f(150), f(150), float(0), RED, {KEY_W, KEY_S, KEY_A, KEY_D, KEY_Q});

int draw() {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    map.draw();
    tank.draw();

    EndDrawing();
    return 0;
}

int main() {
    InitWindow(screenWidth, screenHeight, "Tank Troublee");
    InitPhysics();
    SetTargetFPS(60);

    map.generate();
    while (!WindowShouldClose()) {
        tank.run();
        draw();
    }

    ClosePhysics();
    CloseWindow();        
    return 0;
}