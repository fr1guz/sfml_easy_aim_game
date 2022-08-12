#include "Game/Game.h"

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    Game game;

    while (game.running()) {
        game.update();

        game.render();
    }
}
