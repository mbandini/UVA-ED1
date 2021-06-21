#include <stdio.h>
#include "double_linked.h"

#define ELEMENTS 3

int main () {
  int value, i;
  Tdl *list, *s;

  list = create_double_linked ();

  for (i = 1; i <= ELEMENTS; i++) {
    printf ("Insira um elemento: ");
    scanf ("%d", &value);
    list = insert_double_linked (list, value);
  }

  print_double_linked (list);
  printf ("++++++++++++++++++++++\n");

  s = search_double_linked (list, 5);

  if (s) {
    printf ("Elemento %d encontrado\n", s->info);
  }
  else {
    printf ("Elemento não encontrado\n");
  }

  list = remove_elem_double_linked (list, 4);
  print_double_linked (list);
  list = remove_elem_double_linked (list, 5);
  print_double_linked (list);
  list = remove_elem_double_linked (list, 7);
  printf ("++++++++++++++++++++++\n");

  if (list) {
    clear_double_linked (list);
  }

  return 0;
}