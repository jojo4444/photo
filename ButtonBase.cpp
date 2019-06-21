#include "ButtonBase.h"

namespace gui
{
	ButtonBase::ButtonBase(const std::string& pathToTexture, sf::RenderWindow* win,sf::Vector2f position)
		:Window(win)
	{
		BTexture.loadFromFile(pathToTexture);
		BSprite.setTexture(BTexture);
		BSprite.setPosition(position);
	}
	sf::Vector2i ButtonBase::size()
	{
		sf::IntRect Rect = BSprite.getTextureRect();
		return sf::Vector2i(Rect.width - Rect.left, Rect.height - Rect.top);
	}
	void ButtonBase::draw()
	{
		Window->draw(BSprite);
	}
	bool ButtonBase::containsCursorButton()
	{
		sf::Vector2i cursor(sf::Mouse::getPosition(*Window));
		sf::Vector2f wcursor = (Window->mapPixelToCoords(cursor));
		if (BSprite.getGlobalBounds().contains(wcursor))
			return true;
		else
			return false;
	}
	
	bool ButtonBase::ButtonPressed()
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			return true;
		else
			return false;
	}
	bool ButtonBase::ispushed()
	{
		if (containsCursorButton() && ButtonPressed())
			return true;
		else
			return false;
	}
	void ButtonBase::move(const sf::Vector2f& newposition)
	{
		BSprite.move(newposition);
	}
	void ButtonBase::update(const std::string& file)
	{

	}
	void ButtonBase::moveCent()
	{
		sf::Vector2f Position(size());
		Position.x /= (-2);
		Position.y = 0;
		move(Position);
	}
	ButtonBase::~ButtonBase()
	{}
}