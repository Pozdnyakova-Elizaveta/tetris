#include "Game.h"
#include "Square.h"
#include "Shapes.h"
#include "menu.h"
Game::Game():Base_window() {
	grid.loadFromFile("files\\grid.jpeg");//обработка изображения игрового поля
	s_grid.setTexture(grid);
    s_grid.setScale(1.2f, 1.2f);
    s_grid_next_shapes.setTexture(grid);//обработка изображения поля следующей фигуры
    s_grid_next_shapes.setTextureRect(IntRect(0, 0, 188, 187));
    s_grid_next_shapes.setScale(1.2f, 1.2f);
    font.loadFromFile("files\\font_game.ttf");//загрузка шрифта
    button_main_menu.loadFromFile("files\\menu.png");//обработка изображения кнопки выхода в главное меню
    s_button_main_menu.setTexture(button_main_menu);
    s_button_main_menu.setScale(0.4f, 0.4f);
    score = 0;
}
void Game::functioning() {
    RenderWindow window(VideoMode(length, width), "Tetris");//создание окна
    time_t start, next;
    double second;
    int c = 0;
    while (window.isOpen())
    {
        Event event;
        Text text_next_shape("Next shape:", font, 26);//надпись над полем следующей фигуры
        text_next_shape.setPosition(545, 150);
        Text text_score("", font, 26);
        std::string s = "Score: " + std::to_string(score);//строка счета
        text_score.setString(s);
        text_score.setPosition(580, 450);
       // window.draw(s_background);//вывод фона
        s_grid.setPosition(30, 20);//размещение элементов окна
        s_grid_next_shapes.setPosition(535, 200);
        s_button_main_menu.setPosition(770, 680);
       // window.draw(s_button_main_menu);//отрисовка элементов окна и надписей
       // window.draw(s_grid);
       // window.draw(s_grid_next_shapes);
        //window.draw(text_score);
        //window.draw(text_next_shape);
        s7.Choice_shape();
        s7.draw_s(window);
       // window.display();
        Cursor cursor;
        time(&start);
        while (c == 0) {
            window.draw(s_background);//вывод фона
            window.draw(s_button_main_menu);//отрисовка элементов окна и надписей
            window.draw(s_grid);
            window.draw(s_grid_next_shapes);
            window.draw(text_score);
            window.draw(text_next_shape);
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)//закрытие окна
                    window.close();
                if (event.type == sf::Event::MouseMoved) {
                    if (event.mouseMove.x >= 770 && event.mouseMove.x <= 852 && event.mouseMove.y >= 680 && event.mouseMove.y <= 760) {//курсор наведен на кнопку - изображение курсора меняется на руку
                        if (cursor.loadFromSystem(sf::Cursor::Hand))
                            window.setMouseCursor(cursor);
                    }
                    else {//иначе курсор - стрелка
                        if (cursor.loadFromSystem(sf::Cursor::Arrow))
                            window.setMouseCursor(cursor);
                    }
                }
                if (event.type == event.MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
                    if (IntRect(770, 680, 82, 80).contains(Mouse::getPosition(window))) {//если была нажата ЛКМ в области кнопки выхода в главное меню - закрытие окна, создание окна меню
                        window.close();
                        Menu* menu = new Menu();
                        menu->functioning();
                        delete menu;
                    }
                }
            }
            time(&next);
            second = difftime(next, start);
            if (second >= 2) {
                if (s7.fall_check() == false) {
                    s7.fall();
                    time(&start);
                }
            }
            s7.draw_s(window);
            window.display();
        }
    }
}