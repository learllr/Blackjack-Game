/**
 * @file Carte.h
 * @brief La carte d'un paquet de cartes
 * @author TAIBI Youssef, BEN JEMIA Boran, ROULLIER Léa
 * @version 0.2 (démonstration finale)
 * @date 10 mai 2021
**/

#ifndef carte_h
#define carte_h

#include <string>
#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

/**
 * @class Carte
**/
class Carte
{   
    /**
     * @brief Les données membres privées de la classe Carte
     * @param couleur Chaîne de caractère qui contient la couleur (carreau, trèfle, coeur et pique) de la carte
     * @param valeur Chaîne de caractère qui contient la valeur (1 à 10 et V, D, R, As) de la carte
    **/
private:
    string couleur;
    string valeur;

public:
    
    /*
    ----- Constructeur/Destructeur -----
    */
    
    /**
     * @brief Constructeur de Carte
    **/
    Carte();

    /**
     * @brief Constructeur avec deux paramètres de Carte qui lui attribue une couleur et une valeur
     * @param nouvelleCouleur Chaîne de caractères qui contient la couleur attribuée à la carte
     * @param nouvelleValeur Chaîne de caractères qui contient la valeur attribuée à la carte
    **/
    Carte(string nouvelleCouleur, string nouvelleValeur);
    
    /**
     * @brief Destructeur de Carte
    **/
    ~Carte();
    

    /*
    ----- Les accesseurs -----
    */

    /**
     * @fn getCouleur() const
     * @brief Récupère la couleur de la carte
     * @return Retourne une chaîne de caractères
    **/
    string getCouleur() const;
    
    /**
     * @fn getValeur() const
     * @brief Récupère la valeur de la carte
     * @return Retourne une chaîne de caractères
    **/
    string getValeur() const;
    
    
    /*
    ----- Les mutateurs -----
    */
    
    /**
     * @fn setCouleur(string nouvelleCouleur) -> void
     * @brief Modifie la couleur de la carte
     * @param nouvelleCouleur Chaîne de caractères qui contient la nouvelle couleur de la carte
    **/
    void setCouleur(string nouvelleCouleur);
    
    /**
     * @fn setValeur(string nouvelleValeur) -> void
     * @brief Modifie la valeur de la carte
     * @param nouvelleValeur Chaîne de caractères qui contient la nouvelle valeur de la carte
    **/
    void setValeur(string nouvelleValeur);


    /*
    ----- Test de régression -----
    */

    /**
     * @fn testRegressionCarte() -> void
     * @brief Réalise les tests de régression de la classe Carte
    **/
    void testRegressionCarte();
};

#endif
