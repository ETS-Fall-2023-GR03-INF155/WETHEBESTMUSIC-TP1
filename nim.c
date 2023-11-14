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

//a des fin de test!!! print la matrice binaire

static void afficher_mat_binaire(const int matrice[][CODAGE_NB_BITS], int nb_colonnes) {
	int i, j;
	for (int i = 0; i < nb_colonnes; i++) {
		for (int j = 0; j < CODAGE_NB_BITS; j++) {
			printf("%d ", matrice[i][j]);
		}
		printf("\n");
	}
}

/*===========================================================================*/

//construit une matrice le nb de bit maximal comme x et le nb de colonne comme j
//rempli cette matrice grace a codage_dec2bin

static void construire_mat_binaire(const int plateau[], int nb_colonnes,
	int matrice[][CODAGE_NB_BITS]) {
	int j;
	for (j = 0; j < nb_colonnes; j++) {
		codage_dec2bin(plateau[j], matrice[j]);//change ligne par ligne la matrice grace a tableau 
		//1 dimension de codage dec2bin
	}
}

/*===========================================================================*/

// Fonction qui calcule la somme de chaque colonne d'une matrice binaire
static void sommes_mat_binaire(const int matrice[][CODAGE_NB_BITS],
	int nb_lignes, int sommes[]) {
	int i, j;
	for (int j = 0; j < CODAGE_NB_BITS; j++) {
		sommes[j] = 0;
		for (int i = 0; i < nb_lignes; i++) {
			sommes[j] += matrice[i][j];
		}
	}
}

/*===========================================================================*/

//fonction qui détecte le premier impaire 

static int position_premier_impaire(const int tab[])
{
	int i;
	for (i = 0; i < CODAGE_NB_BITS; i++)
	{
		if (tab[i] & 2 != 0)
			return i;
	}
	return -1;
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

//fonction qui determine le jeu de l'ordinateur intelligent

void nim_choix_ia(const int plateau[], int nb_colonnes, int* choix_colonne, int* choix_nb_pieces)
{

	int matrice[PLATEAU_MAX_COLONNES][CODAGE_NB_BITS];
	int sommes[CODAGE_NB_BITS];
	int tabcol[CODAGE_NB_BITS];
	int bonne_colonne = 0;
	int good_colonne;
	int good = 1;
	int i;
	int j;
	int convert;
	int initial;

	// Initialiseà -1 au cas où il y aurait une erreur

	*choix_colonne = PAIR;
	*choix_nb_pieces = PAIR;

	//choix colonne

	construire_mat_binaire(plateau, nb_colonnes, matrice); //construire la matrice
	sommes_mat_binaire(matrice, nb_colonnes, sommes); //construire le tableau sommes
	bonne_colonne = position_premier_impaire(sommes); //trouver la pos de prem somme impair
	if (bonne_colonne == -1) //si pas de nb impair
	{
		nim_choix_ia_aleatoire(plateau, nb_colonnes, choix_colonne, choix_nb_pieces);
		return;
	}
	for (i = 0; good && i<nb_colonnes; i++)
	{
		if (matrice[i][bonne_colonne] == 1)
		{
			good_colonne = i;	//bonne ligne
			good = 0; //sors de la boucle
		}
	}

	//choix nb piece

	for (j = bonne_colonne; j < CODAGE_NB_BITS; j++)
	{
		matrice[good_colonne][j] = (matrice[good_colonne][j] == 1) ? 0 : 1; //inverse les bits
	}
	convert = codage_bin2dec(matrice[good_colonne]);
	initial = plateau[good_colonne];

	*choix_nb_pieces = initial - convert;
	*choix_colonne = good_colonne;

}
/*===========================================================================*/
