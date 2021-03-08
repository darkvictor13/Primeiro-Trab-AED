#ifndef PEOPLE_LIST_STRUCTURE
#define PEOPLE_LIST_STRUCTURE

#define MAX_LEN 100

#define LEN_RG 20
#define LEN_CPF 20
#define LEN_PHONE 20
#define LEN_NAME 30
// Estrutura Person para o cadastro de habitantes
typedef struct {
    char *name;         // required
    int age;            // required
    char genre;         // required
    char *rg;           // required
    char *cpf;          // required
    char *phone;
    char *address;
    char *profession;
    short int priority; // required
    short int dose;
    struct vaccine *vaccine;
}Person;

// Estrutura nó para Lista
typedef struct node {
    Person data;
    struct node *next;
}Node;
// Estrutura para lista encadeada com cabeça e cauda
typedef struct {
    struct node *head;
    struct node *tail;
}List;

#endif
