#include <iostream>
#include "Player.h"
#include "Shoot.h"
#include "SFML/Graphics.hpp"
#include <vector>
#include "Enemy.h"
#include <string>


#ifndef MAIN_CPP_GAMEBOARD_H
#define MAIN_CPP_GAMEBOARD_H

using namespace std;

class GameBoard {

    sf::RenderWindow* window;

    sf::Texture backgroundTexture;
    sf::Sprite background;

    sf::Font font;
    sf::Text Result;
    sf::Text Defeat;

    sf::Texture* textures;
    vector<Shoot*> shoots;

    Player* player;
    Player ship;
    Enemy* enemy;
    vector<Enemy*> enemies;
    float spawnEnemy;
    float spawnEnemyMax;

    //Shoot* shoot;
    sf::RectangleShape shipLive;
    int result;

    void CreateWindow();
    void newPlayer();
    void newShoot();

public:
    GameBoard();
    virtual ~GameBoard();
    void update();
    void render();
    void play();
    void worldSetup();
    void handleEvent();
    void updateShoots();
    void renderShoot();
    void renderEnemy();
    void updateEnemy();
    void updateHit();
    void showResult();
    void uDefeat();
    void Live();
};


#endif //MAIN_CPP_GAMEBOARD_H
