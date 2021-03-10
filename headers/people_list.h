#ifndef PEOPLE_LIST
#define PEOPLE_LIST

#include "../structures/people_list_structure.h"
#include "../structures/registry_structure.h"


#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*************************************************
 * Aloca a estrutura Person
 * Retorno: Estrutura alocada
 * Pré-condição: Nenhum
 * Pós-condição: Estrutura Person alocada
**************************************************/
Node* allocPerson();

/*************************************************
 * Cria a lista
 * Retorno: Retorna a lista alocada
 * Pré-condição: Nenhum
 * Pós-condição: Lista alocada
**************************************************/
List* createList();
/*************************************************
 * Insere dados na lista
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Insere habitante na lista
**************************************************/
void insertPerson(List *list, Person data);
/*************************************************
 * Remove um habitante na cabeça
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Remover o primeiro habitante
**************************************************/
void removeNodeInHead(List *list);
/*************************************************
 * Remove um habitante na cauda
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Remover o ultimo habitante
**************************************************/
void removeNodeInTail(List *l);
/*************************************************
 * Remove um habitante no meio da lista
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Remover habitante no meio da lista
**************************************************/
void removeNodeInMiddle(List *l, Node *data);
/*************************************************
 * Remove um habitante independente de sua posição
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Remove um habitante
**************************************************/
void removeNode(List *list, Node *node);
/*************************************************
 * Busca pelo CPF
 * Retorno: Retorna nó do CPF
 * Pré-condição: CPF deve estar cadastrado
 * Pós-condição: CPF encontrado
**************************************************/
Node* searchByCPF(List *list, char *cpf);
/*************************************************
 * Verifica se a string esta vazia
 * Retorno: booleano, string vazia
 * Pré-condição: Nenhum
 * Pós-condição: Verdadeiro ou falso
**************************************************/
int isEmptyString(char s[]);
/*************************************************
 * Verifica se data é vazia
 * Retorno: Booleano, data é NULL
 * Pré-condição: Nenhum
 * Pós-condição: Verdadeiro ou falso
**************************************************/
int isNull(void * data);

/*************************************************
 * Libera um nó da lista de vacinas
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Nó vazio
**************************************************/
void freeVaccine(Vaccine *vaccine);

/*************************************************
 * Libera a lista de vacinas
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Lista vazia
**************************************************/
void freeVaccineList(Vaccine *vaccine);

/*************************************************
 * Libera a lista Person
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Lista vazia
**************************************************/
void freePerson(Person *person);
/*************************************************
 * Libera o Nó da lista
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Nó vazia
**************************************************/
void freeNodes(Node *node);
/*************************************************
 * Libera a estrutura Lista
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Lista vazia
**************************************************/
void freeList(List *list);

#endif
