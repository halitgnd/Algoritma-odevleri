#include <stdio.h>
#include "SickNode.h"
#include "SickNode.h"

int main() {
    // 1. Veri Yapısı Başlangıç İşaretçileri (Pointer'lar)
    patient *front = NULL;
    patient *rear = NULL;
    patient *top = NULL;
    patient *historyHead = NULL;

    printf("==========================================\n");
    printf("   HASTANE YONETIM SISTEMI TEST AKISI     \n");
    printf("==========================================\n\n");

    // ADIM 1: Hastalar hastaneye gelir ve kuyruga girer (Enqueue)
    printf(">>> 1. ADIM: Hastalar kuyruga aliniyor...\n");
    enqueue(101, "Ahmet Yilmaz", &front, &rear);
    enqueue(102, "Ayse Demir", &front, &rear);
    enqueue(103, "Mehmet Kaya", &front, &rear);

    // Kuyruktaki hastaları gör
    printWaiting(front);

    // ADIM 2: İlk iki hasta sirayla muayeneye cagirilir (Dequeue -> Push)
    printf("\n>>> 2. ADIM: Hastalar muayene odasina aliniyor...\n");
    patient *currentPatient = dequeue(&front, &rear);
    if (currentPatient != NULL) {
        printf("Muayeneye alindi: %s (ID: %d)\n", currentPatient->name, currentPatient->id);
        push(currentPatient, &top);
    }

    currentPatient = dequeue(&front, &rear);
    if (currentPatient != NULL) {
        printf("Muayeneye alindi: %s (ID: %d)\n", currentPatient->name, currentPatient->id);
        push(currentPatient, &top);
    }

    // Muayenelerden sonra kuyrukta kim kaldi?
    printf("\nKuyrukta Kalanlar:");
    printWaiting(front);

    // ADIM 3: Muayenesi bitenler odadan cikar ve gecmise eklenir (Pop -> AddHistory)
    printf("\n>>> 3. ADIM: Muayenesi biten hastalar taburcu ediliyor...\n");
    // Yığın (LIFO) çalıştığı için son giren (Ayşe) önce çıkar!
    patient *completedPatient = pop(&top);
    if (completedPatient != NULL) {
        printf("Taburcu edildi: %s (ID: %d)\n", completedPatient->name, completedPatient->id);
        addHistory(&historyHead, completedPatient);
    }

    completedPatient = pop(&top);
    if (completedPatient != NULL) {
        printf("Taburcu edildi: %s (ID: %d)\n", completedPatient->name, completedPatient->id);
        addHistory(&historyHead, completedPatient);
    }

    // ADIM 4: Gecmis listesini ekrana basalim (PrintHistory)
    printf("\n>>> 4. ADIM: Gecmis Hasta Listesi Raporlaniyor...\n");
    printHistory(historyHead);

    return 0;
}