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
  short living_peng = 0;
  short output = 0 ;
  
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
      <<"Would you like to see output today? (1/0  -1 for yes  -0 for no)";
  cin>>output;
  
  
  
  if (output)
  {
    cout<<the_sea;
    //display the grid
    do
    {
    living_peng = 0;
    
    for (int f = 0; f<NUM_FISH; f++)
    {
      if (fishes[f].isAlive())
      {
        fishes[f].move(the_sea);        
      }         
    }		
    
    the_sea.updateFish(fishes);
    for (int p = 0; p<NUM_PENG; p++)
    {
      if (penguins[p].isAlive())
      {
        living_peng++;
        penguins[p].move(the_sea);
      }
      if (penguins[p].getHealth() >= PENG_SPAWN)
      {
        the_sea.spawn(penguins[p]);
      }
    }
    the_sea.updatePenguin(penguins);
    for (int w = 0; w<NUM_WHALE; w++)
    {
      whales[w].move(the_sea);
    }
    
    cout<<the_sea;
    usleep(200000);
    iterations++;
    } while (iterations < MAX_ITERATIONS && living_peng>0); 
  }
  
  return 0;
}