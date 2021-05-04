#include "newperson.h"

void enqueuePerson(Queue *q, Person *p)
{
  enqueue(q, *p);
}
//========================================
void enqueuePriorityPerson(Queue *q, Person *p)
{
  if(p->age >= 75 || p->hea == true)
  {
    p->sta = 1;
    enqueue_pri(q, *p);
  }
  else if (p->age >= 60 && p->age <= 74)
  {
    p->sta = 2;
    enqueue_pri(q, *p);
  }
  else if (p->com == true)
  {
    p->sta = 3;
    enqueue_pri(q, *p);
  }
  else if (p->pro == true)
  {
    p->sta = 4;
    enqueue_pri(q, *p);
  }
}
//========================================
void personRegister(Queue *q)
{
  char name[50];
  int age, com, hea, pro;

  printf( "\n\tName: ");
  fflush(stdin);
  scanf("%s", name);
  printf("\n\tAge: ");
  scanf("%d", &age);
  printf("\n\tAny comorbidity?\n\t[1] yes [0] no: ");
  scanf("%d", &com);
  printf("\n\tHealthcare professional?\n\t[1] yes [0] no: ");
  scanf("%d", &hea);
  printf("\n\tFourth stage professional?\n\t[1] yes [0] no: ");
  scanf("%d", &pro);
  puts("\n\t");
  
  Person p;
  
  strcpy(p.name, name);
  p.age = age;
  p.com = com;
  p.hea = hea;
  p.pro = pro;

  if(age>59||com==1||hea==1||pro==1)
  {
    enqueuePriorityPerson(q, &p);
  }
  else
  {
    p.sta=5;
    enqueuePerson(q, &p);
  }
}