#include "tauler.h"



int main()
{
	Tauler tauler;
	tauler.llegirTaulerDeArxiu("taulerInicial.txt");
	cout << tauler.taulaToString();
		
	return 0;
}

