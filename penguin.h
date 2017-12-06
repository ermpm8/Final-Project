//Programmer: Evan Maynard and Justin Palermo        Date: 11/29/2017
//Class: CS1570                   Section: B
//File: penguin.h
//Purpose: Header file for the penguin class.

#ifndef PENGUIN_H
#define PENGUIN_H

class sea;
#include "sim.h"
#include "fish.h"


const short LOWER_HEALTH = 60, UPPER_HEALTH = 81;
//health values used for initial spawn
const short MAX_HEALTH = 100, MIN_HEALTH = 1;
//health values used for later spawns

const short HEALTH_LOSS = 1;
//Amount of health penguins lose each movement


const short TIER1 = 81;
const short TIER2 = 61;
const short TIER3 = 41;
const short TIER4 = 21;
const short TIER5 = 1;
const short TIER6 = 0;
//Health values in tiers that correlate to the number
//of tiles to move

const short MOVE_TIER1 = 5;
const short MOVE_TIER2 = 4;
const short MOVE_TIER3 = 3;
const short MOVE_TIER4 = 2;
const short MOVE_TIER5 = 1;
const short MOVE_TIER6 = 0;
//Number of tiles to move based on health


const short PENGUIN_SIGHT = 8;
//Distance a penguin can "see" in the grid

//The penguin() is the default constructor for the penguin class.
//Pre: none
//Post: Initializes the health value to a random int [60-80], sets all
//      positional values to DEAD_POS (-1) and alive to false.


//The move() is responsible for moving the penguin in the grid.
//Pre: s must be a sea that contains a char grid full of data
//Post: Moves the penguin based on proximity to whales and fish.

//The die() is responsible for "killing" the penguin.
//Pre: none
//Post: The penguin will be removed from the grid, and reset to default values

//The setPos() will set the position of the penguin in the grid.
//Pre: x and y must be > 0 and both be less than the size of the grid.
//Post: The penguin is given a location and set to alive.

//The isAlive() will check to see if the penguin is alive.
//Pre: none.
//Post: Returns the value of m_alive.

//The isAt() will check if a penguin is at the specified location
//Pre: x and y must be contained within the grid ( > 0 && < size).
//Post: returns a boolean value that represents if the penguin is at the loc.

//The eat() will consume a fish and give the penguin the health val from it.
//Pre: x and y must be within the grid.
//Post: fish will be eaten and penguin gains fish's health val.

//The spawn() will spawn a penguin.
//Pre: x and y must be within the grid, health must be between 1 and 100.
//Post: A penguin is placed on the grid with random health, and set to alive.

//The getHealth() will return the penguin's health.
//Pre: none.
//Post: Returns health val.

//The distance() will find the distance between two points.
//Pre: x1,x2,y1,y2 must be within the grid.
//Post: returns the distance.

//The checkSurroundings() will search for nearby fish and whales.
//Pre: s must contain a char grid full of data.
//Post: Calls setStatus().

//The setStatus() will modify the feed or run status of the penguin.
//Pre: s must contain a char grid full of data, and x and y must be within 
//     the grid ( > 0 && < size).
//Post: modifies run or feed based on the char at that position.

class penguin
{
  public:
    penguin();
    void move(sea& s, fish fishes[NUM_FISH]);  
    void die();		
		void setPos(const short x, const short y);
    bool isAlive() const;
		bool isAt(const short x, const short y) const;
    void eat(const short x, const short y, sea& s, fish fishes[NUM_FISH]);
    void spawn(const short x, const short y, const short health);
    short getHealth() const {return m_health;}
  private:
    float distance(const short x1, const short y1, const short x2,
                        const short y2);
    void checkSurroundings(sea& s);
    void setStatus(sea& s, const short x, const short y);
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