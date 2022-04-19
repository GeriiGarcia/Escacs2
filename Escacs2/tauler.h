#pragma once
#include "fitxa.h"
#include "PosicioTauler.h"

#define FILES_TAULER 8
#define COLUMNES_TAULER 8

typedef vector<PosicioTauler> vectorDePosicions;

class Tauler
{
public:
    // Constructors
    Tauler();

    // Setters       
    
    // Getters
    Fitxa getFitxa(int x, int y) { return m_tauler[x][y]; }
    // Metodes de la clase
    void llegirTaulerDeArxiu(const string& nomFitxer); // Cal copiar i modificar el metode loadFromFile de Source.cpp
    vectorDePosicions aconseguirPosicionsValides(const PosicioTauler& pos);
    void moureFitxa(const PosicioTauler& posFrom, const PosicioTauler& posTo);
    string taulaToString() const;
    

private:
    Fitxa m_tauler[COLUMNES_TAULER][FILES_TAULER];
    
};


/*
    Aqui representem un tauler d'escacs amb les negres amunt i les blanques avall:

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