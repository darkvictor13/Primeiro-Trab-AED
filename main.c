#include "headers/people_list.h"
#include "headers/read_file.h"
#include "headers/print_stdio.h"
#include "headers/menu.h"

#include "structures/registry_structure.h"

int main (int argc, char *argv[]) {
<<<<<<< HEAD
    Registry registry;
   
=======
    List *population = createList();
    VaccineStock vaccineStock;

>>>>>>> e46cb06522b1d5a305fd3a4fe8dec33854e10d9a
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

    menuController();
<<<<<<< HEAD
   
    printList(registry.people);
   
=======

>>>>>>> e46cb06522b1d5a305fd3a4fe8dec33854e10d9a
    return 0;
}
