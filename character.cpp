#include "character.h"
    Character::Character(): character(NULL){}
    Character::Character(int _x, int _y): xspeed(0),yspeed(0),character(NULL){
        bounding.x = _x;
        bounding.y = _y;
    }
    void Character::setX(int n){bounding.x= n;}
    void Character::setY(int n){bounding.y= n;}
    int Character::getX(){return bounding.x;}
    int Character::getY(){return bounding.y;}
    void Character::setXspeed(int n){xspeed = n;}
    void Character::setYspeed(int n){yspeed = n;}
    int Character::getXspeed(){return xspeed;}
    int Character::getYspeed(){return yspeed;}
    void Character::update(){
       setX(bounding.x+xspeed);
       setY(bounding.y-yspeed);
    }
    void Character::setBitmap(const char* file){
        character = al_load_bitmap(file);
    }
    ALLEGRO_BITMAP* Character::getBitmap(){
        return character;
    }
    int Character::getWidth(){return bounding.width;}
    int Character::getHeight(){return bounding.height;}
    void Character::draw(int _width, int _height){
        bounding.width = _width;
        bounding.height = _height;
        al_draw_scaled_bitmap(character, 0,0,al_get_bitmap_width(character),
            al_get_bitmap_height(character), bounding.x, bounding.y, bounding.width, bounding.height, 0);
        
    }
