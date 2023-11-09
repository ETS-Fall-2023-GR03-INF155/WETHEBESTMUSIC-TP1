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

#define PLATEAU_MAX_PIECES 35		//Nombre maximal de pi�ces par colonne
#define TRUE   1
#define FALSE  0


/*===========================================================================*/
/*                   Prototype des fonctions publiques                       */
/*===========================================================================*/

//Initialise le plateau de jeu en remplissant les "nb_colonnes" d'un nombre al�atoire de pi�ces 
void plateau_init(int[], int);

//permet de retirer des pic�ces du pateau si possible (TRUE), renvois FALSE sinon 
int nim_jouer_tour(int[], int, int, int);

//utilise la fonction priv�e plateau supprimer colonne pour suprimer les colones vides
int plateau_defragmenter(int[], int);

//permet a l'ia de faire un choix al�atoire de colone et de piece
void nim_choix_ia_aleatoire(int[], int, int*, int*);

//choix de l'ia intelligent
void nim_choix_ia(const int plateau[], int nb_colonnes, int niveau, int* choix_colonne, int* choix_nb_pieces);

/*===========================================================================*/
#endif // vas avec le #ifndef
/*===========================================================================*/