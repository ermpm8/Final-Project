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
  updateFish(fishes);
  
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
      whales[i].setPos(rand_x,rand_y);
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
  m_size = (size>MIN_SIZE && size<=MAX) ? size : MAX;
  return;
}

bool sea::isEmpty(const char source) const
{
  bool empty = false;
  empty = (source==WHITESPACE);
  return empty;
}

bool sea::isSurrounded(const short x, const short y, sea& s) const
{
  bool surr = true;
  
  if (s.isEmpty(s.getActor(x,y+1)))
  {
    surr = false;
  }
  
  if (s.isEmpty(s.getActor(x+1,y+1)))
  {
    surr = false;
  }
  
  if (s.isEmpty(s.getActor(x+1,y)))
  {
    surr=false;
  }
  
  if (s.isEmpty(s.getActor(x+1,y-1)))
  {
    surr=false;
  }
  
  if (s.isEmpty(s.getActor(x,y-1)))
  {
    surr = false;
  }
  
  if (s.isEmpty(s.getActor(x-1,y-1)))
  {
    surr = false;
  }
  
  if (s.isEmpty(s.getActor(x-1,y)))
  {
    surr = false;
  }
  
  if (s.isEmpty(s.getActor(x-1,y+1)))
  {
    surr = false;
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

bool sea::validMove(const short x, const short y, sea& s) const
{
  bool valid = false;
  valid = inBounds(x,y) && s.isEmpty(s.getActor(x,y));
  return valid;  
}

bool sea::inBounds(const short x, const short y) const
{
  bool inBounds = false;
  inBounds = (x>=0 && x<m_size)&&(y>=0 && y<m_size);
  return inBounds;
}

void sea::updateFish(fish fishes[NUM_FISH])
{
  for (int i = 0; i<NUM_FISH;i++)
  {
    m_fishes[i] = fishes[i];    
  }
  return;
}

short sea::killFish(const short x, const short y)
{
  short health = -100;
  for (int i =0; i<NUM_FISH; i++)
  {
    if (m_fishes[i].isAt(x,y) && m_fishes[i].isAlive())
    {
      health = m_fishes[i].die();
    }
  }
  return health;
}

void sea::updatePenguin(penguin penguins[NUM_PENG])
{
	for(int i=0;i<NUM_PENG;i++)
	{
		m_penguins[i] = penguins[i];
	}
	return;
}

void sea::killPenguin(const short x, const short y)
{
	for (int i=0; i<NUM_PENG;i++)
	{
		if(m_penguins[i].isAt(x,y) && m_penguins[i].isAlive())
		{
			m_penguins[i].die();
		}
	}
	return;
}
	
