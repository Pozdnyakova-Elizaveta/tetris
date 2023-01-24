#include "Rules.h"
#include "menu.h"

Rules::Rules() :Base_window() {
    font.loadFromFile("files\\font_game.ttf");
    button_main_menu.loadFromFile("files\\menu.png");//��������� ����������� ������ ������ � ������� ����
    s_button_main_menu.setTexture(button_main_menu);
    s_button_main_menu.setScale(0.4f, 0.4f);
}
void Rules::functioning() {
    RenderWindow window(VideoMode(length, width), "Tetris");
    //Text rules("������ ���� ������ ������ ������ ������ � ����. ������ ����� ������� �� ����������� �������� �� ���������� ������� ������ � �����, ������� ����� �������� ������ �� ������� �������,\n ������� ���� - ������ �������. ����� Enter, ������ ����� �������� � ������� ������ ���������. ��� ��������� �� �����, ���� �������� ������ ����������, ������ ������� � ��������� ��������� ���������. ������ ������ �������� ������ � ��������� ����������� ���. � ����� ������ ��� �������� � ����� �������� �����. ����� ���� ��� ����� ������� ���� ���, ��  �������� 10 ������, �� ��� ���� - 30, �� ��� - 60. ����� ������� ����� � ������� ���� �����������, ���������� ���� � ������� ����� � ������� 2 ������ � ����������� �� 0.5 �������. \n\n\n������������ ���� - �������� ������, ���������� ���������", font, 26);

    while (window.isOpen())
    {
        Event event;
        Cursor cursor;
        Text rules(L"������ ���� ������ ������ ������ ������ � ����. ������ ����� \n������� �� ����������� �������� �� ���������� ������� ������ � \n�����, ������� ����� �������� ������ �� ������� �������,\n������� ���� - ������ �������. ����� Enter, ������ ����� �������� �\n������� ������ ���������. ��� ��������� �� �����, ���� �������� \n������ ����������, ������ ������� � ��������� ��������� \n���������. ������ ������ �������� ������ � ��������� ����������� \n���. � ����� ������ ��� �������� � ����� �������� �����. ����� ���� \n��� ����� ������� ���� ���, ��  �������� 10 ������, �� ��� ���� - 30, \n�� ��� - 60. ����� ������� ����� � ������� ���� �����������, \n���������� ���� � ������� ����� � ������� 2 ������ � �����������\n �� 0.5 �������. \n\n\n\n\n\n\n\n������������ ���� - �������� ������, ���������� ���������", font, 18);
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
                if (event.mouseMove.x >= 770 && event.mouseMove.x <= 852 && event.mouseMove.y >= 680 && event.mouseMove.y <= 760) {//������ ������� �� ������ - ����������� ������� �������� �� ����
                    if (cursor.loadFromSystem(sf::Cursor::Hand))
                        window.setMouseCursor(cursor);
                }
                else {//����� ������ - �������
                    if (cursor.loadFromSystem(sf::Cursor::Arrow))
                        window.setMouseCursor(cursor);
                }
            }
            if (event.type == event.MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
                if (IntRect(770, 680, 82, 80).contains(Mouse::getPosition(window))) {//���� ���� ������ ��� � ������� ������ ������ � ������� ���� - �������� ����, �������� ���� ����
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
