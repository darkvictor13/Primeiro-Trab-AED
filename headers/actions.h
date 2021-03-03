#ifndef ACTIONS
#define ACTIONS

#include "../structures/registry_structure.h"
#include "../structures/people_list_structure.h"
#include "people_list.h"
#include "registry.h"
#include "verify.h"
#include "utils.h"
#include "stdio.h"

#include <stdio.h>

void registerHabitant(Registry *registry);

void registerVaccination(Registry *registry);

void removeHabitant(Registry *registry);

void releaseGroup(Registry *registry);

void controlStock(Registry *registry);

void reports(Registry *registry);

#endif