#include "../headers/print_stdio.h"

void printIfExist(char* string, char* identation, char* content) {

    printf("%s%s", identation, string);

    if (isNull(content) || isEmptyString(content)) {
        printf("(não especificado).\n");
    }else {
        printf("%s.\n", content);
    }
}

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

void printList(List* list) {
    char indentation[5] = "    \0";

    for (; list->head != NULL; list->head = list->head->next) {
        printf(" /========== Habitantes ==========\\\n");
        printPerson(list->head->data, indentation);
        printf(" \\================================/\n\n");
    }
}
