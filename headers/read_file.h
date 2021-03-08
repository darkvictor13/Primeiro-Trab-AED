#ifndef READ_FILE
#define READ_FILE

#include "../structures/people_list_structure.h"
#include "people_list.h"

#include <stdlib.h>
#include <stdio.h>

/*************************************************
 * Lê os dados uma string de um arquivo
 * Retorno: String alocado
 * Pré-condição: Nenhum
 * Pós-condição: String alocado
**************************************************/
char* readDataString(FILE *file);
/*************************************************
 * Lê os dados da estrutura Person de um arquivo
 * Retorno: 1
 * Pré-condição: Nenhum
 * Pós-condição: Nenhum
**************************************************/
int readPerson(FILE *file, Person *data);
/*************************************************
 * Lê um arquivo e insere os dados na lista
 * Retorno: Lista com os dados do arquivo inserido
 * Pré-condição: Arquivo deve existir
 * Pós-condição: Arquivo lido e inserido na lista
**************************************************/
List *readFile(char *fn, List *list);

#endif
