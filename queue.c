#include "queue.h"
//========================================
void print_person(Person p){
  printf("\n\t{name: %s, age: %d}\n", p.name, p.age);
  printf("\n\t{comorbidity: %s, fourth stage: %s}\n", p.com==1?"yes":"no", p.pro==1?"yes":"no");
}
//========================================
Cell *new_cell(){
  Cell *tmp = (Cell*) malloc(sizeof(Cell));
  tmp->next = NULL;
  return tmp;
}
//========================================
void new_queue(Queue *q){

  Cell *news = new_cell();

  q->start = news;
  q->end = news;
  q->size = 0;
}
//========================================
void enqueue(Queue *q, Person data){

  Cell *news = new_cell();
  news->data = data;

  q->end->next = news;
  q->end = news;
  q->size++;
}
/*
void enqueue_pri(Queue *q, Person data){

  Cell *news = new_cell();
  news->data = data;

  if(dado.idade >= 65) {

    // PRIORIDADE
    Celula *ant = f->inicio;
    Celula *tmp = f->inicio->prox;
  // 73 25 32 44 ==> 65
  // 1 1 1 22 3 3
    while(tmp!=NULL && tmp->dado.fase <=  dado.fase ){
      ant = ant->prox;
      tmp = tmp->prox;
    }
   
    nova->prox = tmp;
    ant->prox = nova;
    f->tam++;

    if(tmp == NULL){
      f->fim = nova;
    }

  }else{

    f->fim->prox = nova;
    f->fim = nova;
    f->tam++;
  }
}*/
//========================================
void print_queue(Queue *q){

  Cell *tmp = q->start->next;

  while(tmp != NULL){
    print_person(tmp->data);
    tmp = tmp->next;
  }
}
//========================================
int size_queue(Queue *q){
  return q->size;
}
//========================================
Person dequeue(Queue *q){

  if(q->size == 0){
    Person p = {"Invalid", -1};
    return p;
  }


  Cell *tmp = q->start;

  q->start = q->start->next;  
  
  free(tmp);

  q->size--;

  return q->start->data;

}