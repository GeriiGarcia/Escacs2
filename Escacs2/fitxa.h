#pragma once

#include <iostream>

#define BUIT -1
#define BLANCA 0
#define NEGRA 1

#define REI 1
#define DAMA 2
#define	TORRE 3
#define	ALFIL 4
#define CAVALL 5
#define PEO 6

#define alcadaTauler 8
#define ampladaTauler 8

struct Posicio {
	int x, y;
};

class Fitxa
{
public:
	// Constructors 
	Fitxa();
	
	//setters

	//getters
	Posicio getPosicio() { return m_pos; }
	int getPosicioX() { return m_pos.x; }
	int getPosicioY() { return m_pos.y; }
	

	int getColor() { return m_color; }
	int getTipus() { return m_tipus; }

	//metodes
	void setFitxa(Posicio pos, int tipus, int color);

private:
	int m_tipus, m_color;
	Posicio m_pos;

};
