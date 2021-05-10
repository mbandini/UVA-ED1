#include <stdio.h>
#include "stack.h"

int main () {
  Tstack *stack = create();
  int elem;

  printf ("Insira o valor de info para o elemento da pilha: ");
  scanf ("%d", &elem);
  push (stack, elem);
  printf ("Insira o valor de info para o elemento da pilha: ");
  scanf ("%d", &elem);
  push (stack, elem);
  printf ("Insira o valor de info para o elemento da pilha: ");
  scanf ("%d", &elem);
  push (stack, elem);

  empty(stack) ? printf("Pilha vazia\n") : printf("Pilha não vazia\n");

  // printf ("Elemento %d removido da pilha\n", pop (stack));

  empty(stack) ? printf("Pilha vazia\n") : printf("Pilha não vazia\n");

  print_stack (stack);

  clear (stack);

  return 0;
}