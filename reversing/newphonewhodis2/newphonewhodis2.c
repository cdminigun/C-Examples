#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

int main(void){
    char *numba      = "WindowsIsTrash";
    char *notnumba1  = "HackTheGibsons";
    char *notnuba2   = "ayyyyyhowudoin";
    char *notnumba3  = "!passwordispas";
    int i, k;
    char userInput[256];
    char xornumba[15];
    xornumba[14] = '\0';

    for (i =0; i<14;i++){
        xornumba[i] = (char)(numba[i] ^ notnuba2[i]);
    }
    k = scanf("%s", userInput);
    if(k < 0) exit(-1);
    if(strlen(userInput) != 14){
        printf("Wrong Length.\n");
    }
    noob(xornumba, userInput);
    if((boon(xornumba, userInput )) != 0){
        printf("Wrong numba.\n");
    }
    else {
        printf("Oh hiiiiii. You win!");
    }
    return 0;
}



int noob(char *a, char *b){
    int i;
    struct timeval tv;
    time_t curtime;
    for(i=0;i<15;i++){
        gettimeofday(&tv, NULL);
        curtime=tv.tv_sec;
        if(!curtime){
            return -1;
        }
    }
    return 0;
}
int boon(char *a, char *b){
    int i;
    for (i=0;i<15;i++){
        if(a[i] != b[i]){
            return -1;
        }
    }
    return 0;
}




