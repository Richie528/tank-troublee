#include <bits/stdc++.h>
#include "raylib.h"
#include "map.hpp"
#include "tank.hpp"
#include "bullet.hpp"

int screenWidth = 808;
int screenHeight = 808;

Map map;
Tank tank(50, 50, 90, RED);

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
    SetTargetFPS(60);

    map.generate();
    while (!WindowShouldClose()) {
        tank.run();
        draw();
    }

    CloseWindow();        
    return 0;
}