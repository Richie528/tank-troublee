#include "map.hpp"

Map::Map() {
    
}

const std::vector<Rectangle> *Map::getWalls() {
    return &walls;
}

float Map::f(int x) {
    return float(x + 3);
}

int Map::leader(int x) {
    if (dsu[x] == x) return x;
    return dsu[x] = leader(dsu[x]);
}

int Map::generate() {
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
            int a = (i - 1) * 8 + j;
            int b = i * 8 + j;
            if (wallsX[i][j]) edges.push_back({a, b});
            else dsu[leader(a)] = leader(b);
        }
    }
    std::random_shuffle(edges.begin(), edges.end());
    for (std::pair<int, int> edge : edges) {
        int a = edge.first;
        int b = edge.second;
        if (leader(a) != leader(b)) {
            int ai = a / 8, aj = a % 8;
            int bi = b / 8, bj = b % 8;
            // Vertical Wall
            if (bj - aj == 1) {
                wallsY[bi][bj] = 0;
            }
            // Horizontal Wall
            if (bi - ai == 1) {
                wallsX[bi][bj] = 0;
            }
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
    // Create physics bodies
    for (Rectangle wall : walls) {
        CreatePhysicsBodyRectangle(Vector2{wall.x, wall.y}, wall.width, wall.height, 10);
    }
    return 0;
}

int Map::draw() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            DrawRectangle(
                f(i * 100),
                f(j * 100),
                f(100),
                f(100),
                ((i + j) % 2) ? gridColourA : gridColourB
            );
        }
    }
    for (Rectangle wall : walls) {
        DrawRectangleRec(wall, wallColour);
    }
    return 0;
}