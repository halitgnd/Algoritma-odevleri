/*soru4:
    malloc() kullanarak 10 --&gt; 20 --&gt; 30 --&gt; NULL listesini oluşturun.
*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* n1=(struct Node*) malloc(sizeof(struct Node));
    struct Node* n2=(struct Node*) malloc(sizeof(struct Node));
    struct Node* n3=(struct Node*) malloc(sizeof(struct Node));
    if (n1==NULL||n2==NULL||n3==NULL) {
        printf("Bellek tahsisatı malesef gerçekleştirilemedi!\n");
        if (n1 !=NULL) {free(n1);}
        if (n2 !=NULL) {free(n2);}
        if (n3 !=NULL) {free(n3);}
    }
    n1->data=10;
    n2->data=20;
    n3->data=30;
    n1->next=n2;
    n2->next=n3;
    struct Node* gecici= (struct Node*) malloc(sizeof(struct Node));
    gecici=n1;
    printf("Bağlı liste: ");
    while(gecici != NULL) {
        printf("%d -> ",gecici->data);
        gecici=gecici->next;
    }
    printf("NULL\n");
    free(n1);
    free(n2);
    free(n3);
    return 0;
}