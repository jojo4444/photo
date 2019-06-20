// gui.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "WindowBase.h"
#include "SFML/Window.hpp"
#include <SFML/Graphics.hpp>

int main()
{
	gui::WindowBase w("win");
	w(1,1);
	return 0;
}

