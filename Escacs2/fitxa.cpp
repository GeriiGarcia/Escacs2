#include "fitxa.h"

// ----------------------- Constructors 
Fitxa::Fitxa()
{
	m_color = C_CAP;
	m_tipus = T_BUIT;
	m_moguda = false;
}


// ----------------------- Metodes
string Fitxa::fitxaToString()
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
			str.append("");
		break;

		case T_REINA:
			str.append("");
		break;

		case T_TORRE:
			str.append("");
		break;

		case T_CABALL:
			str.append("");
		break;

		case T_ALFIL:
			str.append("");
		break;

		case T_PEO:
			str.append("");
		break; 

		default:
			str.append("");
	}
	
	return str;
}

ostream& Fitxa::operator<<(const Fitxa& dt)
{
	cout << dt.m_tipus;
}

