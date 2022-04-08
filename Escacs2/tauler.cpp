#include "tauler.h"


/*
Tauler::Tauler()
{
    
}


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
    // El rei es pot moure en totes direccions a una dist�ncia de 1 casella
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