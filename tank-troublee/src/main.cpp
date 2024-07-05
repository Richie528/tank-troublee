#include "raylib.h"

int FPS = 60;

int screenWidth = 800;
int screenHeight = 800;

int map[8][8];
int wallsX[8][10];
int wallsY[10][8];

int createMap() {
    for(int i = 0; i < 8; i++) {
        wallsX[i][0] = wallsX[i][9] = 1;
        wallsY[0][i] = wallsX[9][i] = 1;

        BeginDrawing();
        ClearBackground(RAYWHITE);

        EndDrawing();
    }

    return 0;
}

int main()
{
    InitWindow(screenWidth, screenHeight, "Tank Troublee");
    SetTargetFPS(FPS);

    while (!WindowShouldClose()) 
    {
        createMap();
    }

    CloseWindow();        
    return 0;
}