#include "util.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int randomInt(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

float randomFloat(float min, float max)
{
    float scale = rand() / (float) RAND_MAX;
    return min + scale * ( max - min );
}

int min(int a, int b)
{
    if(a<=b){
        return a;
    }else{
        return b;
    }
}

int max(int a, int b)
{
    if(a<=b){
        return b;
    }else{
        return a;
    }
}


int int_pow(int base, int exp)
{
    int result = 1;
    while (exp)
    {
        if (exp & 1)
           result *= base;
        exp /= 2;
        base *= base;
    }
    return result;
}



