#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char *disnumba = "Wakainaiooooo";
    char newNumba[14];
    char userInput[14];
    int i, k, temp = 12;
    newNumba[13] = '\0';

    for(i=0; i<13; i++){
        newNumba[i] = disnumba[temp-i];
    }
    k = scanf("%s", userInput);
    if (k<0){
        printf("An error occured with scanf.");
        exit(-1);
    }
    if(strlen(userInput)!=13){
        printf("Wrong Length.");
        exit(-1);
    }
    if((strcmp(userInput, newNumba))!=0){
        printf("Wrong numba.");
    }
    else{printf("Ohiiiiii, you gottt itttttt. Grats.");}
    return 0;
}
