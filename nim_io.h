/*===========================================================================*/
/*                                 nim_io.h                                  */
/*          Ce module contient les fonctions assurant l’interactivité        */
/*                            du jeu avec l’usager                           */
/*===========================================================================*/

#ifndef _NIM_IO_H_
#define _NIM_IO_H_

#include"nim.h"
#include"winconsole.h"

/*===========================================================================*/
/*                       Déclarations des constantes                         */
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

//Demande à l'usager de saisir un entier entre les bornes "min" et "max" (inclusivement).
int lire_entier(int, int);

//Affiche la configuration du plateau à l'écran
void plateau_afficher(int[], int, int);

//tour de l'humain
void tour_humain(int[], int);

//tour de l'ia
void tour_ia(int[], int, int);

//démare le jeux en demandant le nb de colones puis en alternant entre le tour du joueur et le 
// tour de l'ia jusqu'a ce qu'un des deux gagne
void demarrer_jeu(int niveau);

/*===========================================================================*/
#endif // vas avec le #ifndef
/*===========================================================================*/