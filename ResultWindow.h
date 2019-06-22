#pragma once
#include "WindowBase.h"
namespace gui
{
	class ResultWindow :
		public WindowBase
	{
	public:
		ResultWindow();
		void run() override;
		virtual ~ResultWindow();
	};

}