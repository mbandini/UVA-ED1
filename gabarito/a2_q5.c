#include <stdio.h>
#include <time.h>
#include "stack.h"
#include "single_lists.h"

#define ELEMENTS 10

void imprime_invertido (Tlist *l) {
  Tlist *p = l;
  Tstack *stack = create_stack ();

  while (p) {
    push (stack, p->info);
    p = p->next;
  }

  while (!empty_stack (stack)) {
    printf ("%d\n", pop (stack));
  }

  clear_stack (stack);
}


int main() {
  int elem, i, sum = 0;
  Tlist *l = create ();
  time_t t;
  srand((unsigned) time(&t));

  for (i = 1; i <= ELEMENTS; i++) {
    l = ordered_insert (l, rand () % 20);
  }

  printf ("IMPRIMINDO LISTA:\n");
  print_list (l);

  printf ("IMPRIMINDO LISTA IMVERTIDA:\n");
  imprime_invertido (l);

  clear (l);

  return 0;
}