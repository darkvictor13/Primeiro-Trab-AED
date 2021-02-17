#include "../headers/lista.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*************************************************
 * Aloca o espaço de memória para guardar 1 pessoa
 * Retorno: o local de memória da pessoa
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
**************************************************/
Lista* allocPeople() {
	return (Lista *)malloc(sizeof(Lista));
}

/*************************************************
 * Insere no fim da lista um único elemento
 * Retorno: o local de memória da cabeça da lista
 * Pré-condição: Lista não é vazia
 * Pós-condição: Lista possui um elemento a mais no final
**************************************************/
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

/*************************************************
 * Remove o último elemento alocado da lista
 * Retorno: Nenhum
 * Pré-condição: Lista possuí pelo menos 2 elementos
 * Pós-condição: Lista fica sem seu último elemento
**************************************************/
void removeLast(Lista *l) {
	while (l->prox->prox != NULL) {
		l = l->prox;
	}
	// l == penúltimo item da lista
	// l->prox é o ultimo item da lista
	free(l->prox);
	l->prox = NULL;
}

/*************************************************
 * Lê uma pessoa do arquivo
 * Retorno: booleano (leitura realizada com sucesso)
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
**************************************************/
int readPeople(FILE *arch, People *dado) {
	char aux;
	if(fscanf(arch, "%c", &aux) == EOF){
		// falha ao ler o arquivo
		return 0;
	}
	
	int tam;
	dado->nome = (char*)malloc(MAX_TAM * sizeof(char));
	dado->nome[0] = aux;
	fscanf(arch, "%[^;]%*c", dado->nome+1);
	tam = strlen(dado->nome);
	dado->nome = (char*)realloc(dado->nome, tam * sizeof(char) + 1);
	dado->nome[tam] = '\0';

	fscanf(arch, "%d%*c", &dado->idade);
	fscanf(arch, "%c%*c", &dado->sexo);
	fscanf(arch, "%[^;]%*c", dado->rg);
	dado->rg[TAM_RG - 1] = '\0';
	fscanf(arch, "%[^;]%*c", dado->cpf);
	dado->cpf[TAM_CPF - 1] = '\0';
	fscanf(arch, "%c", &aux);
	if (aux != ';') {
		dado->tel[0] = aux;
		fscanf(arch, "%[^;]%*c", dado->tel+1);
	}else{
		dado->tel[0] = '\0';
	}
	fscanf(arch, "%c", &aux);
	if (aux != ';') {
		dado->endereco = (char*)malloc(MAX_TAM * sizeof(char));
		dado->endereco[0] = aux;
		fscanf(arch, "%[^;]%*c", dado->endereco+1);
		dado->endereco = (char*)realloc(dado->endereco, MAX_TAM * sizeof(char));
	}else {
		dado->endereco = NULL;
	}
	fscanf(arch, "%c", &aux);
	if (aux != ';') {
		dado->profissao = (char*)malloc(MAX_TAM * sizeof(char));
		dado->profissao[0] = aux;
		fscanf(arch, "%[^;]%*c", dado->profissao+1);
		dado->profissao = (char*)realloc(dado->profissao, MAX_TAM * sizeof(char));
	}else {
		dado->profissao = NULL;
	}
	fscanf(arch, "%hd%*r", &dado->prioridade);

	//leitura de 1 habitante realizada com sucesso
	return 1;
}

/*************************************************
 * Lê carrega os dados de um arquivo texto para a
 * estrutura lista
 * Retorno: o local de memória da cabeça da lista
 * Pré-condição: Nenhuma
 * Pós-condição: Lista é carregada com as informações
 *               condidas no arquivo
**************************************************/
Lista *readFile(char *fn, Lista *l) {
	FILE *arch = fopen(fn, "r");
	if (arch == NULL) {
		printf("Nome do arquivo inválido\n");
		return l;
	}

	if (l == NULL) {
		l = allocPeople();
	}
	Lista *p = l;
	// enquanto conseguir ler novas pessoas continua a leitura
	while (readPeople(arch, &p->dado)) {
		// o último elemento saí com espaço alocado
		p->prox = allocPeople();
		p = p->prox;
	}
	
	removeLast(l);
	
	fclose(arch);
	return l;
}

/*************************************************
 * Informa se uma string é vazia
 * Retorno: booleano
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
**************************************************/
int isEmpthyString(char s[]) {
	return s[0] == '\0';
}

/*************************************************
 * Informa se um ponteiro é Nulo
 * Retorno: booleano
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
**************************************************/
int isNull (void * dado) {
	return dado == NULL;
}

/*************************************************
 * Imprime os dados de um único habitante
 * Retorno: Nenhum
 * Pré-condição: dados da pessoa são válidos
 * Pós-condição: Nenhuma
**************************************************/
void printPeople(People dado) {
	printf("Nome       = %s\n", dado.nome);
	printf("Idade      = %d\n", dado.idade);
	printf("Sexo       = %c\n", dado.sexo);
	printf("RG         = %s\n", dado.rg);
	printf("CPF        = %s\n", dado.cpf);
	printf("Telefone   = ");
	if (isEmpthyString(dado.tel)) {
		printf("(Não informado)\n");
	}else {
		printf("%s\n", dado.tel);
	}
	printf("Endereço   = ");
	if (isNull(dado.endereco)) {
		printf("(Não informado)\n");
	}else{
		printf("%s\n", dado.endereco);
	}
	printf("Profissão  = ");
	if (isNull(dado.profissao)) {
		printf("(Não informado)\n");
	}else {
		printf("%s\n", dado.profissao);
	}
	printf("Prioridade = %hd\n", dado.prioridade);
}

/*************************************************
 * Imprime toda a lista encadeada com os dados
 * Retorno: Nenhum
 * Pré-condição: Lista não está vazia
 * Pós-condição: Nenhuma
**************************************************/
void printList(Lista* l) {
	if (l != NULL) {
		printf("===========HABITANTE===========\n");
		printPeople(l->dado);
		printf("===============================\n\n");
		printList(l->prox);
	}
}
