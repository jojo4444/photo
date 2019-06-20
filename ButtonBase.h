#ifndef BUTTONBASE_H
#define BUTTONBASE_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
namespace gui
{
	class ButtonBase
	{
	protected:
		sf::Texture BTexture;
		sf::Sprite BSprite;
		sf::Font Bfont;
		sf::Text BText;
		sf::Cursor BCur;
		sf::RenderWindow* window;
		sf::Vector2f position;

	public:
		ButtonBase(const std::string& pathToTextur,sf::RenderWindow* win, sf::Vector2f position);
		void draw();
		void move(const sf::Vector2f&);
		void update(const std::string&);
		bool ispushed();
		~ButtonBase();
	};
} //gui
#endif //BUTTONBASE_H