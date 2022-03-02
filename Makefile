# ----- Les variables -----

LIB = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
DIRECT_SDL = -I/usr/include/SDL2 -L/usr/lib


# ----- make all -----

all: bin/blackjack bin/maintest bin/maindemo


# ----- L'exécutable -----

bin/blackjack :  obj/main.o obj/Carte.o obj/Paquet.o obj/Joueur.o obj/Croupier.o obj/JeuTxt.o obj/JeuSdl.o
	g++ -g -W -Wall  obj/main.o obj/Carte.o obj/Paquet.o obj/Joueur.o obj/Croupier.o obj/JeuTxt.o obj/JeuSdl.o -o bin/blackjack $(LIB) 

bin/maintest :  obj/maintest.o obj/Carte.o obj/Paquet.o obj/Joueur.o obj/Croupier.o obj/JeuTxt.o obj/JeuSdl.o
	g++ -g -W -Wall obj/maintest.o obj/Carte.o obj/Paquet.o obj/Joueur.o obj/Croupier.o obj/JeuTxt.o obj/JeuSdl.o -o bin/maintest $(LIB)

bin/maindemo :  obj/maindemo.o obj/Carte.o obj/Paquet.o obj/Joueur.o obj/Croupier.o obj/JeuTxt.o obj/JeuSdl.o
	g++ -g -W -Wall obj/maindemo.o obj/Carte.o obj/Paquet.o obj/Joueur.o obj/Croupier.o obj/JeuTxt.o obj/JeuSdl.o -o bin/maindemo $(LIB)


# ----- Les fichiers obj -----

obj/maintest.o: src/maintest.cpp src/Paquet.h src/Joueur.h src/Croupier.h src/JeuTxt.h src/JeuSdl.h
	g++ -g -W -Wall -c src/maintest.cpp -o obj/maintest.o $(DIRECT_SDL)

obj/maindemo.o: src/maindemo.cpp src/Paquet.h src/Joueur.h src/Croupier.h src/JeuTxt.h src/JeuSdl.h
	g++ -g -W -Wall -c src/maindemo.cpp -o obj/maindemo.o $(DIRECT_SDL)

obj/main.o: src/main.cpp src/Paquet.h src/Joueur.h src/Croupier.h src/JeuTxt.h src/JeuSdl.h
	g++ -g -W -Wall -c src/main.cpp -o obj/main.o $(DIRECT_SDL)

obj/Carte.o: src/Carte.cpp src/Carte.h
	g++ -g -W -Wall -c src/Carte.cpp -o obj/Carte.o $(DIRECT_SDL)

obj/Paquet.o: src/Paquet.cpp src/Carte.h src/Paquet.h
	g++ -g -W -Wall -c src/Paquet.cpp -o obj/Paquet.o $(DIRECT_SDL)

obj/Joueur.o: src/Joueur.cpp src/Joueur.h src/Carte.h
	g++ -g -W -Wall -c src/Joueur.cpp -o obj/Joueur.o $(DIRECT_SDL)

obj/Croupier.o: src/Croupier.cpp src/Croupier.h src/Carte.h
	g++ -g -W -Wall -c src/Croupier.cpp -o obj/Croupier.o $(DIRECT_SDL)

obj/JeuTxt.o: src/JeuTxt.cpp src/JeuTxt.h src/Carte.h src/Paquet.h src/Croupier.h src/Joueur.h 
	g++ -g -W -Wall -c src/JeuTxt.cpp -o obj/JeuTxt.o $(DIRECT_SDL)

obj/JeuSdl.o: src/JeuSdl.cpp src/JeuSdl.h src/Carte.h src/Paquet.h src/Croupier.h src/Joueur.h 
	g++ -g -W -Wall -c src/JeuSdl.cpp -o obj/JeuSdl.o $(DIRECT_SDL)


# ----- Nettoyage -----

clean:
	rm -rf obj/*
	rm -rf bin/*
