//
//  Shop.cpp
//  adventure_gui
//
//  Created by Preston Meade on 10/28/17.
//  Copyright © 2017 com.preston.xc. All rights reserved.
//

#include "Shop.hpp"


Shop::Shop(){
    fill_weapon_shop();
    cout << "shop filled "<< endl;
    
}

void Shop::fill_weapon_shop(){
    weapons.push_back(Weapon("bronze dagger", 5, 5));
    weapons.push_back(Weapon("iron dagger", 5, 5));
    weapons.push_back(Weapon("draggon dagger", 5, 5));
   
    cur_weapon = weapons.at(0);
}

int Shop::buy_weapon(Weapon weapon){
    
}

void Shop::next_weapon(){
    
    for(int i = 0; i < weapons.size(); i++){
        cout << "checking: " << weapons.at(i).name << endl;
        if(weapons.at(i).name ==  cur_weapon.name){
            
            if(i + 1 < weapons.size()){
                cur_weapon = weapons.at(i + 1);
                cout << "set tool: " << cur_weapon.name;
                break;
            }else{
                cur_weapon = weapons.at( 0);
                
                cout << "set 0: " << cur_weapon.name;
                
            }
            
        }
    }
    cout << "current weapon: " << cur_weapon.name << endl;
}

int Shop::get_weapon_index(Weapon weapon){
    for(int i = 0; i < weapons.size();i++){
        if(weapons.at(i).name == weapon.name){
            return i;
        }
    }
    return -1;
}
