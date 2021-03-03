#include "../headers/verify.h"

int verifyName(char* name) {

    return 1;
}

int verifyAge(int age) {

    return 1;
}

int verifyGenre(char genre) {

    return 1;
}

int verifyRG(char* rg) {

    return 1;
}

int verifyCPF(char* cpf) {

    return 1;
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

    return 1;
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
