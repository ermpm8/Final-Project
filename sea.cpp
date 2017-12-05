//Programmer: Evan Maynard and Justin Palermo        Date: 11/29/2017
//Class: CS1570                   Section: B
//File: sea.cpp
//Purpose: Implementation file for the sea class.

#include "sea.h"

sea::sea(const short size, fish fishes[NUM_FISH],
         penguin penguins[NUM_PENG], killer_whale whales[NUM_WHALE])
{
  setSize(size);
  clear();
  populate(fishes, penguins, whales);
}

void sea::clear()
{
  for (int i = 0; i<=m_size-1; i++)
  {
    for (int j = 0; j<=m_size-1; j++)
    {
      m_grid[i][j] = WHITESPACE;
    }
  }
  return;
}

void sea::populate(fish fishes[NUM_FISH], penguin penguins[NUM_PENG],
                   killer_whale whales[NUM_WHALE])
{
  short rand_x;
  short rand_y;
  for (int i = 0; i<START_FISH; i++)
  {    
    do
    {
      rand_x = rand() % m_size;
      rand_y = rand() % m_size;    
    }while(!(isEmpty(m_grid[rand_x][rand_y])));
      m_grid[rand_x][rand_y] = FISH;
      fishes[i].setPos(rand_x, rand_y);    
  }
  
  for (int i = 0; i<START_PENG; i++)
  {
    do
    {
      rand_x = rand() % m_size;
      rand_y = rand() % m_size;    
    }while(!(isEmpty(m_grid[rand_x][rand_y])));
      m_grid[rand_x][rand_y] = PENG;
      penguins[i].setPos(rand_x, rand_y);
  }
  for (int i = 0; i<NUM_WHALE; i++)
  {
    do
    {
      rand_x = rand() % m_size;
      rand_y = rand() % m_size;    
    }while(!(isEmpty(m_grid[rand_x][rand_y])));
      m_grid[rand_x][rand_y] = WHALE;
      //whales[i].m_x = rand_x;
      //whales[i].m_y = rand_y;
  }
  
  return;
}

ostream& operator << (ostream& os, const sea& s)
{
  for (int i=0; i <=((s.m_size)*BORDER_MULT); i++)
  {
    os<<BORDER;
  }
  os<<endl;
  for (int i = 0; i<=s.m_size-1; i++)
  {
    for (int j = 0; j<=s.m_size-1; j++)
    {
      os<<SIDE<<s.m_grid[i][j];
    }
    os<<SIDE<<endl;
  }
  for (int i=0; i <=((s.m_size)*BORDER_MULT); i++)
  {
    os<<BORDER;
  }
  os<<endl;
  return os;
}

void sea::setSize(const short size)
{
  m_size = (size>MIN_SIZE) ? size : MIN_SIZE;
  return;
}

bool sea::isEmpty(const char source) const
{
  bool empty = false;
  empty = (source==' ');
  return empty;
}

bool sea::isSurrounded(const short x, const short y) const
{
  bool surr = false;
  if(y==0 || !isEmpty(m_grid[x][y-1]) //NORTH check
	{
		surr=true;
	}else if(x==m_size-1 || !isEmpty(m_grid[x+1][y]) //EAST check
	{
		surr=true;
	}else if(y==m_size-1 || !isEmpty(m_grid[x][y+1]) //SOUTH check
	{
		surr=true;
	}else if(y==m_size-1 || !isEmpty(m_grid[x][y-1]) //WEST check
	{
		surr=true;
	}else if((y==0 && x==m_size-1) || !isEmpty(m_grid[x+1][y-1]) //NORTHEAST check
	{
		surr=true;
	}else if((y==m_size-1 && x==m_size-1) || !isEmpty(m_grid[x+1][y+1]) //SOUTHEAST check
	{
		surr=true;
	}else if((y==m_size-1 && x==0) || !isEmpty(m_grid[x-1][y+1]) //SOUTHWEST check
	{
		surr=true;
	}else if((y==0 && x==0) || !isEmpty(m_grid[x][y-1]) //NORTHWEST check
	{
		surr=true;
	}
  return surr;  
}

void sea::update(const short x, const short y, const char actor)
{
  m_grid[x][y] = actor;
  return;
}

char sea::getActor(const short x, const short y)
{
  return m_grid[x][y];  
}
/*
short sea::onEdge(const short x, const short y) const
{
  short edge = NOT_ON_EDGE;
  if (x==0 && y==0)
  {
    edge = NW;
  }else if (x==0 && y==m_size-1)
  {
    edge = SW;
  }else if (x==m_size-1 && y==0)
  {
    edge = NE;
  }else if (x==m_size-1 && y==m_size-1)
  {
    edge = SE;
  }else if (x==0 && y!=0)
  {
    edge = W;
  }else if (x==m_size-1 && y!=0)
  {
    edge = E;
  }else if (x!=0 && y==0)
  {
    edge = N;
  }else if (x!=0 && y==m_size-1)
  {
    edge = S;
  }
   return edge;  
}
*/