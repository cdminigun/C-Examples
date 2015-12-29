/*
 * File: random.c
 * --------------
 * This file implements the random.h interface.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* #include "genlib.h" */
#include "random.h"

/*
 * Function: RandomInteger
 * -----------------------
 * This function begins by using rand to select an integer
 * in the interval [0, RAND_MAX] and then converts it to the
 * desired range by applying the following steps:
 *
 * 1. Normalize the value to a real number in the interval [0, 1)
 * 2. Scale the resulting value to the appropriate range size
 * 3. Truncate the scaled value to an integer
 * 4. Translate the integer to the appropriate starting point
 */

int RandomInteger(int low, int high)
{
    int k;
    double d;

    d = (double) rand() / ((double) RAND_MAX + 1);
    k = (int) (d * (high - low + 1));
    return (low + k);
}

/*
 * Function: RandomReal
 * --------------------
 * The implementation of RandomReal is similar to that
 * of RandomInteger, without the truncation step.
 */



void Randomize(void)
{
    srand((int) time(NULL));
}
