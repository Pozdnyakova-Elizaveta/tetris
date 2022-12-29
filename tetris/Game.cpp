#include "Game.h"
Game::Game():Base_window() {
	grid.loadFromFile("image\\grid.png");
	s_grid.setTexture(grid);
}
void Game::functioning() {
	RenderWindow window(VideoMode(length, width), "Tetris");
    while (window.isOpen())
    {
        Event event;
        window.draw(s_background);
        s_grid.setPosition(30,20);
        window.draw(s_grid);
        window.display();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
}