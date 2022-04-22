#include "tauler.h"

Tauler::Tauler()
{
	/*ns fins a quin punt cal aixo, ja que la única cosa que hi ha per inicialitzar
	es una fixa que ja s'inicialitza sola*/
} 

vectorDePosicions Tauler::aconseguirPosicionsValides(const PosicioTauler & pos)
{
	/*
	REI:			REINA:			TORRE:			CABALL			ALFIL:		 	PEO			
	- - - - -		X - X - X		- - X - -		- X - X -		X - - - X		- - - - -		
	- X X X -		- X X X -		- - X - -		X - - - X		- X - X -		- - X - -	
	- X R X -		X X R X X		X X T X X		- - C - -		- - A - -		- X X X -	
	- X X X -		- X X X -		- - X - -		X - - - X		- X - X -		- - P - -	
	- - - - -		X - X - X		- - X - -		- X - X -		X - - - X		- - - - -	
	*/
	
	vectorDePosicions vectorPos;
	PosicioTauler posAuxiliar;

	switch (m_tauler[pos.getPosicioX()][pos.getPosicioY()].getTipus())
	{
	case T_REI:
		// analitzem cada posició que hi ha al voltant del rei i ens quedem amb les vàlides
		for(int i = -1; i <= 1; i++)
		{
			PosicioTauler posAuxiliar;
			posAuxiliar.setPosicioX(pos.getPosicioX() + i);
			
			for(int j = -1; j <= 1; j++)
			{
				posAuxiliar.setPosicioY(pos.getPosicioY() + j);
				
				if(posicioValida(posAuxiliar, pos))
					vectorPos.push_back(posAuxiliar);
			}
		}

		break;

	case T_REINA: //amb diagonal NE em refereixo a la diagonal de adalt a la dreta ns  si m'entens rbro v 
	
		int i = 0;
		posAuxiliar.setPosicioX(pos.getPosicioX() + i);   //diagonal NE
		posAuxiliar.setPosicioY(pos.getPosicioY() - i);
		while (posicioValida(posAuxiliar, pos))
		{
			i++;
			posAuxiliar.setPosicioX(pos.getPosicioX() + i);
			posAuxiliar.setPosicioY(pos.getPosicioY() - i);
			vectorPos.push_back(posAuxiliar);
		}

		int i = 0;
		posAuxiliar.setPosicioX(pos.getPosicioX() - i);   //diagonal NO
		posAuxiliar.setPosicioY(pos.getPosicioY() - i);
		while (posicioValida(posAuxiliar, pos))
		{
			i++;
			posAuxiliar.setPosicioX(pos.getPosicioX() - i);
			posAuxiliar.setPosicioY(pos.getPosicioY() - i);
			vectorPos.push_back(posAuxiliar);
		}

		int i = 0;
		posAuxiliar.setPosicioX(pos.getPosicioX() - i);   //diagonal SO
		posAuxiliar.setPosicioY(pos.getPosicioY() + i);
		while (posicioValida(posAuxiliar, pos))
		{
			i++;
			posAuxiliar.setPosicioX(pos.getPosicioX() - i);
			posAuxiliar.setPosicioY(pos.getPosicioY() + i);
			vectorPos.push_back(posAuxiliar);
		}

		int i = 0;
		posAuxiliar.setPosicioX(pos.getPosicioX() + i);   //diagonal SE
		posAuxiliar.setPosicioY(pos.getPosicioY() + i);
		while (posicioValida(posAuxiliar, pos))
		{
			i++;
			posAuxiliar.setPosicioX(pos.getPosicioX() + i);
			posAuxiliar.setPosicioY(pos.getPosicioY() + i);
			vectorPos.push_back(posAuxiliar);
		}

		int i = 0;
		posAuxiliar.setPosicioX(pos.getPosicioX() + i);   //horizontal E
		while (posicioValida(posAuxiliar, pos))
		{
			i++;
			posAuxiliar.setPosicioX(pos.getPosicioX() + i);
			vectorPos.push_back(posAuxiliar);
		}

		int i = 0;
		posAuxiliar.setPosicioX(pos.getPosicioX() - i);   //horizontal O
		while (posicioValida(posAuxiliar, pos))
		{
			i++;
			posAuxiliar.setPosicioX(pos.getPosicioX() - i);
			vectorPos.push_back(posAuxiliar);
		}

		int i = 0;
		posAuxiliar.setPosicioY(pos.getPosicioY() + i);   //Vertical N
		while (posicioValida(posAuxiliar, pos))
		{
			i++;
			posAuxiliar.setPosicioY(pos.getPosicioY() + i);
			vectorPos.push_back(posAuxiliar);
		}

		int i = 0;
		posAuxiliar.setPosicioY(pos.getPosicioY() - i);   //Vertical S
		while (posicioValida(posAuxiliar, pos))
		{
			i++;
			posAuxiliar.setPosicioY(pos.getPosicioY() - i);
			vectorPos.push_back(posAuxiliar);
		}


		break;

	case T_TORRE:
		//PosicioTauler posAuxiliar;
		int i;
		i = 0;
		posAuxiliar.setPosicioY(pos.getPosicioY() + i);
		while (posicioValida(posAuxiliar, pos))
		{
			i++;
			posAuxiliar.setPosicioY(pos.getPosicioY() + i);
			vectorPos.push_back(posAuxiliar);
		}

		i = 0;
		posAuxiliar.setPosicioY(pos.getPosicioY() + i);
		while (posicioValida(posAuxiliar, pos))
		{
			i--;
			posAuxiliar.setPosicioY(pos.getPosicioY() + i);
			vectorPos.push_back(posAuxiliar);
		}

		i = 0;
		posAuxiliar.setPosicioX(pos.getPosicioX() + i);
		while (posicioValida(posAuxiliar, pos))
		{
			i++;
			posAuxiliar.setPosicioX(pos.getPosicioX() + i);
			vectorPos.push_back(posAuxiliar);
		}

		i = 0;
		posAuxiliar.setPosicioX(pos.getPosicioX() + i);
		while (posicioValida(posAuxiliar, pos))
		{
			i--;
			posAuxiliar.setPosicioX(pos.getPosicioX() + i);
			vectorPos.push_back(posAuxiliar);
		}
		break;

	case T_CABALL: // ----------------------------------------------- CABALL
		//PosicioTauler posAuxiliar;

		// analitzem les posicions per columnes i només en les que es pot moure el caball
		for(int i = -2; i <= 2; i++)
		{
			posAuxiliar.setPosicioX(pos.getPosicioX() + i);

			if(i == -2 || i == 2)
			{
				posAuxiliar.setPosicioY(pos.getPosicioY() - 1);
				if(posicioValida(posAuxiliar, pos))
					vectorPos.push_back(posAuxiliar);

				posAuxiliar.setPosicioY(pos.getPosicioY() + 1);
				if(posicioValida(posAuxiliar, pos))
					vectorPos.push_back(posAuxiliar);
			}
			else if (i == -1 || i == 1)
			{
				posAuxiliar.setPosicioY(pos.getPosicioY() - 2);
				if(posicioValida(posAuxiliar, pos))
					vectorPos.push_back(posAuxiliar);

				posAuxiliar.setPosicioY(pos.getPosicioY() + 2);
				if(posicioValida(posAuxiliar, pos))
					vectorPos.push_back(posAuxiliar);
			}
		}

		break;

	case T_ALFIL:

		int i = 0;
		posAuxiliar.setPosicioX(pos.getPosicioX() + i);   //diagonal NE
		posAuxiliar.setPosicioY(pos.getPosicioY() - i);
		while (posicioValida(posAuxiliar, pos))
		{
			i++;
			posAuxiliar.setPosicioX(pos.getPosicioX() + i);
			posAuxiliar.setPosicioY(pos.getPosicioY() - i);
			vectorPos.push_back(posAuxiliar);
		}

		int i = 0;
		posAuxiliar.setPosicioX(pos.getPosicioX() - i);   //diagonal NO
		posAuxiliar.setPosicioY(pos.getPosicioY() - i);
		while (posicioValida(posAuxiliar, pos))
		{
			i++;
			posAuxiliar.setPosicioX(pos.getPosicioX() - i);
			posAuxiliar.setPosicioY(pos.getPosicioY() - i);
			vectorPos.push_back(posAuxiliar);
		}

		int i = 0;
		posAuxiliar.setPosicioX(pos.getPosicioX() - i);   //diagonal SO
		posAuxiliar.setPosicioY(pos.getPosicioY() + i);
		while (posicioValida(posAuxiliar, pos))
		{
			i++;
			posAuxiliar.setPosicioX(pos.getPosicioX() - i);
			posAuxiliar.setPosicioY(pos.getPosicioY() + i);
			vectorPos.push_back(posAuxiliar);
		}

		int i = 0;
		posAuxiliar.setPosicioX(pos.getPosicioX() + i);   //diagonal SE
		posAuxiliar.setPosicioY(pos.getPosicioY() + i);
		while (posicioValida(posAuxiliar, pos))
		{
			i++;
			posAuxiliar.setPosicioX(pos.getPosicioX() + i);
			posAuxiliar.setPosicioY(pos.getPosicioY() + i);
			vectorPos.push_back(posAuxiliar);
		}

		break;


	case T_PEO: // -------------------------------------------------- PEO
		//PosicioTauler posAuxiliar;
		posAuxiliar.setPosicioX(pos.getPosicioX());

		// fem una variable direcció que ens indiqui a quina direccio es mou el peo (depenent del color)
		int direccio = 1;
		if(getColorFitxa(pos) == C_BLANC)
			direccio = -1;

		// analitzem la posició frontal
		posAuxiliar.setPosicioY(pos.getPosicioY() + 1 * direccio);
		if(posicioValida(posAuxiliar, pos) && getColorFitxa(posAuxiliar) == C_CAP)
			vectorPos.push_back(posAuxiliar);
		

		// analitzem les posicions diagonals frontals 
		posAuxiliar.setPosicioX(pos.getPosicioX() - 1);
		if(posicioValida(posAuxiliar, pos) && getColorFitxa(posAuxiliar) != getColorFitxa(pos))
			vectorPos.push_back(posAuxiliar);
		
		posAuxiliar.setPosicioX(pos.getPosicioX() + 1);
		if(posicioValida(posAuxiliar, pos) && getColorFitxa(posAuxiliar) != getColorFitxa(pos))
			vectorPos.push_back(posAuxiliar);


		// analitzem la 2a posició frontal
		posAuxiliar.setPosicioY(pos.getPosicioY() + 2 * direccio);
		if(posicioValida(posAuxiliar, pos) && getColorFitxa(posAuxiliar) == C_CAP && !getMogudaFitxa(pos))
			vectorPos.push_back(posAuxiliar);

		
		break;
	}
	return vectorPos;
}


// Aquest procediment analitza una posició i mira si aquesta entra dins del tauler i si hi ha una fitxa del mateix color
bool Tauler::posicioValida(PosicioTauler posAuxiliar, PosicioTauler pos)
{
	bool esValida = true;

	if(posAuxiliar.getPosicioX() > COLUMNES_TAULER - 1 || posAuxiliar.getPosicioX() < 0 || posAuxiliar.getPosicioY() > FILES_TAULER - 1 ||  posAuxiliar.getPosicioY() < 0)
		esValida = false;
	else if(getTipusFitxa(posAuxiliar) != T_BUIT && getColorFitxa(posAuxiliar) == getColorFitxa(pos))
		esValida = false;

	return esValida;

}

// funcions auxiliars que ens permeten jugar amb les fitxes amb l'objectiu d'acotar codi
int Tauler::getColorFitxa(PosicioTauler pos)
{
	return m_tauler[pos.getPosicioX()][pos.getPosicioY()].getColor();
}

int Tauler::getTipusFitxa(PosicioTauler pos)
{
	return m_tauler[pos.getPosicioX()][pos.getPosicioY()].getTipus();
}

int Tauler::getMogudaFitxa(PosicioTauler pos)
{
	return m_tauler[pos.getPosicioX()][pos.getPosicioY()].getMoguda();
}


// Funcio per a llegir un tauler d'un arxiu
void Tauler::llegirTaulerDeArxiu(const string& nomFitxer)
{

	ifstream fitxer(nomFitxer);
	string linea;

	PosicioTauler pos;
	int posVertical, posHoritzontal, tipus, color;

	do {
		if (fitxer.is_open())
			std::getline(fitxer, linea);
		
		// Mirem de quin color es
		if (linea.at(0) == '0')
			color = C_BLANC;
		else if(linea.at(0) == '1')
			color = C_NEGRE;
		else
			color = C_CAP;



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
	if(getColorFitxa(posFrom) != C_CAP && posicioDinsVector(posTo, aconseguirPosicionsValides(posFrom)))// fer posicioDinsVector()
	{
		// asignar la nova posició amb la peça
		// borrar la peça de on estava
	} 
	
}

bool Tauler::posicioDinsVector(const PosicioTauler& pos, vectorDePosicions& vectorPos)
{
	int i = 0;
	bool trobat = false;

	while(!trobat && i < vectorPos.max_size())
	{
		if(pos == vectorPos.at(i))
			trobat = true;
		else
			i++;
	}
 
	return trobat;
}

// funció on guardem tota la taula en un string
string Tauler::taulaToString() const
{
	string taulaStr = "";

	for(int fila = 0; fila > FILES_TAULER; fila++)
	{
		// afegim els noms de la fila
		taulaStr.append(to_string(8 - fila));

		// afegim columna a columna les fitxes
		for(int columna = 0; columna < COLUMNES_TAULER; columna++)
		{
			taulaStr.append(" ");
			taulaStr.append(m_tauler[fila][columna].fitxaToString());
		}
			
		taulaStr.append("\n");

	}

	// afegim els noms de les files
	taulaStr.append("  a  b  c  d  e  f  g  h");
	return taulaStr;
}
