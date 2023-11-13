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
	int tab_bits[CODAGE_NB_BITS];
	int nb_bits;

	// Test de inverser_tab_bits
	int bits_inverses[CODAGE_NB_BITS] = { 19, 10, 14, 13, 4, 20, 7 };
	printf("Bits avant inversion : ");
	afficher_tab_bits(bits_inverses, CODAGE_NB_BITS); //test aff tab bits
	inverser_tab_bits(bits_inverses, CODAGE_NB_BITS); //test inverser tab bits
	printf("Bits apres inversion : ");
	afficher_tab_bits(bits_inverses, CODAGE_NB_BITS);

	// Test de codage_dec2bin
	int nombre = 25;
	nb_bits = codage_dec2bin(nombre, tab_bits);
	printf("Nombre decimal : %d\n", nombre);
	printf("Bits en binaire : ");
	afficher_tab_bits(tab_bits, nb_bits);

	// Test de codage_bin2dec
	int nombre_recupere = codage_bin2dec(tab_bits);
	printf("Bits en decimal : %d\n\n", nombre_recupere);

	// Exemple d'utilisation de la fonction
	int plateau[] = { 19, 10, 14, 13, 4, 20, 7 };
	int nb_colonnes = 7;
	int matrice[7][CODAGE_NB_BITS];

	construire_mat_binaire(plateau, nb_colonnes, matrice);

	afficher_mat_binaire(matrice, nb_colonnes);
}