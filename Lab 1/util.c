#include "util.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

long long int randomInt(long long int min, long long max)
{
    srand(time(NULL));
    return (min + rand()%max);
}

long double randomFloat(long double min, long double max)
{
    srand(time(NULL));
    long double range = (max - min);
    long double div = RAND_MAX / range;
    return (min + (rand() / div));
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



