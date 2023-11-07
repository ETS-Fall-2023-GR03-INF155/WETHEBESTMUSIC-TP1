/*===========================================================================*/

#define _CRT_SECURE_NO_WARNINGS

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
	md_srand_interne();// pour la fonction md randf (initialise un nouveau nombre de départ)

	printf("\nTEST 1 ET 2\n");
	test_Partie1_2();


	getchar();
	return 0;
}