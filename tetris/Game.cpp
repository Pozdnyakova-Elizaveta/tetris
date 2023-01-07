#include "Game.h"
#include "Square.h"
#include "Shapes.h"
Game::Game():Base_window() {
	grid.loadFromFile("image\\grid.jpeg");
	s_grid.setTexture(grid);
}
void Game::functioning() {
	RenderWindow window(VideoMode(length, width), "Tetris");
    while (window.isOpen())
    {
        Event event;
        window.draw(s_background);
        s_grid.setPosition(30,20);
        s_grid.setScale(1.2f,1.2f);
        window.draw(s_grid);
        Shapes s7;
        s7.Choice_shape(window);
        window.display();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
}