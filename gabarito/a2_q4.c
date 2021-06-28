#include <stdio.h>
#include <time.h>
#include "single_lists.h"

#define DRAWED_NUMBERS 6
#define TOTAL_NUMBERS 60

void mega_sena () {
  Tlist *list = create (), *drawed = create (), *found = NULL;
  int i, r;
  time_t t;

  // Inicializar o gerador de números pseudo-aleatório
  srand((unsigned) time(&t));

  for (i = 1; i <= TOTAL_NUMBERS; i++) {
    list = ordered_insert (list, i);
  }

  printf ("NÚMEROS PARA O SORTEIO:\n");
  print_list (list);
  printf ("\n++++++++++++++++++++++++++++++++++++++++++++\n");

  i = 1;
  do {
    r = rand () % 60;
    found = search (list, r);
    if (found) {
      drawed = ordered_insert (drawed, found->info);
      remove_elem (list, found->info);
      found = NULL;
      i++;
    }
  } while (i <= DRAWED_NUMBERS);

  printf ("NÚMEROS NÃO SORTEADOS:\n");
  print_list (list);
  printf ("\n++++++++++++++++++++++++++++++++++++++++++++\n");

  printf ("NÚMEROS SORTEADOS:\n");
  print_list (drawed);
  printf ("\n++++++++++++++++++++++++++++++++++++++++++++\n");

  clear (drawed);
  clear (found);
  clear (list);
}


int main() {
  mega_sena ();
  return 0;
}