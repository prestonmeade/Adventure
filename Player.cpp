//
//  Player.cpp
//  adventuree
//
//  Created by Preston Meade on 10/27/17.
//  Copyright © 2017 com.preston.xc. All rights reserved.
//

#include "Player.hpp"
#include <stdio.h>
#include <string.h>
#include <cstring>


Player::Player(Map* m){
    this->username = "preston";
    cout << "Player()" << endl;
    coins = 0;
    
    hp = 10;
    map = m;
    pos = new Position();
    get_pos().set_x(1);
    skills = new Skills();
    invo = new Inventory();
    
}

string Player::get_username(){
    return username;
}

void Player::set_username(string new_username){
    this->username = new_username;
}

Skills& Player::get_skills(){
    return *skills;
}

Inventory& Player::get_invo(){
    return *invo;
}

int Player::get_y(){
    return y;
}

int Player::get_x(){
    return x;
}

void Player::set_x(int n_x){
    x = n_x;
}

void Player::set_y(int n_y){
    y = n_y;
}

bool Player::is_alive(){
    return (hp > 0);
}


void Player::set_coins(int coins){
    this->coins = coins;
}

int Player::get_coins(){
    return coins;
}

void Player::take_damage(int damage){
    hp -= damage;
    cout << "player takes " << damage << " damage! hp: " << hp << endl;
}

int Player::get_hp(){
    return hp;
}


Position& Player::get_pos(){
    return *pos;
}

void Player::move(int x){
    if(in_shop){
        in_shop = false;
    }
    if(in_store_buying){
        in_store_buying = false;
    }
    if(get_pos().get_x() + x > 0 && get_pos().get_x() + x < map->width - 1 ){
        get_pos().set_x(get_pos().get_x() + x);
        get_pos().set_direction(x);
    }
}

string Player::get_stats(){
    stringstream ss;
    for(int i = 0; i < get_skills().skills.size(); i++){
        string name = get_skills().skills.at(i).name;
        
        ss << get_skills().get_skill(i).name << ": "
        <<  get_skills().get_skill(i).get_xp() << "\tlvl: " << get_skills().calc_lvl(name)  << '\n';
    }
    return ss.str();
}

bool Player::cut_tree(int tile_x){
    bool cut = false;
    
    if(next_to(tile_x)){
            
            if(get_invo().cur_tool.name == ("axe")){
                add_xp("wc", 5);
                cut = true;
                cout << "cut tree: ";
                cout << get_xp("wc") << endl;
           
                map->map[tile_x] = '*';
                get_invo().add_item(Item("log", 5));
            }else{
                cout << "You need an axe" << endl;
            }
           
        }else{
            cout << "You are too far away" << endl;
        }
    
    return cut;
}


bool Player::buy_shop(int tile_x){
    bool shop = false;
    
    if(next_to(tile_x)){
        
        //if(get_invo().cur_tool.name == ("fishing_pole")){
        
        in_store_buying = !in_store_buying;
        shop = true;
        
    }else{
        cout << "You are too far away" << endl;
    }
    return shop;
}

bool Player::shop(int tile_x){
    bool shop = false;
    
    if(next_to(tile_x)){
        
        //if(get_invo().cur_tool.name == ("fishing_pole")){
            
        in_shop = !in_shop;
            shop = true;
        
        
       
    }else{
        cout << "You are too far away" << endl;
    }
    return shop;
}

bool Player::fish(int tile_x){
    bool fish = false;

    if(next_to(tile_x)){
        
        if(get_invo().cur_tool.name == ("fishing_pole")){
        
        add_xp("fish", 2);
        fish = true;
        cout << "fished shark: ";
        cout << get_xp("fish") << endl;
            get_invo().add_item(Item("shark", 25));

        map->map[tile_x] = '*';

        }else{
            cout << "You need a fishing pole" << endl;
        }
    }else{
        cout << "You are too far away" << endl;
    }
    return fish;
}

bool Player::mine_rock(int tile_x){
    bool mine = false;
        if(next_to(tile_x)){
            if(get_invo().cur_tool.name == ("pickaxe")){

            add_xp("mine", 2);
            mine = true;
            cout << "mine rock: ";
            cout << get_xp("mine") << endl;
                get_invo().add_item(Item("iron_ore",12));

            map->map[tile_x] = '*';
            }else{
                cout << "You need a pickaxe" << endl;
            }
        }else{
            cout << "You are too far away" << endl;
        }
    return mine;
}



bool Player::next_to(int x){
    int player_x = get_pos().get_x();
    
    if(player_x == x -1 || player_x == x || player_x == x + 1){
        return true;
    }
    return false;
}

bool Player::next_to(char s){
    int x = get_pos().get_x();
    if(x < map->width && map->map[x + 1] == s){
        return true;
    }else if(x > 0 && map->map[x - 1] == s){
        return true;
    }else if(x >= 0 && map->map[x] == s){
        return true;
    }
    return false;
}

void Player::add_xp(string skill_name, int xp){
    get_skills().add_xp(skill_name, xp);
}

int Player::get_xp(string skill_name){
   return get_skills().get_xp(skill_name);
}
