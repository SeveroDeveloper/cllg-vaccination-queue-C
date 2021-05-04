#ifndef NP_H
#define NP_H
//=============================================================================
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

void personRegister(Queue *q);
void enqueuePerson(Queue *q, Person *p);
void enqueuePriorityPerson(Queue *q, Person *p);
//=============================================================================
#endif