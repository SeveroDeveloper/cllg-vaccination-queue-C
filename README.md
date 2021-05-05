# cllg-vaccination-queue-C :syringe: :walking: :walking: :walking:
College dynamic ADT project, working in a vaccination queue divided into different priority levels.
## Main Menu
You have four options:<br>
### 1 - Register a new person
> * You must inform name, age, if the person has comorbidity, if he works in healthcare or some profession of the fourth stage (such as teachers, security, etc).
> * Here you enter 1 for YES or 0 for NO.
> * The system automatically registers the person in his stage and enqueue it, usign this logic:
```c
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
```
### 2 - Show the intire queue
> * That's just gonna show you the queue, all stages.
```c
void print_queue(Queue *q){

  Cell *tmp = q->start->next;

  while(tmp != NULL){
    print_person(tmp->data);
    tmp = tmp->next;
  }
}
```
### 3 - show queue by priority level
> * You must inform witch stage you wat to see, so the system shows you just the people in this stage, using this:
```c
void print_priorityqueue(Queue *q, int *stage)
{
  Cell *tmp = q->start->next;

  while(tmp != NULL){
    if(tmp->data.sta == *stage)
    {
      print_person(tmp->data);
    }
    if(tmp->data.sta > *stage)
    {
      break;
    }
    tmp = tmp->next;
  }
}
```
### 4 - exit
> * Just bye, bye! See you. :v:
