#include "util.h"
#include <math.h>
#include "polynomialDynamicArray.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct Polynomial
{
    void *data;
    type dataType;
    int n;
};

struct Polynomial *createPolynomial()
{
    struct Polynomial *polynomial=malloc(sizeof(struct Polynomial));
    int currType=0, n=0;

    printf("Input n :  ");
    scanf("%d", &n);
    printf("Input type (0-int, 1-float) : ");
    scanf("%d", &currType);
    polynomial->n = n;
    (currType==0)?(polynomial->dataType=INT):(polynomial->dataType=DOUBLE);

    polynomial->data = NULL;
    if(polynomial->dataType==INT){
        printf("Input int : \n");
        for(int i=0;i<=polynomial->n;i++){
            int element;
            scanf("%d", &element);
            polynomial = pushElementInDynamicArray(polynomial, &element);
        }
    }else if(polynomial->dataType==DOUBLE){
        printf("Input float : \n");
        for(int i=0;i<=polynomial->n;i++){
            float element;
            scanf("%f", &element);
            polynomial = pushElementInDynamicArray(polynomial, &element);
        }
    }
    return polynomial;
}


struct Polynomial *pushElementInDynamicArray(struct Polynomial *dynamicArray, void *element)
{
    int i;
    struct Polynomial *result;

    if(dynamicArray->dataType==INT){
        (_msize(dynamicArray->data)==-1)?(i=0):(i = (_msize(dynamicArray->data))/(sizeof(int)) );

        if(i>0){
            dynamicArray->data = realloc(dynamicArray->data, (i+1)*sizeof(int));
        }

        result = (struct Polynomial *)malloc( _msize(dynamicArray) + sizeof(int) );
        result->data = realloc(dynamicArray->data, (i+1)*sizeof(int));
        int *p = (int *)realloc(dynamicArray->data, (i+1)*sizeof(int));
        *(p+i) = *(int *)element;
        memcpy(result->data, (void *)p, (i+1)*sizeof(int));
    }else if(dynamicArray->dataType==DOUBLE){
        (_msize(dynamicArray->data)==-1)?(i=0):(i = (_msize(dynamicArray->data))/(sizeof(float)) );

        if(i>0){
            dynamicArray->data = realloc(dynamicArray->data, (i+1)*sizeof(float));
        }

        result = (struct Polynomial *)malloc( _msize(dynamicArray) + sizeof(float) );
        result->data = realloc(dynamicArray->data, (i+1)*sizeof(float));
        float *p = (float *)realloc(dynamicArray->data, (i+1)*sizeof(float));
        *(p+i) = *(float *)element;
        memcpy(result->data, (void *)p, (i+1)*sizeof(float));
    }

    result->dataType = dynamicArray->dataType;
    result->n = dynamicArray->n;
    return result;
}

void *getElementFromDynamicArray(struct Polynomial *dynamicArray, int i)
{
    void *result;

    if(elementType==0){
        int *p = (int *)dynamicArray;
        result = (int *)(p+i);
    }else{
        float *p = (float *)dynamicArray;
        result = (float *)(p+i);
    }

    return result;
}

void outputPolynomial(struct Polynomial *polynomial)
{
    if(polynomial->dataType==INT){
        int *p = (int *)polynomial->data;
        for(int i=0;i<=polynomial->n;i++){
            printf("int        data[%d] = %d\n",i,*(int *)(p+i));
        }
    }else{
        float *p = (float *)polynomial->data;
        for(int i=0;i<=polynomial->n;i++){
            printf("double     data[%d] = %f\n",i,*(float *)(p+i));
        }
    }
}

struct Polynomial *polynomialAdditionFunction(struct Polynomial *polynomial1, struct Polynomial *polynomial2)
{
    struct Polynomial *result = malloc(sizeof(polynomial1) + sizeof(polynomial2));

    int n = max(polynomial1->n, polynomial2->n);
    result->n = malloc(sizeof(int));
    result->n = n;

    if((polynomial1->dataType==INT)&&(polynomial2->dataType==INT)){
        result->dataType = INT;
    }else if((polynomial1->dataType==DOUBLE)||(polynomial2->dataType==DOUBLE)){
        result->dataType = DOUBLE;
    }

    for(int i=0;i<=max(polynomial1->n, polynomial2->n);i++)
    {
        if(polynomial1->n!=polynomial2->n){
            for(int d=0;d<max(polynomial1->n, polynomial2->n)-min(polynomial1->n, polynomial2->n);d++){
                if(result->dataType==INT){
                    int *p = (int *)malloc((result->n + 1) * sizeof(int));
                    result->data = malloc((result->n + 1)* sizeof(int));
                    for(int j=0;j<=result->n;j++){
                        int *k = (int *)polynomial1->data;
                        *(int *)(p+j) = *(int *)(k+j);
                    }
                    memcpy(result->data, (void *)p, (result->n + 1) * sizeof(int));
                }else{
                    float *p = (float *)malloc((result->n + 1) * sizeof(float));
                    result->data = malloc((result->n + 1)* sizeof(float));
                    for(int j=0;j<=result->n;j++){
                        float *k = (float *)polynomial1->data;
                        *(float *)(p+j) = *(float *)(k+j);
                    }
                    memcpy(result->data, (void *)p, (result->n + 1) * sizeof(float));
                }
            }
        }



    }

    system("pause");

    return result;
}

struct Polynomial *polynomialMultiplicationFunction(struct Polynomial *polynomial1, struct Polynomial *polynomial2)
{

}

/*
struct Polynomial *polynomialMultiplicationByScalarFunction(struct Polynomial *polynomial, int psize, struct Coefficient *scalar)
{

}


struct Coefficient *polynomialResultForVariableFunction(struct Polynomial *polynomial, int psize, struct Coefficient *X)
{

}
*/

struct Polynomial *polynomialCompositionFunction(struct Polynomial *polynomial1, struct Polynomial *polynomial2, int p1Size, int p2Size)
{

}


void polynomialAddition()
{
    struct Polynomial *polynomial1 = createPolynomial();
    struct Polynomial *polynomial2 = createPolynomial();

    printf("pol1\n");
    outputPolynomial(polynomial1);
    printf("pol2\n");
    outputPolynomial(polynomial2);

    struct Polynomial *result = polynomialAdditionFunction(polynomial1, polynomial2);
    outputPolynomial(result);
}


void polynomialMultiplication()
{

}


void polynomialMultiplicationByScalar()
{

}


void polynomialResultForVariable()
{

}


void polynomialComposition()
{

}

