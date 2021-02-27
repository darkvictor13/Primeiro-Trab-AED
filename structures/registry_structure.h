#ifndef REGISTRY_STRUCTURE
#define REGISTRY_STRUCTURE

#include "people_list_structure.h"

typedef struct {
	int coronavac;
	int oxford;
	int sputnik;
	int pfizer;
	int moderna;
}VaccineStock;

typedef struct {
	List *people;
	VaccineStock vaccineStock;
	int validGroup;
}Registry;

#endif
