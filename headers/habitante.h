#ifndef HABITANTE
#define HABITANTE

#define TAM_RG   4 //8
#define TAM_CPF 12
#define TAM_TEL 12
#define MAX_TAM 51

typedef struct {
	char *nome;           // OBRIGATÓRIO
	int idade;            // OBRIGATÓRIO
	char sexo;            // OBRIGATÓRIO
	char rg[TAM_RG];      // OBRIGATÓRIO
	char cpf[TAM_CPF];    // OBRIGATÓRIO
	char tel[TAM_TEL];
	char *endereco;
	char *profissao;
	short int prioridade; // OBRIGATÓRIO
}People;

typedef struct no {
	People dado;
	struct no *prox;
}Lista;

#endif
