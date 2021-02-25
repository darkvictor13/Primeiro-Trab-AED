# Primeiro Trabalho de Algoritmos e Estrutura de Dados

# Requisitos

Data de entrega: 09/3/2021

Desenvolvido em linguagem C.

Sistema de gerenciamento de vacinas

- Informações apenas na memória
- Interface por linha de comandos

- Cadastro
   - nome*
   - idade*
   - genero*
   - rg*
   - cpf*
   - telefone
   - endereco
   - profissao
   - prioridade*

   *requerido

# Funcionalidades

- Retirar habitante em função do cpf

- Liberar grupo para vacinação

- Controle de estoque
   - coronavac
   - oxford
   - sputnik
   - pfizer
   - moderna

- Opsão de registrar vacinação a partir do cpf
   - se pertence ao grupo prioritario e a vacina esta diponível
      - a pessoa é vacinada
      - é registra a data de vacinacao, o tipo de vacina e a dose

   - caso a pessoa não pertença ao grupo
      - emite messagem negando a vacinação

   - se ja tomou dua doses
      - emite messagem negando a vacinação

   - se o estoque esta vacio
      - emite messagem negando a vacinação

- Adicionar ao estoque um conjunto de vacinas

- Emitir relatorios
   - número de doses em estoque
   - lista de habitantes vacinados com 1 dose
   - lista de habitantes vacinados com 2 dose 
   - lista de habitantes sem vacinar
   - número de habitantes por grupo

- Ler informacoes de habitantes apartir de arquivo de texto

# Entrega

- Criar relatorio do trabalho
   - nome dos integrantes
   - instruções para execução do programa
   - descrição das estruturas e funcionalidades

