//Programmer: Evan Maynard and Justin Palermo        Date: 11/29/2017
//Class: CS1570                   Section: B
//File: killer_whale.h
//Purpose: Header file for the killer_whale class

#ifndef KILLER_WHALE_H
#define KILLER_WHALE_H

class sea;
#include "sim.h"


const short WHALES_MOVE_CELLS=3;

class killer_whale
{
  public:
    killer_whale();
		void move(sea& s);
		void setPos(const short x, const short y);
		void checkSurroundings(sea &s);
		void updateKills();
		void eat(const short x, const short y, sea& s);
    short getKills() const;
  private:
    short m_kills;
		short m_x;
		short m_y;
		short m_penguin_x;
		short m_penguin_y;
		bool m_feed;
};




#endif