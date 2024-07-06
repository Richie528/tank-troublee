#include<bits/stdc++.h>
#include "raylib.h"

int screenWidth = 808;
int screenHeight = 808;

int map[8][8];
int wallsY[8][9];
int wallsX[9][8];
std::vector<Rectangle> walls;

float f(int x) {
    return float(x + 3);
}

int generateMap() {
    // OUTER WALLS
    for(int i = 0; i < 8; i++) {
        wallsY[i][0] = wallsY[i][8] = 1;
        wallsX[0][i] = wallsX[8][i] = 1;
    }
    // HORIZONTAL WALLS
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 9; j++) {
            if (wallsY[i][j]) {
                Rectangle newWall = Rectangle{
                    f(j * 100 - 3), 
                    f(i * 100 - 3), 
                    f(6), 
                    f(106)
                };
                walls.push_back(newWall);
            }
        }
    }
    // VERTICAL WALLS
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 8; j++) {
            if (wallsX[i][j]) {
                Rectangle newWall = Rectangle{
                    f(j * 100 - 3), 
                    f(i * 100 - 3), 
                    f(106), 
                    f(6)
                };
                walls.push_back(newWall);
            }
        }
    }
    return 0;
}

int drawMap() {
    for (Rectangle wall : walls) {
        DrawRectangleRec(wall, RED);
    }
    return 0;
}

int draw() {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    drawMap();

    EndDrawing();
    return 0;
}

int main()
{
    InitWindow(screenWidth, screenHeight, "Tank Troublee");
    SetTargetFPS(60);

    generateMap();
    while (!WindowShouldClose()) 
    {
        draw();
    }

    CloseWindow();        
    return 0;
}