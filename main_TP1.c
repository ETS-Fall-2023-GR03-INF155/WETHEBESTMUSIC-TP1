/*===========================================================================*/

#define _CRT_SECURE_NO_WARNINGS

/*===========================================================================*/

/*
Nom : Noah Tremblay et Justin Martel 
Code Permanant: TREN85330401 et ...
Cours : INF155
Projet: Jeux de Nim
Description:

Le jeu de Nim est un jeu très célèbre et probablement un des plus anciens jeux du monde .
Il en existe plusieurs variantes et nous allons mettre en œuvre une de ces variantes dans un programme où 
un joueur humain doit s’opposer à un ordinateur.

Les règles du jeu sont très simples : nous disposons un ensemble de pièces sur plusieurs colonnes. 
Le nombre de pièces et leur disposition en colonnes se fait aléatoirement. Dans notre cas, nous nous limiterons à un maximum de 20 colonnes 
et un maximum de 35 pièces par colonne.

Le joueur commence par décider combien de colonnes il souhaite avoir dans le plateau du jeu. 
Un ensemble de pièces par colonne est alors déterminé aléatoirement. L’exemple ci-contre présente une configuration du jeu à 7 colonnes.
Ensuite le joueur et l’ordinateur jouent tour à tour (c’est toujours le joueur qui va commencer), chacun choisissant une colonne et le 
nombre de pièces à retirer de cette colonne (minimum une pièce, maximum toutes les pièces de la colonne). Le jeu se poursuit
jusqu’à ce que la dernière pièce soit retirée, et le joueur l’ayant retirée sera déclaré gagnant.

Afin de simplifier le projet, nous le réaliserons en deux parties :
a)	Le programme permettant de jouer contre un ordinateur qui choisit ses coups de façon aléatoire;
b)	Compléter la partie (a) en implémentant un algorithme de jeu intelligent qui mène l’ordinateur systématiquement à la victoire. 

L’étape ultime du travail sera d’afficher un menu principal qui offre 4 choix :
1)	Jeu niveau FACILE :l’ordinateur choisit ses coups de façon aléatoire
2)	Jeu niveau MOYEN  :l’ordinateur choisit ses coups de façon aléatoire une fois sur deux et
autrement choisit ses coups de façon intelligente avec l’algorithme.
3)	Jeu niveau DIFFICILE  :l’ordinateur choisit tous ses coups de façon intelligente avec l’algorithme.
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
	md_srand_interne();// pour la fonction md_randf (initialise un nouveau nombre de départ)

	//jeu de nim
	test_partie1(); 

	getchar(); //pause
	return 0;
}