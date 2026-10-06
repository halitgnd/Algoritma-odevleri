#ifndef ALGORITMA_ODEVLERI_SONG_H
#define ALGORITMA_ODEVLERI_SONG_H
#define MAX_NAME_LEN 50
typedef struct Song {
    char name[MAX_NAME_LEN];
    struct Song* next;
    struct Song* prev;
}Song;
#endif //ALGORITMA_ODEVLERI_SONG_H
