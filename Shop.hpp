//
//  Shop.hpp
//  adventure_gui
//
//  Created by Preston Meade on 10/28/17.
//  Copyright © 2017 com.preston.xc. All rights reserved.
//

#ifndef Shop_hpp
#define Shop_hpp

#include <stdio.h>
#include <iostream>
#include "Weapon.hpp"
#include <vector>


using namespace  std;

class Shop{
private:
public:
    
    vector<Weapon> weapons;
    Weapon cur_weapon;
    
    
    Shop();
    
    void fill_weapon_shop();
    
    int buy_weapon(Weapon weapon);
    void next_weapon();
    
    int get_weapon_index(Weapon weapon);

};
#endif /* Shop_hpp */
