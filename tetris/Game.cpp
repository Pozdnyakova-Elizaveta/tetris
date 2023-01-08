#include "Game.h"
#include "Square.h"
#include "Shapes.h"
#include "menu.h"
Game::Game():Base_window() {
	grid.loadFromFile("files\\grid.jpeg");
	s_grid.setTexture(grid);
    s_grid.setScale(1.2f, 1.2f);
    s_grid_next_shapes.setTexture(grid);
    s_grid_next_shapes.setTextureRect(IntRect(0, 0, 188, 187));
    s_grid_next_shapes.setScale(1.2f, 1.2f);
    font.loadFromFile("files\\font_game.ttf");
    button_main_menu.loadFromFile("files\\menu.png");
    s_button_main_menu.setTexture(button_main_menu);
    s_button_main_menu.setScale(0.4f, 0.4f);
    score = 0;
}
void Game::functioning() {
    RenderWindow window(VideoMode(length, width), "Tetris");
    while (window.isOpen())
    {
        Event event;
        Text text_next_shape("Next shape:", font, 26);
        text_next_shape.setPosition(545, 150);
        Text text_score("", font, 26);
        std::string s = "Score: " + std::to_string(score);
        text_score.setString(s);
        text_score.setPosition(580, 450);
        window.draw(s_background);
        s_grid.setPosition(30, 20);
        s_grid_next_shapes.setPosition(535, 200);
        s_button_main_menu.setPosition(770, 680);
        window.draw(s_button_main_menu);
        window.draw(s_grid);
        window.draw(s_grid_next_shapes);
        window.draw(text_score);
        window.draw(text_next_shape);
        Shapes s7;
        s7.Choice_shape(window);
        window.display();
        Cursor cursor;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseMoved) {
                if (event.mouseMove.x >= 770 && event.mouseMove.x <= 852 && event.mouseMove.y >= 680 && event.mouseMove.y <= 760) {
                    if (cursor.loadFromSystem(sf::Cursor::Hand))
                        window.setMouseCursor(cursor);
                }
                else {
                    if (cursor.loadFromSystem(sf::Cursor::Arrow))
                        window.setMouseCursor(cursor);
                }
            }
            if (event.type == event.MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
                if (IntRect(770, 680, 82, 80).contains(Mouse::getPosition(window))) {
                    window.close();
                    Menu *menu = new Menu();
                    menu->functioning();
                    delete menu;
                }
            }
        }
    }
}