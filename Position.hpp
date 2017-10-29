//
//  Position.hpp
//  adventuree
//
//  Created by Preston Meade on 10/27/17.
//  Copyright © 2017 com.preston.xc. All rights reserved.
//

#ifndef Position_hpp
#define Position_hpp

#include <stdio.h>
#include <iostream>
#include <sstream>

using namespace std;

class Position{
private:
 
public:
    
    double x,y;
    double dx, dy;
    int direction;
    
    Position(double x, double y, double dx, double dy);
    Position(double x, double y);
    Position();
    
    double get_x();
    void set_x(double new_x);
    
    
    double get_y();
    void set_y(double new_y);
    
    
    double get_dx();
    void set_dx(double new_dx);
    
    double get_dy();
    void set_dy(double new_dy);
    
    int get_direction();
    void set_direction(int d);
    
    string str_pos();
};

#endif /* Position_hpp */
