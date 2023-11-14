/*===========================================================================*/

#define _CRT_SECURE_NO_WARNINGS

/*===========================================================================*/

/*
Nom : Noah Tremblay et Justin Martel 
Code Permanant: TREN85330401 et ...
Cours : INF155
Projet: Jeux de Nim
Description:

Le jeu de Nim est un jeu tr�s c�l�bre et probablement un des plus anciens jeux du monde .
Il en existe plusieurs variantes et nous allons mettre en �uvre une de ces variantes dans un programme o� 
un joueur humain doit s�opposer � un ordinateur.

Les r�gles du jeu sont tr�s simples : nous disposons un ensemble de pi�ces sur plusieurs colonnes. 
Le nombre de pi�ces et leur disposition en colonnes se fait al�atoirement. Dans notre cas, nous nous limiterons � un maximum de 20 colonnes 
et un maximum de 35 pi�ces par colonne.

Le joueur commence par d�cider combien de colonnes il souhaite avoir dans le plateau du jeu. 
Un ensemble de pi�ces par colonne est alors d�termin� al�atoirement. L�exemple ci-contre pr�sente une configuration du jeu � 7 colonnes.
Ensuite le joueur et l�ordinateur jouent tour � tour (c�est toujours le joueur qui va commencer), chacun choisissant une colonne et le 
nombre de pi�ces � retirer de cette colonne (minimum une pi�ce, maximum toutes les pi�ces de la colonne). Le jeu se poursuit
jusqu�� ce que la derni�re pi�ce soit retir�e, et le joueur l�ayant retir�e sera d�clar� gagnant.

Afin de simplifier le projet, nous le r�aliserons en deux parties :
a)	Le programme permettant de jouer contre un ordinateur qui choisit ses coups de fa�on al�atoire;
b)	Compl�ter la partie (a) en impl�mentant un algorithme de jeu intelligent qui m�ne l�ordinateur syst�matiquement � la victoire. 

L��tape ultime du travail sera d�afficher un menu principal qui offre 4 choix :
1)	Jeu niveau FACILE :l�ordinateur choisit ses coups de fa�on al�atoire
2)	Jeu niveau MOYEN  :l�ordinateur choisit ses coups de fa�on al�atoire une fois sur deux et
autrement choisit ses coups de fa�on intelligente avec l�algorithme.
3)	Jeu niveau DIFFICILE  :l�ordinateur choisit tous ses coups de fa�on intelligente avec l�algorithme.
4)	Quitter :on quitte la boucle principale

*/

/*===========================================================================*/
/*                            Librairies usuelles                            */
/*===========================================================================*/

#include<stdio.h>
#include"nim_io.h"
#include"m_distributions.h"
#include"nim_test.h"

/*===========================================================================*/
/*                                 Main                                      */
/*===========================================================================*/

int main(void)
{
	md_srand_interne();// pour la fonction md_randf (initialise un nouveau nombre de d�part)

	//jeu de nim
	test_partie1(); 

	getchar(); //pause
	return 0;
}