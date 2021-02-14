#include <SFML/Graphics.hpp>
#include "board.h"
#include "mainHeader.h"
#include "game.h"
#include "gamemanu.h"


int main()
{
    bool black_start;
    bool vs_computer;
    sf::RenderWindow window(sf::VideoMode(WIDTH + 200, HEIGHT), "Chess", sf::Style::Close);
    chess::GameManu manu(window);
    manu.run(black_start, vs_computer);
    chess::Game game(window, black_start);
    game.run();
    return 0;
}