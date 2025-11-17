#ifndef FICHIER_MATRICE_H
#define FICHIER_MATRICE_H

#include"OperationMatrice.h"

#define TAILLE_NOM_FICHIER 15
#define DEBUT_NOM_FICHIER "matrice"
#define EXTENSIONT_FICHIER ".txt\n"

Matrice* lireFichierMatrice(void);
void ecrireFichierMatrice(Matrice mat);
#endif // !FICHIER_MATRICE_H