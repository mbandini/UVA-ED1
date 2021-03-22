#include <stdio.h>
#define N 5

int recursive_sum (int *vet, int size) {
  if (size < 1) {
    return 0;
  }
  else if (size == 1) {
    return vet[0];
  }
  else {
    return vet[size - 1] + recursive_sum(vet, size - 1);
  }
}

// É POSSÍVEL TRANSFORMAR A FUNÇÃO ACIMA EM UMA FUNÇAO RECURSIVA COM TERNÁRIOS?
int recursive_sum_ternary (int *vet, int size) {
  return (size < 1 ? 0 : (size == 1 ? vet[0] : vet[size - 1] + recursive_sum(vet, size - 1)));
}


int main () {
  int vet[N] = {3, 7, 14, 1, 4};
  printf ("SOMA RECURSIVA DO VETOR = %d\n", recursive_sum(vet, N));
  printf ("SOMA RECURSIVA DO VETOR COM TERNÁRIO = %d\n", recursive_sum_ternary(vet, N));
  return 0;
}