#include "../headers/menu.h"

/*************************************************
 * Selecionar a opção desejada
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Nenhum
**************************************************/
void thisOption(char* string, int selected) {

    printf(" [");

    if( selected ) {
        printf("x");
    }else{
        printf(" ");
    }

    printf("] %s\n", string);
}
/*************************************************
 * Muda para o menu principal ao teclar Enter
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Muda para o menu principal
**************************************************/
void continueMenu() {
    printf("\n\nAperte [ENTER] para continuar ... \n\n\n");
    getChar();
}
/*************************************************
 * Interface do programa
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: 
**************************************************/
void initMessage() {

    system(CLEAR);

    printf("\n");
    printf(" ------------------------------------------------\n");
    printf(" ------------------------------------------------\n");
    printf(" -------- Sistema de Controle de Vacinas --------\n");
    printf(" ------------------------------------------------\n");
    printf(" ------------------------------------ Desde 2021.\n");
    continueMenu();
}
/*************************************************
 * Controla o menu principal
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Navega para a opção selecionada
**************************************************/
void menuController(Registry *registry) {

    int option = 0;
    char selected;
    
    initMessage();

    system(CLEAR);
    menuMessage(option);

    selected = getChar();

    while( 1 ) {

        if( selected == UP_DEFAULT && option > 0 ) {
            option--;
        }

        if( selected == DOWN_DEFAULT && option < 6 ) {
            option++;
        }

        if( selected == ENTER ) {
            if( option == 0 ) {
                registerHabitant(registry);
            }

            if( option == 1 ) {
                registerVaccination(registry);
            }

            if( option == 2 ) {
                removeHabitant(registry);
            }
            
            if( option == 3 ) {
                releaseGroup(registry);
            }

            if( option == 4 ) {
                controlStock(registry);
            }

            if( option == 5 ) {
                reports(registry);
            }

            if( option == 6 ) {
                endMessage();
                return;
            }
        }

        system(CLEAR);
        menuMessage(option);

        selected = getChar();

        //nanosleep(10);
    }
}

/*************************************************
 * Menu principal
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Imprime no console o menu principal
**************************************************/
void menuMessage(int option) {

    printf(" -------------------------\n");
    printf("           Menu \n");
    printf(" -------------------------\n");

    thisOption("Cadastrar habitante", option == 0 );
    thisOption("Registrar vacinação", option == 1 );
    thisOption("Retirar habitante", option == 2 );
    thisOption("Liberar grupo", option == 3 );
    thisOption("Controlar estoque", option == 4 );
    thisOption("Emitir relatórios", option == 5 );
    thisOption("Encerrar", option == 6 );
    
    printf(" -------------------------\n");
}
/*************************************************
 * Interface de encerramento do programa
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Imprime no console que o programa foi encerrado
**************************************************/
void endMessage() {

    system(CLEAR);

    printf("\n");
    printf("------------------------------------------\n");
    printf("----- Programa encerrado com sucesso -----\n");
    printf("------------------------------------------\n");
}
