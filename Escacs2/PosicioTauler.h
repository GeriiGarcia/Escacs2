#pragma once

class PosicioTauler
{
	public:
	// Constructors
	PosicioTauler();		// Falta fer i mirar si cal fer un constructor amb parametres

	// Setters
	void setPosicioX(int num) { m_posX = num; }		
	void setPosicioY(int num) { m_posY = num; }		

	// Getters
	int getPosicioX() const { return m_posX; }
	int getPosicioY() const { return m_posY; }

	private:
	int m_posX, m_posY;
};