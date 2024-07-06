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

int dsu[69];
int leader(int x) {
    if (dsu[x] == x) return x;
    return dsu[x] = leader(dsu[x]);
}

int generateMap() {
    // Generate map randomly
    std::srand(std::time(nullptr));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 9; j++) {
            wallsY[i][j] = std::rand() % 2;
            if (j == 0 || j == 8) wallsY[i][j] = 1;
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 8; j++) {
            wallsX[i][j] = std::rand() % 2;
            if (i == 0 || i == 8) wallsX[i][j] = 1;
        }
    }
    // Make sure map is connected
    std::vector<std::pair<int, int>> edges;
    for (int i = 0; i < 64; i++) dsu[i] = i;
    for (int i = 0; i < 8; i++) {
        for (int j = 1; j < 8; j++) {
            int a = i * 8 + j - 1;
            int b = i * 8 + j;
            if (wallsY[i][j]) edges.push_back({a, b});
            else dsu[leader(a)] = leader(b);
        }
    }
    for (int i = 1; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int a = j * 8 + i - 1;
            int b = j * 8 + i;
            if (wallsY[i][j]) edges.push_back({a, b});
            else dsu[leader(a)] = leader(b);
        }
    }
    std::random_shuffle(edges.begin(), edges.end());
    for (std::pair<int, int> edge : edges) {
        int a = edge.first;
        int b = edge.second;
        if (leader(a) != leader(b)) {
            /*
            
            REMOVE THE WALL BETWEEN A AND B SOMEHOW
            
            */
            dsu[leader(a)] = leader(b);
        }
    }
    // Create rectangles
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