#ifndef PRINT_STDIO
#define PRINT_STDIO

#include "../structures/people_list_structure.h"
#include "people_list.h"

#include <stdlib.h>
#include <stdio.h>

/**
* Function - imprime um dado do tipo string
*
* @authors - mGuerra, mLucas, vAlmeida
* @version - 1.0
* @since - 1.0
* 
* @pre-conditions - uma string
* @pos-conditions - nenhuma
*
* @param -
*
* @return -
*/
void printIfExist(char* string, char* content, char* identation);

/**
* Function - imprime os dados de um habitante
*
* @authors - mGuerra, mLucas, vAlmeida
* @version - 1.0
* @since - 1.0
* 
* @pre-conditions - os dados de uma pessoa válida
* @pos-conditions - nenhuma
*
* @param -
*
* @return -
*/
void printPerson(Person data, char* identation);

/**
* Function - imprime a lista de pessoas
*
* @authors - mGuerra, mLucas, vAlmeida
* @version - 1.0
* @since - 1.0
*
* @pre-conditions - a lista deve possuir pelomenos um elemento
* @pos-conditions - nenhuma
*
* @param -
*
* @return - nenhum
*/
void printList(List* list);

#endif