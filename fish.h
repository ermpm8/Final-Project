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



class fish
{
  public:
    fish();
    bool move(sea& s);
    void setPos(const short x, const short y);
    bool isAlive() const;
  private:
    short m_food;
    short m_x;
    short m_y;
    bool m_alive;
};



#endif