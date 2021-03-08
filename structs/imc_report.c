/*
DADO UM VETOR DE 3 PESSOAS, CALCULE O IMC MÉDIO DE TODAS ELAS E IDENTIFIQUE A IDADE DAQUELE QUE POSSUI O
MENOR IMC E DAQUELE QUE POSSUI O MAIOR IMC
*/
#include <stdio.h>
#include <math.h>
#include "structs.h"
#define POPULATION 3

int main() {
  Person People[POPULATION];
  int i;
  float avg_imc = 0, imc;
  int index_max_imc = 0, index_min_imc = 0;

  printf("Insira a idade da pessoa 1: ");
  scanf("%d", &People[0].age);
  printf("Insira a altura da pessoa 1: ");
  scanf("%f", &People[0].height);
  printf("Insira o peso da pessoa 1: ");
  scanf("%f", &People[0].weight);
  imc = People[0].weight / pow(People[0].height, 2);
  printf("IMC da pessoa 1: %f\n", imc);
  avg_imc = imc;

  for (i = 1; i < POPULATION; i++) {
    printf("Insira a idade da pessoa %d: ", i + 1);
    scanf("%d", &People[i].age);
    printf("Insira a altura da pessoa %d: ", i + 1);
    scanf("%f", &People[i].height);
    printf("Insira o peso da pessoa %d: ", i + 1);
    scanf("%f", &People[i].weight);
    imc = People[i].weight / pow(People[i].height, 2);
    printf("IMC da pessoa %d: %f\n", i + 1, imc);
    avg_imc += imc; // avg_imc = avg_imc + imc

    if (People[i].weight / pow(People[i].height, 2) > People[index_max_imc].weight / pow(People[index_max_imc].height, 2)) {
      index_max_imc = i;
    }

    if (People[i].weight / pow(People[i].height, 2) < People[index_max_imc].weight / pow(People[index_max_imc].height, 2)) {
      index_min_imc = i;
    }
  }

  printf ("O IMC médio é: %f\n", avg_imc / POPULATION);
  printf ("A idade da pessoa com maior IMC é %d\n", People[index_max_imc].age);
  printf ("A idade da pessoa com menor IMC é %d\n", People[index_min_imc].age);

  return 0;
}