#ifndef VERIFY
#define VERIFY

#include "../structures/people_list_structure.h"

/*************************************************
 * Verifica o nome escrito do habitante
 * Retorno: Booleano
 * Pré-condição: Nome diferente de NULL e menor ou igual o tamanho da string
 * Pós-condição: Nenhum
**************************************************/
int verifyName(char* name);
/*************************************************
 * Verifica a idade escrita do habitante
 * Retorno: Booleano
 * Pré-condição: Idade maior que zero e menor que cento e vinte
 * Pós-condição: Nenhum
**************************************************/
int verifyAge(int age);
/*************************************************
 * Verifica o genero escrito do habitante
 * Retorno: Booleano
 * Pré-condição: Genero definido por f ou m
 * Pós-condição: Nenhum
**************************************************/
int verifyGenre(char genre);
/*************************************************
 * Verifica o rg escrito do habitante
 * Retorno: Booleano
 * Pré-condição: RG diferente de NULL e menor ou igual o tamanho da string
 * Pós-condição: Nenhum
**************************************************/
int verifyRG(char* rg);
/*************************************************
 * Verifica o CPF escrito do habitante
 * Retorno: Booleano
 * Pré-condição: CPF diferente de NULL e menor ou igual o tamanho da string
 * Pós-condição: Nenhum
**************************************************/
int verifyCPF(char* cpf);

/*************************************************
 * Verifica a prioridade escrita do habitante
 * Retorno: Booleano
 * Pré-condição: Prioridade maior ou igual a 1 e menor ou igual a 5
 * Pós-condição: Nenhum
**************************************************/
int verifyPriority(int priority);
/*************************************************
 * Verifica o cadastro escrito do habitante
 * Retorno: 1
 * Pré-condição: Se todos forem verdadeiro
 * Pós-condição: Nenhum
**************************************************/
int verifyPerson(Person data);

#endif
