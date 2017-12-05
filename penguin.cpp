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
  
  short near_whale_x;
  short near_whale_y;
  
  short near_fish_x;
  short near_fish_y;
  
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
    
    for (int k = 0; k<PENGUIN_SIGHT; k++)
    {
      for (int i = 0; i< NUM_DIRS; i++)
      {
        for (int j = 0; j< NUM_DIRS; j++)
        {
          if (DIR[i] && DIR[j] !=0 && s.inBounds(m_x+DIR[i]*k,m_y+DIR[j]*k))
          {
            if (s.getActor(m_x+DIR[i]*k,m_y+DIR[j]*k == WHALE))
            {
              run = true;
              near_whale_x = m_x+DIR[i]*k;
              near_whale_y = m_y+DIR[j]*k;
            }
            if (s.getActor(m_x+DIR[i]*k,m_y+DIR[j]*k == FISH))
            {
              feed = true;
              near_fish_x = m_x+DIR[i]*k;
              near_fish_y = m_y+DIR[j]*k;
            }         
          }      
        }
      }
    }
    
    
    if (run && feed)
    {
      
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