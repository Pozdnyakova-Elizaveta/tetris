#include "menu.h"
#include "Rules.h"
#include <iostream>
using namespace std;
Menu::Menu():Base_window() {
    menu_title.loadFromFile("image\\title.png");
    rules_button.loadFromFile("image\\rules.png");
    play_button.loadFromFile("image\\start.png");
    s_rules.setTexture(rules_button);
    s_title.setTexture(menu_title);
    s_play.setTexture(play_button);
}
void Menu::functioning() {
    RenderWindow window(VideoMode(length, width), "Tetris");
    bool animation = 0;
    Clock clock;
    float change = 0;
    while (window.isOpen())
    {
        Event event;
        Event event_rules;
        window.draw(s_background);
        s_title.setPosition(260, 160);
        s_title.setScale(0.2f, 0.2f);
        s_rules.setPosition(1000, 20);
        s_rules.setScale(0.3f, 0.3f);
        s_play.setPosition(450, 400);
        s_play.setScale(2.0f, 2.0f);
        if (!animation) {
            float time = clock.getElapsedTime().asMicroseconds();
            clock.restart();
            time = time / 800;
            change = time;
            int i = 1;
            s_title.setTextureRect(IntRect(0, 0,0, 0));
            while (i != 7) {
                window.draw(s_background);
                if (change > 1000) {
                    s_title.setTextureRect(IntRect(0, 0, i * 500, 797));
                    i++;
                    cout << i << endl;
                    change = 0;
                }
                else {
                    time = clock.getElapsedTime().asMicroseconds();
                    clock.restart();
                    time = time / 800;
                    change += time;
                }
                window.draw(s_title);
                window.display();
            }
            animation = true;
        }
        window.draw(s_background);
        window.draw(s_title);
        window.draw(s_rules);
        window.draw(s_play);
        window.display();
        Cursor cursor;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseMoved) {
                if ((event.mouseMove.x >= 1000 && event.mouseMove.x <= 1062 && event.mouseMove.y >= 20 && event.mouseMove.y <= 80)||(event.mouseMove.x >= 450 && event.mouseMove.x <= 664 && event.mouseMove.y >= 400 && event.mouseMove.y <= 490)) {
                    if (cursor.loadFromSystem(sf::Cursor::Hand))
                        window.setMouseCursor(cursor);
                }
                else{
                    if (cursor.loadFromSystem(sf::Cursor::Arrow))
                        window.setMouseCursor(cursor);
                }
            }
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
    }
}