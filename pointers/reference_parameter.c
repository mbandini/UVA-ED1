//Exemplo passagem de parâmetro por referência:
#include <stdio.h>

int func (int *a) {
	// printf("%d", *a); // 10
	*a = 20;
	int b = 15;
	return *a + b; // função retorna 35
}

int main () {
	int value = 10;
	printf ("PRINT 1: %d\n", value); // 10
	int result = func (&value); // passa o endereço de memória da variável value como parâmetro (passagem por referência)
	printf ("PRINT 2: %d\n", value); // 20

	return 0;
}