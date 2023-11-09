/*===========================================================================*/
/*                                  nim.h                                    */
/*Ce module contient les fonctions necéssaires à l'implémantation du jeu NIM */
/*===========================================================================*/

#ifndef MANIP_PLATEAU_H_
#define MANIP_PLATEAU_H_

#include "codage_numerique.h"
#include "m_distributions.h"

/*===========================================================================*/
/*                       Déclarations des constantes                         */
/*===========================================================================*/

#define PLATEAU_MAX_PIECES 35		//Nombre maximal de pièces par colonne
#define TRUE   1
#define FALSE  0


/*===========================================================================*/
/*                   Prototype des fonctions publiques                       */
/*===========================================================================*/

//Initialise le plateau de jeu en remplissant les "nb_colonnes" d'un nombre aléatoire de pièces 
void plateau_init(int[], int);

//permet de retirer des picèces du pateau si possible (TRUE), renvois FALSE sinon 
int nim_jouer_tour(int[], int, int, int);

//utilise la fonction privée plateau supprimer colonne pour suprimer les colones vides
int plateau_defragmenter(int[], int);

//permet a l'ia de faire un choix aléatoire de colone et de piece
void nim_choix_ia_aleatoire(int[], int, int*, int*);

//choix de l'ia intelligent
void nim_choix_ia(const int plateau[], int nb_colonnes, int niveau, int* choix_colonne, int* choix_nb_pieces);

/*===========================================================================*/
#endif // vas avec le #ifndef
/*===========================================================================*/