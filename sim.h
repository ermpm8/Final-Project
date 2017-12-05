//Programmer: Evan Maynard and Justin Palermo        Date: 11/29/2017
//Class: CS1570                   Section: B
//File: sim.h
//Purpose: Header file for the simulation file

#ifndef SIM_H
#define SIM_H

#include <iostream>
#include <unistd.h>
#include <cstdlib>

using namespace std;




/*---Border Constants---*/
const char BORDER = '-';
//Represents the char that borders the top and bottom of the output grid
const char SIDE = '|';
//Represents the char making up the side of each "tile" in the grid
const char WHITESPACE = ' ';
//Represents the char for blank spaces in the grid

const short NOT_ON_EDGE = 0;
const short N = 1;
const short NE = 2;
const short E = 3;
const short SE = 4;
const short S = 5;
const short SW = 6;
const short W = 7;
const short NW = 8;






/*---Actor Char Constants---*/
const char FISH = 'F';
//char to represent fish
const char PENG = 'P';
//char to represent penguins
const char WHALE = 'K';
//char to represent killer whales




/*---Size constants---*/
const short MAX = 25;
//The maximum size of the grid (25 x 25)
const short MIN_SIZE = 0;
//The min size of the grid (0x0)
const short BORDER_MULT = 2;
//Multiplier for the number of border characters at the top and bottom

/*---Simulation Constants---*/
const short SIM_SIZE = 17;
//Size of the simulation grid
const short NUM_FISH = 200;
//Number of fish to be used in the simulation
const short START_FISH = 35;
//Number of fish to start the sim
const short NUM_PENG = 50;
//Number of penguins to be used in the sim
const short START_PENG = 20;
//Number of penguins to start the sim
const short NUM_WHALE = 2;
//Number of killer whales

const short NUM_DIRS = 4;
const short DIR[NUM_DIRS] = {-1,0,0,1};
//values used to randomly assign the direction of movement




const short DEAD_POS = -1;
//position of dead actors




#endif




