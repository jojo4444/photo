#pragma once

#include <windows.h>
#include <string>
#include <cstring>
#include <SFML/Graphics.hpp>

#define IDM_FILE_NEW 1

using sf::Image;
using std::string;

const string FAILED_UPLOAD = "failUpload";
const string FAILED_SAVE = "failSave";

const int LOAD = 1;
const int SAVE = 2;

class FileDialogWindow {
public:
    FileDialogWindow();
    bool loadImage();
    bool saveImage(const Image& T);
    Image getImage();
private:
    string OpenDialog(int status);

    Image img_;
};
