#ifndef MENU
#define MENU

#define UP_DEFAULT 'w'
#define DOWN_DEFAULT 's'
#define RIGHT_DEFAULT 'd'
#define LEFT_DEFAULT 'a'

#define UP_VIM 'k'
#define DOWN_VIM 'j'

#define ENTER 10

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <termios.h>

void thisOption(char* string, int selected);

char getChar();

void line (int lineLength);

void fillSpaces (int numberOfSpaces);

void initMessage();

void menuController();

void menuMessage(int option);

void endMessage();

#endif