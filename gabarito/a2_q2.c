#include <stdio.h>
#include <time.h>
#include "stack.h"
#include "queue.h"

#define ELEMENTS 5

Tstack *Fila2Pilha (Tqueue *f) {
  Tstack *aux_stack = create_stack ();
  Tqueue *aux_queue = create_queue ();
  int elem;

  while (!empty_queue (f)) {
    elem = remove_node (f);
    push (aux_stack, elem);
    insert_queue (aux_queue, elem);
  }

  while (!empty_queue (aux_queue)) {
    elem = remove_node (aux_queue);
    insert_queue (f, elem);
  }

  clear_queue (aux_queue);

  return aux_stack;
}


int main() {
  int elem, i, sum = 0;
  Tqueue *f = create_queue ();
  Tstack *p;
  time_t t;
  srand((unsigned) time(&t));

  for (i = 1; i <= ELEMENTS; i++) {
    elem = rand () % 20;
    insert_queue (f, elem);
  }

  printf ("IMPRIMINDO FILA ORIGINAL:\n");
  print_queue (f);
  p = Fila2Pilha (f);

  printf ("IMPRIMINDO APÓS CHAMADA:\n");
  print_queue (f);

  printf ("IMPRIMINDO PILHA RETORNADA:\n");
  print_stack (p);

  clear_queue (f);
  clear_stack (p);

  return 0;
}