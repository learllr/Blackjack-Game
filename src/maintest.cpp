#include <iostream>

#include "Carte.h"
#include "Paquet.h"
#include "Croupier.h"
#include "Joueur.h"
#include "JeuTxt.h"
#include "JeuSdl.h"

using namespace std;

int main()
{
    cout << "Test des fonctions des classes :" << endl;
    Carte carte;
    carte.testRegressionCarte();
    
    Paquet paq;
    paq.testRegressionPaquet();
    
    Joueur j;
    j.testRegressionJoueur();

    
    char **argument;

    argument = new char* [10]; 

    for(unsigned int i = 0; i<6 ; i++)
    {
        argument[i] = new char[20];
    }

    argument[0][0] = 'b';
    argument[1][0] = 't';
    argument[2][0] = '1';
    argument[3][0] = '1';
    argument[4][0] = '1';
    argument[4][1] = '1';
    argument[4][2] = '1';
    argument[4][3] = '1';
    argument[5][0] = 'J';

    

    JeuTxt JTNiveau1(argument);
    JTNiveau1.testRegressionJeuTxt();

    for(unsigned int i = 0; i<6 ; i++)
    {
       delete argument[i];
    }

    delete argument;
    
    return 0;
}
