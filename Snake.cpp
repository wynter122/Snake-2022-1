#include <iostream>
#include "Snake.h"
#include <ncurses.h>

Snake::Snake()
{
    this->direction = 1;
    this->isDead = false;
    this->x = 6;
    this->y = 6;

}
Snake::~Snake(){}

void Snake::setDir(int direction)
{
    this->direction = direction;
}

void Snake::willMove()
{
    if(direction == 1) {
        y--;
    }
    else if(direction == 2){
        x++;
    }
    else if(direction == 3){
        y++;
    }
    else if(direction == 4){
        x--;
    }
}

void Snake::upDate(){
    int  KeyPressed;

    KeyPressed = getch();
    switch (KeyPressed)
    {
    case KEY_LEFT:
        if(direction !=4 ) direction = 4;
        else break;
        break;

    default:
        break;
    }
}
