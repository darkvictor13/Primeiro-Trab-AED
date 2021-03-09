#include "../headers/actions.h"
#include "../headers/menu.h"

/*************************************************
 * Alloca e realoca dados pra inserir na lista
 * Retorno: Retorna char alocado com o tamanho devido
 * Pré-condição: nenhuma
 * Pós-condição: dado é realocado com o tamanho definido
**************************************************/
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
/*************************************************
 * Insere um habitante na lista de cadastro
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Novo cadastro inserido
**************************************************/
void registerHabitant(Registry *registry) {
    system(CLEAR);
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
/*************************************************
 * Registra vacinação no CPF cadastrado
 * Retorno: Nenhum
 * Pré-condição: CPF estar registrado, estar no grupo de prioridade liberado e ter vacinas no estoque
 * Pós-condição: Menos uma vacina no estoque de vacinas
**************************************************/
void registerVaccination(Registry *registry) {
    system(CLEAR);
    printf(" -------------------------\n");
    printf("    Registrar vacinação\n");
    printf(" -------------------------\n\n");

    char cpf[LEN_CPF];

    printf("CPF: ");
    scanf("%s%*c", cpf);

    Node *person = searchByCPF(registry->people , cpf);

    if(person != NULL && registry->validGroup >= person->data.priority && person->data.dose < 2) {
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
/*************************************************
 * Remove o cadastro de um habitante
 * Retorno: Nenhum
 * Pré-condição: Habitante estar cadastrado
 * Pós-condição: Habitante removido
**************************************************/
void removeHabitant(Registry *registry) {
    system(CLEAR);
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
/*************************************************
 * Libera um grupo para vacinas
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Pode liberar ou não o(s) grupo(s) de prioridade
**************************************************/
void releaseGroup(Registry *registry) {
    system(CLEAR);
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
/*************************************************
 * Adiciona vacinas no estoque
 * Retorno: Nenhum
 * Pré-condição: Vacina estar no cadastro
 * Pós-condição: Vacinas adicionadas no estoque
**************************************************/
void controlStock(Registry *registry) {
    system(CLEAR);
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
/*************************************************
 * Imprime relatorios de estoque, habitantes com a primeira e segunda dose, habitantes sem vacinar e grupo de prioridade
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Os relatorios sao impressos no console
**************************************************/
void reports(Registry *registry) {
    system(CLEAR);
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
