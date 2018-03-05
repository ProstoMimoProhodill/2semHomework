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


struct Polynomial *getData()
{
    // make input in this func


    /*
    int currType=0, n=0;
    printf("Input n :  ");
    scanf("%d", &n);
    printf("Input type (0-int, 1-float) : ");
    scanf("%d", &currType);

    polynomial->n = n;
    (currType==0)?(polynomial->dataType=INT):(polynomial->dataType=DOUBLE);
    */
}


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

    //make get input and push to array


    /*

    if(polynomial->dataType==INT){
        for(int i=0;i<=polynomial->n;i++){
            scanf("%d",(int *)(p+i));
        }
         polynomial->data = pushElementInDynamicArray(polynomial->data, INT, i);
    }else if(polynomial->dataType==DOUBLE){
        for(int i=0;i<=polynomial->n;i++){
            scanf("%d",(int *)(p+i));
        }
        polynomial->data = pushElementInDynamicArray(polynomial->data, DOUBLE, i);
    }
    */

    if(polynomial->dataType==INT){
        int *p = (int *)malloc((polynomial->n + 1) * sizeof(int));
        polynomial->data = malloc((polynomial->n + 1)* sizeof(int));
        printf("Input int : \n");
        for(int i=0;i<=polynomial->n;i++){
            scanf("%d",(int *)(p+i));
        }
        memcpy(polynomial->data, (void *)p, (polynomial->n + 1) * sizeof(int));
    }else{
        float *p = (float *)malloc((polynomial->n + 1) * sizeof(float));
        polynomial->data = malloc((polynomial->n + 1) * sizeof(float));
        printf("Input float : \n");
        for(int i=0;i<=polynomial->n;i++){
            scanf("%f",(float *)(p+i));
        }
        memcpy(polynomial->data, (void *)p, (polynomial->n + 1) * sizeof(float));
    }
    return polynomial;
}

void *pushElementInDynamicArray(void *dynamicArray, int elementType, int i)
{
    void *result;
    return result;
}

void *getElementFromDynamicArray(void *dynamicArray, int i)
{
    void *result;
    return result;
}

void outputPolynomial(struct Polynomial *polynomial)
{
    if(polynomial->dataType==INT){
        int *p = (int *)malloc((polynomial->n + 1) * sizeof(int));
        p = (int *)polynomial->data;
        for(int i=0;i<=polynomial->n;i++){
            printf("data[%d] = %d\n",i,*(int *)(p+i));
        }
    }else{
        float *p = (float *)malloc((polynomial->n + 1) * sizeof(float));
        p = (float *)polynomial->data;
        for(int i=0;i<=polynomial->n;i++){
            printf("data[%d] = %f\n",i,*(float *)(p+i));
        }
    }
}

struct Polynomial *polynomialAdditionFunction(struct Polynomial *polynomial1, struct Polynomial *polynomial2)
{
    struct Polynomial *result = malloc(sizeof(polynomial1) + sizeof(polynomial2));
    result->n = max(polynomial1->n, polynomial2->n);

    if((polynomial1->dataType==INT)&&(polynomial2->dataType==INT)){
        result->dataType = INT;
    }else if((polynomial1->dataType==DOUBLE)&&(polynomial2->dataType==DOUBLE)){
        result->dataType = DOUBLE;
    }else{
        printf("Error: different type \n");
        result = NULL;
        return result;
    }

    for(int i=0;i<=min(polynomial1->n, polynomial2->n);i++)
    {
        /*
        for(int d=0;d<max(polynomial1->n, polynomial2->n)-min(polynomial1->n, polynomial2->n);d++)
        {

        }
        */

        result->data = *(int *)(i);
    }
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

