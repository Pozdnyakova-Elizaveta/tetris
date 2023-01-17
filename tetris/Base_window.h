#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Base_window //абстрактный класс создания общего окна
{
protected:
	int length; //размер окна
	int width;
	Texture background; //фон окна
	Sprite s_background;
public:
	Base_window();
	~Base_window();
	virtual void functioning() = 0;

};

