#ifndef HABITANTE
#define HABITANTE

#define TAM_RG 3 //8
#define TAM_CPF 11
#define TAM_TEL 11
#define MAX_TAM 51

typedef struct {
	char *nome; // OBG
	int idade; // OBG
	char sexo; // OBG
	char rg[TAM_RG]; // OBG
	char cpf[TAM_CPF]; // OBG
	char tel[TAM_TEL];
	char *endereco;
	char *profissao;
	short int prioridade; // OBG
}People;

typedef struct no {
	People dado;
	struct no *prox;
}Lista;

#endif
