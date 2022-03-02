/**
 * @file Croupier.h
 * @brief Le croupier du blackjack
 * @author TAIBI Youssef, BEN JEMIA Boran, ROULLIER Léa
 * @version 0.2 (démonstration finale)
 * @date 10 mai 2021
**/

#ifndef croupier_h
#define croupier_h
#include <iostream>
#include "Carte.h"
#include <vector>
using namespace std;

/**
 * @class Croupier
**/
class Croupier
{
    /**
     * @brief Les données membres privées de la classe Croupier
     * @param nom Nom du croupier donné aléatoirement
     * @param tabCartesC Pointeur de vecteur de Carte qui contient les cartes de jeu du croupier
     * @param nbrCartes Entier positif qui contient le nombre de cartes de jeu du croupier
     * @param depassementCartes Booléen qui renvoie vraie si les cartes de jeu du croupier ont dépassé 21
     * @param estResteCartes Booléen qui renvoie vraie si le croupier a fait l'action de rester (somme de ses cartes > 17)
    **/
private:
    string nom;
    vector<Carte*> tabCartesC;
    unsigned int nbrCartes;
    bool depassementCartes;
    bool estResteCartes;

public:

    /*
    ----- Constructeur/Destructeur -----
    */

    /**
     * @brief Constructeur de Croupier qui initialise ses données membres et attribue un nom aléatoire au croupier
    **/
    Croupier();

    /**
     * @brief Destructeur de Croupier qui remet le nombre de cartes à 0 et les booléens à faux pour ensuite nettoyer le tableau de cartes
    **/
    ~Croupier();


    /*
    ----- Les accesseurs -----
    */

    /**
     * @fn getNom() const
     * @brief Récupère le nom du croupier
     * @return Retourne une chaîne de caractères
    **/
    string getNom() const;

    /**
     * @fn getElementTab(unsigned int i) const
     * @brief Récupère une des cartes d'un ou plusieurs paquets à un indice i
     * @param i Entier positif qui est l'indice 
     * @return Retourne un pointeur de Carte
    **/
    Carte* getElementTab(unsigned int i) const;

    /**
     * @fn getNbrCartes() const
     * @brief Récupère le nombre de cartes du croupier
     * @return Retourne un entier positif
    **/
    unsigned int getNbrCartes() const;

    /**
     * @fn getDepassementCartes() const
     * @brief Récupère la valeur du booléen depassementCartes qui décide si le croupier a perdu (somme des cartes > 21)
     * @return Retourne un booléen
    **/
    bool getDepassementCartes() const;

    /**
     * @fn getEstResteCartes() const
     * @brief Récupère la valeur du booléen estResteCartes qui décide si le croupier a choisit de rester (17 < somme des cartes < 21)
     * @return Retourne un booléen
    **/
    bool getEstResteCartes() const;


    /*
        ----- Les mutateurs -----
    */

    /**
     * @fn setDepassementCartes(bool nouveauDepassement) -> void
     * @brief Modifie la valeur du booléen depassementCartes qui décide si le croupier a perdu (somme des cartes > 21)
     * @param nouveauDepassement Booléen qui contient la nouvelle valeur de depassementCartes
    **/
    void setDepassementCartes(bool nouveauDepassement);

    /**
     * @fn setEstResteCartes(bool nouveauEstReste) -> void
     * @brief Modifie la valeur du booléen estResteCartes qui décide si le croupier a choisit de rester (17 < somme des cartes < 21)
     * @param nouveauEstReste Booléen qui contient la nouvelle valeur de estResteCartes
    **/
    void setEstResteCartes(bool nouveauEstReste);


    /*
        ----- Autres fonctions membres -----
    */

    /**
     * @fn sommeValeurCartes()
     * @brief Calcule la somme des cartes de jeu du croupier
     * @return Retourne un entier positif
    **/
    unsigned int sommeValeurCartes();

    /**
     * @fn calculDepassement()
     * @brief Calcule si la somme des cartes de jeu du croupier a dépassé 21
     * @return Retourne un booléen
    **/
    bool calculDepassement();

    /**
     * @fn ajouterCarte(Carte* c) -> void
     * @brief Ajoute une nouvelle carte aux cartes de jeu du croupier
     * @param c Pointeur de Carte qui va être ajouté au(x) paquet(s)
    **/
    void ajouterCarte(Carte* c);

    /**
     * @fn finManche() -> void
     * @brief Remet le nombre de cartes du croupier à 0, les booléens à faux et nettoie le tableau de cartes quand la manche est terminée
    **/
    void finManche();


    /*
    ----- Les possibilités d'actions du croupier -----
    */

    /**
     * @fn verificationPiocher()
     * @brief Vérifie que la somme des cartes du croupier n'excède pas 20
     * @return Retourne un booléen
    **/
    bool verificationPiocher(); 


    /*
    ----- Test de régression -----
    */

    /**
     * @fn testRegressionCroupier() -> void
     * @brief Réalise les tests de régression de la classe Croupier
    **/
    void testRegressionCroupier();
};

#endif
