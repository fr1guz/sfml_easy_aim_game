#ifndef PROJECT_AIM_CIRCLE_H
#define PROJECT_AIM_CIRCLE_H


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Circle {
public:
    sf::CircleShape circle;

    //Constructors & Destructors
    Circle();

    virtual ~Circle() = default;

    virtual void setColor() = 0;

    virtual void initCircle() = 0;

    //Class logic
    bool reduceCircle();
};

class GreenCircle final : public Circle {
    void setColor() override;

    void initCircle() override;

public:
    GreenCircle();
};

class BlueCircle final : public Circle {
    void setColor() override;

    void initCircle() override;

public:
    BlueCircle();
};

class PurpleCircle final : public Circle {
    void setColor() override;

    void initCircle() override;

public:
    PurpleCircle();
};

class RedCircle final : public Circle {
    void setColor() override;

    void initCircle() override;

public:
    RedCircle();
};


#endif //PROJECT_AIM_CIRCLE_H
