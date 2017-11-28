#include "puluc.h"
#define HAUTEUR 5
#define LARGEUR 11
#define TAILLEMAX 100

int main()
{
    textbackground(LIGHTGRAY);
    textcolor (BLACK);

    int capturej1 = 0;  // pions mis hors jeu par le joueur 2
    int capturej2 = 0; // pions mis hors jeu par le joueur 1
    int i = 0;
    int j = 0;
    int i_final = 0;
    int j_final = 0;
    int deplacement = 0;
    int fin = 0;
    char plateau [HAUTEUR][LARGEUR];
    char nomjoueur1[TAILLEMAX];
    char nomjoueur2[TAILLEMAX];
    int verification = 0;
    int verification2 = 0;
    int peut_bouger = 0;

    printf ("test");
    clrscr();



    // affichage plateau de jeu et saisie des noms des joueurs


    printf ("________________Bienvenu sur le jeu Puluc de Camille et Florian_________________\n\n\n");


    printf ("entrer le nom du joueur 1 \n");
    scanf ("%s", nomjoueur1);
    printf ("entrer le nom du joueur 2 \n");
    scanf ("%s", nomjoueur2);

    clrscr();

    for (i = 0; i < HAUTEUR; i ++)
    {
        for (j = 0; j < LARGEUR; j ++)
        {
            plateau [i][j] = NULL;
        }
    }


    for (i = 0; i < HAUTEUR; i ++)
    {
        plateau [i][0] = 'V';
        plateau [i][10] = 'R';
    }



    printf ("  0   1   2   3   4   5   6   7   8   9   10\n");
    for (i = 0; i < HAUTEUR; i ++)
    {
        for (j = 0; j < LARGEUR; j ++)
        {
            textcolor (BLACK);
            printf ("|");

            if (plateau [i][j] == 'V')
            {
                textcolor (GREEN);
            }

            else if (plateau [i][j] == 'R')
            {
                textcolor (LIGHTRED);
            }

            else
            {
                textcolor (BLACK);
            }

            printf (" %c ", plateau [i][j]);
        }
        textcolor (BLACK);
        printf ("|  %d\n", i);
    }




    // commencement du jeu


    do
    {
        // debut tour joueur 1

        peut_bouger = 0;
        printf ("\nau tour de %s :\n", nomjoueur1);
        deplacement = lancement ();

        for (i = 0; i < HAUTEUR; i ++)
        {
            for (j = 0; j < LARGEUR; j ++)
            {
                if ((plateau [i][j] == 'V') && ((plateau [i][j + deplacement] == NULL) ||(plateau [i][j + deplacement] == 'R')))
                {
                    peut_bouger ++;
                    printf ("deplacement trouve : ligne %d colonne %d\n", i, j);
                }
            }
        }

        if (peut_bouger >= 1)
        {
            do
            {
                printf ("donc vous pouvez avancer de %d cases \nquel pion souhaitez vous bouger entrer la ligne puis la colonne voulue\n", deplacement);
                verification = scanf ("%d", &i);
                verification2 = scanf ("%d", &j);

                if ((verification == 0)|| (verification2 == 0))
                {
                    printf("ERREUR: Votre saisie est invalide ! Veuillez refaire votre choix.\n");
                    fflush(stdin);
                }
            }while (((i < 0)|| (j < 0))&& (plateau [i][j] != 'R') && (plateau [i][j] != NULL));

            i_final = ver_dep_i (deplacement , i);
            j_final = ver_dep_j1 (deplacement , j);
            plateau [i_final][j_final] = plateau [i][j];
            plateau [i][j] = NULL;
        }

                // passage prisonniers
        if (plateau [i_final][j_final] == 'R')
        {
            printf ("pion adverse capture par %s\n", nomjoueur1);

        }

        if (plateau [j_final] == 10)
        {
            printf ("pion hors jeu\n");
        }



        clrscr();

        // affichage nouvelle version du plateau
        printf ("  0   1   2   3   4   5   6   7   8   9   10\n");
        for (i = 0; i < HAUTEUR; i ++)
        {
            for (j = 0; j < LARGEUR; j ++)
            {
                textcolor (BLACK);
                printf ("|");

                if (plateau [i][j] == 'V')
                {
                    textcolor (GREEN);
                }

                else if (plateau [i][j] == 'R')
                {
                    textcolor (LIGHTRED);
                }

                else
                {
                    textcolor (BLACK);
                }

                printf (" %c ", plateau [i][j]);
            }
            textcolor (BLACK);
            printf ("|  %d\n", i);
        }

        if (capturej2 != 0)
        {
            printf ("%s a %d pions mis hors jeu par %s\n", nomjoueur1, capturej1, nomjoueur2);
        }


        // fin tour joueur 1 debut tour joueur 2


        peut_bouger = 0;
        deplacement = lancement ();

        printf ("\nau tour de %s:\n", nomjoueur2);

        for (i = 0; i < HAUTEUR; i ++)
        {
            for (j = 0; j < LARGEUR; j ++)
            {
                if ((plateau [i][j] == 'R') && ((plateau [i][j - deplacement] == NULL) ||(plateau [i][j - deplacement] == 'V')))
                {
                    peut_bouger ++;
                    printf ("deplacement trouve : ligne %d colonne %d\n", i, j);
                }
            }
        }

        if (peut_bouger >= 1)
        {
            do
            {
                printf ("donc vous pouvez avancer de %d cases \nquel pion souhaitez vous bouger entrer la ligne puis la colonne voulue\n", deplacement);
                verification = scanf ("%d", &i);
                verification2 = scanf ("%d", &j);

                if ((verification == 0)|| (verification2 == 0))
                {
                    printf("ERREUR: Votre saisie est invalide ! Veuillez refaire votre choix.\n");
                    fflush(stdin);
                }
            }while (((i < 0) || (j < 0))&& (plateau [i][j] != 'V')&& (plateau [i][j] != NULL));


            i_final = ver_dep_i (deplacement , i);
            j_final = ver_dep_j2(deplacement , i);
            plateau [i_final][j_final] = plateau [i][j];
            plateau [i][j] = NULL;

        }
        // passage prisonniers
        if (plateau [i_final][j_final] == 'R')
        {
            printf ("pion adverse capture par %s\n", nomjoueur2);

        }

        if (plateau [j_final] == 10)
        {
            printf ("pion hors jeu\n");
        }



        clrscr();

        // affichage du nouveau plateau
        printf ("  0   1   2   3   4   5   6   7   8   9   10\n");
        for (i = 0; i < HAUTEUR; i ++)
        {
            for (j = 0; j < LARGEUR; j ++)
            {
                textcolor (BLACK);
                printf ("|");

                if (plateau [i][j] == 'V')
                {
                    textcolor (GREEN);
                }

                else if (plateau [i][j] == 'R')
                {
                    textcolor (LIGHTRED);
                }

                else
                {
                    textcolor (BLACK);
                }

                printf (" %c ", plateau [i][j]);
            }
            textcolor (BLACK);
            printf ("|  %d\n", i);
        }




        if (capturej2 != 0)
        {
            printf ("%s a %d pions mis hors jeu par %s\n", nomjoueur2, capturej2, nomjoueur1);
        }



    }while (fin == 0);



    // affichage du nom du vaiqueur


    // fin du jeu

    printf ("merci d avoir jouer ;) \n");


    return 0;
}


