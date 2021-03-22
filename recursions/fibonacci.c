#include <stdio.h>

// 1 1 2 3 5 8 13 21 34
double fibo_rec (double n) { // retorna o elemento n da sequência de Fibonacci
  if (n <= 2) {
    return 1;
  }
  else {
    return fibo_rec (n - 1) + fibo_rec (n - 2);
  }
}

double fibo_ternary (double n) {
  return (n <= 2 ? 1 : fibo_ternary (n - 1) + fibo_ternary (n - 2));
}

double fibo_it (double n) {
  if (n <= 2) {
    return 1;
  }
  double penult = 1, last = 1, current = 2, counter, aux;
  for (counter = 3; counter < n; counter++) {
    aux = last;
    current += last; // current = current + last
    last += penult;
    penult = aux;
  }
  return current;
}

int main () {
  double value;
  printf ("Insira o enésimo elemento de Fibonacci a ser calculado: ");
  scanf ("%lf", &value);

  printf ("FIBONACCI RECURSIVO - ENÉSIMO ELEMENTO: %.0lf\n", fibo_rec(value));
  printf ("FIBONACCI RECURSIVO COM TERNÁRIO - ENÉSIMO ELEMENTO: %.0lf\n", fibo_ternary(value));
  printf ("FIBONACCI ITERATIVO - ENÉSIMO ELEMENTO: %.0lf\n", fibo_it(value));

  return 0;
}