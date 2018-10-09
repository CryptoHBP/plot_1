#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "priorityqueue.h"
#include "withheap.h"
#define MAX_SIZE 100000

int main()
{
    priority_q* p_q = create_p_q();
    heap* heap = create_h();
    long long int numberofcomparisons = 0,number = 0,numberof = 0,randomN[MAX_SIZE],numbers[MAX_SIZE];
    long long int heapcomp = 0, priorityqcomp = 0, ran = 0,i = 0,p_qcomp[MAX_SIZE],heapc[MAX_SIZE];

    FILE* archive;
    archive = fopen("Graficos.txt", "wb");

    printf("Enter the quantity of Data Numbers you want to insert:\n");
    scanf("%Ld",&numberofcomparisons);

    srand(time(NULL));
    for(number = 0; number <= numberofcomparisons; number++)
    {
       numbers[number] = rand()%numberofcomparisons;
       p_qcomp[number] = enqueuepq(p_q,numbers[number],numbers[number],priorityqcomp);
       heapc[number] = enqueuehp(heap,numbers[number],heapcomp);
    }
    ran = 0;
    printf("How many numbers do you want to compare?\n");
    scanf("%Ld",&numberof);

    srand(time(NULL));
    for (i = 0; i < numberof; i ++)
    {
        randomN[i] = rand()%numberof;
        fprintf(archive, "Number: %Ld\n", randomN[i]);
        fprintf(archive, "PQ:%Ld\n",  p_qcomp[i]);
        fprintf(archive, "HP:%Ld\n", heapc[i]);
    }
    fclose(archive);
    return 0;
}
