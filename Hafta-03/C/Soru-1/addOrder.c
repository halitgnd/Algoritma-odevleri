#include <stdio.h>
#include <stdlib.h>
#include "addOrder.h"
void addOrder(struct Node **head, int value) {
    node* yeni=(node*)malloc(sizeof(struct Node));
    if (yeni == NULL) {
        printf("Bellek tahsisi başarısız.\n");
        return;
    }
    yeni->data=value;
    yeni->next=NULL;
    if (*head == NULL || (*head)->data >= value) {
        yeni->next = *head;
        *head = yeni;
        return;
    }
    node* current = *head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }

    yeni->next=current->next;
    current->next=yeni;
}