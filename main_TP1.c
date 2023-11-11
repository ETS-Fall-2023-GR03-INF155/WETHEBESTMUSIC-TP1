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
	md_srand_interne();// pour la fonction md_randf (initialise un nouveau nombre de départ)

	test_partie1();

	test_partie1();
	getchar();
	return 0;
}