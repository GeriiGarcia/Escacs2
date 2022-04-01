#pragma once
#include "fitxa.h"

#define MAX_POSICIONS_VALIDES 27 // con la reina en el centro (argumentar bé)

class Tauler
{
public:
    // Constructors
    Tauler();

    // Setters       
    void setFitxaDelTauler(Posicio pos, int tipus, int color) { m_tauler[pos.x][pos.y].setFitxa(pos, tipus, color); }
    // Metodes
    int getTipusFitxa(Posicio pos) { return m_tauler[pos.x][pos.y].getTipus();}
    void getValidMoves(Fitxa& fitxa);
    bool posicioValida(Posicio pos, int diferenciaX, int diferenciaY, int color);
private:
    Fitxa m_tauler[ampladaTauler][alcadaTauler];

    Posicio m_posicionsValides[MAX_POSICIONS_VALIDES];
    int m_nPosicionsValides;
};



/*
    Aquí representem un tauler d'escacs amb les negres amunt i les blanques avall:

        i/j 0       1       2       3       4       5       6       7
        0   TORRE   CAVALL  ALFIL   DAMA    REI     ALFIL   CAVALL  TORRE
        1   PEO     PEO     PEO     PEO     PEO     PEO     PEO     PEO
        2   BUIT    BUIT    BUIT    BUIT    BUIT    BUIT    BUIT    BUIT
        3   BUIT    BUIT    BUIT    BUIT    BUIT    BUIT    BUIT    BUIT
        4   BUIT    BUIT    BUIT    BUIT    BUIT    BUIT    BUIT    BUIT
        5   BUIT    BUIT    BUIT    BUIT    BUIT    BUIT    BUIT    BUIT
        6   PEO     PEO     PEO     PEO     PEO     PEO     PEO     PEO
        7   TORRE   CAVALL  ALFIL   DAMA    REI     ALFIL   CAVALL  TORRE
*/