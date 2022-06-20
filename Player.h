
#ifndef MAIN_CPP_PLAYER_H
#define MAIN_CPP_PLAYER_H

#include <iostream>
#include <vector>
#include <sstream>
#include "SFML/Graphics.hpp"
#include "Shoot.h"
#include "Enemy.h"




using namespace std;


class Player {

        sf::Texture shipTexture;
        sf::Sprite ship;

        float shootcooldown;
        float maxshootcooldown;
        int lives;

public:
    Player();
    ~Player();

    void Texture();
    void Sprite();

    int moveLEFT();
    int moveRIGHT();
    int moveUP();
    int moveDOWN();

    const sf::Vector2f& getPosition() const;
    sf::FloatRect getGlobalBounds() const;
    const int&setLive()const;

    void update();
    void setPosition(float x, float y);
    void isAlive(int hits);
    void updateShoot();
    bool canShoot();

    void render(sf::RenderTarget& target);
};


#endif //MAIN_CPP_PLAYER_H
