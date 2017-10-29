//
//  Position.cpp
//  adventuree
//
//  Created by Preston Meade on 10/27/17.
//  Copyright © 2017 com.preston.xc. All rights reserved.
//

#include "Position.hpp"

Position::Position(double x, double y, double dx, double dy){
    this->x = x;
    this->y = y;
    this->dx = dx;
    this->dy = dy;
    cout << "pos(x,y,dx,dy) " << endl;

}

Position::Position(double x, double y){
    this->x = 0;
    this->y = y;
    this->dx = 0;
    this->dy = 0;
    cout << "pos(x,y) " << endl;

}

Position::Position(){
    this->x = 0;
    this->y = 0;
    this->dx = 0;
    this->dy = 0;
    direction = 0;
    cout << "pos() " << endl;
}

double Position::get_x(){
    return x;
}

int Position::get_direction(){
    return direction;
}

void Position::set_direction(int d){
    direction = d;
}

void Position::set_x(double new_x){
    x = new_x;

}

double Position::get_y(){
    return y;
}

void Position::set_y(double new_y){
    this->y = new_y;

}

double Position::get_dx(){
    return dx;
}

void Position::set_dx(double new_dx){
    dx = new_dx;
}

double Position::get_dy(){
    return dy;
}

void Position::set_dy(double new_dy){
    dy = new_dy;
}

string Position::str_pos(){
    stringstream ss;
    ss << "x: " << this->x << " y: " << y;
    return ss.str();
}






