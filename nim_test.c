/*===========================================================================*/

#define _CRT_SECURE_NO_WARNINGS

/*===========================================================================*/
/*                            Librairies usuelles                            */
/*===========================================================================*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"nim_test.h"

/*===========================================================================*/
/*                            Test des fonctions                             */
/*===========================================================================*/

// test lire_entier et plateau_init
void test_1_et_2()
{

	//variables

	int colones; //le nb de colones du plateau
	int plateau[PLATEAU_MAX_COLONNES], i;
	int selection = 1;
	int colonne; //temporaire
	int nb_pieces; //temporaire
	int iacolonne = 0;
	int iapiece = 0;

	//test lire_entier

	colones = lire_entier(1, PLATEAU_MAX_COLONNES);
	printf("votre nombre selectione est: %d\n", colones); //fin test lire_entier

	//test plateau_ini

	plateau_init(plateau, colones); //nb de colones définie dans lire_entier
	printf("Voici votre tableau:\n");
	for (i = 0; i < colones; i++) //print le tableau test
		printf("%d ", plateau[i]); //fin test plateau_ini

	//test plateau_afficher
	//BUG ***** quand on entre 2 colones, la colone de gauche est rouge aussi

	getchar();
	getchar();//fait une pause (attend que l'utilisateur entre une touche)

	clrscr(); //clear le terminal IMPORTANT

	plateau_afficher(plateau, colones, selection);

	//test nim jouer tour 
		//demander quelle rangée le joueur veut enlever TEMPORAIRE
	getchar();
	getchar();//fait une pause (attend que l'utilisateur entre une touche)
	system("color 0F"); //s'essure d'enlever le rouge
	clrscr(); //clear le terminal IMPORTANT


	do
	{
		printf("entrez une colone :");
		scanf("%d", &colonne);
		printf("entrez un nombre de pieces:");
		scanf("%d", &nb_pieces);
	} while (!nim_jouer_tour(plateau, colones, colonne, nb_pieces));
	//fin TEMPORAIRE
	getchar();
	getchar();//fait une pause (attend que l'utilisateur entre une touche)

	clrscr(); //clear le terminal IMPORTANT

	plateau_afficher(plateau, colones, selection);

	//test plateau supprimer et plateau défragmenter

	colones = plateau_defragmenter(plateau, colones);

	getchar();
	getchar();//fait une pause (attend que l'utilisateur entre une touche)
	system("color 0F"); //s'essure d'enlever le rouge
	clrscr(); //clear le terminal IMPORTANT

	plateau_afficher(plateau, colones, selection);

	//test ia choix aléatoire
	/*
		gotoxy(0, 0);
		printf("\ncolonne: %d, piece : %d", iacolonne, iapiece);
		nim_choix_ia_aleatoire(plateau, colones, &iacolonne, &iapiece);
		printf("\ncolonne: %d, piece : %d", iacolonne, iapiece);
	*/
	//test nim_choix_ia
	nim_choix_ia(plateau, colones, 1, &iacolonne, &iapiece);
	printf("\ncolonne: %d, piece : %d", iacolonne, iapiece);
}

void test_tour()
{

	//variables

	int colones; //le nb de colones du plateau
	int plateau[PLATEAU_MAX_COLONNES], i;

	//test lire_entier

	colones = lire_entier(1, PLATEAU_MAX_COLONNES);
	printf("votre nombre selectione est: %d\n", colones); //fin test lire_entier

	//test plateau_ini

	plateau_init(plateau, colones); //nb de colones définie dans lire_entier
	printf("Voici votre tableau:\n");
	for (i = 0; i < colones; i++) //print le tableau test
		printf("%d ", plateau[i]); //fin test plateau_ini

	//test choisir colone + joueur humain
	clrscr(); //clear le terminal IMPORTANT
	plateau_afficher(plateau, colones, 0);

	tour_humain(plateau, colones);
	tour_ia(plateau, colones, 1);
}

void test_partie1()
{
	int difficulte;

	do
	{
		system("color 0F"); //s'essure d'enlever le rouge
		clrscr();
		//imprimer le menu
		gotoxy(0, 0);
		printf(" MENU:\n-------\n(1) Jeu niveau FACILE\n(2) Jeu niveau MOYEN\n(3) Jeu niveau DIFFICILE\n(4) Quitter\n");
		difficulte = lire_entier(1, 4);

		if (difficulte != 4)
		{
			//demare le jeu
			demarrer_jeu(difficulte);
		}
	} while (difficulte != 4); //si l'utilisateur de demande pas de quitte
}

void test_bits()
{
	int tableau[8] = {0,0,0,0,0,0,0,0}, nb, i;

	printf("entrez un nombre svp : \n");
	scanf("%d", &nb);
	printf("%d\n", codage_dec2bin(nb, tableau));
	for (i = 0; i < 8; i++) {
		printf("%d, ",  tableau[i]);
	}
}