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
    enterDataString("Telefone: ", node->data.phone);
    enterDataString("Endereço: ", node->data.address);
    enterDataString("Profisão: ", node->data.profession);

    printf("Prioridade: [1-5] ");
    scanf("%d", &node->data.priority);

    if(
        verifyName(node->data.name) ||
        verifyAge(node->data.age) ||
        verifyGenre(node->data.genre) ||
        verifyRG(node->data.rg) ||
        verifyCPF(node->data.cpf) ||
        verifyPhone(node->data.phone) ||
        verifyAddress(node->data.address) ||
        verifyProfession(node->data.profession) ||
        verifyPriority(node->data.priority)
    ) {
        node->data.dose = 0;
        insertPerson(registry->people, node->data);
    }else{

    }

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

        char answer[2];
        printf("Deseja remover o registro de %s? [Y/N] ", person->data.name);
        scanf("%s", answer);

        if( answer[0] == 'Y' || answer[0] == 'y' ) {
            removeNode(registry->people, person);
        }

    }else{
        printf("Pessoa não encontrada.");
    }
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
    printf("    Imprimir relatório\n");
    printf(" -------------------------\n\n");

    printf(" Tipos de relatórios: \n");
    printf(" -------------------\n");
    printf("    1 - Relatório de estoque.\n");
    printf("    2 - Habiatntes com a primeira dose.\n");
    printf("    3 - Habitantes com a segunda dose.\n");
    printf("    4 - Habitantes sem vacinar.\n");
    printf("    5 - Habitantes por grupo de risco.\n\n");

    char answer;

    printf(" Selecione um tipo de relatório: [1-5] ");
    scanf("%c", &answer);

    switch(answer) {
        case '1':
            reportStock(&registry->vaccineStock);
        break;

        case '2':
            reportFirstDose(registry->people);
        break;
        
        case '3':
            reportSecondDose(registry->people);
        break;
        
        case '4':
            reportWithoutVaccine(registry->people);
        break;
        
        case '5':
            reportGroups(registry->people);
        break;

        default:
            printf("Tipo de relatório não identificado.\n");
    }

    getChar();
}
