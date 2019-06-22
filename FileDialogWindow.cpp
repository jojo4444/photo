#include "FileDialogWindow.hpp"
#include <windows.h>

namespace gui
{
	FileDialogWindow::FileDialogWindow() {

	}

	std::string FileDialogWindow::loadImage() {
		std::wstring wayToFile = OpenDialog(LOAD);
		return std::string(wayToFile.begin(), wayToFile.end());
	}


	std::string FileDialogWindow::saveImage() {
		std::wstring wayToFile = OpenDialog(SAVE);
		return std::string(wayToFile.begin(), wayToFile.end());
	}

	std::wstring FileDialogWindow::OpenDialog(status stat) {
		OPENFILENAME ofn;
		TCHAR sfile[MAX_PATH];

		ZeroMemory(&ofn, sizeof(ofn));
		ZeroMemory(sfile, sizeof(TCHAR) * MAX_PATH);
		ofn.lStructSize = sizeof(ofn);
		ofn.hwndOwner = NULL;
		ofn.lpstrFile = sfile;
		ofn.nMaxFile = MAX_PATH;
		ofn.lpstrFilter = NULL;
		ofn.nFilterIndex = 1;
		ofn.lpstrTitle = TEXT("Please Select a File");
		ofn.lpstrInitialDir = NULL;
		ofn.lpstrCustomFilter = NULL;
		ofn.nMaxCustFilter = 0;
		ofn.lpstrFileTitle = NULL;
		ofn.nMaxFileTitle = 0;
		ofn.nFileOffset = 0;
		ofn.nFileExtension = 0;
		ofn.lpstrDefExt = NULL;
		ofn.lCustData = 0;
		ofn.lpfnHook = 0;
		ofn.lpTemplateName = 0;
		ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;

		if (stat == LOAD) {
			ofn.lpstrFilter = TEXT("ALL files(*)\0*\0BMP files(*.bmp)\0*.bmp\0PNG files(*.png)\0*.png\0JPEG files(*.jpg)\0*.jpg\0\0");
		}

		char way[MAX_PATH];
		memset(way, 0, sizeof way);
		if (stat == LOAD) {
			if (GetOpenFileName(&ofn)) {
				return std::wstring(ofn.lpstrFile);
			}
			else {
				return WFAILED_UPLOAD;
			}
		}
		else if (stat == SAVE) {
			if (GetSaveFileName(&ofn))

				return std::wstring(ofn.lpstrFile);
		}
		else {
			return WFAILED_SAVE;
		}
	}
}