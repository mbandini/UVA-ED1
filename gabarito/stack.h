#include <stdlib.h>
#include <stdio.h>

typedef struct stack_node {
  int info;
  struct stack_node *next;
} Tstack_node;

typedef struct stack {
  Tstack_node *top;
} Tstack;

Tstack *create_stack () {
  Tstack *s = (Tstack *) malloc (sizeof (Tstack));
  s->top = NULL;
  return s;
}

int empty_stack (Tstack *s) {
  return s->top == NULL; // Se verdadeiro, retorna 1, 0 caso contrário
}

void push (Tstack *s, int elem) {
  Tstack_node *newNode = (Tstack_node *) malloc (sizeof (Tstack_node));
  newNode->info = elem;
  newNode->next = s->top;
  s->top = newNode;
}

int pop (Tstack *s) {
  if (empty_stack (s)) {
    exit (1);
  }
  // novo ponteiro que aponta para o topo da pilha
  Tstack_node *t = s->top;
  // reapontar o topo da pilha para o elemento imediatamente abaixo
  s->top = s->top->next;
  int result = t->info;
  free (t);
  return result;
}

void clear_stack (Tstack *s) {
  Tstack_node *r = s->top, *t;
  while (r) {
    t = r;        // ponteiro auxiliar t aponta para o ponteiro r, que aponta para o topo da pilha
    r = r->next;  // reaponto o topo para o seu elemento imediatamente abaixo
    free (t);     // liberar a memória de ocupada pelo node t
  }
  free (s);       // liberar a memória da estrutura da pilha
}

void print_stack (Tstack *s) {
  Tstack *t = create_stack();
  int elem, counter = 1;

  while (!empty_stack (s)) {
    push (t, pop (s));
  }
  // Ao fim do while, temos uma cópia invertida da pilha s na pilha t

  while (!empty_stack (t)) {
    elem = pop (t);
    printf ("Elemento %d da pilha = %d\n", counter, elem);
    push (s, elem);
    counter ++;
  }
  // Ao final do while, temos a pilha s repopulada na ordem correta com os seus elementos impressos e a pilha t vazia
  clear_stack (t);
}

void copy_stack (Tstack *s1, Tstack *s2) {
  if (empty_stack (s1)) {
    exit (1);
  }

  if (!empty_stack (s2)) {
    exit (1);
  }

  Tstack *aux = create_stack();
  int elem;

  while (!empty_stack (s1)) {
    push (aux, pop (s1));
  }

  while (!empty_stack (aux)) {
    elem = pop (aux);
    push (s1, elem);
    push (s2, elem);
  }

  clear_stack (aux);
}

void separate_stacks (Tstack *s, Tstack *s_pairs, Tstack *s_odds) {
  Tstack *aux = create_stack();
  int elem;

  while (!empty_stack(s)) {
    push (aux, pop (s));
  }
  // ao fim deste while, a pilha s estará vazia e a aux estará com todos os elementos em ordem inversa

  while (!empty_stack (aux)) {
    elem = pop (aux);
    push (s, elem);
    if (elem % 2 == 0) {
      push (s_pairs, elem);
    }
    else {
      push (s_odds, elem);
    }
  }
  // ai fim do while, a pilha s está como antes, a s_odds com os ímpares, a s_pairs com os pares e a aux está vazia

  clear_stack (aux);
}