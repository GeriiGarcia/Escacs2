#include "fitxa.h"

// ----------------------- Constructors 
Fitxa::Fitxa()
{
	m_color = C_CAP;
	m_tipus = T_BUIT;
	m_moguda = false;
}


// ----------------------- Metodes
string Fitxa::fitxaToString() const
{
	string str = "";

	switch(m_color)
	{
		case C_BLANC:
			str.append("w");
		break;

		case C_NEGRE:
			str.append("b");
		break;

		default:
			str.append("_");
	}

	switch(m_tipus)
	{
		case T_REI:
			str.append("R");
		break;

		case T_REINA:
			str.append("D");
		break;

		case T_TORRE:
			str.append("T");
		break;

		case T_CABALL:
			str.append("C");
		break;

		case T_ALFIL:
			str.append("A");
		break;

		case T_PEO:
			str.append("P");
		break; 

		default:
			str.append("_");
	}
	
	return str;
}

ostream& Fitxa::operator<<(const Fitxa& dt)
{
	cout << dt.m_tipus;
}

