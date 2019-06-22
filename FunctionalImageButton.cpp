#include "FunctionalImageButton.h"
#include "Errorlog.h"
#include "FileDialogWindow.hpp"
#include "Color.h"

namespace gui
{
	FunctionalImageButton::FunctionalImageButton(const std::string& pathToTextur, sf::RenderWindow* win, sf::Vector2f position):
		WindowBase("search",800,600),ButtonBase(pathToTextur,win,position),released(false)
	{
		NativeSprite = BSprite;
		NativeRect = NativeSprite.getTextureRect();
		NativeTexture = BTexture;
	}
	bool FunctionalImageButton::Realize(const std::string& pathToImage)
	{
		released = loadedImage.loadFromFile(pathToImage);
		ChangeSprite();
		return released;
	}
	bool FunctionalImageButton::Realized()
	{
		return released;
	}
	sf::Image& FunctionalImageButton::getImage()
	{
		return loadedImage;
	}
	void FunctionalImageButton::ChangeSprite()
	{
		if (released)
		{
			BTexture.loadFromImage(loadedImage);
			sf::Vector2f scale = NativeSprite.getScale();
			BSprite.setScale(scale);
			BSprite.setTexture(BTexture);
			BSprite.setPosition(NativeSprite.getPosition());

		}
		else
		{
			BTexture = NativeTexture;
			BSprite.setTexture(BTexture);
			BSprite.setPosition(NativeSprite.getPosition());
		}
	}
	void FunctionalImageButton::move(const sf::Vector2f& newposition)
	{
		BSprite.move(newposition);
		NativeSprite.move(newposition);
	}
	void FunctionalImageButton::run()
	{
		std::string str;
		FileDialogWindow reader;
		str = reader.loadImage();
		if (str == FAILED_UPLOAD)
			return;
		Realize(str);
	}

	FunctionalImageButton::~FunctionalImageButton()
	{}
}