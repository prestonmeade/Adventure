//
//  Map.hpp
//  adventuree
//
//  Created by Preston Meade on 10/27/17.
//  Copyright © 2017 com.preston.xc. All rights reserved.
//

#ifndef Map_hpp
#define Map_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Map{
private:
public:
    vector<char> map;
    
    int width = 50;
    int height = 1;
    
    Map();
    
    void set(int x, int symbol);
    void load_map();
    void print_map();
    void draw(int x,  char symbol);
    bool is_open(int i);
    bool is_full();
    void clear();
    void render(int x, int width);
    
    
};

#endif /* Map_hpp */
