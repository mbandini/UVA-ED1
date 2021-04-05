#include <stdio.h>

int main () {
  char name[50];
  printf("Insira o nome: ");
  scanf("%[A-Z a-z 0-9]", name);

  printf("%s\n", name);
  return 0;
}