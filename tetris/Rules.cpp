#include "Rules.h"
#include "menu.h"

Rules::Rules() :Base_window() {
    font.loadFromFile("files\\font_game.ttf");
    button_main_menu.loadFromFile("files\\menu.png");//обработка изображения кнопки выхода в главное меню
    s_button_main_menu.setTexture(button_main_menu);
    s_button_main_menu.setScale(0.4f, 0.4f);
}
void Rules::functioning() {
    RenderWindow window(VideoMode(length, width), "Tetris");
    //Text rules("Сверху вниз падают фигуры разных цветов и форм. Фигуру можно двигать по горизонтали нажатием на клавиатуре стрелок вправо и влево, стрелка вверх повернет фигуру по часовой стрелки,\n стрелка вниз - против часовой. Нажав Enter, фигуру можно опустить в крайнее нижнее положение. При положении по краям, если движение дальше недоступно, фигура остаётся в последнем доступном положении. Задача игрока собирать фигуры в полностью заполненный ряд. В таком случае ряд исчезает и игрок получает баллы. После того как игрок соберет один ряд, он  получает 10 баллов, за два ряда - 30, за три - 60. Время падения фигур в течении игры уменьшается, начинается игра с падения фигур в течении 2 секунд и сокращается до 0.5 секунды. \n\n\nРазработчики игры - Малахова Ульяна, Позднякова Елизавета", font, 26);

    while (window.isOpen())
    {
        Event event;
        Cursor cursor;
        Text rules(L"Сверху вниз падают фигуры разных цветов и форм. Фигуру можно \nдвигать по горизонтали нажатием на клавиатуре стрелок вправо и \nвлево, стрелка вверх повернет фигуру по часовой стрелки,\nстрелка вниз - против часовой. Нажав Enter, фигуру можно опустить в\nкрайнее нижнее положение. При положении по краям, если движение \nдальше недоступно, фигура остаётся в последнем доступном \nположении. Задача игрока собирать фигуры в полностью заполненный \nряд. В таком случае ряд исчезает и игрок получает баллы. После того \nкак игрок соберет один ряд, он  получает 10 баллов, за два ряда - 30, \nза три - 60. Время падения фигур в течении игры уменьшается, \nначинается игра с падения фигур в течении 2 секунд и сокращается\n до 0.5 секунды. \n\n\n\n\n\n\n\nРазработчики игры - Малахова Ульяна, Позднякова Елизавета", font, 18);
        rules.setPosition(30, 20);
        window.draw(s_background);
        window.draw(rules);
        s_button_main_menu.setPosition(770, 680);
        window.draw(s_button_main_menu);
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
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
        window.display();
    }
}
