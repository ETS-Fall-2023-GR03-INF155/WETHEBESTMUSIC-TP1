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

#define ESC 27		/* code ASCII du <ESC> */
#define FLECHE_GAUCHE	75	/* code ASCII de <FLECHE_GAUCHE> */
#define	FLECHE_DROITE	77	/* code ASCII de <FLECHE_DROITE> */

/*===========================================================================*/
/*                         Prototype des fonctions                           */
/*===========================================================================*/

//Demande à l'usager de saisir un entier entre les bornes "min" et "max" (inclusivement).
int lire_entier(int, int);

//Affiche la configuration du plateau à l'écran
void plateau_afficher(int[], int, int);

//Déclenche le tour de l'humain.
void tour_humain(int plateau[], int nb_colonnes);

//Déclenche le tour de l'ordinateur
void tour_ia(int plateau[], int nb_colonnes, double difficulte);

//Fonction qui contrôle le jeu de nim: elle donne la main, tour à tour, à chacun 
// des deux joueurs et déclare le gagnant une fois la partie terminée. 
// On quitte cette fonction quand la partie est terminée.
void demarrer_jeu(int niveau);

/*===========================================================================*/
#endif // vas avec le #ifndef
/*===========================================================================*/