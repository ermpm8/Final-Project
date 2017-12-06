//Programmer: Evan Maynard and Justin Palermo        Date: 11/29/2017
//Class: CS1570                   Section: B
//File: sea.h
//Purpose: Header file for the sea class.

#ifndef SEA_H
#define SEA_H



#include "sim.h"
#include "penguin.h"
#include "fish.h"
#include "killer_whale.h"



class sea
{
  public:
    sea(const short size, fish fishes[NUM_FISH], penguin penguins[NUM_PENG],
        killer_whale whales[NUM_WHALE]);   
    friend ostream& operator << (ostream& os, const sea& s);
    void setSize(const short size);
    bool isEmpty(const char source) const;
    bool isSurrounded(const short x, const short y, sea& s) const;
    void update(const short x, const short y, const char actor);
    char getActor(const short x, const short y);
    short getSize() const {return m_size;}
    bool validMove(const short x, const short y, sea& s) const;
    bool inBounds(const short x, const short y) const;
    void updateFish(fish fishes[NUM_FISH]);
    short killFish(const short x, const short y);
		void updatePenguin(penguin penguins[NUM_PENG]);
		void killPenguin(const short x, const short y);
    void spawn(penguin& p);
  private:
    void clear();
    void populate(fish fishes[NUM_FISH], penguin penguins[NUM_PENG],
                  killer_whale whales[NUM_WHALE]);    
    char m_grid[MAX][MAX];
    short m_size;
    fish m_fishes[NUM_FISH];
		penguin m_penguins[NUM_PENG];
};

#endif