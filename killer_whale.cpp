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

void killer_whale::move(sea &s)
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
			
			if (s.inBounds(m_x+x_dif,m_y+y_dif)&&s.getActor(m_x+x_dif,m_y+y_dif)==PENG)
			{
				m_x+=x_dif;
				m_y+=y_dif;
				eat(m_x,m_y,s);
			}else if(s.inBounds(m_x+x_dif,m_y+y_dif) && s.isEmpty(s.getActor(m_x+x_dif,m_y+y_dif)))
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
		}while(ctn<WHALES_MOVE_CELLS);
	}
	s.update(m_x, m_y, WHALE);
	return;
}

void killer_whale::eat(const short x, const short y, sea& s)
{
	s.killPenguin(x,y);
	updateKills();
	return;
}
	
void killer_whale::checkSurroundings(sea& s)
{
	m_feed = false;
	bool penguinFound=false;
	short k=1;
	while(!(penguinFound))
	{
    
		//North
		for(int i=0;i<k;i++)
		{
			if(s.getActor(m_x-i,m_y-k)==PENG)
			{
				penguinFound=true;
        m_penguin_x = m_x-i;
        m_penguin_y = m_y-k;
			}
		}
		
		//Northeast
		for(int i=0;i<k;i++)
		{
			if(s.getActor(m_x+k,m_y-k)==PENG)
			{
				penguinFound=true;
        m_penguin_x = m_x+k;
        m_penguin_y = m_y-k;
			}
		}
		
		//East
		for(int i=0;i<k;i++)
		{
			if(s.getActor(m_x+k,m_y+i)==PENG)
			{
				penguinFound=true;
        m_penguin_x = m_x+k;
        m_penguin_y = m_y+i;
			}
		}
		
		//Southeast
		for(int i=0;i<k;i++)
		{
			if(s.getActor(m_x+k,m_y+k+i)==PENG)
			{
				penguinFound=true;
        m_penguin_x = m_x+k;
        m_penguin_y = m_y+k+i;
			}
		}
		
		//South
		for(int i=0;i<k;i++)
		{
			if(s.getActor(m_x+i,m_y+k+i)==PENG)
			{
				penguinFound=true;
        m_penguin_x = m_x+i;
        m_penguin_y = m_y+k+i;
			}
		}
		
		//Southwest
		for(int i=0;i<k;i++)
		{
			if(s.getActor(m_x-k+i,m_y+k)==PENG)
			{
				penguinFound=true;
        m_penguin_x = m_x-k+i;
        m_penguin_y = m_y+k+k;
			}
		}
		
		//West
		for(int i=0;i<k;i++)
		{
			if(s.getActor(m_x-k,m_y-k-i)==PENG)
			{
				penguinFound=true;
        m_penguin_x = m_x-k;
        m_penguin_y = m_y-k-i;
			}
		}
		
		//Northwest
		for(int i=0;i<k;i++)
		{
			if(s.getActor(m_x-k,m_y-k-i)==PENG)
			{
				penguinFound=true;
        m_penguin_x = m_x-k;
        m_penguin_y = m_y-k-i;
			}
		}
    k++;
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