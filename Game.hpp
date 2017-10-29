#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <iostream>
#include "Player.hpp"
#include "Map.hpp"
#include "Shop.hpp"

using namespace std;


class Game {
private:
    Player* player;
    Map* map;
    Shop* shops;

public:
    
    Game();
    ~Game();
    
    Player& get_player();
    Map& get_map();
    Shop& get_shops();
    
    void spawn();
    
    void update();
    void render();
    void load();
};


#endif /* Game_hpp */
