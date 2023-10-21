#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char *items[] = {"Pierre", "Feuille", "Ciseaux"};

void clean_stdin(void)
{
    int c;
    do
    {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

const char *get_item(int choice)
{
    if (choice >= 1 && choice <= 3)
    {
        return items[choice - 1];
    }
    return "Choix invalide";
}

int main()
{
    int choice, joueur = 0, machine = 0, nbr_manches, start;

    srand(time(NULL));

    int item = rand() % 3 + 1;

    printf("Vous allez jouer au jeu de Pierre, Feuille, Ciseaux\n");
    printf("Pour commencer, en combiens de manches voulez vous jouer ? ");

    scanf("%d", &nbr_manches);

    printf("Ensuite, vous allez devoir ecrire ce que vous allez jouer \n");
    printf("Etes vous pret (1) oui / (2) non) ? ");

    if (scanf("%d", &start) != 1 || start == 1)
    {
        printf("C'est parti !!\n");
    }
    else
    {
        return 0;
    }

    for (int i = 0; nbr_manches > i; i++)
    {
        do
        {
            printf("Que voulez vous jouer ? Pierre (1), Feuille (2) ou Ciseaux (3) ? ");
        } while (scanf("%d", &choice) != 1 || choice < 1 || choice > 3);
        clean_stdin();
        printf("Le joueur joue : %s | La machine joue : %s\n", items[choice - 1], items[item - 1]);
        if (((choice == 1) && (item == 2)) || ((choice == 2) && (item == 3)) || ((choice == 3) && (item == 1)))
        {
            machine++;
            printf("La machine gagne\n");
        }
        else if (((choice == 2) && (item == 1)) || ((choice == 3) && (item == 2)) || ((choice == 1) && (item == 3)))
        {
            joueur++;
            printf("Le joueur gagne\n");
        }
        else if (choice == item)
        {
            printf("Match nul\n");
        }

        printf("Score : [Joueur : %d | Machine : %d]\n", joueur, machine);
    }

    if (joueur > machine)
    {
        printf("Le joueur a gagné la partie");
    }
    else
    {
        printf("La machine a gagné la partie");
    }
}
