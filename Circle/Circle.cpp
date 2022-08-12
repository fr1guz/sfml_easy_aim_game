#include "Circle.h"

//Base circle
Circle::Circle() {
    circle.setRadius(150.f);
    circle.setOrigin(150.f, 150.f);
}

//Game logic
bool Circle::reduceCircle() {
    if (circle.getScale().x > .40f) circle.scale(.99f, .99f);
    else circle.scale(.97f, .97f);
    return (circle.getScale().x < .05f);
}


//Green _circle
//Inits
void GreenCircle::initCircle() {
    circle.setRadius(150.f);
    circle.setOrigin(150.f, 150.f);
}

void GreenCircle::setColor() {
    circle.setFillColor(sf::Color::Green);
}

//Public functions
//Constructors
GreenCircle::GreenCircle() : Circle() {
    initCircle();
    setColor();
}


//Blue _circles
void BlueCircle::initCircle() {
    circle.setRadius(120.f);
    circle.setOrigin(120.f, 120.f);
}

void BlueCircle::setColor() {
    circle.setFillColor(sf::Color::Blue);
}

//Public functions
//Constructor
BlueCircle::BlueCircle() : Circle() {
    initCircle();
    setColor();
}


//Purple _circles
void PurpleCircle::initCircle() {
    circle.setRadius(90.f);
    circle.setOrigin(90.f, 90.f);
}

void PurpleCircle::setColor() {
    circle.setFillColor(sf::Color::Magenta);
}

//Public functions
//Constructor
PurpleCircle::PurpleCircle() : Circle() {
    initCircle();
    setColor();
}


//Red _circles
void RedCircle::initCircle() {
    circle.setRadius(70.f);
    circle.setOrigin(70.f, 70.f);
}

void RedCircle::setColor() {
    circle.setFillColor(sf::Color::Red);
}

//Public functions
//Constructor
RedCircle::RedCircle() : Circle() {
    initCircle();
    setColor();
}
