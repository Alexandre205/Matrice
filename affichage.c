#include<stdio.h>
#include"Affichage.h"
#include"OperationMatrice.h"
void afficherMatrice(Matrice matrice) {
	for (int iColonne = 0; iColonne < matrice.nbCol; iColonne++) {
		for (int iLigne = 0; iLigne < matrice.nbLig; iLigne++) {
			printf("[%d]", matrice.matrice[iColonne][iLigne]);
		}
		printf("\n");
	}
	printf("\n");
}