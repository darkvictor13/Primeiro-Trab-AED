#include "../headers/utils.h"

/*************************************************
 * Lê um caractere
 * Retorno: caractere lido
 * Pré-condição: Nenhum
 * Pós-condição: Nenhum
**************************************************/
#ifdef linux
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
#else
char getChar() {
    
    DWORD mode, cc;
    HANDLE h = GetStdHandle( STD_INPUT_HANDLE );

    if (h == NULL) {
        return 0; // console not found
    }

    GetConsoleMode( h, &mode );
    SetConsoleMode( h, mode & ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT) );
    TCHAR c = 0;
    ReadConsole( h, &c, 1, &cc, NULL );
    SetConsoleMode( h, mode );
    return c;
}
#endif
/*************************************************
 * Imprime uma linha para os menus
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Nenhum
**************************************************/
void line (int lineLength) {

	printf("|");

	for (int i = 0; i < lineLength; i++) {
		printf("-");
	}

	printf("|\n");
}
/*************************************************
 * Imprime uma quantidade de espaços em branco
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Nenhum
**************************************************/
void fillSpaces (int numberOfSpaces) {
	
	for (int i = 0; i < numberOfSpaces; i++) {
		printf(" ");
	}
}
