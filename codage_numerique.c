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

//Fonction qui inverse les "nb_bits/2" premières valeurs d'un tableau de bits ok

int inverser_tab_bits(int tab_bits[], int nb_bits) {
	int i = 0;
	if (nb_bits <= 0 || nb_bits > CODAGE_NB_BITS) {
		return FALSE;
		//printf(" Veuillez entrez un nb_bits <= à 8 : ");  NÉCÉSSAIRE????
	}

	//Inverse les "nb_bits/2" valeurs dans le tableau
	for (i = 0; i < nb_bits / 2; i++) {
		int temp = tab_bits[i];
		tab_bits[i] = tab_bits[nb_bits - i - 1];
		tab_bits[nb_bits - i - 1] = temp;
	}
	return TRUE;
}

/*===========================================================================*/

//traduit un nombre décimal en binaire

int codage_dec2bin(int nombre, int resultat[]) {
	int i = 8;	//commence au bit 0 (position 7 du tableau)
	while (i>=0 && nombre>0){ // s'arret si le nombre est plus petit que 0 ou si on a 8 bits
		i--; //vas de gauche a droite
		resultat[i] = nombre % 2; //1 si nombre est impair
		nombre /= 2;
	}
	
	if (nombre > 0)
	{
		return 0;
	}

	return 8-i;
}
