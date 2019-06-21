#ifndef WINDOWBASE
#define WINDOWBASE

#include "WindowBase.h"
#include "SFML/Window.hpp"
#include <SFML/Graphics.hpp>
#include "SFML/System.hpp"
namespace gui
{
	class Errorlog :
		public WindowBase
	{
	protected:
		sf::Text text;
		sf::Font font;
	public:
		Errorlog(size_t w, size_t h, const std::string& what);
		void run() override;
		virtual ~Errorlog();
	};
}
#endif // !WINDOWBASE