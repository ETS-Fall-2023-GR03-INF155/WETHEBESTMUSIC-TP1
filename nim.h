/*===========================================================================*/
/*                                  nim.h                                    */
/*Ce module contient les fonctions nec�ssaires � l'impl�mantation du jeu NIM */
/*===========================================================================*/

#ifndef MANIP_PLATEAU_H_
#define MANIP_PLATEAU_H_

#include "codage_numerique.h"
#include "m_distributions.h"

/*===========================================================================*/
/*                       D�clarations des constantes                         */
/*===========================================================================*/

#define PLATEAU_MAX_COLONNES 20		//Nombre maximal de colonnes sur le plateau
#define PLATEAU_MAX_PIECES 35		//Nombre maximal de pi�ces par colonne
#define TRUE   1
#define FALSE  0

/*===========================================================================*/
/*                   Prototype des fonctions publiques                       */
/*===========================================================================*/

//Initialise le plateau de jeu en remplissant les "nb_colonnes" d'un nombre al�atoire de pi�ces 
void plateau_init(int plateau[], int nb_colonnes);

//Applique des changements � la configuration du plateau de jeu en retirant 
// "nb_pieces" de la colonne "colonne" du plateau
int nim_jouer_tour(int plateau[], int nb_colonnes, int colonne,
                   int nb_pieces);

//Fonction qui supprime les colonnes vides du tableau en utilisant la fonction 
// "plateau_supprimer_colonne"
int plateau_defragmenter(int plateau[], int nb_colonnes);

//Fonction qui effectue un jeu al�atoire en choisissant au hasard une colonne,
// puis au hasard le nombre de pi�ces � jouer de cette colonne
void nim_choix_ia_aleatoire(const int plateau[], int nb_colonnes,
                            int* choix_colonne, int* choix_nb_pieces);

//Fonction qui d�termine quel doit �tre le jeu de l'ordinateur. Cette fonction impl�mente l'algorithme
// intelligent d�crit dans la partie 2 du TP. Le choix de l'ordinateur sera stock� dans les deux r�f�rences
// "choix_colonne" et "choix_nb_pieces"
void nim_choix_ia(const int plateau[], int nb_colonnes, int niveau,
                  int* choix_colonne, int* choix_nb_pieces);

/*===========================================================================*/
#endif // vas avec le #ifndef
/*===========================================================================*/