#include <iostream>
#include "JeuSdl.h"

void JeuSdl::draw(string dir, string &dirchange, SDL_Rect *selection, SDL_Rect *selection2, unsigned int &ch, unsigned int &item)
{

    if (!strcmp(dir.c_str(), "down"))
    {
        if (ch == 0)
        {
            if ((selection->y > 430) && (selection->y < 700))
            {
                selection->y = selection->y + 300;
                selection2->y = selection2->y + 300;
            }
            if ((selection->y >= 290) && (selection->y < 430))
            {
                selection->y = selection->y + 75;
                selection2->y = selection2->y + 75;
            }
        }
        if (ch == 1)
        {

            if ((selection->y < 840) && (selection->y > 620))
            {
                selection->h = 64;
                selection->w = 270;
                selection->x = 628;
                selection->y = 848;

                selection2->h = selection->h + 1;
                selection2->w = selection->w + 2;
                selection2->x = selection->x - 2;
                selection2->y = selection->y - 2;
            }
            else if ((selection->y < 550) && (selection->y > 470))
            {
                selection->y = 630;
                selection2->y = selection->y - 2;
            }
            else if ((selection->y < 550) && (selection->y > 400))
            {
                selection->y = 480;
                selection2->y = selection->y - 2;
            }
            else if ((selection->y < 420)) // nom
            {
                selection->y = 410;
                selection2->y = selection->y - 2;

                selection->x = 885;
                selection2->x = selection->x - 2;

                selection->w = selection->w - 90;
                selection2->w = selection->w + 2;
            }
        }
        if (ch == 3)
        {

            if ((selection->y < 800) && (selection->y > 560))
            {
                selection->y = selection->y + 230;
                selection->x = selection->x - 100;

                selection2->y = selection->y - 2;
                selection2->x = selection->x - 2;

                selection->w = selection->w - 14;
                selection->h = selection->h - 30;

                selection2->w = selection->w + 2;
                selection2->h = selection->h + 2;
            }
            else if ((selection->y < 560) && (selection->y > 430))
            {
                selection->y = selection->y + 110;

                selection2->y = selection->y - 2;
            }
            else if ((selection->y < 430) && (selection->y > 380))
            {
                selection->y = selection->y + 110;

                selection2->y = selection->y - 2;
            }
            else if ((selection->y < 320) && (selection->y > 230))
            {
                selection->y = selection->y + 50;

                selection2->y = selection->y - 2;
            }

            else if ((selection->y < 340) && (selection->y > 300))
            {
                selection->y = selection->y + 60;

                selection2->y = selection->y - 2;
                selection->w = selection->w + 2;
                selection->h = selection->h + 50;
                selection2->w = selection->w + 2;
                selection2->h = selection->h + 2;
            }
        }
        if ((ch == 7))
        {
            float ratioLong = 1080 / (float)hauteur;
            float ratioLarg = 1920 / (float)largeur;

            selection->h = 60 * ratioLarg;
            selection->w = 253 * ratioLong;
            selection->x = largeur - 1055;
            selection->y = hauteur - 390;

            selection2->h = selection->h + 1;
            selection2->w = selection->w + 2;
            selection2->x = selection->x - 2;
            selection2->y = selection->y - 2;
        }
        if ((ch == 6) && (selection->y < 500))
        {
            if ((!menulance) && (!reglelance))
            {
                initrect(selection, selection2, 6, item);
            }
            else if (menulance)
            {
                if (selection->y < 10)
                {
                    selection->h = 63;
                    selection->w = 230;
                    selection->x = 1535;
                    selection->y = 112;

                    selection2->h = selection->h + 1;
                    selection2->w = selection->w + 2;
                    selection2->x = selection->x - 2;
                    selection2->y = selection->y - 2;
                }
                else if ((selection->y < 120) && (selection->y > 30))
                {
                    selection->y = selection->y + 78;
                    selection2->y = selection->y - 2;
                }
                else if ((selection->y < 250) && (selection->y > 120))
                {
                    selection->y = selection->y + 78;
                    selection2->y = selection->y - 2;
                }
            }
        }
    }

    if (!strcmp(dir.c_str(), "up"))
    {
        if (ch == 0)
        {
            if ((selection->y < 600) && (selection->y > 320))
            {
                selection->y = selection->y - 75;
                selection2->y = selection2->y - 75;
            }
            if (selection->y > 600) // salut
            {
                selection->y = selection->y - 300;
                selection2->y = selection2->y - 300;
            }
        }
        if (ch == 1)
        {

            if ((selection->y < 420) && (selection->y > 390)) // nom
            {
                selection->y = 347;
                selection2->y = selection->y - 2;

                selection->x = 837;
                selection2->x = selection->x - 2;

                selection->w = selection->w + 90;
                selection2->w = selection->w + 2;
            }
            if ((selection->y < 550) && (selection->y > 420))
            {
                selection->y = 410;
                selection2->y = selection->y - 2;
            }
            if ((selection->y < 840) && (selection->y > 620))
            {
                selection->y = 480;
                selection2->y = selection->y - 2;
            }

            if (selection->y > 840)
            {
                selection->x = 885;
                selection->y = 630;
                selection->w = selection->w - 80;
                selection->h = selection->h - 20;

                selection2->x = selection->x - 2;
                selection2->y = selection->y - 2;
                selection2->w = selection->w + 2;
                selection2->h = selection->h + 2;
            }
        }
        if (ch == 3)
        {

            if (selection->y > 800)
            {
                selection->y = selection->y - 230;
                selection->x = selection->x + 100;

                selection2->y = selection->y - 2;
                selection2->x = selection->x - 2;

                selection->w = selection->w + 14;
                selection->h = selection->h + 30;

                selection2->w = selection->w + 2;
                selection2->h = selection->h + 2;
            }
            else if ((selection->y < 800) && (selection->y > 560))
            {
                selection->y = selection->y - 110;

                selection2->y = selection->y - 2;
            }
            else if ((selection->y < 560) && (selection->y > 430))
            {
                selection->y = selection->y - 110;

                selection2->y = selection->y - 2;
            }
            else if ((selection->y < 430) && (selection->y > 360))
            {
                selection->y = selection->y - 60;

                selection2->y = selection->y - 2;

                selection->w = selection->w - 2;
                selection->h = selection->h - 50;
                selection2->w = selection->w + 2;
                selection2->h = selection->h + 2;
            }
            else if ((selection->y < 360) && (selection->y > 300))
            {
                selection->y = selection->y - 50;

                selection2->y = selection->y - 2;
            }
        }
        if ((ch == 7) && (selection->y < 1800))
        {
            selection->h = 74;
            selection->w = 340;
            selection->x = 756;
            selection->y = 436;

            selection2->h = selection->h + 1;
            selection2->w = selection->w + 2;
            selection2->x = selection->x - 2;
            selection2->y = selection->y - 2;
        }
        if ((ch == 6) && (selection->y > 630))
        {
            if ((!menulance) && (!reglelance))
            {
                selection->x = 1568;
                selection->y = 0;
                selection->w = 162;
                selection->h = 80;

                selection2->x = selection->x - 2;
                selection2->y = selection->y - 2;
                selection2->w = selection->w + 2;
                selection2->h = selection->h + 2;
            }
        }
        else if ((ch == 6) && (selection->y < 630) && (selection->y > 150))
        {
            if (menulance)
            {
                if ((selection->y < 120) && (selection->y > 30))
                {
                    selection->y = selection->y - 78;
                    selection2->y = selection->y - 2;
                }
                else if ((selection->y < 250) && (selection->y > 120))
                {
                    selection->y = selection->y - 78;
                    selection2->y = selection->y - 2;
                }
                else if ((selection->y < 300) && (selection->y > 250))
                {
                    selection->y = selection->y - 78;
                    selection2->y = selection->y - 2;
                }
            }
        }
    }
    if (!strcmp(dir.c_str(), "right"))
    {
        if (ch == 0)
        {
            selection->x = 1792;
            selection->y = 13;
            selection->w = 45;
            selection->h = 45;
            selection2->x = 1790;
            selection2->y = 13;
            selection2->w = 47;
            selection2->h = 47;
        }

        if (ch == 1)
        {
            if (selection->y > 800)
            {
                selection->x = 920;
                selection2->x = selection->x - 2;
            }
            if (selection->y < 350) // Nom
            {
                item = 1;
                dirchange = "right";
                estSaisieNom = false;
            }
            if ((selection->y > 350) && (selection->y < 420)) // Difficulté
            {
                item = 2;
                dirchange = "right";
                estSaisieNiveau = false;
            }
            if ((selection->y > 420) && (selection->y < 500)) // Paquets
            {

                item = 3;
                dirchange = "right";
                estSaisiePaquet = false;
            }
            if ((selection->y > 500) && (selection->y < 650)) // Jetons
            {
                item = 4;
                dirchange = "right";
                estSaisieJet = false;
            }
        }
        if (ch == 6)
        {
            if (selection->y > 30)
            {
                if (assuranceachoisir)
                {
                    if ((selection->y < 700) && (selection->x < 1240))
                    {
                        selection->x = selection->x + 260;
                        selection2->x = selection->x - 2;
                    }
                }
                else
                {
                    if ((selection->x > 1000) && (selection->x < 1300))
                    {
                        selection->x = selection->x + 320;
                        selection2->x = selection->x - 2;
                    }
                    if ((selection->x > 250) && (selection->x < 900))
                    {
                        selection->x = 1015;
                        selection2->x = selection->x - 2;
                    }
                    if ((selection->x < 250) && (selection->x < 1000))
                    {
                        selection->x = selection->x + 320;
                        selection2->x = selection->x - 2;
                    }
                }
            }
            else if (selection->x < 1500)
            {
                selection->x = 1568;
                selection->y = 0;
                selection->w = 162;
                selection->h = 80;

                selection2->x = selection->x - 2;
                selection2->y = selection->y - 2;
                selection2->w = selection->w + 2;
                selection2->h = selection->h + 2;
            }
        }
        if (ch == 4)
        {
            if ((selection->x < 1300))
            {
                selection->x = selection->x + 261;
                selection2->x = selection->x - 2;
            }
        }
        if (ch == 7)
        {
            if (selection->y >= 436)
            {
                estMise = false;
                dirchange = "right";
            }
        }
        if (ch == 3)
        {
            if ((selection->y < 800) && (selection->y > 560))
            {
                item = 5;
                estSaisieDesignJetons = false;
                dirchange = "right";
                jetonsdessine = false;
            }
            else if ((selection->y < 560) && (selection->y > 430))
            {
                item = 4;
                estSaisieDesignTable = false;
                dirchange = "right";
                tabledessine = false;
            }
            else if ((selection->y < 430) && (selection->y > 380))
            {
                item = 3;
                estSaisieDesignCartes = false;
                dirchange = "right";
            }
            else if ((selection->y < 320) && (selection->y > 230))
            {
                item = 1;
                estSaisieCouper = false;
                dirchange = "right";
            }

            else if ((selection->y < 340) && (selection->y > 300))
            {
                item = 2;
                estSaisieVolume = false;
                dirchange = "right";
            }
        }
    }
    if (!strcmp(dir.c_str(), "left"))
    {

        if (ch == 0)
        {
            selection->x = 755;
            selection->y = 290;
            selection->h = 64;
            selection->w = 308;
            selection2->h = 65;
            selection2->w = 310;
            selection2->x = 753;
            selection2->y = 288;
        }
        if (ch == 1)
        {
            if (selection->y > 800)
            {
                selection->x = 628;
                selection2->x = selection->x - 2;
            }
            if (selection->y < 350) // Nom
            {
                item = 1;
                dirchange = "left";
                estSaisieNom = false;
            }
            if ((selection->y > 350) && (selection->y < 420)) // Difficulté
            {
                item = 2;
                dirchange = "left";
                estSaisieNiveau = false;
            }
            if ((selection->y > 420) && (selection->y < 500)) // Paquets
            {

                item = 3;
                dirchange = "left";
                estSaisiePaquet = false;
            }
            if ((selection->y > 500) && (selection->y < 650)) // Jetons
            {
                item = 4;
                dirchange = "left";
                estSaisieJet = false;
            }
        }

        if (ch == 6)
        {
            if (selection->y > 30)
            {
                if (assuranceachoisir)
                {
                    if ((selection->y < 700) && (selection->x > 1240))
                    {
                        selection->x = selection->x - 260;
                        selection2->x = selection->x - 2;
                    }
                }
                else
                {
                    if (selection->x > 1000)
                    {
                        selection->x = selection->x - 320;
                        selection2->x = selection->x - 2;
                    }

                    if ((selection->x > 500) && (selection->x < 800))
                    {
                        selection->x = selection->x - 175;
                        selection2->x = selection->x - 2;
                    }
                    if ((selection->x < 500) && (selection->x > 250))
                    {
                        selection->x = selection->x - 145;
                        selection2->x = selection->x - 2;
                    }
                }
            }
            else if (selection->x > 1500)
            {
                selection->x = 1480;
                selection->y = 0;
                selection->w = 80;
                selection->h = 80;

                selection2->x = selection->x - 2;
                selection2->y = selection->y - 2;
                selection2->w = selection->w + 2;
                selection2->h = selection->h + 2;
            }
        }

        if (ch == 7)
        {
            if (selection->y >= 436)
            {
                estMise = false;
                dirchange = "left";
            }
        }

        if (ch == 4)
        {
            if (selection->x > 300)
            {
                selection->x = selection->x - 261;
                selection2->x = selection->x - 2;
            }
        }
        if (ch == 3)
        {
            if ((selection->y < 800) && (selection->y > 560))
            {
                item = 5;
                estSaisieDesignJetons = false;
                dirchange = "left";
                jetonsdessine = false;
            }
            else if ((selection->y < 560) && (selection->y > 430))
            {
                item = 4;
                estSaisieDesignTable = false;
                dirchange = "left";
                tabledessine = false;
            }
            else if ((selection->y < 430) && (selection->y > 380))
            {
                item = 3;
                estSaisieDesignCartes = false;
                dirchange = "left";
            }
            else if ((selection->y < 320) && (selection->y > 230))
            {
                item = 1;
                estSaisieCouper = false;
                dirchange = "left";
            }

            else if ((selection->y < 340) && (selection->y > 300))
            {
                item = 2;
                estSaisieVolume = false;
                dirchange = "left";
            }
        }
    }
    if (!strcmp(dir.c_str(), "back"))
    {

        if ((ch == 1) || (ch == 2) || (ch == 3) || (ch == 4))
        {
            initrect(selection, selection2, 0, item);
            ch = 0;
        }
        if (ch == 6)
        {
            initrect(selection, selection2, 1, item);
            ch = 1;
        }
    }
}

unsigned int JeuSdl::choix(SDL_Rect *selection, SDL_Rect *selection2, unsigned int ch, unsigned int &item)
{
    if (ch == 0)
    {
        if (selection->y == 290) // Nouveau Jeu
        {
            initrect(selection, selection2, 1, item);
            SDL_RenderClear(renderer);
            return 1;
        }
        if (selection->y == 365) // load
        {
            initrect(selection, selection2, 2, item);
            SDL_RenderClear(renderer);
            return 2;
        }
        if (selection->y == 440) // options
        {
            initrect(selection, selection2, 3, item);
            SDL_RenderClear(renderer);
            return 3;
        }
        if (selection->y == 515) // Règles
        {
            initrect(selection, selection2, 4, item);
            SDL_RenderClear(renderer);
            return 4;
        }
        if ((selection->y > 520) || (selection->x > 1500)) // exit ou croix
        {
            SDL_RenderClear(renderer);
            return 5;
        }
    }
    else if (ch == 7)
    {

        SDL_RenderClear(renderer);
        if ((!estSaisieJet) || (!estSaisieNiveau) || (!estSaisieNom) || (!estSaisiePaquet))
        {
            initrect(selection, selection2, 1, item);
            return 1;
        }
        else
        {
            initrect(selection, selection2, 6, item);
            return 6;
        }
    }
    else if (ch == 1)
    {
        if ((selection->x > 900) && ((selection->y > 800)))
        {
            initrect(selection, selection2, 7, item);
            SDL_RenderClear(renderer);
            premierlancement = false;
            return 7;
        }
        if ((selection->x < 700) && ((selection->y > 800)))
        {
            initrect(selection, selection2, 0, item);
            SDL_RenderClear(renderer);
            return 0;
        }
    }

    else if (ch == 3)
    {
        if (selection->y > 800)
        {
            if (!menulance)
            {
                initrect(selection, selection2, 0, item);
                SDL_RenderClear(renderer);
                return 0;
            }
            if (menulance)
            {
                initrect(selection, selection2, 6, item);
                menulance = false;
                return 6;
            }
        }
    }
    else if (ch == 2)
    {
        initrect(selection, selection2, 0, item);
        return 0;
    }
}

void JeuSdl::inittexturetable()
{
    SDL_Surface *surftable;
    if (!tabledessine)
    {
        if (styleTable == "western")
        {
            surftable = SDL_LoadBMP("data/ImageWestern.bmp");
        }
        if (styleTable == "feerique")
        {
            surftable = SDL_LoadBMP("data/ImageFeerique.bmp");
        }
        if (styleTable == "normal")
        {
            surftable = SDL_LoadBMP("data/tableblackjack-jb.bmp");
        }
        TableSur = SDL_CreateTextureFromSurface(renderer, surftable);
        tabledessine = true;
    }
    if (!jetonsdessine)
    {
        if (styleJetons == "bleu")
        {
            surftable = SDL_LoadBMP("data/tableblackjack-jb.bmp");
        }
        if (styleJetons == "vert")
        {
            surftable = SDL_LoadBMP("data/tableblackjack-jve.bmp");
        }
        if (styleJetons == "violet")
        {
            surftable = SDL_LoadBMP("data/tableblackjack-jvi.bmp");
        }
        Table = SDL_CreateTextureFromSurface(renderer, surftable);
        jetonsdessine = true;
    }
}

void JeuSdl::actionCroupier()
{
    if (!Player.getDepassementCartes())
    {
        if (!strcmp(niv.c_str(), "normal"))
        {
            if (Croup.sommeValeurCartes() < 17)
            {
                Carte *carte = Deck.prendPremiereCarte();
                Croup.ajouterCarte(carte);
                SDL_Delay(1000);
            }
            else
            {
                Croup.setEstResteCartes(true);
            }
        }
        else if (!strcmp(niv.c_str(), "cauchemar"))
        {
            if (Croup.sommeValeurCartes() <= 10)
            {
                Carte *carte = Deck.prendPremiereCarte();
                Croup.ajouterCarte(carte);
                SDL_Delay(1000);
            }
            else if (Croup.sommeValeurCartes() < 18)
            {
                Carte *carte = Deck.prendPremiereCarte();
                string nouvelleV = to_string(rand() % 4 + (18 - Croup.sommeValeurCartes()));
                carte->setValeur(nouvelleV);
                Croup.ajouterCarte(carte);
                SDL_Delay(1000);
            }
            else if (Croup.sommeValeurCartes() >= 18)
            {
                Croup.setEstResteCartes(true);
            }
        }
    }
    else
    {
        Croup.setEstResteCartes(true);
    }
}

unsigned int JeuSdl::changeim(string dir, unsigned int item, SDL_Rect *locali, unsigned int ch)
{
    if (ch == 1)
    {
        if ((item == 1) && (!estSaisieNom)) // nom
        {
            string text = saisie();
            LocaliNom.h = locali->h;
            LocaliNom.w = text.size() * 25;
            LocaliNom.x = ((locali->x + (locali->x + text.size() * 25)) / 2) - ((text.size() * 25) / 2);
            LocaliNom.y = locali->y;
            int fontsize = 14;
            SDL_Color text_color = {0, 0, 0};

            Nomarendre = text;
            estSaisieNom = true;
            TTF_Font *font = TTF_OpenFont("data/ttf/arial.ttf", fontsize);
            SDL_Surface *textsurface = TTF_RenderText_Blended(font, text.c_str(), text_color);
            Nom = SDL_CreateTextureFromSurface(renderer, textsurface);
        }
        if ((item == 2) && (!estSaisieNiveau))
        {
            Niveauxloca.h = locali->h;
            Niveauxloca.w = locali->w;
            Niveauxloca.x = locali->x;
            Niveauxloca.y = locali->y;

            SDL_Surface *textsurface;
            if ((!strcmp(niv.c_str(), "cauchemar") && (!estSaisieNiveau)))
            {
                textsurface = SDL_LoadBMP("data/Menuavant/Normal.bmp");
                niv = "normal";
                estSaisieNiveau = true;
            }
            else if ((!strcmp(niv.c_str(), "normal")) && (!estSaisieNiveau))
            {
                textsurface = SDL_LoadBMP("data/Menuavant/Cauchemar.bmp");
                niv = "cauchemar";
                estSaisieNiveau = true;
            }
            Niveaux = SDL_CreateTextureFromSurface(renderer, textsurface);
        }
        if ((item == 3) && (!estSaisiePaquet))
        {

            Paqloca.h = locali->h;
            Paqloca.w = locali->w;
            Paqloca.x = locali->x;
            Paqloca.y = locali->y;

            SDL_Surface *textsurface;
            if ((!strcmp(dir.c_str(), "right")))
            {
                if ((nbrePaquet == 8) && (!estSaisiePaquet))
                {
                    textsurface = SDL_LoadBMP("data/Menuavant/1.bmp");
                    nbrePaquet = 1;
                    estSaisiePaquet = true;
                }

                if ((nbrePaquet == 1) && (!estSaisiePaquet))
                {
                    textsurface = SDL_LoadBMP("data/Menuavant/2.bmp");
                    nbrePaquet = 2;
                    estSaisiePaquet = true;
                }
                if ((nbrePaquet == 2) && (!estSaisiePaquet))
                {
                    textsurface = SDL_LoadBMP("data/Menuavant/3.bmp");
                    nbrePaquet = 3;
                    estSaisiePaquet = true;
                }
                if ((nbrePaquet == 3) && (!estSaisiePaquet))
                {
                    textsurface = SDL_LoadBMP("data/Menuavant/4.bmp");
                    nbrePaquet = 4;
                    estSaisiePaquet = true;
                }
                if ((nbrePaquet == 4) && (!estSaisiePaquet))
                {
                    textsurface = SDL_LoadBMP("data/Menuavant/5.bmp");
                    nbrePaquet = 5;
                    estSaisiePaquet = true;
                }
                if ((nbrePaquet == 5) && (!estSaisiePaquet))
                {
                    textsurface = SDL_LoadBMP("data/Menuavant/6.bmp");
                    nbrePaquet = 6;
                    estSaisiePaquet = true;
                }
                if ((nbrePaquet == 6) && (!estSaisiePaquet))
                {
                    textsurface = SDL_LoadBMP("data/Menuavant/7.bmp");
                    nbrePaquet = 7;
                    estSaisiePaquet = true;
                }
                if ((nbrePaquet == 7) && (!estSaisiePaquet))
                {
                    textsurface = SDL_LoadBMP("data/Menuavant/8.bmp");
                    nbrePaquet = 8;
                    estSaisiePaquet = true;
                }
            }
            else if ((!strcmp(dir.c_str(), "left")))
            {
                if ((nbrePaquet == 8) && (!estSaisiePaquet))
                {
                    textsurface = SDL_LoadBMP("data/Menuavant/7.bmp");
                    nbrePaquet = 7;
                    estSaisiePaquet = true;
                }

                else if ((nbrePaquet == 1) && (!estSaisiePaquet))
                {
                    textsurface = SDL_LoadBMP("data/Menuavant/8.bmp");
                    nbrePaquet = 8;
                    estSaisiePaquet = true;
                }
                else if ((nbrePaquet == 2) && (!estSaisiePaquet))
                {
                    textsurface = SDL_LoadBMP("data/Menuavant/1.bmp");
                    nbrePaquet = 1;
                    estSaisiePaquet = true;
                }
                else if ((nbrePaquet == 3) && (!estSaisiePaquet))
                {
                    textsurface = SDL_LoadBMP("data/Menuavant/2.bmp");
                    nbrePaquet = 2;
                    estSaisiePaquet = true;
                }
                else if ((nbrePaquet == 4) && (!estSaisiePaquet))
                {
                    textsurface = SDL_LoadBMP("data/Menuavant/3.bmp");
                    nbrePaquet = 3;
                    estSaisiePaquet = true;
                }
                else if ((nbrePaquet == 5) && (!estSaisiePaquet))
                {
                    textsurface = SDL_LoadBMP("data/Menuavant/4.bmp");
                    nbrePaquet = 4;
                    estSaisiePaquet = true;
                }
                else if ((nbrePaquet == 6) && (!estSaisiePaquet))
                {
                    textsurface = SDL_LoadBMP("data/Menuavant/5.bmp");
                    nbrePaquet = 5;
                    estSaisiePaquet = true;
                }
                else if ((nbrePaquet == 7) && (!estSaisiePaquet))
                {
                    textsurface = SDL_LoadBMP("data/Menuavant/6.bmp");
                    nbrePaquet = 6;
                    estSaisiePaquet = true;
                }
            }

            NbPaq = SDL_CreateTextureFromSurface(renderer, textsurface);
        }
        if ((item == 4) && (!estSaisieJet))
        {
            JetLoca.h = locali->h;
            JetLoca.w = locali->w;
            JetLoca.x = locali->x;
            JetLoca.y = locali->y;

            SDL_Surface *textsurface;
            if ((!strcmp(dir.c_str(), "right")))
            {
                if ((Jetons == 10000) && (!estSaisieJet))
                {
                    textsurface = SDL_LoadBMP("data/Menuavant/500.bmp");
                    Jetons = 500;
                    estSaisieJet = true;
                }
                if ((Jetons == 500) && (!estSaisieJet))
                {
                    textsurface = SDL_LoadBMP("data/Menuavant/1000.bmp");
                    Jetons = 1000;
                    estSaisieJet = true;
                }
                if ((Jetons == 1000) && (!estSaisieJet))
                {
                    textsurface = SDL_LoadBMP("data/Menuavant/2500.bmp");
                    Jetons = 2500;
                    estSaisieJet = true;
                }
                if ((Jetons == 2500) && (!estSaisieJet))
                {
                    textsurface = SDL_LoadBMP("data/Menuavant/5000.bmp");
                    Jetons = 5000;
                    estSaisieJet = true;
                }
                if ((Jetons == 5000) && (!estSaisieJet))
                {
                    textsurface = SDL_LoadBMP("data/Menuavant/7500.bmp");
                    Jetons = 7500;
                    estSaisieJet = true;
                }
                if ((Jetons == 7500) && (!estSaisieJet))
                {
                    textsurface = SDL_LoadBMP("data/Menuavant/10000.bmp");
                    Jetons = 10000;
                    estSaisieJet = true;
                }
            }
            if ((!strcmp(dir.c_str(), "left")))
            {
                if ((Jetons == 10000) && (!estSaisieJet))
                {
                    textsurface = SDL_LoadBMP("data/Menuavant/7500.bmp");
                    Jetons = 7500;
                    estSaisieJet = true;
                }
                else if ((Jetons == 500) && (!estSaisieJet))
                {
                    textsurface = SDL_LoadBMP("data/Menuavant/10000.bmp");
                    Jetons = 10000;
                    estSaisieJet = true;
                }
                else if ((Jetons == 1000) && (!estSaisieJet))
                {
                    textsurface = SDL_LoadBMP("data/Menuavant/500.bmp");
                    Jetons = 500;
                    estSaisieJet = true;
                }
                else if ((Jetons == 2500) && (!estSaisieJet))
                {
                    textsurface = SDL_LoadBMP("data/Menuavant/1000.bmp");
                    Jetons = 1000;
                    estSaisieJet = true;
                }
                else if ((Jetons == 5000) && (!estSaisieJet))
                {
                    textsurface = SDL_LoadBMP("data/Menuavant/2500.bmp");
                    Jetons = 2500;
                    estSaisieJet = true;
                }
                else if ((Jetons == 7500) && (!estSaisieJet))
                {
                    textsurface = SDL_LoadBMP("data/Menuavant/5000.bmp");
                    Jetons = 5000;
                    estSaisieJet = true;
                }
            }
            Jet = SDL_CreateTextureFromSurface(renderer, textsurface);
        }
    }

    if (ch == 7)
    {
        if (locali->y < 1200)
        {
            if (!premierlancement)
            {
                Player.setJetons(Jetons);
            }
            if (!test2)
            {
                MiseLoca.h = locali->h;
                MiseLoca.w = locali->w;
                MiseLoca.x = locali->x;
                MiseLoca.y = locali->y;
                test2 = true;
            }
            if (Player.getJetons() < 50)
            {
                SurMise = SDL_LoadBMP("data/Argentnecessaire.bmp");
                SDL_Texture *perdu = SDL_CreateTextureFromSurface(renderer, SurMise);
                SDL_RenderCopy(renderer, perdu, NULL, NULL);
                SDL_RenderPresent(renderer);
                SDL_Delay(3000);
                SDL_Quit();
            }

            if ((!strcmp(dir.c_str(), "right")))
            {
                if ((MiseEnCours == 2500) && (!estMise))
                {
                    SurMise = SDL_LoadBMP("data/Miseinitiale/50.bmp");
                    MiseEnCours = 50;
                    estMise = true;
                }

                if ((MiseEnCours == 50) && (!estMise) && (int(Player.getJetons()) - 100 >= 0))
                {
                    SurMise = SDL_LoadBMP("data/Miseinitiale/100.bmp");
                    MiseEnCours = 100;
                    estMise = true;
                }
                if ((MiseEnCours == 100) && (!estMise) && (int(Player.getJetons()) - 250 >= 0))
                {
                    SurMise = SDL_LoadBMP("data/Miseinitiale/250.bmp");
                    MiseEnCours = 250;
                    estMise = true;
                }

                if ((MiseEnCours == 250) && (!estMise) && (int(Player.getJetons()) - 500 >= 0))
                {
                    SurMise = SDL_LoadBMP("data/Miseinitiale/500.bmp");
                    MiseEnCours = 500;
                    estMise = true;
                }
                if ((MiseEnCours == 500) && (!estMise) && (int(Player.getJetons()) - 750 >= 0))
                {
                    SurMise = SDL_LoadBMP("data/Miseinitiale/750.bmp");
                    MiseEnCours = 750;
                    estMise = true;
                }
                if ((MiseEnCours == 750) && (!estMise) && (int(Player.getJetons()) - 1000 >= 0))
                {
                    SurMise = SDL_LoadBMP("data/Miseinitiale/1000.bmp");
                    MiseEnCours = 1000;
                    estMise = true;
                }
                if ((MiseEnCours == 1000) && (!estMise) && (int(Player.getJetons()) - 1500 >= 0))
                {
                    SurMise = SDL_LoadBMP("data/Miseinitiale/1500.bmp");
                    MiseEnCours = 1500;
                    estMise = true;
                }
                if ((MiseEnCours == 1500) && (!estMise) && (int(Player.getJetons()) - 2000 >= 0))
                {
                    SurMise = SDL_LoadBMP("data/Miseinitiale/2000.bmp");
                    MiseEnCours = 2000;
                    estMise = true;
                }
                if ((MiseEnCours == 2000) && (!estMise) && (int(Player.getJetons()) - 2500 >= 0))
                {
                    SurMise = SDL_LoadBMP("data/Miseinitiale/2500.bmp");
                    MiseEnCours = 2500;
                    estMise = true;
                }
            }
            else if ((!strcmp(dir.c_str(), "left")))
            {
                if ((MiseEnCours == 2500) && (!estMise) && (int(Player.getJetons()) - 2000 >= 0))
                {
                    SurMise = SDL_LoadBMP("data/Miseinitiale/2000.bmp");
                    MiseEnCours = 2000;
                    estMise = true;
                }

                else if ((MiseEnCours == 50) && (!estMise) && (int(Player.getJetons()) - 2500 >= 0))
                {
                    SurMise = SDL_LoadBMP("data/Miseinitiale/2500.bmp");
                    MiseEnCours = 2500;
                    estMise = true;
                }
                else if ((MiseEnCours == 100) && (!estMise) && (int(Player.getJetons()) - 50 >= 0))
                {
                    SurMise = SDL_LoadBMP("data/Miseinitiale/50.bmp");
                    MiseEnCours = 50;
                    estMise = true;
                }

                else if ((MiseEnCours == 250) && (!estMise) && (int(Player.getJetons()) - 100 >= 0))
                {
                    SurMise = SDL_LoadBMP("data/Miseinitiale/100.bmp");
                    MiseEnCours = 100;
                    estMise = true;
                }
                if ((MiseEnCours == 500) && (!estMise) && (int(Player.getJetons()) - 250 >= 0))
                {
                    SurMise = SDL_LoadBMP("data/Miseinitiale/250.bmp");
                    MiseEnCours = 250;
                    estMise = true;
                }
                else if ((MiseEnCours == 750) && (!estMise) && (int(Player.getJetons()) - 500 >= 0))
                {
                    SurMise = SDL_LoadBMP("data/Miseinitiale/500.bmp");
                    MiseEnCours = 500;
                    estMise = true;
                }
                else if ((MiseEnCours == 1000) && (!estMise) && (int(Player.getJetons()) - 750 >= 0))
                {
                    SurMise = SDL_LoadBMP("data/Miseinitiale/750.bmp");
                    MiseEnCours = 750;
                    estMise = true;
                }
                else if ((MiseEnCours == 1500) && (!estMise) && (int(Player.getJetons()) - 1000 >= 0))
                {
                    SurMise = SDL_LoadBMP("data/Miseinitiale/1000.bmp");
                    MiseEnCours = 1000;
                    estMise = true;
                }
                else if ((MiseEnCours == 2000) && (!estMise) && (int(Player.getJetons()) - 1500 >= 0))
                {
                    SurMise = SDL_LoadBMP("data/Miseinitiale/1500.bmp");
                    MiseEnCours = 1500;
                    estMise = true;
                }
            }
            TextMise = SDL_CreateTextureFromSurface(renderer, SurMise);
        }
    }
    if (ch == 3)
    {
        if ((item == 1) && (!estSaisieCouper))
        {
            LocaCut.h = locali->h;
            LocaCut.w = locali->w;
            LocaCut.x = locali->x;
            LocaCut.y = locali->y;

            SDL_Surface *textmute;
            if ((!mute) && (!estSaisieCouper))
            {
                textmute = SDL_LoadBMP("data/Options/Oui.bmp");
                mute = true;
                estSaisieCouper = true;
            }
            else if ((mute) && (!estSaisieCouper))
            {
                textmute = SDL_LoadBMP("data/Options/Non.bmp");
                mute = false;
                estSaisieCouper = true;
            }
            Couper = SDL_CreateTextureFromSurface(renderer, textmute);
        }
        if ((item == 2) && (!estSaisieVolume))
        {
            LocaVol.h = locali->h;
            LocaVol.w = locali->w;
            LocaVol.x = locali->x;
            LocaVol.y = locali->y;

            SDL_Surface *textVol;
            if ((!strcmp(dir.c_str(), "right")))
            {
                if ((!strcmp(nivVolume.c_str(), "faible")) && (!estSaisieVolume))
                {
                    textVol = SDL_LoadBMP("data/Options/Moyen.bmp");
                    nivVolume = "moyen";
                    estSaisieVolume = true;
                }
                else if ((!strcmp(nivVolume.c_str(), "moyen")) && (!estSaisieVolume))
                {
                    textVol = SDL_LoadBMP("data/Options/Fort.bmp");
                    nivVolume = "fort";
                    estSaisieVolume = true;
                }
                else if ((!strcmp(nivVolume.c_str(), "fort")) && (!estSaisieVolume))
                {
                    textVol = SDL_LoadBMP("data/Options/Faible.bmp");
                    nivVolume = "faible";
                    estSaisieVolume = true;
                }
            }
            else if ((!strcmp(dir.c_str(), "left")))
            {
                if ((!strcmp(nivVolume.c_str(), "fort")) && (!estSaisieVolume))
                {
                    textVol = SDL_LoadBMP("data/Options/Moyen.bmp");
                    nivVolume = "moyen";
                    estSaisieVolume = true;
                }
                else if ((!strcmp(nivVolume.c_str(), "faible")) && (!estSaisieVolume))
                {
                    textVol = SDL_LoadBMP("data/Options/Fort.bmp");
                    nivVolume = "fort";
                    estSaisieVolume = true;
                }
                else if ((!strcmp(nivVolume.c_str(), "moyen")) && (!estSaisieVolume))
                {
                    textVol = SDL_LoadBMP("data/Options/Faible.bmp");
                    nivVolume = "faible";
                    estSaisieVolume = true;
                }
            }
            ecoutecommence = false;
            Volume = SDL_CreateTextureFromSurface(renderer, textVol);
        }
        if ((item == 3) && (!estSaisieDesignCartes))
        {
            LocaDesCartes.h = locali->h;
            LocaDesCartes.w = locali->w;
            LocaDesCartes.x = locali->x;
            LocaDesCartes.y = locali->y;

            SDL_Surface *textdesign;
            if ((!strcmp(dir.c_str(), "right")))
            {
                if ((!strcmp(styleCartes.c_str(), "western")) && (!estSaisieDesignCartes))
                {
                    textdesign = SDL_LoadBMP("data/Options/Feerique.bmp");
                    styleCartes = "feerique";
                    estSaisieDesignCartes = true;
                }
                else if ((!strcmp(styleCartes.c_str(), "feerique")) && (!estSaisieDesignCartes))
                {
                    textdesign = SDL_LoadBMP("data/Options/Normal.bmp");
                    styleCartes = "normal";
                    estSaisieDesignCartes = true;
                }
                else if ((!strcmp(styleCartes.c_str(), "normal")) && (!estSaisieDesignCartes))
                {
                    textdesign = SDL_LoadBMP("data/Options/Western.bmp");
                    styleCartes = "western";
                    estSaisieDesignCartes = true;
                }
            }
            else if ((!strcmp(dir.c_str(), "left")))
            {
                if ((!strcmp(styleCartes.c_str(), "normal")) && (!estSaisieDesignCartes))
                {
                    textdesign = SDL_LoadBMP("data/Options/Feerique.bmp");
                    styleCartes = "feerique";
                    estSaisieDesignCartes = true;
                }
                else if ((!strcmp(styleCartes.c_str(), "western")) && (!estSaisieDesignCartes))
                {
                    textdesign = SDL_LoadBMP("data/Options/Normal.bmp");
                    styleCartes = "normal";
                    estSaisieDesignCartes = true;
                }
                else if ((!strcmp(styleCartes.c_str(), "feerique")) && (!estSaisieDesignCartes))
                {
                    textdesign = SDL_LoadBMP("data/Options/Western.bmp");
                    styleCartes = "western";
                    estSaisieDesignCartes = true;
                }
            }
            DesignCartes = SDL_CreateTextureFromSurface(renderer, textdesign);
        }
        if ((item == 4) && (!estSaisieDesignTable))
        {
            LocaDesTable.h = locali->h;
            LocaDesTable.w = locali->w;
            LocaDesTable.x = locali->x;
            LocaDesTable.y = locali->y;

            SDL_Surface *textdesignT;
            if ((!strcmp(dir.c_str(), "right")))
            {
                if ((!strcmp(styleTable.c_str(), "western")) && (!estSaisieDesignTable))
                {
                    textdesignT = SDL_LoadBMP("data/Options/Feerique.bmp");
                    styleTable = "feerique";
                    estSaisieDesignTable = true;
                }
                else if ((!strcmp(styleTable.c_str(), "feerique")) && (!estSaisieDesignTable))
                {
                    textdesignT = SDL_LoadBMP("data/Options/Normal.bmp");
                    styleTable = "normal";
                    estSaisieDesignTable = true;
                }
                else if ((!strcmp(styleTable.c_str(), "normal")) && (!estSaisieDesignTable))
                {
                    textdesignT = SDL_LoadBMP("data/Options/Western.bmp");
                    styleTable = "western";
                    estSaisieDesignTable = true;
                }
            }

            else if ((!strcmp(dir.c_str(), "left")))
            {
                if ((!strcmp(styleTable.c_str(), "normal")) && (!estSaisieDesignTable))
                {
                    textdesignT = SDL_LoadBMP("data/Options/Feerique.bmp");
                    styleTable = "feerique";
                    estSaisieDesignTable = true;
                }
                else if ((!strcmp(styleTable.c_str(), "western")) && (!estSaisieDesignTable))
                {
                    textdesignT = SDL_LoadBMP("data/Options/Normal.bmp");
                    styleTable = "normal";
                    estSaisieDesignTable = true;
                }
                else if ((!strcmp(styleTable.c_str(), "feerique")) && (!estSaisieDesignTable))
                {
                    textdesignT = SDL_LoadBMP("data/Options/Western.bmp");
                    styleTable = "western";
                    estSaisieDesignTable = true;
                }
            }

            DesignTable = SDL_CreateTextureFromSurface(renderer, textdesignT);
        }
        if ((item == 5) && (!estSaisieDesignJetons))
        {
            LocaDesJetons.h = locali->h;
            LocaDesJetons.w = locali->w;
            LocaDesJetons.x = locali->x;
            LocaDesJetons.y = locali->y;

            SDL_Surface *textdesignJ;
            if ((!strcmp(dir.c_str(), "right")))
            {
                if ((!strcmp(styleJetons.c_str(), "bleu")) && (!estSaisieDesignJetons))
                {
                    textdesignJ = SDL_LoadBMP("data/Options/JetonVert.bmp");
                    styleJetons = "vert";
                    estSaisieDesignJetons = true;
                }
                else if ((!strcmp(styleJetons.c_str(), "vert")) && (!estSaisieDesignJetons))
                {
                    textdesignJ = SDL_LoadBMP("data/Options/JetonViolet.bmp");
                    styleJetons = "violet";
                    estSaisieDesignJetons = true;
                }
                else if ((!strcmp(styleJetons.c_str(), "violet")) && (!estSaisieDesignJetons))
                {
                    textdesignJ = SDL_LoadBMP("data/Options/JetonBleu.bmp");
                    styleJetons = "bleu";
                    estSaisieDesignJetons = true;
                }
            }
            else if ((!strcmp(dir.c_str(), "left")))
            {
                if ((!strcmp(styleJetons.c_str(), "violet")) && (!estSaisieDesignJetons))
                {
                    textdesignJ = SDL_LoadBMP("data/Options/JetonVert.bmp");
                    styleJetons = "vert";
                    estSaisieDesignJetons = true;
                }
                else if ((!strcmp(styleJetons.c_str(), "bleu")) && (!estSaisieDesignJetons))
                {
                    textdesignJ = SDL_LoadBMP("data/Options/JetonViolet.bmp");
                    styleJetons = "violet";
                    estSaisieDesignJetons = true;
                }
                else if ((!strcmp(styleJetons.c_str(), "vert")) && (!estSaisieDesignJetons))
                {
                    textdesignJ = SDL_LoadBMP("data/Options/JetonBleu.bmp");
                    styleJetons = "bleu";
                    estSaisieDesignJetons = true;
                }
            }
            DesignJetons = SDL_CreateTextureFromSurface(renderer, textdesignJ);
        }
    }
}

string JeuSdl::saisie()
{
    string saisie = "";
    SDL_Event events;
    bool quit2 = false;
    while (!quit2)
    {
        while (SDL_PollEvent(&events))
        {
            if (events.type == SDL_KEYDOWN)
            {
                if (events.key.keysym.scancode == SDL_SCANCODE_RETURN)
                {
                    return (saisie);
                }
                else if (saisie.length() < 10)
                {
                    const char *c = SDL_GetScancodeName(events.key.keysym.scancode);
                    SDL_Scancode verif = SDL_GetScancodeFromName(c);
                    if ((verif >= 4) && (verif <= 29))
                    {
                        saisie += c;
                    }
                }
            }
        }
    }
}

void JeuSdl::initrect(SDL_Rect *selection, SDL_Rect *selection2, unsigned int ch, unsigned int &item)
{
    item = 0;
    if (ch == 0)
    {
        selection->h = 64;
        selection->w = 308;
        selection->x = 755;
        selection->y = 290;

        selection2->h = 65;
        selection2->w = 310;
        selection2->x = 753;
        selection2->y = 288;
    }
    if (ch == 1)
    {
        /* selection->h = 64;
        selection->w = 270;
        selection->x = 628;
        selection->y = 848;*/

        selection->y = 347;

        selection->x = 837;

        selection->w = 280;

        selection->h = 44;

        selection2->h = selection->h + 1;
        selection2->w = selection->w + 2;
        selection2->x = selection->x - 2;
        selection2->y = selection->y - 2;
    }
    if (ch == 2)
    {
        selection->h = 65;
        selection->w = 272;
        selection->x = 812;
        selection->y = 750;

        selection2->h = selection->h + 1;
        selection2->w = selection->w + 2;
        selection2->x = selection->x - 2;
        selection2->y = selection->y - 2;
    }
    if (ch == 3)
    {
        selection->h = 44;
        selection->w = 282;
        selection->x = 877;
        selection->y = 288;

        selection2->h = selection->h + 1;
        selection2->w = selection->w + 2;
        selection2->x = selection->x - 2;
        selection2->y = selection->y - 2;
    }
    if (ch == 4)
    {
        selection->h = 84;
        selection->w = 230;
        selection->x = 290;
        selection->y = 738;

        selection2->h = selection->h + 1;
        selection2->w = selection->w + 2;
        selection2->x = selection->x - 2;
        selection2->y = selection->y - 2;
    }
    if (ch == 6)
    {
        selection->h = 90;
        selection->w = 310;
        selection->x = 200;
        selection->y = 855;

        selection2->h = selection->h + 1;
        selection2->w = selection->w + 2;
        selection2->x = selection->x - 2;
        selection2->y = selection->y - 2;
    }

    if (ch == 7)
    {
        float ratioLong = 1080 / (float)hauteur;
        float ratioLarg = 1920 / (float)largeur;

        /*
        selection->h = 60 * ratioLarg;

        selection->w = 253 * ratioLong;
        selection->x = largeur - 1055;
        selection->y = hauteur - 390;
        
*/
        selection->h = 72 * ratioLarg;
        selection->w = 320 * ratioLong;
        selection->x = largeur - 1092;
        selection->y = hauteur - 580;
        selection2->h = selection->h + 1;
        selection2->w = selection->w + 2;
        selection2->x = selection->x - 2;
        selection2->y = selection->y - 2;
    }
}

void JeuSdl::InitJeuSdl(string comp)
{
    Player.initialisationJoueur(Nomarendre, nbrePaquet);
    Deck.initialisationPaquet(nbrePaquet);
    if (!strcmp(comp.c_str(), "demo"))
    {
        Deck.demopaquet();
    }
    Player.setJetons(Jetons);
}

void JeuSdl::choixJoueur(SDL_Rect *selection, SDL_Rect *selection2, unsigned int &item, unsigned int &ch)
{
    SDL_Surface *SurfImpossible = SDL_LoadBMP("data/ActionImpossible.bmp");
    ActionImpossible = SDL_CreateTextureFromSurface(renderer, SurfImpossible);
    locaImpossible.h = 200;
    locaImpossible.w = 600;
    locaImpossible.x = 1200;
    locaImpossible.y = 400;
    if (reglelance)
    {
        reglelance = false;
        cout << "fin regle" << endl;
        initrect(selection, selection2, 6, item);
    }
    else if (selection->y > 550)
    {
        if (assuranceachoisir)
        {
            if (selection->x > 1240)
            {
                cout << "assurance pas prise" << endl;
                assuranceachoisir = false;
                initrect(selection, selection2, 6, item);
                decisionprise = true;
            }
            else
            {
                cout << "assurance prise" << endl;
                Player.prendreAssurance();
                assuranceachoisir = false;
                initrect(selection, selection2, 6, item);
                decisionprise = true;
            }
        }
        else
        {
            if (!actionfaite)
            {
                if ((Player.getNbrCartesSplit() == 0) || ((Player.getNbrCartesSplit() >= 1) && (tour % 2 == 0)))
                {
                    if (selection->x > 1200) // doubler
                    {
                        if ((Player.verificationDoubler()) && (Player.verificationPiocher()) && (!Player.getEstResteCartes()))
                        {
                            cout << "je double" << endl;
                            Player.doubler();
                            Player.ajouterCarte(Deck.prendPremiereCarte());
                            impossible = false;
                            Player.setEstResteCartes(true);
                        }
                        else
                        {
                            impossible = true;
                        }
                        actionfaite = true;
                    }

                    else if ((selection->x > 900) && (selection->x < 1100)) // tirer
                    {
                        if ((Player.verificationPiocher()) && (!Player.getEstResteCartes()))
                        {
                            cout << "je tire" << endl;
                            Player.ajouterCarte(Deck.prendPremiereCarte());
                            impossible = false;
                            SDL_Delay(1000);
                        }
                        else
                        {
                            impossible = true;
                        }
                        actionfaite = true; // En parler au prof
                    }
                    else if ((selection->x < 600) && (selection->x > 250)) // rester
                    {
                        cout << "je reste" << endl;
                        Player.setEstResteCartes(true);
                        impossible = false;
                        actionfaite = true;
                    }
                    else
                    {
                        if ((Player.verificationSplitter()) && (!Player.getEstResteCartes()))
                        {
                            cout << "je splitte" << endl;
                            Player.splitter();
                            impossible = false;
                            tour = 1;
                        }
                        else
                        {
                            impossible = true;
                        }
                        actionfaite = true;
                    }
                    tour++;
                }

                if ((Player.getNbrCartesSplit() >= 1) && (tour % 2 == 1) && (!actionfaite))
                {
                    if (selection->x > 1200) // doubler
                    {
                        if ((Player.verificationDoublerSplit()) && (Player.verificationPiocherSplit()) && (!Player.getEstResteCartesSplit()))
                        {
                            cout << "je double" << endl;
                            Player.doublerSplit();
                            Player.ajouterCarteSplit(Deck.prendPremiereCarte());
                            Player.setEstResteCartesSplit(true);
                            impossible = false;
                        }
                        actionfaite = true;
                    }

                    else if ((selection->x > 900) && (selection->x < 1100)) // tirer
                    {
                        if ((Player.verificationPiocherSplit()) && (!Player.getEstResteCartesSplit()))
                        {
                            cout << "je tire split" << endl;
                            Player.ajouterCarteSplit(Deck.prendPremiereCarte());
                            impossible = false;
                            SDL_Delay(1000);
                        }
                        else
                        {
                            impossible = true;
                        }
                        actionfaite = true; // En parler au prof
                    }
                    else if ((selection->x < 600) && (selection->x > 250)) // rester
                    {
                        cout << "je reste" << endl;
                        Player.setEstResteCartesSplit(true);
                        impossible = false;
                        actionfaite = true;
                    }
                    else
                    {
                        cout << "tu n'es pas au bon endroit" << endl;
                    }
                    tour++;
                }
            }
        }
    }
    else
    {
        SDL_Surface *menur;
        if ((!menulance) && (!reglelance))
        {
            if (selection->x > 1500)
            {
                cout << "lancement menu" << endl;
                menulance = true;
                menur = SDL_LoadBMP("data/tableblackoption.bmp");
            }
            else
            {
                cout << "lancement règles" << endl;
                reglelance = true;
                menur = SDL_LoadBMP("data/regles.bmp");
                initrect(selection, selection2, 2, item);
            }
            menu = SDL_CreateTextureFromSurface(renderer, menur);
        }
        else if (menulance)
        {

            if (selection->y < 120)
            {
                menulance = false;
                initrect(selection, selection2, 6, item);
            }
            else if ((selection->y < 220) && (selection->y > 120))
            {
                cout << "options" << endl;
                ch = 3;
                initrect(selection, selection2, 3, item);
            }
            else
            {
                cout << "quitter" << endl;
                menur = SDL_LoadBMP("data/QuitterAventure.bmp");
                menu = SDL_CreateTextureFromSurface(renderer, menur);
                SDL_RenderCopy(renderer, menu, NULL, NULL);
                SDL_RenderPresent(renderer);
                SDL_Delay(3000);
                SDL_Quit();
            }
        }
    }
}

void JeuSdl::renderassurance(SDL_Rect *selection, SDL_Rect *selection2)
{
    if (Player.verificationAssurance(Croup.getElementTab(0))) //(Croup.getNbrCartes() == 1) && ((Croup.sommeValeurCartes() == 10) || (Croup.sommeValeurCartes() == 11)) && (!Player.getBoolAssurance() && ))
    {
        SDL_Rect LocaAssurance;
        LocaAssurance.x = 1200;
        LocaAssurance.y = 500;
        LocaAssurance.w = 500;
        LocaAssurance.h = 200;

        if (selection->y > 670)
        {
            selection->x = 1235;
            selection->y = 610;
            selection->w = 173;
            selection->h = 92;
        }

        selection2->x = selection->x - 1;
        selection2->y = selection->y - 1;
        selection2->w = selection->w + 1;
        selection2->h = selection->h + 1; //

        SDL_Surface *assur = SDL_LoadBMP("data/PrendreAssurance.bmp");
        SDL_Texture *Assurance = SDL_CreateTextureFromSurface(renderer, assur);
        SDL_RenderCopy(renderer, Assurance, NULL, &LocaAssurance);
        assuranceachoisir = true;
    }
}

void JeuSdl::affichagescore()
{
    SDL_Surface *CarreSomme = SDL_LoadBMP("data/sommeCartes.bmp");
    ScoreDesDeux = SDL_CreateTextureFromSurface(renderer, CarreSomme);

    int fontsize = 14;
    SDL_Color text_color = {255, 255, 255};
    string text;
    text = to_string(Player.sommeValeurCartes());
    TTF_Font *font = TTF_OpenFont("data/ttf/arial.ttf", fontsize);
    SDL_Surface *textsurfaceJoueur = TTF_RenderText_Blended(font, text.c_str(), text_color);
    ScoreJoueur = SDL_CreateTextureFromSurface(renderer, textsurfaceJoueur);
    locaScoreJoueur.x = 230;
    locaScoreJoueur.y = 265;
    if (Player.sommeValeurCartes() < 10)
    {
        locaScoreJoueur.w = 20;
    }
    else
    {
        locaScoreJoueur.w = 40;
    }
    locaScoreJoueur.h = 30;

    text = "";
    if (Player.getNbrCartesSplit() >= 1)
    {
        text = text + to_string(Player.sommeValeurCartesSplit());
    }
    textsurfaceJoueur = TTF_RenderText_Blended(font, text.c_str(), text_color);
    ScoreJoueurSplit = SDL_CreateTextureFromSurface(renderer, textsurfaceJoueur);
    locaScoreJoueurSplit.x = 230;
    locaScoreJoueurSplit.y = 310;
    if ((Player.getNbrCartesSplit() >= 1) && (Player.sommeValeurCartesSplit() < 10))
    {
        locaScoreJoueurSplit.w = 20;
    }
    else
    {
        locaScoreJoueurSplit.w = 40;
    }
    locaScoreJoueurSplit.h = 30;

    text = to_string(Croup.sommeValeurCartes());
    textsurfaceJoueur = TTF_RenderText_Blended(font, text.c_str(), text_color);
    ScoreCroupier = SDL_CreateTextureFromSurface(renderer, textsurfaceJoueur);
    locaScoreCroupier.x = 270;
    locaScoreCroupier.y = 165;
    if (Croup.sommeValeurCartes() < 10)
    {
        locaScoreCroupier.w = 20;
    }
    else
    {
        locaScoreCroupier.w = 40;
    }
    locaScoreCroupier.h = 30;
}

void JeuSdl::rendercarte()
{
    SDL_Rect placement;
    placement.h = 150;
    placement.w = 70;
    placement.x = 650;
    placement.y = 475;

    SDL_Surface *car;
    SDL_Texture *texcar;
    //if (actionfaite)
    // {
    for (unsigned i = 0; i < Player.getNbrCartes(); i++)
    {
        string doc = "data/Cartes/";
        bool place = false;

        placement.x = placement.x + 100;

        if (Player.getElementTab(i)->getCouleur() == "C")
        {
            doc.append("Carreau/");
        }
        if (Player.getElementTab(i)->getCouleur() == "T")
        {
            doc.append("Trefle/");
        }
        if (Player.getElementTab(i)->getCouleur() == "P")
        {
            doc.append("Pique/");
        }
        if (Player.getElementTab(i)->getCouleur() == "H")
        {
            doc.append("Coeur/");
        }

        doc.append(Player.getElementTab(i)->getValeur());

        if (Player.getElementTab(i)->getCouleur() == "C")
        {
            doc.append("carreau.bmp");
        }
        if (Player.getElementTab(i)->getCouleur() == "T")
        {
            doc.append("trefle.bmp");
        }
        if (Player.getElementTab(i)->getCouleur() == "P")
        {
            doc.append("pique.bmp");
        }
        if (Player.getElementTab(i)->getCouleur() == "H")
        {
            doc.append("coeur.bmp");
        }
        car = SDL_LoadBMP(doc.c_str());
        texcar = SDL_CreateTextureFromSurface(renderer, car);
        if (!place)
        {
            SDL_RenderCopy(renderer, texcar, NULL, &placement);
        }
    }

    placement.x = 650;
    placement.y = placement.y - 300;

    for (unsigned i = 0; i < Croup.getNbrCartes(); i++)
    {
        string doc = "data/Cartes/";
        bool place = false;

        placement.x = placement.x + 100;

        if (Croup.getElementTab(i)->getCouleur() == "C")
        {
            doc.append("Carreau/");
        }
        if (Croup.getElementTab(i)->getCouleur() == "T")
        {
            doc.append("Trefle/");
        }
        if (Croup.getElementTab(i)->getCouleur() == "P")
        {
            doc.append("Pique/");
        }
        if (Croup.getElementTab(i)->getCouleur() == "H")
        {
            doc.append("Coeur/");
        }

        doc.append(Croup.getElementTab(i)->getValeur());

        if (Croup.getElementTab(i)->getCouleur() == "C")
        {
            doc.append("carreau.bmp");
        }
        if (Croup.getElementTab(i)->getCouleur() == "T")
        {
            doc.append("trefle.bmp");
        }
        if (Croup.getElementTab(i)->getCouleur() == "P")
        {
            doc.append("pique.bmp");
        }
        if (Croup.getElementTab(i)->getCouleur() == "H")
        {
            doc.append("coeur.bmp");
        }
        car = SDL_LoadBMP(doc.c_str());
        texcar = SDL_CreateTextureFromSurface(renderer, car);
        if (!place)
        {
            SDL_RenderCopy(renderer, texcar, NULL, &placement);
        }
    }
    placement.x = 650;
    placement.y = placement.y + 150;
    for (unsigned i = 0; i < Player.getNbrCartesSplit(); i++)
    {
        string doc = "data/Cartes/";
        bool place = false;

        placement.x = placement.x + 100;

        if (Player.getElementTabSplit(i)->getCouleur() == "C")
        {
            doc.append("Carreau/");
        }
        if (Player.getElementTabSplit(i)->getCouleur() == "T")
        {
            doc.append("Trefle/");
        }
        if (Player.getElementTabSplit(i)->getCouleur() == "P")
        {
            doc.append("Pique/");
        }
        if (Player.getElementTabSplit(i)->getCouleur() == "H")
        {
            doc.append("Coeur/");
        }

        doc.append(Player.getElementTabSplit(i)->getValeur());

        if (Player.getElementTabSplit(i)->getCouleur() == "C")
        {
            doc.append("carreau.bmp");
        }
        if (Player.getElementTabSplit(i)->getCouleur() == "T")
        {
            doc.append("trefle.bmp");
        }
        if (Player.getElementTabSplit(i)->getCouleur() == "P")
        {
            doc.append("pique.bmp");
        }
        if (Player.getElementTabSplit(i)->getCouleur() == "H")
        {
            doc.append("coeur.bmp");
        }
        car = SDL_LoadBMP(doc.c_str());
        texcar = SDL_CreateTextureFromSurface(renderer, car);
        if (!place)
        {
            SDL_RenderCopy(renderer, texcar, NULL, &placement);
        }
    }

    if (Player.calculDepassement())
    {
        Player.setDepassementCartes(true);
    }
    if (Player.calculDepassementSplit())
    {
        Player.setDepassementCartesSplit(true);
    }
    if (Croup.calculDepassement())
    {
        Croup.setDepassementCartes(true);
    }
}

void JeuSdl::affichagejetons()
{
    int fontsize = 14;
    SDL_Color text_color = {255, 255, 255};
    string text = to_string(JetonsActuels);
    TTF_Font *font = TTF_OpenFont("data/ttf/arial.ttf", fontsize);
    SDL_Surface *textsurfacejetons = TTF_RenderText_Blended(font, text.c_str(), text_color);
    AfficheJetons = SDL_CreateTextureFromSurface(renderer, textsurfacejetons);
    LocaAfficheJetons.x = 860;
    LocaAfficheJetons.y = 905;
    LocaAfficheJetons.w = 60;
    LocaAfficheJetons.h = 50;
}

void JeuSdl::gainMancheSDL()
{
    SDL_Event events;
    Player.gainManche(Croup.sommeValeurCartes(), Croup.getNbrCartes());
    SDL_Surface *surfResult;
    SDL_Texture *textResulat;

    if (Player.getResultat() == 1)
    {
        surfResult = SDL_LoadBMP("data/Gain/PerdantInitial.bmp");
    }
    if (Player.getResultat() == 2)
    {
        surfResult = SDL_LoadBMP("data/Gain/EgaliteInitial.bmp");
    }
    if (Player.getResultat() == 3)
    {
        surfResult = SDL_LoadBMP("data/Gain/GagnantInitial.bmp");
    }
    textResulat = SDL_CreateTextureFromSurface(renderer, surfResult);

    SDL_Rect MiseAvant;
    MiseAvant.h = 50;
    MiseAvant.w = 60;
    MiseAvant.x = 920;
    MiseAvant.y = 490;
    int fontsize = 14;
    SDL_Color text_color = {255, 255, 255};

    if (Player.getResultat() == 1)
    {
        JetonsActuels = JetonsActuels + Player.getJetonsMises();
    }
    if (Player.getResultat() == 3)
    {
        JetonsActuels = JetonsActuels - Player.getJetonsMises();
    }
    if (Player.getResultatSplit() == 1)
    {
        JetonsActuels = JetonsActuels + Player.getJetonsMisesSplit();
    }
    if (Player.getResultatSplit() == 3)
    {
        JetonsActuels = JetonsActuels - Player.getJetonsMisesSplit();
    }

    string text = to_string(JetonsActuels);
    TTF_Font *font = TTF_OpenFont("data/ttf/arial.ttf", fontsize);
    SDL_Surface *textsurfacemise = TTF_RenderText_Blended(font, text.c_str(), text_color);
    SDL_Texture *Misebefore = SDL_CreateTextureFromSurface(renderer, textsurfacemise);

    SDL_RenderCopy(renderer, textResulat, NULL, NULL);
    SDL_RenderCopy(renderer, Misebefore, NULL, &MiseAvant);

    MiseAvant.y = MiseAvant.y + 50;
    text = to_string(Player.getJetons());
    font = TTF_OpenFont("data/ttf/arial.ttf", fontsize);
    textsurfacemise = TTF_RenderText_Blended(font, text.c_str(), text_color);
    Misebefore = SDL_CreateTextureFromSurface(renderer, textsurfacemise);

    SDL_RenderCopy(renderer, Misebefore, NULL, &MiseAvant);

    SDL_RenderPresent(renderer);
    SDL_Delay(3000);

    if (Player.getResultatSplit() != 0)
    {
        if (Player.getResultatSplit() == 1)
        {
            surfResult = SDL_LoadBMP("data/Gain/PerdantSplitte.bmp");
        }
        if (Player.getResultatSplit() == 2)
        {
            surfResult = SDL_LoadBMP("data/Gain/EgaliteSplitte.bmp");
        }
        if (Player.getResultatSplit() == 3)
        {
            surfResult = SDL_LoadBMP("data/Gain/GagnantSplitte.bmp");
        }
        textResulat = SDL_CreateTextureFromSurface(renderer, surfResult);
        SDL_RenderCopy(renderer, textResulat, NULL, NULL);

        MiseAvant.h = 50;
        MiseAvant.w = 60;
        MiseAvant.x = 920;
        MiseAvant.y = 490;

        string text = to_string(JetonsActuels);
        TTF_Font *font = TTF_OpenFont("data/ttf/arial.ttf", fontsize);
        SDL_Surface *textsurfacemise = TTF_RenderText_Blended(font, text.c_str(), text_color);
        SDL_Texture *Misebefore = SDL_CreateTextureFromSurface(renderer, textsurfacemise);

        SDL_RenderCopy(renderer, Misebefore, NULL, &MiseAvant);

        MiseAvant.y = MiseAvant.y + 50;
        text = to_string(Player.getJetons());
        font = TTF_OpenFont("data/ttf/arial.ttf", fontsize);
        textsurfacemise = TTF_RenderText_Blended(font, text.c_str(), text_color);
        Misebefore = SDL_CreateTextureFromSurface(renderer, textsurfacemise);

        SDL_RenderCopy(renderer, Misebefore, NULL, &MiseAvant);

        SDL_RenderPresent(renderer);
        SDL_Delay(3000);
    }

    if (Player.getBoolAssurance())
    {
        if (Player.getAssurance() == 1)
        {
            surfResult = SDL_LoadBMP("data/AssuranceSertARien.bmp");
        }
        if (Player.getAssurance() == 2)
        {
            surfResult = SDL_LoadBMP("data/AssuranceGagne.bmp");
        }
        textResulat = SDL_CreateTextureFromSurface(renderer, surfResult);
        SDL_RenderCopy(renderer, textResulat, NULL, NULL);

        MiseAvant.h = 50;
        MiseAvant.w = 60;
        MiseAvant.x = 920;
        MiseAvant.y = 490;

        string text = to_string(JetonsActuels);
        TTF_Font *font = TTF_OpenFont("data/ttf/arial.ttf", fontsize);
        SDL_Surface *textsurfacemise = TTF_RenderText_Blended(font, text.c_str(), text_color);
        SDL_Texture *Misebefore = SDL_CreateTextureFromSurface(renderer, textsurfacemise);

        SDL_RenderCopy(renderer, Misebefore, NULL, &MiseAvant);

        MiseAvant.y = MiseAvant.y + 50;
        text = to_string(Player.getJetons());
        font = TTF_OpenFont("data/ttf/arial.ttf", fontsize);
        textsurfacemise = TTF_RenderText_Blended(font, text.c_str(), text_color);
        Misebefore = SDL_CreateTextureFromSurface(renderer, textsurfacemise);

        SDL_RenderCopy(renderer, Misebefore, NULL, &MiseAvant);

        SDL_RenderPresent(renderer);
        SDL_Delay(3000);
    }
}

void JeuSdl::currentmise()
{
    string text;
    if (!premierlancement)
    {
        text = to_string(int(Jetons));
    }
    else
    {
        text = to_string(int(Player.getJetons()));
    }

    LocaCurJet.h = 50;
    LocaCurJet.w = 60;
    LocaCurJet.x = 920;
    LocaCurJet.y = 540;
    int fontsize = 14;
    SDL_Color text_color = {255, 255, 255};

    estSaisieJetonsActuels = true;
    TTF_Font *font = TTF_OpenFont("data/ttf/arial.ttf", fontsize);
    SDL_Surface *textsurfacemise = TTF_RenderText_Blended(font, text.c_str(), text_color);
    CurrentJetons = SDL_CreateTextureFromSurface(renderer, textsurfacemise);
}

void JeuSdl::renderscore()
{
    SDL_RenderCopy(renderer, ScoreDesDeux, NULL, NULL);
    SDL_RenderCopy(renderer, ScoreJoueur, NULL, &locaScoreJoueur);
    SDL_RenderCopy(renderer, ScoreJoueurSplit, NULL, &locaScoreJoueurSplit);
    SDL_RenderCopy(renderer, ScoreCroupier, NULL, &locaScoreCroupier);
}

void JeuSdl::renderpaquet()
{
    SDL_Surface *lookpaquet;

    if (styleCartes == "normal")
    {
        lookpaquet = SDL_LoadBMP("data/Cartes/PaquetNormal.bmp");
    }
    if (styleCartes == "western")
    {
        lookpaquet = SDL_LoadBMP("data/Cartes/PaquetWestern.bmp");
    }
    if (styleCartes == "feerique")
    {
        lookpaquet = SDL_LoadBMP("data/Cartes/PaquetFeerique.bmp");
    }
    PaquetCartes = SDL_CreateTextureFromSurface(renderer, lookpaquet);

    LocaPaquet.x = 1200;
    LocaPaquet.y = 250;
    LocaPaquet.w = 200;
    LocaPaquet.h = 100;

    SDL_RenderCopy(renderer, PaquetCartes, NULL, &LocaPaquet);
}

void JeuSdl::afficher(string dem)
{
    unsigned int ch = 0;
    niv = "normal";
    nbrePaquet = 8;
    //bool test = false;
    Jetons = 10000;
    nivVolume = "moyen";
    styleCartes = "normal";
    styleTable = "normal";
    styleJetons = "bleu";
    unsigned int item, positionavant;
    string dirchange;
    item = 0;
    MiseEnCours = 2500;
    SDL_Rect selection, selection2;
    initrect(&selection, &selection2, ch, item);
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Init(SDL_INIT_AUDIO);
    SDL_AudioSpec wavSpec;
    Uint32 wavLength;
    Uint8 *wavBuffer;
    SDL_AudioDeviceID deviceId;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        cout << "error initializing SDL: %s\n"
             << SDL_GetError() << endl;
    }
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }
    if (TTF_Init() != 0)
    {
        cout << "Erreur lors de l'initialisation de la SDL_ttf : " << TTF_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
        SDL_Quit();
        exit(1);
    }
    bool quit = false;
    window = SDL_CreateWindow("Image", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1848, 1016, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    if (window == NULL)
    {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    SDL_Event events;
    renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_Surface *imagemenu = SDL_LoadBMP("data/menu.bmp");
    SDL_Texture *texturemenu = SDL_CreateTextureFromSurface(renderer, imagemenu);

    SDL_Surface *imagetable = SDL_LoadBMP("data/tableblackjack-jb.bmp");
    Table = SDL_CreateTextureFromSurface(renderer, imagetable);

    SDL_Surface *imageoption = SDL_LoadBMP("data/option.bmp");
    SDL_Texture *textureoption = SDL_CreateTextureFromSurface(renderer, imageoption);

    SDL_Surface *imageoption2 = SDL_LoadBMP("data/Options/Options.bmp");
    SDL_Texture *textureoption2 = SDL_CreateTextureFromSurface(renderer, imageoption2);

    SDL_Surface *imageregle = SDL_LoadBMP("data/regles.bmp");
    SDL_Texture *textureregle = SDL_CreateTextureFromSurface(renderer, imageregle);

    SDL_Surface *imagemenuavant = SDL_LoadBMP("data/Menuavant/menuavantjeu.bmp");
    SDL_Texture *texturemenuavant = SDL_CreateTextureFromSurface(renderer, imagemenuavant);

    SDL_Surface *imagebonus = SDL_LoadBMP("data/journalier.bmp");
    SDL_Texture *texturebonus = SDL_CreateTextureFromSurface(renderer, imagebonus);

    SDL_Surface *imagemise = SDL_LoadBMP("data/Miseinitiale/MiseInitiale.bmp");
    SDL_Texture *texturemise = SDL_CreateTextureFromSurface(renderer, imagemise);
    bool cartepremiere = false;
    while (!quit)
    {
        SDL_GetWindowSize(window, &largeur, &hauteur);
        // SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        bool jeufini = false;

        // Utiliser Librairie chrono pour voir le temps entre 2 évenements et forcer le prochain evenement si le jeu est bloqué
        if (compteur > 4)
        {
            SDL_PushEvent(&events);
            compteur = 1.0;
        }
        auto start = std::chrono::high_resolution_clock::now();
        while (SDL_PollEvent(&events))
        {
            temps = true;
            if (ch != 6)
            {
                if (events.type == SDL_QUIT)
                    quit = true;
                else if (events.type == SDL_KEYDOWN)
                {
                    switch (events.key.keysym.scancode)
                    {
                    case SDL_SCANCODE_ESCAPE:
                        quit = true;
                        break;
                    case SDL_SCANCODE_UP:
                        draw("up", dirchange, &selection, &selection2, ch, item);
                        break;
                    case SDL_SCANCODE_DOWN:
                        draw("down", dirchange, &selection, &selection2, ch, item);
                        break;
                    case SDL_SCANCODE_RETURN:
                        ch = choix(&selection, &selection2, ch, item);
                        break;
                    case SDL_SCANCODE_RIGHT:
                        draw("right", dirchange, &selection, &selection2, ch, item);
                        break;
                    case SDL_SCANCODE_LEFT:
                        draw("left", dirchange, &selection, &selection2, ch, item);
                        break;
                    case SDL_SCANCODE_BACKSPACE:
                        draw("back", dirchange, &selection, &selection2, ch, item);
                        break;
                    default:
                        break;
                    }
                }

                if (ch == 0)
                {
                    SDL_RenderCopy(renderer, texturemenu, NULL, NULL);
                }
                if (ch == 1)
                {
                    SDL_RenderCopy(renderer, texturemenuavant, NULL, NULL);
                }

                if (ch == 3)
                {
                    SDL_RenderCopy(renderer, textureoption2, NULL, NULL);
                    if (estSaisieCouper)
                    {
                        SDL_RenderCopy(renderer, Couper, NULL, &LocaCut);
                    }
                    if (estSaisieVolume)
                    {
                        SDL_RenderCopy(renderer, Volume, NULL, &LocaVol);
                    }
                    if (estSaisieDesignCartes)
                    {
                        SDL_RenderCopy(renderer, DesignCartes, NULL, &LocaDesCartes);
                    }
                    if (estSaisieDesignTable)
                    {
                        SDL_RenderCopy(renderer, DesignTable, NULL, &LocaDesTable);
                    }
                    if (estSaisieDesignJetons)
                    {
                        SDL_RenderCopy(renderer, DesignJetons, NULL, &LocaDesJetons);
                    }
                }

                if (ch == 2)
                {
                    SDL_RenderCopy(renderer, textureregle, NULL, NULL);
                }

                if (ch == 4)
                {
                    SDL_RenderCopy(renderer, texturebonus, NULL, NULL);
                }
                if (ch == 7)
                {
                    currentmise();
                }

                int stop = changeim(dirchange, item, &selection, ch);

                if ((estSaisieNom) && (ch == 1))
                {
                    SDL_RenderCopy(renderer, Nom, NULL, &LocaliNom);
                }

                if ((estSaisieNiveau) && (ch == 1))
                {

                    SDL_RenderCopy(renderer, Niveaux, NULL, &Niveauxloca);
                }

                if ((estSaisiePaquet) && (ch == 1))
                {

                    SDL_RenderCopy(renderer, NbPaq, NULL, &Paqloca);
                }
                if ((estSaisieJet) && (ch == 1))
                {
                    SDL_RenderCopy(renderer, Jet, NULL, &JetLoca);
                }
                if (ch == 7)
                {

                    SDL_RenderCopy(renderer, texturemise, NULL, NULL);
                }
                if ((ch == 7) && (estMise))
                {
                    SDL_RenderCopy(renderer, TextMise, NULL, &MiseLoca);
                }
                if ((ch == 7) && (estSaisieJetonsActuels))
                {
                    SDL_RenderCopy(renderer, CurrentJetons, NULL, &LocaCurJet);
                }
                SDL_RenderDrawRect(renderer, &selection);
                SDL_RenderDrawRect(renderer, &selection2);
            }
            else if (ch == 6)
            {
                if (!mute) //
                {
                    if (!ecoutecommence)
                    {
                        SDL_ClearQueuedAudio(deviceId);
                        if (!strcmp(nivVolume.c_str(), "moyen"))
                        {
                            if (!strcmp(niv.c_str(), "cauchemar"))
                            {
                                SDL_LoadWAV("data/Musique/Cauchemar.wav", &wavSpec, &wavBuffer, &wavLength);
                            }
                            if (!strcmp(niv.c_str(), "normal"))
                            {
                                SDL_LoadWAV("data/Musique/Normal.wav", &wavSpec, &wavBuffer, &wavLength);
                            }
                        }
                        else if (!strcmp(nivVolume.c_str(), "faible"))
                        {
                            SDL_LoadWAV("data/Musique/CauchemarFaible.wav", &wavSpec, &wavBuffer, &wavLength);
                            if (!strcmp(niv.c_str(), "cauchemar"))
                            {
                                SDL_LoadWAV("data/Musique/CauchemarFaible.wav", &wavSpec, &wavBuffer, &wavLength);
                            }
                            if (!strcmp(niv.c_str(), "normal"))
                            {
                                SDL_LoadWAV("data/Musique/NormalFaible.wav", &wavSpec, &wavBuffer, &wavLength);
                            }
                        }
                        else if (!strcmp(nivVolume.c_str(), "fort"))
                        {
                            SDL_LoadWAV("data/Musique/CauchemarFort.wav", &wavSpec, &wavBuffer, &wavLength);
                            if (!strcmp(niv.c_str(), "cauchemar"))
                            {
                                SDL_LoadWAV("data/Musique/CauchemarFort.wav", &wavSpec, &wavBuffer, &wavLength);
                            }
                            if (!strcmp(niv.c_str(), "normal"))
                            {
                                SDL_LoadWAV("data/Musique/NormalFort.wav", &wavSpec, &wavBuffer, &wavLength);
                            }
                        }
                        deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, SDL_AUDIO_ALLOW_ANY_CHANGE);
                        int success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
                        SDL_PauseAudioDevice(deviceId, 0);
                        ecoutecommence = true;
                    }
                }
                else if (mute)
                {
                    SDL_PauseAudioDevice(deviceId, 1);
                    ecoutecommence = false;
                }
                if ((!tabledessine) || (!jetonsdessine))
                {
                    inittexturetable();
                }

                if (!jeufini)
                {
                    affichagejetons();
                    if (!premierlancement)
                    {
                        InitJeuSdl(dem);
                        premierlancement = true;
                    }

                    if (!cartepremiere)
                    {
                        Player.ajouterCarte(Deck.prendPremiereCarte());
                        SDL_Delay(1000);
                        Croup.ajouterCarte(Deck.prendPremiereCarte());
                        Player.setJetonsMises(MiseEnCours);
                        Player.setJetons(Player.getJetons() - Player.getJetonsMises());
                        JetonsActuels = Player.getJetons();
                        cartepremiere = true;
                    }

                    if (events.type == SDL_QUIT)
                        quit = true;
                    else if ((events.type == SDL_KEYDOWN) && (events.key.repeat == 0))
                    {
                        switch (events.key.keysym.scancode)
                        {
                        case SDL_SCANCODE_ESCAPE:
                            quit = true;
                            break;
                        case SDL_SCANCODE_UP:
                            draw("up", dirchange, &selection, &selection2, ch, item);
                            break;
                        case SDL_SCANCODE_DOWN:
                            draw("down", dirchange, &selection, &selection2, ch, item);
                            break;
                        case SDL_SCANCODE_RETURN:
                            if ((!Player.getDepassementCartes() && !Player.getEstResteCartes()) || (!Player.getDepassementCartesSplit() && !Player.getEstResteCartesSplit() && (Player.getNbrCartesSplit() > 0)))
                            {
                                choixJoueur(&selection, &selection2, item, ch);
                            }
                            actionfaite = false;
                            break;
                        case SDL_SCANCODE_RIGHT:
                            draw("right", dirchange, &selection, &selection2, ch, item);
                            break;
                        case SDL_SCANCODE_LEFT:
                            draw("left", dirchange, &selection, &selection2, ch, item);
                            break;
                        default:
                            break;
                        }
                    }
                    affichagescore();
                    if (((Player.getDepassementCartes()) || (Player.getEstResteCartes())) && ((Player.getDepassementCartesSplit()) || (Player.getEstResteCartesSplit()) || (Player.getNbrCartesSplit() == 0)) && (!Croup.getDepassementCartes()) && (!Croup.getEstResteCartes()))
                    {
                        cout << "croupier" << endl;
                        actionCroupier();
                    }
                }
                SDL_RenderCopy(renderer, Table, NULL, NULL);
                if (((!strcmp(styleTable.c_str(), "feerique") || (!strcmp(styleTable.c_str(), "western")))))
                {
                    SDL_RenderCopy(renderer, TableSur, NULL, NULL);
                }
                SDL_RenderCopy(renderer, AfficheJetons, NULL, &LocaAfficheJetons);
                if (impossible)
                {
                    SDL_RenderCopy(renderer, ActionImpossible, NULL, &locaImpossible);
                }
                rendercarte();

                renderpaquet();
                if (!decisionprise)
                {
                    renderassurance(&selection, &selection2);
                }
                if ((menulance) || (reglelance))
                {
                    SDL_RenderCopy(renderer, menu, NULL, NULL);
                }
                SDL_RenderDrawRect(renderer, &selection);
                SDL_RenderDrawRect(renderer, &selection2);
                renderscore();
                SDL_RenderPresent(renderer);

                if (((Player.getDepassementCartes()) || (Player.getEstResteCartes())) && ((Player.getDepassementCartesSplit()) || (Player.getEstResteCartesSplit()) || (Player.getNbrCartesSplit() == 0)) && ((Croup.getDepassementCartes()) || (Croup.getEstResteCartes())))
                {
                    SDL_Delay(500);
                    gainMancheSDL();
                    SDL_RenderPresent(renderer);
                    SDL_Delay(500);
                    Player.finManche();
                    Croup.finManche();
                    cartepremiere = false;
                    decisionprise = false;
                    ch = 7;
                    MiseEnCours = 50;
                    initrect(&selection, &selection2, 7, item);
                }
            }
            // Render the rect to the screen
            SDL_RenderPresent(renderer);
            if (ch == 5)
            {
                SDL_Quit();
            }
        }
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        if (!temps)
        {
            compteur = compteur + elapsed.count() * 4;
        }
        else
        {
            compteur = 1.0;
        }
        temps = false;
    }

    SDL_DestroyRenderer(renderer);

    // SDL_DestroyTexture(texture);
    SDL_DestroyWindow(window);

    SDL_CloseAudioDevice(deviceId);

    //SDL_FreeWAV(wavBuffer);
    cout << "fini" << endl;
    IMG_Quit();
    SDL_Quit();
}
