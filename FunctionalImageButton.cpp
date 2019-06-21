#include "FunctionalImageButton.h"
#include "Errorlog.h"
#include "iostream"
#include "Color.h"

namespace gui
{
	FunctionalImageButton::FunctionalImageButton(const std::string& pathToTextur, sf::RenderWindow* win, sf::Vector2f position):
		WindowBase("search",800,600),ButtonBase(pathToTextur,win,position),released(false)
	{
		NativeSprite = BSprite;
		NativeRect = NativeSprite.getTextureRect();
		NativeTexture = BTexture;
	}
	bool FunctionalImageButton::Realize(const std::string& pathToImage)
	{
		released = loadedImage.loadFromFile(pathToImage);
		ChangeSprite();
		return released;
	}
	bool FunctionalImageButton::Realized()
	{
		return released;
	}
	sf::Image& FunctionalImageButton::getImage()
	{
		released = false;
		return loadedImage;
	}
	void FunctionalImageButton::ChangeSprite()
	{
		if (released)
		{
			BTexture.loadFromImage(loadedImage);
			sf::Vector2f scale = NativeSprite.getScale();
			BSprite.setScale(scale);
			BSprite.setTexture(BTexture);
			BSprite.setPosition(NativeSprite.getPosition());

		}
		else
		{
			BTexture = NativeTexture;
			BSprite.setTexture(BTexture);
			BSprite.setPosition(NativeSprite.getPosition());
		}
	}
	void FunctionalImageButton::move(const sf::Vector2f& newposition)
	{
		BSprite.move(newposition);
		NativeSprite.move(newposition);
	}
	void FunctionalImageButton::run()
	{
		std::string str;
		std::cin >> str;
		Realize(str);

		/*sf::RenderWindow window(sf::VideoMode(W, H/2), Name, sf::Style::Close | sf::Style::Titlebar);
		sf::Font font;
		if (!font.loadFromFile("res/arial.ttf"))
		{
			Errorlog error (W / 2, H / 2,"what");
			makeNewWindowThread(error);
		}
		sf::Text text("", font, 50);
		text.setPosition(W, H / 2);
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
			
				std::string str;
				sf::Text text;
				if (event.type == sf::Event::TextEntered)
				{

					if (event.text.unicode < 128)
					{
						str += static_cast<char>(event.text.unicode);
						text.setString(str);
					}
				}

				if (event.type == sf::Keyboard::Enter)
				{
					Realize(str);
					window.close();
				}
				if (event.type == sf::Event::Closed)
				{
					window.close();
				}
			}
			window.clear(BACKGROUND);
			window.draw(text);
			window.display();
		}*/
	}

	FunctionalImageButton::~FunctionalImageButton()
	{}
}