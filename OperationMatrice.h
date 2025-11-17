#ifndef MATRICE_H
#define MATRICE_H

typedef struct matrice Matrice;
struct matrice {
	int nbCol;
	int nbLig;
	int** matrice;
};
Matrice* initMatrice(int nbLig, int nbCol);
void deleteMatrice(Matrice* matrice);


Matrice operationSimpleExterneSurMatrice(Matrice mat, int nombre, int(*operation)(int, int));

Matrice operationSimpleInterneSurMatrice(Matrice mat1, Matrice mat2, int(*operation)(int, int));
Matrice* multiplicationDeMatriceParMatrice(Matrice mat1, Matrice mat2);

Matrice* transpositionMatrice(Matrice matrice);
Matrice permuterLigne(Matrice matrice, int indiceLigne1, int indiceLigne2);

void placeNombreDansCase(Matrice* matrice, int iCol, int iLigne, int nombreAPlacer);


#endif // !MATRICE_H