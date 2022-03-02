#include "Carte.h"

Carte::Carte()
{
}

Carte::Carte(string nouvelleCouleur, string nouvelleValeur)
{
    couleur = nouvelleCouleur;
    valeur = nouvelleValeur;
}

Carte::~Carte()
{
}

string Carte::getCouleur() const
{
    return couleur;
}

string Carte::getValeur() const
{
    return valeur;
}

void Carte::setCouleur(string nouvelleCouleur)
{
    couleur = nouvelleCouleur;
}

void Carte::setValeur(string nouvelleValeur)
{
    valeur = nouvelleValeur;
}

void Carte::testRegressionCarte()
{
    Carte *c1 = new Carte("C","V");
    assert(c1->getCouleur() == "C");
    assert(c1->getValeur() == "V");

    c1->setCouleur("H");
    c1->setValeur("2");

    assert(c1->getCouleur() == "H");
    assert(c1->getValeur() == "2");

    cout<<"Test de Carte Validés"<<endl;

    delete c1;
}
