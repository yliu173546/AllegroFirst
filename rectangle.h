#include<iostream>
#include<stdio.h>
class Rectangle{
    public:
        Rectangle();
        Rectangle(int x, int y, int w, int h);
        int getX();
        int getY();
        int getWidth();
        int getHeight();
        void setX(int _x);
        void setY(int _y);
    private:
        int x,y, width, height;
}
