#include "menu.h"
#include "Rules.h"
#include "Game.h"
#include <iostream>
#include <SFML/Audio.hpp>
bool Menu::animation = 0;
using namespace std;
Menu::Menu():Base_window() {
    menu_title.loadFromFile("files\\title.png");
    rules_button.loadFromFile("files\\rules.png");
    play_button.loadFromFile("files\\start.png");
    s_rules.setTexture(rules_button);
    s_title.setTexture(menu_title);
    s_play.setTexture(play_button);
}
void Menu::set_animation(bool a) { animation = a; }
bool Menu::get_animation() { return animation; }
void Menu::functioning() {
    RenderWindow window(VideoMode(length, width), "Tetris");
    Clock clock;
    float change = 0;
    sf::Music music;
    music.openFromFile("files\\2340.wav");
    music.play();
    music.setLoop(true);
    while (window.isOpen())
    {
        Event event;
        Event event_rules;
        window.draw(s_background);
        s_title.setPosition(160, 260);
        s_title.setScale(0.2f, 0.2f);
        s_rules.setPosition(800, 20);
        s_rules.setScale(0.3f, 0.3f);
        s_play.setPosition(350, 550);
        s_play.setScale(2.0f, 2.0f);
        if (!Menu::get_animation()) {
            float time = clock.getElapsedTime().asMicroseconds();
            clock.restart();
            time = time / 800;
            change = time;
            int i = 1;
            s_title.setTextureRect(IntRect(0, 0,0, 0));
            while (i != 7) {
                if (Keyboard::isKeyPressed(Keyboard::Escape))
                {
                    i = 7;
                    s_title.setTextureRect(IntRect(0, 0, 3000, 797));
                }
                window.draw(s_background);
                if (change > 1000) {
                    s_title.setTextureRect(IntRect(0, 0, i * 500, 797));
                    i++;
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
            Menu::set_animation(true);
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
                if ((event.mouseMove.x >= 800 && event.mouseMove.x <= 862 && event.mouseMove.y >= 20 && event.mouseMove.y <= 80)||(event.mouseMove.x >= 350 && event.mouseMove.x <= 564 && event.mouseMove.y >= 550 && event.mouseMove.y <= 640)) {
                    if (cursor.loadFromSystem(sf::Cursor::Hand))
                        window.setMouseCursor(cursor);
                }
                else{
                    if (cursor.loadFromSystem(sf::Cursor::Arrow))
                        window.setMouseCursor(cursor);
                }
            }
            if (event.type == event.MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
                if (IntRect(800, 20, 62, 60).contains(Mouse::getPosition(window))){
                    window.clear();
                    Rules* rules = new Rules();
                    rules->functioning();
                    delete rules;
                }
                if (IntRect(350, 550, 214, 90).contains(Mouse::getPosition(window))) {
                    window.close();
                    Game* game = new Game();
                    game->functioning();
                    delete game;
                }
            }
        }
    }
}