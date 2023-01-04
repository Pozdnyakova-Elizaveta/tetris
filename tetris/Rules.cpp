#include "Rules.h"
Rules::Rules():Base_window() {

}
void Rules::functioning() {
    RenderWindow window(VideoMode(length, width), "Tetris");
    while (window.isOpen())
    {
        Event event;
        window.draw(s_background);
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.display();
    }
}
