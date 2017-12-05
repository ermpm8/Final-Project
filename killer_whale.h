//Programmer: Evan Maynard and Justin Palermo        Date: 11/29/2017
//Class: CS1570                   Section: B
//File: killer_whale.h
//Purpose: Header file for the killer_whale class

#ifndef KILLER_WHALE_H
#define KILLER_WHALE_H

class sea;
#include "sim.h"

class killer_whale
{
  public:
    killer_whale();
		bool move(sea& s);
		void setPos(const short x, const short y);
		
  private:
    short m_kills;
		short m_x;
		short m_y;
};




#endif