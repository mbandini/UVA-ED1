#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ELEMENTS 10
#define SEARCH_ELEMENTS 3

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

// Busca linear (não recursiva) por um elemento na lista
Tlist *search (Tlist *l, int elem) {
  Tlist *p = l; // ponteiro auxiliar apontando para a cabeça da lista

  while (p) { // enquanto tivermos elementos na lista
    if (p->info != elem) {
      p = p->next; // se o elemento atual for diferente daquele buscado, anda para o próximo
    }
    else {
      return p; // retorna o elemento da lista assim que ele é encontrado
    }
  }

  return p; // só será executado se o elemento não estiver na lista
}

// Remover um determinado elemento da lista
Tlist *remove_elem (Tlist *l, int elem) {
  // Tlist *previous = NULL, *p = l;
  Tlist *previous = l, *p = l->next;

  while ((p != NULL)  && (p->info != elem)) { // andando na lista até ela acabar ou até encontrar o elemento
    previous = p;
    p = p->next;
  }

  if (!p) { // p aponta para NULL, ou seja, o fim da lista foi alcançado
    printf ("O elemento %d não está na lista\n", elem);
    return l; // retorno a própria lista original sem remover nenhum elemento
  }

  if (!previous) { // significa que o elemento a ser removido foi encontrado na primeira posição da lista
    l = l->next; // cabeça da lista apronta para o segund elemento
  }
  else {
    previous->next = p->next; // o anterior aponta para o elemento seguinte ao elemento p
  }

  printf ("Elemento %d removido da lista\n", p->info);
  free (p);
  return l;
}

// Exercício 1
void random_draw () {
  Tlist *list = create (), *found = NULL;
  int i, r;
  time_t t;

  // Inicializar o gerador de números pseudo-aleatório
  srand((unsigned) time(&t));

  for (i = 1; i <= NUM_ELEMENTS; i++) {
    list = ordered_insert (list, rand () % 20);
  }

  printf ("Lista criada com os seguintes elementos:\n");
  print_list (list);
  printf ("\n++++++++++++++++++++++++++++++++++++++++++++\n");

  i = 1;
  do {
    r = rand () % 20;
    found = search (list, r);
    if (found) {
      printf ("Valor %d encontrado na lista\n", found->info);
      remove_elem (list, found->info);
      found = NULL;
      i++;
    }
    else {
      printf ("Valor %d não encontrado na lista\n", r);
    }
  } while (i <= SEARCH_ELEMENTS);
  printf ("\nPROGRAMA ENCERRADO\n");

  clear (found);
  clear (list);
}

// Tlist *start_insert (Tlist *l, int elem);
// Tlist *end_insert (Tlist *l, int elem);
// Tlist *start_remove (Tlist *l);
// Tlist *end_remove (Tlist *l);