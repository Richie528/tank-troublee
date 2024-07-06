#include <bits/stdc++.h>
#include "raylib.h"
#include "map.hpp"
#include "tank.hpp"
#include "bullet.hpp"

int screenWidth = 808;
int screenHeight = 808;

Map map;

int draw() {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    map.draw();

    EndDrawing();
    return 0;
}

int main() {
    InitWindow(screenWidth, screenHeight, "Tank Troublee");
    SetTargetFPS(60);

    map.generate();
    while (!WindowShouldClose()) {
        draw();
    }

    CloseWindow();        
    return 0;
}