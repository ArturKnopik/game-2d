#include <SFML/Graphics.hpp>
#include "include/Game.h"
#include "GameStates/MenuState.h"

int main()
{
    std::shared_ptr<Game> game;
    game = std::make_shared<Game>() ;
    game->pushState(std::make_shared<MenuState>(game));
    game->gameLoop();
    return 0;
}