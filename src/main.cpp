#include "game.h"
#include "SFML/Main.hpp"

int main(int argc, char** argv)
{
    Game game;
    game.Init();
    game.Loop();
    game.Destroy();
    return 0;
}