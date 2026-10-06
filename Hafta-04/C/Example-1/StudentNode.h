#ifndef ALGORITMA_ODEVLERI_NODE_H
#define ALGORITMA_ODEVLERI_NODE_H
#define MAX_NAME_LEN 50
typedef struct StudentNode {
    int id;
    char name[MAX_NAME_LEN];
     struct StudentNode *next;
     struct StudentNode *prev;
}Node;
#endif //ALGORITMA_ODEVLERI_NODE_H
