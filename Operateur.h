#ifndef OPERATEUR_H
#define OPERATEUR_H
int add(int nb1, int nb2);
int sous(int nb1, int nb2);
int mult(int nb1, int nb2);
int divi(int nb1, int nb2);
int modulo(int nb1, int nb2);
void echange(int* nb1, int* nb2);
int (*choisirOperation(char operateur))(int, int);
#endif // !OPERATEUR_H