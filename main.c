#include "headers/habitante.h"
#include "headers/lista.h"

int main (int argc, char *argv[]) {
	Lista *populacao = NULL;
	if (argc == 2) {
		//ler arquivo
		populacao = readFile(argv[1], populacao);
	}
	imprimir(populacao);
	return 0;
}
