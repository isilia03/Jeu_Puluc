#include "puluc.h"


int lancement ()
{

    int de1 = 0;
    int de2 = 0;
    int de3 = 0;
    int de4 = 0;

    srand(time(NULL));
    de1 = rand () % 2;
    de2 = rand () % 2;
    de3 = rand () % 2;
    de4 = rand () % 2;

    printf ("tirage des des : %d   %d   %d   %d\n", de1, de2, de3, de4);

    if (de1 + de2 + de3 + de4 == 0)
    {
        return 5;
    }

    else if (de1 + de2 + de3 + de4 == 1)
    {
       return 1;
    }

    else if (de1 + de2 + de3 + de4 == 2)
    {
        return 2;
    }

    else if (de1 + de2 + de3 + de4 == 3)
    {
        return 3;
    }

    else
    {
        return 4;
    }


}



int ver_dep_i (int deplacement, int i)
{
    int i_final = 0;
    int verification = 0;

    do
    {
       printf ("entrer la ligne finale de votre pion \n");
       verification = scanf ("%d", &i_final);

       if (verification == 0)
       {
           printf("ERREUR: Votre saisie est invalide ! Veuillez refaire votre choix.\n");
           fflush(stdin);
       }
    }while (i_final != 2);

    return i_final;

}

int ver_dep_j1(int deplacement, int j)
{
    int j_final = 0;
    int verification = 0;

    do
    {
       printf ("entrer la colonne finale de votre pion \n");
       verification = scanf ("%d", &j_final);

       if (verification == 0)
       {
           printf("ERREUR: Votre saisie est invalide ! Veuillez refaire votre choix.\n");
           fflush(stdin);
       }
    }while ((j_final < 0)&&(j_final > 11)&&(j_final-j == deplacement));

    return j_final;
}

int ver_dep_j2(int deplacement, int j)
{
    int j_final = 0;
    int verification = 0;

    do
    {
       printf ("entrer la colonne finale de votre pion \n");
       verification = scanf ("%d", &j_final);

       if (verification == 0)
       {
           printf("ERREUR: Votre saisie est invalide ! Veuillez refaire votre choix.\n");
           fflush(stdin);
       }
    }while ((j_final < -1)&&(j_final > 10)&&(j-j_final == deplacement));

    return j_final;
}





