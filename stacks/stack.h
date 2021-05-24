#include <stdlib.h>

typedef struct node {
  int info;
  struct node *next;
} Tnode;

typedef struct stack {
  Tnode *top;
} Tstack;

Tstack *create () {
  Tstack *s = (Tstack *) malloc (sizeof (Tstack));
  s->top = NULL;
  return s;
}

int empty (Tstack *s) {
  return s->top == NULL; // Se verdadeiro, retorna 1, 0 caso contrário
}

void push (Tstack *s, int elem) {
  Tnode *newNode = (Tnode *) malloc (sizeof (Tnode));
  newNode->info = elem;
  newNode->next = s->top;
  s->top = newNode;
}

int pop (Tstack *s) {
  if (empty (s)) {
    exit (1);
  }
  // novo ponteiro que aponta para o topo da pilha
  Tnode *t = s->top;
  // reapontar o topo da pilha para o elemento imediatamente abaixo
  s->top = s->top->next;
  int result = t->info;
  free (t);
  return result;
}

void clear (Tstack *s) {
  Tnode *r = s->top, *t;
  while (r) {
    t = r;        // ponteiro auxiliar t aponta para o ponteiro r, que aponta para o topo da pilha
    r = r->next;  // reaponto o topo para o seu elemento imediatamente abaixo
    free (t);     // liberar a memória de ocupada pelo node t
  }
  free (s);       // liberar a memória da estrutura da pilha
}

void print_stack (Tstack *s) {
  Tstack *t = create();
  int elem, counter = 1;

  while (!empty (s)) {
    push (t, pop (s));
  }
  // Ao fim do while, temos uma cópia invertida da pilha s na pilha t

  while (!empty (t)) {
    elem = pop (t);
    printf ("Elemento %d da pilha = %d\n", counter, elem);
    push (s, elem);
    counter ++;
  }
  // Ao final do while, temos a pilha s repopulada na ordem correta com os seus elementos impressos e a pilha t vazia
  clear (t);
}

void copy_stack (Tstack *s1, Tstack *s2) {
  if (empty (s1)) {
    exit (1);
  }

  if (!empty (s2)) {
    exit (1);
  }

  Tstack *aux = create();
  int elem;

  while (!empty (s1)) {
    push (aux, pop (s1));
  }

  while (!empty (aux)) {
    elem = pop (aux);
    push (s1, elem);
    push (s2, elem);
  }

  clear (aux);
}

void separate_stacks (Tstack *s, Tstack *s_pairs, Tstack *s_odds) {
  Tstack *aux = create();
  int elem;

  while (!empty(s)) {
    push (aux, pop (s));
  }
  // ao fim deste while, a pilha s estará vazia e a aux estará com todos os elementos em ordem inversa

  while (!empty (aux)) {
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

  clear (aux);
}