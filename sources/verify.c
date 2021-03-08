#include "../headers/verify.h"
#include <string.h>
#include <stdio.h>

/*************************************************
 * Verifica o nome escrito do habitante
 * Retorno: Booleano
 * Pré-condição: Nome diferente de NULL e menor ou igual o tamanho da string
 * Pós-condição: Nenhum
**************************************************/
int verifyName(char* name) {
    return (name != NULL && strlen(name) <= LEN_NAME);
}
/*************************************************
 * Verifica a idade escrita do habitante
 * Retorno: Booleano
 * Pré-condição: Idade maior que zero e menor que cento e vinte
 * Pós-condição: Nenhum
**************************************************/
int verifyAge(int age) {
    return ((age > 0) && (age < 120));
}
/*************************************************
 * Verifica o genero escrito do habitante
 * Retorno: Booleano
 * Pré-condição: Genero definido por f ou m
 * Pós-condição: Nenhum
**************************************************/
int verifyGenre(char genre) {
    return (genre == 'F' || 
            genre == 'M' ||
            genre == 'f' ||
            genre == 'm');
}
/*************************************************
 * Verifica o rg escrito do habitante
 * Retorno: Booleano
 * Pré-condição: RG diferente de NULL e menor ou igual o tamanho da string
 * Pós-condição: Nenhum
**************************************************/
int verifyRG(char* rg) {
    return (rg != NULL && strlen(rg) <= LEN_RG);
}
/*************************************************
 * Verifica o CPF escrito do habitante
 * Retorno: Booleano
 * Pré-condição: CPF diferente de NULL e menor ou igual o tamanho da string
 * Pós-condição: Nenhum
**************************************************/
int verifyCPF(char* cpf) {
    return (cpf != NULL && strlen(cpf) <= LEN_CPF);
}

/*************************************************
 * Verifica a prioridade escrita do habitante
 * Retorno: Booleano
 * Pré-condição: Prioridade maior ou igual a 1 e menor ou igual a 5
 * Pós-condição: Nenhum
**************************************************/
int verifyPriority(int priority) {
    return (priority >= 1 && priority <= 5);
}
/*************************************************
 * Verifica o cadastro escrito do habitante
 * Retorno: 1
 * Pré-condição: Se todos forem verdadeiro
 * Pós-condição: Nenhum
**************************************************/
int verifyPerson(Person data) {
    if(
        verifyName(data.name) &&
        verifyAge(data.age) &&
        verifyGenre(data.genre) &&
        verifyRG(data.rg) &&
        verifyCPF(data.cpf) &&
        verifyPriority(data.priority)
    ) {
        return 1;
    }

    return 0;
}
