//Exemplo passagem de parâmetro por valor:
#include <stdio.h>

int func (int a) {
	// printf("%d", *a); // 10
	a = 20;
	int b = 15;
	return a + b; // função retorna 35
}

int main () {
	int value = 10;
	printf ("PRINT 1: %d\n", value); // 10
	int result = func (value); // passa o valor contido na variável value como parâmetro (passagem por valor)
	printf ("PRINT 2: %d\n", value); // 10

	return 0;
}