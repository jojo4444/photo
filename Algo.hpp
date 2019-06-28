#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>

class Algo{
public:
    Algo();
    void upload(const sf::Image& content, const sf::Image& style);
    sf::Image getResult();

private:
    bool isBlack(const sf::Image& img) const;
    sf::Image content_, style_;

};
