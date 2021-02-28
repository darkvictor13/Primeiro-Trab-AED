#ifndef MENU
#define MENU

#define ENTER 10

#include "../structures/registry_structure.h"
#include "actions.h"
#include "utils.h"

void thisOption(char* string, int selected);

void initMessage();

void menuController(Registry *registry);

void menuMessage(int option);

void endMessage();

#endif