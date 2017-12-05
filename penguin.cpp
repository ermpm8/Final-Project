//Programmer: Evan Maynard and Justin Palermo        Date: 11/29/2017
//Class: CS1570                   Section: B
//File: penguin.cpp
//Purpose: Implementation file for the penguin class.

#include "penguin.h"
#include "sea.h"

penguin::penguin()
{
  m_health = rand() % (MAX_HEALTH - MIN_HEALTH) + MIN_HEALTH;
  m_x = DEAD_POS;
  m_y = DEAD_POS;
  m_alive = false;
}

bool penguin::move(sea& s)
{
  bool moved = false;
  short x_dif;
  short y_dif;
  short move_cells;
  
  bool run = false;
  bool feed = false;
  
  if(m_health>=TIER1)
  {
    move_cells = MOVE_TIER1;
  }else if(m_health>=TIER2)
  {
    move_cells = MOVE_TIER2;
  }else if(m_health>=TIER3)
  {
    move_cells = MOVE_TIER3;
  }else if(m_health>=TIER4)
  {
    move_cells = MOVE_TIER4;
  }else if(m_health>=TIER5)
  {
    move_cells = MOVE_TIER5;
  }else if(m_health<=TIER6)
  {
    move_cells = MOVE_TIER6;
  }
  
  if (!(s.isSurrounded(m_x,m_y)))
  {
    s.update(m_x, m_y, WHITESPACE);
    
    
    for (int i = 0; i< NUM_DIRS; i++)
    {
      for (int j = 0; j< NUM_DIRS; j++)
      {
        if (DIR[i] && DIR[j] !=0)
        {
          if (s.getActor(x+DIR[i],y+DIR[j] == ))
          {
            
          }
        }      
      }
    }
  
  
  }
 
}

void penguin::die()
{
  m_x = DEAD_POS;
  m_y = DEAD_POS;
  m_alive = false;
  return;
}

void penguin::setPos(const short x, const short y)
{
  m_x = x;
  m_y = y;
  m_alive = true;
  return;
}

bool penguin::isAlive() const
{
  return m_alive; 
}

void checkSurroundings(sea& s)
{
  
}