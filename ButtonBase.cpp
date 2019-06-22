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
		{
			BSprite.setColor(sf::Color(180, 180, 234, 254));
			return true;
		}
		else
		{
			BSprite.setColor(sf::Color(255,255,255,255));
			return false;
		}
	}
	
	bool ButtonBase::ButtonPressed()
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			return true;
		else
			return false;
	}
	bool ButtonBase::Focused()
	{
		sf::Event event;
		while (Window->pollEvent(event))
		{
			if (event.type == sf::Event::GainedFocus)
				return true;
			else
				return false;
		}
	}
	bool ButtonBase::ispushed()
	{
		if (containsCursorButton() && ButtonPressed() && Window->hasFocus())
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