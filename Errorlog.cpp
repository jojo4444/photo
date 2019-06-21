#include "Errorlog.h"
#include "ButtonBase.h"
#include "SFML/Window.hpp"
#include <SFML/Graphics.hpp>
#include "SFML/System.hpp"
#include "Color.h"

namespace gui
{
	Errorlog::Errorlog(size_t h, size_t l, const std::string& what):
		WindowBase("Error",h,l)
	{
		text.setString(what);
		font.loadFromFile("res/Tahoma.ttf");
		text.setFont(font);
		text.setCharacterSize(h * l / 100);
		text.setFillColor(sf::Color::Black);
		text.setStyle(sf::Text::Regular);
		text.setPosition(sf::Vector2f(W / 4, H / 4));
	}
	void Errorlog::run()
	{
		sf::RenderWindow window(sf::VideoMode(W, H), Name, sf::Style::Titlebar);
		ButtonBase OkB("res/ok.png", &window, sf::Vector2f(W / 2, H *3/4));
		sf::Vector2f size(OkB.size());
		size.x /= 2;
		size.x = -size.x;
		size.y = 0;
		OkB.move(size);
		while (window.isOpen())
		{
			
			if (OkB.ispushed())
				window.close();
			window.clear(BACKGROUND);
			OkB.draw();
			window.draw(text);
			window.display();
		}
	}
	Errorlog::~Errorlog()
	{}
}