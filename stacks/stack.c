#include <stdio.h>
#include "stack.h"

int main () {
  Tstack *stack = create(), *stack_copy = create();
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

  printf ("++++++++++++ PILHA 1 ++++++++++++\n");
  print_stack (stack);

  copy_stack (stack, stack_copy);

  printf ("++++++++++++ PILHA 2 ++++++++++++\n");
  print_stack (stack_copy);

  clear (stack);
  clear (stack_copy);

  return 0;
}