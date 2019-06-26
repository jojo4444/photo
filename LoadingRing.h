#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>

namespace gui
{
	class LoadingRing
	{
	public:
		LoadingRing(std::string loading_ring_image_name, int x_pos, int y_pos);
		void Rotate();
		sf::Sprite Sprite();
	private:
		sf::Texture texture_;
		sf::Sprite sprite_;
		bool texture_error_;
	};
}