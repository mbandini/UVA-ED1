#include <stdio.h>
#include <stdlib.h>

int *new_vector (int size) {
  int *vector;
  vector = malloc(size * sizeof(int));
  return vector;
}

int *resize_vector (int *v, int size) {
  v = realloc(v, size * sizeof(int));
  return v;
}

void populate_vector (int *v, int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf ("Insira a posição %d do vetor: ", i);
    scanf ("%d", &v[i]);
  }
}

void fill_vector (int *v, int size, int new_size) {
  int i;
  for (i = size; i < new_size; i++) {
    printf ("Insira a posição %d do vetor: ", i);
    scanf ("%d", &v[i]);
  }
}

void print_vector (int *v, int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf ("Elemento %d do vetor: %d\n", i, v[i]);
  }
}

int main () {
  int matrix[3][4];
  int *v, size, new_size;
  printf ("Escolha o tamanho do vetor: ");
  scanf ("%d", &size);

  v = new_vector(size);

  populate_vector(v, size);
  print_vector(v, size);

  printf ("Escolha o novo tamanho do vetor: ");
  scanf ("%d", &new_size);

  printf ("\n----------------------------------------------------------------\n");
  v = resize_vector(v, new_size);
  fill_vector(v, size, new_size);
  print_vector(v, new_size);

  free(v);

  return 0;
}