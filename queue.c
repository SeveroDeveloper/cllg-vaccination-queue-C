#include "queue.h"
//========================================
void print_person(Person p){
  printf("\n\t-> {name: %s, age: %d, healthcare: %s\n", p.name, p.age, p.hea==true?"yes":"no");
  printf("\n\tcomorbidity: %s, fourth stage: %s, stage: %d}\n", p.com==true?"yes":"no", p.pro==true?"yes":"no", p.sta);
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

void enqueue_pri(Queue *q, Person data){

  Cell *news = new_cell();
  news->data = data;

  if(q->size==0)
  {
    enqueue(q, data);
  }
  else
  {
    switch(data.sta)
    {
      case 1:
      {
        Cell *back = q->start;
        Cell *front = q->start->next;
        while(front != NULL && front->data.sta <= 1)
        {
          back = back->next;
          front = front->next;
        }

        news->next = front;
        back->next = news;
        q->size++;

        if(news->next == NULL)
        {
          q->end = news;
        }
      break;
      }
      
      case 2:
      {
        Cell *back = q->start;
        Cell *front = q->start->next;
        while(front != NULL && front->data.sta <= 2)
        {
          back = back->next;
          front = front->next;
        }

        news->next = front;
        back->next = news;
        q->size++;

        if(news->next == NULL)
        {
          q->end = news;
        }
      break;
      }
      case 3:
      {
        Cell *back = q->start;
        Cell *front = q->start->next;
        while(front != NULL && front->data.sta <= 3)
        {
          back = back->next;
          front = front->next;
        }

        news->next = front;
        back->next = news;
        q->size++;

        if(news->next == NULL)
        {
          q->end = news;
        }
      break;
      }

      case 4:
      {
        Cell *back = q->start;
        Cell *front = q->start->next;
        while(front != NULL && front->data.sta <= 4)
        {
          back = back->next;
          front = front->next;
        }
        news->next = front;
        back->next = news;
        q->size++;
        if(news->next == NULL)
        {
          q->end = news;
        }
      break;
      }
      case 5:
      {
        enqueue(q, data);
        break;
      }
      default:
      puts("\n\tError: something went wrong in the switch stages!");
      break;
    }
  }

  /*
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
  }*/
}
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