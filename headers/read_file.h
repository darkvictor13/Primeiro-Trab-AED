#ifndef READ_FILE
#define READ_FILE

#include "../structures/people_list_structure.h"
#include "people_list.h"

#include <stdlib.h>
#include <stdio.h>

/**
* Function - realiza a leitura de uma pessoa
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
* @return bool - leitura realizada com sucesso
*/
int readPerson(FILE *file, Person *data);

/**
* Function - carrega os dados de um arquivo de texto para a lista indicada
*
* @authors - mGuerra, mLucas, vAlmeida
* @version - 1.0
* @since - 1.0
*
* @pre-conditions - nenhuma
* @pos-conditions - lista com as informações carregadas a partir do arquivo
*
* @param -
* @param -
*
* @return - o local de memória da cabeça da lista
*/
List *readFile(char *fn, List *list);

#endif