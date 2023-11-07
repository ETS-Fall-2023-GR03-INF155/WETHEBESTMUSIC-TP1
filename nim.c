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

//Initialise le plateau de jeu en remplissant les colonnes
// d'un nombre aléatoire de pièces 
void plateau_init(int plateau[], int nb_colonnes)
{
	int i;

	for (i = 0; i < nb_colonnes; i++) {
		plateau[i] = md_randf(1, PLATEAU_MAX_PIECES); //rempli le tableau avec un nombre aléatoire
	}
}

//Fonction pour jouer un tour en retirant des pièces
// de la colonne
int nim_jouer_tour(int plateau[], int nb_colonnes, int colonne,
				   int nb_pieces) {
	if (colonne < 0 || colonne >= nb_colonnes || nb_pieces <= 0 || nb_pieces > plateau[colonne]) {
		return FALSE;
	}
	plateau[colonne] -= nb_pieces;	//Retire "nb_pieces" de la colonne "colonne" du plateau et retourne Vrai
	return TRUE;
}

//Fonction pour supprimer une colonne du plateau
void plateau_supprimer_colonne(int plateau[], int nb_colonnes,
							   int col_a_supprimer) {
	for (int i = col_a_supprimer; i < nb_colonnes - 1; i++) {
		for (int j = 0; j < nb_colonnes; j++) {
			plateau[i] = plateau[(i + 1) * nb_colonnes + j];
		}
	}
	nb_colonnes--;
}

//
int plateau_defragmenter(int plateau[], int nb_colonnes) {
	int nouveau_nb_colonnes = nb_colonnes;
	for (int i = 0; i < nb_colonnes; i++) {
		if (plateau[i] == 0) {
			plateau_supprimer_colonne(plateau, nouveau_nb_colonnes, i);
			nouveau_nb_colonnes--;
		}
	}
	return nouveau_nb_colonnes;
}

//Fonction pour choisir une colonne aléatoire et 
// un nombre aléatoire de pièces à jouer de cette colonne
void nim_choix_ia_aleatoire(const int plateau[], int nb_colonnes,
	int* choix_colonne, int* choix_nb_pieces) {
	//Choix aléatoire de la colonne
	srand(time(NULL));
	*choix_colonne = rand() % nb_colonnes;
	// Choix aléatoire du nombre de pièces entre 1 et le nombre de pièces dans la colonne 
	*choix_nb_pieces = (rand() % plateau[*choix_colonne]) + 1;
}

/*===========================================================================*/
