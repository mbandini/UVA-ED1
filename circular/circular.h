#include <stdio.h>
#include <stdlib.h>

// Estrutura básica de uma lista circular
typedef struct circular {
  int info;
  struct circular *next;
} Tcl;

// Criar uma nova lista circular vazia
Tcl *create_circular () {
  return NULL;
}



// Inserir um novo elemento na lista circular no início da lista
Tcl *insert_circular (Tcl *l, int elem) {
  Tcl *new_elem = (Tcl *) malloc (sizeof (Tcl));
  new_elem->info = elem;

  if (!l) { // Se a lista estiver vazia e este for o primeiro elemento,
    new_elem->next = new_elem; // o next do primeiro elemento aponta para ele mesmo
    return new_elem;
  }

  new_elem->next = l->next;
  l->next = new_elem;
  return l;
}

// Limpar a lista circular da memória
void clear_circular (Tcl *l) {
  if (l) {
    Tcl *p = l->next;
    while (p != l) {
      Tcl *q = p;
      p = p->next;
      free (q);
    }
    free (p);
  }
}

void print_circular (Tcl *l) {
  if (l) {
    printf ("%d\n", l->info);
    Tcl *p = l->next;
    while (p != l) {
      printf ("%d\n", p->info);
      p = p->next;
    }
  }
}

// Busca por um valor em uma lista circular
Tcl *search_circular (Tcl *l, int elem) {
  if (!l) {
    return NULL;
  }
  if (l->info == elem) {
    return l;
  }

  Tcl *p = l->next;
  while (p != l && p->info != elem) {
    p = p->next;
  }

  if (p == l) {
    return NULL;
  }

  return p;
}

// Remove um elemento da lista circular, caso ele exista
Tcl *remove_circular (Tcl *l, int elem) {
  if (!l) {
    printf ("Lista vazia ou não existe\n");
    return NULL;
  }

  if (l->info == elem && l->next == l) { // o elemento a ser removido é o único presente na lista
    printf ("Elemento %d removido (último elemento existente na lista)\n", l->info);
    free (l);
    return NULL;
  }

  Tcl *p = l->next;
  Tcl *previous = l;

  while (p != l && p->info != elem) {
    previous = p;
    p = p->next;
  }

  if (p == l && p->info != elem) { // voltamos ao início da lista e na encontramos o elemento
    printf ("Elemento a ser removido nao encontrado\n");
    return l;
  }

  if (p == l) { // o elemento a ser removido é o mesmo do início da lista
    l = l->next;
  }

  previous->next = p->next;
  printf ("Elemento %d removido\n", p->info);
  free (p);
  return l;
}