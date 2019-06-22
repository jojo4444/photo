#include "WindowBase.h"
#include "SFML/Window.hpp"
#include <SFML/Graphics.hpp>
#include "SFML/System.hpp"
#include "ButtonBase.h"

namespace gui
{
	WindowBase::WindowBase(const std::string& name,size_t w, size_t h) 
		:Name(name),H(h),W(w)
	{}
	void WindowBase::makeNewWindowThread(WindowBase& tmp)
	{
		sf::Thread thread((&WindowBase::run),&tmp);
		thread.launch();
		thread.terminate();
	}
	void WindowBase::makeNewWindowThreadAndWait(WindowBase& tmp)
	{
		sf::Thread thread((&WindowBase::run), &tmp);
		thread.launch();
		thread.wait();
	}

}