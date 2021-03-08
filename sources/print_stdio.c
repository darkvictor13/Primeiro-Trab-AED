#include "../headers/print_stdio.h"

/*************************************************
 * Imprime se existe uma string
 * Retorno: Nenhum
 * Pré-condição: Se a string é valida
 * Pós-condição: Nenhum
**************************************************/
void printIfExist(char* string, char* identation, char* content) {

    printf("%s%s", identation, string);

    if (isNull(content) || isEmptyString(content)) {
        printf("(não especificado).\n");
    }else {
        printf("%s.\n", content);
    }
}
/*************************************************
 * Imprime os dados de um habitante
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Nenhum
**************************************************/
void printPerson(Person data, char* identation) {

    printIfExist("Nome: ", identation, data.name);
    
    printf("%sIdade: %d.\n", identation, data.age);
    printf("%sSexo: %c.\n", identation, data.genre);

    printIfExist("RG: ", identation, data.rg);
    printIfExist("CPF: ", identation, data.cpf);

    printIfExist("Telefone: ", identation, data.phone);
    printIfExist("Endereço: ", identation, data.address);
    printIfExist("Profissão: ", identation, data.profession);
    
    printf("%sPrioridade: %hd.\n", identation, data.priority);
}
/*************************************************
 * Imprime toda a lista de habitantes
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Nenhum
**************************************************/
void printList(List* list) {
    char indentation[5] = "    \0";

    for (; list->head != NULL; list->head = list->head->next) {
        printf(" /========== Habitantes ==========\\\n");
        printPerson(list->head->data, indentation);
        printf(" \\================================/\n\n");
    }
}
