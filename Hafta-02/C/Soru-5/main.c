/*Soru5:
    10 20 30 40 NULL listesinin kaç Node içerdiğini bulun.
*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

static void sonaEkle(struct Node** head, int deger) {
    struct Node* yeni = (struct Node*) malloc(sizeof(struct Node));
    yeni->data = deger;
    yeni->next = NULL;
    if (*head == NULL) {
        *head = yeni;
        return;
    }
    struct Node* gecici= *head;
    while (gecici->next != NULL) {
            gecici = gecici->next;
    }
    gecici->next = yeni;
}
static int nodeSayaci(const struct Node* head) {
    int sayac=0;
    const struct Node* gecici= head;
    while (gecici != NULL) {
        sayac++;
        gecici = gecici->next;
    }
    return sayac;
}
int main() {
    struct Node* head = NULL;
    {
        const int veriler[]={10,20,30,40};
        const int elemansayisi =sizeof(veriler)/sizeof(veriler[0]);
        for (int i=0; i<elemansayisi; i++) {
            sonaEkle(&head, veriler[i]);
        }
    }
    const struct Node* gecici = head;
    printf("Bağlı liste: ");
    while (gecici != NULL) {
        printf("%d -> ",gecici->data);
        gecici = gecici->next;
    }
    printf("NULL\n");
    int toplamNode=nodeSayaci(head);
    printf("Listedeki düğüm sayısı: %d\n", toplamNode);

    while (head!=NULL) {
        struct Node* silinecek =head;
        head = head->next;
        free(silinecek);
    }
    return 0;
}