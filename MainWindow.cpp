#include "MainWindow.h"
#include "FunctionalImageButton.h"
#include "ButtonBase.h"
#include "Errorlog.h"
#include "Color.h"
#include "Algo.hpp"
#include "LoadingWindow.h"


namespace gui
{
	MainWindow::MainWindow(const std::string& name, size_t w, size_t h):
		WindowBase(name,w,h)
	{}
	void MainWindow::run()
	{
		sf::RenderWindow main(sf::VideoMode(W, H), Name, sf::Style::Close | sf::Style::Titlebar);

		ButtonBase Merge(std::string("res/sliyanie1.png"),&main,sf::Vector2f(W/2,H*3/4));
		Merge.moveCent();
		FunctionalImageButton found(std::string("res/osnova.png"), &main, sf::Vector2f(W / 4, H / 7));
		found.moveCent();
		FunctionalImageButton filter(std::string("res/filter.png"), &main, sf::Vector2f(W * 3 / 4, H / 7));
		filter.moveCent();
		Algo tmp;
		while (main.isOpen())
		{
			sf::Event event;
			if (Merge.ispushed())
			{
				if (found.Realized() && filter.Realized())
				{
					tmp.upload(found.getImage(),filter.getImage());
					sf::Image result = tmp.getResult();
					sf::Texture Texture;
					Texture.loadFromImage(result);
					sf::Sprite Sp;
					Sp.setTexture(Texture);
					sf::RenderWindow resultWin(sf::VideoMode(result.getSize().x, result.getSize().y), "Result", sf::Style::Close);
					while (resultWin.isOpen())
					{
						while (resultWin.pollEvent(event))
						{
							if (event.type == sf::Event::Closed)
								resultWin.close();
						}
						resultWin.clear(BACKGROUND);
						resultWin.draw(Sp);
						resultWin.display();
					}

				}
				else
				{
					LoadingWindow loading_window("Loading", W, H);
					loading_window.run();
				}
			}
			if (found.ispushed())
			{
				found.run();
			}
			if (filter.ispushed())
			{
				filter.run();
			}
			while (main.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					main.close();
			}
			main.clear(BACKGROUND);
			filter.draw();
			found.draw();
			Merge.draw();
			main.display();
		}
	}
	MainWindow::~MainWindow()
	{
	}
}