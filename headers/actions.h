#ifndef ACTIONS
#define ACTIONS

#include "../structures/registry_structure.h"
#include "../structures/people_list_structure.h"
#include "people_list.h"
#include "registry.h"
#include "verify.h"
#include "utils.h"
#include "stdio.h"

#include <stdio.h>

/*************************************************
 * Alloca e realoca dados pra inserir na lista
 * Retorno: Retorna char alocado com o tamanho devido
 * Pré-condição: nenhuma
 * Pós-condição: dado é realocado com o tamanho definido
**************************************************/
char* enterDataString(char *message);
/*************************************************
 * Insere um habitante na lista de cadastro
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Novo cadastro inserido
**************************************************/
void registerHabitant(Registry *registry);
/*************************************************
 * Registra vacinação no CPF cadastrado
 * Retorno: Nenhum
 * Pré-condição: CPF estar registrado, estar no grupo de prioridade liberado e ter vacinas no estoque
 * Pós-condição: Menos uma vacina no estoque de vacinas
**************************************************/
void registerVaccination(Registry *registry);
/*************************************************
 * Remove o cadastro de um habitante
 * Retorno: Nenhum
 * Pré-condição: Habitante estar cadastrado
 * Pós-condição: Habitante removido
**************************************************/
void removeHabitant(Registry *registry);
/*************************************************
 * Libera um grupo para vacinas
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Pode liberar ou não o(s) grupo(s) de prioridade
**************************************************/
void releaseGroup(Registry *registry);
/*************************************************
 * Adiciona vacinas no estoque
 * Retorno: Nenhum
 * Pré-condição: Vacina estar no cadastro
 * Pós-condição: Vacinas adicionadas no estoque
**************************************************/
void controlStock(Registry *registry);
/*************************************************
 * Imprime relatorios de estoque, habitantes com a primeira e segunda dose, habitantes sem vacinar e grupo de prioridade
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Os relatorios sao impressos no console
**************************************************/
void reports(Registry *registry);
#endif
