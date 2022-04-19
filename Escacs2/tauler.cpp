#include "tauler.h"

Tauler::Tauler()
{
	/*ns fins a quin punt cal aixo, ja que la única cosa que hi ha per inicialitzar
	es una fixa que ja s'inicialitza sola*/
}

vectorDePosicions Tauler::aconseguirPosicionsValides(const PosicioTauler & pos)
{
	vectorDePosicions vectorPos;
	

	switch (m_tauler[pos.getPosicioX()][pos.getPosicioY()].getTipus())
	{
	case T_REI:
		// analitzem cada posició que hi ha al voltant del rei i ens quedem amb les vàlides
		for(int i = -1; i < 2; i++)
		{
			PosicioTauler posAuxiliar;
			posAuxiliar.setPosicioX(pos.getPosicioX() + i);
			
			for(int j = -1; j < 2; j++)
			{
				posAuxiliar.setPosicioY(pos.getPosicioY() + j);
				
				if(posicioValida(posAuxiliar, pos))
					vectorPos.push_back(posAuxiliar);
			}
		}

		break;

	case T_REINA:
		break;

	case T_TORRE:
		PosicioTauler posAuxiliar;
		int i;
		i = 0;
		posAuxiliar.setPosicioY(pos.getPosicioY + i);
		while (posicioValida(posAuxiliar, pos))
		{
			i++;
			posAuxiliar.setPosicioY(pos.getPosicioY + i);
			vectorPos.push_back(posAuxiliar);
		}

		i = 0;
		posAuxiliar.setPosicioY(pos.getPosicioY + i);
		while (posicioValida(posAuxiliar, pos))
		{
			i--;
			posAuxiliar.setPosicioY(pos.getPosicioY + i);
			vectorPos.push_back(posAuxiliar);
		}

		i = 0;
		posAuxiliar.setPosicioX(pos.getPosicioX + i);
		while (posicioValida(posAuxiliar, pos))
		{
			i++;
			posAuxiliar.setPosicioX(pos.getPosicioX + i);
			vectorPos.push_back(posAuxiliar);
		}

		i = 0;
		posAuxiliar.setPosicioX(pos.getPosicioX + i);
		while (posicioValida(posAuxiliar, pos))
		{
			i--;
			posAuxiliar.setPosicioX(pos.getPosicioX + i);
			vectorPos.push_back(posAuxiliar);
		}
		break;

	case T_CABALL:
		break;

	case T_ALFIL:
		break;

	case T_PEO:
		PosicioTauler posAuxiliar;
		posAuxiliar.setPosicioX(pos.getPosicioX());

		// fem una variable direcció que ens indiqui a quina direccio es mou el peo (depenent del color)
		int direccio = 1;
		if(m_tauler[pos.getPosicioX()][pos.getPosicioY()].getColor() == C_BLANC)
			dirrecio = -1;


		posAuxiliar.setPosicioY(pos.getPosicioY() + 1 * direccio);
		if(posicioValida(posAuxiliar, pos) && m_tauler[posAuxiliar.getPosicioX()][posAuxiliar.getPosicioY()].getColor() == C_CAP)
			vectorPos.push_back(posAuxiliar);
		
		posAuxiliar.setPosicioY(pos.getPosicioY() + 2 * direccio);
		if(posicioValida(posAuxiliar, pos) && m_tauler[posAuxiliar.getPosicioX()][posAuxiliar.getPosicioY()].getColor() == C_CAP)
			vectorPos.push_back(posAuxiliar);

		posAuxiliar.setPosicioY(pos.getPosicioY() + 1 * direccio);
		if(posicioValida(posAuxiliar, pos) && m_tauler[posAuxiliar.getPosicioX()][posAuxiliar.getPosicioY()].getColor() != m_tauler[pos.getPosicioX()][pos.getPosicioY()].getColor())
			vectorPos.push_back(posAuxiliar);
		break;
	}

}


bool Tauler::posicioValida(PosicioTauler posAuxiliar, PosicioTauler pos)
{
	// Aquest procediment analitza una posició i mira si aquesta entra dins del tauler i si hi ha una fitxa del mateix color
	bool esValida = true;

	if(posAuxiliar.getPosicioX() > ampladaTauler - 1 || posAuxiliar.getPosicioX() < 0 || posAuxiliar.getPosicioY > alcadaTauler - 1 ||  posAuxiliar.getPosicioY < 0)
		esValida = false;
	else if(m_tauler[posAuxiliar.getPosicioX()][posAuxiliar.getPosicioY()].getTipus() != BUIT && m_tauler[posAuxiliar.getPosicioX()][posAuxiliar.getPosicioY()].getColor() == m_tauler[pos.getPosicioX()][pos.getPosicioY()].getColor())
		esValida = false;

	return esValida;

}


void Tauler::llegirTaulerDeArxiu(const string& nomFitxer)
{
	PosicioTauler pos;
	int posVertical, posHoritzontal, tipus, color;

	ifstream fitxer(nomFitxer);
	string linea;

	do {
		getline(fitxer, linea);

		// Mirem de quin color es
		if (linea.at(0) == '0')
			color = C_BLANC;
		else
			color = C_NEGRE;

		// Mirem quin tipus de fitxa es
		switch (linea.at(3))
		{
		case 'R':
			tipus = T_REI;
			break;

		case 'D':
			tipus = T_REINA;
			break;

		case 'T':
			tipus = T_TORRE;
			break;

		case 'A':
			tipus = T_ALFIL;
			break;

		case 'C':
			tipus = T_CABALL;
			break;

		case 'P':
			tipus = T_PEO;
			break;
		}

		// Mirem la seva posició Horitzontal
		switch (linea.at(4))
		{
		case 'a':
			posHoritzontal = 0;
			break;
		case 'b':
			posHoritzontal = 1;
			break;
		case 'c':
			posHoritzontal = 2;
			break;
		case 'd':
			posHoritzontal = 3;
			break;
		case 'e':
			posHoritzontal = 4;
			break;
		case 'f':
			posHoritzontal = 5;
			break;
		case 'g':
			posHoritzontal = 6;
			break;
		case 'h':
			posHoritzontal = 7;
			break;
		}

		// Mirem la seva posició vertical
		switch (linea.at(5))
		{
		case '1':
			posVertical = 7;
			break;
		case '2':
			posVertical = 6;
			break;
		case '3':
			posVertical = 5;
			break;
		case '4':
			posVertical = 4;
			break;
		case '5':
			posVertical = 3;
			break;
		case '6':
			posVertical = 2;
			break;
		case '7':
			posVertical = 1;
			break;
		case '8':
			posVertical = 0;
			break;
		}

		pos.setPosicioX(posHoritzontal);
		pos.setPosicioY(posVertical);

		m_tauler[posVertical][posHoritzontal].setColor(color);
		m_tauler[posVertical][posHoritzontal].setTipus(tipus);
		
	} while (!fitxer.eof());

	fitxer.close();
}

void Tauler::moureFitxa(const PosicioTauler& posFrom, const PosicioTauler& posTo)
{
	vectorDePosicions vector = aconseguirPosicionsValides(posFrom);

	int i = 0;
	while ((vector[i] != posTo) && (i < vector.size())) //es busca si en el vector existeix posTo
	{
		i++;
	}
	
	if (i != vector.size() - 1) //si el while no ha arribat al final doncs es cambia la posicio de la fitxa
	{
		m_tauler[posFrom.getPosicioX()][posFrom.getPosicioY()].setPosicioX(posTo.getPosicioX()); //ns si esta be
		m_tauler[posFrom.getPosicioX()][posFrom.getPosicioY()].setPosicioY(posTo.getPosicioY());
	}
	else
	{
		/*doncs dir que no s'ha trobat posTo i que escolleixi un altre posicio
		  ns fins a quin punt es podria fer un bool i que en el main es repeteixi aquesta funcio fins
		  que sigui true*/
	}
}

string Tauler::taulaToString() const
{

}
