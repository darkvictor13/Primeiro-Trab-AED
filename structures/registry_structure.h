#ifndef REGISTRY_STRUCTURE
#define REGISTRY_STRUCTURE

#include "people_list_structure.h"

// Estrutura Vacina para o controle das vacinas 
typedef struct vaccine {
	char *name;
	char *pharmaceutical;
	int inStock;
	struct vaccine *next;
}Vaccine;

// coronavac
// oxford
// sputnik
// pfizer
// moderna
// Estrutura para lista encadeada para o registro
typedef struct {
	List *people;
	Vaccine *vaccine;
	int validGroup;
}Registry;

#endif
