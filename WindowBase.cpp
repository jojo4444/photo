#include "WindowBase.h"
#include "SFML/Window.hpp"
#include <SFML/Graphics.hpp>
#include "ButtonBase.h"

namespace gui
{
	WindowBase::WindowBase(const std::string& name) :
		name_(name)
	{}
	void  WindowBase::operator() (uint32 x, uint32 y)
	{
		sf::RenderWindow window(sf::VideoMode(800, 600), name_);
		ButtonBase Button1("res/osnova.png",&window,sf::Vector2f(40,30));
		while (window.isOpen())
		{
			sf::Event event;
			if (Button1.ispushed())
			{
				sf::Window w(sf::VideoMode(600, 300), "test");
				while (w.isOpen())
				{
					while (w.pollEvent(event))
					{
						if (event.type == sf::Event::Closed)
							w.close();
					}
				}
			}
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}
			window.clear(sf::Color::Black);
			Button1.draw();
			window.display();
		}
	}

}