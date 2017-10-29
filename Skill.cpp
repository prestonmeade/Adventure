//
//  Skill.cpp
//  adventuree
//
//  Created by Preston Meade on 10/27/17.
//  Copyright © 2017 com.preston.xc. All rights reserved.
//

#include "Skill.hpp"

Skill::Skill(string name){
    this->name = name;
    xp = new int(0);
}

void Skill::add_xp(int num_xp){
    *xp += num_xp;
   // cout << "added: " << num_xp << " total: " << *xp << endl;
}

int Skill::get_xp(){
    return *xp;
}


int Skill::get_lvl(){
    return ( *xp / 10);
}
