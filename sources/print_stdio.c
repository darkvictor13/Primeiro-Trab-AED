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

void printList(List* tail) {
    char indentation[5] = "    \0";

    if (tail != NULL) {
        printf(" /========== Habitantes ==========\\\n");
        printPerson(tail->data, indentation);
        printf(" \\================================/\n\n");

        printList(tail->next);
    }
}
