#ifndef MENU
#define MENU

#define ENTER 10

#include "actions.h"
#include "utils.h"

void thisOption(char* string, int selected);

void initMessage();

void menuController();

void menuMessage(int option);

void endMessage();

#endif