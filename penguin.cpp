//Programmer: Evan Maynard and Justin Palermo        Date: 11/29/2017
//Class: CS1570                   Section: B
//File: penguin.cpp
//Purpose: Implementation file for the penguin class.

#include "penguin.h"
#include "sea.h"

penguin::penguin()
{
  m_health = rand() % (UPPER_HEALTH - LOWER_HEALTH) + LOWER_HEALTH;
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

void penguin::move(sea& s)
{
  bool eaten = false;
  short x_dif;
  short y_dif;
  short move_cells;  
  int ctn = 0;
  if (m_health>=100)
  {
    m_health = MAX_HEALTH;
  }
  
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
  
  if (!(s.isSurrounded(m_x,m_y,s)))
  {
    s.update(m_x, m_y, WHITESPACE);
    checkSurroundings(s);

    if (m_run)
    { 
      do
      {
        x_dif = m_x - m_whale_x;
        if (x_dif!=0)
        {
          x_dif = (x_dif<0) ? NEG : POS;
        }
        
        y_dif = m_y - m_whale_y;
        
        if (y_dif!=0)
        {
          y_dif = (y_dif<0) ? NEG : POS;
        }
        if (s.inBounds(m_x+x_dif,m_y+y_dif) && s.isEmpty(s.getActor(m_x+x_dif,m_y+y_dif)))
        {
          m_x+=x_dif;
          m_y+=y_dif;
        }else if(s.inBounds(m_x+x_dif,m_y) && s.isEmpty(s.getActor(m_x+x_dif,m_y)))
        {
          m_x+=x_dif;
        }else if(s.inBounds(m_x,m_y+y_dif) && s.isEmpty(s.getActor(m_x,m_y+y_dif)))
        {
          m_y+=y_dif;
        }else if(s.inBounds(m_x-x_dif,m_y+y_dif) && s.isEmpty(s.getActor(m_x-x_dif,m_y+y_dif)))
        {
          m_x-=x_dif;
          m_y+=y_dif;
        }//add the other directions
        ctn++;
      } while (ctn<move_cells);
    } else if (m_feed)
    {
      
      
            
      do
      {       
      x_dif = m_x - m_fish_x;
      if (x_dif!=0)
      {
        x_dif = (x_dif<0) ? POS : NEG;
      }
      
      
      
      
      y_dif = m_y - m_fish_y;
      if (y_dif!=0)
      {
        y_dif = (y_dif<0) ? POS : NEG;
      }
      
        if (s.inBounds(m_x+x_dif,m_y+y_dif) && s.getActor(m_x+x_dif,m_y+y_dif)==FISH)
        {
          m_x+=x_dif;
          m_y+=y_dif;
          eat(m_x,m_y,s);
          eaten = true;
        }else if (s.inBounds(m_x+x_dif,m_y+y_dif) && s.isEmpty(s.getActor(m_x+x_dif,m_y+y_dif)))
        {
          m_x+=x_dif;
          m_y+=y_dif;
        }else if(s.inBounds(m_x+x_dif,m_y) && s.isEmpty(s.getActor(m_x+x_dif,m_y)))
        {
          m_x+=x_dif;
        }else if(s.inBounds(m_x,m_y+y_dif) && s.isEmpty(s.getActor(m_x,m_y+y_dif)))
        {
          m_y+=y_dif;
        }else if(s.inBounds(m_x-x_dif,m_y+y_dif) && s.isEmpty(s.getActor(m_x-x_dif,m_y+y_dif)))
        {
          m_x-=x_dif;
          m_y+=y_dif;
        }else if(s.inBounds(m_x+x_dif,m_y-y_dif) && s.isEmpty(s.getActor(m_x+x_dif,m_y-y_dif)))
        {
          m_x+=x_dif;
          m_y-=y_dif;
        }else if(s.inBounds(m_x,m_y-y_dif) && s.isEmpty(s.getActor(m_x,m_y-y_dif)))
        {
          m_y-=y_dif;
        }
        
        ctn++;
      } while(ctn<move_cells && (!(eaten)));
    }
    m_health-=HEALTH_LOSS;
  }
  s.update(m_x, m_y, PENG);
  return;
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
    for (int i = 0;i<k; i++)
    {
      setStatus(s,m_x-i,m_y-k);
    }
    
    //Northeast
    for (int i = 0;i<k; i++)
    {
      setStatus(s,m_x+k-i,m_y-k);
    }
    
    //East
    for (int i = 0;i<k; i++)
    {
      setStatus(s,m_x+k,m_y+i);
    }
    
    //Southeast
    for (int i = 0;i<k; i++)
    {
      setStatus(s,m_x+k,m_y+k+i);
    }
    
    //South
    for (int i = 0;i<k; i++)
    {
      setStatus(s,m_x+i,m_y+k);
    }
    
    //Southwest
    for (int i = 0;i<k; i++)
    {
      setStatus(s,m_x-k+i,m_y+k);
    }
    
    //West
    for (int i = 0;i<k; i++)
    {
      setStatus(s,m_x-k,m_y-i);
    }
    
    //Northwest
    for (int i = 0;i<k; i++)
    {
      setStatus(s,m_x-k,m_y-k-i);
    }
  }    
  return;
}

void penguin::setStatus(sea& s,const short x, const short y)
{
  char loc = s.getActor(x,y);
  if (loc==WHALE && (!m_run))
  {
    m_run = true;
    m_whale_x = x;
    m_whale_y = y;
  }else if (loc==FISH && (!m_feed))
  {
    m_feed = true;
    m_fish_x = x;
    m_fish_y = y;
  }
  return;
}

void penguin::eat(const short x, const short y, sea& s)
{
  m_health+= s.killFish(x,y);    
  return;
}

bool penguin::isAt(const short x, const short y)
{ 
  return (m_x == x && m_y == y);
}

void penguin::spawn(const short x, const short y, const short health)
{
  setPos(x,y);
  m_health = health/2;
  return;
}