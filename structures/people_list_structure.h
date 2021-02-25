#ifndef PEOPLE_LIST_STRUCTURE
#define PEOPLE_LIST_STRUCTURE

#define MAX_LEN 100

#define LEN_RG 20
#define LEN_CPF 20
#define LEN_PHONE 20

typedef struct {
   char *name; // required
   int age; // required
   char genre; // required
   char rg[LEN_RG]; // required
   char cpf[LEN_CPF]; // required
   char phone[LEN_PHONE];
   char *address;
   char *profession;
   short int priority; // required
}Person;

typedef struct node {
   Person data;
   struct node *next;
}List;

#endif
