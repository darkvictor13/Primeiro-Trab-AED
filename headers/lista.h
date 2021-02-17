#include <stdlib.h>
#include <stdio.h>

#include "habitante.h"

/*************************************************
 * Aloca o espaço de memória para guardar 1 pessoa
 * Retorno: o local de memória da pessoa
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
**************************************************/
Lista* allocPeople();

/*************************************************
 * Insere no fim da lista um único elemento
 * Retorno: o local de memória da cabeça da lista
 * Pré-condição: Lista não é vazia
 * Pós-condição: Lista possui um elemento a mais no final
**************************************************/
Lista *inserir(Lista *l, People dado);

/*************************************************
 * Remove o último elemento alocado da lista
 * Retorno: Nenhum
 * Pré-condição: Lista é valida
 * Pós-condição: Lista fica sem seu último elemento
**************************************************/
void removeLast(Lista *l);

/*************************************************
 * Lê uma pessoa do arquivo
 * Retorno: booleano (leitura realizada com sucesso)
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
**************************************************/
int readPeople(FILE *arch, People *dado);

/*************************************************
 * Lê carrega os dados de um arquivo texto para a
 * estrutura lista
 * Retorno: o local de memória da cabeça da lista
 * Pré-condição: Nenhuma
 * Pós-condição: Lista é carregada com as informações
 *               condidas no arquivo
**************************************************/
Lista *readFile(char *fn, Lista *l);

/*************************************************
 * Informa se uma string é vazia
 * Retorno: booleano
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
**************************************************/
int isEmpthyString(char s[]);

/*************************************************
 * Informa se um ponteiro é Nulo
 * Retorno: booleano
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
**************************************************/
int isNull (void * dado);

/*************************************************
 * Imprime os dados de um único habitante
 * Retorno: Nenhum
 * Pré-condição: dados da pessoa são válidos
 * Pós-condição: Nenhuma
**************************************************/
void printPeople(People dado);

/*************************************************
 * Imprime toda a lista encadeada com os dados
 * Retorno: Nenhum
 * Pré-condição: Lista não está vazia
 * Pós-condição: Nenhuma
**************************************************/
void printList(Lista* l);
