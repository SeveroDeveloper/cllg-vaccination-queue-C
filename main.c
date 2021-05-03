#include <stdio.h>
#include <stdlib.h>
#include "newperson.h"

void menu()
{
  int op = -1;
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
      break;
      case 2:
      puts("\n\t>> show the intire queue <<");
      break;
      case 3:
      puts("\n\t>> show queue by priority level <<");
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
  menu();
  return 0;
}