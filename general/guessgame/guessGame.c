#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
/* #include "genlib.h"  */
#include "random.h"

void playGuessGame(int a[], int b[]);
void getRandomNum(int a[]);
void getUserNum(int a[]);
void makeArray(int a[4], int b);
int checkArray(int a[]);
int checkMatchingNums(int a[], int b[]);
int checkExactNums(int a[], int b[]);


int main(void)
{
   int secret;			/*  Declare variables */
   int a_a[4];
   int a_s[4];
   int i, j;
   Randomize();
   printf("Welcome to the guessing game.\n The object of this game is to guess a random 4 digit number.\n Good luck.\n");
   playGuessGame(a_s, a_a);
   return 0;
}

void playGuessGame(int a[], int b[])
{
  int i, exact, matching, missing;
  for(i=1; i <=40; i++){
    missing = 0;
    getRandomNum(a);
    getUserNum(b);
    exact = checkExactNums(a,b);
    matching = checkMatchingNums(a,b);
    printf("matching = %d exact = %d\n", matching, exact);
    matching = matching-exact;
    missing = (4-(matching+exact));
    if(exact == 1)
      printf("1 digit is in place.\n");
    if(exact > 1)
      printf("%d digits are in place.\n", exact);
    if(matching == 1)
      printf("1 digit is out of place.\n");
    if(matching >1)
      printf("%d digits are out of place.\n", matching);
    if(missing == 1)
      printf("1 digit does not exist.\n");
    if(missing > 1)
      printf("%d digits do not exist\n", missing);
    }
  return;
}
void getRandomNum(int a[])
{
  int i = 1;
  int secret;

  while(i)
  {
    secret = RandomInteger(1000,9999);
    makeArray(a, secret);
    i = checkArray(a);
  }
}
void getUserNum(int a[])
{
  int i =1,b,k=0,j=0;
  printf("Please enter a 4 digit number with no repeating numbers.");
  while(i)
  {
    scanf("%d", &b);
    makeArray(a, b);
    k = checkArray(a);
    j = floor(log10(abs(b))) + 1;
    if(k==0 && j==4)
      i = 0;
    else
      printf("Your number was not valid. Please enter another.");

  }
}
void makeArray(int a[4], int b)
{
  a[0]=b/1000;
  a[1]=(b%1000)/100;
  a[2]=(b%100)/10;
  a[3]= b%10;
}
int checkArray(int a[])
{
  int i,j;
  for (i = 0; i < 4; i++) {
    for (j = i + 1; j < 4; j++) {
        if (a[i] == a[j]) {
          return 1;
        }
    }
  }
  return 0;
}
int checkMatchingNums(int a[], int b[])
{
  int i,j, count=0;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
        if (a[i] == b[j])
          count++;
        }
    }

  return count;
}
int checkExactNums(int a[], int b[])
{
  int i, count=0;
  for(i=0;i<4;i++)
  {
    if(a[i]==b[i])
      count++;
  }
  return count;
}
