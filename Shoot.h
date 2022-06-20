#ifndef MAIN_CPP_SHOOT_H
#define MAIN_CPP_SHOOT_H

#include <iostream>
#include "SFML/Graphics.hpp"

using namespace std;



class Shoot {
    sf::Sprite shoot;
    //sf::Texture textures;
    sf::Vector2f direction;
    float moveSpeed;
public:
    Shoot(sf::Texture* shootTexture, float xpos, float ypos, float xdir, float ydir, float speed);
    Shoot();
    ~Shoot();
//  void Texture();
//  void Sprite();
    void update();
    sf::FloatRect getLimit()const;
    void render(sf::RenderTarget& target);
};


#endif //MAIN_CPP_SHOOT_H
