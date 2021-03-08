#ifndef PRINT_STDIO
#define PRINT_STDIO

#include "../structures/people_list_structure.h"
#include "people_list.h"

#include <stdlib.h>
#include <stdio.h>

/*************************************************
 * Imprime se existe uma string
 * Retorno: Nenhum
 * Pré-condição: Se a string é valida
 * Pós-condição: Nenhum
**************************************************/
void printIfExist(char* string, char* identation, char* content);
/*************************************************
 * Imprime os dados de um habitante
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Nenhum
**************************************************/
void printPerson(Person data, char* identation);
/*************************************************
 * Imprime toda a lista de habitantes
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Nenhum
**************************************************/
void printList(List* list);

#endif
