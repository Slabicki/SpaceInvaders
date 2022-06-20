//
// Created by huber on 31.05.2022.
//

#include "Enemy.h"

using namespace std;

Enemy::Enemy(float xpos, float ypos)
{
    this->Texture();
    this->Sprite();
    enemy.setPosition(xpos, ypos);
    points=1;
}

Enemy::~Enemy()
{

}

void Enemy::Texture()
{
    if(this->enemyTexture.loadFromFile("../Textures/enemy.png") != true)
    {
        cout<<"could not load enemy texture" << endl;
    }
}

void Enemy::Sprite(){
    this->enemy.setTexture(this->enemyTexture);
    this->enemy.scale(0.5f, 0.5f);
}

void Enemy::update(){
    enemy.move(-5.5f, 0.f);
}

sf::FloatRect Enemy::getLimit() const
{
    return enemy.getGlobalBounds();
}

const int& Enemy::getResult() const
{
    return points;
}

void Enemy::render(sf::RenderTarget& target)
{
   target.draw(enemy);
}
