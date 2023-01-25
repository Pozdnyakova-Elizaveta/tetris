#pragma once
#include "Base_window.h"
#include "Shapes.h"
class Game :public Base_window //класс игрового окна
{
private:
	Texture grid;
	Sprite s_grid;//игровое поле
	Sprite s_grid_next_shapes;//поле для изображения следующей фигуры
	Font font;//шрифт для надписей
	Texture button_main_menu;//кнопка выхода в главное меню
	Sprite s_button_main_menu;
	int score;//счет игры
	//Shapes s7;
public:
	Game();
	void functioning();
};

