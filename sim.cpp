//Programmer: Evan Maynard and Justin Palermo        Date: 11/29/2017
//Class: CS1570                   Section: B
//File: sim.cpp
//Purpose: To demonstrate the functionality of the classes previously created
//         and to simulate this arctic environment.


#include "sim.h"
#include "sea.h"


int main()
{
  srand(time(NULL));
  //seed the random number generator
  
  fish fishes[NUM_FISH];          
  //declare the fish array
  penguin penguins[NUM_PENG];     
  //declare the penguin array
  killer_whale whales[NUM_WHALE];
  //declare the whale array
  
  sea the_sea(SIM_SIZE,fishes,penguins,whales);
  //declare the sea grid
  
  cout<<the_sea;
  //display the grid
  
  //fishes[0].move(the_sea);
  
  
  
  for (int i = 0; i<15; i++)
  {
    for (int f = 0; f<NUM_FISH; f++)
    {
      if (fishes[f].isAlive())
      {
        fishes[f].move(the_sea);
        cout<<the_sea;  
      }     
    }		
    usleep(200000);
    	
  }
  
  return 0;
}