#include "Paquet.h"

Paquet::Paquet()
{
}

Paquet::~Paquet()
{
    nbPaquets = 0;
    for (unsigned int i = 0; i < tabCartes.size(); i++)
    {
        delete tabCartes.at(i);
    }
    tabCartes.clear();
}

void Paquet::initialisationPaquet(unsigned int nouveauPaquet)
{
    nbPaquets = nouveauPaquet;
    reinitialisationPaquets();
}

void Paquet::reinitialisationPaquets()
{
    // Quand on aura - de 20 cartes.
    for (unsigned int i = 0; i < tabCartes.size(); i++)
    {
        delete tabCartes.at(i);
    }
    tabCartes.clear();
    for (unsigned int i = 0; i < nbPaquets; i++)
    {
        tabCartes.push_back(new Carte("P", "A"));
        tabCartes.push_back(new Carte("P", "2"));
        tabCartes.push_back(new Carte("P", "3"));
        tabCartes.push_back(new Carte("P", "4"));
        tabCartes.push_back(new Carte("P", "5"));
        tabCartes.push_back(new Carte("P", "6"));
        tabCartes.push_back(new Carte("P", "7"));
        tabCartes.push_back(new Carte("P", "8"));
        tabCartes.push_back(new Carte("P", "9"));
        tabCartes.push_back(new Carte("P", "10"));
        tabCartes.push_back(new Carte("P", "V"));
        tabCartes.push_back(new Carte("P", "D"));
        tabCartes.push_back(new Carte("P", "R"));

        tabCartes.push_back(new Carte("T", "A"));
        tabCartes.push_back(new Carte("T", "2"));
        tabCartes.push_back(new Carte("T", "3"));
        tabCartes.push_back(new Carte("T", "4"));
        tabCartes.push_back(new Carte("T", "5"));
        tabCartes.push_back(new Carte("T", "6"));
        tabCartes.push_back(new Carte("T", "7"));
        tabCartes.push_back(new Carte("T", "8"));
        tabCartes.push_back(new Carte("T", "9"));
        tabCartes.push_back(new Carte("T", "10"));
        tabCartes.push_back(new Carte("T", "V"));
        tabCartes.push_back(new Carte("T", "D"));
        tabCartes.push_back(new Carte("T", "R"));

        tabCartes.push_back(new Carte("C", "A"));
        tabCartes.push_back(new Carte("C", "2"));
        tabCartes.push_back(new Carte("C", "3"));
        tabCartes.push_back(new Carte("C", "4"));
        tabCartes.push_back(new Carte("C", "5"));
        tabCartes.push_back(new Carte("C", "6"));
        tabCartes.push_back(new Carte("C", "7"));
        tabCartes.push_back(new Carte("C", "8"));
        tabCartes.push_back(new Carte("C", "9"));
        tabCartes.push_back(new Carte("C", "10"));
        tabCartes.push_back(new Carte("C", "V"));
        tabCartes.push_back(new Carte("C", "D"));
        tabCartes.push_back(new Carte("C", "R"));

        tabCartes.push_back(new Carte("H", "A"));
        tabCartes.push_back(new Carte("H", "2"));
        tabCartes.push_back(new Carte("H", "3"));
        tabCartes.push_back(new Carte("H", "4"));
        tabCartes.push_back(new Carte("H", "5"));
        tabCartes.push_back(new Carte("H", "6"));
        tabCartes.push_back(new Carte("H", "7"));
        tabCartes.push_back(new Carte("H", "8"));
        tabCartes.push_back(new Carte("H", "9"));
        tabCartes.push_back(new Carte("H", "10"));
        tabCartes.push_back(new Carte("H", "V"));
        tabCartes.push_back(new Carte("H", "D"));
        tabCartes.push_back(new Carte("H", "R"));
    }
    melangerCartes();
}

void Paquet::melangerCartes()
{
    srand((unsigned)time(0));

    for (unsigned int i = 0; i < (unsigned int)tabCartes.size(); i++)
    {
        swap(tabCartes[i], tabCartes[rand() % tabCartes.size()]);
    }
}

Carte *Paquet::prendPremiereCarte()
{
    Carte *premiereCarte = tabCartes.front();
    tabCartes.erase(tabCartes.begin());
    return premiereCarte;
}

void Paquet::testRegressionPaquet()
{
    Paquet p;

    p.initialisationPaquet(1);
    assert(p.tabCartes.size() == 52); // 52 cartes par paquets.

    /*
   for(unsigned int i = 1 ; i < 10; i++)
   {
       assert(p.tabCartes.at(i)->getCouleur() == "P");
   }
   
   for(unsigned int i = 13 ; i < 26; i++)
   {
       assert(p.tabCartes.at(i)->getCouleur() == "T");
   }
   assert(p.tabCartes.at(3)->getValeur() == "4");

    */

    for (unsigned int i = 1; i < 51; i++)
    {
        assert((p.tabCartes.at(i)->getValeur() != p.tabCartes.at(i - 1)->getValeur()) || (p.tabCartes.at(i)->getValeur() != p.tabCartes.at(i + 1)->getValeur()) || (p.tabCartes.at(i)->getCouleur() != p.tabCartes.at(i + 1)->getCouleur()) || (p.tabCartes.at(i - 1)->getCouleur() != p.tabCartes.at(i)->getCouleur()));
    }

    Carte *c = p.tabCartes.front();
    Carte *c2 = p.prendPremiereCarte();
    assert(c->getValeur() == c2->getValeur());
    assert(c->getCouleur() == c2->getCouleur());

    cout << "Test de Paquet Vérifié" << endl;
}

void Paquet::demopaquet()
{
    for (unsigned int i = 0; i < tabCartes.size(); i++)
    {
        delete tabCartes.at(i);
    }
    tabCartes.clear();
    tabCartes.clear();

    // victoire avec paquet splitté et défaite paquet initial

    tabCartes.push_back(new Carte("T", "10"));
    tabCartes.push_back(new Carte("H", "9"));
    tabCartes.push_back(new Carte("C", "10"));
    tabCartes.push_back(new Carte("P", "V"));
    tabCartes.push_back(new Carte("C", "7"));
    tabCartes.push_back(new Carte("T", "9")); 

    // Assurance Gagnée mais pas la partie

    tabCartes.push_back(new Carte("P", "10"));
    tabCartes.push_back(new Carte("C", "V"));
    tabCartes.push_back(new Carte("H", "8"));
    tabCartes.push_back(new Carte("T", "A"));

    // Assurance Perdue et partie perdue

    tabCartes.push_back(new Carte("C", "10"));
    tabCartes.push_back(new Carte("H", "V"));
    tabCartes.push_back(new Carte("T", "8"));
    tabCartes.push_back(new Carte("P", "9")); 
                                              
    
    // blackjack joueur

    tabCartes.push_back(new Carte("C", "A"));
    tabCartes.push_back(new Carte("C", "10"));
    tabCartes.push_back(new Carte("C", "D"));
    tabCartes.push_back(new Carte("C", "8"));

    // echec joueur la main depasse 21

    tabCartes.push_back(new Carte("C", "7"));
    tabCartes.push_back(new Carte("T", "10"));
    tabCartes.push_back(new Carte("P", "V"));
    tabCartes.push_back(new Carte("H", "D"));

    // victoire joueur pas blackjack

    tabCartes.push_back(new Carte("C", "10"));
    tabCartes.push_back(new Carte("H", "R"));
    tabCartes.push_back(new Carte("P", "9"));
    tabCartes.push_back(new Carte("C", "8"));

    // Victoire joueur le croupier pioche trop

    tabCartes.push_back(new Carte("T", "10"));
    tabCartes.push_back(new Carte("H", "10"));
    tabCartes.push_back(new Carte("C", "9"));
    tabCartes.push_back(new Carte("P", "6"));
    tabCartes.push_back(new Carte("P", "10"));

    // Victoire avec paquet splitté et paquet initial

    tabCartes.push_back(new Carte("T", "10"));
    tabCartes.push_back(new Carte("H", "9"));
    tabCartes.push_back(new Carte("C", "10"));
    tabCartes.push_back(new Carte("P", "V"));
    tabCartes.push_back(new Carte("C", "D"));
    tabCartes.push_back(new Carte("T", "9")); 

    // Defaite Croupier a une meilleur main

    tabCartes.push_back(new Carte("T", "10"));
    tabCartes.push_back(new Carte("H", "9"));
    tabCartes.push_back(new Carte("C", "4"));
    tabCartes.push_back(new Carte("P", "A")); 

    
    // Égalité paquet normal

    tabCartes.push_back(new Carte("P", "10"));
    tabCartes.push_back(new Carte("H", "V"));
    tabCartes.push_back(new Carte("C", "D"));
    tabCartes.push_back(new Carte("P", "R"));

    // Égalité paquet splitté et defaite paquet normal

    tabCartes.push_back(new Carte("C", "D"));
    tabCartes.push_back(new Carte("T", "V"));
    tabCartes.push_back(new Carte("P", "D"));
    tabCartes.push_back(new Carte("P", "R"));
    tabCartes.push_back(new Carte("C", "7"));
    tabCartes.push_back(new Carte("T", "10"));

    // BlackJack avec Paquet Splitté et défaite paquet initial

    tabCartes.push_back(new Carte("P", "D"));
    tabCartes.push_back(new Carte("H", "10"));
    tabCartes.push_back(new Carte("T", "D"));
    tabCartes.push_back(new Carte("P", "A"));
    tabCartes.push_back(new Carte("H", "7"));
    tabCartes.push_back(new Carte("C", "8"));


    //RESERVE DE CARTES :

    tabCartes.push_back(new Carte("T", "10"));
    tabCartes.push_back(new Carte("H", "9"));
    tabCartes.push_back(new Carte("C", "10"));
    tabCartes.push_back(new Carte("P", "V"));
    tabCartes.push_back(new Carte("C", "D"));
    tabCartes.push_back(new Carte("T", "9"));
    tabCartes.push_back(new Carte("T", "10"));
    tabCartes.push_back(new Carte("H", "9"));
    tabCartes.push_back(new Carte("C", "10"));
    tabCartes.push_back(new Carte("P", "V"));
    tabCartes.push_back(new Carte("C", "D"));
    tabCartes.push_back(new Carte("T", "9"));
    tabCartes.push_back(new Carte("T", "10"));
    tabCartes.push_back(new Carte("H", "9"));
    tabCartes.push_back(new Carte("C", "10"));
    tabCartes.push_back(new Carte("P", "V"));
    tabCartes.push_back(new Carte("C", "D"));
    tabCartes.push_back(new Carte("T", "9"));
    tabCartes.push_back(new Carte("T", "10"));
    tabCartes.push_back(new Carte("H", "9"));
    tabCartes.push_back(new Carte("C", "10"));
    tabCartes.push_back(new Carte("P", "V"));
    tabCartes.push_back(new Carte("C", "D"));
    tabCartes.push_back(new Carte("T", "9"));
    tabCartes.push_back(new Carte("T", "10"));
    tabCartes.push_back(new Carte("H", "9"));
    tabCartes.push_back(new Carte("C", "10"));
    tabCartes.push_back(new Carte("P", "V"));
    tabCartes.push_back(new Carte("C", "D"));
    tabCartes.push_back(new Carte("T", "9"));
    tabCartes.push_back(new Carte("T", "10"));
    tabCartes.push_back(new Carte("H", "9"));
    tabCartes.push_back(new Carte("C", "10"));
    tabCartes.push_back(new Carte("P", "V"));
    tabCartes.push_back(new Carte("C", "D"));
    tabCartes.push_back(new Carte("T", "9"));
    tabCartes.push_back(new Carte("T", "10"));
    tabCartes.push_back(new Carte("H", "9"));
    tabCartes.push_back(new Carte("C", "10"));
    tabCartes.push_back(new Carte("P", "V"));
    tabCartes.push_back(new Carte("C", "D"));
    tabCartes.push_back(new Carte("T", "9"));
    tabCartes.push_back(new Carte("C", "D"));
    tabCartes.push_back(new Carte("T", "9"));
    tabCartes.push_back(new Carte("T", "10"));
    tabCartes.push_back(new Carte("H", "9"));
    tabCartes.push_back(new Carte("C", "10"));
    tabCartes.push_back(new Carte("P", "V"));
    tabCartes.push_back(new Carte("C", "D"));
    tabCartes.push_back(new Carte("T", "9"));
    tabCartes.push_back(new Carte("T", "10"));
    tabCartes.push_back(new Carte("H", "9"));
    tabCartes.push_back(new Carte("C", "10"));
    tabCartes.push_back(new Carte("P", "V"));
    tabCartes.push_back(new Carte("C", "D"));
    tabCartes.push_back(new Carte("T", "9"));
    tabCartes.push_back(new Carte("C", "D"));
    tabCartes.push_back(new Carte("T", "9"));
    tabCartes.push_back(new Carte("T", "10"));
    tabCartes.push_back(new Carte("H", "9"));
    tabCartes.push_back(new Carte("C", "10"));
    tabCartes.push_back(new Carte("P", "V"));
    tabCartes.push_back(new Carte("C", "D"));
    tabCartes.push_back(new Carte("T", "9"));
    tabCartes.push_back(new Carte("T", "10"));
    tabCartes.push_back(new Carte("H", "9"));
    tabCartes.push_back(new Carte("C", "10"));
    tabCartes.push_back(new Carte("P", "V"));
    tabCartes.push_back(new Carte("C", "D"));
    tabCartes.push_back(new Carte("T", "9"));
}
