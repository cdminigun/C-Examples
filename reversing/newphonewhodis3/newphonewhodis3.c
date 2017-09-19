#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
int boon(char *a, char *b);
int noob(char *a, char *input);

int main(void){
    char *numba      = "ThisIsAVeryLongPassword!AreYouGoodAtReVerSing?IDontThinkSo";
    int i, k;
    char userInput[256];
    k = scanf("%s", userInput);
    if(k < 0) exit(-1);
    if(strlen(userInput) != 24){
        printf("Wrong Length.\n");
        exit(0);
    }
    boon(numba, userInput);
    if((noob(numba, userInput)) != 0){
        printf("Wrong numba.\n");
        return 0;
    }
    else {
        printf("Oh hiiiiii. You win!");
    }
    return 0;
}



int boon(char *a, char *b){
    int i;
    struct timeval tv;
    time_t curtime;
    for(i=0;i<12;i++){
        gettimeofday(&tv, NULL);
        curtime=tv.tv_sec;
        if(!curtime){
            return -1;
        }
    }
    return 0;
}
int noob(char *a, char *input){
    int i;
    for (i=0;i<24;i++){
        if(input[i] != a[i*21352%58]){
            return -1;
        }
    }
    return 0;
}




