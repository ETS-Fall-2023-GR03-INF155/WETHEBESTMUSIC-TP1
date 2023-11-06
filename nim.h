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

#define PLATEAU_MAX_COLONNES 20		//Nombre maximal de colonnes sur le plateau
#define PLATEAU_MAX_PIECES 35		//Nombre maximal de pièces par colonne
#define TRUE   1
#define FALSE  0

/*===========================================================================*/
/*                   Prototype des fonctions publiques                       */
/*===========================================================================*/

//Initialise le plateau de jeu en remplissant les "nb_colonnes" d'un nombre aléatoire de pièces 
void plateau_init(int plateau[], int nb_colonnes);

/*===========================================================================*/
#endif // vas avec le #ifndef
/*===========================================================================*/