/**
 * @file JeuTxt.h
 * @brief Le jeu blackjack en version textuel
 * @author TAIBI Youssef, BEN JEMIA Boran, ROULLIER Léa
 * @version 0.2 (démonstration finale)
 * @date 10 mai 2021
**/

#ifndef jeuTxt_h
#define jeuTxt_h
#include <iostream>
#include <string.h>
#include "Carte.h"
#include "Paquet.h"
#include "Croupier.h"
#include "Joueur.h"

using namespace std;

/**
 * @class JeuTxt
**/
class JeuTxt
{
    /**
     * @brief Les données membres privées de la classe JeuTxt
     * @param paquet Paquet de cartes
     * @param croupier Croupier du jeu
     * @param joueur Joueur du jeu
     * @param stop Booléen qui sert à tenir la boucle infinie du jeu
     * @param niveauJeu Entier positif qui contient le niveau du jeu saisi par le joueur (1 ou 2)
     * @param nbPaquets Entier positif qui contient le nombre de paquets saisi par le joueur (1 à 7)
    **/
    private:
    Paquet paquet;
    Croupier croupier;
    Joueur joueur;
    bool stop;
    unsigned int niveauJeu;
    unsigned int nbPaquets;

    public:

    /*
    ----- Constructeur/Destructeur -----
    */

    /**
     * @brief Constructeur de JeuTxt qui démarre le jeu et récupère les données saisies par l'utilisateur
    **/
    JeuTxt(char** argv);

    /**
     * @brief Destructeur de JeuTxt
    **/
    ~JeuTxt();


    /*
    ----- Autres fonctions membres -----
    */

    /**
     * @fn casCouleur(Carte *c) const
     * @brief Traduit la couleur d'une carte (T -> de Trèfle)
     * @param c Carte pour récupérer sa couleur
     * @return Retourne une chaîne de caractères
    **/
    string casCouleur(Carte *c) const;

    /**
     * @fn casValeur(Carte *c) const
     * @brief Traduit la valeur d'une carte (V -> Valet)
     * @param c Carte pour récupérer sa valeur
     * @return Retourne une chaîne de caractères
    **/
    string casValeur(Carte *c) const;

    /**
     * @fn executionJeuTxt() -> void
     * @brief Demande au joueur la mise de départ
    **/
    void choisirMise();

    /**
     * @fn choixJoueur(Carte *c)
     * @brief Demande au joueur son choix de jeu pour le paquet initial
     * @param c Carte du joueur
     * @return Retourne un entier positif
    **/
    unsigned int choixJoueur(Carte *c);

    /**
     * @fn choixJoueurSplit()
     * @brief Demande au joueur son choix de jeu pour le paquet split
     * @return Retourne un entier positif
    **/
    unsigned int choixJoueurSplit();

    /**
     * @fn actionJoueur(Carte *c) -> bool
     * @brief Action déclenchée par le choix du joueur
     * @param c Carte du joueur
    **/
    bool actionJoueur(Carte *c);

    /**
     * @fn actionCroupier() -> void
     * @brief Action déclenchée par le croupier
    **/
    void actionCroupier();

    /**
     * @fn affichagePaquets() -> void
     * @brief Affichage cout des paquets du jeu
    **/
   void affichagePaquets();

    /**
     * @fn executionJeuTxt() -> void
     * @brief Execution du jeu blackjack
    **/
    void executionJeuTxt();


    /*
    ----- Test de régression -----
    */

    /**
     * @fn testRegressionJeuTxt() -> void
     * @brief Réalise les tests de régression de la classe JeuTxt
    **/
    void testRegressionJeuTxt();


    /*
    ----- Fonctions pour la démo -----
    */

    void demo();

    
};

#endif
