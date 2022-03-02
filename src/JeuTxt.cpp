#include "JeuTxt.h"

// Code couleur dans le terminal.
#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRNN "\e[32m"
#define GRN "\e[1;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"
#define GY "\e[1;30m"
#define BLL "\e[34m"
#define BL "\e[1;34m"
#define VL "\e[35m"
#define VLL "\e[1;35m"

using namespace std;

JeuTxt::JeuTxt(char **argv)
{
    niveauJeu = atoi(argv[2]);
    nbPaquets = atoi(argv[3]);
    paquet.initialisationPaquet(atoi(argv[3]));
    joueur.initialisationJoueur(argv[5], atoi(argv[4]));
    stop = true;
}

JeuTxt::~JeuTxt()
{
}

string JeuTxt::casCouleur(Carte *c) const
{
    string couleur;
    char s = c->getCouleur().front();
    switch (s)
    {
    case 'T':
        couleur = "de Trèfle";
        break;
    case 'H':
        couleur = "de Coeur";
        break;
    case 'P':
        couleur = "de Pique";
        break;
    case 'C':
        couleur = "de Carreau";
        break;
    }
    return (couleur);
}

string JeuTxt::casValeur(Carte *c) const
{
    string valeur;
    char s = c->getValeur().front();
    switch (s)
    {
    case 'V':
        valeur = "Valet";
        break;
    case 'D':
        valeur = "Dame";
        break;
    case 'R':
        valeur = "Roi";
        break;
    case 'A':
        valeur = "As";
        break;
    case '1':
        valeur = "10";
        break;
    default:
        valeur = s;
        break;
    }
    return (valeur);
}

void JeuTxt::choisirMise()
{
    string choixMise;
    bool stop = true;
    while (stop)
    {
        cout << endl
             << GY "Veuillez choisir la mise de départ : " NC << endl;
        cin >> choixMise;
        cout << endl
             << endl;
        // string en char* et char* en int.
        if (((unsigned int)atoi(choixMise.c_str()) <= joueur.getJetons()) && (atoi(choixMise.c_str()) > 0))
            stop = false;
        else
            cout << RED "Mise proposée impossible, veuillez recommencer votre saisie." NC << endl;
    }
    joueur.setJetons(joueur.getJetons() - atoi(choixMise.c_str()));
    joueur.setJetonsMises(atoi(choixMise.c_str()));
}

unsigned int JeuTxt::choixJoueur(Carte *c)
{
    string choixJoueur;
    bool stop = true;
    while (stop)
    {
        cout << endl
             << BL "Action(s) possible(s) pour le paquet initial : " NC << endl;
        if (joueur.verificationPiocher())
            cout << BLL "- Piocher(1)" << endl;
        if (joueur.verificationDoubler())
            cout << "- Doubler(2)" << endl;
        cout << "- Rester(3)" << endl;
        if (joueur.verificationSplitter())
            cout << "- Splitter(4)" << endl;
        if (joueur.verificationAssurance(c))
            cout << "- Assurance(5)" << endl;
        cout << "- Quitter(6)" NC << endl;

        cout << GY "Quel est votre choix " << joueur.getNom() << " ? (Mettre un des chiffres en parenthèses)" NC << endl;
        cin >> choixJoueur;
        cout << endl;
        if (((joueur.verificationPiocher()) && (choixJoueur == "1")) || ((joueur.verificationDoubler()) && (choixJoueur == "2")) || (choixJoueur == "3") || ((joueur.verificationSplitter()) && (choixJoueur == "4")) || ((joueur.verificationAssurance(c)) && (choixJoueur == "5")) || (choixJoueur == "6"))
        {
            stop = false;
        }
        else
            cout << RED "Action séléctionnée impossible, veuillez recommencer votre sélection." << endl;
    }
    return (atoi(choixJoueur.c_str()));
}
unsigned int JeuTxt::choixJoueurSplit()
{
    string choixJoueur;
    bool stop = true;
    while (stop)
    {
        cout << endl
             << BL "Action(s) possible(s) pour le paquet splitté : " NC << endl;
        if (joueur.verificationPiocherSplit())
            cout << BLL "- Piocher(1)" << endl;
        if (joueur.verificationDoublerSplit())
            cout << "- Doubler(2)" << endl;
        cout << "- Rester(3)" << endl;
        cout << "- Quitter(4)" << endl;

        cout << endl
             << GY "Quel est votre choix " << joueur.getNom() << " ? (Mettre un des chiffres en parenthèses)" NC << endl;
        cin >> choixJoueur;
        cout << endl;
        if (((joueur.verificationPiocherSplit()) && (choixJoueur == "1")) || ((joueur.verificationDoublerSplit()) && (choixJoueur == "2")) || (choixJoueur == "3") || (choixJoueur == "4"))
        {
            stop = false;
        }
        else
            cout << RED "Action séléctionnée impossible, veuillez recommencer votre sélection." NC << endl;
    }
    return (atoi(choixJoueur.c_str()));
}

bool JeuTxt::actionJoueur(Carte *c)
{
    unsigned int choix = choixJoueur(c);

    if ((!joueur.getDepassementCartes()) && (!joueur.getEstResteCartes()))
    {
        if (choix == 1)
        {
            joueur.ajouterCarte(paquet.prendPremiereCarte());
            cout << VLL "Le croupier " << croupier.getNom() << " vous a distribué sur le paquet initial la carte " << casValeur(joueur.getElementTab(joueur.getNbrCartes() - 1))
                 << " " << casCouleur(joueur.getElementTab(joueur.getNbrCartes() - 1)) << "." NC << endl
                 << endl;
            if (joueur.calculDepassement())
                cout << RED "[Paquet initial] Vous avez perdu !" NC << endl;
        }
        else if (choix == 2)
        {
            joueur.doubler();
            cout << "Vous avez décidé de doubler votre mise initiale, elle s'élève à : " << joueur.getJetonsMises() << "." << endl
                 << endl;
            joueur.ajouterCarte(paquet.prendPremiereCarte());
            if (joueur.calculDepassement())
                cout << RED "[Paquet initial] Vous avez perdu !" NC << endl
                     << endl;
            joueur.setEstResteCartes(true);
        }
        else if (choix == 3)
        {
            joueur.setEstResteCartes(true);
            cout << "Vous avez décidé de rester sur votre paquet initial." << endl
                 << endl;
        }
        else if (choix == 4)
        {
            joueur.splitter();
            cout << "Vous avez décidé de splitter." << endl
                 << endl;
        }
        else if (choix == 5)
        {
            joueur.prendreAssurance();
            cout << "Vous avez décidé de prendre l'assurance, vous posez " << joueur.getJetonsAssurance() << " jetons sur la ligne assurance." << endl;
            cout << "Jetons: " << joueur.getJetons() << "/ Jetons misés: " << joueur.getJetonsMises() << " / Jetons assurance: " << joueur.getJetonsAssurance() << endl
                 << endl;
        }
        else if (choix == 6)
        {
            cout << RED "Vous avez quitté le casino ! Vous repartez avec " << joueur.getJetons() << " jetons." << NC << endl
                 << endl;
            return (false);
        }
        affichagePaquets();
    }
    if ((joueur.getNbrCartesSplit()) && (!joueur.getDepassementCartesSplit()) && (!joueur.getEstResteCartesSplit()))
    {
        choix = choixJoueurSplit();
        if (choix == 1)
        {
            joueur.ajouterCarteSplit(paquet.prendPremiereCarte());
            cout << VLL "Le croupier " << croupier.getNom() << " vous a distribué sur le paquet splitté la carte " << casValeur(joueur.getElementTabSplit(joueur.getNbrCartesSplit() - 1))
                 << " " << casCouleur(joueur.getElementTabSplit(joueur.getNbrCartesSplit() - 1)) << "." NC << endl;
            if (joueur.calculDepassementSplit())
                cout << RED "[Paquet splitté] Vous avez perdu !" NC << endl
                     << endl;
        }
        else if (choix == 2)
        {
            joueur.doublerSplit();
            cout << "Vous avez décidé de doubler votre mise splittée, elle s'élève à : " << joueur.getJetonsMisesSplit() << "." << endl
                 << endl;
            joueur.ajouterCarteSplit(paquet.prendPremiereCarte());
            if (joueur.calculDepassementSplit())
                cout << RED "[Paquet splitté] Vous avez perdu !" NC << endl
                     << endl;
            joueur.setEstResteCartes(true);
        }
        else if (choix == 3)
        {
            joueur.setEstResteCartesSplit(true);
            cout << "Vous avez décidé de rester sur votre paquet splitté." << endl
                 << endl;
        }
        else if (choix == 4)
        {
            cout << RED "Vous avez quitté le casino ! Vous repartez avec " << joueur.getJetons() << " jetons." << NC << endl
                 << endl;
            return (false);
        }
        affichagePaquets();
    }
    return (true);
}

void JeuTxt::actionCroupier()
{
    if (!joueur.getDepassementCartes())
    {
        if (niveauJeu == 1)
        {
            if (croupier.sommeValeurCartes() < 17)
            {
                Carte *carte = paquet.prendPremiereCarte();
                croupier.ajouterCarte(carte);
                cout << endl
                     << VLL "Le croupier " << croupier.getNom() << " a pioché la carte " << casValeur(croupier.getElementTab(croupier.getNbrCartes() - 1))
                     << " " << casCouleur(croupier.getElementTab(croupier.getNbrCartes() - 1)) << "." NC << endl
                     << endl;
                if (croupier.calculDepassement())
                {
                    cout << GRN "Vous avez gagné !" NC << endl
                         << endl;
                }
            }
            else
            {
                croupier.setEstResteCartes(true);
                cout << endl
                     << VLL "Le croupier a décidé de rester." NC << endl
                     << endl;
            }
        }
        else if (niveauJeu == 2)
        {
            if (croupier.sommeValeurCartes() <= 10)
            {
                Carte *carte = paquet.prendPremiereCarte();
                croupier.ajouterCarte(carte);
                cout << endl
                     << VLL "Le croupier " << croupier.getNom() << " a pioché la carte " << casValeur(croupier.getElementTab(croupier.getNbrCartes() - 1))
                     << " " << casCouleur(croupier.getElementTab(croupier.getNbrCartes() - 1)) << "." NC << endl
                     << endl;
            }
            else if (croupier.sommeValeurCartes() < 18)
            {
                Carte *carte = paquet.prendPremiereCarte();
                string nouvelleV = to_string(rand() % 4 + (18 - croupier.sommeValeurCartes()));
                carte->setValeur(nouvelleV);
                croupier.ajouterCarte(carte);
                cout << endl
                     << VLL "Le croupier " << croupier.getNom() << " a pioché la carte " << casValeur(croupier.getElementTab(croupier.getNbrCartes() - 1))
                     << " " << casCouleur(croupier.getElementTab(croupier.getNbrCartes() - 1)) << "." NC << endl
                     << endl;
            }
            else if (croupier.sommeValeurCartes() >= 18)
            {
                croupier.setEstResteCartes(true);
                cout << VLL "Le croupier a décidé de rester car il a 18." NC << endl
                     << endl;
            }
        }
    }
    else
    {
        croupier.setEstResteCartes(true);
        cout << VLL "Le croupier reste." NC << endl
             << endl;
    }
}

void JeuTxt::affichagePaquets()
{
    cout << "--------------------------------------------------------------------------------------------------------------" << endl;
    // Affichage du résumé des cartes détenus par le joueur et le croupier.
    cout << "Joueur " << joueur.getNom() << " [Paquet initial] : ";

    for (unsigned int i = 0; i < joueur.getNbrCartes(); i++)
    {
        cout << casValeur(joueur.getElementTab(i)) << " " << casCouleur(joueur.getElementTab(i));
        if ((i + 1) < joueur.getNbrCartes())
        {
            cout << " / ";
        }
    }
    cout << " (" << joueur.sommeValeurCartes() << ")" << endl;
    if (joueur.getNbrCartesSplit() >= 1)
    {
        cout << "Joueur " << joueur.getNom() << " [Paquet splitté] : ";
        for (unsigned int j = 0; j < joueur.getNbrCartesSplit(); j++)
        {
            cout << casValeur(joueur.getElementTabSplit(j)) << " " << casCouleur(joueur.getElementTabSplit(j));
            if ((j + 1) < joueur.getNbrCartesSplit())
                cout << " / ";
        }
        cout << " (" << joueur.sommeValeurCartesSplit() << ")" << endl;
    }
    cout << "Croupier " << croupier.getNom() << " : ";
    for (unsigned int k = 0; k < croupier.getNbrCartes(); k++)
    {
        cout << casValeur(croupier.getElementTab(k)) << " " << casCouleur(croupier.getElementTab(k));
        if ((k + 1) < croupier.getNbrCartes())
            cout << " / ";
    }
    cout << " (" << croupier.sommeValeurCartes() << ")" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------" << endl;
}

void JeuTxt::executionJeuTxt()
{
    while (stop)
    {
        cout << endl
             << endl;
        cout << GRNN "------------------------------------------------------------------" << endl;
        cout << GRN "                      Bienvenue dans le casino! " NC << endl;
        cout << GRNN "------------------------------------------------------------------" NC << endl;
        cout << GRN "[Informations de " << joueur.getNom() << "]" NC << endl
             << endl;
        cout << GRNN "Vous êtes sur la version textuelle." << endl;
        cout << "Vous avez choisi de jouer avec " << nbPaquets << " paquet(s)." << endl;
        cout << "Vous avez " << joueur.getJetons() << " jetons." << endl;
        cout << "------------------------------------------------------------------" << endl;
        cout << GRN "NIVEAU " << niveauJeu << " / BLACKJACK" NC << endl;
        cout << GRNN "------------------------------------------------------------------" NC << endl;

        choisirMise();
        cout << VLL "Le croupier " << croupier.getNom() << " mélange les cartes." NC << endl
             << endl;
        // Le croupier distribue une carte au joueur puis à lui-même.
        Carte *carte = paquet.prendPremiereCarte();
        joueur.ajouterCarte(carte);
        cout << "--------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Joueur " << joueur.getNom() << " [Paquet initial] : " << casValeur(carte) << " " << casCouleur(carte) << endl;
        carte = paquet.prendPremiereCarte();
        croupier.ajouterCarte(carte);
        cout << "Croupier " << croupier.getNom() << " : " << casValeur(carte) << " " << casCouleur(carte) << endl;
        cout << "--------------------------------------------------------------------------------------------------------------" << endl
             << endl;

        while ((stop) && (!croupier.getDepassementCartes()) && (!croupier.getEstResteCartes()))
        {
            if ((!joueur.getDepassementCartes() && !joueur.getEstResteCartes()) || (!joueur.getDepassementCartesSplit() && !joueur.getEstResteCartesSplit() && (joueur.getNbrCartesSplit() > 0)))
            {
                stop = actionJoueur(carte);
            }

            if ((stop) && ((!croupier.getDepassementCartes()) && (!croupier.getEstResteCartes())) && (joueur.getDepassementCartes() || joueur.getEstResteCartes()) && (joueur.getDepassementCartesSplit() || joueur.getEstResteCartesSplit() || (joueur.getNbrCartesSplit() == 0)))
            {
                actionCroupier();
                affichagePaquets();
            }
        }
        if (stop)
        {
            // Calcul les jetons gagnés en fin de manche.
            joueur.gainManche(croupier.sommeValeurCartes(), croupier.getNbrCartes());

            // Vérifié si le joueur à encore des jetons.
            if (joueur.getJetons() == 0)
            {
                cout << RED "Vous avez quitté le casino ! Il ne vous reste plus de jetons." NC << endl
                     << endl;
                stop = false;
            }

            // Fin manche pour les classes Joueur et Croupier.
            croupier.finManche();
            joueur.finManche();
        }
    }
}

void JeuTxt::testRegressionJeuTxt()
{
    Carte *carte1 = new Carte("C", "8");
    Carte *carte2 = new Carte("H", "R");
    Carte *carte3 = new Carte("P", "D");
    Carte *carte4 = new Carte("T", "V");
    Carte *carte5 = new Carte("C", "A");
    Carte *carte6 = new Carte("T", "10");

    string valeurC = casCouleur(carte1);
    assert(valeurC == "de Carreau");
    valeurC = casCouleur(carte2);
    assert(valeurC == "de Coeur");
    valeurC = casCouleur(carte3);
    assert(valeurC == "de Pique");
    valeurC = casCouleur(carte4);
    assert(valeurC == "de Trèfle");

    valeurC = casValeur(carte1);
    assert(valeurC == "8");
    valeurC = casValeur(carte2);
    assert(valeurC == "Roi");
    valeurC = casValeur(carte3);
    assert(valeurC == "Dame");
    valeurC = casValeur(carte4);
    assert(valeurC == "Valet");
    valeurC = casValeur(carte5);
    assert(valeurC == "As");
    valeurC = casValeur(carte6);
    assert(valeurC == "10");

    cout << "Test de Jeu.txt sans cin vérifié" << endl;

    cout << "Les tests pour les cin sont fait manuellement" << endl;

    delete carte1;
    delete carte2;
    delete carte3;
    delete carte4;
    delete carte5;
    delete carte6;
}

void JeuTxt::demo()
{
    paquet.demopaquet();
    executionJeuTxt();
}
