#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SickNode.h"
#define MAX_NAME_LENGTH 50

void enqueue(int id, const char *name, patient **front, patient **rear){
    patient* newpat=(patient*)malloc(sizeof(patient));
    if (newpat==NULL) {
        printf("Bellek tahsisatı başarızı oldu !!\n");
        return;
    }
    newpat->id=id;
    strncpy(newpat->name, name, MAX_NAME_LENGTH - 1);
    newpat->name[MAX_NAME_LENGTH - 1] = '\0';
    newpat->state=Bekleyen;
    newpat->next=NULL;
    if (*front==NULL) {
        *front=newpat;
        *rear=newpat;
    }
    else {
        (*rear)->next=newpat;
        *rear=newpat;
    }
}
patient* dequeue(patient** front, patient** rear) {
    if (*front == NULL) {
        printf("Hasta yok\n");
        return NULL;
    }
    patient* temp=*front;
    if (*front == *rear) {
        *front = NULL;
        *rear = NULL;
    }
    else{
        *front=(*front)->next;
    }
    temp->next=NULL;
    temp->state=Muayenede;
    return temp;
}
void push(patient *pat,patient **top) {
    if (pat == NULL) return;
    pat->next = *top;
    *top = pat;
}
patient* pop(patient **top) {
    if (top == NULL || *top == NULL) {
        printf("Muayene odasinda hasta yok!\n");
        return NULL;
    }
    patient *temp = *top;
    *top = temp->next;
    temp->state = Tamamlandi;
    temp->next = NULL;
    return temp;
}
void addHistory(patient **pat,patient *new_pat) {
    if (new_pat == NULL) {
        return;
    }
    new_pat->next = NULL;
    if (*pat == NULL) {
        *pat = new_pat;
    }
    else {
        patient* temp=*pat;
        while (temp->next!=NULL) {
            temp=temp->next;
        }
        temp->next = new_pat;
    }
}
void printHistory(const patient *head) {
    if (head == NULL) {
        printf("Hasta yok\n");
        return;
    }
    const patient* temp=head;
    printf("Geçmiş hasta kayıtları: ");
    while (temp!=NULL) {
        const char *stateStr = (temp->state == Tamamlandi) ? "Tamamlandi" :
                                (temp->state == Muayenede)  ? "Muayenede"  : "Bekleyen";
        printf("Hasta ID: %d, Isim: %s, Durum: %s\n", temp->id, temp->name, stateStr);
        temp=temp->next;
    }
    printf("\n");
}
void printWaiting(const patient *head) {
    if (head == NULL) {
        printf("Hasta yok\n");
        return;
    }
    const patient* temp=head;
    printf("----Bekleyan Hastalar----\n\n");
    while (temp!=NULL) {
        if (temp->state == Bekleyen) {
            printf("Hasta ID: %d, Isim: %s",temp->id, temp->name);
        }
        temp=temp->next;
    }
}