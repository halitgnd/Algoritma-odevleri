/* Soru2:
    10 ve 20 değerlerini içeren iki Node oluşturun ve 10  20 NULL listesini oluşturun.
 */

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node* birinci=(struct Node*)malloc(sizeof(struct Node));
    struct Node* ikinci=(struct Node*)malloc(sizeof(struct Node));

    if (birinci==NULL || ikinci==NULL) {
    printf("Bellek tahsisatı başarısız oldu!!");
        if (birinci!=NULL) {
            free(birinci);
        }
        if (ikinci!=NULL) {
            free(ikinci);
        }
        return 1;
    }
    birinci->data=10;
    ikinci->data=20;
    birinci->next=ikinci;
    ikinci->next=NULL;
    struct Node* gecici=birinci;
    printf("Bağlı liste: ");
    while (gecici!=NULL) {
    printf("%d -> ",gecici->data);
        gecici=gecici->next;
    }
    printf("NULL\n");
    free(birinci);
    free(ikinci);
    birinci=NULL;
    ikinci=NULL;
    gecici=NULL;
    return 0;
}