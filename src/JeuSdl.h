/**
 * @file JeuSdl.h
 * @brief Le jeu blackjack en version graphique
 * @author TAIBI Youssef, BEN JEMIA Boran, ROULLIER Léa
 * @version 0.2 (démonstration finale)
 * @date 10 mai 2021
**/

#ifndef jeuSdl_h
#define jeuSdl_h

#include "Paquet.h"
#include "Croupier.h"
#include "Joueur.h"
#include <iostream>
#include <SDL.h>
#include <cassert>
#include <fstream>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <chrono>

using namespace std;

/**
 * @class JeuSdl
**/
class JeuSdl
{
private:
    /** @param Nomarendre Chaîne de caractères qui contient le nom que l'utilisateur écris dans le deuxième menu (nom, niveau, nombre jetons, nombre paquets) */
     /** @param window Fenêtre de jeu */
      /** @param renderer Moteur de rendu du jeu pour la fenêtre (espace où l'on peut dessiner, écrire...) */
      /** @param estSaisieNom Booléen qui informe si l'utilisateur a saisie un nom de joueur */
      /** @param Nom Texture du nom du joueur (permet de tracer un dessin ou de charger une image, on peut l'utiliser à notre guise indépendamment du renderer) */
      /** @param LocaliNom Rectangle de sélection du nom du joueur */
      /** @param estSaisieNiveau Booléen qui informe si l'utilisateur a saisie un niveau de jeu */
      /** @param Niveauxloca Texture du niveau de jeu du joueur (permet de tracer un dessin ou de charger une image, on peut l'utiliser à notre guise indépendamment du renderer)*/
      /** @param Niveaux Rectangle de sélection du niveau de jeu*/
      /** @param niv Chaîne de caractères qui contient le niveau choisi par l'utilisateur*/
      /** @param estSaisiePaquet Booléen qui informe si l'utilisateur a saisie un nombre de paquets dans le jeu*/
      /** @param NbPaq Texture du nombre de paquets dans le jeu (permet de tracer un dessin ou de charger une image, on peut l'utiliser à notre guise indépendamment du renderer)*/
      /** @param Paqloca Rectangle de sélection du nombre de paquets dans le jeu*/
      /** @param nbrePaquet Entier positif qui contient le nombre de paquets choisi par l'utilisateur*/
      /** @param estSaisieJet Booléen qui informe si l'utilisateur a saisie un nombre de jetons pour le joueur*/
      /** @param Jet Texture du nombre de jetons pour le joueur (permet de tracer un dessin ou de charger une image, on peut l'utiliser à notre guise indépendamment du renderer)*/
      /** @param JetLoca Rectangle de sélection du nombre de paquets dans le jeu*/
      /** @param Jetons Entier positif qui contient le nombre de jetons saisie par l'utilisateur*/
      /** @param estMise Booléen qui informe si l'utilisateur a saisie une mise de départ du joueur*/
      /** @param SurMise Structure qui contient une collection de pixels*/
      /** @param TextMise Texture de la mise de départ du joueur (permet de tracer un dessin ou de charger une image, on peut l'utiliser à notre guise indépendamment du renderer)*/
      /** @param MiseLoca Rectangle de sélection de la mise de départ du joueur*/
      /** @param MiseEnCours Entier positif qui contient la mise de départ du joueur*/
      /** @param estSaisieJetonsActuels Booléen qui informe du nombre de jetons actuel du joueur*/
      /** @param CurrentJetons Texture du nombre de jetons actuel du joueur (permet de tracer un dessin ou de charger une image, on peut l'utiliser à notre guise indépendamment du renderer)*/
      /** @param LocaCurJet Rectangle de sélection du nombre de jetons actuel du joueur*/
      /** @param JetonsActuels Entier positif qui contient le nombre de jetons actuel du joueur*/
      /** @param estSaisieCouper Booléen qui informe si l'utilisateur a choisi si la musique est coupée ou non*/
      /** @param Couper Texture pour l'état de la musique (coupée ou non)*/
      /** @param LocaCut Rectangle pour l'emplacement d'affichage du statut de la musique*/
      /** @param mute Booléen indiquant l'état de la musique (mute = coupée)*/
      /** @param estSaisieVolume Booléen qui informe si l'utilisateur a choisi le volume de la musique*/
      /** @param Volume Texture pour le volume du son*/
      /** @param LocaVol Rectangle pour l'emplacement d'affichage du volume de la musique*/
      /** @param nivVolume Chaîne de caractères qui contient moyen/faible/fort*/
      /** @param estSaisieDesignCartes Booléen qui informe si l'utilisateur a choisi le design des cartes*/
      /** @param DesignCartes Texture pour le design des cartes*/
      /** @param LocaDesCartes Rectangle pour l'emplacement d'affichage du design des cartes*/
      /** @param styleCartes Chaîne de caractères qui contient fééerique/normal/western*/
      /** @param estSaisieDesignTable Booléen qui informe si l'utilisateur a choisi le design de la table*/
      /** @param DesignTable Texture pour le design de la table*/
      /** @param LocaDesTable Rectangle pour l'emplacement d'affichage du design de la table*/
      /** @param styleTable Chaîne de caractères qui contient fééerique/normal/western*/
      /** @param estSaisieDesignJetons Booléen qui informe si l'utilisateur a choisi le design des jetons (couleur)*/
      /** @param DesignJetons Texture pour le design des jetons*/
      /** @param LocaDesJetons Rectangle pour l'emplacement d'affichage du design des jetons*/
      /** @param styleJetons Chaîne de caractères qui contient bleu/vert/violet*/
      /** @param Table Texture pour le design de la table*/
      /** @param TableSur Texture pour le design de la table mise dessus (féerique, western)*/
      /** @param tabledessine Booléen qui informe si la table est bien dessiné*/
      /** @param jetonsdessine Booléen qui informe si les jetons sont bien dessinés*/
      /** @param Deck Paquet de carte du jeu*/
      /** @param Croup Croupier (intelligence artificielle) du jeu*/
      /** @param Player Joueur (utilisateur) du jeu*/
      /** @param hauteur Entier positif qui représente la hauteur de la taille d'un écran*/
      /** @param largeur Entier positif qui représente la largeur de la taille d'un écran*/
      /** @param test2 Booléen qui permet de distinguer le bouton de mise du bouton valider*/
      /** @param premierlancement Booléen qui permet de savoir si le premier lancement du jeu a eu lieu*/
      /** @param actionfaite Booléen qui permet d'éviter les dédoublements d'actions du jeu*/
      /** @param tour Entier positif qui permet de gérer le tour de chaque jour*/
      /** @param AfficheJetons Texture d'affichage des jetons*/
      /** @param LocaAfficheJetons Rectangle pour l'emplacement de l'affichage des jetons*/
      /** @param ActionImpossible Texture d'affichage de l'action impossible*/
      /** @param locaImpossible Rectangle pour l'emplacement de l'affichage de l'action impossible*/
      /** @param impossible Booléen qui permet de savoir si l'action cliqué est impossible*/
      /** @param ScoreJoueur Texture qui permet d'afficher le score d'un joueur sur son paquet initial*/
      /** @param locaScoreJoueur Rectangle pour l'emplacement de l'affichage du score d'un joueur sur son paquet initial*/
      /** @param ScoreJoueurSplit Texture qui permet d'afficher le score d'un joueur sur son paquet splitté*/
      /** @param locaScoreJoueurSplit Rectangle pour l'emplacement de l'affichage du score d'un joueur sur son paquet splitté*/
      /** @param ScoreCroupier Texture qui permet d'afficher le score du croupier*/
      /** @param locaScoreCroupier Rectangle pour l'emplacement de l'affichage du score du croupier*/
      /** @param ScoreDesDeux Texture qui permet d'afficher le score des deux (croupier et joueur)*/
      /** @param locaScoreDeux Rectangle pour l'emplacement de l'affichage du score des deux (croupier et joueur)*/
      /** @param PaquetCartes Texture qui permet d'afficher le paquet de cartes*/
      /** @param locaScoreDeux Rectangle pour l'emplacement de l'affichage du paquet de cartes*/
      /** @param success Entier qui permet de stocker une valeur pour savoir si elle a bien été mise dans la file d'attente*/
      /** @param ecoutecommence Booléen qui permet de savoir si la musique commence*/
      /** @param assuranceachoisir Booléen qui permet de savoir si on affiche la fenêtre d'assurance*/
      /** @param decisionprise Booléen qui permet de savoir si l'on affiche des choses tant que l'assurance n'est pas choisie*/
      /** @param temps Booléen qui permet de savoir si on est rentré dans la boucle d'événements*/
      /** @param menu Texture qui permet d'afficher le menu du jeu*/
      /** @param menulance Booléen qui permet de savoir si on a cliqué sur le bouton pour lancer le menu*/
      /** @param reglelance Booléen qui permet de savoir si on a cliqué sur le bouton pour lancer les règles*/
      /** @param compteur Double qui permet de stocker la valeur du compteur (événement automatique)*/

    string Nomarendre;

    SDL_Window *window;

    SDL_Renderer *renderer;

    bool estSaisieNom = false;
    SDL_Texture *Nom;
    SDL_Rect LocaliNom;

    bool estSaisieNiveau = false;
    SDL_Rect Niveauxloca;
    SDL_Texture *Niveaux;
    string niv;

    bool estSaisiePaquet = false;
    SDL_Texture *NbPaq;
    SDL_Rect Paqloca;
    unsigned int nbrePaquet;

    bool estSaisieJet = false;
    SDL_Texture *Jet;
    SDL_Rect JetLoca;
    unsigned int Jetons;

    bool estMise = false;
    SDL_Surface *SurMise;
    SDL_Texture *TextMise;
    SDL_Rect MiseLoca;
    unsigned int MiseEnCours;

    bool estSaisieJetonsActuels = false;
    SDL_Texture *CurrentJetons;
    SDL_Rect LocaCurJet;
    unsigned int JetonsActuels;

    bool estSaisieCouper = false;
    SDL_Texture *Couper;
    SDL_Rect LocaCut;
    bool mute = false;

    bool estSaisieVolume = false;
    SDL_Texture *Volume;
    SDL_Rect LocaVol;
    string nivVolume;

    bool estSaisieDesignCartes = false;
    SDL_Texture *DesignCartes;
    SDL_Rect LocaDesCartes;
    string styleCartes;

    bool estSaisieDesignTable = false;
    SDL_Texture *DesignTable;
    SDL_Rect LocaDesTable;
    string styleTable;

    bool estSaisieDesignJetons = false;
    SDL_Texture *DesignJetons;
    SDL_Rect LocaDesJetons;
    string styleJetons;

    SDL_Texture *Table;
    SDL_Texture *TableSur;
    bool tabledessine = true;
    bool jetonsdessine = true;

    Paquet Deck;

    Croupier Croup;

    Joueur Player;

    int hauteur, largeur;

    bool test2 = false;

    bool premierlancement = false;

    bool actionfaite = false;

    bool tire = false;

    unsigned int tour = 2;

    SDL_Texture *AfficheJetons;
    SDL_Rect LocaAfficheJetons;

    SDL_Texture *ActionImpossible;
    SDL_Rect locaImpossible;
    bool impossible = false;

    SDL_Texture *ScoreJoueur;
    SDL_Rect locaScoreJoueur;
    SDL_Texture *ScoreJoueurSplit;
    SDL_Rect locaScoreJoueurSplit;
    SDL_Texture *ScoreCroupier;
    SDL_Rect locaScoreCroupier;
    SDL_Texture *ScoreDesDeux;
    SDL_Rect locaScoreDeux;

    SDL_Texture *PaquetCartes;
    SDL_Rect LocaPaquet;

    int success;

    bool ecoutecommence = false;

    bool assuranceachoisir = false;

    bool decisionprise = false;

    bool temps = false;

    SDL_Texture *menu;
    bool menulance = false;
    bool reglelance = false;

    double compteur = 1.0;

public:
    /**
     * @fn afficher() -> void
     * @brief Affichage graphique du jeu.
     * @param dem String permettant de savoir dans quel mode on est : démo ou comportement normal
    */
    void afficher(string dem);

    /**
     * @fn draw(string dir, string &dirchange, SDL_Rect *selection, SDL_Rect *selection2, int &ch, int &item) -> void
     * @brief Dessin graphique du jeu.
     * @param dir Chaîne de caractères qui correspond à la direction dans lequel les flèches sont affichées.
     * @param dirchange Chaîne de caractères qui correspond au changement de direction dans lequel les flèches sont affichées.
     * @param selection Premier rectangle de sélection du jeu
     * @param selection2 Deuxième rectangle de sélection du jeu (pour mieux le voir)
     * @param ch Entier positif qui contient le numéro d'un écran du jeu
     * @param item Entier positif qui contient le numéro d'une catégorie sur l'écran
    */
    void draw(string dir, string &dirchange, SDL_Rect *selection, SDL_Rect *selection2, unsigned int &ch, unsigned int &item);

    /**
     * @fn choix(SDL_Rect *selection, SDL_Rect *selection2, int ch) -> void
     * @brief Applique le rectangle de sélection sur les différents choix du joueur
     * @param selection Premier rectangle de sélection du jeu
     * @param selection2 Deuxième rectangle de sélection du jeu (pour mieux le voir)
     * @param ch Entier positif qui contient le numéro d'un écran du jeu
     * @param item Entier positif qui contient le numéro d'une catégorie sur l'écran
    */
    unsigned int choix(SDL_Rect *selection, SDL_Rect *selection2, unsigned int ch, unsigned int &item);

    /**
     * @fn choixJoueur(SDL_Rect *selection, SDL_Rect *selection2) -> void
     * @brief Réalise des actions suivant le choix du joueur
     * @param selection Premier rectangle de sélection du jeu
     * @param selection2 Deuxième rectangle de sélection du jeu (pour mieux le voir)
     * @param item Entier positif qui contient le numéro d'une catégorie sur l'écran
     * @param ch Entier positif qui contient le numéro d'un écran du jeu
    */
    void choixJoueur(SDL_Rect *selection, SDL_Rect *selection2, unsigned int &item, unsigned int &ch);

    /**
     * @fn initrect(SDL_Rect *selection, SDL_Rect *selection2, int ch) -> void
     * @brief Initialisation des rectangles de sélection suivant les écrans du jeu
     * @param selection Premier rectangle de sélection du jeu
     * @param selection2 Deuxième rectangle de sélection du jeu (pour mieux le voir)
     * @param ch Entier positif qui contient le numéro d'un écran du jeu
     * @param item Entier positif qui désigne la case à changer, remis à 0 pour éviter les superpositions
    */
    void initrect(SDL_Rect *selection, SDL_Rect *selection2, unsigned int ch, unsigned int &item);

    /**
     * @fn changeim(string dir, int item, SDL_Rect *locali, int ch, bool &test) -> int
     * @brief Changement des images pour chaque catégorie du menu
     * @param dir Direction dans lequel les flèches sont affichées.
     * @param item item Entier positif qui contient le numéro d'une catégorie sur l'écran 
     * @param locali Rectangle de sélection pour chaque catégorie
     * @param ch Entier positif qui contient le numéro d'un écran du jeu
     * @return Retourne un entier
    */
    unsigned int changeim(string dir, unsigned int item, SDL_Rect *locali, unsigned int ch);

    /**
     * @fn InitJeuSdl() -> void
     * @brief Initialise le jeu graphique avec un joueur, un croupier et un paquet
     * @param comp String permettant de savoir dans quel mode on est : démo ou jeu normal
    */
    void InitJeuSdl(string comp);

    /**
     * @fn rendercarte() -> void
     * @brief Affichage des cartes du jeu
    */
    void rendercarte();

    /**
     * @fn actionCroupier() -> void
     * @brief Réalise les actions du croupier
    */
    void actionCroupier();

    /**
     * @fn saisie() -> string
     * @brief Prend en compte la saisie au clavier de l'utilisateur
     * @return Retourne une chaîne de caractères
    */
    string saisie();

    /**
     * @brief Choisie les images apropriées à afficher en fonction des résultats de la partie.
     */
    void gainMancheSDL();

    /**
     * @brief Initialise la texture qui permettra d'afficher les jetons actuels dans l'écran de mise.
     */
    void currentmise();

    /**
     * @brief Initialise la texture de la table et la couleur du jeton en fonction des paramètres
     */
    void inittexturetable();

    /**
     * @brief Initialise la texture et l'emplacement d'affichage pour afficher les jetons restants à l'utilisateur.
     */
    void affichagejetons();

    /**
     * @brief Initialise les différentes textures des scores actuels du joueur et du croupier, ainsi que l'emplacement d'affichage
     */
    void affichagescore();

    /**
     * @brief Ajoute dans le renderer les textures pour les scores du joueur et du croupier
     */
    void renderscore();

    /**
     * @brief Initialise et ajoute dans le renderer les textures et l'emplacement d'affichage pour le paquet de cartes en fonction des paramètres.
     */
    void renderpaquet();

    /**
     * @brief Initialise et ajoute dans le renderer les textures et l'emplacement d'affichage pour le menu de choix d'assurance
     * @param selection Premier rectangle de sélection du jeu
     * @param selection2 Deuxième rectangle de sélection du jeu (pour mieux le voir)
     */
    void renderassurance(SDL_Rect *selection, SDL_Rect *selection2);
};

#endif