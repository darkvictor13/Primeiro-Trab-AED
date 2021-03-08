#include "../headers/people_list.h"

/*************************************************
 * Aloca a estrutura Person
 * Retorno: Estrutura alocada
 * Pré-condição: Nenhum
 * Pós-condição: Estrutura Person alocada
**************************************************/
Node* allocPerson() {
    return (Node *)malloc(sizeof(Node));
}

/*************************************************
 * Cria a lista
 * Retorno: Retorna a lista alocada
 * Pré-condição: Nenhum
 * Pós-condição: Lista alocada
**************************************************/
List* createList() {
    List* new_list = (List*)malloc(sizeof(List));
    new_list->head = NULL;
    new_list->tail = NULL;

    return new_list;
}
/*************************************************
 * Insere dados na lista
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Insere habitante na lista
**************************************************/
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
/*************************************************
 * Remove um habitante na cabeça
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Remover o primeiro habitante
**************************************************/
void removeNodeInHead(List *list) {
    Node *newHead = list->head->next;

    free(list->head);
    list->head = newHead;
}
/*************************************************
 * Remove um habitante na cauda
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Remover o ultimo habitante
**************************************************/
void removeNodeInTail(List *l) {
    Node *prev_tail = l->head;
    while(prev_tail->next != l->tail) {
        prev_tail = prev_tail->next;
    }

    l->tail = prev_tail;
    free(prev_tail->next);
    prev_tail->next = NULL;
}
/*************************************************
 * Remove um habitante no meio da lista
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Remover habitante no meio da lista
**************************************************/
void removeNodeInMiddle(List *l, Node *data) {
    Node *prev_data = l->head;
    while(prev_data->next != data) {
        prev_data = prev_data->next;
    }

    prev_data->next = data->next;
    free(data);
}
/*************************************************
 * Remove um habitante independente de sua posição
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Remove um habitante
**************************************************/
void removeNode(List *list, Node *node) {
    if(list->head == node) {
        removeNodeInHead(list);
    }else if (list->tail == node) {
        removeNodeInTail(list);
    }else {
        removeNodeInMiddle(list, node);
    }
}
/*************************************************
 * Busca pelo CPF
 * Retorno: Retorna nó do CPF
 * Pré-condição: CPF deve estar cadastrado
 * Pós-condição: CPF encontrado
**************************************************/
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
/*************************************************
 * Verifica se a string esta vazia
 * Retorno: booleano, string vazia
 * Pré-condição: Nenhum
 * Pós-condição: Verdadeiro ou falso
**************************************************/
int isEmptyString(char s[]) {
    return s[0] == '\0';
}
/*************************************************
 * Verifica se data é vazia
 * Retorno: Booleano, data é NULL
 * Pré-condição: Nenhum
 * Pós-condição: Verdadeiro ou falso
**************************************************/
int isNull(void * data) {
    return data == NULL;
}
/*************************************************
 * Libera a lista Person
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Lista vazia
**************************************************/
void freePerson(Person *person) {

}
/*************************************************
 * Libera o Nó da lista
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Nó vazia
**************************************************/
void freeNode(Node *node) {

}
/*************************************************
 * Libera a estrutura Lista
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Lista vazia
**************************************************/
void freeList(List *list) {

}
