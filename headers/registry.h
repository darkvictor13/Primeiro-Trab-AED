#ifndef REGISTRY
#define REGISTRY

#include "../structures/registry_structure.h"
#include "utils.h"

#include <string.h>

/*************************************************
 * Inicia o registro de vacinação
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Nenhum
**************************************************/
void initRegistry(Registry *registry);
/*************************************************
 * Aloca a string
 * Retorno: String alocada
 * Pré-condição: Nenhum
 * Pós-condição: String alocada
**************************************************/
char* allocString(char *message);
/*************************************************
 * Inicia o registro de vacinação
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Nenhum
**************************************************/
Vaccine* fillVaccine(char *name, char *pharmaceutical, int inStock);
/*************************************************
 * Adiciona vacina
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Vacina adicionada no registro
**************************************************/
void addVaccine(Registry *registry, char *name, char *pharmaceutical, int inStock);
/*************************************************
 * Procura vacina disponivel
 * Retorno: Vacina com estoque maior que zero
 * Pré-condição: Ter vacinas no estoque
 * Pós-condição: Vacina encontrada
**************************************************/
Vaccine* findVaccineAvailable(Vaccine *vaccine);
/*************************************************
 * Imprime lista de vacinas
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: As vacinas são impressos no console
**************************************************/
void listVaccines(Vaccine *vaccine);
/*************************************************
 * Busca vacina
 * Retorno: Vacina encontrada
 * Pré-condição: Conter vacinas registradas
 * Pós-condição: Vacina encontrada
**************************************************/
Vaccine* findVaccine(Vaccine *vaccine, char *name);
/*************************************************
 * Imprime dados da estrutura Person
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Imprime no console os dados
**************************************************/
void printPersonData(char *name, char *cpf);
    /*************************************************
 * Lista as pessoas que receberam as doses da vacina
 * Retorno: Nenhum
 * Pré-condição: Habitantes que receberam as doses
 * Pós-condição: Nenhum
**************************************************/
void listByDose(List *people, int dose);
/*************************************************
 * Relatorio de vacinas em estoque
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Imprime as vacinas e o seu estoque
**************************************************/
void reportStock(Vaccine *vaccine);
/*************************************************
 * Relatorio de pessoas vacinadas com a primeira dose
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Imprime no console as pessoas vacinadas com a primeira dose
**************************************************/
void reportFirstDose(List *people);
/*************************************************
 * Relatorio de pessoas vacinadas com a segunda dose
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Imprime no console as pessoas vacinadas com a segunda dose
**************************************************/
void reportSecondDose(List *people);
/*************************************************
 * Relatorio de pessoas não vacinadas
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Imprime no console as pessoas não vacinadas
**************************************************/
void reportWithoutVaccine(List *people);
/*************************************************
 * Conta quantas pessoas estao em um grupo de prioridade
 * Retorno: Quantidade de pessoas no grupo prioritario
 * Pré-condição: Nenhum
 * Pós-condição: Quantidade de pessoas contadas em um grupo
**************************************************/
int countGroup(List *people, int group);
/*************************************************
 * Relatorio de pessoas por grupo
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Imprime no console as pessoas por grupo prioritario
**************************************************/
void reportGroups(List *people);

#endif
