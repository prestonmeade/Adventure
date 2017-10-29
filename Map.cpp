//
//  Map.cpp
//  adventuree
//
//  Created by Preston Meade on 10/27/17.
//  Copyright © 2017 com.preston.xc. All rights reserved.
//

#include "Map.hpp"
#include <sstream>
#include <fstream>
#include "ResourcePath.hpp"


Map::Map(){
    cout << "map loaded" << endl;
    load_map();
}

void Map::load_map(){
    
    cout << "loading score..\n";
    ifstream file;
    file.open(resourcePath() + "map.txt");
    if(file.is_open()){
        cout << "file loaded\n";
    }
    string found_map;
    file >> found_map;
    cout << "found old score of: " << found_map << endl;
    file.close();
    
    for(int i = 0; i < found_map.size(); i++){
        map.push_back(found_map.at(i));
    }
    
    width = map.size();
  
    
}

void Map::set(int x,  int symbol){
    map[x] = symbol;
}

void Map::print_map(){
    for(int i = 0; i < map.size(); i++){
            cout << map.at(i);
        }
        cout << endl;
    
}

void Map::render(int x, int width){
    int start = x - width;
    if(start < 0){
        start = 0;
    }
    
    for(int i = start; i < (width * 2 + start); i++){
       // cout << "i: " << i << endl;
        if(i == x){
            cout << 'P';
        }else if(i < this->width){
          cout << map.at(i) ;
        }
    }
}



void Map::clear(){
    for(int i = 0; i < map.size(); i++){
            if(map[i] == 'P'){
                map.at(i) = '*';
            
        }
    }
}



bool Map::is_full(){
    bool full = true;
    for(int i = 0; i < map.size(); i++){
        if(full && map.at(i) == '*'){
            full = false;
            break;
        }
    }
    return full;
}

bool Map::is_open(int i){
    return (map.at(i) == '*');
}

void Map::draw(int x, char symbol){
    if( x >= 0 && x < width ){
          map.at(x) = symbol;
    }
    
    
}



