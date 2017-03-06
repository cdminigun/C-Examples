#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){ // Declares argc and argv
                                  // for use within the main
                                  // program. Note that argv
                                  // is effectively a double
                                  // pointer. 
    int i; //Declares an integer variable.
    if (argc > 1){ //Checks for inputs
        printf("This is your program: %s\n", argv[0]);
        printf("This is your input:\n");
        for(i=1;i<argc;i++){ //For loop
            printf("%s\n", argv[i]); //Values accessed in
                                     // array notation.
        } //End Loop
    } // End Function 
}


