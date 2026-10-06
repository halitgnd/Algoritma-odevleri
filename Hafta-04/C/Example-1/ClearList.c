#include <stdio.h>
#include <stdlib.h>
#include "StudentNode.h"
#include "ClearList.h"

void ClearList(Node** head) {
    if (head == NULL || *head == NULL) return;
    Node* curr = *head;
    while (curr->next != NULL) {
        while (curr != NULL) {
            Node* nextNode = curr->next;
            free(curr);
            curr = nextNode;
        }
        *head = NULL;
    }
}