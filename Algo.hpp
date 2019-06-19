#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>

using namespace sf;
using std::vector;

int intSquare(int x);

bool colorCmp(Color& u, Color& v);

class Algo{
public:
    Algo();
    Algo(const Image& first, const Image& second);
    void upload(const Image& first, const Image& second);
    Image getResult();

private:
    vector <Color> calculate(const Image& T);
    void assignColorsConvertor();
    Color findColor(Color u);

    vector<vector<vector <int> > > convertColors_;
    Image first_, second_;
    vector <Color> firstColors_, secondColors_;
};
