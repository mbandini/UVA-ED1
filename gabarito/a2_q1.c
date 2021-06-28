#include <stdio.h>
#include <time.h>
#include "stack.h"

#define ELEMENTS 5

int soma_par (Tstack *p) {
  int sum = 0, elem;
  Tstack *aux = create_stack ();

  while (!empty_stack (p)) {
    elem = pop (p);
    push (aux, elem);
    if (elem % 2 == 0) {
      sum += elem;
    }
  }

  while (!empty_stack (aux)) {
    push (p, pop (aux));
  }

  clear_stack (aux);

  return sum;
}


int main() {
  int elem, i, sum = 0;
  Tstack *p = create_stack ();
  time_t t;
  srand((unsigned) time(&t));

  for (i = 1; i <= ELEMENTS; i++) {
    elem = rand () % 20;
    printf ("Valor empilhado: %d\n", elem);
    push (p, elem);
  }

  printf ("Soma dos pares da pilha: %d\n", soma_par (p));

  clear_stack (p);

  return 0;
}