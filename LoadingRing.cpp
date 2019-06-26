#include "LoadingRing.h"

namespace gui
{
	LoadingRing::LoadingRing(std::string loading_ring_image_name, int x_pos, int y_pos)
	{
		texture_error_ = false;
		if (!texture_.loadFromFile(loading_ring_image_name))
		{
			texture_error_ = true;
			return;
		}
		texture_.setSmooth(true);
		sprite_.setTexture(texture_);
		sprite_.setPosition(sf::Vector2f(x_pos, y_pos));

		sprite_.setRotation(0.f);
	}

	void LoadingRing::Rotate()
	{
		if (!texture_error_)
			sprite_.rotate(-1.f);
	}

	sf::Sprite LoadingRing::Sprite()
	{
		if (!texture_error_)
			return sprite_;
		else
		{
			sf::Sprite empty_sprite;
			return empty_sprite;
		}
	}
}