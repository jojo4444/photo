#include "ButtonBase.h"


namespace gui
{
	ButtonBase::ButtonBase(const std::string& pathToTexture, sf::RenderWindow* win,sf::Vector2f position)
		:window(win)
	{
		if (!BTexture.loadFromFile(pathToTexture))
		{
			throw std::exception("Cant open textures!");
		}
		BSprite.setTexture(BTexture);
		BSprite.setPosition(position);
	}

	void ButtonBase::draw()
	{
		window->draw(BSprite);
	}
	ButtonBase::~ButtonBase()
	{
	}
}