#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#include"FichierMatrice.h"

void obtenirNomFichier(char nomFichier[TAILLE_NOM_FICHIER]) {
	strcpy_s(nomFichier, TAILLE_NOM_FICHIER, DEBUT_NOM_FICHIER);
	char numeroFichier;
	printf("Numero du fichier(de 1 a 9) : ");
	scanf_s("%c", &numeroFichier, 1);
	getchar();
	strncat_s(nomFichier, TAILLE_NOM_FICHIER, &numeroFichier,1);
	strncat_s(nomFichier, TAILLE_NOM_FICHIER, EXTENSIONT_FICHIER,4);
}
int obtenirNombreValide(int limiteInf) {
	int nombre;
	scanf_s("%d", &nombre);
	while (nombre < limiteInf) {
		printf("Erreur, entrez un nombre superieur a %d ", limiteInf);
		scanf_s("%d", &nombre);
	}
	getchar();
	return nombre;
}
char obtenirChar() {
	char caracter;
	scanf_s("%c", &caracter,1);
	getchar();
	return caracter;
}
Matrice* obtenirMatrice() {
	puts("Entrez le nombre de ligne");
	int nbCol = obtenirNombreValide(0);
	puts("Entrez le nombre colonne");
	int nbLigne = obtenirNombreValide(0);
	Matrice* matrice = initMatrice(nbLigne, nbCol);
	for (int iCol = 0; iCol < nbCol; iCol++) {
		for (int iLigne = 0; iLigne < nbLigne; iLigne++) {
			matrice->matrice[iCol][iLigne] = obtenirNombreValide(INT_MIN);
		}
	}
	return matrice;
}