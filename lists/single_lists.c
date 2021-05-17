#include <stdio.h>
#include "single_lists.h"

int main () {
  int value, i;
  Tlist *list;

  list = create();

  for (i = 1; i <= 4; i++) {
    printf ("Insira um elemento: ");
    scanf ("%d", &value);
    list = ordered_insert (list, value);
    print_list (list);
    printf ("++++++++++++++++++++++\n");
  }

  clear (list);

  return 0;
}