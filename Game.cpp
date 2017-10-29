
#include "Game.hpp"

#include "Shop.hpp"

Game::Game(){
    cout << "+ Game loaded" << endl;
    
    srand (time(NULL));

    map = new Map();
    player = new Player(map);
    
    shops = new Shop();
    
    load();
    
}
Game::~Game(){
    cout << "deleting player" << endl;
    delete player;
}

Player& Game::get_player(){
    return  *player;
}

Shop& Game::get_shops(){
    return *shops;
}

Map& Game::get_map(){
    return *map;
}

void Game::load(){
    //fill map..
    //get_map().set(0,  't');
}

void Game::spawn(){
    int num = rand() % 3;
    int x = rand() % get_map().width;
    
    if(!get_map().is_full()){
       while(!get_map().is_open(x)){
           x = rand() % get_map().width;
        }
       if(num == 0){
           get_map().set(x, 't');
       }else if(num == 1){
            get_map().set(x, 'r');

       }else{
           get_map().set(x, 'f');
       }
    }
}

void Game::update(){
    spawn();
}

void Game::render(){
    int pos = get_player().get_pos().get_x();
    get_map().render( pos, 10);
}
