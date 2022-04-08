#include "tauler.h"
#include <fstream>
#include <string>


using namespace std;



void loadBoardFromFile(const string& nomFitxer, Tauler &tauler);
int main()
{
	Tauler tauler;
	loadBoardFromFile("taulerInicial.txt", tauler);
	
	PosicioTauler pos;

	for (int i = 0; i < FILES_TAULER; i++)
	{
		pos.setPosicioX(i);
		for (int j = 0; j < COLUMNES_TAULER; j++){
			pos.setPosicioY(j);
			cout << tauler.getFitxa(i,j) << "\t";
		}
		cout << endl;
	}

	return 0;
}


// Carreguem una partida des de un arxiu ".txt"
void loadBoardFromFile(const string& nomFitxer, Tauler &tauler) 
{
	ifstream fitxer(nomFitxer);
	string linea;

	PosicioTauler pos;
	int posVertical, posHoritzontal, tipus, color;

	do{
		getline (fitxer, linea);
		
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

		pos.x = posVertical;
		pos.y = posHoritzontal;

		tauler.setFitxaDelTauler(pos, tipus, color);
	}while(!fitxer.eof());

	fitxer.close();
}

