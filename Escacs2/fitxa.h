#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "PosicioTauler.h"

using namespace std;

// -+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+ enum
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
	void setColor(int color) { m_color = color; } 
	void setTipus(int tipus) { m_tipus = tipus; } 
	void setMoguda(int moguda) { m_moguda = moguda; } 
	
	//getters
	int getColor() const { return m_color; } 
	int getTipus() const { return m_tipus; } 
	int getMoguda() const { return m_moguda; } 

	//metodes
	string fitxaToString() const;
	

private:
	PosicioTauler pos;
	int m_color, m_tipus;
	bool m_moguda;
	
};
