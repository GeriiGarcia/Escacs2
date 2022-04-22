#include "PosicioTauler.h"

PosicioTauler::PosicioTauler()
{
	m_posX = 0;
	m_posY = 0;
}

bool PosicioTauler::operator==(PosicioTauler pos) const
{
	bool iguals = false;
	
	if(m_posX == pos.getPosicioX() && m_posY == pos.getPosicioY())
		iguals = true;

	return iguals;
}

