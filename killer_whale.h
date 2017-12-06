//Programmer: Evan Maynard and Justin Palermo        Date: 11/29/2017
//Class: CS1570                   Section: B
//File: killer_whale.h
//Purpose: Header file for the killer_whale class

#ifndef KILLER_WHALE_H
#define KILLER_WHALE_H

class sea;
#include "sim.h"
#include "penguin.h"



const short WHALES_MOVE_CELLS=3;
const short MAX_CHECKS = 1000;

//The killer_whale() is the default constructor
//Pre: none.
//Post: Creates a killer_whale



class killer_whale
{
  public:
    killer_whale();
		void move(sea& s, penguin penguins[NUM_PENG]);
		void setPos(const short x, const short y);
		void checkSurroundings(sea &s);
		void updateKills();
		void eat(const short x, const short y, sea& s, penguin penguins[NUM_PENG]);
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