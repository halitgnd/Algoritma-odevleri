#include <stdio.h>
#include <stdlib.h>
#include "removeNode.h"

void removeNode(struct Node** head, int value) {
    if (*head==NULL) {
        return;
    }
    if ((*head)->data==value) {
        node *silinecek=*head;
        *head=(*head)->next;
        free(silinecek);
        return;
    }
    node* gecici=*head;
    while (gecici->next != NULL && gecici->next->data !=value) {
        gecici=gecici->next;
    }
    if (gecici->next==NULL) {
        return;
    }
    node* silinecek=gecici->next;
    gecici->next=silinecek->next;
    free(silinecek);
}
