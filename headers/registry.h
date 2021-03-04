#ifndef REGISTRY
#define REGISTRY

#include "../structures/registry_structure.h"
#include "utils.h"

#include <string.h>

void initRegistry(Registry *registry);

char* allocString(char *message);

Vaccine* fillVaccine(char *name, char *pharmaceutical, int inStock);

void addVaccine(Registry *registry, char *name, char *pharmaceutical, int inStock);

void listVaccines(Vaccine *vaccine);

Vaccine* findVaccine(Vaccine *vaccine, char *name);

Vaccine* findVaccineAvailable(Vaccine *vaccine);

void listByDose(List *people, int dose);

void reportStock(Vaccine *vaccine);

void reportFirstDose(List *people);

void reportSecondDose(List *people);

void reportWithoutVaccine(List *people);

int countGroup(List *people, int group);

void reportGroups(List *people);

#endif