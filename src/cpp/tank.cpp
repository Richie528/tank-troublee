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
    tankBodyDef.position.Set(
        pos.x, 
        pos.y
    );
    tankBody = world->CreateBody(&tankBodyDef);

    b2PolygonShape tankBox;
    tankBox.SetAsBox(
        tankHeight / 2, 
        tankWidth / 2
    );

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

    rotation = tankBody->GetAngle();

    b2Vec2 targetVel = {
        move * sin(rotation),
        -move * cos(rotation)
    };

    tankBody->SetAngularVelocity(rotate);
    tankBody->SetLinearVelocity(targetVel);

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
    b2Vec2 drawPosition = tankBody->GetPosition();
    float drawRotation = tankBody->GetAngle();

    Vector2 a = Vector2{
        drawPosition.x - (tankWidth / 2) * cos(drawRotation) - (tankHeight / 2) * sin(drawRotation),
        drawPosition.y - (tankWidth / 2) * sin(drawRotation) + (tankHeight / 2) * cos(drawRotation)
    };
    Vector2 b = Vector2{
        drawPosition.x + (tankWidth / 2) * cos(drawRotation) - (tankHeight / 2) * sin(drawRotation),
        drawPosition.y + (tankWidth / 2) * sin(drawRotation) + (tankHeight / 2) * cos(drawRotation)
    };
    Vector2 c = Vector2{
        drawPosition.x + (tankWidth / 2) * cos(drawRotation) + (tankHeight / 2) * sin(drawRotation),
        drawPosition.y + (tankWidth / 2) * sin(drawRotation) - (tankHeight / 2) * cos(drawRotation)
    };
    Vector2 d = Vector2{
        drawPosition.x - (tankWidth / 2) * cos(drawRotation) + (tankHeight / 2) * sin(drawRotation),
        drawPosition.y - (tankWidth / 2) * sin(drawRotation) - (tankHeight / 2) * cos(drawRotation)
    };

    DrawLineEx(a, b, 2, colour);
    DrawLineEx(b, c, 2, colour);
    DrawLineEx(c, d, 2, colour);
    DrawLineEx(d, a, 2, colour);

    return 0;
}