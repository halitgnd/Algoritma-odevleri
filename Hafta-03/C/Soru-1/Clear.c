#include <stdlib.h>
#include "Clear.h"
void Clear(node **head) {
   if (head==NULL || *head == NULL) {
      return;
   }
   node* current=*head;
   while (current != NULL) {
      node* nextNode = current->next;
      free(current);
     current=nextNode;
   }
   *head=NULL;
}