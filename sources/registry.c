#include "../headers/registry.h"
/*************************************************
 * Inicia o registro de vacinação
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Nenhum
**************************************************/
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
/*************************************************
 * Aloca a string
 * Retorno: String alocada
 * Pré-condição: Nenhum
 * Pós-condição: String alocada
**************************************************/
char* allocString(char *message) {
    char *string;

    int len = strlen(message);
    string = (char*)malloc(len * sizeof(char));

    strcpy(string, message);

    return string;
}
/*************************************************
 * Inicia o registro de vacinação
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Nenhum
**************************************************/
Vaccine* fillVaccine(char *name, char *pharmaceutical, int inStock) {
    Vaccine *vaccine = (Vaccine*)malloc(sizeof(Vaccine));

    vaccine->name = allocString(name);
    vaccine->pharmaceutical = allocString(pharmaceutical);
    vaccine->inStock = inStock;

    vaccine->next = NULL;

    return vaccine;
}
/*************************************************
 * Adiciona vacina
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Vacina adicionada no registro
**************************************************/
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
/*************************************************
 * Procura vacina disponivel
 * Retorno: Vacina com estoque maior que zero
 * Pré-condição: Ter vacinas no estoque
 * Pós-condição: Vacina encontrada
**************************************************/
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
/*************************************************
 * Imprime lista de vacinas
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: As vacinas são impressos no console
**************************************************/
void listVaccines(Vaccine *vaccine) {
    if(vaccine != NULL) {
        printf("    %s \t %s \t %d\n", vaccine->name, vaccine->pharmaceutical, vaccine->inStock);

        if(vaccine->next != NULL) {
            listVaccines(vaccine->next);
        }
    }
}
/*************************************************
 * Busca vacina
 * Retorno: Vacina encontrada
 * Pré-condição: Conter vacinas registradas
 * Pós-condição: Vacina encontrada
**************************************************/
Vaccine* findVaccine(Vaccine *vaccine, char *name) {
    if(vaccine == NULL) {
        return NULL;
    }

    if(!strcmp(vaccine->name, name)) {
        return vaccine;
    }

    findVaccine(vaccine->next, name);
}
/*************************************************
 * Imprime dados da estrutura Person
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Imprime no console os dados
**************************************************/
void printPersonData(char *name, char *cpf) {
    int i;
    int qnt_spaces =  LEN_NAME - strlen(name);
    printf("    Nome: %s", name);
    for(i = 0; i < qnt_spaces; i++) {
        printf("%c", ' ');
    }
    printf("CPF: %s\n", cpf);
}
    /*************************************************
 * Lista as pessoas que receberam as doses da vacina
 * Retorno: Nenhum
 * Pré-condição: Habitantes que receberam as doses
 * Pós-condição: Nenhum
**************************************************/
void listByDose(List *people, int dose){
    Node *this = people->head;

    while(1) {
        if( this == NULL ) {
            return;
        }
        
        if( this->data.dose == dose ) {
            printPersonData(this->data.name, this->data.cpf);
        }
        
        this = this->next;
    }
}
/*************************************************
 * Relatorio de vacinas em estoque
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Imprime as vacinas e o seu estoque
**************************************************/
void reportStock(Vaccine *vaccine) {
    system(clear);
    printf(" ------------------------------------------\n");
    printf("      Relatório de vacinas em estoque\n");
    printf(" ------------------------------------------\n\n");

    listVaccines(vaccine);
}
/*************************************************
 * Relatorio de pessoas vacinadas com a primeira dose
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Imprime no console as pessoas vacinadas com a primeira dose
**************************************************/
void reportFirstDose(List *people) {
    system(clear);
    printf(" ------------------------------------------------------------\n");
    printf("      Relatório de pessoas vacinadas com a primeira dose\n");
    printf(" ------------------------------------------------------------\n\n");

    listByDose(people, 1);
}
/*************************************************
 * Relatorio de pessoas vacinadas com a segunda dose
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Imprime no console as pessoas vacinadas com a segunda dose
**************************************************/
void reportSecondDose(List *people) {
    system(clear);
    printf(" -----------------------------------------------------------\n");
    printf("      Relatório de pessoas vacinadas com a segunda dose\n");
    printf(" -----------------------------------------------------------\n\n");

    listByDose(people, 2);
}
/*************************************************
 * Relatorio de pessoas não vacinadas
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Imprime no console as pessoas não vacinadas
**************************************************/
void reportWithoutVaccine(List *people) {
    system(clear);
    printf(" ------------------------------------------\n");
    printf("      Relatório de pessoas sem vacinar\n");
    printf(" ------------------------------------------\n\n");

    listByDose(people, 0);
}
/*************************************************
 * Conta quantas pessoas estao em um grupo de prioridade
 * Retorno: Quantidade de pessoas no grupo prioritario
 * Pré-condição: Nenhum
 * Pós-condição: Quantidade de pessoas contadas em um grupo
**************************************************/
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
/*************************************************
 * Relatorio de pessoas por grupo
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Imprime no console as pessoas por grupo prioritario
**************************************************/
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
