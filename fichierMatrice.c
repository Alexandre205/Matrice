#include<stdio.h>

#include"FichierMatrice.h"
#include"OperationMatrice.h"
#include"Obtention.h"


Matrice* lireFichierMatrice(void) {
	FILE* fiMatrice;
	char nomFichier[TAILLE_NOM_FICHIER];
	obtenirNomFichier(nomFichier);
	int nbCol;
	int nbLig;
	fopen_s(&fiMatrice, nomFichier, "r");
	if (fiMatrice == NULL) {
		printf("l'ouverture du fichier a foire");
		return NULL;
	}
	fscanf_s(fiMatrice, "%d %d", &nbLig, &nbCol);
	Matrice* newMatrice = initMatrice(nbLig, nbCol);
	for (int iLigne = 0; iLigne < nbCol; iLigne++) {
		for (int iCol = 0; iCol < nbLig; iCol++) {
			fscanf_s(fiMatrice,"%d", &newMatrice->matrice[iLigne][iCol]);
		}
	}
	
	fclose(fiMatrice);
	return newMatrice;
}
void ecrireFichierMatrice(Matrice mat) {
	FILE* fiMatrice;
	char nomFichier[TAILLE_NOM_FICHIER];
	obtenirNomFichier(nomFichier);
	fopen_s(&fiMatrice, nomFichier, "w");
	if (fiMatrice == NULL) {
		printf("l'ouverture du fichier a foire");
		return;
	}
	fprintf(fiMatrice, "%d %d\n\n", mat.nbLig, mat.nbCol);
	for (int iCol = 0; iCol < mat.nbCol; iCol++) {
		for (int iLigne = 0; iLigne < mat.nbLig; iLigne++) {
			fprintf(fiMatrice,"%d ", mat.matrice[iCol][iLigne]);
		}
		fprintf(fiMatrice, "\n");
	}

	fclose(fiMatrice);
}