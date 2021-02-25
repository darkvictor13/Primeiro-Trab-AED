#ifndef UTILS
#define UTILS

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
#include <termios.h>

char getChar();

void line (int lineLength);

void fillSpaces (int numberOfSpaces);

#endif
