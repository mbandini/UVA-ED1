#include <stdio.h>
#include <stdlib.h> // necessário para usar as funções de alocação dinâmica

int main () {
  int *v, size;

  printf ("Tamanho do CHAR: %ld byte(s)\n", sizeof(char));

  printf ("Escolha o tamanho do vetor: ");
  scanf ("%d", &size); // supondo que o usuário escolheu 1000

  v = malloc (size * sizeof (int)); // alocação dinâmica de um vetor de tamanho 1000. Equivale a int v[1000];

  // printf ("Tamanho do vetor: %ld\n", sizeof(v)); // A descobrir

  // Se o usuário quiser mudar o tamanho do vetor alocado dinamicamente -> utilizar realloc
  printf ("Escolha o novo tamanho do vetor: ");
  scanf ("%d", &size); // supondo que o usuário escolheu 2000
  v = realloc (v, size * sizeof (int)); // neste caso, o vetor passaria a ter 2000 posições

  free(v); // Libera a memória alocada para o vetor v

  return 0;
}