/*Soru6:
10 20 30 40 NULL listesindeki değerlerin toplamını bulun.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
static void sonaEkle(struct Node** head, int deger) {
    struct Node* yeni =(struct Node*)malloc(sizeof(struct Node));
    yeni->data = deger;
    yeni->next = NULL;
    if (*head == NULL) {
        *head = yeni;
        return;
    }
    struct Node* gecici = *head;
    while (gecici->next != NULL) {
        gecici = gecici->next;
    }
    gecici->next = yeni;
}
int main() {
    struct Node* head=NULL;
    {
        const int veriler[]={10,20,30,40};
        const int veriuzunlugu= sizeof(veriler)/sizeof(veriler[0]);
        for (int i=0; i<veriuzunlugu; i++) {
            sonaEkle(&head, veriler[i]);
        }
    }
    struct Node* gecici=head;
    printf("Bağlı liste: ");
    while (gecici != NULL) {
        printf("%d -> ",gecici->data);
        gecici = gecici->next;
    }
    printf("NULL\n");
    gecici=head;
    int toplamdeger=0;
    while (gecici != NULL) {
        toplamdeger+=gecici->data;
        gecici = gecici->next;
    }
    printf("Toplam değer: %d",toplamdeger);
    while (head!=NULL) {
        struct Node* silinecek= head;
        head=head->next;
        free(silinecek);
    }
    return 0;
}