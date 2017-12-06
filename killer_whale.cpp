//Programmer: Evan Maynard and Justin Palermo        Date: 11/29/2017
//Class: CS1570                   Section: B
//File: killer_whale.cpp
//Purpose: Implementation file for the killer_whale class

#include "killer_whale.h"
#include "sea.h"

killer_whale::killer_whale()
{
	m_kills=0;
	m_x= DEAD_POS;
	m_y= DEAD_POS;
}
void killer_whale::setPos(const short x, const short y)
{
  m_x = x;
  m_y = y;
  return;
}

void killer_whale::move(sea &s, penguin penguins[NUM_PENG])
{
	short x_dif;
	short y_dif;
	int ctn=0;
	
	if (!(s.isSurrounded(m_x,m_y,s)))
	{
		s.update(m_x, m_y, WHITESPACE);
		checkSurroundings(s);
		do
		{
      
			x_dif=m_x-m_penguin_x;
			if (x_dif!=0)
			{
				x_dif = (x_dif<0) ? POS : NEG;
			}
				
			y_dif=m_y-m_penguin_y;
			if(y_dif!=0)
			{
				y_dif= (y_dif<0) ? POS : NEG;
		  }
			
			if (s.inBounds(m_x+x_dif,m_y+y_dif)&&
      s.getActor(m_x+x_dif,m_y+y_dif)==PENG)
			{
				m_x+=x_dif;
				m_y+=y_dif;
				eat(m_x,m_y,s, penguins);
      }else if (s.inBounds(m_x+x_dif,m_y) &&
      s.getActor(m_x+x_dif,m_y)==PENG)
      {
        m_x+=x_dif;
        eat(m_x,m_y,s, penguins);
      }else if (s.inBounds(m_x,m_y+y_dif) &&
      s.getActor(m_x,m_y+y_dif)==PENG)
      {
        m_y+=y_dif;
        eat(m_x,m_y,s, penguins);
      }else if(s.inBounds(m_x+x_dif,m_y+y_dif) && 
      s.isEmpty(s.getActor(m_x+x_dif,m_y+y_dif)))
			{
        m_x+=x_dif;
        m_y+=y_dif;
      }else if(s.inBounds(m_x+x_dif,m_y) && 
      s.isEmpty(s.getActor(m_x+x_dif,m_y)))
      {
        m_x+=x_dif;
      }else if(s.inBounds(m_x,m_y+y_dif) &&
      s.isEmpty(s.getActor(m_x,m_y+y_dif)))
      {
        m_y+=y_dif;
      }else if(s.inBounds(m_x-x_dif,m_y+y_dif) &&
      s.isEmpty(s.getActor(m_x-x_dif,m_y+y_dif)))
      {
        m_x-=x_dif;
        m_y+=y_dif;
      }else if(s.inBounds(m_x+x_dif,m_y-y_dif) &&
      s.isEmpty(s.getActor(m_x+x_dif,m_y-y_dif)))
      {
        m_x+=x_dif;
        m_y-=y_dif;
      }else if(s.inBounds(m_x,m_y-y_dif) &&
      s.isEmpty(s.getActor(m_x,m_y-y_dif)))
      {
        m_y-=y_dif;
      }else if(s.inBounds(m_x-x_dif,m_y) &&
      s.isEmpty(s.getActor(m_x-x_dif,m_y)))
      {
        m_x-=x_dif;
      }        
		  ctn++;
		}while(ctn<WHALES_MOVE_CELLS);
	}
	s.update(m_x, m_y, WHALE);
	return;
}

void killer_whale::eat(const short x, const short y, sea& s,
 penguin penguins[NUM_PENG])
{
  if (s.getActor(x,y) == PENG)
  {
    s.killPenguin(x,y,penguins);
	  updateKills();
  }
	
	return;
}
	
void killer_whale::checkSurroundings(sea& s)
{
	bool penguinFound=false;
	short k=1;
  short ctn = 0;
	while((!(penguinFound)) && ctn<MAX_CHECKS)
	{
    
		//North
		for(int i=0;i<k;i++)
		{
			if(s.inBounds(m_x-i,m_y-k) && s.getActor(m_x-i,m_y-k)==PENG
      && !(penguinFound))
			{
				penguinFound=true;
        m_penguin_x = m_x-i;
        m_penguin_y = m_y-k;
			}
		}
		
		//Northeast
		for(int i=0;i<k;i++)
		{
			if(s.inBounds(m_x+k,m_y-k) && s.getActor(m_x+k,m_y-k)==PENG
      && !(penguinFound))
			{
				penguinFound=true;
        m_penguin_x = m_x+k;
        m_penguin_y = m_y-k;
			}
		}
		
		//East
		for(int i=0;i<k;i++)
		{
			if(s.inBounds(m_x+k,m_y+i) && s.getActor(m_x+k,m_y+i)==PENG &&
      !(penguinFound))
			{
				penguinFound=true;
        m_penguin_x = m_x+k;
        m_penguin_y = m_y+i;
			}
		}
		
		//Southeast
		for(int i=0;i<k;i++)
		{
			if(s.inBounds(m_x+k,m_y+k+i) && s.getActor(m_x+k,m_y+k+i)==PENG &&
      !(penguinFound))
			{
				penguinFound=true;
        m_penguin_x = m_x+k;
        m_penguin_y = m_y+k+i;
			}
		}
		
		//South
		for(int i=0;i<k;i++)
		{
			if(s.inBounds(m_x+i,m_y+k+i) && s.getActor(m_x+i,m_y+k+i)==PENG &&
      !(penguinFound))
			{
				penguinFound=true;
        m_penguin_x = m_x+i;
        m_penguin_y = m_y+k+i;
			}
		}
		
		//Southwest
		for(int i=0;i<k;i++)
		{
			if(s.inBounds(m_x-k+i,m_y+k) && s.getActor(m_x-k+i,m_y+k)==PENG &&
      !(penguinFound))
			{
				penguinFound=true;
        m_penguin_x = m_x-k+i;
        m_penguin_y = m_y+k+k;
			}
		}
		
		//West
		for(int i=0;i<k;i++)
		{
			if(s.inBounds(m_x-k,m_y-k-i) && s.getActor(m_x-k,m_y-k-i)==PENG && 
      !(penguinFound))
			{
				penguinFound=true;
        m_penguin_x = m_x-k;
        m_penguin_y = m_y-k-i;
			}
		}
		
		//Northwest
		for(int i=0;i<k;i++)
		{
			if(s.inBounds(m_x-k,m_y-k-i) && s.getActor(m_x-k,m_y-k-i)==PENG &&
      !(penguinFound))
			{
				penguinFound=true;
        m_penguin_x = m_x-k;
        m_penguin_y = m_y-k-i;
			}
		}
    k++;
    ctn++;
	}
  
  return;
}

void killer_whale::updateKills()
{
	m_kills+=1;
	return;
}


short killer_whale::getKills() const
{
  return m_kills;
}