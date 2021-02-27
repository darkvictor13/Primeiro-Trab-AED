#include "../headers/people_list.h"

Node* allocPerson() {
    return (Node *)malloc(sizeof(Node));
}

List* createList() {
    List* new_list = (List*)malloc(sizeof(List));
    new_list->head = NULL;
    new_list->tail = NULL;

<<<<<<< HEAD
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
=======
    return new_list;
>>>>>>> e46cb06522b1d5a305fd3a4fe8dec33854e10d9a
}

int isEmptyString(char s[]) {
    return s[0] == '\0';
}

int isNull(void * data) {
    return data == NULL;
}

void insert(List *list, Person data) {
    Node *new_tail = allocPerson();
    new_tail->next = NULL;
    new_tail->data = data;

    // se a lista é vazia
    if(isNull(list->head)) {
        list->head = new_tail;
        list->tail = new_tail;
    }else {
        list->tail->next = new_tail;
        list->tail = new_tail;
    }
}
