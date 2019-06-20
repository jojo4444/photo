#ifndef WINDOW_H
#define WINDOW_H
#include <string>
#include "SFML/Window.hpp"

typedef uint32_t uint32;

namespace gui
{
	class WindowBase
	{
	private:
		const std::string& name_;
	public:
		WindowBase(const std::string&);
		virtual void operator()(uint32 x, uint32 y);
		virtual ~WindowBase() = default;
	};
}
#endif //WINDOW_H