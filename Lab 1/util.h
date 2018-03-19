#ifndef UTIL_H_
#define UTIL_H_

typedef enum {false, true} bool;
typedef enum {INT, DOUBLE} type;

int randomInt(int min, int max);
float randomFloat(float min, float max);

int min(int a, int b);
int max(int a, int b);

int int_pow(int base, int exp);

#endif

