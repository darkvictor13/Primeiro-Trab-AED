#include "../headers/menu.h"

void thisOption(char* string, int selected) {

    printf(" [");

    if( selected ) {
        printf("x");
    }else{
        printf(" ");
    }

    printf("] %s\n", string);
}

void initMessage() {

    system("clear");

    printf("\n");
    printf(" ----------------------------------------\n");
    printf(" ----------------------------------------\n");
    printf(" -------- Vaccine Control System --------\n");
    printf(" ----------------------------------------\n");
    printf(" ---------------------------- Since 2021.\n");
    printf(" Press enter to continue ... \n\n\n");

    getChar();
}

void menuController() {

    int option = 0;
    char selected;
    
    initMessage();

    system("clear");
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
                registerHabitant();
            }

            if( option == 1 ) {
                registerVaccination();
            }

            if( option == 2 ) {
                removeHabitant();
            }
            
            if( option == 3 ) {
                releaseGroup();
            }

            if( option == 4 ) {
                controlStock();
            }

            if( option == 5 ) {
                reports();
            }

            if( option == 6 ) {
                endMessage();
                return;
            }
        }

        system("clear");
        menuMessage(option);

        selected = getChar();
    }
}

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

void endMessage() {

    system("clear");

    printf("\n");
    printf("-------------------------------------------\n");
    printf("----- Program terminated successfully -----\n");
    printf("-------------------------------------- End.\n\n");
}