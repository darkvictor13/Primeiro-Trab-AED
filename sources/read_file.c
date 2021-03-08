#include "../headers/read_file.h"

/*************************************************
 * Lê os dados uma string de um arquivo
 * Retorno: String alocado
 * Pré-condição: Nenhum
 * Pós-condição: String alocado
**************************************************/
char* readDataString(FILE *file) {
    char* value = (char*)malloc(MAX_LEN * sizeof(char));
    
    fscanf(file, "%[^;]%*c", value);
    
    int len = strlen(value);
    
    value = (char*)realloc(value, (len + 1) * sizeof(char));
    value[len] = '\0';
    
    return value;
}
/*************************************************
 * Lê os dados da estrutura Person de um arquivo
 * Retorno: 1
 * Pré-condição: Nenhum
 * Pós-condição: Nenhum
**************************************************/
int readPerson(FILE *file, Person *data) {
    char c;

    data->name = readDataString(file);

    fscanf(file, "%d%*c", &data->age);
    fscanf(file, "%c%*c", &data->genre);

    data->rg = readDataString(file);
    data->cpf = readDataString(file);

    fscanf(file, "%c", &c);
    if (c != ';') {
        data->phone = readDataString(file);
    }else{
        data->phone[0] = '\0';
    }

    fscanf(file, "%c", &c);
    if (c != ';') {
        data->address = readDataString(file);
    }else {
        data->address = NULL;
    }

    fscanf(file, "%c", &c);
    if (c != ';') {
        data->profession = readDataString(file);
    }else {
        data->profession = NULL;
    }

    fscanf(file, "%hd%*r", &data->priority);

    data->dose = 0;
    data->vaccine = NULL;

    return 1;
}
/*************************************************
 * Lê um arquivo e insere os dados na lista
 * Retorno: Lista com os dados do arquivo inserido
 * Pré-condição: Arquivo deve existir
 * Pós-condição: Arquivo lido e inserido na lista
**************************************************/
List *readFile(char *fn, List *list) {
    FILE *file = fopen(fn, "r");

    if (file == NULL) {
        printf("Nome do arquivo inválido.\n");
        return list;
    }

    if (list == NULL) {
        list = createList();
    }

    Person person;

    while( feof(file) == 0 ) {
        readPerson(file, &person);
        insertPerson(list, person);
    }

    fclose(file);
    return list;
}
