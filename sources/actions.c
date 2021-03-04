#include "../headers/actions.h"

char* enterDataString(char *message) {
    char *value = (char*)malloc(MAX_LEN * sizeof(char));

    printf(message);
    scanf("%[^\n]%*c", value);
    
    int len = strlen(value);
    
    value = (char*)realloc(value, (len + 1) * sizeof(char));
    value[len] = '\0';

    return value;
}

void registerHabitant(Registry *registry) {
    system(clear);
    printf(" -------------------------\n");
    printf("    Registrar habiatnte\n");
    printf(" -------------------------\n\n");

    Node *node = allocPerson();

    node->data.name = enterDataString("Nome: ");

    printf("Idade: ");
    scanf("%d%*c", &node->data.age);
    
    printf("Gênero: [M/F] ");
    scanf("%c%*c", &node->data.genre);
    
    node->data.rg = enterDataString("RG: ");
    node->data.cpf = enterDataString("CPF: ");
    node->data.phone = enterDataString("Telefone: ");
    node->data.address = enterDataString("Endereço: ");
    node->data.profession = enterDataString("Profisão: ");

    printf("Prioridade: [1-5] ");
    scanf("%d%*c", &node->data.priority);

    if( verifyPerson(node->data) ) {
        node->data.dose = 0;
        node->data.vaccine = NULL;
        insertPerson(registry->people, node->data);
    }else{
        printf("");
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

    if(person != NULL && registry->validGroup <= person->data.priority && person->data.dose < 2) {
        if(person->data.vaccine == NULL) {
            person->data.vaccine = findVaccineAvailable(registry->vaccine);
            
            if(person->data.vaccine == NULL) {
                printf("Não há vacinas em estoque.\n");
                getChar();
                return;
            }
            
            person->data.vaccine->inStock--;
            person->data.dose++;
            
            printf("Vacinação realizada com sucesso.\n");            
        }else{
            if(person->data.vaccine->inStock > 0) {
                person->data.vaccine->inStock--;
                person->data.dose++;

                printf("Vacinação realizada com sucesso.\n");
            }else{
                printf("Não tem %s em estoque.\n", person->data.vaccine->name);
            }
        }
    }else{
        printf("Pessoa não válida para vacinação.\n");
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

    printf("Atualemente os grupos de prioridade até %d estão permitidos de se vacinarr.\n");
    
    printf("Deseja liberar a vacinação de outro grupo? [Y/N] \n");
    scanf("%c", answer);

    if( answer == 'Y' || answer == 'y' ) {
        int group;
        printf("Grupo: ");
        scanf("%d", &group);
        registry->validGroup = group;
    }

    getChar();
}

void controlStock(Registry *registry) {
    system(clear);
    printf(" -------------------------\n");
    printf("     Controlar estoque\n");
    printf(" -------------------------\n\n");

    char name[MAX_LEN];

    printf("Vacina: ");
    scanf("%s", name);

    Vaccine *vaccine = findVaccine(registry->vaccine, name);

    if(vaccine == NULL) {
        printf("Vacina não encontrada.\n");
    }else{
        int amount;
        printf("Quntidade: ");
        scanf("%d", &amount);
        vaccine->inStock += amount;
    }

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

    char answer[2];

    printf(" Selecione um tipo de relatório: [1-5] ");
    scanf("%s", &answer);

    switch(answer[0]) {
        case '1':
            reportStock(registry->vaccine);
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
