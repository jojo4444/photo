#pragma once

#include <string>
#include <cstring>
#include <SFML/Graphics.hpp>

#define IDM_FILE_NEW 1
namespace gui
{
	const std::wstring WFAILED_UPLOAD = L"failUpload";
	const std::wstring WFAILED_SAVE = L"failSave";
	const std::string FAILED_UPLOAD = "failUpload";
	const std::string FAILED_SAVE = "failSave";

	class FileDialogWindow {
	public:
		enum status { LOAD, SAVE };
	public:
		FileDialogWindow();
		std::string loadImage();
		std::string saveImage();
	private:
		std::wstring OpenDialog(status);
	};
}
