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
	char aux;
	if(fscanf(arch, "%c", &aux) == EOF){
		return 0;
	}
	
	read->dado.nome = (char*)malloc(MAX_TAM * sizeof(char));
	read->dado.nome[0] = aux;
	fscanf(arch, "%[^;]%*c", read->dado.nome);
	read->dado.nome = (char*)realloc(read->dado.nome, MAX_TAM * sizeof(char));

	fscanf(arch, "%d%*c", &read->dado.idade);
	fscanf(arch, "%c%*c", &read->dado.sexo);
	fscanf(arch, "%[^;]%*c", read->dado.rg);
	fscanf(arch, "%[^;]%*c", read->dado.cpf);
	fscanf(arch, "%c", &aux);
	if (aux != ';') {
		read->dado.tel[0] = aux;
		fscanf(arch, "%[^;]%*c", read->dado.tel+1);
	}else{
		read->dado.tel[0] = '\0';
	}
	fscanf(arch, "%c", &aux);
	if (aux != ';') {
		read->dado.endereco = (char*)malloc(MAX_TAM * sizeof(char));
		read->dado.endereco[0] = aux;
		fscanf(arch, "%[^;]%*c", read->dado.endereco+1);
		read->dado.endereco = (char*)realloc(read->dado.endereco, MAX_TAM * sizeof(char));
	}else {
		read->dado.endereco = NULL;
	}
	fscanf(arch, "%c", &aux);
	if (aux != ';') {
		read->dado.profissao = (char*)malloc(MAX_TAM * sizeof(char));
		read->dado.profissao[0] = aux;
		fscanf(arch, "%[^;]%*c", read->dado.profissao+1);
		read->dado.profissao = (char*)realloc(read->dado.profissao, MAX_TAM * sizeof(char));
	}else {
		read->dado.profissao = NULL;
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
	
	// enquanto conseguir ler novas pessoas
	// continua a leitura
	for (Lista *p = l; readAluno(arch, p); p = p->prox) {
		p->prox = allocPeople();
	}
	
	fclose(arch);
	return l;
}


void imprimir(Lista* l) {
	if (l != NULL) {
		printf("===HABITANTE===\n");
		printf("Nome = %s\n", l->dado.nome);
		printf("Idade = %d\n", l->dado.idade);
		printf("Sexo = %c\n", l->dado.sexo);
		printf("RG = %s\n", l->dado.rg);
		printf("CPF = %s\n", l->dado.cpf);
		printf("Endereço = %s\n", l->dado.endereco);
		printf("Profissão = %s\n", l->dado.profissao);
		printf("Prioridade = %hd\n", l->dado.prioridade);
		printf("===============\n\n");
		imprimir(l->prox);
	}
}
