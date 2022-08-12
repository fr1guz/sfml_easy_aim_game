#ifndef PROJECT_AIM_GAME_H
#define PROJECT_AIM_GAME_H


#include <ctime>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "../Circle/Circle.h"

class Game {
private:
    sf::RenderWindow *_window;
    sf::Event _event;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    //Game logic
    sf::Clock _clock;
    std::vector<Circle *> _circles;
    sf::Time spawnTimer;
    int nMaxCircles;
    bool mouseHeld;
    int destroyedCircles;

    //Inits
    void initVariables();

    void initWindow();
public:
    //Constructors & Destructors
    Game();

    virtual ~Game();

    //Accessories
    const bool running() const;

    //Updates
    void pollEvent();

    void updateMousePos();

    void updateEnemySpawnTimer();

    void spawnCircle();

    void updateCircles();

    void reduceCircles();

    void update();

    //Renders
    void render();

    void renderCircles(sf::RenderTarget &renderTarget);

};


#endif //PROJECT_AIM_GAME_H
