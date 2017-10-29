//
//  Inventory.cpp
//  adventure_gui
//
//  Created by Preston Meade on 10/28/17.
//  Copyright © 2017 com.preston.xc. All rights reserved.
//

#include "Inventory.hpp"

Inventory::Inventory(){
    cout << "invo intalized" << endl;
    
}

vector<Tool> Inventory::get_tools(){
    return tools;
}

vector<Item> Inventory::get_items(){
    return items;
}

void Inventory::add_tool(Tool tool){
    if(tools.size() == 0){
        cur_tool = tool;
    }
    if(!has_tool(tool.name)){
        cout << "adding tool" << endl;

        tools.push_back(tool);
    }
    
}

void Inventory::add_weapon(Weapon weapon){
    weapons.push_back(weapon);
    cout << "weapon added to player; "<< weapon.name << endl;
}

vector<Weapon> Inventory::get_weapons(){
    return weapons;
}

void Inventory::add_item(Item item){
    if(!has_item(item.name)){
        
        if(items.size() == 0){
            cur_item = item;
           // items.push_back(item);
            cout << "cur item set" << item.name << endl;
        }
        
        items.push_back(item);
        items.at(items.size() - 1).amount = 1;
        cout << "added item:" << item.name << endl;
    }else{
       
        for(int i = 0; i < items.size(); i++){
            if(items.at(i).name == item.name){
                items.at(i).add_one();
            }
        }
    }
}

int Inventory::sell_item(Item item){
    int price = 0;
    for(int i  = 0; i < items.size(); i++){
        if(items.at(i).name == item.name){
            if(items.at(i).amount > 1){
                price = items.at(i).price;
                cout << "removing one from: " << item.name << endl;
                items.at(i).amount--;
            }else{
                price = items.at(i).price;
                cout << "last one" << endl;
                items.erase(items.begin() + i);
                if(items.size() > 0){
                    cur_item = items.at(0);
                }
                
            }
        }
    
    }
    return price;
}

bool Inventory::has_weapon(string weapon){
    bool has = false;
    for(int i = 0; i < weapons.size(); i++){
        if(weapons.at(i).name == weapon){
            has = true;
            return true;
            break;
        }
    }
    return has;
}

bool Inventory::has_item(string item){
    bool has = false;
    for(int i = 0; i < items.size(); i++){
        if(items.at(i).name == item){
            has = true;
            return true;
            break;
        }
    }
    return has;
}

int Inventory::get_item_index(Item item){
    for(int i = 0; i < items.size();i++){
        if(items.at(i).name == item.name){
            return i;
        }
    }
    return -1;
}

bool Inventory::has_tool(string tool_name){
    bool has = false;
    for(int i = 0; i < tools.size(); i++){
        if(tools.at(i).name == tool_name){
            has = true;
            return true;
            break;
        }
    }
    return has;
}

void Inventory::next_item(){
    
    for(int i = 0; i < items.size(); i++){
        cout << "checking: " << items.at(i).name << endl;
        if(items.at(i).name ==  cur_item.name){
            
            if(i + 1 < items.size()){
                cur_item = items.at(i + 1);
                cout << "set tool: " << cur_item.name;
                break;
            }else{
                cur_item = items.at( 0);
                
                cout << "set 0: " << cur_item.name;
                
            }
            
        }
    }
    cout << "current tool: " << cur_tool.name << endl;
}

void Inventory::next_tool(){
  
    for(int i = 0; i < tools.size(); i++){
        cout << "checking: " << tools.at(i).name << endl;
        if(tools.at(i).name ==  cur_tool.name){
           
            if(i + 1 < tools.size()){
                cur_tool = tools.at(i + 1);
                cout << "set tool: " << cur_tool.name;
                break;
            }else{
                cur_tool = tools.at( 0);

                cout << "set 0: " << cur_tool.name;

            }
            
        }
    }
    cout << "current tool: " << cur_tool.name << endl;
}

