#include <stdio.h>
#include <stdlib.h>
#include "sumList.h"
int sumList(const node* head) {
    int sum=0;
    const node* current=head;
    while (current !=NULL) {
        sum+=current->data;
        current=current->next;
    }
    printf("Düğümlerdeki toplam değer: %d \n",sum);
    return sum;
}