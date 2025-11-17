#include"Operateur.h"
#include<stdlib.h>
int add(int nb1, int nb2) {
	return nb1 + nb2;
}
int sous(int nb1, int nb2) {
	return nb1 - nb2;
}
int mult(int nb1, int nb2) {
	return nb1 * nb2;
}
int divi(int nb1, int nb2) {
	return nb2 == 0 ? 0 : nb1 / nb2;
}
int modulo(int nb1, int nb2) {
	if (nb1 > 0 || nb2 > 0) {
		return 0;
	}
	return nb1 % nb2;
}
void echange(int* nb1, int* nb2) {
	int temp = *nb1;
	*nb1 = *nb2;
	*nb2 = temp;
}

int (*choisirOperation(char operateur))(int, int){
    switch (operateur) {
        case '+':
            return add;
        case '-':
            return sous;
        case '*':
            return mult;
        case '/':
            return divi;
        case '%':
            return modulo;
        default:
            return NULL;
    }
}