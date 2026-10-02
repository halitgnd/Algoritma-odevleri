#include <stdio.h>
#include <stdlib.h>
#include "printList.h"

void printList(const node *head){
    const node* current = head;
    printf("Bağlı liste: ");
    while (current != NULL) {
        printf("%d -> ",current->data);
        current = current->next;
    }
    printf("NULL\n");
}
