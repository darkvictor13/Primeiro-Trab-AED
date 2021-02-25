#include "../headers/read_file.h"

int readPerson(FILE *file, Person *data) {
   char aux;

   if( fscanf(file, "%c", &aux) == EOF ){
      // falha ao ler o arquivo
      return 0;
   }
	
   int tam;

   data->name = (char*)malloc(MAX_LEN * sizeof(char));
   data->name[0] = aux;
   fscanf(file, "%[^;]%*c", data->name + 1);
   tam = strlen(data->name);
   data->name = (char*)realloc(data->name, tam * sizeof(char) + 1);
   data->name[tam] = '\0';

   fscanf(file, "%d%*c", &data->age);

   fscanf(file, "%c%*c", &data->genre);
   
   fscanf(file, "%[^;]%*c", data->rg);
   
   data->rg[LEN_RG - 1] = '\0';
   fscanf(file, "%[^;]%*c", data->cpf);
   
   data->cpf[LEN_CPF - 1] = '\0';
   fscanf(file, "%c", &aux);
   
   if (aux != ';') {
      data->phone[0] = aux;
      fscanf(file, "%[^;]%*c", data->phone + 1);
   }else{
      data->phone[0] = '\0';
   }
   
   fscanf(file, "%c", &aux);
   
   if (aux != ';') {
      data->address = (char*)malloc(MAX_LEN * sizeof(char));
      data->address[0] = aux;
      fscanf(file, "%[^;]%*c", data->address + 1);
      data->address = (char*)realloc(data->address, MAX_LEN * sizeof(char));
   }else {
      data->address = NULL;
   }
   
   fscanf(file, "%c", &aux);
   
   if (aux != ';') {
      data->profession = (char*)malloc(MAX_LEN * sizeof(char));
      data->profession[0] = aux;
      fscanf(file, "%[^;]%*c", data->profession + 1);
      data->profession = (char*)realloc(data->profession, MAX_LEN * sizeof(char));
   }else {
      data->profession = NULL;
   }
   
   fscanf(file, "%hd%*r", &data->priority);

   //leitura de 1 habitante realizada com sucesso
   return 1;
}

List *readFile(char *fn, List *list) {
   FILE *file = fopen(fn, "r");
   
   if (file == NULL) {
      printf("Nome do arquivo inválido.\n");

      return list;
   }

   if (list == NULL) {
      list = allocPerson();
   }
   
   List *newList = list;
   
   // enquanto conseguir ler novas pessoas continua a leitura
   while (readPerson(file, &newList->data)) {
      // o último elemento saí com espaço alocado
      newList->next = allocPerson();
      newList = newList->next;
   }
	
   removeLast(list);
	
   fclose(file);
   return list;
}