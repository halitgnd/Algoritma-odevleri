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
int Search(bstnode* root,int key) {
    if (root==NULL) return 0;
    if (root->data==key) return 1;
    if (key<root->data) return Search(root->Left,key);
    if (key>root->data) return Search(root->Right,key);

}
int FindMin(bstnode* root) {
    bstnode*current=root;
    while (current->Left!=NULL) {
        current=current->Left;
    }
    return current->data;
}
int main(void) {
    bstnode* root=NULL;
    int veri[]={10,30,20,40,50,70,80,60};
    int lenght=sizeof(veri)/sizeof(veri[0]);
    for(int i=0;i<lenght;i++) {
        root=Insert(root,veri[i]);
    }
    printf("İkili arama ağacı sıralama:\n");
    Inorder(root);
    printf("En küçük değer: \n",FindMin(root));

    if (Search(root,20)) {
        printf("20 ağaçta bulundu.\n");
    }
    else {
        printf("20 ağaçta bulunamadı!!\n");
    }
    return 0;
}