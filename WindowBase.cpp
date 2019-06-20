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
		ButtonBase Button1("res/osn.png",&window,sf::Vector2f(40,30));
		while (window.isOpen())
		{
			sf::Event event;
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