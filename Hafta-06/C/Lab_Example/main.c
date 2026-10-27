#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode {
    int data;
    struct BSTNode* Right,*Left;
}bstnode;

bstnode* Newnode(int data) {
    struct BSTNode* temp=(struct BSTNode*)malloc(sizeof(struct BSTNode));
    temp->data=data;
    temp->Left=NULL;
    temp->Right=NULL;
    return temp;
}
bstnode* Insert(bstnode* node,int data) {
    if(node==NULL) {return Newnode(data);}

    if(data<node->data) {
        node->Left=Insert(node->Left,data);
    }
    if(data>node->data) {
        node->Right=Insert(node->Right,data);
    }
    return node;
}
void Inorder(bstnode* node) {
    if(node==NULL) {
        return;
    }
    Inorder(node->Left);
    printf("%d\n",node->data);
    Inorder(node->Right);
}



int main(void) {
    bstnode* root=NULL;
    printf("Ağaç boş.\n");
    Inorder(root);
    root=Insert(root,40);
    root=Insert(root,20);
    root=Insert(root,60);
    root=Insert(root,10);
    root=Insert(root,30);
    root=Insert(root,50);
    root=Insert(root,70);
    printf("İkili arama ağacı sıralama:\n");
    Inorder(root);
    printf("\n");
    return 0;
}