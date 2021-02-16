#include "habitante.h"
#include <stdlib.h>
#include <stdio.h>

Lista* allocPeople();

Lista *inserir(Lista *l, People dado);

int readAluno(FILE *arch, Lista *read);

Lista *readFile(char *fn, Lista *l);

void imprimir(Lista* l);
