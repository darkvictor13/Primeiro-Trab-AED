#include "../headers/verify.h"
#include <string.h>
#include <stdio.h>

int verifyName(char* name) {
    return (name != NULL && strlen(name) <= LEN_NAME);
}

int verifyAge(int age) {
    return ((age > 0) && (age < 120));
}

int verifyGenre(char genre) {
    return (genre == 'F' || 
            genre == 'M' ||
            genre == 'f' ||
            genre == 'm');
}

int verifyRG(char* rg) {
    return (rg != NULL && strlen(rg) <= LEN_RG);
}

int verifyCPF(char* cpf) {
    return (cpf != NULL && strlen(cpf) <= LEN_CPF);
}

int verifyPhone(char* phone) {
    return 1;
}

int verifyAddress(char* address) {
    return 1;
}

int verifyProfession(char* profession) {
    return 1;
}

int verifyPriority(int priority) {
    return (priority >= 1 && priority <= 5);
}

int verifyPerson(Person data) {
    if(
        verifyName(data.name) &&
        verifyAge(data.age) &&
        verifyGenre(data.genre) &&
        verifyRG(data.rg) &&
        verifyCPF(data.cpf) &&
        verifyPhone(data.phone) &&
        verifyAddress(data.address) &&
        verifyProfession(data.profession) &&
        verifyPriority(data.priority)
    ) {
        return 1;
    }

    return 0;
}
