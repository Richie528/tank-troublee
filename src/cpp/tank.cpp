#include "tank.hpp"
#include "action.hpp"

float rad(float x) {
    return x * PI / 180;
}

Tank::Tank(float posX, float posY, float rot, Color col, std::vector<int> inputKeys) : rotation(rot), colour(col) {
    pos = Vector2{posX, posY};

    actionKeys[Action::forward] = inputKeys[0];
    actionKeys[Action::backward] = inputKeys[1];
    actionKeys[Action::left] = inputKeys[2];
    actionKeys[Action::right] = inputKeys[3];
    actionKeys[Action::shoot] = inputKeys[4];

    body = {
        Rectangle{-15, -20, 30, 40}
    };
}

const std::vector<Rectangle> *Tank::getBody() {
    return &body;
}

int Tank::updateBody() {
    body.clear();
    body = {
        Rectangle{-15 + pos.x, -20 + pos.y, 30, 40}
    };

    return 0;
}

int Tank::move() {
    float move = IsKeyDown(actionKeys[Action::forward]) - IsKeyDown(actionKeys[Action::backward]);
    float rotate = IsKeyDown(actionKeys[Action::right]) - IsKeyDown(actionKeys[Action::left]);

    pos.x += moveSpeed * move * sin(rad(rotation));
    pos.y += -moveSpeed * move * cos(rad(rotation));
    updateBody();

    rotation = std::fmod((rotation + (rotate * rotateSpeed) + 360), 360);

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
    for (Rectangle bodyPart : body) {
        DrawRectanglePro(bodyPart, Vector2{15, 20}, rotation, colour);
    }
    return 0;
}