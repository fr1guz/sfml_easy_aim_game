#include "Game.h"

//Private functions
//Inits
void Game::initVariables() {
    _window = nullptr;

    nMaxCircles = 10;
    mouseHeld = false;
    destroyedCircles = 0;
    spawnTimer = sf::seconds(1);
}

void Game::initWindow() {
    _window = new sf::RenderWindow(sf::VideoMode(1920, 1080),
                                   "project_aim",
                                   sf::Style::Close | sf::Style::Titlebar);
    _window->setFramerateLimit(60);
}

//Public functions
//Constructors & Destructors
Game::Game() {
    initVariables();
    initWindow();
}

Game::~Game() {
    delete _window;
}

//Accessories
const bool Game::running() const {
    return _window->isOpen();
}

//Updates
void Game::pollEvent() {
    while (_window->pollEvent(_event)) {
        switch (_event.type) {
            case sf::Event::Closed:
                _window->close();
                break;
            default:
                break;
        }
    }
}

void Game::updateMousePos() {
    mousePosWindow = sf::Mouse::getPosition(*_window);
    mousePosView = _window->mapPixelToCoords(mousePosWindow);
}

void Game::updateEnemySpawnTimer() {
    if (destroyedCircles >10) spawnTimer = sf::seconds(.5f);
}

void Game::spawnCircle() {
    Circle *circle;
    int randomCircle = rand() % 10;
    switch (randomCircle) {
        case 4:
        case 3:
        case 7:
        case 9:
            circle = new GreenCircle;
            break;
        case 1:
        case 0:
        case 5:
            circle = new BlueCircle;
            break;
        case 6:
        case 2:
            circle = new PurpleCircle;
            break;
        case 8:
            circle = new RedCircle;
            break;
    }
    circle->circle.setPosition(
            static_cast<float>(circle->circle.getRadius() +
                               rand() % static_cast<int>(_window->getSize().x - circle->circle.getRadius())),
            static_cast<float>(circle->circle.getRadius() +
                               rand() % static_cast<int>(_window->getSize().y - circle->circle.getRadius()))
    );
    _circles.push_back(circle);
}

void Game::updateCircles() {
    if (_clock.getElapsedTime().asSeconds() >= spawnTimer.asSeconds()) {
        if (_circles.size() < nMaxCircles) {
            spawnCircle();
            _clock.restart();
        }
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        if (!mouseHeld) {
            mouseHeld = true;
            bool deleted = false;
            for (int i = _circles.size() - 1; i > -1 && !deleted; --i) {
                if (_circles[i]->circle.getGlobalBounds().contains(mousePosView)) {
                    delete _circles[i];
                    _circles.erase(_circles.begin() + i);
                    ++destroyedCircles;
                    deleted = true;
                }
            }
        }
    } else {
        mouseHeld = false;
    }
}

void Game::reduceCircles() {
    for (int i = 0; i < _circles.size(); ++i) {
        if (_circles[i]->reduceCircle()) {
            delete _circles[i];
            _circles.erase(_circles.begin() + i);
        }
    }
}

void Game::update() {
    pollEvent();
    updateMousePos();
    updateEnemySpawnTimer();
    updateCircles();
    reduceCircles();
}

//Renders
void Game::renderCircles(sf::RenderTarget &renderTarget) {
    for (const auto &circle: _circles) {
        renderTarget.draw(circle->circle);
    }
}

void Game::render() {
    _window->clear(sf::Color::Black);

    renderCircles(*_window);

    _window->display();
}
