//Programmer: Evan Maynard        Date: 11/26/2017
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
    
  }
 
}

void penguin::die()
{
  m_x = DEAD_POS;
  m_y = DEAD_POS;
  m_alive = false;
  return;
}

short penguin::findWhale(sea& s)
{
  short dist = -1;
  
  for (int i = 0; i<PENGUIN_SIGHT; i++)
  {
    if (getActor(m_x+i, m_y+i+1)==WHALE) //NORTH check
    {
      dist = i;
      m_avoid_x = m_x+i;
      m_avoid_y = m_y+i+1;
    }
    
    
    
  }
  
  
  
  return foundWhale;
}
