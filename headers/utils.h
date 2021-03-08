#ifndef UTILS
#define UTILS

#ifdef linux
#define CLEAR "clear"
#else
#define CLEAR "cls"
#endif

#define UP_DEFAULT 'w'
#define DOWN_DEFAULT 's'
#define RIGHT_DEFAULT 'd'
#define LEFT_DEFAULT 'a'

#define UP_VIM 'k'
#define DOWN_VIM 'j'

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

#ifdef linux
#include <termios.h>
#else
#include <conio.h>
#endif


/*************************************************
 * Lê um caractere
 * Retorno: caractere lido
 * Pré-condição: Nenhum
 * Pós-condição: Nenhum
**************************************************/
char getChar();
/*************************************************
 * Imprime uma linha para os menus
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Nenhum
**************************************************/
void line (int lineLength);
/*************************************************
 * Imprime uma quantidade de espaços em branco
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Nenhum
**************************************************/
void fillSpaces (int numberOfSpaces);

#endif
