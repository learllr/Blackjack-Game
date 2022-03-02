/**
 * @file Paquet.h
 * @brief Le paquet de cartes d'un jeu
 * @author TAIBI Youssef, BEN JEMIA Boran, ROULLIER Léa
 * @version 0.2 (démonstration finale)
 * @date 10 mai 2021
**/

#ifndef paquet_h
#define paquet_h

#include "Carte.h"
#include <vector>
#include <iostream>

using namespace std;

/**
 * @class Paquet
**/
class Paquet
{
    /**
     * @brief Les données membres privées de la classe Paquet
     * @param tabCartes Pointeur de vecteur de Carte qui contient plusieurs cartes du jeu
     * @param nbPaquets Entier positif qui contient le nombre de paquets du jeu
    **/
private:
    vector<Carte*> tabCartes;
    unsigned int nbPaquets;
    
public:
    
    /*
    ----- Constructeur/Destructeur -----
    */
    
    /**
     * @brief Constructeur de Paquet
    **/
    Paquet();
    
    /**
     * @brief Destructeur de Paquet qui remet le nombre de paquet à 0 et nettoie les cartes du/des paquets
    **/
    ~Paquet();
    
    
    /*
    ----- Autres fonctions membres -----
    */
    
    /**
     * @fn initialisationPaquet(unsigned int nouveauPaquet) -> void
     * @brief Initialise le(s) paquet(s) avec 52 cartes dans chacun(s) et les mélange
     * @param nouveauPaquet Entier positif qui contient le nombre de paquet saisi par le joueur
    **/
    void initialisationPaquet(unsigned int nouveauPaquet);
    
    /**
     * @fn reinitialisationPaquets() -> void
     * @brief Nettoie le tableau de cartes, lui ajoute 52 cartes pour ensuite les mélanger
    **/
    void reinitialisationPaquets();
    
    /**
     * @fn melangerCartes() -> void
     * @brief Mélange les cartes d'un paquet de cartes
    **/
    void melangerCartes();
    
    /**
     * @fn prendPremiereCarte() -> void
     * @brief Prend la première carte du/des paquet(s)
     * @return Retourne un pointeur de Carte
    **/
    Carte* prendPremiereCarte();
    
    
    /*
    ----- Test de régression -----
    */

    /**
     * @fn testRegressionPaquet() -> void
     * @brief Réalise les tests de régression de la classe Paquet
    **/
    void testRegressionPaquet();

    void demopaquet();
};

#endif
