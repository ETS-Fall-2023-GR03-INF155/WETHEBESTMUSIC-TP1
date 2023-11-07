/*===========================================================================*/
/*                          codage_numerique.h                               */
/*Ce module permet de faire des conversions de base (numerique <---> binaire)*/
/*===========================================================================*/

#ifndef _CODAGE_NUMERIQUE_H_
#define _CODAGE_NUMERIQUE_H_

/*===========================================================================*/
/*                       D�clarations des constantes                         */
/*===========================================================================*/

#define	CODAGE_NB_BITS	8	// Constante �gale � 8
#define TRUE   1
#define FALSE  0

/*===========================================================================*/
/*                         Prototype des fonctions                           */
/*===========================================================================*/

//Fonction qui inverse les "nb_bits/2" premi�res valeurs d'un tableau de bits:
// le premier bit devient le dernier (et inversement), le deuxi�me devient
// l'avant dernier, etc.
int inverser_tab_bits(int tab_bits[], int nb_bits);

/*===========================================================================*/
#endif // vas avec le #ifndef
/*===========================================================================*/
