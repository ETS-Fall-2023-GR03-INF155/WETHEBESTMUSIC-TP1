/*===========================================================================*/

#define _CRT_SECURE_NO_WARNINGS

/*===========================================================================*/
/*                            Librairies usuelles                            */
/*===========================================================================*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include "nim_io.h"

/*===========================================================================*/
/*                              Fonctions                                    */
/*===========================================================================*/

//Demande à l'usager de saisir un entier entre les bornes "min" et "max" (inclusivement).
int lire_entier(int min, int max)

{
	int entier;
	//boucle qui redemande un entier tant que celui ci n'est pas entre les bornes
	do
	{
		printf("\nEntrez un entier entre %d et %d: ", min, max);
		scanf("%d", &entier);
		if (entier < min || entier > max) //Affiche erreur si l'entier n'est pas entre les bornes
			printf("\nErreur,");
	} while (entier < min || entier > max);

	return entier;
}

/*===========================================================================*/

//Affiche la configuration du plateau à l'écran
void plateau_afficher(const int plateau[], int nb_colonnes, int col_select)
{
	int coltab, j, i;

	for (i = 0; i < nb_colonnes; i++)
	{
		for (j = 1; j <= PLATEAU_MAX_PIECES; j++)
		{

			//Étape 1 rangée d'en bas

			gotoxy(7 + i + (i * 2), 42);
			printf("%d", i);

			//Étape 2 première colone

			gotoxy(2, 40 - j);
			printf("%d", j);

			//Étape 3 les étoile

			if (plateau[i] >= j) //condition pour avoir une étoile
			{
				if (i == col_select) // si la colone est celle sélectionée
				{
					textbackground(RED); //tout les prochains print seront sur un fond roug

					gotoxy(7 + i + (i * 2), 40 - j);
					printf("*");
				}

				else
				{
					textbackground(BLACK); // tout les prochains print seront en noir

					gotoxy(7 + i + (i * 2), 40 - j);
					printf("*");
				}
			}
		}
	}
}

/*===========================================================================*/
