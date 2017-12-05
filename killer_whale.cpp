//Programmer: Evan Maynard and Justin Palermo        Date: 11/29/2017
//Class: CS1570                   Section: B
//File: killer_whale.cpp
//Purpose: Implementation file for the killer_whale class

#include "killer_whale"
#include "sea.h"

killer_whale::killer_whale()
{
	m_kills=0;
	m_x= DEAD_POS;
	m_y= DEAD_POS;
}













void setPos(const short x, const short y)
{
	m_x=x;
	m_y=y;
	return;
}