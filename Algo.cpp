#include "Algo.hpp"

int intSquare(int x) {
    return x * x;
}

bool colorCmp(Color& u, Color& v){
    return intSquare(u.r) + intSquare(u.g) + intSquare(u.b) <
           intSquare(v.r) + intSquare(v.g) + intSquare(v.b);
}


Algo::Algo(){
    assignColorsConvertor();
}

Algo::Algo(const Image& first, const Image& second){
    assignColorsConvertor();
    first_ = first;
    second_ = second;
}

void Algo::upload(const Image& first, const Image& second){
    first_ = first;
    second_ = second;
}

vector <Color> Algo::calculate(const Image& T){
    vector <Color> res;

    for (int y = 0; y < T.getSize().y; ++y) {
        for (int x = 0; x < T.getSize().x; ++x) {
            res.push_back(T.getPixel(x, y));
        }
    }

    std::sort(res.begin(), res.end(), colorCmp);
    return res;

}

void Algo::assignColorsConvertor(){
    for (int i = 0; i < 256; ++i){
        vector <vector <int> > tmp1;
        for (int j = 0; j < 256; ++j){
            vector <int> tmp2;
            tmp2.assign(256, 0);
            tmp1.push_back(tmp2);
        }
        convertColors_.push_back(tmp1);
    }
}

Color Algo::findColor(Color u){
    int szSource = firstColors_.size();
    int szFilter = secondColors_.size();
    int it = (long long)convertColors_[u.r][u.g][u.b] * szFilter / szSource;
    return secondColors_[it];
}

Image Algo::getResult(){
    firstColors_ = calculate(first_);
    secondColors_ = calculate(second_);

    int num = 0;
    for (Color& c : firstColors_){
        convertColors_[c.r][c.g][c.b] = num++;
    }

    Image result = first_;
    for (int y = 0; y < first_.getSize().y; ++y) {
        for (int x = 0; x < first_.getSize().x; ++x) {
            Color c = findColor(first_.getPixel(x, y));
            result.setPixel(x, y, c);
        }
    }

    return result;
}
