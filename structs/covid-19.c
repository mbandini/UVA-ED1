/*
Crie uma estrutura que possua:
1 - um código de duas letras que represente um país
2 - o total de casos de COVID-19 daquele país
3 - o total de óbitos em decorrência de COVID-19 naquele país

O programa deve calcular o país com a menor relação e com a maior relação de óbitos/caso de COVID-19 e exibir
os respectivos valores e os países correspondentes. Considere pelo menos 5 países.
*/

#include <stdio.h>
#include "structs.h"
#define COUNTRY_TOTAL 2

void populate_countries (Country *c) {
  int i;
  for (i = 0; i < COUNTRY_TOTAL; i++) {
    printf ("Sigla do país: ");
    scanf ("%s", c[i].acr);
    printf ("Total de casos: ");
    scanf ("%li", &c[i].cases);
    printf ("Total de mortes: ");
    scanf ("%li", &c[i].deaths);
  }
}

int main () {
  Country countries[COUNTRY_TOTAL];

  populate_countries(countries);

  // printf("Sigla: %s\n", countries[1].acr);

  return 0;
}