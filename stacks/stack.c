#include <stdio.h>
#include "stack.h"

int main () {
  Tstack *stack = create(), *stack_copy = create(), *stack_pairs = create(), *stack_odds = create();;
  int elem, i;

  for (i = 1; i <= 5; i++) {
    printf ("Insira o valor de info para o elemento da pilha: ");
    scanf ("%d", &elem);
    push (stack, elem);
  }
  // empty(stack) ? printf("Pilha vazia\n") : printf("Pilha não vazia\n");

  // printf ("Elemento %d removido da pilha\n", pop (stack));

  // empty(stack) ? printf("Pilha vazia\n") : printf("Pilha não vazia\n");

  // printf ("++++++++++++ PILHA 1 ++++++++++++\n");
  // print_stack (stack);

  // copy_stack (stack, stack_copy);

  // printf ("++++++++++++ PILHA 2 ++++++++++++\n");
  // print_stack (stack_copy);

  separate_stacks (stack, stack_pairs, stack_odds);

  printf ("++++++++++++ PILHA PADRÃO ++++++++++++\n");
  print_stack (stack);

  printf ("++++++++++++ PILHA DE PARES ++++++++++++\n");
  print_stack (stack_pairs);

  printf ("++++++++++++ PILHA DE IMPARES ++++++++++++\n");
  print_stack (stack_odds);

  clear (stack);
  clear (stack_copy);
  clear (stack_pairs);
  clear (stack_odds);

  return 0;
}