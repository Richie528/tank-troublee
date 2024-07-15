#include "tank.hpp"
#include "action.hpp"

float rad(float x) {
    return x * PI / 180;
}

Tank::Tank(b2World* world, float posX, float posY, float rot, Color col, std::vector<int> inputKeys) : rotation(rot), colour(col) {
    pos = Vector2{posX, posY};

    actionKeys[Action::forward] = inputKeys[0]; 
    actionKeys[Action::backward] = inputKeys[1];
    actionKeys[Action::left] = inputKeys[2];
    actionKeys[Action::right] = inputKeys[3];
    actionKeys[Action::shoot] = inputKeys[4];

    b2BodyDef tankBodyDef;
    tankBodyDef.type = b2_dynamicBody;
    tankBodyDef.position.Set(pos.x, pos.y);
    tankBody = world->CreateBody(&tankBodyDef);

    b2PolygonShape tankBox;
    tankBox.SetAsBox(tankHeight, tankWidth);

    b2FixtureDef tankFixtureDef;
    tankFixtureDef.shape = &tankBox;
    tankFixtureDef.density = 1.0f;
    tankFixtureDef.friction = 0.3f;

    tankBody->CreateFixture(&tankFixtureDef);
}

const b2Body *Tank::getTankBody() {
    return tankBody;
}

int Tank::move() {
    float move = moveSpeed * (IsKeyDown(actionKeys[Action::forward]) - IsKeyDown(actionKeys[Action::backward]));
    float rotate = rotateSpeed * (IsKeyDown(actionKeys[Action::right]) - IsKeyDown(actionKeys[Action::left]));

    rotation = std::fmod(rotation + rotate, 360);

    int x = move * sin(rad(rotation));
    int y = -move * cos(rad(rotation));

    return 0;
}

int Tank::shoot() {
    if (IsKeyDown(actionKeys[Action::shoot])) {
        die();
    }
    return 0;
}

int Tank::die() {

    std::cout << "died\n";
    return 0;
}

int Tank::run() {
    move();
    shoot();
    return 0;
}

int Tank::draw() {

    return 0;
}