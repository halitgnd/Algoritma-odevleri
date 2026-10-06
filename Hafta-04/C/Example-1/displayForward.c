#include <stdio.h>
#include "StudentNode.h"
#include "displayForward.h"

void displayForward(const Node* head) {
    printf("\n-----Öğrenci listesi baştan sona yazdırma-----\n\n");
    if (head==NULL) {
        printf("Liste: NULL\n");
        return;
    }
    const Node* current = head;
    while (current->next != NULL) {
        printf("[%d] %-15s", current->id, current->name);
        if (current->next != NULL) {
            printf(" <-> ");
        }
        current = current->next;
    }
    printf("-> NULL\n");
}