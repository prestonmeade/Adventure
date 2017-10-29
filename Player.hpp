#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <iostream>
#include "Skills.hpp"
#include "Map.hpp"
#include "Position.hpp"
#include <stdio.h>
#include <string.h>
#include <cstring>

#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <sstream>
#include <cstdlib>
#include "Inventory.hpp"


using namespace std;

class Player{
private:
    
    string username;
    int hp;
    int coins;
    
    Skills*  skills;
    Position* pos;
    Map* map;
    
    Inventory* invo;
    

public:
    
    int x,y;
    
    bool in_shop;
    bool in_store_buying;
    
    
    Player(Map* m);
    
    string get_username();
    void set_username(string new_username);
    
    
    int get_x();
    int get_y();
    
    void set_x(int n_x);
    void set_y(int n_y);
    
    //invo
    Inventory& get_invo();
    
    //stats
    string get_stats();
    
    //coins
    void set_coins(int coins);
    int get_coins();
    
    //methods with health/alive/combat
    bool is_alive();
    void take_damage(int damage);
    int get_hp();
    
    //methods that edit skills
    void add_xp(string skill_name, int xp);
    int get_xp(string skill_name);
    
    //methods that edit position
    void move(int x);
    
    //actions
    bool cut_tree(int tile_x);
    bool mine_rock(int tile_x);
    bool fish(int tile_x);
    bool next_to(char s);
    bool next_to(int index);
    bool shop(int tile_x);
    bool buy_shop(int tile_x);
    
    
    
    
    Position& get_pos();
    Skills& get_skills();

};

#endif /* Player_hpp */
