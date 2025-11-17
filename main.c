#include<stdio.h>
#include<stdlib.h>

#include"Obtention.h"
#include"OperationMatrice.h"
#include"Affichage.h"
#include"Operateur.h"
#include"FichierMatrice.h"


void matriceSeul() {
	puts("1.Transposer\n2.Permuter ligne");
	int choixMenu = obtenirNombreValide(0);
	switch (choixMenu) {
	case 1: {
			Matrice* mat = lireFichierMatrice();
			afficherMatrice(*mat);
			mat = transpositionMatrice(*mat);
			afficherMatrice(*mat);
			deleteMatrice(mat);
			break;
		}
		case 2: {
			Matrice* mat = lireFichierMatrice();
			afficherMatrice(*mat);
			puts("Entrez les 2 ligne à permuter");
			int indiceLigne1 = obtenirNombreValide(0);
			int indiceLigne2 = obtenirNombreValide(0);
			*mat = permuterLigne(*mat,indiceLigne1,indiceLigne2);
			afficherMatrice(*mat);
			deleteMatrice(mat);
			break;
		}
		default:puts("Option non prise en compte");
	}
}
void matrices2() {
	puts("1.Operation simple\n2.Multiplication");
	int choixMenu = obtenirNombreValide(0);
	switch (choixMenu) {
		case 1: { 
			puts("Entrez un operateur");
			char caract = obtenirChar();
			int(*operation)(int, int) = choisirOperation(caract);
			if (operation == NULL) {
				puts("Opérateur non pris en charge");
			}
			else {
				Matrice* mat1 = lireFichierMatrice();
				Matrice* mat2 = lireFichierMatrice();
				Matrice matR = operationSimpleInterneSurMatrice(*mat1, *mat2,operation);
				afficherMatrice(matR);
				deleteMatrice(mat1);
				deleteMatrice(mat2);
			}
			break; 
		}
		case 2: { 
			Matrice* mat1 = lireFichierMatrice();
			Matrice* mat2 = lireFichierMatrice();
			Matrice* matR = multiplicationDeMatriceParMatrice(*mat1, *mat2);
			afficherMatrice(*matR);
			deleteMatrice(mat1);
			deleteMatrice(mat2);
			deleteMatrice(matR);
			break; 
		}
		default:puts("Option non prise en compte");
	}
}
void matriceEtNombre() {
	puts("Entrez un opérateur");
	char caract = obtenirChar();
	int(*operation)(int, int) = choisirOperation(caract);
	if (operation == NULL) {
		puts("Opérateur non pris en charge");
	}
	else {
		puts("Entrez un nombre");
		int nombre = obtenirNombreValide(INT_MIN);
		Matrice* mat = lireFichierMatrice();
		Matrice matR = operationSimpleExterneSurMatrice(*mat, nombre, operation);
		afficherMatrice(*mat);
		deleteMatrice(mat);
	}
}
void menuOperation() {
	puts("1.Matrice seul\n2.Matrices entre elles\n3.Matrice avec un nombre");
	int choixMenu = obtenirNombreValide(0);
	switch (choixMenu) {
	case 1:matriceSeul(); break;
	case 2:matrices2(); break;
	case 3:matriceEtNombre(); break;
	default:puts("Option non prise en compte");
	}
}
void main(void) {
	int choixMenu = 0;
	puts("Bienvenu sur matrice.exe");
	while (choixMenu != 4) {
		puts("Que voulez vous faire?\n1.Afficher une matrice\n2.Encoder une matrice\n3.Faire des opérations sur des matrices\n4.Quitter");
		choixMenu = obtenirNombreValide(0);
		switch (choixMenu) {
			case 1: {
				Matrice* mat = lireFichierMatrice();
				afficherMatrice(*mat);
				deleteMatrice(mat);
				break;
			}
			case 2: { 
				Matrice* mat = obtenirMatrice();
				afficherMatrice(*mat);
				ecrireFichierMatrice(*mat);
				deleteMatrice(mat);
				break; 
			}
			case 3:menuOperation(); break;
			case 4:break;
			default:puts("Option non prise en charge");
		}
	}
}