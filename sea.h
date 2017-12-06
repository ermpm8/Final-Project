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


//The sea() will create the sea and call clear() and populate()
//Pre: size must be > 0 and less than MAX_SIZE
//Post: Creates the sea.

//The operator<<() is the overloaded insertion operator.
//Pre: s must contain data.
//Post: Outputs the sea object to the stream.

//The setSize() will modify the grid size.
//Pre: size must be > 0 and < MAX_SIZE.
//Post: Sets the size.

//The isEmpty() will check to see if a space in the grid is empty.
//Pre: none
//Post: Returns whether the char is WHITESPACE or not.

//The isSurrounded() will check if an actor is surrounded.
//Pre: x and y must be within the grid. s must contain data.
//Post: returns the surrounded status of the actor.

//The update() will update the grid.
//Pre: x and y must be within the grid. actor must be a valid actor.
//Post: Updates the location on the grid with the actor.

//The getActor() will return the actor at a location.
//Pre: x and y must be in the grid.
//Post: returns the actor.

//The getSize() will return the size of the grid.
//Pre: none.
//Post: Returns size.

//The validMove() will check to see if the space to move is in the grid & empty
//Pre: s must contain data.
//Post: returns whether the move is valid.

//The inBounds() will check to see if a space is in the grid.
//Pre: none.
//Post: Returns whether the move is in the grid.

//The killFish() will kill a fish.
//Pre: x and y must be within the grid.
//Post: kills a fish and resets the position.

//The killPenguin will kill a penguin.
//Pre: x and y must be within the grid.
//Post: kills a penguin and resets the pos.

//The spawn() will spawn either a penguin or a fish.
//Pre: a valid penguin or fish.
//Post: puts the peng or fish on the grid.

//The clear() will clear the grid to only whitespace.
//Pre: none.
//Post: Grid is cleared.

//The populate() will add actors to the grid.
//Pre: none.
//Post: Actors are added to the grid.


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
    short killFish(const short x, const short y, fish fishes[NUM_FISH]);
		void killPenguin(const short x, const short y, penguin penguins[NUM_PENG]);
    void spawn(penguin& p);
    void spawn(fish& f);
    short getLiving(fish fishes[NUM_FISH]) const;
    short getLiving(penguin penguins[NUM_PENG]) const;
  private:
    void clear();
    void populate(fish fishes[NUM_FISH], penguin penguins[NUM_PENG],
                  killer_whale whales[NUM_WHALE]);    
    char m_grid[MAX][MAX];
    short m_size;
};

#endif