#include "../headers/people_list.h"

List* allocPerson() {
   return (List *)malloc(sizeof(List));
}

List *insert(List *head, Person data) {
   if( head == NULL ) {
      List *newLast = allocPerson();

      newLast->data = data;
      newLast->next = NULL;
      
      return newLast;
   }

   head->next = insert(head->next, data);
   
   return head;
}

void freeList(List *list) {
   while (list->next->next != NULL) {
      list = list->next;
   }

   free(list->next);
   
   list->next = NULL;
}

int isEmptyString(char s[]) {
   return s[0] == '\0';
}

int isNull(void * data) {
   return data == NULL;
}
