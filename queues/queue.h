#include <stdlib.h>

// Definição de um nó (elemento) da fila
typedef struct node {
  int info;
  struct node *next;
} Tnode;

// Definição da estrutura da fila
typedef struct queue {
  Tnode *start, *end;
} Tqueue;

// Criação de uma fila vazia
Tqueue *create () {
  Tqueue *q = (Tqueue *) malloc (sizeof(Tqueue));
  q->start = q->end = NULL;
  return q;
}

// Verificar se fila está vazia
int empty (Tqueue *q) {
  return !q->end;
}

// Inserir um elemento na fila
void insert (Tqueue *q, int elem) {
  Tnode *node = (Tnode *) malloc (sizeof(Tnode));
  node->info = elem;
  node->next = NULL;

  // apontar o ponteiro do antigo último elemento para o novo último elemento
  if (q->end) {
    q->end->next = node;
  }

  // andar com o ponteiro de fim da fila
  q->end = node;

  // apontar o ponteiro de início caso a fila esteja vazia
  if (!q->start) {
    q->start = node;
  }
}
