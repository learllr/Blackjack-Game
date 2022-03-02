#include "Joueur.h"

#define NC "\e[0m"
#define YL "\e[33m"

using namespace std;

Joueur::Joueur()
{
    jetonsMises = 0;
    jetonsMisesSplit = 0;
    jetonsAssurance = 0;
    nbrCartes = 0;
    nbrCartesSplit = 0;
    prisAssurance = false;
    depassementCartes = false;
    depassementCartesSplit = false;
    estResteCartes = false;
    estResteCartesSplit = false;
    resultat = 0;
    resultatSplit = 0;
    assurance = 0;
}

Joueur::~Joueur()
{
    nom = "";
    jetonsMises = 0;
    jetonsMisesSplit = 0;
    jetonsAssurance = 0;
    nbrCartes = 0;
    nbrCartesSplit = 0;
    prisAssurance = false;
    depassementCartes = false;
    depassementCartesSplit = false;
    estResteCartes = false;
    estResteCartesSplit = false;
    resultat = 0;
    resultatSplit = 0;
    assurance = 0;

    for (unsigned int i = 0; i < nbrCartes; i++)
    {
        delete tabCartesJ.at(i);
    }
    for (unsigned int j = 0; j < nbrCartesSplit; j++)
    {
        delete tabCartesJsplit.at(j);
    }
    tabCartesJ.clear();
    tabCartesJsplit.clear();
}

string Joueur::getNom() const
{
    return nom;
}

unsigned int Joueur::getJetons() const
{
    return jetons;
}

unsigned int Joueur::getJetonsMises() const
{
    return jetonsMises;
}

unsigned int Joueur::getJetonsMisesSplit() const
{
    return jetonsMisesSplit;
}

unsigned int Joueur::getJetonsAssurance() const
{
    return jetonsAssurance;
}

unsigned int Joueur::getNbrCartes() const
{
    return nbrCartes;
}

unsigned int Joueur::getNbrCartesSplit() const
{
    return nbrCartesSplit;
}

Carte *Joueur::getElementTab(unsigned int i) const
{
    return tabCartesJ.at(i);
}

Carte *Joueur::getElementTabSplit(unsigned int i) const
{
    return tabCartesJsplit.at(i);
}

bool Joueur::getBoolAssurance() const
{
    return prisAssurance;
}

bool Joueur::getDepassementCartes() const
{
    return depassementCartes;
}

bool Joueur::getDepassementCartesSplit() const
{
    return depassementCartesSplit;
}

bool Joueur::getEstResteCartes() const
{
    return estResteCartes;
}

bool Joueur::getEstResteCartesSplit() const
{
    return estResteCartesSplit;
}

unsigned int Joueur::getResultat() const
{
    return resultat;
}

unsigned int Joueur::getResultatSplit() const
{
    return resultatSplit;
}

unsigned int Joueur::getAssurance() const
{
    return assurance;
}

void Joueur::setNom(string nouveauNom)
{
    nom = nouveauNom;
}

void Joueur::setJetons(unsigned int nouveauxJetons)
{
    jetons = nouveauxJetons;
}

void Joueur::setJetonsMises(unsigned int nouveauxJetons)
{
    jetonsMises = nouveauxJetons;
}

void Joueur::setJetonsMisesSplit(unsigned int nouveauxJetonsSplit)
{
    jetonsMisesSplit = nouveauxJetonsSplit;
}

void Joueur::setJetonsAssurance(unsigned int nouveauxJetonsAssurance)
{
    jetonsAssurance = nouveauxJetonsAssurance;
}

void Joueur::setDepassementCartes(bool nouveauDepassement)
{
    depassementCartes = nouveauDepassement;
}

void Joueur::setDepassementCartesSplit(bool nouveauDepassementSplit)
{
    depassementCartesSplit = nouveauDepassementSplit;
}

void Joueur::setBoolAssurance(bool nouveauChoixAssurance)
{
    prisAssurance = nouveauChoixAssurance;
}

void Joueur::setEstResteCartes(bool nouveauEstReste)
{
    estResteCartes = nouveauEstReste;
}

void Joueur::setEstResteCartesSplit(bool nouveauEstResteSplit)
{
    estResteCartesSplit = nouveauEstResteSplit;
}

void Joueur::setResultat(bool nouveauResultat)
{
    resultat = nouveauResultat;
}

void Joueur::setResultatSplit(bool nouveauResultatSplit)
{
    resultatSplit = nouveauResultatSplit;
}

void Joueur::setAssurance(bool nouvelleAssurance)
{
    assurance = nouvelleAssurance;
}

void Joueur::initialisationJoueur(string nomJoueur, unsigned int nbrJetons)
{
    nom = nomJoueur;
    jetons = nbrJetons;
}

unsigned int Joueur::sommeValeurCartes()
{
    unsigned int i = 0;
    vector<Carte *> TabCopie(tabCartesJ);
    int nouvelle_somme = 0;

    for (unsigned int j = 0; j < tabCartesJ.size(); j++)
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

unsigned int Joueur::sommeValeurCartesSplit()
{
    unsigned int i = 0;
    vector<Carte *> TabCopie(tabCartesJsplit);
    int nouvelle_somme = 0;

    for (unsigned int j = 0; j < tabCartesJsplit.size(); j++)
    {
        if (TabCopie.at(j)->getValeur() == "A")
        {
            TabCopie.push_back(TabCopie.at(j));
            TabCopie.erase(TabCopie.begin() + j);
        }
    }
    while (i < nbrCartesSplit)
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

bool Joueur::calculDepassement()
{
    if (sommeValeurCartes() > 21)
    {
        setDepassementCartes(true);
        return (true);
    }
    return (false);
}

bool Joueur::calculDepassementSplit()
{
    if (sommeValeurCartesSplit() > 21)
    {
        setDepassementCartesSplit(true);
        return (true);
    }
    return (false);
}

void Joueur::ajouterCarte(Carte *c)
{
    tabCartesJ.push_back(c);
    nbrCartes++;
}

void Joueur::ajouterCarteSplit(Carte *c)
{
    tabCartesJsplit.push_back(c);
    nbrCartesSplit++;
}

void Joueur::finManche()
{
    jetonsMises = 0;
    jetonsMisesSplit = 0;
    jetonsAssurance = 0;
    nbrCartes = 0;
    nbrCartesSplit = 0;
    prisAssurance = false;
    depassementCartes = false;
    depassementCartesSplit = false;
    estResteCartes = false;
    estResteCartesSplit = false;
    resultat = 0;
    resultatSplit = 0;
    assurance = 0;

    for (unsigned int i = 0; i < nbrCartes; i++)
    {
        delete tabCartesJ.at(i);
    }
    for (unsigned int j = 0; j < nbrCartesSplit; j++)
    {
        delete tabCartesJsplit.at(j);
    }
    tabCartesJ.clear();
    tabCartesJsplit.clear();
}

void Joueur::gainManche(unsigned int sommeCartesC, unsigned int nbrCartesC)
{
    // Cas : Le joueur a pris l'assurance et il gagne.
    if (prisAssurance && (sommeCartesC == 21) && (nbrCartesC == 2))
    {
        setJetons(getJetons() + (getJetonsAssurance() * 3));
        cout << endl
             << YL "=> Le croupier a eu un BlackJack mais vous aviez pris une assurance. Vous gagnez 3 fois la valeur de l'assurance." NC << endl
             << endl;
        assurance = 2;
    }

    // Cas :Le Joueur a pris une assurance mais elle n'a servi à rien.
    else if (prisAssurance && (((sommeCartesC == 21) && (nbrCartesC > 2)) || ((sommeCartesC != 21))))
    {
        cout << endl
             << YL "=> Vous avez pris une assurance mais le croupier n'a pas eu un BlackJack, vous perdez votre mise d'assurance." NC << endl
             << endl;
        assurance = 1;
    }

    // Cas : Double blackjack de la part du joueur et du croupier ou qu'il y a une égalité entre le joueur et le croupier sans blackjack.
    if (((sommeCartesC == 21) && (sommeValeurCartes() == 21) && (nbrCartesC == 2) && (nbrCartes == 2)) || (((sommeCartesC == sommeValeurCartes())) && (sommeCartesC != 21)))
    {
        setJetons(getJetons() + getJetonsMises());
        cout << endl
             << YL "=> Il y a égalité, chacun reprend sa mise." NC << endl;
        resultat = 2;
    }

    // Cas : Double blackjack avec 2 cartes du joueur et +3 cartes du croupier
    else if (((sommeCartesC == 21) && (sommeValeurCartes() == 21) && (nbrCartesC != 2) && (nbrCartes == 2)))
    {
        setJetons(getJetons() + (getJetonsMises() * 1.5));
        cout << endl
             << YL "=> Le joueur et le croupier ont eu 21 mais le joueur est le seul ayant obtenu un BlackJack, il gagne la moitié de sa mise en plus." NC << endl
             << endl;
        resultat = 3;
    }

    // Cas : double blackJack avec +3 cartes du joueur et 2 cartes du croupier
    else if (((sommeCartesC == 21) && (sommeValeurCartes() == 21) && (nbrCartesC == 2) && (nbrCartes != 2)))
    {
        setJetons(getJetons() + (getJetonsMises() * 0.5));
        cout << endl
             << YL "=> Le joueur et le croupier ont eu 21 mais le croupier est le seul ayant obtenu un BlackJack, le joueur perd la moitié de sa mise." NC << endl
             << endl;
        resultat = 2;
        
    }

    // Cas : Joueur qui gagne sans BlackJack
    else if (((sommeCartesC < sommeValeurCartes()) && (sommeValeurCartes() < 21)) || ((sommeCartesC > 21)))
    {
        setJetons(getJetons() + (getJetonsMises() * 2));
        cout << endl
             << YL "=> Le joueur gagne et obtient le double de sa mise." NC << endl;
        resultat = 3;
    }

    // Cas : Joueur qui gagne avec un blackjack
    else if ((sommeCartesC != sommeValeurCartes()) && (sommeValeurCartes() == 21))
    {
        setJetons(getJetons() + (getJetonsMises() * 2.5));
        cout << endl
             << YL "=> Le joueur gagne avec un BlackJack et obtient 2.5 fois sa mise." NC << endl
             << endl;
        resultat = 3;
    }

    // Cas : Égalité double black jack ou égalité simple pour split
    if (((sommeCartesC == 21) && (sommeValeurCartesSplit() == 21) && (nbrCartesC == 2) && (nbrCartesSplit == 2)) || (((sommeCartesC == sommeValeurCartesSplit())) && (sommeCartesC != 21)))
    {
        setJetons(getJetons() + getJetonsMisesSplit());
        cout << endl
             << YL "=> Il y a égalité sur le paquet splitté, chacun reprend sa mise." NC << endl
             << endl;
        resultatSplit = 2;
    }

    // Cas : double blackJack avec 2 cartes du joueur et +3 cartes du croupier (split)
    else if (((sommeCartesC == 21) && (sommeValeurCartesSplit() == 21) && (nbrCartesC != 2) && (nbrCartesSplit == 2)))
    {
        setJetons(getJetons() + (getJetonsMisesSplit() * 1.5));
        cout << endl
             << YL "=> Le joueur et le croupier ont eu 21 avec le paquet splitté mais le joueur est le seul ayant obtenu un blackJack, il gagne la moitié de sa mise splittée en plus." NC << endl
             << endl;
        resultatSplit = 3;
    }

    // Cas : double blackJack avec +3 cartes du joueur et 2 cartes du croupier (split)
    else if (((sommeCartesC == 21) && (sommeValeurCartesSplit() == 21) && (nbrCartesC == 2) && (nbrCartesSplit != 2)))
    {
        setJetons(getJetons() + (getJetonsMisesSplit() * 0.5));
        cout << endl
             << YL "=> Le joueur et le croupier ont eu 21 avec le paquet splitté mais le croupier est le seul ayant obtenu un blackJack, le joueur perd la moitié de sa mise." NC << endl
             << endl;
        resultatSplit = 1;
    }

    // Cas : Joueur gagne sans BlackJack split
    else if ((nbrCartesSplit >= 1) && (((sommeCartesC < sommeValeurCartesSplit()) && (sommeValeurCartesSplit() < 21)) || ((sommeCartesC > 21))))
    {
        setJetons(getJetons() + (getJetonsMisesSplit() * 2));
        cout << endl
             << YL "=> Le joueur gagne avec son paquet splité et obtient le double de sa mise." NC << endl
             << endl;
        resultatSplit = 3;
    }

    // Cas : Joueur gagne avec BlackJack split
    else if ((sommeCartesC != sommeValeurCartesSplit()) && (sommeValeurCartesSplit() == 21))
    {
        cout << endl
             << YL "=> Le joueur gagne avec un BlackJack avec son paquet splitté et obtient 2.5 fois sa mise." NC << endl
             << endl;
        setJetons(getJetons() + (getJetonsMisesSplit() * 2.5));
        resultatSplit = 3;
    }

    // Croupier gagne car il a une meilleur main que le paquet initial
    if ((sommeCartesC > sommeValeurCartes()) && (sommeCartesC <= 21))
    {
        cout << endl
             << YL "=> Vous avez perdu avec le paquet initial car le croupier a une meilleur main." NC << endl
             << endl;
        resultat = 1;
    }

    // Croupier gagne car il a une meilleur main que le paquet splitté
    if ((sommeCartesC > sommeValeurCartesSplit()) && (sommeCartesC <= 21) && (nbrCartesSplit >= 1))
    {
        cout << endl
             << YL "=> Vous avez perdu avec le paquet splitté car le croupier a une meilleur main." NC << endl
             << endl;
        resultatSplit = 1;
    }

    if (sommeValeurCartes() > 21)
    {
        cout << endl
             << YL "=> Vous avez perdu avec le paquet initial car votre main dépasse 21." NC << endl
             << endl;
        resultat = 1;
    }

    if (sommeValeurCartesSplit() > 21)
    {
        cout << endl
             << YL "=> Vous avez perdu avec le paquet splitté car votre main dépasse 21." NC << endl
             << endl;
        resultatSplit = 1;
    }
}

void Joueur::doubler()
{
    // On soustrait aux jetons ceux qu'on a misés.
    setJetons(getJetons() - getJetonsMises());
    // On double la mise.
    setJetonsMises(getJetonsMises() * 2);
}

void Joueur::doublerSplit()
{
    // On soustrait aux jetons ceux qu'on a misés.
    setJetons(getJetons() - getJetonsMisesSplit());
    // On double la mise.
    setJetonsMisesSplit(getJetonsMisesSplit() * 2);
}

void Joueur::splitter()
{
    setJetons(getJetons() - getJetonsMises());
    setJetonsMisesSplit(getJetonsMises());
    nbrCartes--;

    ajouterCarteSplit(tabCartesJ.front());
    tabCartesJ.erase(tabCartesJ.begin());
}

void Joueur::prendreAssurance()
{
    setJetons(getJetons() - (getJetonsMises() / 2));
    setJetonsAssurance(getJetonsMises() / 2);
    setBoolAssurance(true);
}

bool Joueur::verificationDoubler()
{
    return (getJetons() >= getJetonsMises());
}

bool Joueur::verificationDoublerSplit()
{
    return (getJetons() >= getJetonsMisesSplit());
}

bool Joueur::verificationPiocher()
{
    return (sommeValeurCartes() < 21);
}

bool Joueur::verificationPiocherSplit()
{
    return (sommeValeurCartesSplit() < 21);
}

bool Joueur::verificationSplitter()
{
    return ((nbrCartes == 2) && (getElementTab(0)->getValeur() == getElementTab(1)->getValeur()) && (getJetons() >= getJetonsMises()));
}

bool Joueur::verificationAssurance(Carte *carteC)
{
    return ((!getBoolAssurance()) && (getNbrCartes() == 1) && ((!strcmp(carteC->getValeur().c_str(), "10")) || (!strcmp(carteC->getValeur().c_str(), "V")) || (!strcmp(carteC->getValeur().c_str(), "D")) || (!strcmp(carteC->getValeur().c_str(), "R")) || (!strcmp(carteC->getValeur().c_str(), "A"))) && (getJetons() >= (getJetonsMises() / 2)));
}

void Joueur::testRegressionJoueur()
{
    Joueur j;
    assert(j.getJetonsMises() == 0);
    assert(j.getJetonsMisesSplit() == 0);
    assert(j.getJetonsAssurance() == 0);
    assert(j.getNbrCartes() == 0);
    assert(j.getNbrCartesSplit() == 0);
    assert(j.getBoolAssurance() == false);
    assert(j.getDepassementCartes() == false);
    assert(j.getDepassementCartesSplit() == false);
    assert(j.getEstResteCartes() == false);
    assert(j.getEstResteCartesSplit() == false);
    assert(j.tabCartesJ.size() == 0);
    assert(j.tabCartesJsplit.size() == 0);

    j.setJetonsMises(100);
    assert(j.getJetonsMises() == 100);
    j.setJetonsMisesSplit(100);
    assert(j.getJetonsMisesSplit() == 100);
    j.setJetonsAssurance(50);
    assert(j.getJetonsAssurance() == 50);
    j.setBoolAssurance(true);
    assert(j.getBoolAssurance() == true);
    j.setDepassementCartes(true);
    assert(j.getDepassementCartes() == true);
    j.setDepassementCartesSplit(true);
    assert(j.getDepassementCartesSplit() == true);
    j.setEstResteCartes(true);
    assert(j.getEstResteCartes() == true);
    j.setEstResteCartesSplit(true);
    assert(j.getEstResteCartesSplit() == true);

    j.finManche();
    assert(j.getJetonsMises() == 0);

    Carte *carte1 = new Carte("C", "8");
    Carte *carte2 = new Carte("H", "6");
    Carte *carte3 = new Carte("P", "V");
    Carte *carte4 = new Carte("T", "R");
    Carte *carte5 = new Carte("C", "A");

    j.initialisationJoueur("Bonjour", 1000);
    assert(j.getNom() == "Bonjour");
    assert(j.getJetons() == 1000);

    assert(j.calculDepassement() == false);
    assert(j.calculDepassementSplit() == false);

    j.ajouterCarte(carte1);
    assert(j.getNbrCartes() == 1);
    assert(j.getElementTab(0)->getCouleur() == carte1->getCouleur());
    assert(j.getElementTab(0)->getValeur() == carte1->getValeur());
    assert(j.sommeValeurCartes() == 8);
    assert(verificationPiocher() == true);
    j.ajouterCarte(carte1);
    assert(j.calculDepassement() == false);
    assert(j.verificationDoubler() == true);
    assert(j.verificationSplitter() == true);

    j.ajouterCarteSplit(carte2);
    assert(j.getNbrCartesSplit() == 1);
    assert(j.getElementTabSplit(0)->getCouleur() == carte2->getCouleur());
    assert(j.getElementTabSplit(0)->getValeur() == carte2->getValeur());
    assert(j.sommeValeurCartesSplit() == 6);
    assert(j.verificationSplitter() == true);
    assert(j.verificationDoublerSplit() == true);
    assert(j.verificationPiocherSplit() == true);

    j.setJetonsMises(100);
    j.doubler();
    assert(j.getJetonsMises() == 200);
    j.ajouterCarte(carte2);
    j.ajouterCarte(carte3);
    j.ajouterCarte(carte4);
    assert(j.sommeValeurCartes() == 42);
    assert(j.calculDepassement() == true);

    j.setJetonsMisesSplit(200);
    j.doublerSplit();
    assert(j.getJetonsMisesSplit() == 400);
    j.ajouterCarteSplit(carte5);
    assert(j.sommeValeurCartes() == 42);
    assert(j.calculDepassementSplit() == false);
    j.gainManche(12, 2);
    assert(j.getJetons() == 1500);

    j.finManche();

    j.ajouterCarte(carte1);
    j.ajouterCarte(carte1);
    j.setJetonsMises(100);
    j.splitter();

    assert(j.getJetons() == 1400);
    assert(j.getJetonsMisesSplit() == 100);
    assert(j.nbrCartes == 1);
    assert(j.nbrCartesSplit == 1);

    assert(j.getElementTab(0)->getValeur() == j.getElementTabSplit(0)->getValeur());
    j.prendreAssurance();

    assert(j.getJetons() == 1350);
    assert(j.getJetonsAssurance() == 50);
    assert(j.getBoolAssurance() == true);

    cout << "Test classe situations simple Joueur vérifié" << endl;

    Joueur j2;
    Joueur j3;
    Joueur j4;
    Carte *c10 = new Carte("C", "V");
    Carte *c11 = new Carte("C", "A");
    Carte *c12 = new Carte("P", "5");

    j3.setJetons(1000);
    j3.setJetonsMises(100);
    j3.ajouterCarte(c12);
    j3.ajouterCarte(c12);
    j3.ajouterCarte(c11);
    j3.gainManche(21, 2);
    assert(j3.getJetons() == 1050);

    j4.setJetons(1000);
    j4.setJetonsMises(100);
    j4.ajouterCarte(c12);
    j4.ajouterCarte(c12);
    j4.ajouterCarte(c10);
    j4.gainManche(20, 3);
    assert(j4.getJetons() == 1100);

    j4.setJetons(1000);
    j4.setJetonsMises(100);
    j4.gainManche(18, 4);
    assert(j4.getJetons() == 1200);

    j4.setJetons(1000);
    j4.setJetonsMises(100);
    j4.setJetonsAssurance(50);
    j4.setBoolAssurance(true);
    j4.gainManche(21, 2);
    assert(j4.getJetons() == 1150);

    j4.setJetons(1000);
    j4.setJetonsMises(100);
    j4.setJetonsAssurance(50);
    j4.setBoolAssurance(true);
    j4.gainManche(21, 3);
    assert(j4.getJetons() == 1000);

    j4.setJetons(1000);
    j4.setJetonsMises(100);
    j4.setJetonsAssurance(50);
    j4.setBoolAssurance(true);
    j4.gainManche(20, 2);
    assert(j4.getJetons() == 1100);

    j2.setJetons(1000);
    j2.setJetonsMises(100);
    j2.ajouterCarte(c10);
    j2.ajouterCarte(c11);
    j2.gainManche(18, 3);
    assert(j2.getJetons() == 1250);

    j2.setJetons(1000);
    j2.setJetonsMises(100);
    j2.gainManche(21, 2);
    assert(j2.getJetons() == 1100);

    j2.setJetons(1000);
    j2.setJetonsMises(100);
    j2.gainManche(21, 3);
    assert(j2.getJetons() == 1150);

    j2.setJetonsMises(0);
    j3.setJetonsMises(0);
    j4.setJetonsMises(0);

    cout << "Test classe Joueur situations compliquées vérifiés : paquet initial" << endl;

    j3.setJetons(2000);
    j3.setJetonsMisesSplit(200);
    j3.ajouterCarteSplit(c12);
    j3.ajouterCarteSplit(c12);
    j3.ajouterCarteSplit(c11);
    j3.gainManche(21, 2);
    assert(j3.getJetons() == 2100);

    j4.setJetons(2000);
    j4.setJetonsMisesSplit(200);
    j4.ajouterCarteSplit(c12);
    j4.ajouterCarteSplit(c12);
    j4.ajouterCarteSplit(c10);
    j4.gainManche(20, 3);
    assert(j4.getJetons() == 2200);

    j4.setJetons(2000);
    j4.setJetonsMisesSplit(200);
    j4.gainManche(18, 4);
    assert(j4.getJetons() == 2400);

    j2.setJetons(2000);
    j2.setJetonsMisesSplit(200);
    j2.ajouterCarteSplit(c10);
    j2.ajouterCarteSplit(c11);
    j2.gainManche(18, 3);
    assert(j2.getJetons() == 2500);

    j2.setJetons(2000);
    j2.setJetonsMisesSplit(200);
    j2.gainManche(21, 2);
    assert(j2.getJetons() == 2200);

    j2.setJetons(2000);
    j2.setJetonsMisesSplit(200);
    j2.gainManche(21, 3);
    assert(j2.getJetons() == 2300);

    cout << "Verification compliquées split confirmées" << endl;

    delete carte1;
    delete carte2;
    delete carte3;
    delete carte4;
    delete carte5;
    delete c10;
    delete c11;
    delete c12;
}