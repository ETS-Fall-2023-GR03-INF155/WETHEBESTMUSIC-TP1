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
/*                         Prototype des fonctions                           */
/*===========================================================================*/

//Demande à l'usager de saisir un entier entre les bornes "min" et "max" (inclusivement).
int lire_entier(int, int);

////Affiche la configuration du plateau à l'écran
void plateau_afficher(int[], int, int);




/*===========================================================================*/
#endif // vas avec le #ifndef
/*===========================================================================*/