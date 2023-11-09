/*===========================================================================*/
/*                                 nim_io.h                                  */
/*          Ce module contient les fonctions assurant l�interactivit�        */
/*                            du jeu avec l�usager                           */
/*===========================================================================*/

#ifndef _NIM_IO_H_
#define _NIM_IO_H_

#include"nim.h"
#include"winconsole.h"

/*===========================================================================*/
/*                       D�clarations des constantes                         */
/*===========================================================================*/

#define PLATEAU_MIN_COLONNES 2      //Nombre minimal de colonnes sur le plateau
#define PLATEAU_MAX_COLONNES 20		//Nombre maximal de colonnes sur le plateau
#define ESPACE 32
#define FLECHE_GAUCHE 75
#define FLECHE_DROITE 77 
#define ENTER 13


/*===========================================================================*/
/*                         Prototype des fonctions                           */
/*===========================================================================*/

//Demande � l'usager de saisir un entier entre les bornes "min" et "max" (inclusivement).
int lire_entier(int, int);

//Affiche la configuration du plateau � l'�cran
void plateau_afficher(int[], int, int);

//tour de l'humain
void tour_humain(int[], int);

//tour de l'ia
void tour_ia(int[], int, int);

//d�mare le jeux en demandant le nb de colones puis en alternant entre le tour du joueur et le 
// tour de l'ia jusqu'a ce qu'un des deux gagne
void demarrer_jeu(int niveau);

/*===========================================================================*/
#endif // vas avec le #ifndef
/*===========================================================================*/