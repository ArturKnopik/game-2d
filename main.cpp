#include <SFML/Graphics.hpp>
#include "include/Game.h"
#include "include/MenuState.h"

int main()
{
    std::shared_ptr<Game> game;
    game = std::shared_ptr<Game> ( new Game());
    game->pushState(std::shared_ptr<GameState>(new MenuState(game)));
    game->gameLoop();
    return 0;
}