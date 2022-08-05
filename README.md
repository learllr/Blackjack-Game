# BlackJack

Our project is a BlackJack in 1 against 1 against a dealer. It was carried out as part of the teaching unit LIFAP4 of 2020-2021.

## Installation 

To fully install and operate the BlackJack. You must install the SDL2 library. 
```bash
sudo apt install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev imagemagick
```

## Organization of the archive

 
    ./    :  the Makefile (to create the 3 executables that are contained in the bin folder) and the other folders.

	bin/  : Executables -> blackjack maintest et maindemo

	data/ : All the necessary data for the graphic operation: images, music, font.

	doc/  : A doxygen image.doxy configuration file, an htlm folder containing the output of the doxygen documentation and this readme.

	obj/  : Object files (.o) : Carte.o Croupier.o JeuSdl.o JeuTxt.o Joueur.o main.o maindemo.o maintest.o Paquet.o
	
	src/  : Source files cpp et header .h : Carte.cpp Carte.h Croupier.cpp Croupier.h JeuSdl.cpp Jeu.Sdl.h JeuTxt.cpp JeuTxt.h Joueur.cpp Joueur.h main.cpp maindemo.cpp maintest.cpp Paquet.cpp Paquet.h
	
	
## Use and Executables

To compile and create executables, we use the make command in the Linux terminal and then we use the command . /bin/nameExecutable in the terminal from the root folder to launch it.
    
    executables created : blackjack maintest et maindemo
    
    blackjack   : executable to use le mainExemple
    
    maintest      : executable to use le mainTest
    
    maindemo : executable to use le mainAffichage
    
## Mains 

    blackjack   : Allows you to play blackjack in text or graphic mode.
    
    mainTest      : Allows you to use a regression test function for each class to verify that all the behavior of the functions are the expected ones.
    
    maindemo : Allows to play blackjack with a particular package to show the different cases.
    
## Use the main hand (blackjack)

To launch each version of the project (text and graphic), you must specify some arguments after the launch command: . /bin blackjack

    Arguments to put for the text version: 
      - First parameter: txt for the text version
      - Second argument: The level of the game (1 or 2).
      - Third argument: The number of packets (between 1 and 8).
      - Fourth paraArgumentmeter: The number of player chips (between 500 and 10,000).
      - Fifth Argument: The name of the player
      
    Arguments to put for the graphic version:
      - Only one argument: sdl for SDL version 

## Using the game in text

    Follow the instructions in the terminal: 
    
 ![alt text](https://zupimages.net/up/21/18/00s7.png)
        
## Raccouris to use the game in SDL
Shortcuts to follow for each page: 

    Front Page: 
- Main menu: 
  ![alt text](https://zupimages.net/up/21/18/0qtx.png)
  *Shortcuts: 
    - Up and Down arrow to move up and down
    - Right and Left arrow to move from left to right
    - Input to select part of the menu
    - Esc to close the window
    - Result of the choice: 
    - Jouer -> Selection menu for game options (number of chips, name, number of packages, difficulty)
    - Règles -> Rules of the game
    - Option -> Visual Options ( Table Pattern, Music Volume, Token Pattern and Cards)
    - Quitter -> Exit the game


    Règles (Rules) :
    
  ![alt text](https://zupimages.net/up/21/18/6u6a.png)
  * Shortcuts: 
    - Enter to return to Main Menu
    - BackSpace to go back to previous window

    Visual Options (Options):
  ![alt text](https://zupimages.net/up/21/18/21np.png)
  *Shortcuts: 
    - Up and Down arrow to move up and down
    - Right and Left arrow to change data in input fields
    - Enter Validate -> Return to Main Menu (DO NOT PRESS ENTER OTHER PART)
    - Esc to close the window
    - BackSpace to go back to previous window


    Selection Menu (Play):
  ![alt text](https://zupimages.net/up/21/18/scnm.png)
  *Shortcuts: 
    - Up and Down arrow to move up and down
    - Right and Left arrow to change data in input fields (except Player Name)
    - Right and Left arrow with Player Name to start the name entry
    - Enter to end name entry (DO NOT PRESS ENTER TO ANY OTHER INPUT AREA THAN NAME)
    - Return/Play entry (Return to Main Menu / Play to continue to bet selection)
    - Esc to close the window
    - BackSpace to go back to previous window


    Betting selection
   ![alt text](https://zupimages.net/up/21/18/1pw8.png)
   *Shortcuts: 
     - Up and Down arrow to move up and down
     - Right and Left arrow on bet box to change bet
     - Enter Validate to finish the entry of bet (DO NOT PRESS ENTER AT ANY OTHER INPUT AREA THAN THE ENTRY AREA)


    Game screen
- Game screen
  ![alt text](https://zupimages.net/up/21/18/ufjl.png) 
  *Shortcuts: 
    - Up and Down arrow with closed menu to move from top to bottom (between actions and menu to top)
    - Up and down arrow with open menu to choose menu section
    - Right and Left arrow at action level to move between possible actions
    - Right and left arrow at menu level to move between menu (MENU) and rulers (?)
    - Entry at the action level to validate the action
    - Menu level entry to launch menu or rules

- Play screen with insurance 
  ![alt text](https://zupimages.net/up/21/18/a05o.png)
  *Shortcuts: 
    - Left and Right arrow to choose whether to take insurance
    - Input to validate its selection

- Game screen with the menu launched:
   ![alt text](https://zupimages.net/up/21/18/03gb.png)
   *Shortcuts:
     - Up and down arrow with open menu to choose menu section
        * Continue -> Close the menu
        * Options -> Redirects to Visual Options menu
        * Quit -> Quit the game
     - Input to validate its selection 

  
    End of the inning
- Image of Victoire
    * Initial Package: ![alt text](https://zupimages.net/up/21/18/t6c4.bmp)
    * Splitted Package: ![alt text](https://zupimages.net/up/21/18/p0as.bmp)

- Image of Undo
    * Initial Package: ![alt text](https://zupimages.net/up/21/18/q8xi.bmp)
    * Splitted Package: ![alt text](https://zupimages.net/up/21/18/4h9r.bmp)

- Image of Equality
    * Initial Package: ![alt text](https://zupimages.net/up/21/18/4jja.bmp)
    * Splitted Package: ![alt text](https://zupimages.net/up/21/18/gp18.bmp)

- Image for Insurance 
    * Useful Insurance: ![alt text](https://zupimages.net/up/21/18/lqjs.bmp)
    * Insurance Useless ![alt text](https://zupimages.net/up/21/18/h4ev.bmp)

    
## Creators

    
    BEN JEMIA Boran
    
    ROULLIER LEA
    
    

    
    
