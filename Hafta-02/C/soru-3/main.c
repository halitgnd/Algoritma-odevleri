/* Soru3:
    10 20 30 NULL listesini oluşturun ve while kullanarak tüm elemanları yazdırın.
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

    if (*head==NULL) {
        *head = yeni;
        return;
    }
    struct Node* gecici=*head;
    while (gecici->next !=NULL) {
        gecici = gecici->next;
    }
    gecici->next = yeni;
}
int main() {
    struct Node* head=NULL;
    for (int i=0;i<3;i++) {
        const int veriler[3]={10,20,30};
        sonaEkle(&head,veriler[i]);
    }
    struct Node* gecici=head;
    printf("Bağlı Liste: ");
    while (gecici !=NULL) {
        printf("%d -> ",gecici->data);
        gecici = gecici->next;
    }
    printf("NULL\n");

    while (head !=NULL) {
        struct Node* silinecek = head;
        head=head->next;
        free(silinecek);
    }

    return 0;
}