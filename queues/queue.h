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

// Remover um elemento na fila
int remove_node (Tqueue *q) {
  if (empty (q)) {
    exit (1);
  }

  // ponteiro q->start aponta para o primeiro elemento da fila
  int value = q->start->info;

  // criar um novo ponteiro nó que aponta para o primeiro elemento da fila, que será removido
  Tnode *p = q->start;

  // andar com o ponteiro de início da fila para o próximo elemento
  q->start = q->start->next;

  // apontar o ponteiro de fim da fila para NULL, caso o elemento a ser removido sea o último restante
  if (!q->start) {
    q->end = NULL;
  }

  // liberar a memória do elemento removido da fila
  free (p);

  return value;
}

// Limpar uma fila e liberar a sua memória e dos seus elementos
void clear (Tqueue *q) {
  Tnode *p = q->start, *aux;

  // enquanto existirem elementos na fila
  while (p) {
    aux = p;        // utilizar o auxiliar para não perder o apontamento
    p = aux->next;  // caminhar com o ponteiro p
    free (aux);     // liberar a memória o elemento em questão da fila
  }
  free (q);         // liberar a memória da fila
}

// Imprimir os elementos da fila passada como parâmetro
void print_queue (Tqueue *q) {
  Tqueue *p;
  p = create();
  int value;

  while (!empty(q)) {
    value = remove_node (q);
    printf ("%d  ", value);
    insert (p, value);
  }

  while (!empty(p)) {
    value = remove_node (p);
    insert (q, value);
  }
  printf ("\n\n");

  clear (p);
}