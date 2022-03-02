# BlackJack

Notre projet est un BlackJack en 1 contre 1 contre un croupier. Il a été réalisé dans le cadre de l'unité d'enseignement LIFAP4 de 2020-2021.

## Installation 

Pour installer et faire fonctionner pleinement le BlackJack. Il faut installer la bibliothèque SDL2. 
```bash
sudo apt install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev imagemagick
```

## Organisation de l'archive

 
    ./    :  le Makefile (permettant de créer les 3 executables qui sont contenu dans le dossier bin) et les autres dossiers

	bin/  : Les executables : blackjack maintest et maindemo

	data/ : Toutes les données nécessaires pour le fonctionnement graphique : images, musiques, police.

	doc/  : Un fichier de configuration doxygen image.doxy, un dossier htlm contenant le résultat de la génération de la documentation doxygen et ce readme

	obj/  : Les fichiers objets (.o) : Carte.o Croupier.o JeuSdl.o JeuTxt.o Joueur.o main.o maindemo.o maintest.o Paquet.o
	
	src/  : Les fichiers sources cpp et header .h : Carte.cpp Carte.h Croupier.cpp Croupier.h JeuSdl.cpp Jeu.Sdl.h JeuTxt.cpp JeuTxt.h Joueur.cpp Joueur.h main.cpp maindemo.cpp maintest.cpp Paquet.cpp Paquet.h
	
	
## Utilisation et Executables

Pour compiler et créer les executables, on utilise la commande make dans le terminal Linux puis on utilisera la commande ./bin/nomExecutable dans le terminal depuis le dossier racine pour le lancer
    
    executables crées : blackjack maintest et maindemo
    
    blackjack   : executable permettant d'utiliser le mainExemple
    
    maintest      : executable permettant d'utiliser le mainTest
    
    maindemo : executable permettant d'utiliser le mainAffichage
    
## Mains 

    blackjack   : Permet de jouer au blackjack en mode textuel ou graphique
    
    mainTest      : Permet d'utiliser une fonction de test de regression pour chaque classe qui permet de vérifier que tous les comportement des fonctions sont ceux attendus
    
    maindemo : Permet de jouer au blackjack avec un paquet particulier pour montrer les différents cas
    
## Utiliser le main principale (blackjack)
Pour lancer chaque version du projet (textuelle et graphique), il faut préciser certains arguments après la commande de lancement : ./bin blackjack

    Arguments à mettre pour la version textuelle : 
      - Premier paramètre : txt pour la version textuelle
      - Second Argument : Le niveau du jeu (1 ou 2).
      - Troisième Argument : Le nombre de paquets (entre 1 et 8).
      - Quatrième paraArgumentmètre : Le nombre de jetons du joueur (entre 500 et 10 000).
      - Cinquième Argument : Le nom du joueur
      
    Arguments à mettre pour la version graphique :
      - Un seul argument : sdl pour la version SDL 

## Utilisation du jeu en textuel

    Suivre les indications dans le terminal : 
    
 ![alt text](https://zupimages.net/up/21/18/00s7.png)
        
## Raccouris pour utiliser le jeu en SDL
Raccourcis à suivre pour chaque page : 

    Première page : 
- Menu Principal : 
  * ![alt text](https://zupimages.net/up/21/18/0qtx.png)
  * Raccourcis : 
    - Flèche Haut et Bas pour se déplacer de haut en bas
    - Flèche Droite et Gauche pour se déplacer de gauche à droite
    - Entrée pour séléctionner une partie du menu
    - Echap pour fermer la fenêtre
    - Résultat du choix : 
    - Jouer -> Menu de séléction des options de jeu (nombre de jetons, nom, nombre de paquets, difficulté)
    - Règles -> Règles du jeu
    - Option -> Options visuels ( Motif de la table, volume de la musique, Motif des jetons et Cartes)
    - Quitter -> Quitte le jeu


    Règles (Règles) :
    
  * ![alt text](https://zupimages.net/up/21/18/6u6a.png)
  * Raccourcis : 
    - Entrée pour revenir à Menu Principal
    - BackSpace pour revenir à la fenêtre précédente


    Options Visuels (Options) :
  * ![alt text](https://zupimages.net/up/21/18/21np.png)
  * Raccourcis : 
    - Flèche Haut et Bas pour se déplacer de haut en bas
    - Flèche Droite et Gauche pour changer les données dans les zones de saisie
    - Entrée sur Valider -> Retour vers le Menu Principal (NE PAS APPUYER SUR ENTRÉE AUTRE PART)
    - Echap pour fermer la fenêtre
    - BackSpace pour revenir à la fenêtre précédente


    Menu de selection (Jouer) :
  * ![alt text](https://zupimages.net/up/21/18/scnm.png)
  * Raccourcis : 
    - Flèche Haut et Bas pour se déplacer de haut en bas
    - Flèche Droite et Gauche pour changer les données dans les zones de saisie (sauf Nom joueur)
    - Flèche Droite et Gauche avec Nom joueur pour lancer la saisie du nom
    - Entrée pour finir la saisie de nom (NE PAS APPUYER SUR ENTRÉE À UNE AUTRE ZONE DE SAISIE QUE CELLE DU NOM)
    - Entrée sur Retour/Jouer (Retour au Menu Principal / Jouer pour continuer vers la séléction de mise)
    - Echap pour fermer la fenêtre
    - BackSpace pour revenir à la fenêtre précédente


    Selection de Mise
   * ![alt text](https://zupimages.net/up/21/18/1pw8.png)
   * Raccourcis : 
     - Flèche Haut et Bas pour se déplacer de haut en bas
     - Flèche Droite et Gauche sur la case de mise pour changer de mise
     - Entrée sur Valider pour finir la saisie de mise (NE PAS APPUYER SUR ENTRÉE À UNE AUTRE ZONE DE SAISIE QUE CELLE DE LA MISE)


    Écran de jeu
- Écran de jeu
  * ![alt text](https://zupimages.net/up/21/18/ufjl.png) 
  * Raccourcis : 
    - Flèche Haut et Bas avec le menu fermée pour se déplacer de haut en bas (entre les actions et le menu en haut)
    - Flèche Haut et Bas avec le menu ouvert pour choisir la section de menu
    - Flèche Droite et Gauche au niveau des actions pour se déplacer entre les actions possibles
    - Flèche Droite et Gauche au niveau du menu pour se déplacer entre le menu (MENU) et les règles (?)
    - Entrée au niveau des actions pour valider l'action
    - Entrée au niveau du menu pour lancer le menu ou les règles

- Écran de jeu avec l'assurance 
  * ![alt text](https://zupimages.net/up/21/18/a05o.png)
  * Raccourcis : 
    - Flèche Gauche et Droite pour choisir si on prend l'assurance
    - Entrée pour valider sa séléction

- Écran de jeu avec le menu lancé :
   * ![alt text](https://zupimages.net/up/21/18/03gb.png)
   * Raccourcis :
     - Flèche Haut et Bas avec le menu ouvert pour choisir la section de menu
        * Continuer -> Ferme le menu
        * Options -> Redirige vers le menu des options visuels
        * Quitter -> Quitte le jeu
     - Entrée pour valider sa séléction 

  
    Fin de manche
- Image de Victoire
    * Paquet Initial : ![alt text](https://zupimages.net/up/21/18/t6c4.bmp)
    * Paquet Splitté : ![alt text](https://zupimages.net/up/21/18/p0as.bmp)

- Image de Défaire
    * Paquet Initial : ![alt text](https://zupimages.net/up/21/18/q8xi.bmp)
    * Paquet Splitté : ![alt text](https://zupimages.net/up/21/18/4h9r.bmp)

- Image d'Égalité
    * Paquet Initial : ![alt text](https://zupimages.net/up/21/18/4jja.bmp)
    * Paquet Splitté : ![alt text](https://zupimages.net/up/21/18/gp18.bmp)

- Image pour l'Assurance 
    * Assurance Utile : ![alt text](https://zupimages.net/up/21/18/lqjs.bmp)
    * Assurance Inutile ! ![alt text](https://zupimages.net/up/21/18/h4ev.bmp)

    
## Créateurs

    TAIBI YOUSSEF (p1806526)
    
    BEN JEMIA Boran (p1924945)
    
    ROULLIER LEA (p1911736)
    
    

    
    
