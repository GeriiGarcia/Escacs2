#pragma once

#include <iostream>
using namespace std;

// -+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+ enums
typedef enum
{
	// S'asigna un nom per a cada tipius de fitxa 
	T_REI,
	T_REINA,
	T_TORRE,
	T_ABAT,
	T_CABALL,
	T_PEO,
	T_BUIT
}TipusFitxa;

typedef enum
{
	// S'assigna un nom per a cada color de la fitxa
	C_NEGRE,
	C_BLANC,
	C_CAP
}ColorFitxa;


// -+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+ Clase PosicioTauler
class PosicioTauler
{
	public:
	// Constructors
	PosicioTauler();		// Falta fer i mirar si cal fer un constructor amb parametres

	// Setters
	void setPosicioX();		// Falta fer !!
	void setPosicioY();		// Falta fer !!

	// Getters
	int getPosicioX();		// Falta fer !!
	int getPosicioX();		// Falta fer !!

	private:
	int m_posX, m_posY;
};

// -+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+ Clase Fitxa
class Fitxa
{
public:
	// Constructors 
	Fitxa();
	
	//setters
	void setColor(int color) { m_color = color; } const
	void setTipus(int tipus) { m_tipus = tipus; } const
 
	//getters
	int getColor() { return m_color; }
	int getTipus() { return m_tipus; }

	//metodes
	string fitxaToString();
	
private:
	int m_color, m_tipus;
	
};
