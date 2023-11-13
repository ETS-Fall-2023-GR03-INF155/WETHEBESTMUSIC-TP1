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
/*                         Fonctions Privées (static)                        */
/*===========================================================================*/

//supprime une colone et décale les autres vers la gauche
//la dernière colone n'est pas modifiée et devras etre supprimée

static void plateau_supprimer_colonne(int plateau[], int nb_colonnes, int col_a_supprimer)
{
	int j;
	for (j = col_a_supprimer; j < nb_colonnes - 1; j++)
	{
		plateau[j] = plateau[j + 1]; //copie la colone de droite dans la présente colone 
	}
}

/*===========================================================================*/
/*                              Fonctions                                    */
/*===========================================================================*/

//Initialise le plateau de jeu en remplissant les colones
// d'un nombre aléatoire de pièces

void plateau_init(int plateau[], int nb_colonnes)
{
	int i;

	for (i = 0; i < nb_colonnes; i++) {
		plateau[i] = md_randf(1, PLATEAU_MAX_PIECES); //rempli le plateau avec des nombres aléatoires
	}
}

/*===========================================================================*/

//applique des changements a la configuration du plateau de jeu

int nim_jouer_tour(int plateau[], int nb_colonnes, int colonne, int nb_pieces)

{
	if (colonne > nb_colonnes || colonne < 0 || nb_pieces <= 0 || nb_pieces > plateau[colonne])
		return FALSE; //retourne false si une condition n'est pas remplie
	plateau[colonne] -= nb_pieces; //Retire "nb_pieces" de la colonne "colonne" du plateau et retourne Vrai
	return TRUE;

}

/*===========================================================================*/

//utilise la fonction privée plateau supprimer colonne pour suprimer les colones vides
// et retourne le nouveau nombre de colone


int plateau_defragmenter(int plateau[], int nb_colonnes)
{
	int j;
	for (j = 0; j < nb_colonnes; j++)
		if (plateau[j] == 0) //cherche une colone vide
		{
			plateau_supprimer_colonne(plateau, nb_colonnes, j);//suprime les colonnes vides
			nb_colonnes -= 1; //eleve 1 au nb de colones
		}
	return nb_colonnes; //retourne le nouveau nombre de colonnes
}

/*===========================================================================*/

//fonction qui choisis aléatoirement une colonne et un nb de picèces 
//cette fonction pointe vers choix_colonne et choix_nb_pieces qu'elle modifie

void nim_choix_ia_aleatoire(const int plateau[], int nb_colonnes, int* choix_colonne, int* choix_nb_pieces)
{
	//choisis aleatoirement un nb entre 0 et le nb de colonnes
	*choix_colonne = md_randf(0, nb_colonnes);

	//choisis aleatoirement un nb entre 1 (obligé de prendre au moins une piece) et le nb de piece de cette colonne
	*choix_nb_pieces = md_randf(1, plateau[*choix_colonne]);
}

/*===========================================================================*/

//fonction qui determine le jeu de l'ordnateur intelligent

void nim_choix_ia(const int plateau[], int nb_colonnes, int niveau, int* choix_colonne, int* choix_nb_pieces)
{
	nim_choix_ia_aleatoire(plateau, nb_colonnes, choix_colonne, choix_nb_pieces);
	//temporaire pendant que partie 2 n'est pas codée
}
/*===========================================================================*/

void construire_mat_binaire(const int plateau[], int nb_colonnes,
	int matrice[][CODAGE_NB_BITS]) {
	int i;
	for (i = 0; i < nb_colonnes; i++)
		codage_dec2bin(plateau[i], matrice[i]);
}

/*===========================================================================*/

void afficher_mat_binaire(const int matrice[][CODAGE_NB_BITS], int nb_colonnes) {
	int i;
	for (i = 0; i < nb_colonnes; i++) {
		afficher_tab_bits(matrice[i], CODAGE_NB_BITS);
	}
}

/*===========================================================================*/