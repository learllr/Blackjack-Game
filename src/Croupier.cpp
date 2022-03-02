#include "Croupier.h"

Croupier::Croupier()
{
    nbrCartes = 0;
    depassementCartes = false;
    estResteCartes = false;
    
    string tabNoms[10] = {
        "Jérome", "Jean-Michel", "Jean-Joël", "Patrick", "René", 
        "Julien", "Christian", "Pierre-Henri", "Dorian", "Pierre"
    };

    srand((unsigned)time(0));
    nom = tabNoms[rand() % 10];
}

Croupier::~Croupier()
{
    nbrCartes = 0;
    depassementCartes = false;
    estResteCartes = false;
    
    for (unsigned int i = 0; i < nbrCartes; i++)
    {
        delete tabCartesC.at(i);
    }
    tabCartesC.clear();
}

string Croupier::getNom() const
{
    return nom;
}

Carte* Croupier::getElementTab(unsigned int i) const
{
    return tabCartesC.at(i);
}

unsigned int Croupier::getNbrCartes() const
{
    return nbrCartes;
}

bool Croupier::getDepassementCartes() const
{
    return depassementCartes;
}

bool Croupier::getEstResteCartes() const
{
    return estResteCartes;
}

void Croupier::setDepassementCartes(bool nouveauDepassement)
{
    depassementCartes = nouveauDepassement;
}

void Croupier::setEstResteCartes(bool nouveauEstReste)
{
    estResteCartes = nouveauEstReste;
}

unsigned int Croupier::sommeValeurCartes()
{
    unsigned int i = 0;
    vector<Carte *> TabCopie(tabCartesC);
    int nouvelle_somme = 0;

    for (unsigned int j = 0; j < tabCartesC.size(); j++)
    {
        if (TabCopie.at(j)->getValeur() == "A")
        {
            TabCopie.push_back(TabCopie.at(j));
            TabCopie.erase(TabCopie.begin() + j);
        }
    }
    while (i < nbrCartes)
    {
        string ajout = TabCopie.at(i)->getValeur();
        if ((ajout == "A") && (nouvelle_somme <= 10))
            nouvelle_somme = nouvelle_somme + 11;
        else if ((ajout == "V" || ajout == "D" || ajout == "R"))
            nouvelle_somme = nouvelle_somme + 10;
        else if ((ajout == "A" && (nouvelle_somme > 10)))
            nouvelle_somme = nouvelle_somme + 1;
        else
            nouvelle_somme = nouvelle_somme + atoi(ajout.c_str());
        i++;
    }
    return (nouvelle_somme);
}

bool Croupier::calculDepassement()
{
    if (sommeValeurCartes() > 21)
    {
        setDepassementCartes(true);
        return true;
    }
    return false;
}

void Croupier::ajouterCarte(Carte *c)
{
    tabCartesC.push_back(c);
    nbrCartes++;
}

void Croupier::finManche()
{
    nbrCartes = 0;
    depassementCartes = false;
    estResteCartes = false;

    for (unsigned int i = 0; i < nbrCartes; i++)
    {
        delete tabCartesC.at(i);
    }
    tabCartesC.clear();
}

bool Croupier::verificationPiocher()
{
    return (sommeValeurCartes() < 21);
}

void Croupier::testRegressionCroupier()
{
    Croupier croup;
    Carte *carte = new Carte("C", "8");
    Carte *carte2 = new Carte("H", "9");
    Carte *carte3 = new Carte("T", "10");

    assert(croup.getDepassementCartes() == false);
    assert(croup.getEstResteCartes() == false);
    assert((croup.getNom() == "Jérome") || (croup.getNom() == "Jean-Michel") 
    || (croup.getNom() == "Patrick") || (croup.getNom() == "René")
    || (croup.getNom() == "Julien")|| (croup.getNom() == "Christian")
    || (croup.getNom() == "Pierre-Henri")|| (croup.getNom() == "Dorian")
    || (croup.getNom() == "Pierre")|| (croup.getNom() == "Jean-Joël"));
    assert(croup.getNbrCartes() == 0);
    
    croup.ajouterCarte(carte);
    assert(croup.getNbrCartes() == 1);
    assert(croup.getElementTab(0)->getCouleur() == carte->getCouleur());
    assert(croup.getElementTab(0)->getValeur() == carte->getValeur());
    assert(croup.sommeValeurCartes() == 8);
    assert(croup.verificationPiocher() == true);

    croup.setDepassementCartes(true);
    assert(croup.getDepassementCartes() == true);
    croup.setEstResteCartes(true);
    assert(croup.getEstResteCartes() == true);

    croup.setDepassementCartes(false);
    croup.setEstResteCartes(false);

    assert(croup.sommeValeurCartes() == 0);

    croup.ajouterCarte(carte2);
    assert(croup.getNbrCartes() == 2);
    assert(croup.sommeValeurCartes() == 17);
    assert(croup.calculDepassement() == false);
    assert(croup.verificationPiocher() == true);
    assert(croup.getElementTab(1)->getCouleur() == carte2->getCouleur());
    assert(croup.getElementTab(1)->getValeur() == carte2->getValeur());

    croup.ajouterCarte(carte3);
    assert(croup.getNbrCartes() == 3);
    assert(croup.sommeValeurCartes() == 27);
    assert(croup.calculDepassement() == true);
    assert(croup.verificationPiocher() == false);
    assert(croup.getElementTab(2)->getCouleur() == carte3->getCouleur());
    assert(croup.getElementTab(2)->getValeur() == carte3->getValeur());

    croup.finManche();
    assert(croup.getNbrCartes() == 0);
    assert(croup.getEstResteCartes() == false);
    assert(croup.getDepassementCartes() == false);
    assert(croup.sommeValeurCartes() == 0);
    assert(croup.calculDepassement() == false);
    assert(croup.verificationPiocher() == true);

    delete carte;
    delete carte2;
    delete carte3;  
}
