#include "GameBoard.h"
#include <iostream>
#include "SFML/Graphics.hpp"



using namespace std;

void GameBoard::CreateWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(1200, 800), "Space-Invaders", sf::Style::Close);
    this->window->setFramerateLimit(144);
    this->window->setVerticalSyncEnabled(false);
}

void GameBoard::newShoot()
{
    textures=new sf::Texture();
    textures->loadFromFile("../Textures/shoot.png");
}

void GameBoard::newPlayer()
{

    player=new Player();
    enemy=new Enemy(1500.f, 1500.f);
    spawnEnemyMax=40.f;
    spawnEnemy=spawnEnemyMax;
}

GameBoard::GameBoard()
{

    CreateWindow();
    newPlayer();
    newShoot();
    worldSetup();
    result=0;

    font.loadFromFile("../Textures/Montserrat-Light.ttf");

    Result.setFont(font);
    Result.setCharacterSize(30);
    Result.setFillColor(sf::Color::White);

    Defeat.setFont(font);
    Defeat.setCharacterSize(40);
    Defeat.setFillColor(sf::Color::Red);

    shipLive.setSize(sf::Vector2f(150.f, 25.f));
    shipLive.setFillColor(sf::Color::Red);
    shipLive.setPosition(sf::Vector2f(18.f, 50.f));
}

GameBoard::~GameBoard()
{
   delete this->window;
   delete this->player;
}


void GameBoard::play()
{
    while(this->window->isOpen())
    {
        this->update();

        if(ship.setLive()>0) {
            this->handleEvent();
            this->updateShoots();
            this->updateEnemy();
            this->updateHit();
            this->Live();
            this->render();
        }
    }
}

void GameBoard::update()
{
    sf::Event event;
    while (this->window->pollEvent(event))
    {
        if (event.Event::type == sf::Event::Closed)
            this->window->close();
        if (event.Event::KeyPressed && event.Event::key.code == sf::Keyboard::Escape)
            this->window->close();
    }
}

void GameBoard::updateShoots()
{
    for (auto *shoot : shoots)
    {
        shoot->update();
        if (shoot->getLimit().width > window->getSize().x)
        {
            shoots.erase(shoots.begin());
        }
    }
  player->update();
}

void GameBoard::updateEnemy()
{
    spawnEnemy +=1.4f;
    if(spawnEnemy >=spawnEnemyMax)
    {
        enemies.push_back(new Enemy(window->getSize().x, rand() % window->getSize().y-25.f));
        spawnEnemy=0.f;
    }

   for (int i=0; i<enemies.size(); i++)
   {
       enemies[i]->update();
       if(enemies[i]->getLimit().left <0)
       {
           ship.isAlive(1);
           cout<<ship.setLive();
           enemies.erase(enemies.begin() +i);
           break;
       }
       else if(enemies[i]->getLimit().intersects(ship.getGlobalBounds()))
       {
           ship.isAlive(1);
           cout<<ship.setLive();
           enemies.erase(enemies.begin() + i);
           break;
       }
   }
}
void GameBoard::updateHit()
{
 for(int i=0; i<enemies.size(); i++)
 {
     for (int j=0; j<shoots.size(); j++)
     {
        if(shoots[j]->getLimit().intersects(enemies[i]->getLimit())) {
                result += enemies[i]->getResult();
                shoots.erase(shoots.begin()+j);
                enemies.erase(enemies.begin()+i);
                break;
             }
        }
    }
}

void GameBoard::worldSetup()
{

    if (backgroundTexture.loadFromFile("../Textures/background5.jpg") != true)
    {
        cout<<"could not load world texture" << endl;
    }
    background.setTexture(backgroundTexture);

    window->draw(background);
}

void GameBoard::handleEvent() {
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            ship.moveLEFT();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            ship.moveRIGHT();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            ship.moveUP();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            ship.moveDOWN();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && player->canShoot()) {
            shoots.push_back(new Shoot(textures,
                                       ship.getPosition().x + player->getGlobalBounds().width,
                                       ship.getPosition().y+25,
                                       1.f, 0.f, 8.5f));
        }
        if (ship.getPosition().x <= 0)
        {
            ship.setPosition(0.f, ship.getPosition().y);
        }
        if (ship.getPosition().x >= window->getSize().x - ship.getGlobalBounds().width)
        {
            ship.setPosition(window->getSize().x - ship.getGlobalBounds().width, ship.getPosition().y);
        }
        if (ship.getPosition().y <= 0)
        {
            ship.setPosition(ship.getPosition().x, 0.f);
        }
  		if (ship.getPosition().y >= window->getSize().y - ship.getGlobalBounds().height)
        {
            ship.setPosition(ship.getPosition().x, window->getSize().y - ship.getGlobalBounds().height);
        }
    }
}

void GameBoard::uDefeat()
{
    if (ship.setLive() <= 0)
    {
        Defeat.setPosition(300.f, 350.f);
        Defeat.setString("DEFEAT, THE SHIP LOST ALL LIVES!");
        window->draw(Defeat);
    }
}

void GameBoard::showResult()
{
    stringstream ssResult;
    ssResult<<"Result:"<<result;
    Result.setPosition(10.f,10.f);
    Result.setString(ssResult.str());
    window->draw(Result);

}
void GameBoard::Live()
{
    shipLive.setSize(sf::Vector2f((float)ship.setLive()*15.f, 25.f));
    window->draw(shipLive);
}

void GameBoard::renderShoot()
{
    for (auto *shoot : shoots)
    {
        shoot->render(*window);
    }
}

void GameBoard::renderEnemy()
{
    for (auto *enemy : enemies)
    {
        enemy->render(*window);
    }
}

void GameBoard::render()
{

    this->window->clear();
    this->worldSetup();
    this->ship.render(*window);
    this->enemy->render(*window);
    this->renderShoot();
    this->renderEnemy();
    this->showResult();
    this->Live();
    this->uDefeat();
    this->window->display();
}