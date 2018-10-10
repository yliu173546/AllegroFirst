#include "rectangle.h"
    Rectangle::Rectangle(){};
    Rectangle::Rectangle(int _x, int _y, int w, int h): x(_x),y(_y), width(w), height(h){}
    int Rectangle::getX(){return x;}
    int Rectangle::getY(){return y;}
    void Rectangle::setX(int n){ x = n;}    
