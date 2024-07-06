#include "tank.hpp"
#include "action.hpp"

Tank::Tank(float posX, float posY, float rotation, Color colour) : rotation(rotation), colour(colour) {
    pos = {posX, posY};
    body = {
        {-20, -30, 40, 60}
    };
}

const std::vector<Rectangle> *Tank::getBody() {
    return &body;
}

int Tank::move() {
    float move = IsKeyPressed(actionKeys[Action::forward]) - IsKeyPressed(actionKeys[Action::backward]);
    float rotate = IsKeyPressed(actionKeys[Action::right]) - IsKeyPressed(actionKeys[Action::left]);

    pos.x += move * sin(rotation);
    pos.y += move * cos(rotation);

    rotation += rotate;

    return 0;
}

int Tank::shoot() {
    if (IsKeyPressed(actionKeys[Action::shoot])) {
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
        DrawRectanglePro(bodyPart, pos, rotation, colour);
    }
    return 0;
}