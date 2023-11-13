/*===========================================================================*/
/*                          codage_numerique.h                               */
/*Ce module permet de faire des conversions de base (numerique <---> binaire)*/
/*===========================================================================*/

#ifndef _CODAGE_NUMERIQUE_H_
#define _CODAGE_NUMERIQUE_H_

/*===========================================================================*/
/*                       Déclarations des constantes                         */
/*===========================================================================*/

#define	CODAGE_NB_BITS	8	// nb de bit max pour le codage
#define TRUE   1
#define FALSE  0

/*===========================================================================*/
/*                         Prototype des fonctions                           */
/*===========================================================================*/

//Fonction qui inverse les "nb_bits/2" premières valeurs d'un tableau de bits:
// le premier bit devient le dernier (et inversement), le deuxième devient
// l'avant dernier, etc.
int inverser_tab_bits(int [], int);

//Fonction qui traduit un nombre décimal en binaire.
int codage_dec2bin(int, int []);

/*===========================================================================*/
#endif // vas avec le #ifndef
/*===========================================================================*/
