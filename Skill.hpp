//
//  Skill.hpp
//  adventuree
//
//  Created by Preston Meade on 10/27/17.
//  Copyright © 2017 com.preston.xc. All rights reserved.
//

#ifndef Skill_hpp
#define Skill_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class Skill{
public:
    
    string name;
    int* xp;
    
    Skill(string name);
    
    void add_xp(int num_xp);
    int get_lvl();
    int get_xp();
    
};



#endif /* Skill_hpp */
