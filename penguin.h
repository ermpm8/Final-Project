//Programmer: Evan Maynard and Justin Palermo        Date: 11/29/2017
//Class: CS1570                   Section: B
//File: penguin.h
//Purpose: Header file for the penguin class.

#ifndef PENGUIN_H
#define PENGUIN_H

class sea;
#include "sim.h"

const short MIN_HEALTH = 60, MAX_HEALTH = 81;

const short TIER1 = 81;
const short TIER2 = 61;
const short TIER3 = 41;
const short TIER4 = 21;
const short TIER5 = 1;
const short TIER6 = 0;

const short MOVE_TIER1 = 5;
const short MOVE_TIER2 = 4;
const short MOVE_TIER3 = 3;
const short MOVE_TIER4 = 2;
const short MOVE_TIER5 = 1;
const short MOVE_TIER6 = 0;



const short PENGUIN_SIGHT = 8;


class penguin
{
  public:
    penguin();
    bool move(sea& s);  
    void die();		
		void setPos(const short x, const short y);
    bool isAlive() const;
    
  private:
    void checkSurroundings(sea& s);
    short m_health;
    short m_x;
    short m_y;
    bool m_alive;
    short m_whale_x;
    short m_whale_y;
    short m_fish_x;
    short m_fish_y;
    bool m_run;
    bool m_feed;
};




#endif