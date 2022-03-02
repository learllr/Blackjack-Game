/**
 * @file Joueur.h
 * @brief Le joueur du blackjack
 * @author TAIBI Youssef, BEN JEMIA Boran, ROULLIER Léa
 * @version 0.2 (démonstration finale)
 * @date 10 mai 2021
**/

#ifndef joueur_h
#define joueur_h
#include "Carte.h"
#include <vector>
#include <iostream>
#include <cassert>
#include <string.h> // Pour le strcmp().
#include <stdlib.h> // Pour le atoi().

using namespace std;

/**
 * @class Joueur
**/
class Joueur
{
    /**
     * @brief Les données membres privées de la classe Joueur
     * @param nom Chaîne de caractères qui contient le nom du joueur saisi par le joueur lui-même
     * @param jetons Entier positif qui contient le nombre de jetons totals du joueur
     * @param jetonsMises Entier positif qui contient le nombre de jetons misés par rapport à ses cartes initiales sur la table de jeu 
     * @param jetonsMisesSplit Entier positif qui contient le nombre de jetons misés par rapport à ses cartes splittées sur la table de jeu 
     * @param jetonsAssurance Entier positif qui contient le nombre de jetons d'assurance misés sur une autre partie de la table de jeu 
     * @param nbrCartes Entier positif qui contient le nombre de cartes du jeu initiale du joueur
     * @param nbrCartesSplit Entier positif qui contient le nombre de cartes du jeu splitté du joueur
     * @param tabCartesJ Pointeur de vecteur de Carte qui contient les cartes initiales de jeu du joueur
     * @param tabCartesJSplit Pointeur de vecteur de Carte qui contient les cartes splittées de jeu du joueur
     * @param prisAssurance Booléen qui renvoie vrai si le joueur a pris l'assurance
     * @param depassementCartes Booléen qui renvoie vraie si les cartes du jeu initial du joueur ont dépassé 21
     * @param depassementCartesSplit Booléen qui renvoie vraie si les cartes du jeu splitté du joueur ont dépassé 21
     * @param estResteCartes Booléen qui renvoie vraie si le joueur a fait l'action de rester sur son paquet initial
     * @param estResteCartesSplit Booléen qui renvoie vraie si le joueur a fait l'action de rester sur son paquet splitté
     * @param resultat Entier positif qui contient le nombre correspondant au résultat du paquet initiale de fin de manche
     * @param resultatSplit Entier positif qui contient le nombre correspondant au résultat du paquet splitté de fin de manche
     * @param assurance Entier positif qui contient le nombre correspondant au résultat d'assurance de fin de manche
    **/
private:
    string nom;
    unsigned int jetons, jetonsMises, jetonsMisesSplit, jetonsAssurance, nbrCartes, nbrCartesSplit;
    vector<Carte*> tabCartesJ;
    vector<Carte*> tabCartesJsplit;
    bool prisAssurance;
    bool depassementCartes;
    bool depassementCartesSplit;
    bool estResteCartes;
    bool estResteCartesSplit;
    unsigned int resultat;
    unsigned int resultatSplit;
    unsigned int assurance;

public:

    /*
    ----- Constructeur/Destructeur -----
    */
    
    /**
     * @brief Constructeur de Croupier qui initialise ses données membres à 0 et nettoie les tableaux de cartes
    **/
    Joueur();

    /**
     * @brief Destructeur de Croupier qui remet des données membres à 0 et les booléens à faux pour ensuite nettoyer les tableaux de cartes
    **/
    ~Joueur();


    /*
    ----- Les accesseurs -----
    */
    
    /**
     * @fn getNom() const
     * @brief Récupère le nom du joueur
     * @return Retourne une chaîne de caractères
    **/
    string getNom() const;

    /**
     * @fn getJetons() const
     * @brief Récupère le nombre de jetons du joueur
     * @return Retourne un entier positif
    **/
    unsigned int getJetons() const;

    /**
     * @fn getJetonsMises() const
     * @brief Récupère le nombre de jetons qui ont été misés (cartes initiales)
     * @return Retourne un entier positif
    **/
    unsigned int getJetonsMises() const;

    /**
     * @fn getJetonsMisesSplit() const
     * @brief Récupère le nombre de jetons qui ont été misés (cartes splittées)
     * @return Retourne un entier positif
    **/
    unsigned int getJetonsMisesSplit() const;

    /**
     * @fn getJetonsAssurance() const
     * @brief Récupère le nombre de jetons misés pour prendre l'assurance
     * @return Retourne un entier positif
    **/
    unsigned int getJetonsAssurance() const;

    /**
     * @fn getNbrCartes() const
     * @brief Récupère le nombre de cartes du jeu initiale du joueur
     * @return Retourne un entier positif
    **/
    unsigned int getNbrCartes() const;

    /**
     * @fn getNbrCartesSplit() const
     * @brief Récupère le nombre de cartes du jeu splitté du joueur
     * @return Retourne un entier positif
    **/
    unsigned int getNbrCartesSplit() const;

    /**
     * @fn getElementTab(unsigned int i) const
     * @brief Récupère une des cartes du tableau initiale à l'indice i
     * @param i Entier positif qui est l'indice
     * @return Retourne un pointeur de Carte
    **/
    Carte* getElementTab(unsigned int i) const;

    /**
     * @fn getElementTabSplit(unsigned int i) const
     * @brief Récupère une des cartes du tableau splitté à l'indice i
     * @param i Entier positif qui est l'indice
     * @return Retourne un pointeur de Carte
    **/
    Carte* getElementTabSplit(unsigned int i) const;

    /**
     * @fn getBoolAssurance() const
     * @brief Récupère le booléen prisAssurance qui nous dis si le joueur a pris l'assurance
     * @return Retourne un booléen
    **/
    bool getBoolAssurance() const;

    /**
     * @fn getDepassementCartes() const
     * @brief Récupère le booléen depassementCartes qui décide si le joueur a perdu (somme des cartes initiales > 21)
     * @return Retourne un booléen
    **/
    bool getDepassementCartes() const;

    /**
     * @fn getDepassementCartesSplit() const
     * @brief Récupère le booléen depassementCartesSplit qui décide si le joueur a perdu (somme des cartes splittées > 21)
     * @return Retourne un booléen
    **/
    bool getDepassementCartesSplit() const;

    /**
     * @fn getEstResteCartes() const
     * @brief Récupère le booléen estResteCartes du joueur qui choisit de rester sur son paquet de cartes initiales
     * @return Retourne un booléen
    **/
    bool getEstResteCartes() const;

    /**
     * @fn getEstResteCartesSplit() const
     * @brief Récupère le booléen estResteCartesSplit du joueur qui choisit de rester sur son paquet de cartes splittées
     * @return Retourne un booléen
    **/
    bool getEstResteCartesSplit() const;

    /**
     * @fn getResultat() const
     * @brief Récupère le nombre correspondant au résultat du paquet initial de fin de manche
     * @return Retourne un entier positif
    **/
    unsigned int getResultat() const;

    /**
     * @fn getResultatSplit() const
     * @brief Récupère le nombre correspondant au résultat du paquet splitté de fin de manche
     * @return Retourne un entier positif
    **/
    unsigned int getResultatSplit() const;

    /**
     * @fn getAssurance() const
     * @brief Récupère le nombre correspondant au résultat d'assurance de fin de manche
     * @return Retourne un entier positif
    **/
    unsigned int getAssurance() const;
    
    /*
    ----- Les mutateurs -----
    */
    
    /**
     * @fn setNom(string nouveauNom) -> void
     * @brief Modifie le nom du joueur
     * @param nouveauNom Chaîne de caractères qui contient le nouveau nom du joueur
    **/
    void setNom(string nouveauNom);

    /**
     * @fn setJetons(unsigned int nouveauxJetons) -> void
     * @brief Modifie le nombre de jetons totals du joueur
     * @param nouveauxJetons Entier positif qui contient le nouveau nombre de jetons totals du joueur
    **/
    void setJetons(unsigned int nouveauxJetons);

    /**
     * @fn setJetonsMises(unsigned int nouveauxJetons) -> void
     * @brief Modifie le nombre de jetons qui ont été misés (cartes initiales)
     * @param nouveauxJetons Entier positif qui contient le nouveau nombre de jetons misés du joueur (cartes initiales)
    **/
    void setJetonsMises(unsigned int nouveauxJetons);

    /**
     * @fn setJetonsMisesSplit(unsigned int nouveauxJetonsSplit) -> void
     * @brief Modifie le nombre de jetons qui ont été misés (cartes splittées)
     * @param nouveauxJetonsSplit Entier positif qui contient le nouveau nombre de jetons misés du joueur (cartes splittées)
    **/
    void setJetonsMisesSplit(unsigned int nouveauxJetonsSplit);

    /**
     * @fn setJetonsAssurance(unsigned int nouveauxJetonsAssurance) -> void
     * @brief Modifie le nombre de jetons qui ont été misés pour prendre l'assurance 
     * @param nouveauxJetonsAssurance Entier positif qui contient le nouveau nombre de jetons misés pour prendre l'assurance
    **/
    void setJetonsAssurance(unsigned int nouveauxJetonsAssurance);

    /**
     * @fn setDepassementCartes(bool nouveauDepassement) -> void
     * @brief Modifie le booléen depassementCartes qui décide si le joueur a perdu (somme des cartes initiales > 21)
     * @param nouveauDepassement Booléen qui contient la nouvelle valeur de depassementCartes
    **/
    void setDepassementCartes(bool nouveauDepassement);

    /**
     * @fn setDepassementCartesSplit(bool nouveauDepassementSplit) -> void
     * @brief Modifie le booléen depassementCartesSplit qui décide si le joueur a perdu (somme des cartes splittées > 21)
     * @param nouveauDepassementSplit Booléen qui contient la nouvelle valeur de depassementCartesSplit
    **/
    void setDepassementCartesSplit(bool nouveauDepassementSplit);

    /**
     * @fn setBoolAssurance(bool nouveauChoixAssurance) -> void
     * @brief Modifie le booléen prisAssurance qui nous dis si le joueur a pris l'assurance
     * @param nouveauChoixAssurance Booléen qui contient la nouvelle valeur de prisAssurance
    **/
    void setBoolAssurance(bool nouveauChoixAssurance);
    
    /**
     * @fn setEstResteCartes(bool nouveauEstReste) -> void
     * @brief Modifie le booléen estResteCartes du joueur qui choisit de rester sur son paquet de cartes initiales
     * @param nouveauEstReste Booléen qui contient la nouvelle valeur de estResteCartes
    **/
    void setEstResteCartes(bool nouveauEstReste);

    /**
     * @fn setEstResteCartesSplit(bool nouveauEstResteSplit) -> void
     * @brief Modifie le booléen estResteCartesSplit du joueur qui choisit de rester sur son paquet de cartes splittées
     * @param nouveauEstResteSplit Booléen qui contient la nouvelle valeur de estResteCartesSplit
    **/
    void setEstResteCartesSplit(bool nouveauEstResteSplit);

    /**
     * @fn setResultat(bool nouveauResultat) -> void
     * @brief Modifie le booléen resultat du joueur qui correspond au nombre du résultat du paquet initial de fin de manche
     * @param nouveauResultat Booléen qui contient la nouvelle valeur de resultat
    **/
    void setResultat(bool nouveauResultat);

    /**
     * @fn setResultatSplit(bool nouveauResultatSplit) -> void
     * @brief Modifie le booléen resultatSplit du joueur qui correspond au nombre du résultat du paquet splitté de fin de manche
     * @param nouveauResultatSplit Booléen qui contient la nouvelle valeur de resultatSplit
    **/
    void setResultatSplit(bool nouveauResultatSplit);

    /**
     * @fn setAssurance(bool nouvelleAssurance) -> void
     * @brief Modifie le booléen assurance du joueur qui correspond au nombre du résultat d'assurance de fin de manche
     * @param nouvelleAssurance Booléen qui contient la nouvelle valeur de assurance
    **/
    void setAssurance(bool nouvelleAssurance);

    /*
    ----- Autres fonctions membres -----
    */

    /**
     * @fn initialisationJoueur(string nomJoueur, unsigned int nbrJetons) -> void
     * @brief Initialise le joueur en lui attribuant un nom et un nombre de jetons
     * @param nomJoueur Chaîne de caractères qui contient le nom du joueur
     * @param nbrJetons Entier positif qui contient le nombre de jetons du joueur
    **/
    void initialisationJoueur(string nomJoueur, unsigned int nbrJetons);
    
    /**
     * @fn sommeValeurCartes()
     * @brief Calcule la somme des valeurs des cartes initiales du joueur
     * @return Retourne un entier positif
    **/
    unsigned int sommeValeurCartes();

    /**
     * @fn sommeValeurCartesSplit()
     * @brief Calcule la somme des valeurs des cartes splittées du joueur
     * @return Retourne un entier positif
    **/
    unsigned int sommeValeurCartesSplit();

    /**
     * @fn calculDepassement()
     * @brief Calcule si le joueur a dépassé la somme de 21 pour le paquet initial
     * @return Retourne un booléen
    **/
    bool calculDepassement();

    /**
     * @fn calculDepassementSplit()
     * @brief Calcule si le joueur a dépassé la somme de 21 pour le paquet splitté
     * @return Retourne un booléen
    **/
    bool calculDepassementSplit();

    /**
     * @fn ajouterCarte(Carte *c) -> void
     * @brief Ajoute une carte au jeu initiale du joueur
     * @param c Pointeur de Carte
    **/
    void ajouterCarte(Carte *c);

    /**
     * @fn ajouterCarteSplit(Carte *c) -> void
     * @brief Ajoute une carte au jeu splitté du joueur
     * @param c Pointeur de Carte
    **/
    void ajouterCarteSplit(Carte *c);

    /**
     * @fn finManche() -> void
     * @brief Remet à 0 ou faux des données membres et nettoie les tableaux quand la manche est terminée
    **/
    void finManche();

    /**
     * @fn gainManche(unsigned int sommeCartesC, unsigned int nbrCartesC) -> void
     * @brief Calcule les gains d'une manche
     * @param sommeCartesC Entier positif qui contient la somme des cartes de jeu du croupier
     * @param nbrCartesC Entier positif qui contient le nombre de cartes de jeu du croupier
    **/
    void gainManche(unsigned int sommeCartesC, unsigned int nbrCartesC);
    

    /*
    ----- Les possibilités d'actions du joueur -----
    */
    
    /**
     * @fn doubler() -> void
     * @brief Action du joueur de doubler la mise (cartes initiales)
    **/
    void doubler();

    /**
     * @fn doublerSplit() -> void
     * @brief Action du joueur de doubler la mise (cartes splittées)
    **/
    void doublerSplit();

    /**
     * @fn splitter() -> void
     * @brief Action du joueur de splitter deux cartes du joueur qui ont la même valeur
    **/
    void splitter();

    /**
     * @fn prendreAssurance() -> void
     * @brief Action du joueur de prendre l'assurance quand le croupier a en première carte : V ou D ou R ou As
    **/
    void prendreAssurance();

    /**
     * @fn verificationDoubler()
     * @brief Vérifie que l'on a assez de jetons pour doubler la mise (cartes initiales)
     * @return Retourne un booléen
    **/
    bool verificationDoubler(); 

    /**
     * @fn verificationDoublerSplit() 
     * @brief Vérifie que l'on a assez de jetons pour doubler la mise (cartes splittées)
     * @return Retourne un booléen
    **/
    bool verificationDoublerSplit();
    
    /**
     * @fn verificationPiocher() 
     * @brief Vérifie que la somme des cartes initiales du joueur n'excède pas 20
     * @return Retourne un booléen
    **/
    bool verificationPiocher(); 

    /**
     * @fn verificationPiocher() 
     * @brief Vérifie que la somme des cartes splittées du joueur n'excède pas 20
     * @return Retourne un booléen
    **/
    bool verificationPiocherSplit();

    /**
     * @fn verificationSplitter()
     * @brief Vérifie que le joueur a deux cartes, que les deux dernières cartes tirées ont la même valeur (D et D, V et V, 3 et 3) et que'il a en jetons disponibles le double de la mise
     * @return Retourne un booléen
    **/
    bool verificationSplitter(); 

    /**
     * @fn verificationAssurance(Carte* carteC)
     * @brief Vérifie que le joueur n'a pas déjà pris une assurance, que le croupier a soit un 10, valet, dame, roi ou as en première carte et que le joueur a en jetons disponibles la moitié de la mise
     * @param carteC Pointeur de carte pour récupérer la valeur d'une carte du croupier
     * @return Retourne un booléen
    **/
    bool verificationAssurance(Carte* carteC); 


    /*
    ----- Test de régression -----
    */

    /**
     * @fn testRegressionJoueur() -> void
     * @brief Réalise les tests de régression de la classe Joueur
    **/
    void testRegressionJoueur();
};

#endif
