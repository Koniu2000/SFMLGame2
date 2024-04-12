#include "Game.h"

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    Game game;

    while (game.IsRunning())
    {
        game.GameRender();
        game.GameUpdate();
    }

    return 0;
}