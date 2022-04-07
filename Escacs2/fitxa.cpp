#include "fitxa.h"

// ----------------------- Constructors 
Fitxa::Fitxa()
{
	m_color = 0;
	m_tipus = -1;
	m_pos.x = 0;
	m_pos.y = 0;
}


// ----------------------- Getters i setters
void Fitxa::setFitxa(Posicio pos, int tipus, int color)
{
	m_pos.x = pos.x;
	m_pos.y = pos.y;
	m_tipus = tipus;
	m_color = color;
}

