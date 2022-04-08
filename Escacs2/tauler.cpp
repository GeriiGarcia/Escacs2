#include "tauler.h"

vectorDePosicions Tauler::aconseguirPosicionsValides(const PosicioTauler& pos)
{
    vectorDePosicions vectorPos;
	PosicioTauler pos;

    switch(m_tauler[pos.getPosicioX()][pos.getPosicioY()].getTipus())
    {
        case T_REI:
        // hauriem de fer una funció: bool posicioValida(int afegitX, int afegitY)
        break;

        case T_REINA:
        break;

        case T_TORRE:
        break;

        case T_CABALL:
        break;

        case T_ALFIL:	
        break;

        case T_PEO:
        break;
    }

}

Tauler::Tauler()
{
    
}



void Tauler::llegirTaulerDeArxiu(const string& nomFitxer)
{
    PosicioTauler pos;
	int posVertical, posHoritzontal, tipus, color;
    
    ifstream fitxer(nomFitxer);
	string linea;

	do{
		getline(fitxer, linea);
		
		// Mirem de quin color es
		if(linea.at(0) == '0')
			color = C_BLANC;
		else	
			color = C_NEGRE;
		
		// Mirem quin tipus de fitxa es
		switch(linea.at(3))
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

		//tauler.setFitxaDelTauler(pos, tipus, color);
	}while(!fitxer.eof());

	fitxer.close();
}

void Tauler::moureFitxa(const PosicioTauler& posFrom, const PosicioTauler& posTo)
{

}

string Tauler::taulaToString() const 
{

}



/*
bool Tauler::posicioValida(Posicio pos,  int diferenciaX, int diferenciaY, int color)
{
    bool esValida = true;
    pos.x += diferenciaX;
    pos.y += diferenciaY;

    if(pos.x > ampladaTauler - 1 || pos.x < 0 || pos.y > alcadaTauler - 1 ||  pos.y < 0)
        esValida = false;
    else if(m_tauler[pos.x][pos.y].getTipus() != BUIT && m_tauler[pos.x][pos.y].getColor() == color)
        esValida = false;
    
    return esValida;
}


void Tauler::getValidMoves(Fitxa& fitxa)
{

*/
    /*
        switch case per a veure la fitxa 
        Dins de cada case mirar cap a on pot anar
        si es surt del tauler, si hi ha una altre fitxa
    */

/*
    switch (fitxa.getTipus())
    {
    // El rei es pot moure en totes direccions a una distancia de 1 casella
    case REI:
        if (posicioValida(fitxa.getPosicio(), 1, 0, fitxa.getColor()))
        {
            m_posicionsValides[m_nPosicionsValides - 1].x = fitxa.getPosicioX();
            m_posicionsValides[m_nPosicionsValides - 1].y = fitxa.getPosicioY();
            
            m_nPosicionsValides++;
         }

        break;

    case DAMA:
    
        break;

    case TORRE:

        break;

    case ALFIL:

        break;

    case CAVALL:

        break;

    case PEO:

        break;

    default:

        break;
    }


}
*/