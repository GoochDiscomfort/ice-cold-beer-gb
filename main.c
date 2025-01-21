#include <gb/gb.h>
#include <stdint.h>
#include <stdio.h>
#include "ball.h" 
#include "bar.h"


int bar_x_pos = 0;
int bar_y_pos = 0;

int ball_x_pos = 75;
int ball_y_pos = 144;

int speed = 1;

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
            ball_y_pos -= speed;
        }
        if (joy_direction & J_DOWN){
            ball_y_pos += speed;
        }

        if (ball_y_pos > 144){ball_y_pos = 144;}
        if (ball_y_pos < 16){ball_y_pos = 16;}
        if (ball_x_pos > 74){ball_x_pos = 74;}
        if (ball_x_pos < 29){ball_x_pos = 29;}

        // Bar Sprite
        SPRITES_8x8;
        set_sprite_data(0, 8, bar);
        set_sprite_tile(0,0);
        move_sprite(0, 20, 140);
        
        set_sprite_tile(1, 1);
        move_sprite(1, 28,140);
        set_sprite_tile(2, 1);
        move_sprite(2, 36,140);
        set_sprite_tile(3, 1);
        move_sprite(3, 44,140);
        set_sprite_tile(4, 1);
        move_sprite(4, 52,140);
        set_sprite_tile(5, 1);
        move_sprite(5, 60,140);
        set_sprite_tile(6, 1);
        move_sprite(6, 68,140);
        set_sprite_tile(7, 2);
        move_sprite(7, 76,140);

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

