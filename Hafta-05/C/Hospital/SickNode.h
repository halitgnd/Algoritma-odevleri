#ifndef ALGORITMA_ODEVLERI_SICK_H
#define ALGORITMA_ODEVLERI_SICK_H
#define MAX_NAME_LENGHT 50
typedef enum State {
    Bekleyen=0,
    Muayenede=1,
    Tamamlandi=2
} state;
typedef struct Patient {
    enum State state;
    struct Patient* next;
    int id;
    char name[MAX_NAME_LENGHT];
}patient;
void enqueue(int id, const char *name, patient **front, patient **rear);
patient* dequeue(patient** front, patient** rear);
patient* pop(patient **top);
void push(patient *pat,patient **top);
void addHistory(patient **pat,patient *new_pat);
void printHistory(const patient *head);
void printWaiting(const patient *head);

#endif