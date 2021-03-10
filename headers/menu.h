#ifndef MENU
#define MENU

#ifdef linux
#define ENTER 10
#else
#define ENTER 13
#endif

#include "../structures/registry_structure.h"
#include "actions.h"
#include "utils.h"
#include <errno.h>
#include <time.h>

/*************************************************
 * Selecionar a opçao desejada
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Nenhum
**************************************************/
void thisOption(char* string, int selected);
/*************************************************
 * Muda para o menu principal ao teclar Enter
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Muda para o menu principal
**************************************************/
void continueMenu();
/*************************************************
 * Interface do programa
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: 
**************************************************/
void initMessage();
/*************************************************
 * Controla o menu principal
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Navega para a opção selecionada
**************************************************/
void menuController(Registry *registry);

/*************************************************
 * Menu principal
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Imprime no console o menu principal
**************************************************/
void menuMessage(int option);
/*************************************************
 * Interface de encerramento do programa
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Imprime no console que o programa foi encerrado
**************************************************/
void endMessage();

#endif
