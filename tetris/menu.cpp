#include "menu.h"
void start_menu(RenderWindow& window) {
    bool isMenu = 1;
    Texture menu_background, menu_title, rules_button, play_button;
    menu_background.loadFromFile("image\\background.jpg");
    menu_title.loadFromFile("image\\title.png");
    rules_button.loadFromFile("image\\rules.png");
    play_button.loadFromFile("image\\start.png");
    Sprite sprite_bg, sprite_rules, sprite_title, sprite_play;
    sprite_bg.setTexture(menu_background);
    sprite_rules.setTexture(rules_button);
    sprite_title.setTexture(menu_title);
    sprite_play.setTexture(play_button);
    sprite_title.setPosition(260, 160);
    sprite_title.setScale(0.2f, 0.2f);
    sprite_rules.setPosition(1000, 20);
    sprite_rules.setScale(0.3f, 0.3f);
    sprite_play.setPosition(450, 400);
    sprite_play.setScale(2.0f, 2.0f);
    window.draw(sprite_bg);
    window.draw(sprite_title);
    window.draw(sprite_rules);
    window.draw(sprite_play);
}