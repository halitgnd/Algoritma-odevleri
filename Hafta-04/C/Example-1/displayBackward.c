#include "StudentNode.h"
#include <stdio.h>
#include "displayBackward.h"

void displayBackward(const Node* head) {
    printf("\n-----Öğrenci listesini sondan başa yazdırma-----\n\n");
    if (head == NULL) {
        printf("Liste: NULL\n");
        return;
    }
    const Node* curr= head;
    while (curr->next != NULL) {
        curr=curr->next;
    }
    while (curr != NULL) {
        printf("[%d] %-15s", curr->id, curr->name);
        if (curr->prev != NULL) {
            printf(" <-> ");
        }
        curr = curr->prev;
    }
    printf("-> NULL\n");

}
