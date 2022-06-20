#include <iostream>
#include "SFML/Graphics.hpp"
#include "GameBoard.h"
#include "Player.h"
#include "Shoot.h"
#include "Enemy.h"
#include "time.h"


using namespace std;



int main() {
    srand(time(NULL));
    GameBoard game;
    game.play();
    return 0;
}
