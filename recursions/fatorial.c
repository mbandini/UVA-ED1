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

int main () {
  double value;
  printf ("Insira o valor para cálculo do fatorial: ");
  scanf ("%lf", &value);

  printf ("FATORIAL COM RECURSÃO SEM TERNÁRIO: %.0lf\n", fat_rec(value));
  printf ("FATORIAL COM RECURSÃO COM TERNÁRIO: %.0lf\n", fat_ternary(value));
  printf ("FATORIAL ITERATIVO: %.0lf\n", fat_it(value));

  return 0;
}