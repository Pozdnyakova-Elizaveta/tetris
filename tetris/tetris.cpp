// tetris.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "square.h"
#include <math.h>
#include <dos.h>
#include <SFML/Graphics.hpp>
#include "menu.h"
#include <iostream>
#include <windows.h>
using namespace sf;
int main()
{
    Square* s= new Square;
    RenderWindow window(VideoMode(1100, 600), "Tetris");
    while (window.isOpen())
    {
        Event event;
        Event event_rules;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        start_menu(window);
        Cursor cursor;
        if (IntRect(1000, 20, 62, 60).contains(Mouse::getPosition(window)) || IntRect(450, 400, 214, 90).contains(Mouse::getPosition(window))) {
            if (cursor.loadFromSystem(sf::Cursor::Hand))
                window.setMouseCursor(cursor);
        }
        else{
            if (cursor.loadFromSystem(sf::Cursor::Arrow))
                window.setMouseCursor(cursor);
        }
        if (Mouse::isButtonPressed(Mouse::Left) && IntRect(1000, 20, 62, 60).contains(Mouse::getPosition(window))) {
            window.clear();
            RenderWindow window_rules(VideoMode(1000, 500), "Tetris");
            window_rules.display();
            while (window_rules.isOpen())
            {
                while (window_rules.pollEvent(event_rules))
                {
                    bool i = false;
                    if (event.type == Event::MouseButtonReleased)
                    {
                    }
                    if (event_rules.type == Event::Closed&&i==0)
                        window_rules.close();
                }
            }
        }

        if (Mouse::isButtonPressed(Mouse::Left) && IntRect(450, 400, 214, 90).contains(Mouse::getPosition(window))) {
            window.close();
            //game(window);
        }
        /*/ Создание спрайта

        // Отрисовка спрайта
        s->setup();
        window.draw(*s->get_square());

        // Отрисовка окна?/*/
        window.display();
    }

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
