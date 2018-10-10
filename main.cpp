#include<stdio.h>
#include<iostream>
#include "character.h"
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#define numObjects 10
ALLEGRO_DISPLAY *display=NULL;
ALLEGRO_EVENT_QUEUE *event_queue;
Character protag(320, 240);
ALLEGRO_BITMAP *background = NULL;
Character objects[numObjects];
int n =0;
void init();
void draw();
void update(){
    al_rest(0.00001);
    protag.update();   
}
void checkCollision(){
    for(int i=0; i< n; i++){
        if((protag.getX()+protag.getXspeed()>= objects[i].getX()
            ||protag.getX()+protag.getWidth()+protag.getXspeed()<=objects[i].getX() +objects[i].getWidth())
            &&(protag.getY()-protag.getYspeed() >= objects[i].getY()
            ||protag.getY()-protag.getYspeed()-protag.getHeight() <= objects[i].getY()-objects[i].getYspeed())){
            
           // protag.set   
        } 
    }
}
int main(int argc, char **argv){
    init();
    float eventlag = 0.000001;
    bool done = false;
    bool pressed_keys[ALLEGRO_KEY_MAX];
    while(!done){
        ALLEGRO_EVENT evt;
        al_wait_for_event_timed(event_queue, &evt, eventlag);
        if(evt.type == ALLEGRO_EVENT_KEY_DOWN){ 
            switch(evt.keyboard.keycode){
                case ALLEGRO_KEY_LEFT:
                    protag.setXspeed(-1);
                    pressed_keys[ALLEGRO_KEY_LEFT] = 1;   
                    break;
                case ALLEGRO_KEY_RIGHT:
                    protag.setXspeed(1);
                    pressed_keys[ALLEGRO_KEY_RIGHT] = 1;   
                    break;
                case ALLEGRO_KEY_UP:
                    protag.setYspeed(1);
                    pressed_keys[ALLEGRO_KEY_UP] = 1;   
                    break;
                case ALLEGRO_KEY_DOWN:
                    protag.setYspeed(-1);
                    pressed_keys[ALLEGRO_KEY_DOWN] = 1;   
                    break;
                case ALLEGRO_KEY_ESCAPE:
                   al_destroy_display(display);
                   return 0; 
                default: ;
        } }
        else if(evt.type == ALLEGRO_EVENT_KEY_UP){
            switch(evt.keyboard.keycode){
                case ALLEGRO_KEY_LEFT:
                    pressed_keys[ALLEGRO_KEY_LEFT] = 0;   
                    if(!pressed_keys[ALLEGRO_KEY_RIGHT])protag.setXspeed(0);
                    break;
                case ALLEGRO_KEY_RIGHT:
                    pressed_keys[ALLEGRO_KEY_RIGHT] = 0;
                    if(!pressed_keys[ALLEGRO_KEY_LEFT])protag.setXspeed(0);
                    break;
                case ALLEGRO_KEY_UP:
                    pressed_keys[ALLEGRO_KEY_UP] = 0;   
                    if(!pressed_keys[ALLEGRO_KEY_DOWN])protag.setYspeed(0);
                    break;
                case ALLEGRO_KEY_DOWN:
                    pressed_keys[ALLEGRO_KEY_DOWN] = 0;   
                    if(!pressed_keys[ALLEGRO_KEY_UP])protag.setYspeed(0);
                    break;
                default: ;
            }
        }
        update();
        draw();
    }
    return 0;
}
void init(){
    al_init();
    al_init_image_addon();
    al_install_keyboard();             
    display = al_create_display(1000,1000);
    event_queue = al_create_event_queue();   
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    background = al_load_bitmap("background.jpg");
    protag.setBitmap("protag.png");
    objects[0].setBitmap("block.png");    
    objects[0].setX(500);
    objects[0].setY(500);
    n += 1;
}
void draw(){
    al_draw_scaled_bitmap(background, 0, 0, al_get_bitmap_width(background),
            al_get_bitmap_height(background), 0,0,1000, 1000, 0);
    protag.draw(50, 50);
    objects[0].draw(50, 50);    
    al_flip_display();   
    al_clear_to_color(al_map_rgb(0,0,0));
}

