#include "../headers/actions.h"
#include "../headers/menu.h"

char* enterDataString(char *message) {
    char is_eol;
    printf(message);
    scanf("%c", &is_eol);
    if (is_eol == '\n') {
        return NULL;
    }
    char *value = (char*)malloc(MAX_LEN * sizeof(char));
    value[0] = is_eol;

    scanf("%[^\n]%*c", value + 1);
    
    int len = strlen(value);
    
    value = (char*)realloc(value, (len + 1) * sizeof(char));
    value[len] = '\0';

    printf("Li = %s\n", value);
    return value;
}

void registerHabitant(Registry *registry) {
    system(clear);
    printf(" -------------------------\n");
    printf("    Registrar habitante\n");
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
    node->data.profession = enterDataString("Profissão: ");

    printf("Prioridade: [1-5] ");
    scanf("%hd%*c", &node->data.priority);

    if( verifyPerson(node->data) ) {
        node->data.dose = 0;
        node->data.vaccine = NULL;
        insertPerson(registry->people, node->data);
    }else{
        printf("Cadastro inválido\n");
    }

    continueMenu();
}

void registerVaccination(Registry *registry) {
    system(clear);
    printf(" -------------------------\n");
    printf("    Registrar vacinação\n");
    printf(" -------------------------\n\n");

    char cpf[LEN_CPF];

    printf("CPF: ");
    scanf("%s%*c", cpf);

    Node *person = searchByCPF(registry->people , cpf);

    if(person != NULL && registry->validGroup <= person->data.priority && person->data.dose < 2) {
        if(person->data.vaccine == NULL) {
            person->data.vaccine = findVaccineAvailable(registry->vaccine);
            
            if(person->data.vaccine == NULL) {
                printf("Não há vacinas em estoque.\n");
                continueMenu();
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
        
    continueMenu();
}

void removeHabitant(Registry *registry) {
    system(clear);
    printf(" -------------------------\n");
    printf("     Remover habiatnte\n");
    printf(" -------------------------\n\n");

    char cpf[LEN_CPF];

    printf("CPF: ");
    scanf("%s%*c", cpf);

    Node *person = searchByCPF(registry->people , cpf);

    if(person != NULL) {

        char answer;
        printf("Deseja remover o registro de %s? [Y/N] ", person->data.name);
        scanf("%c%*c", &answer);

        if( answer == 'Y' || answer == 'y' ) {
            removeNode(registry->people, person);
        }

    }else{
        printf("Pessoa não encontrada.");
    }

    continueMenu();
}

void releaseGroup(Registry *registry) {
    system(clear);
    printf(" -------------------------\n");
    printf("       Liberar grupo\n");
    printf(" -------------------------\n\n");

    char answer;

    printf("Atualmente os grupos de prioridade até %d tem permissão de se vacinar.\n", registry->validGroup);
    
    printf("Deseja liberar a vacinação de outro grupo? [Y/N] ");
    scanf("%c%*c", &answer);

    if( answer == 'Y' || answer == 'y' ) {
        int group;
        printf("Grupo: ");
        scanf("%d%*c", &group);
        while ((group > 5) || (group < 1)) {
            printf("grupo inválido\n");
            printf("Grupo: ");
            scanf("%d%*c", &group);
        }
        registry->validGroup = group;
    }

    continueMenu();
}

void controlStock(Registry *registry) {
    system(clear);
    printf(" -------------------------\n");
    printf("     Controlar estoque\n");
    printf(" -------------------------\n\n");

    char name[MAX_LEN];

    printf("Vacina: ");
    scanf("%[^\n]%*c", name);

    Vaccine *vaccine = findVaccine(registry->vaccine, name);

    if(vaccine == NULL) {
        printf("Vacina não encontrada.\n");
    }else{
        int amount;
        printf("Quantidade: ");
        scanf("%d%*c", &amount);
        vaccine->inStock += amount;
    }

    continueMenu();
}

void reports(Registry *registry) {
    system(clear);
    printf(" -------------------------\n");
    printf("    Imprimir relatório\n");
    printf(" -------------------------\n\n");

    printf(" Tipos de relatórios: \n");
    printf(" -------------------\n");
    printf("    1 - Relatório de estoque.\n");
    printf("    2 - Habitantes com a primeira dose.\n");
    printf("    3 - Habitantes com a segunda dose.\n");
    printf("    4 - Habitantes sem vacinar.\n");
    printf("    5 - Habitantes por grupo de risco.\n\n");

    char answer;

    printf(" Selecione um tipo de relatório: [1-5] ");
    scanf("%c%*c", &answer);

    switch(answer) {
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

    continueMenu();
}
