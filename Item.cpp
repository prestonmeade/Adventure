//
//  Item.cpp
//  adventure_gui
//
//  Created by Preston Meade on 10/28/17.
//  Copyright © 2017 com.preston.xc. All rights reserved.
//

#include "Item.hpp"

Item::Item(string tool_name, int price){
    name = tool_name;
    this->price = price;
    id = 0;
    broken = false;
    amount++;
    
}

Item::Item(){
    
}

void Item::add_one(){
    amount++;
}

