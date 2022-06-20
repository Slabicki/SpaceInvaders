#include "Player.h"
#include <iostream>
#include "SFML/Graphics.hpp"

using namespace std;



Player::Player()
{
    this->Texture();
    this->Sprite();
    lives=7;
    maxshootcooldown=20.f;
    shootcooldown=maxshootcooldown;

}

Player::~Player()
{
}

void Player::Texture() // wczytanie tekstury
{
   if(this->shipTexture.loadFromFile("../Textures/ship.png") != true)
    {
       cout<<"could not load ship texture" << endl;
    }
}

void Player::Sprite()
{
    this->ship.setTexture(this->shipTexture);
    this->ship.scale(0.55f, 0.55f);
    this->ship.setPosition(0.f,300.f);
}
int Player::moveLEFT()
{
    ship.move(-5.0f, 0.f);
}

int Player::moveRIGHT()
{
    ship.move(5.0f, 0.f);
}

int Player::moveUP()
{
    ship.move(0.f, -5.0f);
}

int Player::moveDOWN()
{
    ship.move(0.f, 5.0f);
}

void Player::setPosition(float x, float y)
{
    ship.setPosition(x,y);
}

const sf::Vector2f & Player::getPosition() const
{
    return ship.getPosition();
}

sf::FloatRect Player::getGlobalBounds() const
{
    return ship.getGlobalBounds();
}

void Player::update()
{
    updateShoot();
}

bool Player::canShoot()
{
    if(shootcooldown>=maxshootcooldown)
    {
        shootcooldown=2.f;
        return true;
    }
  return false;
}
void Player::updateShoot()
{
    if(shootcooldown<maxshootcooldown)
        shootcooldown += 0.8f;
}

const int & Player::setLive() const
{
    return lives;
}

void Player::isAlive(int hits)
{
    lives -= hits;
    if (lives <= 0) {
        lives = 0;
    }
}

void Player::render(sf::RenderTarget& target)
{
    target.draw(ship);
}




