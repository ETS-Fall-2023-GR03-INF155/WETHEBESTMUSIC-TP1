/*===========================================================================*/

#define _CRT_SECURE_NO_WARNINGS

/*===========================================================================*/
/*                            Librairies usuelles                            */
/*===========================================================================*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"codage_numerique.h"

/*===========================================================================*/
/*                              Fonctions                                    */
/*===========================================================================*/

//Fonction qui inverse les "nb_bits/2" premières valeurs d'un tableau de bits
int inverser_tab_bits(int tab_bits[], int nb_bits) {
	int i = 0;
	if (nb_bits <= 0 || nb_bits > CODAGE_NB_BITS) {
		return FALSE;
		printf(" Veuillez entrez un nb_bits <= à 8 : ");
	}

	//Inverse les "nb_bits/2" valeurs dans le tableau
	for (i = 0; i < nb_bits / 2; i++) {
		int temp = tab_bits[i];
		tab_bits[i] = tab_bits[nb_bits - i - 1];
		tab_bits[nb_bits - i - 1] = temp;
	}
	return TRUE;
}
