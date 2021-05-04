#include <stdio.h>
#include <stdlib.h>
#include "newperson.h"
#include "queue.h"

void menu(Queue *q)
{
  int op = -1;
  int stage = 0;
  do
  {
   // printf("\e[H\e[2J");  linux screen clear 
    printf(
      "\n##########  VACCINATION QUEUE  ##########"
      "\n\tchoose an option"
      "\n\t[1] - register a new person"
      "\n\t[2] - show the intire queue"
      "\n\t[3] - show queue by priority level"
      "\n\t[0] - exit"
      "\n\t"
    );
    scanf("%d", &op);

    switch(op)
    {
      case 1:
      puts("\n\t>> register a new person <<");
      personRegister(q);
      break;
      case 2:
      puts("\n\t>> show the intire queue <<");
      print_queue(q);
      break;
      case 3:
      puts("\n\t>> show queue by priority level <<");
      printf("\n\tShow which stage? ");
      scanf("%d", &stage);
      print_priorityqueue(q, &stage);
      break;
      case 0:
      puts("\n\t**********  exit  **********");
      break;
      default:
      puts("\n\tinvalid option");
      break;
    }
  }while (op!=0);
}

int main(void) {
  Queue queue;
  new_queue(&queue);
  menu(&queue);
  return 0;
}