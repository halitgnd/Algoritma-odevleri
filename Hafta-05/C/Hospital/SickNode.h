#ifndef ALGORITMA_ODEVLERI_SICK_H
#define ALGORITMA_ODEVLERI_SICK_H
typedef enum State {
    Bekleyen=0,
    Muayenede=1,
    Tamamlandi=2

} state;
typedef struct Patient {
    enum State state;
    struct Patient* next;
    int id;
    char name[50];
}patient;
void enqueue(patient *pat, patient** front, patient** rear);
patient* dequeue(patient** front, patient** rear);
patient* pop(patient **top);
void push(patient *pat,patient **top);
patient* addHistory(patient **pat,patient *new_pat);
void printHistory(const patient *head);
void printState(const patient *head);
void printWaiting(const patient *head);

#endif