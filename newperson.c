#include "newperson.h"

void personRegister(Queue *q)
{
  char name[50];
  int age, com, pro;

  printf( "\n\tName: ");
  fflush(stdin);
  scanf("%s", name);
  printf("\n\tAge: ");
  scanf("%d", &age);
  printf("\n\tAny comorbidity?\n\t[1] yes [0] no: ");
  scanf("%d", &com);
  printf("\n\tFourth stage professional?\n\t[1] yes [0] no: ");
  scanf("%d", &pro);
  puts("\n\t");

  
}