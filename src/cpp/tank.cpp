#include "tank.hpp"
#include "action.hpp"

Tank::Tank(float posX, float posY, float rot, Color col, std::vector<int> inputKeys) : rotation(rot), colour(col) {
    pos = Vector2{-posX, -posY};

    actionKeys[Action::forward] = inputKeys[0];
    actionKeys[Action::backward] = inputKeys[1];
    actionKeys[Action::left] = inputKeys[2];
    actionKeys[Action::right] = inputKeys[3];
    actionKeys[Action::shoot] = inputKeys[4];

    body = {
        Rectangle{-20, -30, 40, 60}
    };
}

const std::vector<Rectangle> *Tank::getBody() {
    return &body;
}

int Tank::move() {
    float move = IsKeyDown(actionKeys[Action::forward]) - IsKeyDown(actionKeys[Action::backward]);
    float rotate = IsKeyDown(actionKeys[Action::right]) - IsKeyDown(actionKeys[Action::left]);

    pos.x += move * sin(rotation);
    pos.y += move * cos(rotation);

    rotation += rotate;

    return 0;
}

int Tank::shoot() {
    if (IsKeyDown(actionKeys[Action::shoot])) {
        std::cout << "shoot\n";
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
    std::cout << "draw\n";
    for (Rectangle bodyPart : body) {
        DrawRectanglePro(bodyPart, pos, rotation, colour);
        DrawRectanglePro(Rectangle{0, 0, 50, 50}, Vector2{150, 150}, float(0), RED);
        DrawRectangle(250, 250, 100, 100, RED);
    }
    return 0;
}