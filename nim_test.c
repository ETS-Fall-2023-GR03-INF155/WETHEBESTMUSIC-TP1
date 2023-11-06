/*===========================================================================*/

#define _CRT_SECURE_NO_WARNINGS

/*===========================================================================*/
/*                            Librairies usuelles                            */
/*===========================================================================*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"nim_test.h"
#include "nim_io.h"

/*===========================================================================*/
/*                            Test des fonctions                             */
/*===========================================================================*/

// test lire_entier et plateau_init
void test_1_et_2()
{	

//test lire_entier

	int colones; //le nb de colones du plateau
	int plateau[PLATEAU_MAX_COLONNES], i;
	int selection = 1;

	colones = lire_entier(1, PLATEAU_MAX_COLONNES);
	printf("votre nombre selectione est: %d\n", colones); //fin test lire_entier

//test plateau_ini

	plateau_init(plateau, colones); //nb de colones définie dans lire_entier
	printf("Voici votre tableau:\n");
	for (i = 0; i < colones; i++) //print le tableau test
		printf("%d ", plateau[i]); //fin test plateau_ini

//test plateau_afficher

	getchar();
	getchar();//fait une pause (attend que l'utilisateur entre une touche)
	clrscr(); //clear le terminal

	plateau_afficher(plateau, colones, selection);
}