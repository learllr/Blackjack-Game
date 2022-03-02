#include <iostream>
#include <string.h> // Pour le strcmp().
#include <stdlib.h> // Pour le atoi().
#include "Carte.h"
#include "Paquet.h"
#include "Croupier.h"
#include "Joueur.h"
#include "JeuTxt.h"
#include "JeuSdl.h"

using namespace std;

int main()
{
    cout << "Demo" << endl;
    
    JeuSdl SDL;

    SDL.afficher("demo");

    cout<<"demo finie : Merci de nous avoir ecouté!"<<endl;


    return 0;
}
