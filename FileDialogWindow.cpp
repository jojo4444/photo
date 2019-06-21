#include "FileDialogWindow.hpp"

FileDialogWindow::FileDialogWindow() {
    //
}

bool FileDialogWindow::loadImage() {
    string wayToFile = OpenDialog(LOAD);
    if (wayToFile == FAILED_UPLOAD) {
        return false;
    }

    return img_.loadFromFile(wayToFile);
}

Image FileDialogWindow::getImage() {
    return img_;
}

bool FileDialogWindow::saveImage(const Image& T) {
    string wayToFile = OpenDialog(SAVE);
    if (wayToFile == FAILED_SAVE) {
        return false;
    }

    return T.saveToFile(wayToFile);
}

string FileDialogWindow::OpenDialog(int status) {
    OPENFILENAME ofn;
    TCHAR sfile[MAX_PATH];

    ZeroMemory(&ofn, sizeof(ofn));
    ZeroMemory(sfile, sizeof(TCHAR)*MAX_PATH);
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

    if (status == LOAD) {
        ofn.lpstrFilter = TEXT("BMP files(*.bmp)\0*.bmp\0PNG files(*.png)\0*.png\0JPEG files(*.jpg)\0*.jpg\0\0");
    }

    char way[MAX_PATH];
    memset(way, 0, sizeof way);
    if (status == LOAD) {
        if(GetOpenFileName(&ofn)) {
            memcpy(way, ofn.lpstrFile, strlen(ofn.lpstrFile));
            return string(way);
        } else {
            return FAILED_UPLOAD;
        }
    } else if (status == SAVE) {
        if(GetSaveFileName(&ofn)) {
            memcpy(way, ofn.lpstrFile, strlen(ofn.lpstrFile));
            return string(way);
        } else {
            return FAILED_SAVE;
        }
    }
}
