#include "LoadingWindow.h"
#include "LoadingRing.h"
#include "Color.h"

namespace gui
{
	LoadingWindow::LoadingWindow(const std::string& name, size_t w, size_t h) :
		WindowBase(name, w, h)
	{}

	void LoadingWindow::run()
	{
		sf::RenderWindow loading_window(sf::VideoMode(W, H), Name, sf::Style::Close | sf::Style::Titlebar);

		LoadingRing loading_ring("res/loading_ring.png", W/2, H/2);

		while (loading_window.isOpen())
		{
			sf::Event event;
			while (loading_window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					loading_window.close();
			}
			loading_window.clear(BACKGROUND);

			// text of loading
			sf::Font font;
			font.loadFromFile("res/Tahoma.ttf");
			sf::Text text;
			text.setFont(font);
			text.setString("Loading");
			text.setCharacterSize(56);
			text.setPosition(sf::Vector2f(W / 2 - 90, H / 8));
			text.setFillColor(TEXTCOLOR);
			text.setStyle(sf::Text::Bold);
			loading_window.draw(text);

			// loading ring
			loading_window.draw(loading_ring.Sprite());
			loading_ring.Rotate();

			loading_window.display();
		}
	}
}