#ifndef WINDOW_H
#define WINDOW_H
#include <string>
#include "SFML/Window.hpp"
#include <SFML/Graphics.hpp>
#include "SFML/System.hpp"

typedef uint32_t uint32;

namespace gui
{
	class WindowBase
	{
	protected:
		const std::string& Name;
		size_t H;
		size_t W;
	protected:
		void makeNewWindowThread(WindowBase&);
		void makeNewWindowThreadAndWait(WindowBase& tmp);

	public:
		WindowBase(const std::string&,size_t w, size_t h);
		virtual void run() = 0;
		virtual ~WindowBase() = default;
	};
}
#endif //WINDOW_H