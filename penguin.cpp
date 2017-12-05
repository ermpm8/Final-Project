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
    if (s.getActor(m_x+i, m_y+i+1)==WHALE) //NORTH check
    {
      dist = i;
      m_avoid_x = m_x+i;
      m_avoid_y = m_y+i+1;
    }else if (s.getActor(m_x+i+1, m_y+i+1)==WHALE) //NORTHEAST check
    {
			dist=i;
			m_avoid_x = m_x+i+1;
			m_avoid_y = m_y+i+1;
    }else if (s.getActor(m_x+i+1, m_y+i)==WHALE) //EAST check
		{
			dist=i;
			m_avoid_x = m_x+i+1;
			m_avoid_y = m_y+i;
		}else if (s.getActor(m_x+i+1, m_y+i-1)==WHALE) //SOUTHEAST check
		{
			dist=i;
			m_avoid_x = m_x+i+1;
			m_avoid_y = m_y+i-1;
		}else if (s.getActor(m_x+i, m_y+i-1)==WHALE) //SOUTH check
		{
			dist=i;
			m_avoid_x = m_x+i;
			m_avoid_y = m_y+i-1;
		}else if (s.getActor(m_x+i-1, m_y+i-1)==WHALE) //SOUTHWEST check
		{
			dist=i;
			m_avoid_x = m_x+i-1;
			m_avoid_y = m_y+i-1;
		}else if(s.getActor(m_x+i-1, m_y+i)==WHALE) //WEST check
		{
			dist=i;
			m_avoid_x = m_x+i-1;
			m_avoid_y = m_y+i+1;
		}else if(s.getActor(m_x+i-1, m_y+i+1)==WHALE) //NORTWEST check
		{
			dist=i;
			m_avoid_x = m_x+i-1;
			m_avoid_y = m_y+i+1;
		}
  }
  
  
  cout<<"("<<m_avoid_y<<","<<m_avoid_x<<")"<<endl;
  return dist;
}

short penguin::findFish(sea& s)
{
	short dist=-1;
	
	for (int i = 0; i<PENGUIN_SIGHT; i++)
	{
		if (s.getActor(m_x+i, m_y+i+1)==FISH) //NORTH check
		{
			dist=i;
			m_chase_x = m_x+i;
			m_chase_y = m_y+i+1;
		}else if (s.getActor(m_x+i+1, m_y+i+1)==FISH) //NORTHEAST check
		{
			dist=i;
			m_chase_x = m_x+i+1;
			m_chase_y = m_y+i+1;
		}else if (s.getActor(m_x+i+1, m_y+i)==FISH) //EAST check
		{
			dist=i;
			m_chase_x = m_x+i+1;
			m_chase_y = m_y+i;
	  }else if (s.getActor(m_x+i+1, m_y+i-1)==FISH) //SOUTHEAST check
		{
			dist=i;
			m_chase_x = m_x+i+1;
		  m_chase_y = m_y+i-1;
		}else if (s.getActor(m_x+i, m_y+i-1)==FISH)  //SOUTH check
		{
			dist=i;
			m_chase_x = m_x+i;
			m_chase_y = m_y+i-1;
		}else if (s.getActor(m_x+i-1, m_y+i-1)==FISH) //SOUTHWEST check
		{
			dist=i;
			m_chase_x = m_x+i-1;
			m_chase_y = m_y+i-1;
		}else if (s.getActor(m_x+i-1, m_y+i)==FISH) //WEST check
		{
			dist=i;
			m_chase_x = m_x+i-1;
			m_chase_y = m_y+i;
		}else if (s.getActor(m_x+i-1, m_y+i+1)==FISH) //NORTHWEST check
		{
			dist=i;
			m_chase_x = m_x+i-1;
			m_chase_y = m_y+i+1;
		}
	}
	cout<<"("<<m_chase_y<<","<<m_chase_x<<")"<<endl;
  return dist;
}

void penguin::setPos(const short x, const short y)
{
  m_x = x;
  m_y = y;
  return;
}