#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StudentNode.h"
#include "insertOrdered.h"

void insertOrdered(Node** head, int id,const char* name){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Bellek tahsisatı yapılamadı!");
        return;
    }
    newNode->id = id;
    strncpy(newNode->name, name, MAX_NAME_LEN - 1);
    newNode->name[MAX_NAME_LEN - 1] = '\0';
    newNode->prev = NULL;
    newNode->next = NULL;

    if(*head == NULL|| id<(*head)->id) {
        newNode->next = *head;
        if (*head!=NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }
    Node* current=*head;
    while(current->next!=NULL && current->next->id < id) {
        current = current->next;
    }
    newNode->next = current->next;
    newNode->prev = current;
    if (current->next!=NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
}
