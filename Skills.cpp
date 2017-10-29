//
//  Skills.cpp
//  adventuree
//
//  Created by Preston Meade on 10/27/17.
//  Copyright © 2017 com.preston.xc. All rights reserved.
//

#include "Skills.hpp"

Skills::Skills(){
    cout << "loading skills " << endl;
    load_skills();
    
}

void Skills::load_skills(){
    Skill strength("str");
    Skill health("hp");
    Skill woodcut("wc");
    Skill mine("mine");
    Skill fish("fish");
    
    skills.push_back(strength);
    skills.push_back(health);
    skills.push_back(woodcut);
    skills.push_back(mine);
    skills.push_back(fish);
    cout << "loaded skills " << endl;

}

Skill Skills::get_skill(int index){
    return skills[index];
}

void Skills::add_xp(string skill_name, int xp){
    for(int i = 0; i < skills.size(); i++){
        if(skills.at(i).name == skill_name){
           // cout << "adding to: " << skill_name << endl;
            skills.at(i).add_xp(xp);
            break;
        }
    }
}

int Skills::calc_lvl(string skill_name){
    for(int i = 0; i < skills.size(); i++){
        if(skills.at(i).name == skill_name){
            return skills.at(i).get_lvl();
        }
    }
    return -1;
}


int Skills::get_xp(string skill_name){
    for(int i = 0; i < skills.size(); i++){
        if(skills.at(i).name == skill_name){
            return skills.at(i).get_xp();
        }
    }
    return -1;
}
