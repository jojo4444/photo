// gui.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "WindowBase.h"
#include "MainWindow.h"
#include "Errorlog.h"
#include "SFML/Window.hpp"
#include <SFML/Graphics.hpp>

int main()
{

	gui::MainWindow main("Photo", 800, 600);
	main.run();
	return 0;
}

