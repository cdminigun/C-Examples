#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Useful functions for strings. 

int main(int argc, char *argv[]){
    int i;
    char *a = "Password"; //Assigns a string to a var
    if(argc != 2){
        printf("Required one input: ./program password\n");
        exit(0); //Terminates the program
    }
    if(strcmp(a, argv[1]) == 0 ){ //strcmp returns 0 if equal
        printf("Your password was correct.:)\n");
    }
    else{
        printf("Your answer was strong. :(\n");
    }
}
