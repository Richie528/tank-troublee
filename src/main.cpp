#include <bits/stdc++.h>
#include "raylib.h"
#include "physac.h"

#include "map.hpp"
#include "tank.hpp"
#include "bullet.hpp"

int screenWidth = 808;
int screenHeight = 808;
float f(int x) {return float(x + 3);}

int main() {
    InitWindow(screenWidth, screenHeight, "Tank Troublee");
    InitPhysics();

    Map map;
    Tank tank = Tank(f(150), f(150), float(90), RED, {KEY_W, KEY_S, KEY_A, KEY_D, KEY_Q});
    map.generate();

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        tank.run();

        BeginDrawing();
            ClearBackground(BLACK);
            map.draw();
            tank.draw();
        EndDrawing();
    }

    ClosePhysics();
    CloseWindow();
    return 0;
}