#include "Shoot.h"
#include <iostream>
#include "SFML/Graphics.hpp"

using namespace std;

Shoot::Shoot()
{

}

Shoot::Shoot(sf::Texture* shootTexture, float xpos, float ypos, float xdir, float ydir, float speed)
{
    shoot.setTexture(*shootTexture);
    shoot.setScale(0.8f,0.8f);
    this->direction.x = xdir;
    this->direction.y = ydir;
    this->moveSpeed = speed;
    shoot.setPosition(xpos, ypos);
}

Shoot::~Shoot()
{

}

void Shoot::update() // aktualizacja strzału
{
    shoot.move(this->moveSpeed * this->direction);
}

sf::FloatRect Shoot::getLimit() const
{
    return shoot.getGlobalBounds();
}

void Shoot::render(sf::RenderTarget& target)
{
    target.draw(shoot);
}