//
// Created by huber on 31.05.2022.
//

#ifndef MAIN_CPP_ENEMY_H
#define MAIN_CPP_ENEMY_H

#include <iostream>
#include "SFML/Graphics.hpp"


using namespace std;

class Enemy {
    sf::Texture enemyTexture;
    sf::Sprite enemy;
    int points;
public:
    Enemy(float xpos, float ypos);
    ~Enemy();
    void Texture();
    void Sprite();
    void update();
    sf::FloatRect getLimit() const;
    const int &getResult() const;
    void render(sf::RenderTarget& target);
};


#endif //MAIN_CPP_ENEMY_H
