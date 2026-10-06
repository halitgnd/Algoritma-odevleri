#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Song.h"
#include "addSongToEnd.h"

void addSongToEnd(Song** head,const char* name) {
    Song* newSong = (Song*) malloc(sizeof(Song));
    if (newSong == NULL) {
        printf("Bellek tahsis edilemedi!!\n");
        return;
    }
    strncpy(newSong->name, name, MAX_NAME_LEN-1);
    newSong->name[MAX_NAME_LEN-1] = '\0';
    newSong->next = NULL;
    if (*head == NULL) {
        newSong->prev = NULL;
        *head = newSong;
        printf("'%s' calma listesine eklendi.\n", name);
        return;
    }
    Song* currSong = *head;
    while (currSong->next != NULL) {
        currSong = currSong->next;
    }
    currSong->next = newSong;
    newSong->prev = currSong;
    printf(" '%s' isimli şarkı çalma listesine eklendi.\n",name);
}
