#include "../headers/registry.h"

void initRegistry(Registry *registry) {
    
	registry->people = NULL;

    registry->vaccineStock.coronavac = 0;
	registry->vaccineStock.oxford = 0;
	registry->vaccineStock.sputnik = 0;
	registry->vaccineStock.pfizer = 0;
	registry->vaccineStock.moderna = 0;

	registry->validGroup = 1;
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

void reportStock(VaccineStock *vaccineStock) {
    system(clear);
    printf(" ------------------------------------------\n");
    printf("      Relatório de vacinas em estoque\n");
    printf(" ------------------------------------------\n\n");

    printf("    Coronavac: \t %d\n", vaccineStock->coronavac);
	printf("    Oxford: \t %d\n", vaccineStock->oxford);
	printf("    Sputnik: \t %d\n", vaccineStock->sputnik);
	printf("    Pfizer: \t %d\n", vaccineStock->pfizer);
	printf("    Moderna: \t %d\n", vaccineStock->moderna);
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

}

void reportGroups(List *people) {
    system(clear);
    printf(" ----------------------------------------\n");
    printf("      Relatório de pessoas por grupo\n");
    printf(" ----------------------------------------\n\n");

}
