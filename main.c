#include "headers/people_list.h"
#include "headers/read_file.h"
#include "headers/print_stdio.h"
#include "headers/menu.h"

#include "structures/registry_structure.h"

int main (int argc, char *argv[]) {
    List *population = NULL;
    VaccineStock vaccineStock;
   
    if(argc == 2) {
        population = readFile(argv[1], population);
    }else{
        FILE * file;
        file = fopen ("input","r");
        
        if(file != NULL) {
            fclose (file);
            population = readFile("input", population);
        }
    }

    menuController();
   
    return 0;
}
