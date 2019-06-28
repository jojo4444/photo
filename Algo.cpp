#include "Algo.hpp"

Algo::Algo(){}

void Algo::upload(const sf::Image& content, const sf::Image& style){
    content_ = content;
    style_ = style;
}

sf::Image Algo::getResult(){
    content_.saveToFile("C:/Users/user/Desktop/photo/neural-style-master/content.jpg");
    style_.saveToFile("C:/Users/user/Desktop/photo/neural-style-master/style.jpg");
    std::string tmp = "python C:/Users/user/Desktop/photo/neural-style-master/neural_style.py --network C:/Users/user/Desktop/photo/neural-style-master/imagenet-vgg-verydeep-19.mat --content C:/Users/user/Desktop/photo/neural-style-master/content.jpg --styles C:/Users/user/Desktop/photo/neural-style-master/style.jpg --output C:/Users/user/Desktop/photo/neural-style-master/result.jpg";
    char cmd[tmp.size() + 4];
    memset(cmd, 0, sizeof cmd);

    for (int i = 0; i < tmp.size(); ++i){
        cmd[i] = tmp[i];
    }
    system(cmd);

    sf::Image img;
    while (img.loadFromFile("C:/Users/user/Desktop/photo/neural-style-master/result.jpg") == false || isBlack(img)){
        sf::sleep(sf::seconds(10));
    }

    return img;
}

bool Algo::isBlack(const sf::Image& img) const{
    sf::Color black(0, 0, 0, 255);

    for (int y = 0; y < img.getSize().y; ++y){
        for (int x = 0; x < img.getSize().x; ++x){
            if (img.getPixel(x, y) != black){
                return false;
            }
        }
    }

    return true;
}
