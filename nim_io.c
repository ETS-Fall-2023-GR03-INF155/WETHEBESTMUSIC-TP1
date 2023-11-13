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
/*                         Fonctions Privées (static)                        */
/*===========================================================================*/

//fonction qui permet d'utiliser les fleches, la touche espace et enter pour sélectioner une colonne

static int choisir_colonne(int plateau[], int nb_colonnes)
{
	int col = 0;
	unsigned char touche = 0;

	//Boucle qui s'exécute tant que la touche enter n'est pas entree
	while (touche != ENTER)
	{

		//Si une touche est appuyée
		if (_kbhit()) {
			touche = _getch();

			//Si c'est une touche étendue 
			if (touche == 0 || touche == 224) {
				touche = _getch();

				//Si --> 
				if (touche == FLECHE_DROITE) {
					if (col == nb_colonnes - 1) //si on est a la dernière colone vas a la colone 0
						col = 0;
					else
						col++; //bouge la sélection a droite
				}

				//Si <--
				else if (touche == FLECHE_GAUCHE) {
					if (col == 0) //si on est a la premiere colone vas a la dernière colone
						col = nb_colonnes - 1;
					else
						col--; //bouge la sélection a gauche
				}
			}

			//Si ESPACE
			else if (touche == ESPACE) {
				if (col == nb_colonnes - 1) //si on est a la dernière colone vas a la colone 0
					col = 0;
				else
					col++; //bouge la sélection a droite
			}

			//Imprime le tableau avec la nouvelle sélection apres que '-->', '<--' ou 'espace'
			//aient été touchés
			gotoxy(0, 6);
			clreoscr(); //efface le plateau seulement
			plateau_afficher(plateau, nb_colonnes, col);
		}
	}
	return col; //retourne la sélection choisie (sélection au moment ou enter est pressé)
}

/*===========================================================================*/
/*                              Fonctions                                    */
/*===========================================================================*/

//Demande à l'usager de saisir un entier entre les bornes "min" et "max" (inclusivement)

int lire_entier(int min, int max)

{
	int entier, posx, posy;

	posx = wherex(); //prends la position du curseur avant tout
	posy = wherey();

	//boucle qui redemande un entier tant que celui-ci n'est pas entre les bornes
	do
	{
		printf("saisir une valeur entre %d et %d: ", min, max);
		scanf("%d", &entier);

		//Affiche erreur si l'entier n'est pas entre les bornes
		if (entier<min || entier>max)
		{
			gotoxy(posx, posy); //réécris par dessus la ligne
			clreol();
			printf("Erreur, ");
			while (getchar() != '\n') {} //vide le tampon clavier (évite les bug)
		}
	} while (entier<min || entier>max);

	//retourne l'entier valide
	return entier;
}

/*===========================================================================*/

//Affiche la configuration du plateau à l'écran
void plateau_afficher(const int plateau[], int nb_colonnes, int col_select)
{
	int j, i;

	textbackground(BLACK); //pour s'assurer que le texte est écrit sur fond noir

	//le code est séparé en 3 parties pour minimiser le nombre d'appels a
	//gotoxy, printf et textbackground()

	//Étape 1 rangée d'en bas
	for (i = 0; i < nb_colonnes; i++)
	{
		gotoxy(7 + 3 * i, 43);
		printf("%d", i);
	}

	//Étape 2 première colone
	for (j = 1; j <= 35; j++)
	{
		gotoxy(2, 41 - j);
		printf("%d", j);
	}

	//Étape 3 les étoile
	for (i = 0; i < nb_colonnes; i++)
	{
		for (j = 1; j <= 35; j++)
		{
			if (plateau[i] >= j)
			{
				if (i == col_select)
				{
					gotoxy(7 + 3 * i, 41 - j);
					textbackground(RED);
					printf("*");
					textbackground(BLACK);
				}
				else
				{
					gotoxy(7 + 3 * i, 41 - j);
					printf("*");
				}
			}
		}
	}
}
/*===========================================================================*/

//demande a l'utilisateur de choisir une colonne et un nb de pieces

void tour_humain(int plateau[], int nb_colonnes)
{
	int col = 0;
	int nbpiece = 0;

	//entete selection colone joueur
	gotoxy(0, 0);
	printf("****** Tour Joueur ******");
	gotoxy(0, 3);
	printf("==> Veuillez choisir la colonne souhaitee");
	gotoxy(5, 5);
	printf("| <-- , -->, <ESPACE> : Changer la selection | <ENTER> : Valider |");

	//selection colone
	col = choisir_colonne(plateau, nb_colonnes);

	//clear entete
	gotoxy(0, 5);
	clreol(); //clear cette ligne
	gotoxy(0, 3);
	clreol(); //clear cette ligne

	//selection piece entre 1 et le nb de pice de la colone
	gotoxy(0, 3);
	printf("==> Nb de pieces : ");
	nbpiece = lire_entier(1, plateau[col]);

	//changment du plateau selon les choix du joueur
	nim_jouer_tour(plateau, nb_colonnes, col, nbpiece);
}

/*===========================================================================*/

//tour de l'ia

void tour_ia(int plateau[], int nb_colonnes, int difficulte)
{
	int ia_col = 0;
	int ia_piece = 0;

	//demande a l'ia de faire un choix de colonne et de pieces
	//grace a deux pointeurs vers ia_col et ia_piece
	nim_choix_ia(plateau, nb_colonnes, difficulte, &ia_col, &ia_piece);

	//entete selection colone ia
	gotoxy(0, 0);
	printf("****** Tour Ordinateur ******");
	gotoxy(0, 3);
	clreol(); //clear cette ligne
	gotoxy(0, 3);
	printf("Ordinateur va prendre %d pieces de la colonne %d", ia_piece, ia_col);
	gotoxy(0, 5);
	clreol(); //clear cette ligne
	gotoxy(0, 4);
	printf("Appuyez sur une touche pour continuer...");

	//affiche le plateau au joueur en sélectionnant la colone choisie par l'ia
	gotoxy(0, 6);
	system("color 0F"); //s'essure d'enlever le rouge
	clreoscr();
	plateau_afficher(plateau, nb_colonnes, ia_col);

	//changement du plateau selon les choix de l'ia
	nim_jouer_tour(plateau, nb_colonnes, ia_col, ia_piece);

	//attente d'une touche de l'utilisateur pour passer a la prochaine étape
	getchar();
	getchar();

}

/*===========================================================================*/

//fonction qui démare le jeux en demandant le nb de colones puis en alternant entre 
//le tour du joueur et le tour de l'ia jusqu'a ce qu'un des deux gagne

void demarrer_jeu(int niveau)
{
	int nb_colonnes;
	int plateau[PLATEAU_MAX_COLONNES];
	char joueur = 2; //on commence a 2 car le début de la boucle change ce nb


	clrscr(); //efface l'écran

	//MENU , demander a joueur combien de colones il veut
	printf("***** NOUVELLE PARTIE *****\nNombre de colonnes:\n");
	nb_colonnes = lire_entier(PLATEAU_MIN_COLONNES, PLATEAU_MAX_COLONNES); //valide le chiffre du nb de colonnes

	//initialisation du plateau
	plateau_init(plateau, nb_colonnes);

	//Début du jeu
	while (nb_colonnes > 0) //conditions fin de jeu
	{
		//change le joueur en alternance (si joueur 1 on le change a 2 sinon on le met a 1)
		joueur = (joueur == 1) ? 2 : 1;

		//tour de l'humain
		if (joueur == 1)
		{
			//affiche le plateau
			clrscr(); //clear le terminal
			system("color 0F"); //s'essure d'enlever le rouge
			plateau_afficher(plateau, nb_colonnes, 0);

			tour_humain(plateau, nb_colonnes);
		}

		//tour de l'ia
		else
			tour_ia(plateau, nb_colonnes, niveau);

		//défragmente le plateau selon l'action précédente du joueur ou de l'ia
		nb_colonnes = plateau_defragmenter(plateau, nb_colonnes);
	}

	//imprime le plateau final
	clrscr(); //clear le terminal IMPORTANT
	system("color 0F"); //s'essure d'enlever le rouge
	plateau_afficher(plateau, nb_colonnes, 0);

	//affiche le message de victoire
	switch (joueur)
	{
	case 1:
		//entete joueur a gagne
		gotoxy(0, 0);
		printf("****** Partie terminee ******");
		gotoxy(0, 3);
		printf("L'HUMAIN gagne!");
		gotoxy(0, 4);
		printf("Appuyez sur une touche pour continuer...");

		getchar();
		getchar();

		break;

		//si ia gagne
	case 2:

		//entete ia a gagne
		gotoxy(0, 0);
		printf("****** Partie terminee ******");
		gotoxy(0, 3);
		printf("L'IA gagne!");
		gotoxy(0, 4);
		printf("Appuyez sur une touche pour continuer...");

		getchar();
		getchar();

		break;
	}
}