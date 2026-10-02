#include <stdio.h>
#include <stdlib.h>
#include "Count.h"
int Count(const node *head) {
    int sayac=0;
    const node* current = head;

    while (current != NULL) {
        sayac++;
        current = current->next;
    }
    return sayac;
}