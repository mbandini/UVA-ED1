#include <stdio.h>
#include <time.h>
#include "circular.h"
#include "single_lists.h"

#define ELEMENTS 10

Tcl *gera_circular (Tlist *l) {
  Tcl *circular_list = create_circular ();
  Tlist *p = l;

  while (p) {
    circular_list = insert_circular (circular_list, p->info);
    p = p->next;
  }

  return circular_list;
}


int main() {
  int elem, i, sum = 0;
  Tlist *l = create ();
  Tcl *circular_list;
  time_t t;
  srand((unsigned) time(&t));

  for (i = 1; i <= ELEMENTS; i++) {
    l = ordered_insert (l, rand () % 20);
  }

  printf ("IMPRIMINDO LISTA ENCADEADA:\n");
  print_list (l);

  circular_list = gera_circular (l);
  printf ("IMPRIMINDO LISTA CIRCULAR:\n");
  print_circular (circular_list);

  clear (l);
  clear_circular (circular_list);

  return 0;
}