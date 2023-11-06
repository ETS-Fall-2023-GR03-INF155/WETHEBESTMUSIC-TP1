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
void test_Partie1()
{

	//test lire_entier
	int nb_colonnes; //le nb de colones du plateau
	int plateau[PLATEAU_MAX_COLONNES], i;
	int selection = 1;

	nb_colonnes = lire_entier(1, PLATEAU_MAX_COLONNES);
	printf("votre nombre selectione est: %d\n", nb_colonnes); //fin test lire_entier

	//test plateau_in
	plateau_init(plateau, nb_colonnes); //nb de colones définie dans lire_entier
	printf("Voici votre tableau:\n");
	for (i = 0; i < nb_colonnes; i++) //print le tableau test
		printf("%d ", plateau[i]); //fin test plateau_ini

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

	//test plateau_supprimer_colonne
	int col_a_supprimer = lire_entier(0, nb_colonnes - 1);

	plateau_supprimer_colonne(plateau, nb_colonnes, col_a_supprimer);
	plateau_afficher(plateau, nb_colonnes, selection);

	//test plateau_defragmenter
	int nouveau_nb_colonnes = plateau_defragmenter(plateau, nb_colonnes);
	plateau_afficher(plateau, nouveau_nb_colonnes, selection);

	//test nim_choix_ia
	int choix_colonne_ia;
	int choix_nb_pieces_ia;

	nim_choix_ia_aleatoire(plateau, nouveau_nb_colonnes, &choix_colonne_ia, &choix_nb_pieces_ia);
}