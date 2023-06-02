#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
using namespace std;
using namespace sf;
int main() {

    Game game;
	

    while (game.isOpen())
    {
        game.update();
        game.render();
    }
}