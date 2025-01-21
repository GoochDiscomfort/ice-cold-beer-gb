#include <gb/gb.h>
#include <stdint.h>
#include <stdio.h>
#include "ball.h" 
#include "bar.h"


int bar_x_pos = 20;
int bar_y_pos = 140;

int ball_x_pos = 75;
int ball_y_pos = 137;

int speed = 1;

void draw_bar(int x_pos,int y_pos){
    set_sprite_data(0, 8, bar);
    set_sprite_tile(0,0);
    move_sprite(0, x_pos, y_pos);
        
    set_sprite_tile(1, 1);
    move_sprite(1, x_pos+8,y_pos);
    set_sprite_tile(2, 1);
    move_sprite(2, x_pos+16,y_pos);
    set_sprite_tile(3, 1);
    move_sprite(3, x_pos+24,y_pos);
    set_sprite_tile(4, 1);
    move_sprite(4, x_pos+32,y_pos);
    set_sprite_tile(5, 1);
    move_sprite(5, x_pos+40,y_pos);
    set_sprite_tile(6, 1);
    move_sprite(6, x_pos+48,y_pos);
    set_sprite_tile(7, 2);
    move_sprite(7, x_pos+56,y_pos);
}


void main()
{
    
    while (1){
        
        int joy_direction = joypad();

        if (joy_direction & J_RIGHT){
            ball_x_pos += speed;
        }
        if (joy_direction & J_LEFT){
            ball_x_pos -= speed;
        }
        if (joy_direction & J_UP){
            bar_y_pos -= speed;
            ball_y_pos -= speed;
        }
        if (joy_direction & J_DOWN){
            bar_y_pos += speed;
            ball_y_pos += speed;
        }

        if (ball_y_pos > 144){ball_y_pos = 144;}
        if (ball_y_pos < bar_y_pos){ball_y_pos = bar_y_pos- 3;}
        if (ball_x_pos > 73){ball_x_pos = 73;}
        if (ball_x_pos < 23){ball_x_pos = 23;}

        if (bar_y_pos > 140){bar_y_pos = 140;}

        // Bar Sprite
        SPRITES_8x8;
        draw_bar(bar_x_pos, bar_y_pos);

        // Initialize Ball Sprite
        
        //set_sprite_data(3,8, bar); // out of loop??
        set_sprite_tile(8,3);
        move_sprite(8,ball_x_pos, ball_y_pos);
        

        /*set_sprite_tile(1,1);
        move_sprite(1, 16+8, 140);
        set_sprite_tile(2,1);
        move_sprite(2, 75+8, 75);

        set_sprite_tile(10,2);
        move_sprite(1,ball_x_pos +8, ball_y_pos);
        
        for(int i = 1; i<=7; i++){
            set_sprite_tile(i,1);
            move_sprite(i, edge_pos, 140);
            edge_pos += 9;
        }*/
        
        SHOW_SPRITES;
        vsync();
        
    }
}

