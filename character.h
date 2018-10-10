#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>
#include <iostream>
struct BOX{
    int x, y, width, height;
};
class Character{
public:
    Character();
    Character(int _x, int _y);
    void setX(int n);
    void setY(int n);
    int getX();
    int getY(); 
    void update();
    void setBitmap(const char* file);
    ALLEGRO_BITMAP* getBitmap();
    void draw(int width, int height);
    void setXspeed(int n);
    void setYspeed(int n);
    int getXspeed();
    int getYspeed();
    int getWidth();
    int getHeight();
private: 
    int xspeed, yspeed;
    ALLEGRO_BITMAP *character;
    BOX bounding;   
};
