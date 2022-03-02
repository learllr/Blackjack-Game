#include <iostream>
#include <string.h> // Pour le strcmp().
#include <stdlib.h> // Pour le atoi().
#include "Paquet.h"
#include "Croupier.h"
#include "Joueur.h"
#include "JeuTxt.h"
#include "JeuSdl.h"

// Code couleur dans le terminal.
#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"

using namespace std;

int main(int argc, char **argv)
{
    // strcmp renvoie 0 si c'est =
    if ((argc == 2) && (!strcmp(argv[1], "règles"))) // Pour afficher les règles.
    {
        cout << endl
             << "Voir règles cahier des charges :" << endl;
        cout << endl;
    }
    // Pour lancer le jeu en format textuel.
    else if ((argc == 6) && (!strcmp(argv[1], "txt")) && ((atoi(argv[2]) >= 1) && (atoi(argv[2]) <= 2)) && ((atoi(argv[3]) >= 1) && (atoi(argv[3]) <= 8)) && ((atoi(argv[4]) >= 500) && (atoi(argv[4]) <= 10000)))
    {
        JeuTxt j(argv);
        j.executionJeuTxt();
    }
    // Pour lancer le jeu en format sdl.
    else if ((argc == 2) && (!strcmp(argv[1], "sdl")))
    {
        JeuSdl jsdl;
        jsdl.afficher("normal");
    }
    // Pas de paramètres, juste l'exécutable.
    else
    {
        cout << endl;

        cout << CYN " Pour avoir les règles, tapez la commande :" << endl;
        cout << RED " ./bin/blackjack règles" << endl
             << endl;

        cout << CYN " Pour lancer le jeu en format textuel, tapez la commande :" << endl;
        cout << RED " ./bin/blackjack txt 1 5 1000 Hubert" << endl;
        cout << CYN " Second paramètre : Le niveau du jeu (1 ou 2)." << endl;
        cout << CYN " Troisième paramètre : Le nombre de paquets (entre 1 et 8)." << endl;
        cout << CYN " Quatrième paramètre : Le nombre de jetons du joueur (entre 500 et 10 000)." << endl;
        cout << CYN " Cinquième paramètre : Le nom du joueur." << endl
             << endl;

        cout << CYN " Pour lancer le jeu en format sdl, tapez la commande :" << endl;
        cout << RED " ./bin/blackjack sdl" NC << endl
             << endl;
    }
    return 0;
}
