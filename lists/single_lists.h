#include <stdio.h>
#include <stdlib.h>

typedef struct list {
  int info;
  struct list *next;
} Tlist;

// criaçao de uma lista simples vazia
Tlist *create () {
  return NULL;
}

// Inserção ordenada de elementos em uma lista
Tlist *ordered_insert (Tlist *l, int elem) {
  Tlist *p = l; // ponteiro auxiliar para navegar pela lista (NUNCA MANIPULAR O PONTEIRO RECEBIDO COMO PARÂMETRO)
  Tlist *previous = NULL; // aponta para o elemento anterior ao atual
  Tlist *newElem; // novo elemento da lista a ser inserido

  while (p != NULL && p->info <= elem) {
    previous = p;
    p = p->next;
  }

  newElem = (Tlist *) malloc (sizeof (Tlist)); // alocação de memória do novo elemento
  newElem->info = elem;

  if (previous == NULL) { // lista vazia e inserção do primeiro elemento
    newElem->next = l; // o next do novo elemento aponta para a cabeça da lista (NULL)
    l = newElem; // a cabeça da lista aponta para o novo elemento
  }
  else { // lista não vazia
    newElem->next = p; // ponteiro next do novo elemento aponta para o mesmo lugar que p
    previous->next = newElem; // ponteiro next do previous (anterior) aponta para o novo elemento
  }

  return l;
}

// Imprimir o conteúdo de uma lista
void print_list (Tlist *l) {
  Tlist *p = l;

  while (p != NULL) {
    printf ("%d\n", p->info);
    p = p->next;
  }
}

// Liberar a memória ocupada por uma lista
void clear (Tlist *l) {
  Tlist *p = l;

  while (p) {
    Tlist *q = p;
    p = p->next;
    free (q);
  }
}

// Tlist *search (Tlist *l, int elem);

// Tlist *remove (Tlist *l, int elem);



// Tlist *start_insert (Tlist *l, int elem);
// Tlist *end_insert (Tlist *l, int elem);
// Tlist *start_remove (Tlist *l);
// Tlist *end_remove (Tlist *l);