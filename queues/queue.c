#include <stdio.h>
#include <unistd.h> // função sleep
#include "queue.h"
#define SLEEP_TIME 3

void menu () {
  int option, elem, removed;
  Tqueue *q = NULL;

  do {
    printf ("******* MENU DE GERENCIAMENTO DE FILAS *******\n");
    printf ("1 - Criar uma fila vazia\n");
    printf ("2 - Inserir um elemento na fila\n");
    printf ("3 - Remover um elemento da fila\n");
    printf ("4 - Verificar se a fila está vazia\n");
    // printf ("5 - Limpar e remover a fila\n");
    printf ("5 - Imprimir os elementos da fila\n");
    printf ("6 - Sair\n");
    printf ("Escolha uma opção: ");
    scanf ("%d", &option);

    switch (option) {
      case 1:
        if (!q) {
          q = create();
          printf ("Fila criada com sucesso!\n\n");
        }
        else {
          printf ("Uma fila já foi criada.\n\n");
        }
        sleep (SLEEP_TIME);
        system ("clear");
        break;
      case 2:
        if (!q) {
          printf ("A fila não existe. Crie uma fila antes de inserir os elementos\n\n");
        }
        else {
          printf ("Digite um valor inteiro para o elemento a ser inserido na fila: ");
          scanf ("%d", &elem);
          insert (q, elem);
          printf ("Elemento com valor %d inserido na fila com sucesso.\n\n", elem);
        }
        sleep (SLEEP_TIME);
        system ("clear");
        break;
      case 3:
        if (!q) {
          printf ("Nao é possível remover elementos de uma fila que não existe.\n\n");
        }
        else if (empty(q)) {
          printf ("Nao é possível remover elementos de uma fila vazia.\n\n");
        }
        else {
          printf ("O elemento %d foi removido da fila.\n\n", remove_node(q));
        }
        sleep (SLEEP_TIME);
        system ("clear");
        break;
      case 4:
        if (empty(q)) {
          printf ("\nA fila está vazia\n\n");
        }
        else {
          printf ("\nA fila não está vazia\n\n");
        }
        sleep (SLEEP_TIME);
        system ("clear");
        break;
      case 5:
        if (!q) {
          printf ("Nao é possível imprimir os elementos de uma fila que não existe.\n\n");
        }
        else if (empty (q)) {
          printf ("Fila vazia.\n\n");
        }
        else {
          printf ("Imprimindo os elementos da fila.\n");
          print_queue (q);
        }

        sleep (SLEEP_TIME);
        system ("clear");
        break;
      // case 5:
      //   if (!q) {
      //     printf ("Nao é possível liberar a memória de uma fila que não existe.\n\n");
      //   }
      //   else {
      //     clear (q);
      //     printf ("A memória da fila foi liberada com sucesso.\n\n");
      //   }
      //   sleep (SLEEP_TIME);
      //   system ("clear");
      //   break;
      case 6:
        // if (q->start && q->end) {
        //   clear (q);
        // }
        clear (q);
        printf ("Saindo do programa...\n\n");
        sleep (SLEEP_TIME);
        system ("clear");
        break;
      default:
        printf ("Opção inválida!\n\n");
        sleep (SLEEP_TIME);
        system ("clear");
        break;
    }
  } while (option != 6);
}

int main () {
  menu();
  return 0;
}