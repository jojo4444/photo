#ifndef FIB
#define FIB
#include "ButtonBase.h"
#include "WindowBase.h"
#include "SFML/Graphics.hpp"

namespace gui
{
	class FunctionalImageButton :
		public ButtonBase , public WindowBase
	{
	protected:
		sf::IntRect NativeRect;
		sf::Sprite NativeSprite;
		sf::Texture NativeTexture;
		sf::Image loadedImage;
		bool released;
		bool Realize(const std::string& pathToImage);
		void ChangeSprite();
	public:
		FunctionalImageButton(const std::string& pathToTextur, sf::RenderWindow* win, sf::Vector2f position);
		void run() override;
		virtual void move(const sf::Vector2f&) override;
		bool Realized();
		sf::Image& getImage();
		virtual ~FunctionalImageButton();
	};
}
#endif // !FIB