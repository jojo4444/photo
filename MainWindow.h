#ifndef MAINWINDOW
#define MAINWINDOW

#include "WindowBase.h"
namespace gui
{
	class MainWindow :
		public WindowBase
	{
	public:
		MainWindow(const std::string& name, size_t w, size_t h);
		void run() override;
		virtual ~MainWindow();
	};
}
#endif // MAINWINDOW