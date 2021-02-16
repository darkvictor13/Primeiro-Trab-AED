#include "../headers/lista.h"
#include <stdlib.h>
#include <stdio.h>

Lista* allocPeople() {
	return (Lista *)malloc(sizeof(Lista));
}

Lista *inserir(Lista *l, People dado) {
	if (l == NULL) {
		Lista *novo_ultimo = allocPeople();
		novo_ultimo->dado = dado;
		novo_ultimo->prox = NULL;
		return novo_ultimo;
	}
	l->prox = inserir(l->prox, dado);
	return l;
}

int readAluno(FILE *arch, Lista *read) {
	if(fscanf(arch, "%[^;]%*c", read->dado.nome) == EOF){
		return 0;
	}
	
	char aux;
	fscanf(arch, "%d%*c", &read->dado.idade);
	fscanf(arch, "%c%*c", &read->dado.sexo);
	fscanf(arch, "%[^;]%*c", read->dado.rg);
	fscanf(arch, "%[^;]%*c", read->dado.cpf);
	fscanf(arch, "%c", &aux);
	if (aux != ';') {
		read->dado.tel[0] = aux;
		fscanf(arch, "%[^;]%*c", read->dado.tel+1);
	}
	fscanf(arch, "%c", &aux);
	if (aux != ';') {
		read->dado.endereco[0] = aux;
		fscanf(arch, "%[^;]%*c", read->dado.endereco+1);
	}
	fscanf(arch, "%c", &aux);
	if (aux != ';') {
		read->dado.endereco[0] = aux;
		fscanf(arch, "%[^;]%*c", read->dado.endereco+1);
	}
	fscanf(arch, "%hd%*c", &read->dado.prioridade);

	return 1;
}

Lista *readFile(char *fn, Lista *l) {
	FILE *arch = fopen(fn, "r");
	if (arch == NULL) {
		printf("Nome do arquivo inválido\n");
		return l;
	}
	
	for (Lista *p = l; readAluno(arch, p); p = p->prox) {
		;// enquanto conseguir ler novas pessoas
		// continua a leitura
	}
	
	fclose(arch);
	return l;
}
