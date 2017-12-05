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
  
	//findWhale(s);
	//findFish(s);
  
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
	bool foundWhale = false;
  int i = 1;
  
  do
  {
    if (m_y-i < 0)  //NORTH check
    {
      if (s.getActor(m_x, m_y-i)==WHALE) 
      {
        dist = i;
        m_avoid_x = m_x;
        m_avoid_y = m_y-i;
        foundWhale = true;
      }
    }
    
    if (m_x+i <s.getSize() && m_y-i <s.getSize())  //NORTHEAST check
    {
      if (s.getActor(m_x+i, m_y-i)==WHALE) 
      {
        dist=i;
        m_avoid_x = m_x+i;
        m_avoid_y = m_y-i;
        foundWhale = true;
      }
    }
    
    if (m_x+i <s.getSize())  //EAST check
    {
      if (s.getActor(m_x+i, m_y)==WHALE) 
      {
        dist=i;
        m_avoid_x = m_x+i;
        m_avoid_y = m_y;
        foundWhale = true;
      }
    }
    
    if (m_x+i < s.getSize() && m_y+i<s.getSize())
    {
        if (s.getActor(m_x+i, m_y+i)==WHALE) //SOUTHEAST check
      {
        dist=i;
        m_avoid_x = m_x+i;
        m_avoid_y = m_y+i;
        foundWhale = true;
      }
    }   
    
    if (m_y-i <s.getSize())
    {
      if (s.getActor(m_x, m_y-i)==WHALE) //SOUTH check
      {
        dist=i;
        m_avoid_x = m_x;
        m_avoid_y = m_y-i;
        foundWhale = true;
      }
    }
		
		if (m_x-i > 0 && m_y+i <s.getSize())
    {
      if (s.getActor(m_x-i, m_y+i)==WHALE) //SOUTHWEST check
      {
        dist=i;
        m_avoid_x = m_x-i;
        m_avoid_y = m_y+i;
        foundWhale = true;
      }      
    }
    
    if (m_x-i > 0)
    {
      if (s.getActor(m_x-i, m_y)==WHALE) //WEST check
      {
        dist=i;
        m_avoid_x = m_x-i;
        m_avoid_y = m_y;
        foundWhale = true;
      }
    }
    
    if (m_x-i > 0 && m_y-i > 0)
    {
      if (s.getActor(m_x-i, m_y-i)==WHALE) //NORTWEST check
      {
        dist=i;
        m_avoid_x = m_x-i;
        m_avoid_y = m_y-i;
        foundWhale = true;
      }
    }
        
		i++;
  }while(i < PENGUIN_SIGHT || foundWhale);
  
  
  cout<<"("<<m_avoid_y<<","<<m_avoid_x<<")"<<endl;
  return dist;
}

short penguin::findFish(sea& s)
{
	bool foundFish = false;
	short dist=-1;
	int i = 1;
	 do
  {
    if (m_y-i < 0)  //NORTH check
    {
      if (s.getActor(m_x, m_y-i)==FISH) 
      {
        dist = i;
        m_chase_x = m_x;
        m_chase_y = m_y-i;
        foundFish = true;
      }
    }
    
    if (m_x+i <s.getSize() && m_y-i <s.getSize())  //NORTHEAST check
    {
      if (s.getActor(m_x+i, m_y-i)==FISH) 
      {
        dist=i;
        m_chase_x = m_x+i;
        m_chase_y = m_y-i;
        foundFish = true;
      }
    }
    
    if (m_x+i <s.getSize())  //EAST check
    {
      if (s.getActor(m_x+i, m_y)==FISH) 
      {
        dist=i;
        m_chase_x = m_x+i;
        m_chase_y = m_y;
        foundFish = true;
      }
    }
    
    if (m_x+i < s.getSize() && m_y+i<s.getSize())
    {
        if (s.getActor(m_x+i, m_y+i)==FISH) //SOUTHEAST check
      {
        dist=i;
        m_chase_x = m_x+i;
        m_chase_y = m_y+i;
        foundFish = true;
      }
    }   
    
    if (m_y-i <s.getSize())
    {
      if (s.getActor(m_x, m_y-i)==FISH) //SOUTH check
      {
        dist=i;
        m_chase_x = m_x;
        m_chase_y = m_y-i;
        foundFish = true;
      }
    }
		
		if (m_x-i > 0 && m_y+i <s.getSize())
    {
      if (s.getActor(m_x-i, m_y+i)==FISH) //SOUTHWEST check
      {
        dist=i;
        m_chase_x = m_x-i;
        m_chase_y = m_y+i;
        foundFish = true;
      }      
    }
    
    if (m_x-i > 0)
    {
      if (s.getActor(m_x-i, m_y)==FISH) //WEST check
      {
        dist=i;
        m_chase_x = m_x-i;
        m_chase_y = m_y;
        foundFish = true;
      }
    }
    
    if (m_x-i > 0 && m_y-i > 0)
    {
      if (s.getActor(m_x-i, m_y-i)==FISH) //NORTWEST check
      {
        dist=i;
        m_chase_x = m_x-i;
        m_chase_y = m_y-i;
        foundFish = true;
      }
    }
		i++;
  }while(i < PENGUIN_SIGHT || foundFish);
	cout<<"("<<m_chase_x<<","<<m_chase_y<<")"<<endl;
  return dist;
}

void penguin::setPos(const short x, const short y)
{
  m_x = x;
  m_y = y;
  return;
}