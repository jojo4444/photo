#include "WindowBase.h"
#include "SFML/Window.hpp"
#include <SFML/Graphics.hpp>
#include "SFML/System.hpp"
#include "ButtonBase.h"

namespace gui
{
	WindowBase::WindowBase(const std::string& name,size_t w, size_t h) 
		:Name(name),H(h),W(w)
	{}
	void WindowBase::makeNewWindowThread(WindowBase& tmp)
	{
		sf::Thread thread((&WindowBase::run),&tmp);
		thread.launch();
	}
	void WindowBase::makeNewWindowThreadAndWait(WindowBase& tmp)
	{
		sf::Thread thread((&WindowBase::run), &tmp);
		thread.launch();
		thread.wait();
	}
	/*void  WindowBase::operator() ()
	{
		sf::RenderWindow window(sf::VideoMode(High, Length), Name);
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
	}*/

}