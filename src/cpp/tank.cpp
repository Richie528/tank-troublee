#include "tank.hpp"
#include "action.hpp"

float rad(float x) {
    return x * PI / 180;
}

Tank::Tank(float posX, float posY, float rot, Color col, std::vector<int> inputKeys) : rotation(rot), colour(col) {
    pos = Vector2{posX, posY};
    tankBody = CreatePhysicsBodyRectangle(Vector2{pos.x, pos.y}, tankWidth, tankHeight, 10);
    SetPhysicsBodyRotation(tankBody, rad(rotation));

    actionKeys[Action::forward] = inputKeys[0]; 
    actionKeys[Action::backward] = inputKeys[1];
    actionKeys[Action::left] = inputKeys[2];
    actionKeys[Action::right] = inputKeys[3];
    actionKeys[Action::shoot] = inputKeys[4];
}

const std::vector<Rectangle> *Tank::getTankRects() {
    return &tankRects;
}

const PhysicsBody *Tank::getTankBody() {
    return &tankBody;
}

int Tank::updateBody() {
    return 0;
}

int Tank::move() {
    float move = moveSpeed * (IsKeyDown(actionKeys[Action::forward]) - IsKeyDown(actionKeys[Action::backward]));
    float rotate = rotateSpeed * (IsKeyDown(actionKeys[Action::right]) - IsKeyDown(actionKeys[Action::left]));

    rotation = std::fmod(rotation + rotate, 360);
    SetPhysicsBodyRotation(tankBody, rad(rotation));

    PhysicsAddTorque(tankBody, move);

    return 0;
}

int Tank::shoot() {
    if (IsKeyDown(actionKeys[Action::shoot])) {
        // shoot
    }
    return 0;
}

int Tank::run() {
    move();
    shoot();
    return 0;
}

int Tank::draw() {
    if (tankBody == NULL) return 0;
    for (int j = 0; j < 4; j++) {
        DrawLineEx(
            GetPhysicsShapeVertex(tankBody, j),
            GetPhysicsShapeVertex(tankBody, (j + 1) % 4),
            2,
            colour
        );
    }
    return 0;
}