#include "headers/people_list.h"
#include "headers/read_file.h"
#include "headers/print_stdio.h"
#include "headers/menu.h"

#include "structures/registry_structure.h"

#include <locale.h>

int main (int argc, char *argv[]) {
    Registry registry;
    initRegistry(&registry);

    setlocale(LC_ALL,"");
    //setlocale(LC_ALL,"portuguese");
    if(argc == 2) {
        registry.people = readFile(argv[1], registry.people);
    }else{
        FILE *file;
        file = fopen ("input","r");

        if(file != NULL) {
            fclose (file);
            registry.people = readFile("input", registry.people);
        }
    }

    menuController(&registry);

    freeList(registry.people);
    freeVaccineList(registry.vaccine);
   
    return 0;
}
