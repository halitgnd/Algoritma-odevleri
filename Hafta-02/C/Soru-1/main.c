/* Soru1:
    Bir Node yapısı oluşturun. Node içerisinde 10 değerini saklayın ve ekrana yazdırın.
 */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    if (node==NULL) {
        printf("Bellek tahsisi başarısızlıkla sonuçlandı\n");
        return 1;
    }
    node->data=10;
    node->next=NULL;

    printf("Node içerisindeki değer: %d\n",node->data);
    free(node);
    node=NULL;
    return 0;
}