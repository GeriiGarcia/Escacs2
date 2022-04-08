#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

// -+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+ enums
typedef enum
{
	// S'asigna un nom per a cada tipius de fitxa 
	T_REI,
	T_REINA,
	T_TORRE,
	T_ALFIL,
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
	ostream& operator<<(const Fitxa& dt);
	
private:
	PosicioTauler pos;
	int m_color, m_tipus;
	
};
