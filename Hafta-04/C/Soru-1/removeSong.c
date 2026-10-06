#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Song.h"
#include "removeSong.h"

void removeSong(Song** head, const char* name,Song** currentSong) {
    if (head == NULL || *head == NULL) {
        printf("Çalma listesi boş!\n");
        return;
    }
    Song* temp = *head;
    while (temp != NULL&& strcmp(temp->name, name) != 0) {
    temp = temp->next;
    }
    if (temp==NULL) {
        printf(" '%s' isimli şarkı çalma listesinde bulunamadı!!\n",name);
        return;
    }
    if (currentSong != NULL && *currentSong == temp) {
        if (temp->next != NULL) {
            *currentSong = temp->next;
        }
        else {
            *currentSong= temp->prev;
        }
        if (temp==*head) {
            *head= temp->next;
        }
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }
        free(temp);
        printf("'%s isimli şarkı başarıyla silindi.\n");
    }

    if (temp==*head) {
        *head = temp->next;
    }
}