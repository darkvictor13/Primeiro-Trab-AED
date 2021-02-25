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

char getChar() {

	char character = 0;
	struct termios old = {0};

	fflush(stdout);

	if(tcgetattr(0, &old)<0) {
		perror("tcsetattr()");
	}

	old.c_lflag&=~ICANON;
	old.c_lflag&=~ECHO;
	old.c_cc[VMIN]=1;
	old.c_cc[VTIME]=0;

	if(tcsetattr(0, TCSANOW, &old)<0) {
		perror("tcsetattr ICANON");
	}

	if(read(0,&character,1)<0) {
		perror("read()");
	}

	old.c_lflag|=ICANON;
	old.c_lflag|=ECHO;

	if(tcsetattr(0, TCSADRAIN, &old)<0) {
		perror ("tcsetattr ~ICANON");
	}

	return character;
}

void line (int lineLength) {

	printf("|");

	for (int i = 0; i < lineLength; i++) {
		printf("-");
	}

	printf("|\n");
}

void fillSpaces (int numberOfSpaces) {
	
	for (int i = 0; i < numberOfSpaces; i++) {
		printf(" ");
	}
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
            }

            if( option == 1 ) {
            }

            if( option == 2 ) {
            }
            
            if( option == 3 ) {
            }

            if( option == 4 ) {
            }

            if( option == 5 ) {
            }

            if( option == 6 ) {
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