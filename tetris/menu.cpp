#include "menu.h"
#include "Rules.h"
Menu::Menu():Base_window() {
    menu_title.loadFromFile("image\\title.png");
    rules_button.loadFromFile("image\\rules.png");
    play_button.loadFromFile("image\\start.png");
    s_rules.setTexture(rules_button);
    s_title.setTexture(menu_title);
    s_play.setTexture(play_button);
}
void Menu::functioning() {
    RenderWindow window(VideoMode(1100, 600), "Tetris");
    bool animation = 0;
    while (window.isOpen())
    {
        Event event;
        Event event_rules;
        window.draw(s_background);
        s_title.setPosition(260, 160);
        s_title.setScale(0.2f, 0.2f);
        window.draw(s_title);
        s_rules.setPosition(1000, 20);
        s_rules.setScale(0.3f, 0.3f);
        window.draw(s_rules);
        s_play.setPosition(450, 400);
        s_play.setScale(2.0f, 2.0f);
        window.draw(s_play);
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        Cursor cursor;
        if (IntRect(1000, 20, 62, 60).contains(Mouse::getPosition(window)) || IntRect(450, 400, 214, 90).contains(Mouse::getPosition(window))) {
            if (cursor.loadFromSystem(sf::Cursor::Hand))
                window.setMouseCursor(cursor);
        }
        else {
            if (cursor.loadFromSystem(sf::Cursor::Arrow))
                window.setMouseCursor(cursor);
        }
        if (Mouse::isButtonPressed(Mouse::Left) && IntRect(1000, 20, 62, 60).contains(Mouse::getPosition(window))) {
            window.clear();
            Rules *rules = new Rules();
            rules->functioning();
        }

        if (Mouse::isButtonPressed(Mouse::Left) && IntRect(450, 400, 214, 90).contains(Mouse::getPosition(window))) {
            window.close();
            //game(window);
        }
        window.display();
    }
}