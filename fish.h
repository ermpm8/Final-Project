//Programmer: Evan Maynard and Justin Palermo        Date: 11/29/2017
//Class: CS1570                   Section: B
//File: fish.h
//Purpose: Header file for the fish class.

#ifndef FISH_H
#define FISH_H

class sea;
#include "sim.h"



const short MIN_FOOD = 1, MAX_FOOD = 11;
//random food value min and max


//The fish() is the constructor for the fish.
//Pre: none.
//Post: Fish are created.

//The setPos() will set the fish's position.
//Pre: x and y must be within the grid.
//Post: Sets the position.

//The isAlive() will check if the fish is alive.
//Pre: none.
//Post: Returns whether the penguin is alive or not.


class fish
{
  public:
    fish();
    bool move(sea& s);
    void setPos(const short x, const short y);
    bool isAlive() const;
    short die();
    bool isAt(const short x, const short y);
    void spawn(const short x, const short y);
  private:
    short m_food;
    short m_x;
    short m_y;
    bool m_alive;
};



#endif