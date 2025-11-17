#include<stdio.h>
#include<stdlib.h>

#include"Operateur.h"
#include"OperationMatrice.h"
Matrice errorMatrice() {
	Matrice errorMat = { -1,-1 };
	return errorMat;
}

Matrice permuterLigne(Matrice matrice, int indiceLigne1, int indiceLigne2) {
	if (indiceLigne1 >= matrice.nbCol || indiceLigne2 >= matrice.nbCol) {
		printf("La permutation est impossible car l'un des indice renseigné est hors limite de la matrice");
		return errorMatrice();
	}
	for (int i = 0; i < matrice.nbLig; i++) {
		echange(&matrice.matrice[indiceLigne1][i], &matrice.matrice[indiceLigne2][i]);
	}
	return matrice;
}
Matrice* transpositionMatrice(Matrice matrice) {
	Matrice *newMat = initMatrice(matrice.nbCol, matrice.nbLig);
	for (int i = 0; i < newMat->nbLig; i++) {
		for (int j = 0; j < newMat->nbCol; j++) {
			newMat->matrice[j][i] = matrice.matrice[i][j];
		}
	}
	return newMat;
}

Matrice* multiplicationDeMatriceParMatrice(Matrice mat1, Matrice mat2) {
	if (mat1.nbCol != mat2.nbLig) {
		printf("Les 2 matrice ne peuvent pas etre multilpliees entre elles");
		return NULL;
	}
	Matrice* newMatrice = initMatrice(mat1.nbLig, mat2.nbCol);
	if (newMatrice == NULL) {
		return NULL;
	}
	for (int i = 0; i < mat1.nbLig; i++) {
		for (int j = 0; j < mat2.nbCol; j++) {
			for (int k = 0; k < mat1.nbCol; k++) {
				newMatrice->matrice[i][j] += mat1.matrice[i][k] * mat2.matrice[k][j];
			}
		}
	}
	return newMatrice;
}
Matrice operationSimpleInterneSurMatrice(Matrice mat1, Matrice mat2,int(*operation)(int,int)) {
	if (mat1.nbLig != mat2.nbLig || mat1.nbCol != mat2.nbCol) {
		printf("La taille des 2 matrice diffère, impossible de faire le calcule demandé");
		return errorMatrice();
	}
	for (int iColonne = 0; iColonne < mat2.nbLig; iColonne++) {
		for (int iLigne = 0; iLigne < mat2.nbCol; iLigne++) {
			mat1.matrice[iColonne][iLigne] = operation(mat1.matrice[iColonne][iLigne], mat2.matrice[iColonne][iLigne]);
		}
	}
	return mat1;
}
Matrice operationSimpleExterneSurMatrice(Matrice mat, int nombre, int(*operation)(int, int)){
	for (int iColonne = 0; iColonne < mat.nbLig; iColonne++) {
		for (int iLigne = 0; iLigne < mat.nbCol; iLigne++) {
			mat.matrice[iColonne][iLigne] = operation(mat.matrice[iColonne][iLigne], nombre);
		}
	}
	return mat;
}
Matrice* initMatrice(int nbLigne, int nbCol) {

	// allouer la memoire pour la structure Matrice
	Matrice* newMatrice = (Matrice*)malloc(sizeof(Matrice));
	if (newMatrice == NULL) {
		printf("L'allocation de la memoire a foire");
		return NULL;
	}
	newMatrice->nbCol = nbCol;
	newMatrice->nbLig = nbLigne;

	// allouer la memoire de la 1ere colonne
	newMatrice->matrice = (int**)calloc(nbCol, sizeof(int*));
	if (newMatrice->matrice == NULL) {
		printf("L'allocation de la memoire a foire");
		return NULL;
	}

	// allouer la memoire de chaque ligne
	for (int i = 0; i < nbCol; i++) {
		newMatrice->matrice[i] = (int*)calloc(nbLigne,sizeof(int));
		if (newMatrice->matrice[i] == NULL) {
			printf("L'allocation de la memoire a foire");
			return NULL;
		}
	}
	return newMatrice;
}
void deleteMatrice(Matrice* matrice) {
	for (int i = 0; i < matrice->nbCol; i++) {
		free(matrice->matrice[i]);
		matrice->matrice[i] = NULL;
	}
	free(matrice->matrice);
	matrice->matrice = NULL;
	matrice->nbCol = 0;
	matrice->nbLig = 0;
}
void placeNombreDansCase(Matrice* matrice, int iCol, int iLigne, int nombreAPlacer) {
	if (matrice->nbLig < iCol || matrice->nbCol < iLigne) {
		printf("La case specifie est hors de la matrice");
	}
	else {
		matrice->matrice[iCol][iLigne] = nombreAPlacer;
	}
}