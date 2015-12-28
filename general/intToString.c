/***********************************************************************************
hm02.c by Christopher Doege
Purpose:
  Translate from an integer number to a string.
Input:
  Any positive integer number < 999,999
Results:
  Prints the value that was given in a text output.
Notes:


***********************************************************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void calculateN(int *n1, int *n2, int *n3, int *n4, int *n5, int *n6, int userInput);

char ones[10][10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
char tens[10][10] = {"", "ten","twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety"};
char nTeens[10][10] = {"", "elleven","twelve","thirteen","fourteen","fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
int main()
{
  int userInput;
  int n1, n2, n3, n4, n5, n6;
  int test =1;
  int countOfDigits;
  while(test){
    scanf("%d", &userInput);
    countOfDigits=floor(log10(abs(userInput))) + 1;
    if(userInput==0)
      countOfDigits=1;
    if(userInput < 0){
      printf("You have chosen to exit the program.");
      break;
    }
    if(countOfDigits >6){
      printf("Your number is too high, please enter another one.\n");
    }
    calculateN(&n1, &n2, &n3, &n4, &n5, &n6, userInput);
    switch(countOfDigits){
      case 6 :
        printf("%s hundred ", ones[n6]);
        countOfDigits--;
        if(n5<1 && n4<1)
          printf("thousand ");
      case 5 :
        if(n6>=1 && n5>=1)
          printf("and ");
        if(n5==1 && n4>0)
        {
          printf("%s thousand ",nTeens[n4]);
          countOfDigits=4;
        }
        else
        {
          printf("%s",tens[n5]);
          if(n4<1 && n5>=1)
            printf("thousand ");
          countOfDigits--;
        }
      case 4 :
        if(n5>1 && n4>=1)
          printf("-");
        if(n6>=1 && n5<1 && n4>=1)
          printf("and ");
        if(n4>=1 && n5 != 1)
          printf("%s thousand ", ones[n4]);
      case 3 :
      if(n3>=1)
        printf("%s hundred ", ones[n3]);
      case 2 :
        if(n3>=1 && n2>0)
          printf("and ");
        if(n2==1 && n1>=1)
        {
          printf("%s", nTeens[n1]);
          countOfDigits=0;
        }
        else{
          printf("%s",tens[n2]);
          countOfDigits--;
        }

      case 1 :
        if(n2>=2 && n1>=1)
          printf("-");
        if(n1 !=0 && n2 !=1)
          printf("%s ", ones[n1]);
        break;
      }
      printf("\n");
  }
}

void calculateN(int *n1, int *n2, int *n3, int *n4, int *n5, int *n6, int userInput)
{
  *n1 = userInput % 10;
  *n2 = (userInput % 100-*n1)/10;
  *n3 = (userInput % 1000-*n2-*n1)/100;
  *n4 = (userInput % 10000-*n3-*n2-*n1)/1000;
  *n5 = (userInput % 100000 -*n4-*n3-*n2-*n1)/10000;
  *n6 = (userInput -*n5-*n4-*n3-*n2-*n1)/100000;
}
