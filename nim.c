/*===========================================================================*/

#define _CRT_SECURE_NO_WARNINGS

/*===========================================================================*/
/*                            Librairies usuelles                            */
/*===========================================================================*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "nim.h"

/*===========================================================================*/
/*                              Fonctions                                    */
/*===========================================================================*/

//Initialise le plateau de jeu en remplissant les colones
// d'un nombre al�atoire de pi�ces 
void plateau_init(int plateau[], int nb_colonnes)

{
	int i;
	
	for (i = 0; i < nb_colonnes; i++) {
		plateau[i] = md_randf(1, PLATEAU_MAX_PIECES); //rempli le tableau avec un nombre al�atoire
	}
}

/*===========================================================================*/