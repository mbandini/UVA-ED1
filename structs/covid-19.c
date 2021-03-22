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
#define COUNTRY_TOTAL 3

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
  int highest_ratio, lowest_ratio;
  int i;

  populate_countries(countries);

  highest_ratio = lowest_ratio = 0; // assumindo que o país de índice 0 possui a menor e a maior relação

  for (i = 1; i < COUNTRY_TOTAL; i++) {
    if ((double) countries[i].deaths/countries[i].cases > (double) countries[highest_ratio].deaths/countries[highest_ratio].cases) {
      highest_ratio = i;
    }

    if ((double) countries[i].deaths/countries[i].cases < (double) countries[lowest_ratio].deaths/countries[lowest_ratio].cases) {
      lowest_ratio = i;
    }
  }

  printf ("\nPaís com a menor taxa e óbitos/casos: %s\n", countries[lowest_ratio].acr);
  printf ("Total de casos: %li\n", countries[lowest_ratio].cases);
  printf ("Total de óbitos: %li\n", countries[lowest_ratio].deaths);
  printf ("Relação óbitos/casos: %.2lf\n", (double) countries[lowest_ratio].deaths/countries[lowest_ratio].cases);

  printf ("\n++++++++++++++++++++++++++++++++++++++++++++++++++\n");

  printf ("País com a maior taxa e óbitos/casos: %s\n", countries[highest_ratio].acr);
  printf ("Total de casos: %li\n", countries[highest_ratio].cases);
  printf ("Total de óbitos: %li\n", countries[highest_ratio].deaths);
  printf ("Relação óbitos/casos: %.2lf\n", (double) countries[highest_ratio].deaths/countries[highest_ratio].cases);

  return 0;
}