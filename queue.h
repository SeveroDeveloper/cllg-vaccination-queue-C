#ifndef QUEUE_H
#define QUEUE_H
//========================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//========================================
typedef struct Person{
  char name[50];
  int age, sta;
  bool com, hea, pro;
}Person;
void print_person(Person p);
//========================================
typedef struct Cell{
  Person data;
  struct Cell *next;
}Cell;
//========================================
typedef struct Queue{
  Cell *start;
  Cell *end;
  int size;
}Queue;
//========================================
Cell *new_cell();
//========================================
void new_queue(Queue *q);
//========================================
void enqueue(Queue *q, Person data);
void enqueue_pri(Queue *q, Person data);
//========================================
void print_queue(Queue *q);
void print_priorityqueue(Queue *q, int *stage);
//========================================
int size_queue(Queue *q);
//========================================
Person dequeue(Queue *q);
//========================================
#endif