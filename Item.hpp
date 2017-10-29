//
//  Item.hpp
//  adventure_gui
//
//  Created by Preston Meade on 10/28/17.
//  Copyright © 2017 com.preston.xc. All rights reserved.
//

#ifndef Item_hpp
#define Item_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class Item{
private:
    
public:
    
    string name;
    int id;
    bool broken;
    int price;
    int amount;
    
    Item(string tool_name, int price);
    Item();
    
    void add_one();
    
};
#endif /* Item_hpp */
