#include "../headers/registry.h"

void initRegistry(Registry *registry) {
    
	registry->people = NULL;
    registry->vaccine = NULL;
	registry->validGroup = 1;

    addVaccine(registry, "Coronavac", "", 0);
    addVaccine(registry, "Oxford", "", 0);
    addVaccine(registry, "Sputnik", "", 0);
    addVaccine(registry, "Pfizer", "", 0);
    addVaccine(registry, "Moderna", "", 0);
}

char* allocString(char *message) {
    char *string;

    int len = strlen(message);
    string = (char*)malloc(len * sizeof(char));

    strcpy(string, message);

    return string;
}

Vaccine* fillVaccine(char *name, char *pharmaceutical, int inStock) {
    Vaccine *vaccine = (Vaccine*)malloc(sizeof(Vaccine));

    vaccine->name = allocString(name);
    vaccine->pharmaceutical = allocString(pharmaceutical);
    vaccine->inStock = inStock;

    vaccine->next = NULL;

    return vaccine;
}

void addVaccine(Registry *registry, char *name, char *pharmaceutical, int inStock) {
    if(registry->vaccine == NULL) {
        registry->vaccine = fillVaccine(name, pharmaceutical, inStock);
    }else{
        Vaccine *vaccine = registry->vaccine;

        while(vaccine->next != NULL) {
            vaccine = vaccine->next;
        }

        vaccine->next = fillVaccine(name, pharmaceutical, inStock);
    }    
    return;
}

Vaccine* findVaccineAvailable(Vaccine *vaccine) {
    if(vaccine == NULL) {
        return NULL;
    }else{
        if(vaccine->inStock > 0) {
            return vaccine;
        }
        return findVaccineAvailable(vaccine->next);
    }
}

void listVaccines(Vaccine *vaccine) {
    if(vaccine != NULL) {
        printf("    %s \t %s \t %d\n", vaccine->name, vaccine->pharmaceutical, vaccine->inStock);

        if(vaccine->next != NULL) {
            listVaccines(vaccine->next);
        }
    }
}

Vaccine* findVaccine(Vaccine *vaccine, char *name) {
    if(vaccine == NULL) {
        return NULL;
    }

    if(!strcmp(vaccine->name, name)) {
        return vaccine;
    }

    findVaccine(vaccine->next, name);
}

void listByDose(List *people, int dose){
    Node *this = people->head;

    while(1) {
        if( this == NULL ) {
            return;
        }
        
        if( this->data.dose == dose ) {
            printf("    Nome: %s    CPF: %s\n", this->data.name, this->data.cpf);
        }
        
        this = this->next;
    }
}

void reportStock(Vaccine *vaccine) {
    system(clear);
    printf(" ------------------------------------------\n");
    printf("      Relatório de vacinas em estoque\n");
    printf(" ------------------------------------------\n\n");

    listVaccines(vaccine);
}

void reportFirstDose(List *people) {
    system(clear);
    printf(" ------------------------------------------------------------\n");
    printf("      Relatório de pessoas vacinadas com a primeira dose\n");
    printf(" ------------------------------------------------------------\n\n");

    listByDose(people, 1);
}

void reportSecondDose(List *people) {
    system(clear);
    printf(" -----------------------------------------------------------\n");
    printf("      Relatório de pessoas vacinadas com a segunda dose\n");
    printf(" -----------------------------------------------------------\n\n");

    listByDose(people, 2);
}

void reportWithoutVaccine(List *people) {
    system(clear);
    printf(" ------------------------------------------\n");
    printf("      Relatório de pessoas sem vacinar\n");
    printf(" ------------------------------------------\n\n");

    listByDose(people, 0);
}

int countGroup(List *people, int group) {
    Node *this = people->head;

    int count = 0;

    while(1) {
        if( this == NULL ) {
            return count;
        }
        
        if( this->data.priority == group ) {
            count++;
        }
        
        this = this->next;
    }
}

void reportGroups(List *people) {
    system(clear);
    printf(" ----------------------------------------\n");
    printf("      Relatório de pessoas por grupo\n");
    printf(" ----------------------------------------\n\n");

    int i;

    for(i = 1; i <= 5; i++) {
        printf("    Grupo %d: %d\n", i, countGroup(people, i));
    }
}
