#include <stdio.h>
#include "structs.h"

int main () {
  Person P1, P2;

  printf ("Insira a idade de P1: ");
  scanf ("%d", &P1.age);
  printf ("Insira a altura de P1: ");
  scanf ("%f", &P1.height);

  printf ("Insira a idade de P2: ");
  scanf ("%d", &P2.age);
  printf ("Insira a altura de P2: ");
  scanf ("%f", &P2.height);

  if (P1.age > P2.age && P1.height < P2.height) {
    printf ("P1 é mais velho que P2, porém, P2 é mais alto do que P1\n");
  }
  else if (P1.age == P2.age) {
    printf ("P1 e P2 possuem a mesma idade\n");
  }
  else {
    printf ("P2 é mais velho que P1\n");
  }

  return 0;
}