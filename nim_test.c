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
#include "nim.h"

/*===========================================================================*/
/*                            Test des fonctions                             */
/*===========================================================================*/

//Fonction qui test toutes les fonctions de la partie 1
void test_Partie1_2() {
	int nb_colonnes; //le nb de colones du plateau
	int plateau[PLATEAU_MAX_COLONNES];
	int i;
	int selection = 1;

	//Test lire_entier
	nb_colonnes = lire_entier(1, PLATEAU_MAX_COLONNES);
	printf("Votre nombre selectione est: %d\n", nb_colonnes); //fin test lire_entier

	//Test plateau_init
	plateau_init(plateau, nb_colonnes); //nb de colones définie dans lire_entier
	printf("Voici votre tableau:\n");
	for (i = 0; i < nb_colonnes; i++) { //print le tableau test
		printf("%d ", plateau[i]); //fin test plateau_init
	}
	printf("\n");

	//test plateau_afficher

	getchar();
	getchar();//fait une pause (attend que l'utilisateur entre une touche)
	clrscr(); //clear le terminal

	plateau_afficher(plateau, nb_colonnes, selection);

	//test nim_jouer_tour
	int colonne;
	int nb_pieces;

	printf("Entrez la colonne et le nombre de pièce à retirer : ");
	colonne = lire_entier(0, nb_colonnes - 1);
	nb_pieces = lire_entier(1, plateau[colonne]);

	if (nim_jouer_tour(plateau, nb_colonnes, colonne, nb_pieces)) {
		plateau_afficher(plateau, nb_colonnes, selection);
	}
}