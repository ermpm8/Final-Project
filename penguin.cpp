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
  m_whale_x = DEAD_POS;
  m_whale_y = DEAD_POS;
  m_fish_x = DEAD_POS;
  m_fish_y = DEAD_POS;
  
  m_run = false;
  m_feed = false;
  
  
}

bool penguin::move(sea& s)
{
  bool moved = false;
  short x_dif;
  short y_dif;
  short move_cells;
  
  char toMove;
  
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
    checkSurroundings(s);
cout<<"Start : ("<<m_y<<","<<m_x<<")"<<endl;    
    if (m_run)
    {
      x_dif = m_x - m_whale_x;
      x_dif = (x_dif<0) ? NEG : POS;
      
      y_dif = m_y - m_whale_y;
      y_dif = (y_dif<0) ? NEG : POS;
      
      toMove = s.getActor(m_x + (x_dif*move_cells), m_y + (y_dif*move_cells));
cout<<"Space to move: ["<<toMove<<"]"<<endl;      
      
      if (s.inBounds(m_x + (x_dif*move_cells), m_y + (y_dif*move_cells))
      && (s.isEmpty(toMove) || toMove==FISH))
      {
        m_x += (x_dif*move_cells);
        m_y += (y_dif*move_cells);
        moved = true;
      }else if(s.inBounds(m_x + (x_dif*move_cells), m_y)
      && (s.isEmpty(toMove) || toMove==FISH))
      {
        m_x += (x_dif*move_cells);
        moved = true;
      }
    } else if (m_feed)
    {
      x_dif = m_x - m_fish_x;
      x_dif = (x_dif<0) ? POS : NEG;
      
      y_dif = m_y - m_whale_y;
      y_dif = (y_dif<0) ? POS : NEG;
      
      toMove = s.getActor(m_x + (x_dif*move_cells), m_y + (y_dif*move_cells));

      if (s.inBounds(m_x + (x_dif*move_cells), m_y + (y_dif*move_cells))
      && (s.isEmpty(toMove) || toMove==FISH))
      {
cout<<"Space to move: ["<<toMove<<"]"<<"\t"<<(m_y + (y_dif*move_cells))<<","<<(m_x + (x_dif*move_cells)) <<endl;
        m_x += (x_dif*move_cells);
        m_y += (y_dif*move_cells);
        moved = true;
      }
    }
cout<<"Run : "<<m_whale_y<<","<<m_whale_x<<"\t"<<m_run<<endl;    
cout<<"Feed : "<<m_fish_y<<","<<m_fish_x<<"\t"<<m_feed<<endl;    
cout<<"Moved :"<<moved<<endl;    
  
  }
  s.update(m_x, m_y, PENG);
cout<<"End : ("<<m_y<<","<<m_x<<")"<<endl;
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

void penguin::checkSurroundings(sea& s)
{
  m_feed = false;
  m_run = false;
  
  for (int k = 1; k<=PENGUIN_SIGHT; k++)
  {
    //North
    s.getActor(m_x,m_y+k)
    
    //Northeast
    
    //East
    
    //Southeast
    
    //South
    
    //Southwest
    
    //West
    
    //Northwest
  }    
  return;
}