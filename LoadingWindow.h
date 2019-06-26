#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include "WindowBase.h"

namespace gui
{
	class LoadingWindow : public WindowBase
	{
	public:
		LoadingWindow(const std::string& name, size_t w, size_t h);
		void run();
	};
}
