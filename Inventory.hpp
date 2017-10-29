//
//  Inventory.hpp
//  adventure_gui
//
//  Created by Preston Meade on 10/28/17.
//  Copyright © 2017 com.preston.xc. All rights reserved.
//

#ifndef Inventory_hpp
#define Inventory_hpp

#include <stdio.h>
#include <iostream>
#include "Tool.hpp"
#include <vector>
#include "Item.hpp"
#include "Weapon.hpp"

using namespace std;

class Inventory{
private:
    
    vector<Tool> tools;
    vector<Item> items;
    vector<Weapon> weapons;
    

    
public:
    
    Inventory();
    
    Tool cur_tool;
    Item cur_item;
    
    
    vector<Tool> get_tools();
    vector<Item> get_items();
    vector<Weapon> get_weapons();
    
    bool has_tool(string tool_name);
    bool has_item(string item);
    bool has_weapon(string weapon);

    
    int get_item_index(Item item);
    
    void add_item(Item item);
    void add_tool(Tool tool);
    void add_weapon(Weapon weapon);
    
    void next_tool();
    void next_item();
    void next_weapon();
    
    
    int sell_item(Item item);

    
};

#endif /* Inventory_hpp */
