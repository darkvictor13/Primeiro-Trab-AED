#ifndef REGISTRY
#define REGISTRY

#include "../structures/registry_structure.h"
#include "utils.h"

void initRegistry(Registry *registry);

void listByDose(List *people, int dose);

void reportStock(VaccineStock *vaccineStock);

void reportFirstDose(List *people);

void reportSecondDose(List *people);

void reportWithoutVaccine(List *people);

int countGroup(List *people, int group);

void reportGroups(List *people);

#endif