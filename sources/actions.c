#include "../headers/actions.h"

void enterDataString(char *message, char *value) {
    value = (char*)malloc(MAX_LEN * sizeof(char));
    printf(message);
    scanf("%s", value);
    value = (char*)realloc(value, MAX_LEN * sizeof(char));
}

void registerHabitant(Registry *registry) {
    system(clear);
    printf(" -------------------------\n");
    printf("    Registrar habiatnte\n");
    printf(" -------------------------\n\n");

    Node *node = allocPerson();

    enterDataString("Nome: ", node->data.name);

    printf("Idade: ");
    scanf("%d", &node->data.age);
    
    printf("Gênero: [M/F] ");
    scanf("%c", &node->data.genre);
    
    enterDataString("RG: ", node->data.rg);

    enterDataString("CPF: ", node->data.cpf);

    enterDataString("RG: ", node->data.rg);

    enterDataString("Telefone: ", node->data.phone);

    enterDataString("Endereço: ", node->data.address);

    enterDataString("Profisão: ", node->data.profession);

    printf("Prioridade: [1-5] ");
    scanf("%d", &node->data.priority);

    // confirmar registro o nao

    getChar();
}

void registerVaccination(Registry *registry) {
    system(clear);
    printf(" -------------------------\n");
    printf("    Registrar vacinação\n");
    printf(" -------------------------\n\n");

    char cpf[LEN_CPF];

    printf("CPF: ");
    scanf("%s", cpf);

    Node *person = searchByCPF(registry->people , cpf);

    if(person != NULL) {
        printf("Name: %s\n", person->data.name);
    }
        
    getChar();
}

void removeHabitant(Registry *registry) {
    system(clear);
    printf(" -------------------------\n");
    printf("     Remover habiatnte\n");
    printf(" -------------------------\n\n");

    char cpf[LEN_CPF];

    printf("CPF: ");
    scanf("%s", cpf);

    Node *person = searchByCPF(registry->people , cpf);

    if(person != NULL) {

        char answer;
        printf("Deseja remover o registro de %s? [Y/N] \n", person->data.name);
        scanf("%c", answer);

        if( answer == 'Y' || answer == 'y' ) {
            //removePerson(person);
        }

    }else{
        printf("Pessoa não encontrada.");
    }
        
    getChar();
}

void releaseGroup(Registry *registry) {
    system(clear);
    printf(" -------------------------\n");
    printf("       Liberar grupo\n");
    printf(" -------------------------\n\n");

    char answer;

    printf("Atualemente os grupos de prioridade até %d estão permitidos de se vacinarr.]n");
    //printf("Deseja remover o registro de %s? [Y/N] \n", person->data.name);
    scanf("%c", answer);

    if( answer == 'Y' || answer == 'y' ) {
        //removePerson(person);
    }

    getChar();
}

void controlStock(Registry *registry) {
    system(clear);
    printf(" -------------------------\n");
    printf("     Controlar estoque\n");
    printf(" -------------------------\n\n");
    getChar();
}

void reports(Registry *registry) {
    system(clear);
    printf(" -------------------------\n");
    printf("     Imprimir registro\n");
    printf(" -------------------------\n\n");
    getChar();
}

//void enclose() {

//}
