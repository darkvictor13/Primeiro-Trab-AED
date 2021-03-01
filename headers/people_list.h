#ifndef PEOPLE_LIST
#define PEOPLE_LIST

#include "../structures/people_list_structure.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
* Function - aloca o espaço de memória necessário para armazenar uma pessoa
*
* @authors - mGuerra, mLucas, vAlmeida
* @version - 1.0
* @since - 1.0
*
* @pre-conditions - nenhuma
* @pos-conditions - nenhuma
*
* @return - o local de memória alocado para uma pessoa
*/
Node* allocPerson();

List* createList();

/**
* Function - insere um elemento no final da lista
*
* @authors - mGuerra, mLucas, vAlmeida
* @version - 1.0
* @since - 1.0
*
* @pre-conditions - a lista não deve estar vazia
* @pos-conditions - a lista possui um elemento a mais no seu final
*
* @return - void
*/
void insertPerson(List *list, Person data);

void removeNodeInHead(List *list);

void removeNodeInTail(List *l);

void removeNodeInMiddle(List *l, Node *data);

void removeNode(List *list, Node *node);

/**
* Function - busca uma pessoa dentro da lista pelo seu cpf
*
* @authors - mGuerra, mLucas, vAlmeida
* @version - 1.0
* @since - 1.0
*
* @pre-conditions - a lista não deve estar vazia
* @pos-conditions - nenhuma
*
* @return - void
*/
Node* searchByCPF(List *list, char *cpf);

/**
* Function - informa se uma string se encontra vazia
*
* @authors - mGuerra, mLucas, vAlmeida
* @version - 1.0
* @since - 1.0
*
* @pre-conditions - nenhuma
* @pos-conditions - nenhuma
*
* @param -
* @param -
*
* @return bool - informa se uma string se encontra vazia
*/
int isEmptyString(char string[]);

/**
* Function - informa se um ponteiro é nulo
*
* @authors - mGuerra, mLucas, vAlmeida
* @version - 1.0
* @since - 1.0
*
* @pre-conditions - nenhuma
* @pos-conditions - nenhuma
*
* @param -
* @param -
*
* @return bool - informa se um ponteiro é nulo
*/
int isNull (void * data);

void freePerson(Person *person);

void freeNode(Node *node);

/**
* Function - remove o último elemento da lista
*
* @authors - mGuerra, mLucas, vAlmeida
* @version - 1.0
* @since - 1.0
*
* @pre-conditions - a lista deve ser uma lista válida
* @pos-conditions - o último elemento é removido da lista
*
* @return - nenhum
*/
void freeList(List *list);

#endif
