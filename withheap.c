#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "withheap.h"
#define MAX_SIZE 100000

long long int compnumberhp = 0;

heap* create_h()
{
    heap* h = (heap*) malloc(sizeof(heap));
    h->size = 0;
    long long int i;
    for(i = 1;i <= MAX_SIZE;++i)
    {
        h->items[i] = INT_MIN;
    }
    return h;
}

long long int enqueuehp(heap *heap,long long int element,long long int compnumberhp)
{
    if(heap->size >= MAX_SIZE)
    {
        printf("Overflow\n");
    }
    else
    {
        heap->items[++heap->size] = element;

        long int key_i = heap->size;
        long int parent_i = get_parent_i(heap,heap->size);
        while(parent_i > 0 && heap->items[key_i] > heap->items[parent_i])
        {
            compnumberhp++;
            int aux = heap->items[key_i];
            heap->items[key_i] = heap->items[parent_i];
            heap->items[parent_i] = aux;
            key_i = parent_i;
            parent_i = get_parent_i(heap,key_i);
        }
    }
    return compnumberhp;
}

/*long long int searchhp(heap *heap,long long int number, long long int size,long long int compnumberhp)
{
	long long int begin = 0,end = size-1,middle,num,numberresult[size],last = 0,i = 0;
	while(begin <= end)
	{
		middle=(begin+end)/2;
		if(heap->items[middle] < number)
    {
      compnumberhp++;
      begin = middle+1;
    }
		else if(heap->items[middle] > number)
    {
      compnumberhp++;
      end = middle-1;
    }
	  else
    {
      compnumberhp++;
      return compnumberhp++;;
    }
	}
	return 0;
}*/

long long int dequeuehp(heap* heap)
{
    if(heap == NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        long long int element = heap->items[1];
        heap->items[1] = heap->items[heap->size];
        heap->size--;
        max_hfy(heap,1);
        return element;
    }
}
void printf_heap(heap* heap)
{
    long long int i;
    for(i = 1;i <= heap->size;++i)
    {
        printf("%Ld\n",heap->items[i]);
    }
}
long long int get_parent_i(heap* heap, long long int i)
{
    long long int result = i/2;
    return result;
}
long long int get_left_i(heap* heap, long long int i)
{
    long long int result = 2*i;
    return result;
}
long long int get_right_i(heap* heap, long long int i)
{
    long long int result = (2*i) + 1;
    return result;
}
void max_hfy(heap* heap,long long int i)
{
    long long int largest,left_index,right_index,aux;
    left_index = get_left_i(heap,i);
    right_index = get_right_i(heap,i);
    if((left_index <= heap->size) && (heap->items[i] < heap->items[left_index]))
    {
        largest = left_index;
    }
    else
    {
        largest = i;
    }
    if((right_index <= heap->size) && (heap->items[i] < heap->items[right_index]))
    {
        largest = right_index;
    }
    if(heap->items[i] != heap->items[largest])
    {
        aux = heap->items[i];
        heap->items[i] = heap->items[largest];
        heap->items[largest] = aux;
        max_hfy(heap,largest);
    }
}
long long int element_of(heap* heap, long long int i)
{
    return heap->items[i];
}
void heapsort(heap* heap)
{
    long long int i;
    for(i = heap->size;i >= 2;i--)
    {
        int aux = heap->items[1];
        heap->items[1] = heap->items[i];
        heap->items[i] = aux;
        heap->size--;
        max_hfy(heap,1);
    }
}
