#include <stdio.h>
#include <stdlib.h>

typedef struct tdl {
  int info;
  struct tdl *next;
  struct tdl *previous;
} Tdl;

// criaçao de uma lista duplamente encadeada vazia
Tdl *create_double_linked () {
  return NULL;
}

// Inserção ordenada de elementos em uma lista duplamente encadeada
Tdl *insert_double_linked (Tdl *l, int elem) {
  Tdl *p = l;
  Tdl *newElem;

  newElem = (Tdl *) malloc (sizeof (Tdl));
  newElem->info = elem;
  newElem->next = l;
  newElem->previous = NULL;

  if (l) {
    l->previous = newElem;
  }

  return newElem;
}

// Imprimir o conteúdo de uma lista duplamente encadeada (ida e volta)
void print_double_linked (Tdl *l) {
  Tdl *p = l;

  while (p->next != NULL) {
    printf ("%d\n", p->info);
    p = p->next;
  }

  while (p != NULL) {
    printf ("%d\n", p->info);
    p = p->previous;
  }
}

// Liberar a memória ocupada por uma lista duplamente encadeada (partindo do início)
void clear_double_linked (Tdl *l) {
  Tdl *p = l;

  while (p) {
    Tdl *q = p;
    p = p->next;
    free (q);
  }
}

// Busca por um elemento na lista duplamente encadeada (a partir do início)
Tdl *search_double_linked (Tdl *l, int elem) {
  Tdl *p = l;

  while (p) {
    if (p->info != elem) {
      p = p->next;
    }
    else {
      return p;
    }
  }

  return p;
}

// Remover um determinado elemento da lista duplamente encadeada (a partir do início)
Tdl *remove_elem_double_linked (Tdl *l, int elem) {
  // Tdl *previous = l, *p = l->next;
  Tdl *previous = NULL, *p = l;

  while ((p != NULL)  && (p->info != elem)) { // elemento não é o atual
    previous = p;
    p = p->next;
  }

  if (!p) {
    printf ("O elemento %d não está na lista\n", elem);
    return l;
  }

  if (!previous) { // significa que o elemento a ser removido foi encontrado na primeira posição da lista
    l = l->next; // cabeça da lista apronta para o segundo elemento
  }
  else {
    previous->next = p->next; // o anterior aponta para o elemento seguinte ao elemento p
    if (p->next) { // condição para remover elementos, exceto o último da lista
      p->next->previous = previous; // o ponteiro anterior do próximo elemento aponta para o elemento anterior
    }
  }

  printf ("Elemento %d removido da lista\n", p->info);
  free (p);
  return l;
}