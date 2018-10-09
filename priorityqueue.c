#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "priorityqueue.h"
#define MAX_SIZE 100000


priority_q* create_p_q()
{
    priority_q* p_q = (priority_q*) malloc(sizeof(priority_q));
    node *new = (node*) malloc(sizeof(node));
    new->priority = 0;
    p_q->head = new;
    return p_q;
}

long long int enqueuepq(priority_q* priority_queue,long long int element,long long int pr,long long int compnumber)
{
    node *new = (node*) malloc(sizeof(node));
    new->element = element;
    new->priority = pr;
    if((priority_queue->head != NULL) && (pr > priority_queue->head->priority))
    {
        compnumber++;
        new->next = priority_queue->head;
        priority_queue->head = new;
    }
    else
    {
        node* now = priority_queue->head;
        while((now->next != NULL) && (now->next->priority > pr))
        {
            compnumber++;
            now = now->next;
        }
        new->next = now->next;
        now->next = new;
    }
    return compnumber;
}

/*long long int searchpq(priority_q* priority_queue,long long int element,long long int compnumber)
{
   if((priority_queue->head == NULL))
    {
        return 0;
    }
    else{
        while((priority_queue->head->next != NULL))
        {
            if((priority_queue->head->element) == element)
            {
                compnumber++;
                return compnumber;
            }
            else
            {
                compnumber++;
                priority_queue->head = priority_queue->head->next;
            }
        }
    }
    return 0;
}*/

node* dequeue(priority_q* priority_queue)
{
    if((priority_queue->head == NULL))
    {
        printf("Underflow\n");
        return NULL;
    }
    else{
        node* aux = priority_queue->head;
        priority_queue->head = priority_queue->head->next;
        aux->next = NULL;
        return aux;
    }
}

long long int maximum(priority_q* priority_queue)
{
    if(priority_queue->head == NULL)
    {
        printf("Underflow\n");
        return -1;
    }
    else{
        return priority_queue->head->element;
    }
}
