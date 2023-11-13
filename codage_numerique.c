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
    int i;
    if (nb_bits <= 0 || nb_bits > CODAGE_NB_BITS) {
        return FALSE;
    }

    //Inverse les "nb_bits/2" valeurs dans le tableau
    for (i = 0; i < nb_bits / 2; i++) {
        int temp = tab_bits[i];
        tab_bits[i] = tab_bits[nb_bits - i - 1];
        tab_bits[nb_bits - i - 1] = temp;
    }
    return TRUE;
}

//traduit un nombre décimal en binaire

int codage_dec2bin(int nombre, int resultat[]) {
    int i = 0;    //commence au bit 0

    while (nombre > 0) { // s'arrete si le nombre est plus petit que 0
        resultat[i] = nombre % 2; //1 si nombre est impair
        nombre /= 2;
        i++; //vas de doite a gauche
    }

    // Remplissage des bits restants avec des zéros
    while (i < CODAGE_NB_BITS) {
        resultat[i] = 0;
        ++i;
    }

    inverser_tab_bits(resultat, CODAGE_NB_BITS); //inverse le tableau et nb bit = tjrs 8 

    return i;
}

//Affichage d'un tableau de bits à l'écran
void afficher_tab_bits(const int tab_bits[], int nb_bits) {
    int i;
    nb_bits = CODAGE_NB_BITS; //on présume que le tableau est égal exactement au codagenbbits
    for (i = 0; i < nb_bits; i++) {
        printf("%d ", tab_bits[i]);
    }
    printf("\n");
}

//Conversion d'un tableau de bits en nombre binaire, vers sa
// représentation décimale
int codage_bin2dec(const int tab_bits[]) {
    int resultat = 0;
    int puissanceDeux = 1;        // Commence par le bit le plus à gauche (2^0 = 1)
    int i = CODAGE_NB_BITS - 1;

    while (i >= 0) {
        resultat += tab_bits[i] * puissanceDeux;
        puissanceDeux *= 2;        //Augmente la puissance de 2
        i--;
    }
    return resultat;
}
