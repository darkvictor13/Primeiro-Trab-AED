#include "../headers/people_list.h"

Node* allocPerson() {
    return (Node *)malloc(sizeof(Node));
}

List* createList() {
    List* new_list = (List*)malloc(sizeof(List));
    new_list->head = NULL;
    new_list->tail = NULL;

    return new_list;
}

void insertPerson(List *list, Person data) {
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

void removeNodeInHead(List *list) {
    Node *newHead = list->head->next;

    free(list->head);
    list->head = newHead;
}

void removeNodeInTail(List *l) {
    Node *prev_tail = l->head;
    while(prev_tail->next != l->tail) {
        prev_tail = prev_tail->next;
    }

    l->tail = prev_tail;
    free(prev_tail->next);
    prev_tail->next = NULL;
}

void removeNodeInMiddle(List *l, Node *data) {
    Node *prev_data = l->head;
    while(prev_data->next != data) {
        prev_data = prev_data->next;
    }

    prev_data->next = data->next;
    free(data);
}

void removeNode(List *list, Node *node) {
    if(list->head == node) {
        removeNodeInHead(list);
    }else if (list->tail == node) {
        removeNodeInTail(list);
    }else {
        removeNodeInMiddle(list, node);
    }
}

Node* searchByCPF(List *list, char *cpf) {

    Node *this = list->head;

    while(1) {
        if( this == NULL ) {
            return NULL;
        }
        
        if( 0 == strcmp(this->data.cpf, cpf) ) {
            return this;
        }
        
        this = this->next;
    }
}

int isEmptyString(char s[]) {
    return s[0] == '\0';
}

int isNull(void * data) {
    return data == NULL;
}

void freePerson(Person *person) {

}

void freeNode(Node *node) {

}

void freeList(List *list) {

}
