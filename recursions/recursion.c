#include <stdio.h>

double fat_rec (double n) {
  if (n <= 1) {
    return 1;
  }
  else {
    return n * fat_rec(n - 1);
  }
}

double fat_ternary (double n) {
  return (n <= 1 ? 1 : n * fat_ternary (n - 1)); // representação ternário de um if/else
}

double fat_it (double n) {
  double res = 1;
  int counter;
  for (counter = n; counter > 1; counter--) {
    res *= counter;
  }
  return res;
}

// 1 1 2 3 5 8 13 21 34
double fibo_rec (double n) { // retorna o elemento n da sequência de Fibonacci
  if (n <= 2) {
    return 1;
  }
  else {
    return fibo_rec (n - 1) + fibo_rec (n - 2);
  }
}

int main () {
  double value;
  printf ("Insira o valor para cálculo do fatorial e para o enésimo Fibonacci: ");
  scanf ("%lf", &value);

  printf ("FATORIAL COM RECURSÃO SEM TERNÁRIO: %lf\n", fat_rec(value));
  printf ("FATORIAL COM RECURSÃO COM TERNÁRIO: %lf\n", fat_ternary(value));
  printf ("FATORIAL ITERATIVO: %lf\n", fat_it(value));
  printf ("FIBONACCI RECURSIVO - ENÉSIMO ELEMENTO: %lf\n", fibo_rec(value));

  return 0;
}