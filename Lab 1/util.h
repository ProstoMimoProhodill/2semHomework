#ifndef UTIL_H_
#define UTIL_H_

typedef enum {false, true} bool;
typedef enum {INT, DOUBLE} type;

long long int randomInt(long long int min, long long max);
long double randomFloat(long double min, long double max);

int min(int a, int b);
int max(int a, int b);

#endif

