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
  
  short iterations = 0;
  //counter for time in the sim
  short output = 0 ;
  //whether or not the user wants output
  
  fish fishes[NUM_FISH];          
  //declare the fish array
  penguin penguins[NUM_PENG];     
  //declare the penguin array
  killer_whale whales[NUM_WHALE];
  //declare the whale array
  
  sea the_sea(SIM_SIZE,fishes,penguins,whales);
  //declare the sea grid
  
  cout<<"Hello and Welcome to the Sea simulation Project"<<endl
      <<"v0.84......."
      <<"Would you like to see output today? (1/0  -1 for yes  -0 for no) : ";
  cin>>output;
  
  
  
  if (output)
  {
    cout<<the_sea;
    //display the grid
    do
    {    
    
    for (int f = 0; f<NUM_FISH; f++)
    {
      if (fishes[f].isAlive())
      {
        fishes[f].move(the_sea); 
      }         
    }		
   
    for (int p = 0; p<NUM_PENG; p++)
    {
      if (penguins[p].isAlive())
      {
        penguins[p].move(the_sea,fishes);
      }
      if (penguins[p].getHealth() >= PENG_SPAWN)
      {
        for (int i = 0; i<NUM_PENG; i++)
        {
          if (!(penguins[i].isAlive()))
          {
            the_sea.spawn(penguins[i]);
          }
        }
      }
    }
    for (int w = 0; w<NUM_WHALE; w++)
    {
      whales[w].move(the_sea, penguins);
    }
    
    for (int i = 0; i<FISH_SPAWN_RATE; i++)
    {
      bool spawned = false;
      short ctn = 0;
      while ((!(spawned)) && ctn < NUM_FISH)
      {
        if (!(fishes[ctn].isAlive()))
        {
          the_sea.spawn(fishes[ctn]);
          spawned = true;
        }
        ctn++;
      }
    }
    
    cout<<the_sea;
    //usleep(200000);
    iterations++;
    } while (iterations < MAX_ITERATIONS && the_sea.getLiving(penguins)>0); 
    cout<<"Fish left: "<<the_sea.getLiving(fishes)<<endl;
    cout<<"Penguings left: "<<the_sea.getLiving(penguins)<<endl;
    cout<<"Whale #1 Tally: "<<whales[0].getKills()<<endl;
    cout<<"Whale #2 Tally: "<<whales[1].getKills()<<endl;
  }
  return 0;
}