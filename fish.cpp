//Programmer: Evan Maynard and Justin Palermo        Date: 11/29/2017
//Class: CS1570                   Section: B
//File: fish.cpp
//Purpose: Implementation file for the fish class.

#include "fish.h"
#include "sea.h"

fish::fish()
{
  m_food = rand() % (MAX_FOOD - MIN_FOOD) + MIN_FOOD;
  m_x = DEAD_POS;
  m_y = DEAD_POS;
  m_alive = false;
}

bool fish::move(sea& s)
{
  bool moved = false;
  short x_dif;
  short y_dif;

  
  if (!(s.isSurrounded(m_x,m_y))) 
  {
		s.update(m_x, m_y, WHITESPACE);
    do
    {  
      x_dif = DIR[rand()%NUM_DIRS];
      y_dif = DIR[rand()%NUM_DIRS];
			if (m_x+x_dif < SIM_SIZE && m_x+x_dif > 0 && m_y+y_dif < SIM_SIZE &&
          m_y+y_dif > 0)
      {
        moved = true;
      }else
      {
        moved = false;
      }
     
    }while((x_dif != 0 && y_dif != 0) && (!(moved)));    		
    m_x +=x_dif;
    m_y +=y_dif;
		
		
    s.update(m_x, m_y, FISH);    
    moved = true;
  }else
  {
    moved = false;
  }
  
  return moved;
}

void fish::setPos(const short x, const short y)
{
  m_x = x;
  m_y = y;
  return;
}