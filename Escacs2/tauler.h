#pragma once
#include "fitxa.h"

#define MAX_POSICIONS_VALIDES 27 // con la reina en el centro (argumentar b�)
#define FILES_TAULER 8
#define COLUMNES_TAULER 8

class Tauler
{
public:
    // Constructors
    Tauler();

    // Setters       
    
    // Getters

    // Metodes de la clase
    void llegirTaulerDeArxiu(const string& nomFitxer); // Cal copiar i modificar el metode loadFromFile de Source.cpp
    // Falten implementar 3 metodes encara 
private:
    Fitxa m_tauler[COLUMNES_TAULER][FILES_TAULER];
};



/*
    Aqu� representem un tauler d'escacs amb les negres amunt i les blanques avall:

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